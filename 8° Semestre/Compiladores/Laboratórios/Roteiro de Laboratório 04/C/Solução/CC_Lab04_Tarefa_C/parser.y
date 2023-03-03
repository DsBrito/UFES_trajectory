
%output "parser.c"          // File name of generated parser.
%defines "parser.h"         // Produces a 'parser.h'
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "tables.h"
#include "parser.h"

int yylex(void);
int yylex_destroy(void);
void yyerror(char const *s);

Type check_var();
void new_var();

Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type));

void check_assign(Type l, Type r);
void check_bool_expr(const char* cmd, Type t);

extern char *yytext;
extern int yylineno;

StrTable *st;
VarTable *vt;

Type last_decl_type;
%}

%define api.value.type {Type}

%token ASSIGN
%token BEGIN_RW
%token BOOL
%token ELSE
%token END
%token EQ
%token FALSE
%token ID
%token IF
%token INT
%token INT_VAL
%token LPAR
%token LT
%token MINUS
%token OVER
%token PLUS
%token PROGRAM
%token READ
%token REAL
%token REAL_VAL
%token REPEAT
%token RPAR
%token SEMI
%token STRING
%token STR_VAL
%token THEN
%token TIMES
%token TRUE
%token UNTIL
%token VAR
%token WRITE

// Precedence of operators.
// All operators are left associative.
// Higher line number == higher precedence.
%left EQ LT
%left PLUS MINUS
%left TIMES OVER

// Start symbol for the grammar.
%start program

%%

program:
  PROGRAM ID SEMI vars-sect stmt-sect
;

vars-sect:
  VAR opt-var-decl
;

opt-var-decl:
  %empty
| var-decl-list
;

var-decl-list:
  var-decl
| var-decl-list var-decl
;

var-decl:
  type-spec ID { new_var(); } SEMI
;

type-spec:
  BOOL      { last_decl_type = BOOL_TYPE; }
| INT       { last_decl_type = INT_TYPE; }
| REAL      { last_decl_type = REAL_TYPE; }
| STRING    { last_decl_type = STR_TYPE; }
;

stmt-sect:
  BEGIN_RW stmt-list END
;

stmt-list:
  stmt
| stmt-list stmt
;

stmt:
  assign-stmt
| if-stmt
| read-stmt
| repeat-stmt
| write-stmt
;

assign-stmt:
  ID { $1 = check_var(); } ASSIGN expr SEMI  { check_assign($1, $4); }
;

if-stmt:
  IF expr THEN stmt-list END                { check_bool_expr("if", $2); }
| IF expr THEN stmt-list ELSE stmt-list END { check_bool_expr("if", $2); }
;

read-stmt:
  READ ID { check_var(); } SEMI
;

repeat-stmt:
  REPEAT stmt-list UNTIL expr   { check_bool_expr("repeat", $4); }
;

write-stmt:
  WRITE expr SEMI
;

expr:
  expr LT expr      { $$ = unify_bin_op($1, $3, "<", unify_comp); }
| expr EQ expr      { $$ = unify_bin_op($1, $3, "=", unify_comp); }
| expr PLUS expr    { $$ = unify_bin_op($1, $3, "+", unify_plus); }
| expr MINUS expr   { $$ = unify_bin_op($1, $3, "-", unify_other_arith); }
| expr TIMES expr   { $$ = unify_bin_op($1, $3, "*", unify_other_arith); }
| expr OVER expr    { $$ = unify_bin_op($1, $3, "/", unify_other_arith); }
| LPAR expr RPAR    { $$ = $2; }
| TRUE              { $$ = BOOL_TYPE; }
| FALSE             { $$ = BOOL_TYPE; }
| INT_VAL           { $$ = INT_TYPE; }
| REAL_VAL          { $$ = REAL_TYPE; }
| STR_VAL           { $$ = STR_TYPE; }
| ID                { $$ = check_var(); }
;

%%

Type check_var() {
    int idx = lookup_var(vt, yytext);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
    }
    return get_type(vt, idx);
}

void new_var() {
    int idx = lookup_var(vt, yytext);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, yytext, get_line(vt, idx));
        exit(EXIT_FAILURE);
    }
    add_var(vt, yytext, yylineno, last_decl_type);
}

// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type t2) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
    exit(EXIT_FAILURE);
}

Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type)) {
    Type unif = unify(l, r);
    if (unif == NO_TYPE) {
        type_error(op, l, r);
    }
    return unif;
}

void check_assign(Type l, Type r) {
    if (l == BOOL_TYPE && r != BOOL_TYPE) type_error(":=", l, r);
    if (l == STR_TYPE  && r != STR_TYPE)  type_error(":=", l, r);
    if (l == INT_TYPE  && r != INT_TYPE)  type_error(":=", l, r);
    if (l == REAL_TYPE && !(r == INT_TYPE || r == REAL_TYPE)) type_error(":=", l, r);
}

void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
        exit(EXIT_FAILURE);
    }
}

// Primitive error handling.
void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

int main() {
    st = create_str_table();
    vt = create_var_table();

    yyparse();
    printf("PARSE SUCCESSFUL!\n");

    printf("\n\n");
    print_str_table(st); printf("\n\n");
    print_var_table(vt); printf("\n\n");

    free_str_table(st);
    free_var_table(vt);
    yylex_destroy();    // To avoid memory leaks within flex...

    return 0;
}

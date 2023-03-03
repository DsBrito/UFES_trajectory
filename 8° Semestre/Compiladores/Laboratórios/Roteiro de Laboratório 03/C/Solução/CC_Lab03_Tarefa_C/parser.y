
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

void check_var();
void new_var();

extern char *yytext;
extern int yylineno;

StrTable *st;
VarTable *vt;

Type last_decl_type;
%}

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
  ID { check_var(); } ASSIGN expr SEMI
;

if-stmt:
  IF expr THEN stmt-list END
| IF expr THEN stmt-list ELSE stmt-list END
;

read-stmt:
  READ ID { check_var(); } SEMI
;

repeat-stmt:
  REPEAT stmt-list UNTIL expr
;

write-stmt:
  WRITE expr SEMI
;

expr:
  expr LT expr
| expr EQ expr
| expr PLUS expr
| expr MINUS expr
| expr TIMES expr
| expr OVER expr
| LPAR expr RPAR
| TRUE
| FALSE
| INT_VAL
| REAL_VAL
| STR_VAL
| ID                { check_var(); }
;

%%

void check_var() {
    int idx = lookup_var(vt, yytext);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
    }
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


%output "parser.c"          // File name of generated parser.
%defines "parser.h"         // Produces a 'parser.h'
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "tables.h"
#include "ast.h"
#include "parser.h"
#include "interpreter.h"

int yylex(void);
int yylex_destroy(void);
void yyerror(char const *s);

AST* check_var();
AST* new_var();

AST* unify_bin_node(AST* l, AST* r,
                    NodeKind kind, const char* op, Unif (*unify)(Type,Type));

AST* check_assign(AST *l, AST *r);
AST* check_if_then(AST *e, AST *b);
AST* check_if_then_else(AST *e, AST *b1, AST *b2);
AST* check_repeat(AST *b, AST *e);

extern char *yytext;
extern int yylineno;

StrTable *st;
VarTable *vt;

Type last_decl_type;
AST *root;
%}

%define api.value.type {AST*}

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
  PROGRAM ID SEMI vars-sect stmt-sect { root = new_subtree(PROGRAM_NODE, NO_TYPE, 2, $4, $5); }
;

vars-sect:
  VAR opt-var-decl  { $$ = $2; }
;

opt-var-decl:
  %empty            { $$ = new_subtree(VAR_LIST_NODE, NO_TYPE, 0); }
| var-decl-list     { $$ = $1; }
;

var-decl-list:
  var-decl                  { $$ = new_subtree(VAR_LIST_NODE, NO_TYPE, 1, $1); }
| var-decl-list var-decl    { add_child($1, $2); $$ = $1; }
;

var-decl:
  type-spec ID { $2 = new_var(); } SEMI { $$ = $2;}
;

type-spec:
  BOOL      { last_decl_type = BOOL_TYPE; }
| INT       { last_decl_type = INT_TYPE; }
| REAL      { last_decl_type = REAL_TYPE; }
| STRING    { last_decl_type = STR_TYPE; }
;

stmt-sect:
  BEGIN_RW stmt-list END    { $$ = $2; }
;

stmt-list:
  stmt              { $$ = new_subtree(BLOCK_NODE, NO_TYPE, 1, $1); }
| stmt-list stmt    { add_child($1, $2); $$ = $1; }
;

stmt:
  assign-stmt   { $$ = $1; }
| if-stmt       { $$ = $1; }
| read-stmt     { $$ = $1; }
| repeat-stmt   { $$ = $1; }
| write-stmt    { $$ = $1; }
;

assign-stmt:
  ID { $1 = check_var(); } ASSIGN expr SEMI { $$ = check_assign($1, $4); }
;

if-stmt:
  IF expr THEN stmt-list END                { $$ = check_if_then($2, $4); }
| IF expr THEN stmt-list ELSE stmt-list END { $$ = check_if_then_else($2, $4, $6); }
;

read-stmt:
  READ ID { $2 = check_var(); } SEMI { $$ = new_subtree(READ_NODE, NO_TYPE, 1, $2); }
;

repeat-stmt:
  REPEAT stmt-list UNTIL expr   { $$ = check_repeat($2, $4); }
;

write-stmt:
  WRITE expr SEMI { $$ = new_subtree(WRITE_NODE, NO_TYPE, 1, $2); }
;

expr:
  expr LT expr      { $$ = unify_bin_node($1, $3, LT_NODE,    "<", unify_comp); }
| expr EQ expr      { $$ = unify_bin_node($1, $3, EQ_NODE,    "=", unify_comp); }
| expr PLUS expr    { $$ = unify_bin_node($1, $3, PLUS_NODE,  "+", unify_plus); }
| expr MINUS expr   { $$ = unify_bin_node($1, $3, MINUS_NODE, "-", unify_other_arith); }
| expr TIMES expr   { $$ = unify_bin_node($1, $3, TIMES_NODE, "*", unify_other_arith); }
| expr OVER expr    { $$ = unify_bin_node($1, $3, OVER_NODE,  "/", unify_other_arith); }
| LPAR expr RPAR    { $$ = $2; }
| TRUE              { $$ = $1; }
| FALSE             { $$ = $1; }
| INT_VAL           { $$ = $1; }
| REAL_VAL          { $$ = $1; }
| STR_VAL           { $$ = $1; }
| ID                { $$ = check_var(); }
;

%%

// ----------------------------------------------------------------------------

AST* check_var() {
    int idx = lookup_var(vt, yytext);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
    }
    return new_node(VAR_USE_NODE, idx, get_type(vt, idx));
}

AST* new_var() {
    int idx = lookup_var(vt, yytext);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, yytext, get_line(vt, idx));
        exit(EXIT_FAILURE);
    }
    idx = add_var(vt, yytext, yylineno, last_decl_type);
    return new_node(VAR_DECL_NODE, idx, last_decl_type);
}

// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type rt) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(rt));
    exit(EXIT_FAILURE);
}

AST* create_conv_node(Conv conv, AST *n) {
    switch(conv) {
        case B2I:  return new_subtree(B2I_NODE, INT_TYPE,  1, n);
        case B2R:  return new_subtree(B2R_NODE, REAL_TYPE, 1, n);
        case B2S:  return new_subtree(B2S_NODE, STR_TYPE,  1, n);
        case I2R:  return new_subtree(I2R_NODE, REAL_TYPE, 1, n);
        case I2S:  return new_subtree(I2S_NODE, STR_TYPE,  1, n);
        case R2S:  return new_subtree(R2S_NODE, STR_TYPE,  1, n);
        case NONE: return n;
        default:
            printf("INTERNAL ERROR: invalid conversion of types!\n");
            exit(EXIT_FAILURE);
    }
}

AST* unify_bin_node(AST* l, AST* r,
                    NodeKind kind, const char* op, Unif (*unify)(Type,Type)) {
    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    Unif unif = unify(lt, rt);
    if (unif.type == NO_TYPE) {
        type_error(op, lt, rt);
    }
    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(kind, unif.type, 2, l, r);
}

AST* check_assign(AST *l, AST *r) {
    Type lt = get_node_type(l);
    Type rt = get_node_type(r);

    if (lt == BOOL_TYPE && rt != BOOL_TYPE) type_error(":=", lt, rt);
    if (lt == INT_TYPE  && rt != INT_TYPE)  type_error(":=", lt, rt);
    if (lt == STR_TYPE  && rt != STR_TYPE)  type_error(":=", lt, rt);

    if (lt == REAL_TYPE) {
        if (rt == INT_TYPE) {
            r = create_conv_node(I2R, r);
        } else if (rt != REAL_TYPE) {
            type_error(":=", lt, rt);
        }
    }

    return new_subtree(ASSIGN_NODE, NO_TYPE, 2, l, r);
}

void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
    exit(EXIT_FAILURE);
    }
}

AST* check_if_then(AST *e, AST *b) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 2, e, b);
}

AST* check_if_then_else(AST *e, AST *b1, AST *b2) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 3, e, b1, b2);
}

AST* check_repeat(AST *b, AST *e) {
    check_bool_expr("repeat", get_node_type(e));
    return new_subtree(REPEAT_NODE, NO_TYPE, 2, b, e);
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

    stdin = fopen(ctermid(NULL), "r");
    run_ast(root);

    fclose(stdin);
    free_str_table(st);
    free_var_table(vt);
    free_tree(root);
    yylex_destroy();    // To avoid memory leaks within flex...

    return 0;
}

%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full

%{
#include <stdio.h>
#include <stdlib.h>
#include "tables/tables.h"
int yylex(void);
void yyerror(char const *s);

void check_var();
void new_var();
void check_func();
void new_func();

StrTable* strings_table;
VarTable* variables_table;
FuncTable* functions_table;

//extern char *id_copy;
extern char id_copy[100];
extern int yylineno;

Type last_decl_type;
int last_scope = 0;
int last_scope_block = 0;

%}

%token BREAK CASE CHAR DEFAULT DO ELSE FLOAT IF INT RETURN SWITCH VOID WHILE SCAN PRINT ID COLON SUB_OP ADD_OP AST_OP DIV_OP POW_OP PER_OP EXC_OP ATR_OP AMP_OP GRT_OP LSS_OP EQ_OP DIF_OP AND_OP OR_OP LPAR RPAR LSBRACK RSBRACK SEMI COMMA LCBRACK RCBRACK NAT_VAL INT_VAL FLOAT_VAL CHAR_VAL STR_VAL

%left ADD_OP SUB_OP
%left AST_OP DIV_OP
%left POW_OP

%precedence ID
%precedence LPAR

%precedence RPAR
%precedence ELSE

%%
program:
    declaration_list

declaration_list:
    declaration_list declaration
|   declaration

declaration:
    variable_declaration
|   function_declaration

variable_declaration:
    datatype variable_declaration_list SEMI

datatype:
    INT    { last_decl_type = INT_TYPE; }
|   FLOAT  { last_decl_type = REAL_TYPE; }
|   CHAR   { last_decl_type = CHAR_TYPE; }

variable_declaration_list:
    variable_declaration_list COMMA variable_declaration_init
|   variable_declaration_init

variable_declaration_init:
    variable_declaration_id
|   variable_declaration_id ATR_OP simple_expression

variable_declaration_id:
    ID  { new_var(); }
|   ID LSBRACK INT_VAL RSBRACK  { last_decl_type += 3; new_var(); }

function_declaration:
    datatype ID { last_scope++; last_scope_block = last_scope; new_func(); } LPAR parameters RPAR compound_statement
|   VOID ID { last_scope++; last_scope_block = last_scope; last_decl_type = VOID_TYPE; new_func(); } LPAR parameters RPAR compound_statement 

parameters:
    parameters_list
|   VOID
|   %empty

parameters_list:
    parameters_list COMMA datatype parameters_ID_list
|   datatype parameters_ID_list

parameters_ID_list:
    parameters_ID_list parameter_ID
|   parameter_ID

parameter_ID:
    ID  { new_var(); }
|   ID LSBRACK RSBRACK { last_decl_type+= 3; new_var(); }
|   AST_OP ID { last_decl_type+= 3; new_var(); }

statement:
    expression_statement
|   compound_statement
|   select_statement
|   iteration_statement
|   return_statement
|   break_statement

expression_statement:
    expression SEMI
|   SEMI

compound_statement:
    LCBRACK local_declarations statement_list RCBRACK

local_declarations:
    local_declarations variable_declaration
|   %empty

statement_list:
    statement_list statement
|   %empty

select_statement:
    IF LPAR simple_expression RPAR statement { last_scope = last_scope_block; }
|   IF LPAR simple_expression RPAR statement ELSE statement { last_scope = last_scope_block; }

iteration_statement:
    WHILE LPAR simple_expression RPAR statement { last_scope = last_scope_block; }

return_statement:
    RETURN expression_statement 

break_statement:
    BREAK SEMI

expression:
    ID ATR_OP expression { check_var(); }
|   AMP_OP ID   { check_var(); }
|   ID LSBRACK expression RSBRACK ATR_OP expression { check_var(); }
|   simple_expression

simple_expression:
    simple_expression OR_OP and_expression
|   and_expression

and_expression:
    and_expression AND_OP relational_expression
|   relational_expression

relational_expression:
    minimum_maximum_expression LSS_OP minimum_maximum_expression
|   minimum_maximum_expression GRT_OP minimum_maximum_expression
|   minimum_maximum_expression GRT_OP ATR_OP minimum_maximum_expression
|   minimum_maximum_expression LSS_OP ATR_OP minimum_maximum_expression
|   minimum_maximum_expression EQ_OP minimum_maximum_expression
|   minimum_maximum_expression DIF_OP minimum_maximum_expression
|   minimum_maximum_expression

minimum_maximum_expression:
    minimum_maximum_expression sum_expression
|   sum_expression

sum_expression:
    sum_expression ADD_OP multiplication_expression
|   sum_expression SUB_OP multiplication_expression
|   multiplication_expression

multiplication_expression:
    multiplication_expression AST_OP factor
|   multiplication_expression DIV_OP factor
|   multiplication_expression PER_OP factor
|   multiplication_expression POW_OP factor
|   factor

factor:
    LPAR expression RPAR
|   builtin_call
|   constant
|   ID  { check_var(); }
|   ID LSBRACK expression RSBRACK   { check_var(); }
|   ID LPAR arguments RPAR { check_func(); }// non-builtin function call

builtin_call:
    PRINT LPAR STR_VAL COMMA arguments RPAR
|   PRINT LPAR STR_VAL RPAR
|   SCAN LPAR STR_VAL COMMA arguments RPAR


arguments:
    arguments_list
|   %empty

arguments_list:
    arguments_list COMMA expression
|   expression

constant:
    INT_VAL
|   FLOAT_VAL
|   CHAR_VAL
|   STR_VAL

%%

void check_var() {
    int idx = lookup_var(variables_table, last_scope, id_copy);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, id_copy);
        exit(EXIT_FAILURE);
    }
}

void new_var() {
    int idx = lookup_var(variables_table, last_scope, id_copy);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, id_copy, get_var_line(variables_table, idx));
        exit(EXIT_FAILURE);
    }
    add_var(variables_table, id_copy, yylineno, last_scope, last_decl_type);
}

void check_func() {
    int idx = lookup_func(functions_table, id_copy);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): function '%s' was not declared.\n",
                yylineno, id_copy);
        exit(EXIT_FAILURE);
    }
}

void new_func() {
    int idx = lookup_func(functions_table, id_copy);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): function '%s' already declared at line %d.\n",
                yylineno, id_copy, get_func_line(functions_table, idx));
        exit(EXIT_FAILURE);
    }
    add_func(functions_table, id_copy, yylineno, last_scope, last_decl_type);
}
// Primitive error handling.
void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

int main(void) {
    //yydebug = 1;
    functions_table = create_func_table();
    variables_table = create_var_table();
    strings_table = create_str_table();
    if (yyparse() == 0) printf("PARSE SUCCESSFUL!\n");
    else printf("PARSE FAILED!\n");
    print_str_table(strings_table);
    print_var_table(variables_table);
    print_func_table (functions_table);
    free_str_table (strings_table);
    free_var_table (variables_table);
    free_func_table (functions_table);
    return 0;
}
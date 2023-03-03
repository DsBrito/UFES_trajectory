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

Type check_var();
void new_var();
Type check_func();
void new_func();
Type check_args(int id);
void new_arg ();
Type unify_bin_op(Type l, Type r, const char* op, Type (*unify)(Type,Type));
void check_bool_expr(const char* cmd, Type t);
void check_index (Type i);


StrTable* strings_table;
VarTable* variables_table;
FuncTable* functions_table;

//extern char *id_copy;
extern char id_copy[100];
extern int yylineno;

Type last_decl_type;
int last_scope = 0;
int arg_counter = 0;
int current_non_builtin = 0;

%}

%define api.value.type {Type}

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
|   function_declaration { last_scope++; }

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
|   variable_declaration_id ATR_OP simple_expression { unify_bin_op($1, $3, "=", unify_atribution);}

variable_declaration_id:
    ID  { new_var(); $$ = check_var(); }
|   ID LSBRACK expression RSBRACK  { last_decl_type = get_vet(last_decl_type) ; new_var(); $$ = check_var(); }

function_declaration:
    datatype ID { new_func(); } LPAR parameters RPAR compound_statement
|   datatype AST_OP ID { last_decl_type = get_vet(last_decl_type) ; new_func(); } LPAR parameters RPAR compound_statement
|   VOID ID { last_decl_type = VOID_TYPE; new_func(); } LPAR parameters RPAR compound_statement 

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
    ID  { new_var(); new_arg();}
|   ID LSBRACK RSBRACK { last_decl_type = get_vet(last_decl_type) ; new_var(); new_arg(); }
|   AST_OP ID { last_decl_type = get_vet(last_decl_type) ; new_var(); new_arg();}

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
    IF LPAR simple_expression RPAR statement { check_bool_expr ("if", $3); }
|   IF LPAR simple_expression RPAR statement ELSE statement { check_bool_expr ("if", $3); }

iteration_statement:
    WHILE LPAR simple_expression RPAR statement { check_bool_expr ("while", $3); }

return_statement:
    RETURN expression SEMI { unify_bin_op (get_func_type (functions_table, last_scope), $2, "=", unify_atribution); }

break_statement:
    BREAK SEMI

expression:
    ID ATR_OP { $1 = check_var(); } expression { $$ = unify_bin_op($1, $4, "=", unify_atribution); }
|   AMP_OP ID   { $2 = check_var(); }
|   ID LSBRACK expression RSBRACK ATR_OP { $1 = check_var(); } expression { check_index ($3); $1 = get_elem (check_var()); $$ = unify_bin_op($1, $7, "=", unify_atribution); }
|   simple_expression

simple_expression:
    simple_expression OR_OP and_expression { $$ = unify_bin_op ($1, $3, "||", unify_comp); }
|   and_expression

and_expression:
    and_expression AND_OP relational_expression { $$ = unify_bin_op ($1, $3, "&&", unify_comp); }
|   relational_expression

relational_expression:
    minimum_maximum_expression LSS_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $3, "<", unify_comp); }
|   minimum_maximum_expression GRT_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $3, ">", unify_comp); }
|   minimum_maximum_expression GRT_OP ATR_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $4, ">=", unify_comp); }
|   minimum_maximum_expression LSS_OP ATR_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $4, "<=", unify_comp); }
|   minimum_maximum_expression EQ_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $3, "==", unify_comp); }
|   minimum_maximum_expression DIF_OP minimum_maximum_expression { $$ = unify_bin_op ($1, $3, "!=", unify_comp); }
|   minimum_maximum_expression

minimum_maximum_expression:
    minimum_maximum_expression sum_expression
|   sum_expression

sum_expression:
    sum_expression ADD_OP multiplication_expression { $$ = unify_bin_op ($1, $3, "+", unify_plus); }
|   sum_expression SUB_OP multiplication_expression { $$ = unify_bin_op ($1, $3, "-", unify_plus); }
|   multiplication_expression

multiplication_expression:
    multiplication_expression AST_OP factor { $$ = unify_bin_op ($1, $3, "*", unify_plus); }
|   multiplication_expression DIV_OP factor { $$ = unify_bin_op ($1, $3, "/", unify_plus); }
|   multiplication_expression PER_OP factor { $$ = unify_bin_op ($1, $3, "%", unify_plus); }
|   multiplication_expression POW_OP factor { $$ = unify_bin_op ($1, $3, "^", unify_plus); }
|   factor

factor:
    LPAR expression RPAR 
|   EXC_OP LPAR expression RPAR {$$ = unify_bin_op ($1, $3, "!", unify_comp);}
|   builtin_call
|   constant
|   ID LPAR { $1 = check_func(); } arguments RPAR  // non-builtin function call
|   ID LSBRACK expression RSBRACK { check_index ($3); $$ = get_elem (check_var()); }
|   ID  { $$ = check_var(); }

builtin_call:
    PRINT LPAR STR_VAL COMMA arguments_IO RPAR
|   PRINT LPAR STR_VAL RPAR
|   SCAN LPAR STR_VAL COMMA arguments_IO RPAR

arguments_IO:
    arguments_IO_list 
|   %empty

arguments_IO_list:
    arguments_IO_list COMMA expression
|   expression

arguments:
    arguments_list { arg_counter = 0;}
|   %empty

arguments_list:
    arguments_list COMMA expression { unify_bin_op(check_args(arg_counter), $3, "=", unify_param); arg_counter++; }
|   expression { unify_bin_op(check_args(arg_counter), $1, "=", unify_param); arg_counter++; }

constant:
    INT_VAL { $$ = INT_TYPE; }
|   FLOAT_VAL { $$ = REAL_TYPE; }
|   CHAR_VAL { $$ = CHAR_TYPE; }
|   STR_VAL { $$ = CHAR_VET_TYPE; }

%%

Type check_var() {
    int idx = lookup_var(variables_table, last_scope, id_copy);
    //printf ("%s %s\n", id_copy, get_text(get_var_type(variables_table, idx)));
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, id_copy);
        exit(EXIT_FAILURE);
    }
    return get_var_type (variables_table, idx);
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

Type check_func() {
    int idx = lookup_func(functions_table, id_copy);
    current_non_builtin = idx;
    //printf ("%s %s\n", id_copy, get_text(get_func_type(functions_table, idx)));
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): function '%s' was not declared.\n",
                yylineno, id_copy);
        exit(EXIT_FAILURE);
    }
    return get_func_type (functions_table, idx);
}

void new_func() {
    int idx = lookup_func(functions_table, id_copy);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): function '%s' already declared at line %d.\n",
                yylineno, id_copy, get_func_line(functions_table, idx));
        exit(EXIT_FAILURE);
    }
    add_func(functions_table, id_copy, yylineno, last_decl_type);
}

// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type t2) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
    exit(EXIT_FAILURE);
}

Type unify_bin_op(Type l, Type r, const char* op, Type (*unify)(Type,Type)) {
    //printf ("%s %s\n", get_text(l), get_text(r));
    Type unif = unify(l, r);
    if (unif == NO_TYPE) {
        type_error(op, l, r);
    }
    return unif;
}

void new_arg (){
    int idx = last_scope;
    add_args(functions_table, idx, last_decl_type);
}

Type check_args(int id){
    Type return_type = get_args (functions_table, current_non_builtin, id);
    if (return_type == NO_TYPE){
        printf("SEMANTIC ERROR (%d): function '%s' needs %d arguments.\n",
           yylineno, get_func_name (functions_table, current_non_builtin), get_func_nargs (functions_table, current_non_builtin));
        exit (EXIT_FAILURE);
    }
    //printf ("%d %s %s\n", id, id_copy, get_text (return_type));
    return return_type;
}

void check_bool_expr(const char* cmd, Type t) {
    if (t != OK_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(INT_TYPE));
        exit(EXIT_FAILURE);
    }
}

void check_index (Type i){
    unify_bin_op(INT_TYPE, i, "=", unify_atribution);
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
%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput

%{
#include<stdio.h>
#include<string.h>
#include "parser.h"
#include "tables/tables.h"
extern StrTable* strings_table;
char id_copy[100];
%}

espacos " "|"\t"|"\r"
natural_number [1-9][0-9]*|0
int_number [-]?{natural_number}
real_number [-]?[0-9][0-9]*"\."[0-9]*|0
variable [a-zA-Z_][a-zA-Z0-9_]*
%x comment

%%
{espacos}*                        {}
"\n"                              {yylineno++;}
"/*"                                BEGIN(comment);
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>"*"+"/"                    BEGIN(INITIAL);
"#".*                             {}
"//".*                            {}
"break"                           { return BREAK; }
"char"                            { return CHAR; }
"default"                         { return DEFAULT; }
"do"                              { return DO; }
"else"                            { return ELSE; }
"float"                           { return FLOAT; }
"if"                              { return IF; }
"int"                             { return INT; }
"return"                          { return RETURN; }
"void"                            { return VOID; }
"while"                           { return WHILE; }
"scanf"                           { return SCAN; }
"printf"                          { return PRINT; }
[a-zA-Z_][a-zA-Z0-9_]*            { strcpy(id_copy,yytext); return ID; }
":"                               { return COLON; }
"-"                               { return SUB_OP; }
"+"                               { return ADD_OP; }
"*"                               { return AST_OP; }
"/"                               { return DIV_OP; }
"^"                               { return POW_OP; }
"%"                               { return PER_OP; }
"!"                               { return EXC_OP; }
"="                               { return ATR_OP; }
"&"                               { return AMP_OP; }
">"                               { return GRT_OP; }
"<"                               { return LSS_OP; }
"=="                              { return EQ_OP; }
"!="                              { return DIF_OP; }
"&&"                              { return AND_OP; }
"||"                              { return OR_OP; }
"("                               { return LPAR; }
")"                               { return RPAR; }
"["                               { return LSBRACK; }
"]"                               { return RSBRACK; }
";"                               { return SEMI; }
","                               { return COMMA; }
"{"                               { return LCBRACK; }
"}"                               { return RCBRACK; }
{int_number}                      { return INT_VAL; }
{real_number}                     { return FLOAT_VAL; }
"'"[^']"'"                        { return CHAR_VAL; }
\"[^"]+\"                         { add_string(strings_table, yytext); return STR_VAL; }
.                                 { printf("LEXICAL ERROR: Unknown symbol %s\n", yytext); exit(EXIT_FAILURE); }
%%

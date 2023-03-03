
%output "parser.c"          // File name of generated parser.
%defines "parser.h"         // Produces a 'parser.h'
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>

int yylex(void);
void yyerror(char const *s);
%}

%token ENTER LPAR RPAR ZERO ONE IF ELSE OTHER
%precedence RPAR
%precedence ELSE

%%

stmts:
  %empty
| stmts stmt ENTER
;

stmt:
  ifstmt | OTHER;

ifstmt:
  IF LPAR expr RPAR stmt
| IF LPAR expr RPAR stmt ELSE stmt ;

expr:
  ZERO | ONE;

%%

int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL!\n");
    else                printf("PARSE FAILED!\n");
    return 0;
}

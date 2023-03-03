
%output "parser.c"          // File name of generated parser.
%defines "parser.h"         // Produces a 'parser.h'
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>

int yylex(void);
void yyerror(char const *s);

int acc = 0;
%}

%token NUMBER PLUS ENTER

%%
line:
  expr ENTER
;

expr:
  expr PLUS expr
| NUMBER            { acc += $1; }
;

%%

int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL! Result = %d\n", acc);
    else                printf("PARSE FAILED!\n");
    return 0;
}

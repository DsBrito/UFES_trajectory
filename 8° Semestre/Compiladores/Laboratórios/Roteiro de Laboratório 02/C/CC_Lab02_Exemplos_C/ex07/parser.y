
%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full

%{
#include <stdio.h>

int yylex(void);
void yyerror(char const *s);
%}

%token ENTER NUMBER PLUS MINUS TIMES OVER POW
%left PLUS MINUS   // Ops associativos a esquerda.
%left TIMES OVER   // Mais para baixo, maior precedencia.
%precedence UMINUS // Menos unario mais precedencia que binario.
%right POW         // Exponenciacao eh associativa a direita.

%%

line: expr ENTER ;
expr:
  expr PLUS expr
| expr MINUS expr
| expr TIMES expr
| expr OVER expr
| MINUS expr %prec UMINUS
| expr POW expr
| NUMBER ;

%%

int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL!\n");
    else                printf("PARSE FAILED!\n");
    return 0;
}

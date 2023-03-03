/* Reconhece o padrão de placas de carro antigas */

%{
#include<stdio.h>
%}

%%

[A-Z]{3}"-"[0-9]{4} { printf("Encontrada placa: %s\n", yytext); }
(\n|.)              { }

%%

int yywrap() {
  return 1;
}

int main() {
  yylex();
  return 0;
}

%{  /* Reconhece numeros naturais arbitrarios. */
  #include <stdio.h>
%}
/* As definicoes abaixo sao chamadas de fragmentos, que podem
   ser usadas para formar ERs. */
digito  [0-9]
naozero [1-9]
numero  ({naozero}{digito}*)|0

%%
{numero}    { printf("Encontrado numero: %s\n", yytext); }
[^ \t\n]+   { printf("Encontrado nao-numero: %s\n", yytext); }
[ \t\n]     { /* ignorados */ }
<<EOF>>     { printf("Fim de dados\n"); return 0; }
%%

int main() {
  yylex();
  return 0;
}

/* Definindo esta funcao nao precisa compilar com -lfl */
int yywrap() {
  return 1;
}

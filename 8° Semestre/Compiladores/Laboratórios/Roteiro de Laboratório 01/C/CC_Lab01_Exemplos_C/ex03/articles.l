%{ /* Reconhece os artigos em ingles a, an, the */
  #include <stdio.h>
%}
%%
[ \t]+      { } /* pula espaco em branco - acao: fazer nada. */
a|an|the    { printf("%s: eh um artigo.\n", yytext); }
[a-zA-Z]+   { printf("%s: ???\n", yytext); }
%%

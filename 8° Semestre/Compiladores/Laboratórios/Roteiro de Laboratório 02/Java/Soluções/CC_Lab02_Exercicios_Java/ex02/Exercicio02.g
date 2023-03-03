grammar Exercicio02;

line:
  expr ENTER
;

expr:
  expr (TIMES | OVER) expr
| expr (PLUS | MINUS) expr
| LPAR expr RPAR
| NUMBER
;

NUMBER: [0-9]+ ;
PLUS:   '+' ;
MINUS:  '-' ;
TIMES:  '*' ;
OVER:   '/' ;
LPAR:   '(' ;
RPAR:   ')' ;
ENTER:  '\n' ;
WS: ' ' -> skip;

grammar Exercicio01;

line:
  expr ENTER
;

expr:
  LPAR expr RPAR
| A
;

LPAR:  '(' ;
RPAR:  ')' ;
A:     'a' ;
ENTER: '\n' ;
WS:    ' ' -> skip ;

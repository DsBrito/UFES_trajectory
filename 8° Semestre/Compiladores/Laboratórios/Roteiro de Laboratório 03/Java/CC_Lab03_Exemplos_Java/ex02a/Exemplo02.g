grammar Exemplo02;

@header {
    package parser;
}

line:
  expr
;

expr:
  expr (TIMES | OVER) expr
| expr (PLUS | MINUS) expr
| NUMBER
;

NUMBER: [0-9]+ ;
PLUS:   '+' ;
MINUS:  '-' ;
TIMES:  '*' ;
OVER:   '/' ;
WS:     [ \t\n]+ -> skip;

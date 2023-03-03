grammar Exemplo02;

@header {
    package parser;
}

line:
  expr
;

expr:
  expr (TIMES | OVER) expr  # timesOver
| expr (PLUS | MINUS) expr  # plusMinus
| NUMBER                    # number
;

NUMBER: [0-9]+ ;
PLUS:   '+' ;
MINUS:  '-' ;
TIMES:  '*' ;
OVER:   '/' ;
WS:     [ \t\n]+ -> skip;

grammar Exemplo01;

@header {
    package parser;
}

expr:
    term PLUS term
;
term:
    factor TIMES factor
;
factor:
    NUMBER
;

NUMBER: [0-9]+ ;
PLUS:   '+' ;
TIMES:  '*' ;
WS:     [ \t\n]+ -> skip;

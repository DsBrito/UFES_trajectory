lexer grammar Exemplo02;

fragment DIGITS : [0-9]+ ;

WS : [ \t\n]+ -> skip ;

PLUS  : '+' ;
MINUS : '-' ;
TIMES : '*' ;
OVER  : '/' ;

POS_INT : DIGITS ;
NEG_INT : '-' DIGITS;
POS_REAL : DIGITS '.' DIGITS ;
NEG_REAL : '-' DIGITS '.' DIGITS ;

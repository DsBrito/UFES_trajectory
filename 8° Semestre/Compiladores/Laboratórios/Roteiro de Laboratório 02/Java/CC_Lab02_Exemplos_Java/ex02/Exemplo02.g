grammar Exemplo02;

begin:
  (expr SEMI)+
;

expr:
  expr PLUS expr
| expr (LT | GT | EQ) expr
| INT_VAL
;

INT_VAL : [0-9]+ ;
PLUS    : '+'    ;
LT      : '<'    ;
GT      : '>'    ;
EQ      : '='    ;
SEMI    : ';'    ;
WS      : [ \t\n]+ -> skip ;

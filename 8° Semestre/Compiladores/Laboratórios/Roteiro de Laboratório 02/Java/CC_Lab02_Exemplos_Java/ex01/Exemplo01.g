grammar Exemplo01;

begin:
  expr
;

expr:
  INT_VAL op INT_VAL SEMI
| INT_VAL SEMI
;

op:
  EQ | LT | GT
;

INT_VAL : [0-9]+ ;
LT      : '<'    ;
GT      : '>'    ;
EQ      : '='    ;
SEMI    : ';'    ;
WS      : [ \t\n]+ -> skip ;

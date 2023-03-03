grammar Exemplo03;

begin:
  switch_stmt
;
switch_stmt:
  SWITCH ID LBRACE case_stmt+ default_stmt? RBRACE
;
case_stmt:
  CASE INT_VAL COLON BREAK SEMI
;
default_stmt:
  DEFAULT COLON
;

SWITCH  : 'switch';
CASE    : 'case';
DEFAULT : 'default';
BREAK   : 'break';
COLON   : ':' ;
SEMI    : ';' ;
LBRACE  : '{' ;
RBRACE  : '}' ;
INT_VAL : [0-9]+ ;
ID      : [a-zA-Z]+ ;
WS      : [ \t\n]+ -> skip ;

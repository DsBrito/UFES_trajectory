grammar Exercicio03;

stmts:
  (stmt ENTER)*
;

stmt:
  ifstmt
| OTHER
;

ifstmt:
  IF LPAR expr RPAR stmt
| IF LPAR expr RPAR stmt ELSE stmt
;

expr:
  ZERO
| ONE
;

ZERO:  '0' ;
ONE:   '1' ;
IF:    'if' ;
ELSE:  'else' ;
OTHER: 'other' ;
LPAR:  '(' ;
RPAR:  ')' ;
ENTER: '\n' ;
WS: ' ' -> skip;


lexer grammar EZLexer;

@header {
    package parser;
}

WS       : [ \t\n]+      -> skip ;
COMMENTS : '{' ~[}]* '}' -> skip ;

BEGIN   : 'begin'   ;
BOOL    : 'bool'    ;
ELSE    : 'else'    ;
END     : 'end'     ;
FALSE   : 'false'   ;
IF      : 'if'      ;
INT     : 'int'     ;
PROGRAM : 'program' ;
READ    : 'read'    ;
REAL    : 'real'    ;
REPEAT  : 'repeat'  ;
STRING  : 'string'  ;
THEN    : 'then'    ;
TRUE    : 'true'    ;
UNTIL   : 'until'   ;
VAR     : 'var'     ;
WRITE   : 'write'   ;

ASSIGN : ':=' ;
EQ     : '='  ;
LPAR   : '('  ;
LT     : '<'  ;
MINUS  : '-'  ;
OVER   : '/'  ;
PLUS   : '+'  ;
RPAR   : ')'  ;
SEMI   : ';'  ;
TIMES  : '*'  ;

INT_VAL  : [0-9]+            ;
REAL_VAL : [0-9]+ '.' [0-9]+ ;
STR_VAL  : '"' ~["]* '"'     ;

ID : [a-zA-Z]+ ;

UNKNOWN : . ;

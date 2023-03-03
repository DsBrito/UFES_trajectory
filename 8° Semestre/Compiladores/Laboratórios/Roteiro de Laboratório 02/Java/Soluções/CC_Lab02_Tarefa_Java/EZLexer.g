// O ANTLR permite declarar os componentes léxicos e sintáticos em um mesmo
// arquivo, mas vamos continuar usando um arquivo para o scanner (lexer) e
// um outro para o parser, pois isto facilita a organização.

lexer grammar EZLexer;

// Reconhece e descarta espaços em branco e comentários.
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

// O ANTLR já possui um sistema de tratamento de erros embutido. Assim, não
// é necessária uma regra para detectar e indicar os erros léxicos.
// Veja a execução para um dos casos de teste 'lexerr0[1-3].ezl'.
// No entando, precisamos de um tipo de token adicional, caso contrário o ANTLR
// continua a análise sintática mesmo quando há erros léxicos.
UNKNOWN : . ;

// Quando só temos um scanner (lexer), precisamos indicar na declaração da
// gramática, como abaixo.
lexer grammar EZLexer;

// Reconhece e descarta espaços em branco e comentários.
WS       : [ \t\n]+      -> skip ;
COMMENTS : '{' ~[}]* '}' -> skip ; // no flex a expressão do meio seria [^}]*

// Note que não são necessários comandos de impressão abaixo porque o ANTLR
// já exibe os tokens no terminal por padrão.

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
// Isso será útil no próximo laboratório.
UNKNOWN : . ;

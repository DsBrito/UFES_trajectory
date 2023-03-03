// Cria a gramática do analisador sintático (parser).

parser grammar EZParser;

options {
    tokenVocab = EZLexer; // Indica que os tokens estão na "lexer grammar".
}

// Regra inicial da gramática.
program:
  PROGRAM ID SEMI vars_sect stmt_sect
;

// Uso de EBNF permite simplificações na gramática, através dos fechos '*' e '+',
// e do uso do condicional '?'. Coloque a gramática BNF do bison lado a lado e
// veja as mudanças.

vars_sect:
  VAR var_decl*
;

var_decl:
  type_spec ID SEMI
;

type_spec:
  BOOL
| INT
| REAL
| STRING
;

stmt_sect:
  BEGIN stmt+ END
;

stmt:
  assign_stmt
| if_stmt
| read_stmt
| repeat_stmt
| write_stmt
;

assign_stmt:
  ID ASSIGN expr SEMI
;

if_stmt:
  IF expr THEN stmt+ (ELSE stmt+)? END
;

read_stmt:
  READ ID SEMI
;

repeat_stmt:
  REPEAT stmt+ UNTIL expr
;

write_stmt:
  WRITE expr SEMI
;

// No ANTLR a precedência dos operadores é definida pela ordem das regras.
// Regras que aparecem primeiro possuem prioridade maior. Operadores com o
// mesmo nível de prioridade precisam aparecer em uma mesma regra, como é
// o caso abaixo.

expr:
  expr (TIMES | OVER) expr
| expr (PLUS | MINUS) expr
| expr (EQ | LT) expr
| LPAR expr RPAR
| TRUE
| FALSE
| INT_VAL
| REAL_VAL
| STR_VAL
| ID
;

// Assim como para o scanner, o ANTLR já possui um sistema de tratamento de
// erros embutido para o parser. Assim, não é necessário fazer nada mais para
// tratar os erros.

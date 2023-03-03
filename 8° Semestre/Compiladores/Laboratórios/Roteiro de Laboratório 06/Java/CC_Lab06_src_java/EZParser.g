
parser grammar EZParser;

options {
    tokenVocab = EZLexer; // Indica que os tokens estão na "lexer grammar".
}

@header {
    package parser;
}

program:
  PROGRAM ID SEMI vars_sect stmt_sect
;

vars_sect:
  VAR var_decl*
;

var_decl:
  type_spec ID SEMI
;

// A identificação individual de cada regra com '#' é usada
// pelo ANTLR para gerar métodos com os nomes específicos no
// visitor gerado.
// Veja a Seção 4.2 do livro do ANTLR. 
type_spec:
  BOOL		# boolType
| INT		# intType
| REAL		# realType
| STRING    # strType
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

// O nome 'op' nas regras abaixo é para poder
// diferenciar os operadores no visitor.
expr:
  expr op=(TIMES | OVER) expr	# timesOver
| expr op=(PLUS | MINUS) expr	# plusMinus
| expr op=(EQ | LT) expr		# eqLt
| LPAR expr RPAR				# exprPar
| TRUE							# exprTrue
| FALSE							# exprFalse
| INT_VAL						# exprIntVal
| REAL_VAL						# exprRealVal
| STR_VAL						# exprStrVal
| ID							# exprId
;

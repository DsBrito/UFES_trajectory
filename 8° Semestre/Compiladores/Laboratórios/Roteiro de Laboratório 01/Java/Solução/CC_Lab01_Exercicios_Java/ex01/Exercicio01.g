lexer grammar Exercicio01;

COMMENTS: '#'~[\n]* -> skip;
OTHER: . { System.out.print(getText()); };

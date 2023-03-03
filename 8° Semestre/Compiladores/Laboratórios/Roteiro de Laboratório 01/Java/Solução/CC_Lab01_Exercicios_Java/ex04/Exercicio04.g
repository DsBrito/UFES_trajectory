lexer grammar Exercicio04;

fragment DIGIT: [0-9];
fragment ALPHA: [a-zA-Z];

PLACA: ALPHA ALPHA ALPHA '-' DIGIT DIGIT DIGIT DIGIT
       { System.out.println("Encontrada placa: " + getText()); }
     ;

OTHER: . -> skip ;

lexer grammar Exercicio02;

UPPER: [A-Z] { System.out.print(getText().toLowerCase()); } ;
OTHER: .     { System.out.print(getText()); };

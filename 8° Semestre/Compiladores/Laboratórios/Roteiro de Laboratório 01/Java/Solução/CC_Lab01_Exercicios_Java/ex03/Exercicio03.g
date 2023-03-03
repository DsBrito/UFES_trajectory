lexer grammar Exercicio03;

fragment DIGIT: [0-9];
fragment ALPHA: [a-fA-F];
fragment HEXTAIL: (DIGIT | ALPHA)+ ;

HEX: '0' [xX] HEXTAIL   {   if (getText().length() > 10) {
                                System.err.println("Hex number too long!");
                            } else {
                                System.out.println("Found a HEX number: " + getText());
                            }
                        } ;

OTHER: .     { System.out.print(getText()); };

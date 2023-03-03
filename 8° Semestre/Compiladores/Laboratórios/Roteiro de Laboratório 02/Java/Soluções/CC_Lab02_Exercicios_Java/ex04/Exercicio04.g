grammar Exercicio04;

@members {
    int acc = 0;
}

line:
  expr ENTER { System.out.println("Result = " + acc); }
;

expr:
  expr PLUS expr
| NUMBER { acc += Integer.valueOf($NUMBER.getText()); }
;

NUMBER: [0-9]+ ;
PLUS:   '+' ;
ENTER:  '\n' ;
WS: ' ' -> skip;

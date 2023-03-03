
%output "parser.c"          // File name of generated parser.
%defines "parser.h"         // Produces a 'parser.h'
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
int yylex(void);
void yyerror(char const *s);
void test_date(int, int, int);
%}
%token NUMBER SLASH ENTER
%%
dates: %empty | dates date ENTER ;
date: NUMBER SLASH NUMBER SLASH NUMBER {test_date($1, $3, $5);};
%%

int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL!\n");
    else                printf("PARSE FAILED!\n");
    return 0;
}

void test_date(int d, int m, int y) {
    printf("Testing date: %d/%d/%d\n", d, m, y);
    if (y < 1 || y > 9999) {
        printf("Invalid year: %d!\n", y);
        return;
    }
    if (m < 1 || m > 12) {
        printf("Invalid month: %d!\n", m);
        return;
    }
    if (d < 1 || d > 31) {
        printf("Invalid day: %d!\n", d);
        return;
    }
    printf("Valid date!\n");
}

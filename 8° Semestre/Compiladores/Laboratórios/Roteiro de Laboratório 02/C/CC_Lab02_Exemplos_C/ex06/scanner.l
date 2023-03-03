%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput

%{
#include "parser.h" // For the token types from bison.
%}

%%

"0"     { return ZERO; }
"1"     { return ONE; }
"if"    { return IF; }
"else"  { return ELSE; }
"other" { return OTHER; }
"("     { return LPAR; }
")"     { return RPAR; }
"\n"    { return ENTER; }
" "     { /* ignore spaces */ }
.       { printf("LEXICAL ERROR: Unknown symbol %s\n", yytext);
          exit(EXIT_FAILURE); }

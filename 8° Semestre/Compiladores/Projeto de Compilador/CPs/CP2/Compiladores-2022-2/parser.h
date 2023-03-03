/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CASE = 259,
    CHAR = 260,
    DEFAULT = 261,
    DO = 262,
    ELSE = 263,
    FLOAT = 264,
    IF = 265,
    INT = 266,
    RETURN = 267,
    SWITCH = 268,
    VOID = 269,
    WHILE = 270,
    SCAN = 271,
    PRINT = 272,
    ID = 273,
    COLON = 274,
    SUB_OP = 275,
    ADD_OP = 276,
    AST_OP = 277,
    DIV_OP = 278,
    POW_OP = 279,
    PER_OP = 280,
    EXC_OP = 281,
    ATR_OP = 282,
    AMP_OP = 283,
    GRT_OP = 284,
    LSS_OP = 285,
    EQ_OP = 286,
    DIF_OP = 287,
    AND_OP = 288,
    OR_OP = 289,
    LPAR = 290,
    RPAR = 291,
    LSBRACK = 292,
    RSBRACK = 293,
    SEMI = 294,
    COMMA = 295,
    LCBRACK = 296,
    RCBRACK = 297,
    NAT_VAL = 298,
    INT_VAL = 299,
    FLOAT_VAL = 300,
    CHAR_VAL = 301,
    STR_VAL = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

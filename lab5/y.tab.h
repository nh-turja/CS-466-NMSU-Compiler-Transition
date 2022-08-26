/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_INT = 258,
    T_VOID = 259,
    T_IF = 260,
    T_ELSE = 261,
    T_WHILE = 262,
    T_RETURN = 263,
    T_READ = 264,
    T_WRITE = 265,
    T_LE = 266,
    T_LT = 267,
    T_GT = 268,
    T_GE = 269,
    T_EQ = 270,
    T_NE = 271,
    T_BEGIN = 272,
    T_END = 273,
    T_DO = 274,
    T_TRUE = 275,
    T_FALSE = 276,
    T_NOT = 277,
    T_AND = 278,
    T_OR = 279,
    T_THEN = 280,
    T_OF = 281,
    T_BOOLEAN = 282,
    T_ID = 283,
    T_NUM = 284,
    UMINUS = 285
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_VOID 259
#define T_IF 260
#define T_ELSE 261
#define T_WHILE 262
#define T_RETURN 263
#define T_READ 264
#define T_WRITE 265
#define T_LE 266
#define T_LT 267
#define T_GT 268
#define T_GE 269
#define T_EQ 270
#define T_NE 271
#define T_BEGIN 272
#define T_END 273
#define T_DO 274
#define T_TRUE 275
#define T_FALSE 276
#define T_NOT 277
#define T_AND 278
#define T_OR 279
#define T_THEN 280
#define T_OF 281
#define T_BOOLEAN 282
#define T_ID 283
#define T_NUM 284
#define UMINUS 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "lab5cminus.y" /* yacc.c:1909  */

	int value;
	char * string;

#line 119 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

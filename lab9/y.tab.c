/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 17 "yacc.y" /* yacc.c:339  */
	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "symtable.h"
#include "ast.h"
#include "emit.h"

#define max(x,y) ((x)>(y)? (x) : (y))
// #include "lex.yy.c"


extern int mydebug;
extern int lineno;
int maxoffset=0;
int level=0;
int offset = 0;
int goffset = 0;
int moffset = 0;

static FILE *out;

int yylex();
int CompareFormals(ASTnode *formals, ASTnode *actual);

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on Line number: %d\n", s, lineno);
}



#line 103 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    T_BEGIN = 258,
    T_END = 259,
    T_DO = 260,
    T_AND = 261,
    T_OR = 262,
    T_THEN = 263,
    T_OF = 264,
    T_NOT = 265,
    T_TRUE = 266,
    T_FALSE = 267,
    T_ID = 268,
    T_QUOTED_STRING = 269,
    T_BOOLEAN = 270,
    T_NUM = 271,
    T_INT = 272,
    T_VOID = 273,
    T_IF = 274,
    T_ELSE = 275,
    T_WHILE = 276,
    T_RETURN = 277,
    T_READ = 278,
    T_WRITE = 279,
    T_LE = 280,
    T_LT = 281,
    T_GT = 282,
    T_GE = 283,
    T_EQ = 284,
    T_NE = 285,
    UMINUS = 286
  };
#endif
/* Tokens.  */
#define T_BEGIN 258
#define T_END 259
#define T_DO 260
#define T_AND 261
#define T_OR 262
#define T_THEN 263
#define T_OF 264
#define T_NOT 265
#define T_TRUE 266
#define T_FALSE 267
#define T_ID 268
#define T_QUOTED_STRING 269
#define T_BOOLEAN 270
#define T_NUM 271
#define T_INT 272
#define T_VOID 273
#define T_IF 274
#define T_ELSE 275
#define T_WHILE 276
#define T_RETURN 277
#define T_READ 278
#define T_WRITE 279
#define T_LE 280
#define T_LT 281
#define T_GT 282
#define T_GE 283
#define T_EQ 284
#define T_NE 285
#define UMINUS 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "yacc.y" /* yacc.c:355  */

	int value;
	char * string;
	ASTnode *node;
	enum OPERATORS operator;
	

#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,    32,     2,
      43,    44,    35,    33,    42,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    86,    95,    96,    99,   112,   126,
     141,   155,   173,   174,   175,   180,   201,   218,   201,   239,
     241,   246,   247,   249,   250,   254,   269,   286,   286,   300,
     303,   309,   310,   321,   322,   323,   324,   325,   326,   327,
     328,   331,   336,   342,   354,   361,   370,   377,   381,   387,
     393,   398,   405,   408,   431,   458,   459,   475,   476,   477,
     478,   479,   480,   483,   484,   501,   502,   505,   506,   522,
     523,   524,   525,   528,   529,   534,   535,   536,   540,   544,
     552,   576,   577,   580,   586
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BEGIN", "T_END", "T_DO", "T_AND",
  "T_OR", "T_THEN", "T_OF", "T_NOT", "T_TRUE", "T_FALSE", "T_ID",
  "T_QUOTED_STRING", "T_BOOLEAN", "T_NUM", "T_INT", "T_VOID", "T_IF",
  "T_ELSE", "T_WHILE", "T_RETURN", "T_READ", "T_WRITE", "T_LE", "T_LT",
  "T_GT", "T_GE", "T_EQ", "T_NE", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "';'", "'['", "']'", "','", "'('", "')'", "'='",
  "$accept", "P", "DL", "DEC", "VARDEC", "var_list", "typespec", "FUNDEC",
  "fundec_head", "$@1", "$@2", "fundec_tail", "params", "paramlist",
  "param", "compoundstmt", "$@3", "localdeclarations", "statementlist",
  "statement", "expressionstmt", "assignmentstmt", "selectionstmt",
  "iterationstmt", "returnstmt", "readstmt", "writestmt", "expression",
  "var", "simpleexpression", "relop", "additiveexpression", "addop",
  "term", "multop", "factor", "call", "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   124,    38,    43,    45,    42,    47,    37,   286,    59,
      91,    93,    44,    40,    41,    61
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      35,   -89,   -89,   -89,    33,   -89,    35,   -89,    27,   -89,
      10,   -89,   -89,    36,     4,   -89,   -89,   -89,   -89,    38,
      31,   -89,   -89,    35,    20,    28,   -89,    -1,    35,    31,
       8,    24,     1,   -89,   -89,   -89,    39,   -89,    61,   -89,
     -89,    42,   -89,    61,    61,    26,    62,    46,   -89,    61,
     -89,    76,     8,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
      48,    43,    69,   -19,    57,   -89,   -89,    31,    35,    49,
      47,    87,   -89,   -89,    61,    61,    93,   100,   -89,    67,
      68,    70,    71,    72,    63,   -89,   -89,   -89,    61,   -89,
     -89,   -89,   -89,   -89,   -89,    61,   -89,   -89,    61,   -89,
     -89,   -89,   -89,    61,   -89,   -89,   103,   -89,   -89,    73,
      74,    75,   -89,     8,     8,   -89,   -89,   -89,   -89,   -89,
      78,   -19,    57,   -89,    35,   -89,    61,   -89,    95,   -89,
     -89,   -89,   -89,     8,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    12,    13,     0,     2,     3,     5,     0,     6,
       0,     1,     4,     8,     0,    27,    19,    15,    20,     0,
       0,    16,     7,    29,     0,     8,    10,     0,    29,     0,
      31,     9,     0,    21,    17,    22,    23,    30,     0,    77,
      78,    53,    74,     0,     0,     0,     0,     0,    41,     0,
      34,     0,    31,    33,    37,    35,    36,    38,    39,    40,
       0,    75,    52,    55,    63,    67,    76,     0,     0,     0,
       0,     0,    75,    79,     0,    81,     0,     0,    47,     0,
      53,     0,     0,     0,     0,    28,    32,    42,     0,    57,
      58,    59,    60,    61,    62,     0,    65,    66,     0,    71,
      72,    69,    70,     0,    11,    25,     0,    18,    24,     0,
      83,     0,    82,     0,     0,    48,    49,    51,    50,    73,
       0,    56,    64,    68,     0,    54,     0,    80,    44,    46,
      43,    26,    84,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   107,   -89,     0,   -12,   -22,   -89,   -89,   -89,
     -89,   -89,   -89,    50,   -89,   108,   -89,    92,    77,   -88,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -40,   -30,   -89,
     -89,    29,   -89,    25,   -89,   -36,   -89,   -89,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    14,     8,     9,    10,    27,
      70,    17,    34,    35,    36,    50,    23,    30,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    72,    62,
      95,    63,    98,    64,   103,    65,    66,   111,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    29,    73,    76,    77,    79,    29,    83,    26,    84,
      68,    15,    32,    15,    96,    97,    81,    33,    38,    39,
      40,    41,    61,    28,    42,   128,   129,    43,    28,    44,
      45,    46,    47,    11,   109,   110,    38,    39,    40,    41,
      13,    69,    42,    22,    25,   134,   105,    48,   120,    16,
       1,    49,     2,     3,    24,   104,    38,    39,    40,    41,
      82,    31,    42,    99,   100,    78,    67,   123,    19,    49,
      20,    38,    39,    40,    41,    80,    19,    42,    20,    21,
      85,    71,    74,    61,    61,    75,   110,    87,    88,    49,
     106,   107,   101,   102,    89,    90,    91,    92,    93,    94,
      32,   113,   131,    61,    49,   114,   115,   119,    74,   116,
     117,   118,   124,    12,   125,   133,   126,   130,    18,   127,
      37,   108,   132,   122,   121,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
      30,    23,    38,    43,    44,    45,    28,    47,    20,    49,
       9,     3,    13,     3,    33,    34,    46,    18,    10,    11,
      12,    13,    52,    23,    16,   113,   114,    19,    28,    21,
      22,    23,    24,     0,    74,    75,    10,    11,    12,    13,
      13,    40,    16,    39,    13,   133,    68,    39,    88,    39,
      15,    43,    17,    18,    16,    67,    10,    11,    12,    13,
      14,    41,    16,     6,     7,    39,    42,   103,    40,    43,
      42,    10,    11,    12,    13,    13,    40,    16,    42,    43,
       4,    42,    40,   113,   114,    43,   126,    39,    45,    43,
      41,    44,    35,    36,    25,    26,    27,    28,    29,    30,
      13,     8,   124,   133,    43,     5,    39,    44,    40,    39,
      39,    39,     9,     6,    41,    20,    42,    39,    10,    44,
      28,    71,   126,    98,    95,    -1,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    17,    18,    47,    48,    49,    50,    52,    53,
      54,     0,    48,    13,    51,     3,    39,    57,    61,    40,
      42,    43,    39,    62,    16,    13,    51,    55,    50,    52,
      63,    41,    13,    18,    58,    59,    60,    63,    10,    11,
      12,    13,    16,    19,    21,    22,    23,    24,    39,    43,
      61,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    77,    79,    81,    82,    42,     9,    40,
      56,    42,    74,    81,    40,    43,    73,    73,    39,    73,
      13,    74,    14,    73,    73,     4,    64,    39,    45,    25,
      26,    27,    28,    29,    30,    76,    33,    34,    78,     6,
       7,    35,    36,    80,    51,    52,    41,    44,    59,    73,
      73,    83,    84,     8,     5,    39,    39,    39,    39,    44,
      73,    77,    79,    81,     9,    41,    42,    44,    65,    65,
      39,    52,    84,    20,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    52,    53,    55,    56,    54,    57,
      57,    58,    58,    59,    59,    60,    60,    62,    61,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    68,    68,    69,    70,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     2,     0,     0,     7,     1,
       1,     1,     1,     1,     3,     3,     5,     0,     5,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     6,     4,     2,     3,     3,
       3,     3,     1,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       4,     0,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 83 "yacc.y" /* yacc.c:1646  */
    {program= (yyvsp[0].node);}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "yacc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
			else {
				(yyval.node) = (yyvsp[-1].node); 
				(yyvsp[-1].node)->next = (yyvsp[0].node);
			}
		}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[-1].node);
			ASTnode *p0;
			p0 = (yyval.node);
			while (p0!=NULL)
			{
				p0->operator = (yyvsp[-2].operator);
				p0->symbol->Type = (yyvsp[-2].operator);
				p0=p0->s1;
			} 
		}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "yacc.y" /* yacc.c:1646  */
    { 
		if((Search((yyvsp[0].string), level, 0)) == NULL){
			(yyval.node) = ASTCreateNode(A_VARDEC); /* Creating Node for Variable Declaration*/
			(yyval.node)->symbol = Insert((yyvsp[0].string),0, 0, level, 1, offset);
			(yyval.node)->name = (yyvsp[0].string);
			(yyval.node)->offset=offset;
			offset +=1;
		} else{
			yyerror((yyvsp[0].string));
				yyerror("symbol is already used");
			exit(1);
		}
	
					}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "yacc.y" /* yacc.c:1646  */
    {
		if(!Search((yyvsp[-3].string), level, 0)){
			(yyval.node) = ASTCreateNode(A_VARDEC);
			(yyval.node)->name = (yyvsp[-3].string);
			(yyval.node)->value = (yyvsp[-1].value);
			(yyval.node)->symbol = Insert((yyvsp[-3].string), 0, 2,level,(yyvsp[-1].value),offset);
			(yyval.node)->offset = offset;
			offset += (yyvsp[-1].value);
		}else{
			yyerror((yyvsp[-3].string));
				yyerror("symbol is already used");
			exit(1);
		}
			
			}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "yacc.y" /* yacc.c:1646  */
    {

		if(!Search((yyvsp[-2].string), level, 0)){
			(yyval.node) = ASTCreateNode(A_VARDEC); /* Creating Node for Variable Declaration*/
			(yyval.node)->name = (yyvsp[-2].string);
			(yyval.node)->symbol = Insert((yyvsp[-2].string),0, 0, level, 1, offset);
			offset +=1;
			(yyval.node)->s1 = (yyvsp[0].node);
			} else{
			yyerror((yyvsp[-2].string));
				yyerror("symbol is already used");
			exit(1);
			}
		}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "yacc.y" /* yacc.c:1646  */
    {

		if(!Search((yyvsp[-5].string), level, 0)){
			(yyval.node) = ASTCreateNode(A_VARDEC);
			(yyval.node)->name = (yyvsp[-5].string);
			(yyval.node)->value = (yyvsp[-3].value);
			(yyval.node)->symbol = Insert((yyvsp[-5].string), 0, 2,level,(yyvsp[-3].value),offset);
			(yyval.node)->offset = offset;
			offset += (yyvsp[-3].value);
			(yyval.node)->s1 = (yyvsp[0].node);
			} else{
			yyerror((yyvsp[-5].string));
				yyerror("symbol is already used");
			exit(1);
		}

		}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 173 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_INTDEC; }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 174 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator)= A_VOIDDEC; }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 175 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_BOOLDEC; }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 180 "yacc.y" /* yacc.c:1646  */
    {
                (yyval.node)=(yyvsp[-1].node);
				if((yyvsp[0].node)!=NULL) {   /*we know this is a definition, not prototype*/  
					(yyval.node)->s2=(yyvsp[0].node);
					(yyval.node)->symbol=Search((yyval.node)->name, level, 0);
					(yyval.node)->symbol->mysize=maxoffset;
					offset=goffset; 
					maxoffset=0;
												
					}
				else {   /*we know this is a  prototype*/ 
					(yyval.node)->type=A_FUN_PROTOTYPE; 
					offset=goffset;
					struct SymbTab *p; 
					p=Search((yyval.node)->name, level, 0);
					p->IsAFunc=4;  /*to differ between definition and prototype*/ 
					Delete(1);   /*need to delete params for prototype so it does nto conflict with definition*/
					}
				}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 201 "yacc.y" /* yacc.c:1646  */
    {  
					struct SymbTab *p; 
					p=Search((yyvsp[-1].string), level, 0);

					/* not defined nor declared as prototype */ 
 			        if(p==NULL) { 
						Insert((yyvsp[-1].string),(yyvsp[-2].operator),1,level,0,0);
						goffset=offset; offset=0; 
				        }
				
					/* not defined but declared as prototype */ 
                    else if(p!=NULL && p->IsAFunc==4)  
                        {  p->IsAFunc=1; goffset=offset; offset=0;  }
							else {yyerror((yyvsp[-1].string));  printf("func already defined\n"); exit(1);}
				    	}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 218 "yacc.y" /* yacc.c:1646  */
    {
             struct SymbTab *p; p=Search((yyvsp[-3].string), level, 0);
             	if (p->fparms==NULL) /* add params, check to match params of definition and prototype  */
             		{(p->fparms)=(yyvsp[0].node);}
            	else 
					{ 
						if (CompareFormals(p->fparms, (yyvsp[0].node))!=1) 
							{yyerror((yyvsp[0].node));  
							printf("param type,name or length mismtach in definition \n"); 
						exit(1);
							}
                 	}
	  		}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 233 "yacc.y" /* yacc.c:1646  */
    {
					(yyval.node)=ASTCreateNode(A_FUNDEC);
					(yyval.node)->name=(yyvsp[-5].string); (yyval.node)->operator=(yyvsp[-6].operator);(yyval.node)->istype=(yyvsp[-6].operator);
                    (yyval.node)->s1=(yyvsp[-2].node);
                }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 239 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;  }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 241 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 246 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 247 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 249 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 251 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 255 "yacc.y" /* yacc.c:1646  */
    {
		if(Search((yyvsp[-2].string), level+1, 0)==NULL)
				{ 
			(yyval.node)=ASTCreateNode(A_PARAM);	
			(yyval.node)->name=(yyvsp[-2].string);
			(yyval.node)->operator=(yyvsp[0].operator);
			(yyval.node)->value=1; 
			(yyval.node)->symbol=Insert((yyvsp[-2].string),(yyvsp[0].operator),0,level+1,1,offset);
            (yyval.node)->istype=(yyvsp[0].operator); (yyval.node)->value=0;
			offset+=1;					
			}
		else {yyerror((yyvsp[-2].string));  printf("param name already in sym table \n"); exit(1);}
            }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "yacc.y" /* yacc.c:1646  */
    {
			
			if(Search((yyvsp[-4].string), level+1, 0)==NULL)
			{
				(yyval.node)=ASTCreateNode(A_PARAM);	
				(yyval.node)->name=(yyvsp[-4].string);
				(yyval.node)->operator=(yyvsp[0].operator);
				(yyval.node)->value=1; 
				(yyval.node)->symbol=Insert((yyvsp[-4].string),(yyvsp[0].operator),2,level+1,1,offset);
				(yyval.node)->istype=(yyvsp[0].operator); (yyval.node)->value=1;
				offset+=1;
			}
			else {yyerror((yyvsp[-4].string));  printf("param name already in sym table \n"); exit(1);}
	 					}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 286 "yacc.y" /* yacc.c:1646  */
    {level++; }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "yacc.y" /* yacc.c:1646  */
    {
				
				(yyval.node) = ASTCreateNode(A_BLOCK); /* Creating Node for Block statement inside function */
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[-1].node);
				Display();
				(yyval.node)->offset = offset;
				offset -= Delete(level);
				level--;
			}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 300 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
				}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 303 "yacc.y" /* yacc.c:1646  */
    {
					  (yyvsp[-1].node)->next=(yyvsp[0].node);
					  (yyval.node)=(yyvsp[-1].node);
				  }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 309 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 310 "yacc.y" /* yacc.c:1646  */
    {
				  if((yyvsp[-1].node) != NULL){
					  (yyvsp[-1].node)->next = (yyvsp[0].node);
					  (yyval.node) = (yyvsp[-1].node);
				  }
				  else{
					  (yyval.node) = (yyvsp[0].node);
				  }
			  }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 321 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 322 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 325 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 326 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 327 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 328 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 331 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
				(yyval.node) = ASTCreateNode(A_EXPRSTMT);
				(yyval.node)->s1 = NULL; 
			}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 336 "yacc.y" /* yacc.c:1646  */
    {
				   (yyval.node) = ASTCreateNode(A_EXPRSTMT);
				   (yyval.node)->istype = (yyvsp[-1].node)->istype;
				   (yyval.node)->s1 = (yyvsp[-1].node);
			   }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 342 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_ASSIGNSTMT);
				if (((yyvsp[-3].node)->istype == A_VOIDDEC) || ((yyvsp[-3].node)->istype != (yyvsp[-1].node)->istype)){
					yyerror("type error in assignment statement ");
					exit(1);
				}
				(yyval.node)->s1 = (yyvsp[-3].node);
				(yyval.node)->s2 = (yyvsp[-1].node);

				;
			}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 354 "yacc.y" /* yacc.c:1646  */
    { 
				(yyval.node) = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = ASTCreateNode(A_IFSTMT);
				(yyval.node)->s2->s1 = (yyvsp[0].node);
				(yyval.node)->s2->s2 = NULL;
			}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 361 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				(yyval.node)->s1 = (yyvsp[-4].node);
				(yyval.node)->s2 = ASTCreateNode(A_IFSTMT);
				(yyval.node)->s2->s1 = (yyvsp[-2].node);
				(yyval.node)->s2->s2 = (yyvsp[0].node);
			  }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 370 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_WHILESTMT); /* Creating Node for While-do Statemen*/
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[0].node);
			}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 377 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_RETURNSTMT);
			(yyval.node)->s1 = NULL;
		}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 381 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_RETURNSTMT); /* Creating Node for Return Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node); 
		   }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_READSTMT); /* Creating Node for Read Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node);
		}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 393 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_WRITESTMT); /* Creating Node for Write Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node);
		}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 398 "yacc.y" /* yacc.c:1646  */
    {
			  (yyval.node) = ASTCreateNode(A_WRITESTMT);
			  (yyval.node)->name = (yyvsp[-1].string);
			  (yyval.node)->label = CreateLabel();
		  }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 405 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 408 "yacc.y" /* yacc.c:1646  */
    {
		struct SymbTab *p;

		if((p=Search((yyvsp[0].string), level, 1)) != NULL){
			(yyval.node) = ASTCreateNode(A_IDENTIFIER); /* Creating Node for Variable Declaration*/
			(yyval.node)->name = (yyvsp[0].string);
			(yyval.node)->symbol = p;
			(yyval.node)->istype = p->Type;
			printf("Type for VAR is %d \n", p->Type);
			if(p->IsAFunc == 2)
			{
				yyerror(1);
				yyerror("variable is an array, syntax error ");
				exit(1);
			}
			
		} else{
			yyerror((yyvsp[0].string));
				yyerror("Undeclared variable");
			exit(1);
		}

		}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 431 "yacc.y" /* yacc.c:1646  */
    {

		struct SymbTab *p;

		if((p=Search((yyvsp[-3].string), level, 1)) != NULL){
			(yyval.node) = ASTCreateNode(A_IDENTIFIER); /* Creating Node for Variable Declaration*/
			(yyval.node)->name = (yyvsp[-3].string);
			(yyval.node)->s1 = (yyvsp[-1].node);
			(yyval.node)->istype = p->Type;

			if(p->IsAFunc == 2) (yyval.node)->symbol = p;

				else{
					yyerror((yyvsp[-3].string));
					yyerror("not an array, type mismatch");
					exit(1);
				}
			
		} else{
			yyerror((yyvsp[-3].string));
				yyerror("Undeclared variable");
			exit(1);
		}

	}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 458 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 459 "yacc.y" /* yacc.c:1646  */
    {
					 if((yyvsp[-2].node)->istype != (yyvsp[0].node)->istype){
						yyerror("additive type mismatch ");
						exit(1);
					 }
					 (yyval.node) = ASTCreateNode(A_EXPR);
					 (yyval.node)->s1 = (yyvsp[-2].node);
					 (yyval.node)->operator = (yyvsp[-1].operator);
					 (yyval.node)->s2 = (yyvsp[0].node);
					 (yyval.node)->istype = (yyvsp[0].node)->istype;
					 (yyval.node)->name = CreateTemp();
					 (yyval.node)->symbol= Insert((yyval.node)->name, A_INTDEC, 0, level, 1, offset);
					 offset++;
				 }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 475 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LESSTHANEQUAL; }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 476 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LESSTHAN; }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 477 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GREATERTHAN; }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 478 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GREATERTHANEQUAL; }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 479 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_EQUAL; }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 480 "yacc.y" /* yacc.c:1646  */
    { (yyval.operator) = A_NOTEQUAL; }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 483 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 484 "yacc.y" /* yacc.c:1646  */
    {

					   if((yyvsp[-2].node)->istype != (yyvsp[0].node)->istype){
						   yyerror("additive expression type mismatch ");
						   exit(1);
					   }
					   (yyval.node) = ASTCreateNode(A_EXPR); 
					   (yyval.node)->s1 = (yyvsp[-2].node); 
					   (yyval.node)->operator = (yyvsp[-1].operator); 
					   (yyval.node)->s2 = (yyvsp[0].node);
					   (yyval.node)->istype = A_INTDEC;
					   (yyval.node)->name = CreateTemp();
					   (yyval.node)->symbol = Insert((yyval.node)->name, A_INTDEC, 0, level, 1, offset);
					   offset++;
				   }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 501 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_PLUS;}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 502 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MINUS;}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 505 "yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 506 "yacc.y" /* yacc.c:1646  */
    {
		 if((yyvsp[-2].node)->istype != (yyvsp[0].node)->istype){
			 yyerror("term type mismatch ");
			 exit(1);
		 }
		 (yyval.node) = ASTCreateNode(A_EXPR); /* Creating Node for Expression */
		 (yyval.node)->s1 = (yyvsp[-2].node);
		 (yyval.node)->operator = (yyvsp[-1].operator);
		 (yyval.node)->s2 = (yyvsp[0].node);
		 (yyval.node)->istype = A_INTDEC;
		 (yyval.node)->name = CreateTemp();
		 (yyval.node)->symbol = Insert((yyval.node)->name, A_INTDEC, 0, level, 1, offset);
		 offset++;
	 }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 522 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_TIMES;}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 523 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_DIV;}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 524 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_AND;}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 525 "yacc.y" /* yacc.c:1646  */
    {(yyval.operator) = A_OR;}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 528 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 529 "yacc.y" /* yacc.c:1646  */
    { 
		   (yyval.node) = ASTCreateNode(A_NUMBER); /* Creating Node for Number */
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = (yyvsp[0].value); 
		   }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 534 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 535 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 536 "yacc.y" /* yacc.c:1646  */
    { 
		   (yyval.node) = ASTCreateNode(A_NUMBER);
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = 1; }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 540 "yacc.y" /* yacc.c:1646  */
    {  
		   (yyval.node) = ASTCreateNode(A_NUMBER);
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = 0; }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 544 "yacc.y" /* yacc.c:1646  */
    {
		   (yyval.node) = ASTCreateNode(A_EXPR);
		   (yyval.node)->operator=A_NOT;
		   (yyval.node)->istype = (yyvsp[0].node)->istype;
		   (yyval.node)->s1 = (yyvsp[0].node);
	   }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 552 "yacc.y" /* yacc.c:1646  */
    {
		
		struct SymbTab *p;

		if((p=Search((yyvsp[-3].string),0,0)) != NULL){
			if(p->IsAFunc != 1){
				yyerror((yyvsp[-3].string));
				printf("Function name not defined");
				exit(1);	
			}
		(yyval.node) = ASTCreateNode(A_CALL); /* Creating Node for Call Function*/
		(yyval.node)->s1 = (yyvsp[-1].node);
		(yyval.node)->istype = p->Type;
		(yyval.node)->name = (yyvsp[-3].string); 
		(yyval.node)->symbol = p;
		}
		else{
			yyerror((yyvsp[-3].string));
			printf("Function name not defined");
			exit(1);
		}
	}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 576 "yacc.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 577 "yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 580 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_ARGLIST); /* Creating Node for Arguments List*/
			(yyval.node)->s1 = (yyvsp[0].node); 
			(yyval.node)->istype = (yyvsp[0].node)->istype;
			(yyval.node)->next = NULL;
		}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 586 "yacc.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_ARGLIST);
			(yyval.node)->next = (yyvsp[0].node);
			(yyval.node)->s1 = (yyvsp[-2].node); 
		}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2250 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 594 "yacc.y" /* yacc.c:1906  */
 /* end rules */

int main(int argc, char * argv[])
{
	int i = 1;
	FILE *fp = NULL;
	char s[100];
	mydebug = 0;
	while(i < argc){
		if(strcmp(argv[i], "-d") == 0) 
			mydebug = 1;

		if(strcmp(argv[i], "-o") == 0){
			
			mydebug && printf("file name is %s\n",argv[i+1]);
			strcpy(s,argv[i+1]);

			strcat(s,".asm");
			
			
			mydebug && printf("opening %s\n",s);
			fp = fopen(s,"w");
			if(fp == NULL){
				printf("Can not open %s\n",s);
				exit(1);
			}
		}
		i++;
	}
	yyparse();
	if(fp == NULL){
		printf("Must provide a -o file name \n");
		exit(1);
	}
	else{
		emit_header(program, fp);
		emit_ast(program, fp);
}
	
	if(mydebug) Display();
	printf("\n Parsing Complete \n");
	
	if (mydebug) ASTprint(0, program);  /* Printing the Syntax of the Code */
}


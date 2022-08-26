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
#line 17 "lab6algol.y" /* yacc.c:339  */
	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include "symtable.h"
#include "ast.h"
// #include "lex.yy.c"



extern int mydebug;
extern int lineno;
int maxoffset;
int level=0;
int offset = 0;
int goffset = 0;

int yylex();
int CompareFormals(ASTnode *formals, ASTnode *actual);
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on Line number: %d\n", s, lineno);
}



#line 95 "y.tab.c" /* yacc.c:339  */

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
    T_BOOLEAN = 269,
    T_NUM = 270,
    T_INT = 271,
    T_VOID = 272,
    T_IF = 273,
    T_ELSE = 274,
    T_WHILE = 275,
    T_RETURN = 276,
    T_READ = 277,
    T_WRITE = 278,
    T_LE = 279,
    T_LT = 280,
    T_GT = 281,
    T_GE = 282,
    T_EQ = 283,
    T_NE = 284,
    UMINUS = 285
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
#define T_BOOLEAN 269
#define T_NUM 270
#define T_INT 271
#define T_VOID 272
#define T_IF 273
#define T_ELSE 274
#define T_WHILE 275
#define T_RETURN 276
#define T_READ 277
#define T_WRITE 278
#define T_LE 279
#define T_LT 280
#define T_GT 281
#define T_GE 282
#define T_EQ 283
#define T_NE 284
#define UMINUS 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "lab6algol.y" /* yacc.c:355  */

	int value;
	char * string;
	ASTnode *node;
	enum OPERATORS operator;
	

#line 203 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,    31,     2,
      42,    43,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    77,    78,    87,    88,    91,   104,   118,
     133,   147,   165,   166,   167,   172,   193,   210,   193,   231,
     233,   238,   239,   241,   242,   246,   261,   278,   278,   292,
     295,   301,   302,   313,   314,   315,   316,   317,   318,   319,
     320,   323,   328,   334,   346,   353,   362,   369,   373,   379,
     385,   391,   394,   417,   444,   445,   461,   462,   463,   464,
     465,   466,   469,   470,   487,   488,   491,   492,   508,   509,
     510,   511,   514,   515,   520,   521,   522,   526,   530,   538,
     562,   563,   566,   572
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BEGIN", "T_END", "T_DO", "T_AND",
  "T_OR", "T_THEN", "T_OF", "T_NOT", "T_TRUE", "T_FALSE", "T_ID",
  "T_BOOLEAN", "T_NUM", "T_INT", "T_VOID", "T_IF", "T_ELSE", "T_WHILE",
  "T_RETURN", "T_READ", "T_WRITE", "T_LE", "T_LT", "T_GT", "T_GE", "T_EQ",
  "T_NE", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'",
  "'['", "']'", "','", "'('", "')'", "'='", "$accept", "P", "DL", "DEC",
  "VARDEC", "var_list", "typespec", "FUNDEC", "fundec_head", "$@1", "$@2",
  "fundec_tail", "params", "paramlist", "param", "compoundstmt", "$@3",
  "localdeclarations", "statementlist", "statement", "expressionstmt",
  "assignmentstmt", "selectionstmt", "iterationstmt", "returnstmt",
  "readstmt", "writestmt", "expression", "var", "simpleexpression",
  "relop", "additiveexpression", "addop", "term", "multop", "factor",
  "call", "args", "arglist", YY_NULLPTR
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
     124,    38,    43,    45,    42,    47,    37,   285,    59,    91,
      93,    44,    40,    41,    61
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,   -95,   -95,   -95,    11,   -95,    45,   -95,    13,   -95,
       7,   -95,   -95,    26,    -6,   -95,   -95,   -95,   -95,    37,
      50,   -95,   -95,    45,    24,    34,   -95,    10,    45,    50,
      18,    33,    15,   -95,   -95,   -95,    40,   -95,     2,   -95,
     -95,    30,   -95,     2,     2,    38,    64,     2,   -95,     2,
     -95,    74,    18,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
      41,    47,    61,    25,    36,   -95,   -95,    50,    45,    52,
      51,    80,   -95,   -95,     2,     2,    87,    91,   -95,    59,
      60,    65,    66,    55,   -95,   -95,   -95,     2,   -95,   -95,
     -95,   -95,   -95,   -95,     2,   -95,   -95,     2,   -95,   -95,
     -95,   -95,     2,   -95,   -95,    93,   -95,   -95,    67,    68,
      62,   -95,    18,    18,   -95,   -95,   -95,   -95,    70,    25,
      36,   -95,    45,   -95,     2,   -95,    92,   -95,   -95,   -95,
     -95,    18,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    12,    13,     0,     2,     3,     5,     0,     6,
       0,     1,     4,     8,     0,    27,    19,    15,    20,     0,
       0,    16,     7,    29,     0,     8,    10,     0,    29,     0,
      31,     9,     0,    21,    17,    22,    23,    30,     0,    76,
      77,    52,    73,     0,     0,     0,     0,     0,    41,     0,
      34,     0,    31,    33,    37,    35,    36,    38,    39,    40,
       0,    74,    51,    54,    62,    66,    75,     0,     0,     0,
       0,     0,    74,    78,     0,    80,     0,     0,    47,     0,
      52,     0,     0,     0,    28,    32,    42,     0,    56,    57,
      58,    59,    60,    61,     0,    64,    65,     0,    70,    71,
      68,    69,     0,    11,    25,     0,    18,    24,     0,    82,
       0,    81,     0,     0,    48,    49,    50,    72,     0,    55,
      63,    67,     0,    53,     0,    79,    44,    46,    43,    26,
      83,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   100,   -95,    -3,   -12,   -22,   -95,   -95,   -95,
     -95,   -95,   -95,    39,   -95,   102,   -95,    85,    63,   -94,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -40,   -30,   -95,
     -95,    20,   -95,    19,   -95,   -36,   -95,   -95,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    14,     8,     9,    10,    27,
      70,    17,    34,    35,    36,    50,    23,    30,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    72,    62,
      94,    63,    97,    64,   102,    65,    66,   110,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    29,    73,    76,    77,    79,    29,    82,    26,    83,
      15,    11,    38,    39,    40,    41,    81,    42,   126,   127,
      28,    15,    61,    32,    68,    28,    13,    33,    38,    39,
      40,    41,    22,    42,   108,   109,    43,   132,    44,    45,
      46,    47,    98,    99,    49,    16,   104,   118,    38,    39,
      40,    41,    24,    42,    69,   103,    48,    95,    96,     1,
      49,     2,     3,    25,    31,    19,   121,    20,    21,    74,
     100,   101,    75,    19,    67,    20,    78,    80,    84,    86,
      49,    71,    61,    61,   109,    88,    89,    90,    91,    92,
      93,    87,   105,    32,   106,   112,   113,   114,   117,    74,
     129,    61,   122,   115,   116,   125,    12,   123,   128,   124,
     107,   131,    18,    37,   119,    85,   120,   130
};

static const yytype_uint8 yycheck[] =
{
      30,    23,    38,    43,    44,    45,    28,    47,    20,    49,
       3,     0,    10,    11,    12,    13,    46,    15,   112,   113,
      23,     3,    52,    13,     9,    28,    13,    17,    10,    11,
      12,    13,    38,    15,    74,    75,    18,   131,    20,    21,
      22,    23,     6,     7,    42,    38,    68,    87,    10,    11,
      12,    13,    15,    15,    39,    67,    38,    32,    33,    14,
      42,    16,    17,    13,    40,    39,   102,    41,    42,    39,
      34,    35,    42,    39,    41,    41,    38,    13,     4,    38,
      42,    41,   112,   113,   124,    24,    25,    26,    27,    28,
      29,    44,    40,    13,    43,     8,     5,    38,    43,    39,
     122,   131,     9,    38,    38,    43,     6,    40,    38,    41,
      71,    19,    10,    28,    94,    52,    97,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    16,    17,    46,    47,    48,    49,    51,    52,
      53,     0,    47,    13,    50,     3,    38,    56,    60,    39,
      41,    42,    38,    61,    15,    13,    50,    54,    49,    51,
      62,    40,    13,    17,    57,    58,    59,    62,    10,    11,
      12,    13,    15,    18,    20,    21,    22,    23,    38,    42,
      60,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    78,    80,    81,    41,     9,    39,
      55,    41,    73,    80,    39,    42,    72,    72,    38,    72,
      13,    73,    72,    72,     4,    63,    38,    44,    24,    25,
      26,    27,    28,    29,    75,    32,    33,    77,     6,     7,
      34,    35,    79,    50,    51,    40,    43,    58,    72,    72,
      82,    83,     8,     5,    38,    38,    38,    43,    72,    76,
      78,    80,     9,    40,    41,    43,    64,    64,    38,    51,
      83,    19,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    54,    55,    53,    56,
      56,    57,    57,    58,    58,    59,    59,    61,    60,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    67,    67,    68,    69,    69,    70,
      71,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     2,     0,     0,     7,     1,
       1,     1,     1,     1,     3,     3,     5,     0,     5,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     6,     4,     2,     3,     3,
       3,     1,     1,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     4,
       0,     1,     1,     3
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
#line 75 "lab6algol.y" /* yacc.c:1646  */
    {program= (yyvsp[0].node);}
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "lab6algol.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
			else {
				(yyval.node) = (yyvsp[-1].node); 
				(yyvsp[-1].node)->next = (yyvsp[0].node);
			}
		}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "lab6algol.y" /* yacc.c:1646  */
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
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "lab6algol.y" /* yacc.c:1646  */
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
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "lab6algol.y" /* yacc.c:1646  */
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
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "lab6algol.y" /* yacc.c:1646  */
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
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "lab6algol.y" /* yacc.c:1646  */
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
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_INTDEC; }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator)= A_VOIDDEC; }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_BOOLDEC; }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "lab6algol.y" /* yacc.c:1646  */
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
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "lab6algol.y" /* yacc.c:1646  */
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
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "lab6algol.y" /* yacc.c:1646  */
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
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 225 "lab6algol.y" /* yacc.c:1646  */
    {
					(yyval.node)=ASTCreateNode(A_FUNDEC);
					(yyval.node)->name=(yyvsp[-5].string); (yyval.node)->operator=(yyvsp[-6].operator);(yyval.node)->istype=(yyvsp[-6].operator);
                    (yyval.node)->s1=(yyvsp[-2].node);
                }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 231 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;  }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 238 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 239 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 241 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 243 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 247 "lab6algol.y" /* yacc.c:1646  */
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
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 261 "lab6algol.y" /* yacc.c:1646  */
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
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 278 "lab6algol.y" /* yacc.c:1646  */
    {level++; }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 280 "lab6algol.y" /* yacc.c:1646  */
    {
				
				(yyval.node) = ASTCreateNode(A_BLOCK); /* Creating Node for Block statement inside function */
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[-1].node);
				Display();
				(yyval.node)->offset = offset;
				offset -= Delete(level);
				level--;
			}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "lab6algol.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
				}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 295 "lab6algol.y" /* yacc.c:1646  */
    {
					  (yyvsp[-1].node)->next=(yyvsp[0].node);
					  (yyval.node)=(yyvsp[-1].node);
				  }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 301 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 302 "lab6algol.y" /* yacc.c:1646  */
    {
				  if((yyvsp[-1].node) != NULL){
					  (yyvsp[-1].node)->next = (yyvsp[0].node);
					  (yyval.node) = (yyvsp[-1].node);
				  }
				  else{
					  (yyval.node) = (yyvsp[0].node);
				  }
			  }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 313 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 314 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 315 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 316 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 317 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 318 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 319 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 320 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 323 "lab6algol.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
				(yyval.node) = ASTCreateNode(A_EXPRSTMT);
				(yyval.node)->s1 = NULL; 
			}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "lab6algol.y" /* yacc.c:1646  */
    {
				   (yyval.node) = ASTCreateNode(A_EXPRSTMT);
				   (yyval.node)->istype = (yyvsp[-1].node)->istype;
				   (yyval.node)->s1 = (yyvsp[-1].node);
			   }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 334 "lab6algol.y" /* yacc.c:1646  */
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
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 346 "lab6algol.y" /* yacc.c:1646  */
    { 
				(yyval.node) = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = ASTCreateNode(A_IFSTMT);
				(yyval.node)->s2->s1 = (yyvsp[0].node);
				(yyval.node)->s2->s2 = NULL;
			}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 353 "lab6algol.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				(yyval.node)->s1 = (yyvsp[-4].node);
				(yyval.node)->s2 = ASTCreateNode(A_IFSTMT);
				(yyval.node)->s2->s1 = (yyvsp[-2].node);
				(yyval.node)->s2->s2 = (yyvsp[0].node);
			  }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 362 "lab6algol.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_WHILESTMT); /* Creating Node for While-do Statemen*/
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[0].node);
			}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 369 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_RETURNSTMT);
			(yyval.node)->s1 = NULL;
		}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 373 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_RETURNSTMT); /* Creating Node for Return Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node); 
		   }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 379 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_READSTMT); /* Creating Node for Read Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node);
		}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 385 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_WRITESTMT); /* Creating Node for Write Statement*/
			(yyval.node)->s1 = (yyvsp[-1].node);
		}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 391 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 394 "lab6algol.y" /* yacc.c:1646  */
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
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 417 "lab6algol.y" /* yacc.c:1646  */
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
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 444 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 445 "lab6algol.y" /* yacc.c:1646  */
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
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 461 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LESSTHANEQUAL; }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 462 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LESSTHAN; }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 463 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GREATERTHAN; }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 464 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GREATERTHANEQUAL; }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 465 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_EQUAL; }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 466 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.operator) = A_NOTEQUAL; }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 469 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 470 "lab6algol.y" /* yacc.c:1646  */
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
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 487 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_PLUS;}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 488 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MINUS;}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 491 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 492 "lab6algol.y" /* yacc.c:1646  */
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
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 508 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_TIMES;}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 509 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_DIV;}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 510 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_AND;}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 511 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.operator) = A_OR;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 514 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 515 "lab6algol.y" /* yacc.c:1646  */
    { 
		   (yyval.node) = ASTCreateNode(A_NUMBER); /* Creating Node for Number */
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = (yyvsp[0].value); 
		   }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 520 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 521 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 522 "lab6algol.y" /* yacc.c:1646  */
    { 
		   (yyval.node) = ASTCreateNode(A_NUMBER);
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = 1; }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 526 "lab6algol.y" /* yacc.c:1646  */
    {  
		   (yyval.node) = ASTCreateNode(A_NUMBER);
		   (yyval.node)->istype = A_INTDEC;
		   (yyval.node)->value = 0; }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 530 "lab6algol.y" /* yacc.c:1646  */
    {
		   (yyval.node) = ASTCreateNode(A_EXPR);
		   (yyval.node)->operator=A_NOT;
		   (yyval.node)->istype = (yyvsp[0].node)->istype;
		   (yyval.node)->s1 = (yyvsp[0].node);
	   }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 538 "lab6algol.y" /* yacc.c:1646  */
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
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 562 "lab6algol.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 563 "lab6algol.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 566 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_ARGLIST); /* Creating Node for Arguments List*/
			(yyval.node)->s1 = (yyvsp[0].node); 
			(yyval.node)->istype = (yyvsp[0].node)->istype;
			(yyval.node)->next = NULL;
		}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 572 "lab6algol.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_ARGLIST);
			(yyval.node)->next = (yyvsp[0].node);
			(yyval.node)->s1 = (yyvsp[-2].node); 
		}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2228 "y.tab.c" /* yacc.c:1646  */
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
#line 580 "lab6algol.y" /* yacc.c:1906  */
 /* end rules */

int main(int argv, char * argc[])
{
	if (argv > 2) mydebug=1; 
	yyparse();
	fprintf(stderr, "The input has been syntactically checked \n");
	printf("Main symbol table START \n");
	Display();
	printf("Main symbol table END \n");
	ASTprint(0, program); /* Printing the Syntax of the Code */
}


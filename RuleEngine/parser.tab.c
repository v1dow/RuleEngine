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
#line 1 "parser.y" /* yacc.c:339  */

/****************************************************************************
parser.y
Parser for a simple calculator. The parser is implemented using a C++ class.
This is specified by selecting the -Tcpp option in AYACC (the "C++"
selection from the Target Language combo box in the AYACC Options dialog
box).


The parser implements the usual floating point arithmetic using the
addition, subtraction, multiplication and division operators, and unary
minus. Expressions can be grouped and simple error recovery is supported. In
addition it is now posssible to assign values to variables, and to use such
values in expressions.
****************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <array>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "reason.h"
#include "calc.h"
#include "optimize.h"
#include "oriAllocator.h"
#define RAND_M 32767
using namespace calc;
calc::calc_parser *parser;

mutex mtx;
condition_variable cv;
bool ready = false;
bool processed = false;

enum StatOpNo
{
    opMAX,
    opMIN,
    opMEAN,
    opMEDIAN,
    opVAR,
    opSTD
};

extern "C"
{
	extern int yylex(void);
	extern void yyerror(const char *);
	extern void scan_string(const char* str);
	extern void delete_buffer();
}

#line 128 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    AND = 258,
    OR = 259,
    MORE = 260,
    LESS = 261,
    MEQL = 262,
    LEQL = 263,
    EQL = 264,
    NOTEQL = 265,
    BING = 266,
    LIAN = 267,
    UMINUS = 268,
    NOT = 269,
    NUMBER = 270,
    LISTNUMBER = 271,
    ID = 272,
    STRID = 273,
    LID = 274,
    STRING = 275,
    ADDRESS = 276,
    IF = 277,
    LOG = 278,
    SIN = 279,
    ASIN = 280,
    COS = 281,
    ACOS = 282,
    TAN = 283,
    ATAN = 284,
    STRIN = 285,
    EXP = 286,
    POW = 287,
    SQR = 288,
    MAX = 289,
    MIN = 290,
    MAXS = 291,
    MEAN = 292,
    EMPTY = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "parser.y" /* yacc.c:355  */

	symbol* sym;
	double value;
	LISTDOUBLE* listvalue;
	char*	strvalue;
	double* address;

#line 215 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,    15,     5,    48,     6,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       7,     8,     9,    10,    11,    12,    13,    14,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   130,   130,   131,   135,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   150,   151,   154,   155,
     158,   159,   160,   161,   162,   163,   166,   167,   168,   169,
     170,   171,   172,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   187,   189,   190,   191,   192,
     194,   195,   196,   197,   199,   200,   201,   202,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   223,   224,   225,   226,   229,
     230,   231,   232,   233,   234,   235,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "'+'", "'-'", "MORE",
  "LESS", "MEQL", "LEQL", "EQL", "NOTEQL", "BING", "LIAN", "'*'", "'/'",
  "UMINUS", "NOT", "NUMBER", "LISTNUMBER", "ID", "STRID", "LID", "STRING",
  "ADDRESS", "IF", "LOG", "SIN", "ASIN", "COS", "ACOS", "TAN", "ATAN",
  "STRIN", "EXP", "POW", "SQR", "MAX", "MIN", "MAXS", "MEAN", "EMPTY",
  "'\\n'", "';'", "'='", "'('", "')'", "','", "$accept", "lines", "line",
  "stmt", "logexpr", "table", "expr", "listexpr", "strexpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    43,    45,   260,   261,   262,
     263,   264,   265,   266,   267,    42,    47,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,    10,    59,    61,    40,    41,    44
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,    92,   -38,   -23,   448,   484,   -38,   -38,    -8,    -1,
     -15,     5,   -24,   -11,     1,    19,    33,    51,    55,    60,
      80,    91,   117,   118,   122,   126,   -38,   448,   -38,    -5,
     -27,   136,    74,    -3,   -38,    50,   -38,     2,   484,   -38,
     542,    18,   151,   374,    61,    64,    65,    72,    58,     4,
     155,   156,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,     9,     9,   153,     9,   184,   -38,   -38,   138,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   -38,   139,   448,   -38,   140,    85,   112,
     145,   149,   -38,   142,   448,   411,   164,   184,   -38,   -38,
     -38,   -38,   528,    -2,   -38,   -38,    -2,   -38,    -2,   -38,
      -2,   181,    -2,   -38,   181,   -38,   -38,   -38,   -38,   198,
     212,   231,   245,   259,   278,   292,   306,   150,   325,   165,
     178,   182,   179,   -38,   -38,   542,     2,   554,   554,   134,
     134,   134,   134,   134,   134,   134,   134,   -38,   -38,   -38,
     542,     2,   -38,    -2,   -38,    -2,   -38,    -2,   -38,    -2,
     181,   -38,   542,     2,   542,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   448,   -38,   -38,   -38,   448,   -38,
     339,   353,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    60,    75,    32,    86,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     2,     0,
       0,     0,     0,     0,    15,    32,    59,     0,     0,    45,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     0,    12,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,    29,    27,
      31,    17,    26,    85,    79,    83,    49,    47,    57,    55,
      53,    51,    86,    80,    81,    77,    76,    30,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     9,    24,    25,    37,    38,    33,
      34,    42,    41,    40,    39,    43,    44,    35,    36,     6,
      20,    21,    13,    84,    82,    48,    46,    56,    54,    52,
      50,    11,    22,    23,    26,    18,    70,    61,    62,    64,
      65,    66,    67,    69,     0,    63,    71,    73,     0,    74,
       0,     0,    68,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   -38,   154,   191,   -38,    -4,   -37,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    28,    29,    39,    30,    31,    32,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    40,    88,    44,    44,    41,    42,    88,    89,    90,
      45,    46,   116,    89,    90,    33,    68,    69,    50,    51,
      34,    70,    52,    66,     7,   129,   130,    10,   132,     7,
      49,    91,    10,    47,    97,    53,    91,    43,    67,   102,
      92,    93,    98,    48,    48,    94,   115,    54,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   105,   107,
     109,   111,   114,    41,    42,    55,   135,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    56,
     112,   150,   104,   103,   136,   104,   106,   108,   104,   104,
     162,   164,     2,     3,   110,    95,   104,    57,     4,   151,
     113,    58,   154,   156,   158,   160,    59,   153,   163,   104,
       5,     6,     7,     8,     9,    10,    11,    86,    87,    12,
      13,    14,    15,    16,    17,    18,    60,    19,    20,    21,
      22,    23,    24,    25,   155,    26,   104,    61,    27,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    81,    82,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    62,    63,    81,    82,   157,    64,   104,
     180,   159,    65,   104,   181,    99,   117,   118,   131,    83,
      84,   134,   149,   152,    85,   161,    88,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   101,   174,    81,
      82,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   165,   176,    81,    82,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   177,   179,    81,    82,    96,
     178,   133,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,   166,    81,    82,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,   167,
      81,    82,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,    81,    82,     0,     0,   168,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,   169,    81,    82,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,   170,    81,    82,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    82,     0,     0,   171,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,   172,
      81,    82,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,   173,    81,    82,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,    81,    82,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,     0,     5,     6,     0,     8,     9,     0,    11,     0,
     183,    12,    13,    14,    15,    16,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,   100,     4,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     0,    35,     9,     0,    11,     0,     0,    12,    13,
      14,    15,    16,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,   100,     4,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,    35,
       9,     0,    11,     0,     0,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
       4,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     0,    35,     9,     0,    11,     0,
       0,    12,    13,    14,    15,    16,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      38,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     0,    81,    82,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,    81,    82,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,    81,
      82,   -16
};

static const yytype_int16 yycheck[] =
{
       4,     5,     5,     5,     5,    13,    14,     5,    11,    12,
      11,    12,    49,    11,    12,     1,    43,    44,    13,    14,
      43,    48,    46,    27,    20,    62,    63,    23,    65,    20,
      45,    34,    23,    34,    38,    46,    34,    45,    43,    43,
      43,    44,    24,    45,    45,    48,    42,    46,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    44,    45,
      46,    47,    48,    13,    14,    46,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    46,
      22,    85,    24,    22,    70,    24,    22,    22,    24,    24,
      94,    95,     0,     1,    22,    45,    24,    46,     6,    85,
      42,    46,    88,    89,    90,    91,    46,    22,    94,    24,
      18,    19,    20,    21,    22,    23,    24,    43,    44,    27,
      28,    29,    30,    31,    32,    33,    46,    35,    36,    37,
      38,    39,    40,    41,    22,    43,    24,    46,    46,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    15,
      16,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    46,    46,    15,    16,    22,    46,    24,
     174,    22,    46,    24,   178,    24,    21,    21,    25,    43,
      44,    43,    43,    43,    48,    43,     5,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    43,    48,    15,
      16,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    47,    47,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    47,    47,    15,    16,    38,
      48,    47,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    47,    15,    16,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    47,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,    -1,    -1,    47,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    47,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    47,    15,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    -1,    -1,    47,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    47,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    47,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      47,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,     6,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,     6,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
       6,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      46,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    15,    16,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     1,     6,    18,    19,    20,    21,    22,
      23,    24,    27,    28,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    43,    46,    51,    52,
      54,    55,    56,    57,    43,    21,    55,    57,    46,    53,
      55,    13,    14,    45,     5,    11,    12,    34,    45,    45,
      13,    14,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    55,    43,    43,    44,
      48,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    15,    16,    43,    44,    48,    43,    44,     5,    11,
      12,    34,    43,    44,    48,    45,    53,    55,    24,    24,
      42,    52,    55,    22,    24,    57,    22,    57,    22,    57,
      22,    57,    22,    42,    57,    42,    56,    21,    21,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    25,    56,    47,    43,    55,    57,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    43,
      55,    57,    43,    22,    57,    22,    57,    22,    57,    22,
      57,    43,    55,    57,    55,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    48,    47,    47,    47,    48,    47,
      55,    55,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     3,     1,     2,     3,
       2,     3,     2,     3,     2,     2,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     6,     4,     4,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     1
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
        case 4:
#line 135 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value); }
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value); }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-2].value);}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 139 "parser.y" /* yacc.c:1646  */
    {;}
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "parser.y" /* yacc.c:1646  */
    {  if(parser->worktype==0){parser->m_strresult = (char*)(yyvsp[-1].strvalue);}  else parser->m_strresult=NULL;}
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0){parser->m_strresult = (char*)(yyvsp[-2].strvalue); } else parser->m_strresult=NULL;}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 144 "parser.y" /* yacc.c:1646  */
    {  parser->m_lresult = (LISTDOUBLE*)(yyvsp[-1].listvalue); }
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 145 "parser.y" /* yacc.c:1646  */
    {  parser->m_lresult = (LISTDOUBLE*)(yyvsp[-2].listvalue);}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 146 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value);}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "parser.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.value)=(yyvsp[0].value); }
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->assign((yyvsp[-2].sym), (yyvsp[0].value)); }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-1].value); }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].value)!=0)(yyval.value) =1; else (yyval.value) =0; }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "parser.y" /* yacc.c:1646  */
    {;}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "parser.y" /* yacc.c:1646  */
    {;}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 160 "parser.y" /* yacc.c:1646  */
    {;}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "parser.y" /* yacc.c:1646  */
    {;}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "parser.y" /* yacc.c:1646  */
    {;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "parser.y" /* yacc.c:1646  */
    {;}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->assign((yyvsp[-2].sym),(yyvsp[0].value)); }
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLIAN((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLIAN((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetBING((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetBING((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "parser.y" /* yacc.c:1646  */
    { parser->setnull((yyvsp[-2].sym)); }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.value)= parser->GetIDValue((yyvsp[0].sym)); }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) + (yyvsp[0].value); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) - (yyvsp[0].value); }
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) * (yyvsp[0].value); }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->divide((yyvsp[-2].value), (yyvsp[0].value));}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetAnd((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetOr((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLESS((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMORE((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNot((yyvsp[0].value)); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-1].value); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = -(yyvsp[0].value); }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = sin((yyvsp[-1].value)); }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = asin((yyvsp[-1].value)); }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = sqrt((yyvsp[-1].value)); }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = cos((yyvsp[-1].value)); }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = acos((yyvsp[-1].value)); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = tan((yyvsp[-1].value)); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = atan((yyvsp[-1].value)); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->exponent2((yyvsp[-3].value),(yyvsp[-1].value)); }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = exp((yyvsp[-1].value)); }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = log((yyvsp[-1].value)); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMax((yyvsp[-1].listvalue)); }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMaxs((yyvsp[-3].address),(yyvsp[-1].value)); }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMin((yyvsp[-1].listvalue)); }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMean((yyvsp[-1].listvalue)); }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = (yyvsp[0].listvalue); }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = parser->assignlist((yyvsp[-2].sym),(yyvsp[0].listvalue)); }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 225 "parser.y" /* yacc.c:1646  */
    { parser->setlistnull((yyvsp[-2].sym)); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = parser->GetLIDValue((yyvsp[0].sym)); }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 229 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = (yyvsp[0].strvalue); }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 230 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)parser->setnull((yyvsp[-2].sym)); }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 231 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->assignchar((yyvsp[-2].sym), (yyvsp[0].strvalue)); }
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 232 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].strvalue),(yyvsp[0].strvalue));}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 233 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].sym),(yyvsp[0].strvalue));}
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 234 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].strvalue),(yyvsp[0].sym));}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 235 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].sym),(yyvsp[0].sym));}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 236 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->GetIDCharValue((yyvsp[0].sym)); }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1986 "parser.tab.c" /* yacc.c:1646  */
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
#line 238 "parser.y" /* yacc.c:1906  */


	void yyerror(const char *msg)
{
	printf("Error Message:%s\n", msg);
}

string ConvertToString(double value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

string ConvertListToString(LISTDOUBLE *lb)
{
	string s = "[";
	for (auto it = lb->begin(); it != lb->end(); it++)
	{
		double d;
		d = *it;
		s += to_string(d);
		if (it != lb->end() - 1)
			s += ",";
	}
	s += "]";
	return s;
}

double genRandData(double low, double high)
{
	double value = 0;
	value = low + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (high - low)));
	return value;
}

void updateData(oriAllocator *oa)
{
	unique_lock <mutex> lck(mtx);
	double value = 0;
	bool fflag = false;
	while(1)
	{
		value = genRandData(0.8,1.5);
		fflag = oa->appendFile(value);
		if(fflag)
		{
			oa->loadFromDisk();
			ready = true;
			lck.unlock();
			cv.notify_one();
			return;
		}
	}

}

void updatePara(oriAllocator *oa, PARALIST *pl, int index)
{
	string pstring;
	string value;
	LISTDOUBLE *lv;
	PARALIST::iterator pit;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		lv = oa->GetMemData()->at(index);
		(*pit)->SetListValue(lv);
		value = ConvertListToString(lv);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		cout << "The info of para is : " << pstring << endl;
		yyparse();
	}
}

void updatePara1(PARALIST *pl, double dvalue)
{
	string pstring;
	string value;
	PARALIST::iterator pit;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		(*pit)->SetValue(dvalue);
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		cout << "The info of para is : " << pstring << endl;
		yyparse();
	}
}

void initReasonwork(reason *re, calc::calc_parser *parser)
{
	PARALIST *pl = re->GetParaList();
	TOKENLIST *tl = re->GetTokenList();
	PARALIST::iterator pit;
	TOKENLIST::iterator tit;
	string value;
	string pstring;

	string tstring;
	double dvalue = 0;
	LISTDOUBLE *lvalue = new deque<double>();
	/*
	for(pit = pl->begin();pit!=pl->end();pit++)
	{
		dvalue = 0.0;
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value+"\n";
		scan_string(pstring.c_str());
		yyparse();
	}
	*/
	lvalue->push_back(1);
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		value = ConvertListToString(lvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		yyparse();
	}
	/*
	for(tit = tl->begin();tit!=tl->end();tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent()+"\n";
		scan_string(tstring.c_str());
		yyparse();
	}
	*/
	delete lvalue;
}

void dataProduce(reason *re)
{
	PARALIST *pl = re->GetParaList();
	PARALIST::iterator pit;
	string value;
	double dvalue = 0;
	string pstring;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		dvalue = (int)(((rand() % RAND_M + 1) * 1.0 / (RAND_M + 1) * 100.0) * 100.0) / 100.0;
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		//                cout<<"The info of para is : "<< pstring<<endl;
		yyparse();
	}
}

//change
void changeParaValue(reason *re, rule *tmpRule)
{
	double value;

	string conStr = tmpRule->GetConsequent();
	int index = conStr.find('=');

	string name = conStr.substr(0, index);
	string sValue = conStr.substr(index + 1);
	value = atof(sValue.c_str());

	//独立规则没有后件参数??
	//    PARALIST *CPList=(tmpRule)->GetConParaList();
	//    PARALIST::iterator prit;
	//    for(prit = CPList->begin();prit!=CPList->end();prit++)
	//    {
	//        (*prit)->SetValue(value);
	//        cout<<"(改变的参数:"<<(*prit)->GetName()<<":"<<(*prit)->GetValue()<<")"<<endl;
	//    }

	//遍历所有参数 找到该参数再改变
	PARALIST *pl = re->GetParaList();
	PARALIST::iterator pit;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{

		if ((*pit)->GetName() == name)
		{
			(*pit)->SetValue(value);
			cout << "(改变的参数:" << (*pit)->GetName() << ":" << (*pit)->GetValue() << ")" << endl;
		}
	}
}
//change

void testReason(reason *re, calc::calc_parser *parser)
{
	RULELIST *rlist = re->GetRuleList();
	RULELIST::iterator rit;

	string rstring;

	for (rit = rlist->begin(); rit != rlist->end(); rit++)
	{
		rstring = (*rit)->GetAntecedent() + "\n";
		cout << "rstring: " << rstring << endl;
		scan_string(rstring.c_str());
		yyparse();
		cout << "parser result: " << parser->GetResult() << endl;
	}
}

void reasonRules(reason *re, calc::calc_parser *parser)
{
	TOKENLIST *tl = re->GetTokenList();
	RULELIST *rlist = re->GetRuleList();
	TOKENLIST::iterator tit;
	RULELIST::iterator rit;
	PARALIST *ptmplist = NULL;
	PARALIST::iterator ptmpit;
	string value;

	string rstring;
	string tstring;

	for (rit = rlist->begin(); rit != rlist->end(); rit++)
	{
		rstring = (*rit)->GetAntecedent() + "\n";
		cout << "rstring: " << rstring << endl;
		scan_string(rstring.c_str());
		cout << "scan success" << endl;
		yyparse();
		cout << "parser success" << endl;
		if (parser->GetResult() == 1)
		{
			cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
		}
	}
	cout << "reasonRule complete." << endl;
}

void reasonOnce(reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl)
{
	unique_lock <mutex> lck(mtx);
	cv.wait(lck, [] { return ready; });
	for (int i = 0; i < oa->GetInferRound(); i++)
	{
		updatePara(oa, pl, i);

		RULELIST *rlist = re->GetRuleList();
		RULELIST::iterator rit;
		string rstring;
		for (rit = rlist->begin(); rit != rlist->end(); rit++)
		{
			rstring = (*rit)->GetAntecedent() + "\n";
			cout << "rstring: " << rstring << endl;
			scan_string(rstring.c_str());
			cout << "scan success" << endl;
			yyparse();
			cout << "parser success" << endl;
			if (parser->GetResult() == 1)
			{
				cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
			}
		}
	}
	processed = true;
	lck.unlock();
	cv.notify_one();
}

void reasonIndeRules(reason *re, calc::calc_parser *parser)
{

	TOKENLIST *tl = re->GetTokenList();
	RULELIST *inderlist = re->GetIndeRules();
	TOKENLIST::iterator tit;
	RULELIST::iterator rit;
	PARALIST *ptmplist = NULL;
	PARALIST::iterator ptmpit;
	string value;

	string rstring;
	string tstring;

	for (tit = tl->begin(); tit != tl->end(); tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent() + "\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for (rit = inderlist->begin(); rit != inderlist->end(); rit++)
	{
		rstring = (*rit)->GetReplacedRule() + "\n";
		scan_string(rstring.c_str());
		yyparse();
		if (parser->GetResult() == 1)
		{
			//cout<<"Trigger indepedent rule: "<<(*rit)->GetRuleName()<<"---"<<(*rit)->GetAntecedent()<<endl;
			cout << "触发独立规则: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;

			//change
			//rule *tmpRule=*rit;
			changeParaValue(re, *rit);
			//change
		}
	}
}

void reasonNestedRules(reason *re, calc::calc_parser *parser)
{
	NESTEDRULELIST *nrlist = re->GetNestedRules();
	TOKENLIST *tl = re->GetTokenList();

	RULELIST::iterator nrit;

	PARALIST *ptmplist = NULL;

	PARALIST::iterator ptmpit;
	TOKENLIST *ttmplist;
	TOKENLIST::iterator ttmpit;
	TOKENLIST::iterator tit;
	NESTEDRULELIST::iterator neit;

	string tstring;
	string ntstring;
	string constring;
	string ptokenstring;

	for (tit = tl->begin(); tit != tl->end(); tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent() + "\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for (neit = nrlist->begin(); neit != nrlist->end(); neit++)
	{
		for (nrit = (*neit)->begin(); nrit != (*neit)->end(); nrit++)
		{
			ntstring = (*nrit)->GetReplacedRule() + "\n";
			//cout<<ntstring<<endl;
			scan_string(ntstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				//cout<<"Trigger nested rule: "<<(*nrit)->GetRuleName()<<"---"<<(*nrit)->GetAntecedent()<<endl;
				cout << "触发嵌套规则: " << (*nrit)->GetRuleName() << "---" << (*nrit)->GetAntecedent() << endl;

				//change
				changeParaValue(re, *nrit);
				//change

				constring = (*nrit)->GetConsequent() + "\n";
				//cout<<constring<<endl;
				//cout<<parser->GetResult()<<endl;
				scan_string(constring.c_str());
				yyparse();
				//cout<<parser->GetResult()<<endl;

				ptmplist = (*nrit)->GetConParaList();
				for (ptmpit = ptmplist->begin(); ptmpit != ptmplist->end(); ptmpit++)
				{

					ttmplist = (*ptmpit)->QuotedTokenList;
					for (ttmpit = ttmplist->begin(); ttmpit != ttmplist->end(); ttmpit++)
					{
						//cout<<"No!!!!"<<endl;
						ptokenstring = (*ttmpit)->GetTokenName() + "=" + (*ttmpit)->GetTokenContent() + "\n";
						scan_string(ptokenstring.c_str());
						yyparse();
					}
				}
				cout << endl;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int n = -1;

	parser = new calc::calc_parser();

	if (parser->create(0) != 1)
	{
		printf("Create calc_parser failed!\n");
	}

	array<int, 6> opTable{0, 0, 0, 0, 0, 0};

	if (argc == 1)
	{
		cout << "现在用随机产生的数据进行规则推理:"
			 << "(每隔三秒推理一次)" << endl
			 << endl
			 << endl;
		sleep(3);

		reason *re = new reason();
		re->InitReasonNetwork();

		srand((unsigned)time(NULL));
		initReasonwork(re, parser);

		while (1)
		{
			cout << "************" << endl;
			dataProduce(re);
			reasonIndeRules(re, parser);
			reasonNestedRules(re, parser);

			cout << "************" << endl
				 << endl
				 << endl;

			sleep(3);
		}
		delete re;
	}
	if (argc == 2)
	{

		// ifstream fin(argv[1]);
		// if(!fin)
		// {
		//     printf("no file data!\n");
		//     exit(1);
		// }

		//else
		//{
		//cout<<"现在从该文档中读入数据"<<endl;
		//sleep(1);

		int curIndex = 0;
		double value = 0;
		bool mflag = false;
		bool dflag = false;
		bool rflag = false;


		reason *re = new reason();
		re->InitReasonNetwork();
		initReasonwork(re, parser);
		oriAllocator *oa = new oriAllocator();
		optimize *opt = new optimize();
		opt->setOpTable(re);
		opt->testOp();
		srand((unsigned)time(NULL));

		PARALIST *pl = re->GetParaList();
		/*
            PARALIST::iterator pit;
            string value;
            double dvalue=0;
            string pstring;
			*/

		//ifstream fin("data.txt");
		/*
            for(pit= pl->begin();pit!=pl->end();pit++)
            {
                    fin>> dvalue;

                    //change
                    (*pit)->SetValue(dvalue);
                    //change

                    value = ConvertToString(dvalue);
                    pstring = (*pit)->GetName() + "=" + value+"\n";
                    scan_string(pstring.c_str());
                    //cout<<"The info of para is : "<< pstring<<endl;
                    yyparse();
            }
			*/

		// while (1)
		// {
		// 	value = genRandData(0.8,1.5);
		// 	cout << "value: " << value << endl;
		// 	if (mflag)
		// 	{
		// 		// for(int index = 0;index < oa->GetInferRound();index++){
		// 		// 	updatePara(oa,pl,curIndex);
		// 		// 	reasonRules(re,parser);
		// 		// 	if(index == oa->GetInferRound()-1)
		// 		// 		rflag = true;
		// 		// }
		// 		if (curIndex == oa->GetInferRound())
		// 		{
		// 			curIndex = 0;
		// 			rflag = true;
		// 		}
		// 		if (curIndex < oa->GetInferRound())
		// 		{
		// 			updatePara(oa, pl, curIndex);
		// 			cout << "reason Rule: " << curIndex << endl;
		// 			reasonRules(re, parser);
		// 			curIndex++;
		// 		}
		// 		if (dflag && rflag)
		// 		{
		// 			cout << "loadFromDisk1" << endl;
		// 			oa->loadFromDisk();
		// 			cout << "loadFromDisk2" << endl;
		// 			dflag = false;
		// 			rflag = false;
		// 		}
		// 		// else{
		// 		// 	cout<<"appendfile1"<<endl;
		// 		// 	dflag = oa->appendFile(value);
		// 		// 	cout<<"appendfile2"<<endl;
		// 		// }
		// 	}
		// 	else
		// 	{
		// 		mflag = oa->genMemData(value);
		// 	}
		// }

/*
		while(1)
		{
			value = genRandData(0.8,1.5);
			mflag = oa->genMemData(value);
			if(mflag)
				break;
		}
		//reasonOnce(re,parser,oa,pl);
		while(1){
			thread treason(reasonOnce,re,parser,oa,pl);
			updateData(oa);
			{
				unique_lock <mutex> lck(mtx);
				cv.wait(lck, [] { return processed; });
			}
			treason.join();
		}
*/


		// while(1)
		// {
		// 	value = lo + static_cast<double>(rand())/(static_cast<double>(RAND_MAX/(hi-lo)));
		// 	cout<<"value: "<<value<<endl;
		// 	if(mflag){
		// 		break;
		// 	}else{
		// 			mflag = oa->genMemData(value);
		// 		}
		// }
		// for(int i = 0;i<oa->GetMemData()->size();i++){
		// 	updatePara(oa,pl,curIndex);
		// 	//reasonRules(re,parser);
		// 	testReason(re,parser);
		// 	sleep(3);
		// }

		delete re;
		//}
	}

	delete parser;
	return n;

	/*
    int n = -1;
    parser= new calc::calc_parser();

	double* faddress;

	vector<double> v;
	double count = 0;

    if (parser->create(0)!=1) {
        printf("Create calc_parser failed!\n");
    }
    if(argc == 2 )
    {

        ifstream fin(argv[1]);
        if(!fin)
        {
            printf("no file data!\n");
            exit(1);
        }


        else
        {
			while(!fin.eof()){
				string strbuf;
				getline(fin,strbuf);
				v.push_back(atof(strbuf.c_str()));
				count++;
			}
			faddress = &v[0];
		}
		cout<<"address:"<<faddress<<endl;
		cout<<"data:"<<endl;
		for(auto iter=v.begin();iter!=v.end();iter++)
		{
			cout<<*iter<<endl;
		}
		fin.close();
	}

	yyparse();
	delete parser;
	return n;
*/
}

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

/*
mutex mtx;
condition_variable cv;
bool ready = false;
bool fileReady = false;

enum StatOpNo
{
    opMAX,
    opMIN,
    opMEAN,
    opMEDIAN,
    opVAR,
    opSTD
};
*/

extern "C"
{
	extern int yylex(void);
	extern void yyerror(const char *);
	extern void scan_string(const char* str);
	extern void delete_buffer();
}

#line 130 "parser.tab.c" /* yacc.c:339  */

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
    MEDIAN = 293,
    VAR = 294,
    STD = 295,
    EMPTY = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 65 "parser.y" /* yacc.c:355  */

	symbol* sym;
	double value;
	LISTDOUBLE* listvalue;
	char*	strvalue;
	double* address;

#line 220 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    15,     5,    51,     6,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
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
      39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   135,   135,   136,   140,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   155,   156,   159,   160,
     163,   164,   165,   166,   167,   168,   171,   172,   173,   174,
     175,   176,   177,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   192,   194,   195,   196,   197,
     199,   200,   201,   202,   204,   205,   206,   207,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   231,   232,
     233,   234,   237,   238,   239,   240,   241,   242,   243,   244
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
  "STRIN", "EXP", "POW", "SQR", "MAX", "MIN", "MAXS", "MEAN", "MEDIAN",
  "VAR", "STD", "EMPTY", "'\\n'", "';'", "'='", "'('", "')'", "','",
  "$accept", "lines", "line", "stmt", "logexpr", "table", "expr",
  "listexpr", "strexpr", YY_NULLPTR
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
     291,   292,   293,   294,   295,   296,    10,    59,    61,    40,
      41,    44
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,    98,   -35,   -34,   478,   517,   -35,   -35,    -8,    -1,
     -20,     8,   -17,   -11,    18,    36,    57,    58,    63,    66,
      74,    75,    83,    94,    96,    97,   109,   110,   123,   -35,
     478,   -35,   127,   -22,   145,     3,    -3,   -35,    21,   -35,
       2,   517,   -35,   578,    17,    89,   398,    -5,    44,    64,
      67,    -6,     0,   155,   156,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,     7,     7,   153,     7,     7,
       7,     7,   196,   -35,   -35,   134,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   -35,
     135,   478,   -35,   136,    70,    71,    78,    79,   -35,   138,
     478,   438,   137,   196,   -35,   -35,   -35,   -35,   564,    -2,
     -35,   -35,    -2,   -35,    -2,   -35,    -2,   180,    -2,   -35,
     180,   -35,   -35,   -35,   -35,   210,   224,   246,   260,   274,
     296,   310,   324,   159,   346,   139,   140,   142,   144,   147,
     148,   173,   -35,   -35,   578,     2,   590,   590,    55,    55,
      55,    55,    55,    55,    55,    55,   -35,   -35,   -35,   578,
       2,   -35,    -2,   -35,    -2,   -35,    -2,   -35,    -2,   180,
     -35,   578,     2,   578,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   478,   -35,   -35,   -35,   478,   -35,   -35,
     -35,   -35,   360,   374,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    60,    78,    32,    89,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     2,     0,     0,     0,     0,     0,    15,    32,    59,
       0,     0,    45,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,    12,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,    29,    27,    31,    17,    26,    88,
      82,    86,    49,    47,    57,    55,    53,    51,    89,    83,
      84,    80,    79,    30,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     9,    24,    25,    37,    38,    33,    34,
      42,    41,    40,    39,    43,    44,    35,    36,     6,    20,
      21,    13,    87,    85,    48,    46,    56,    54,    52,    50,
      11,    22,    23,    26,    18,    70,    61,    62,    64,    65,
      66,    67,    69,     0,    63,    71,    73,     0,    74,    75,
      76,    77,     0,     0,    68,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   -35,   149,   168,   -35,    -4,   343,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    31,    32,    42,    33,    34,    35,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    43,    94,    47,    47,    44,    45,    94,    95,    96,
      48,    49,    37,    95,    96,    36,   118,   109,   110,   110,
       7,    53,    54,    10,    74,    75,    72,     7,    52,    76,
      10,    97,    55,    50,    44,    45,    97,   103,    56,   119,
      46,   104,   108,    98,    99,   121,    51,    51,   100,    92,
      93,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   111,   113,   115,   117,   120,   112,    57,   110,   101,
      87,    88,   144,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    58,   114,   159,   110,   116,
     145,   110,   162,   164,   110,   110,   171,   173,     2,     3,
     166,   168,   110,   110,     4,   160,    59,    60,   163,   165,
     167,   169,    61,   105,   172,    62,     5,     6,     7,     8,
       9,    10,    11,    63,    64,    12,    13,    14,    15,    16,
      17,    18,    65,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    66,    29,    67,    68,    30,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    69,    70,
      87,    88,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    71,    73,    87,    88,   123,   124,   137,   192,
     143,   158,   161,   193,   170,    94,     0,   174,     0,   185,
     186,    89,    90,   187,   188,   107,    91,   189,   190,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   102,
     183,    87,    88,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   191,     0,    87,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    87,
      88,     0,     0,     0,     0,     0,   142,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
     175,    87,    88,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,   176,    87,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    87,
      88,     0,     0,     0,     0,     0,   177,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
     178,    87,    88,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,   179,    87,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    87,
      88,     0,     0,     0,     0,     0,   180,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
     181,    87,    88,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,   182,    87,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    87,
      88,     0,     0,     0,     0,   122,   184,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     0,   135,   136,
     194,   138,   139,   140,   141,     0,     5,     6,     0,     8,
       9,     0,    11,     0,   195,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   106,     4,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,    38,
       9,     0,    11,     0,     0,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   106,     4,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,    38,
       9,     0,    11,     0,     0,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     4,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     0,    38,     9,
       0,    11,     0,     0,    12,    13,    14,    15,    16,    17,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,    41,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    87,
      88,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,    87,    88,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,    87,    88,     0,     0,     0,
     -16
};

static const yytype_int16 yycheck[] =
{
       4,     5,     5,     5,     5,    13,    14,     5,    11,    12,
      11,    12,    46,    11,    12,     1,    22,    22,    24,    24,
      20,    13,    14,    23,    46,    47,    30,    20,    48,    51,
      23,    34,    49,    34,    13,    14,    34,    41,    49,    45,
      48,    24,    46,    46,    47,    45,    48,    48,    51,    46,
      47,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    47,    48,    49,    50,    51,    22,    49,    24,    48,
      15,    16,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    49,    22,    91,    24,    22,
      76,    24,    22,    22,    24,    24,   100,   101,     0,     1,
      22,    22,    24,    24,     6,    91,    49,    49,    94,    95,
      96,    97,    49,    24,   100,    49,    18,    19,    20,    21,
      22,    23,    24,    49,    49,    27,    28,    29,    30,    31,
      32,    33,    49,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    49,    46,    49,    49,    49,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    49,    49,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    49,    46,    15,    16,    21,    21,    25,   183,
      46,    46,    46,   187,    46,     5,    -1,    50,    -1,    50,
      50,    46,    47,    51,    50,    46,    51,    50,    50,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    41,
      51,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    50,    -1,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      50,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    50,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      50,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    50,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      50,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    50,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    52,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    65,    66,
      50,    68,    69,    70,    71,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    50,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     6,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     6,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     6,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,
      46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     1,     6,    18,    19,    20,    21,    22,
      23,    24,    27,    28,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    46,
      49,    54,    55,    57,    58,    59,    60,    46,    21,    58,
      60,    49,    56,    58,    13,    14,    48,     5,    11,    12,
      34,    48,    48,    13,    14,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    58,    46,    46,    47,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    15,    16,    46,
      47,    51,    46,    47,     5,    11,    12,    34,    46,    47,
      51,    48,    56,    58,    24,    24,    45,    55,    58,    22,
      24,    60,    22,    60,    22,    60,    22,    60,    22,    45,
      60,    45,    59,    21,    21,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    25,    59,    59,
      59,    59,    50,    46,    58,    60,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    46,    58,
      60,    46,    22,    60,    22,    60,    22,    60,    22,    60,
      46,    58,    60,    58,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    50,    50,    50,    51,    50,    50,
      50,    50,    58,    58,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60
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
       4,     4,     6,     4,     4,     4,     4,     4,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1
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
#line 140 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value); }
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 142 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value); }
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 143 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-2].value);}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 144 "parser.y" /* yacc.c:1646  */
    {;}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "parser.y" /* yacc.c:1646  */
    {  if(parser->worktype==0){parser->m_strresult = (char*)(yyvsp[-1].strvalue);}  else parser->m_strresult=NULL;}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0){parser->m_strresult = (char*)(yyvsp[-2].strvalue); } else parser->m_strresult=NULL;}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "parser.y" /* yacc.c:1646  */
    {  parser->m_lresult = (LISTDOUBLE*)(yyvsp[-1].listvalue); }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "parser.y" /* yacc.c:1646  */
    {  parser->m_lresult = (LISTDOUBLE*)(yyvsp[-2].listvalue);}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "parser.y" /* yacc.c:1646  */
    {  parser->m_result = (double)(yyvsp[-1].value);}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "parser.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.value)=(yyvsp[0].value); }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->assign((yyvsp[-2].sym), (yyvsp[0].value)); }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-1].value); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].value)!=0)(yyval.value) =1; else (yyval.value) =0; }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 163 "parser.y" /* yacc.c:1646  */
    {;}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "parser.y" /* yacc.c:1646  */
    {;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "parser.y" /* yacc.c:1646  */
    {;}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 166 "parser.y" /* yacc.c:1646  */
    {;}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 167 "parser.y" /* yacc.c:1646  */
    {;}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 168 "parser.y" /* yacc.c:1646  */
    {;}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->assign((yyvsp[-2].sym),(yyvsp[0].value)); }
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLIAN((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLIAN((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetBING((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetBING((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "parser.y" /* yacc.c:1646  */
    { parser->setnull((yyvsp[-2].sym)); }
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.value)= parser->GetIDValue((yyvsp[0].sym)); }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) + (yyvsp[0].value); }
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) - (yyvsp[0].value); }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-2].value) * (yyvsp[0].value); }
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->divide((yyvsp[-2].value), (yyvsp[0].value));}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetAnd((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetOr((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetLESS((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMORE((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].value),(yyvsp[0].value)); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNot((yyvsp[0].value)); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetEQL((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStrIn((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].strvalue),(yyvsp[0].strvalue)); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].sym),(yyvsp[0].strvalue)); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].strvalue),(yyvsp[0].sym)); }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetNOTEQL((yyvsp[-2].sym),(yyvsp[0].sym)); }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-1].value); }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = -(yyvsp[0].value); }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = sin((yyvsp[-1].value)); }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = asin((yyvsp[-1].value)); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = sqrt((yyvsp[-1].value)); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = cos((yyvsp[-1].value)); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = acos((yyvsp[-1].value)); }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = tan((yyvsp[-1].value)); }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = atan((yyvsp[-1].value)); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->exponent2((yyvsp[-3].value),(yyvsp[-1].value)); }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = exp((yyvsp[-1].value)); }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = log((yyvsp[-1].value)); }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMax((yyvsp[-1].listvalue)); }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMaxs((yyvsp[-3].address),(yyvsp[-1].value)); }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMin((yyvsp[-1].listvalue)); }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMean((yyvsp[-1].listvalue)); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetMedian((yyvsp[-1].listvalue)); }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetVar((yyvsp[-1].listvalue)); }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.value) = parser->GetStd((yyvsp[-1].listvalue)); }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = (yyvsp[0].listvalue); }
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = parser->assignlist((yyvsp[-2].sym),(yyvsp[0].listvalue)); }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 233 "parser.y" /* yacc.c:1646  */
    { parser->setlistnull((yyvsp[-2].sym)); }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.listvalue) = parser->GetLIDValue((yyvsp[0].sym)); }
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 237 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = (yyvsp[0].strvalue); }
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 238 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)parser->setnull((yyvsp[-2].sym)); }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 239 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->assignchar((yyvsp[-2].sym), (yyvsp[0].strvalue)); }
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 240 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].strvalue),(yyvsp[0].strvalue));}
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 241 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].sym),(yyvsp[0].strvalue));}
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 242 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].strvalue),(yyvsp[0].sym));}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 243 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->AddString((yyvsp[-2].sym),(yyvsp[0].sym));}
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 244 "parser.y" /* yacc.c:1646  */
    { if(parser->worktype==0)(yyval.strvalue) = parser->GetIDCharValue((yyvsp[0].sym)); }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2022 "parser.tab.c" /* yacc.c:1646  */
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
#line 246 "parser.y" /* yacc.c:1906  */


	void yyerror(const char *msg)
{
	printf("Error Message:%s\n", msg);
}

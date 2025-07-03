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


/* Substitute the variable and function names.  */
#define yyparse         preparse
#define yylex           prelex
#define yyerror         preerror
#define yydebug         predebug
#define yynerrs         prenerrs

#define yylval          prelval
#define yychar          prechar

/* Copy the first part of user declarations.  */
#line 16 "ppre.y" /* yacc.c:339  */


  /* -------- System includes:  -------------------------------------------- */

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../symtab.h"

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern FILE *ppfp, *ppfp2;

static  char    tmp_str3[128];
static  int     str2int(char *ptr);

int hasdefine = 2;


#line 104 "parser/ppre.yacc.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int predebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    DIV = 261,
    MOD = 262,
    OR = 263,
    AND = 264,
    XOR = 265,
    NOT = 266,
    LSHIFT = 267,
    RSHIFT = 268,
    PAREN1 = 269,
    PAREN2 = 270,
    CH = 271,
    ID = 272,
    SP = 273,
    NL = 274,
    STR = 275,
    COMMENT = 276,
    NUM = 277,
    MAC = 278,
    IFDEF = 279,
    ENDIF = 280,
    ELSE = 281,
    ELIFDEF = 282,
    DEF = 283,
    UNDEF = 284,
    ERR = 285,
    MSG = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 46 "ppre.y" /* yacc.c:355  */
                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */

#line 182 "parser/ppre.yacc.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE prelval;

int preparse (void);



/* Copy the second part of user declarations.  */

#line 199 "parser/ppre.yacc.c" /* yacc.c:358  */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    98,   102,   106,   110,   114,   118,
     122,   126,   130,   134,   138,   144,   149,   154,   169,   174,
     190,   204,   224,   239,   257,   264,   275,   276,   279,   280,
     281,   284,   285,   288,   289,   290,   293,   294,   297,   298,
     299,   300,   301,   303,   309,   314,   319,   324,   329,   334,
     341,   355,   364,   367,   373,   379,   385,   391,   399,   402,
     408,   416,   419,   425,   431,   439,   442,   446,   455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULT", "DIV", "MOD",
  "OR", "AND", "XOR", "NOT", "LSHIFT", "RSHIFT", "PAREN1", "PAREN2", "CH",
  "ID", "SP", "NL", "STR", "COMMENT", "NUM", "MAC", "IFDEF", "ENDIF",
  "ELSE", "ELIFDEF", "DEF", "UNDEF", "ERR", "MSG", "$accept", "all1",
  "all2", "def1", "undef1", "err1", "msg1", "mac1", "ifdef1", "elifdef1",
  "endif1", "else1", "sp1", "sp1a", "sp2", "spnl", "ch2", "ops1", "ch1",
  "id1", "num1", "expr1", "expr2", "expr3", "expr4", "expr5", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      64,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    75,   -51,
     -51,   -51,     7,   -51,     7,     7,    17,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    48,    40,   102,
     -51,   -51,   -51,   -51,     6,     1,    23,   -51,   -51,   -51,
      38,    45,    54,   -51,   -51,    70,    92,    70,    96,    96,
      78,    78,   -51,    78,   -51,   -51,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,     7,    92,    92,   -51,
      24,   -51,   -51,   -51,   -51,    28,    74,   121,   -51,   123,
     -51,   -51,    80,    80,    94,     1,     1,     1,     1,     1,
      23,    23,   -51,   -51,   -51,   107,   -51,   -51,    92,   -51,
      92,    92,    92,   -51,   -16,   -51,   116,    92,   -51,   -51,
     -51,   -51,    -5,   -51,    78,    94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      26,    38,    39,    40,    41,    42,    43,    50,    45,    47,
      48,    49,    26,    25,    26,    26,    26,     2,     4,     5,
       6,     7,     8,     9,    10,    12,    11,     0,     0,    13,
      46,    36,    44,    14,    51,    52,    58,    61,    65,    27,
       0,     0,     0,     1,     3,     0,     0,     0,     0,     0,
      28,    28,    30,    28,    45,    37,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    26,     0,     0,    31,
       0,    33,    34,    35,    24,     0,    33,     0,    16,     0,
      18,    29,    28,    28,    68,    53,    55,    54,    57,    56,
      59,    60,    62,    63,    64,     0,    19,    20,     0,    32,
       0,     0,     0,    29,     0,    67,    28,     0,    22,    23,
      15,    17,     0,    21,    28,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    85,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,    -3,   -50,    83,   -41,   -51,   -51,    87,   -51,
     -51,    50,    -7,    81,    72,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    70,    74,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      82,    83,    52,    84,    61,    62,    53,    78,    80,    40,
     114,    41,    42,    52,    56,    57,    58,    43,    59,    60,
       1,     2,     3,     4,     5,    39,    96,    97,    63,    64,
      65,   -28,   104,     6,     7,     8,     9,    10,    11,   -28,
      12,    98,    99,    13,    50,   100,    99,    14,    15,    85,
      86,    87,    88,    89,    51,    66,   112,   108,    52,   109,
     110,   111,    53,    95,   115,    67,   113,     1,     2,     3,
       4,     5,    45,    46,    68,    47,    48,    49,   -28,   -29,
       6,     7,     8,     9,    10,    11,   -28,    12,    69,   -29,
      13,   -31,   -31,   -29,    14,    15,    81,   -29,   103,   -27,
     -27,    44,   -27,   -27,   -27,     1,     2,     3,     4,     5,
      71,    72,    52,    73,    76,    72,    55,    73,     6,     7,
      54,     9,    10,    11,    56,    57,    58,   107,    59,    60,
      75,    77,    79,   106,    81,    92,    93,    94,   101,    99,
     102,    99,    90,    91,   105
};

static const yytype_uint8 yycheck[] =
{
      50,    51,    18,    53,     3,     4,    22,    48,    49,    12,
      15,    14,    15,    18,     8,     9,    10,     0,    12,    13,
       3,     4,     5,     6,     7,    18,    67,    68,     5,     6,
       7,    14,    82,    16,    17,    18,    19,    20,    21,    22,
      23,    17,    18,    26,     4,    17,    18,    30,    31,    56,
      57,    58,    59,    60,    14,    17,   106,    98,    18,   100,
     101,   102,    22,    66,   114,    20,   107,     3,     4,     5,
       6,     7,    24,    25,    20,    27,    28,    29,    14,     4,
      16,    17,    18,    19,    20,    21,    22,    23,    18,    14,
      26,    17,    18,    18,    30,    31,    18,    22,    18,    24,
      25,    16,    27,    28,    29,     3,     4,     5,     6,     7,
      18,    19,    18,    21,    18,    19,    29,    21,    16,    17,
      18,    19,    20,    21,     8,     9,    10,    20,    12,    13,
      47,    48,    49,    83,    18,    63,    64,    65,    17,    18,
      17,    18,    61,    62,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    17,    18,    19,
      20,    21,    23,    26,    30,    31,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    18,
      44,    44,    44,     0,    34,    24,    25,    27,    28,    29,
       4,    14,    18,    22,    18,    50,     8,     9,    10,    12,
      13,     3,     4,     5,     6,     7,    17,    20,    20,    18,
      46,    18,    19,    21,    47,    46,    18,    46,    47,    46,
      47,    18,    45,    45,    45,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    44,    47,    47,    17,    18,
      17,    17,    17,    18,    45,    57,    53,    20,    47,    47,
      47,    47,    45,    47,    15,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    35,    35,    36,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    44,    45,    45,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      51,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55,    55,    56,    56,    56,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     5,     3,     4,
       4,     6,     5,     5,     3,     1,     0,     1,     0,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     7,     4,     3
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
        case 3:
#line 94 "ppre.y" /* yacc.c:1646  */
    {
        }
#line 1359 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 4:
#line 99 "ppre.y" /* yacc.c:1646  */
    {
        //printf(" { all1 def1 '%s'} ", (char*)$1);
        }
#line 1367 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 undef1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1375 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 err1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1383 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 msg1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1391 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 mac1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1399 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 ifdef1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1407 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 elifdef1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1415 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 11:
#line 127 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 else1 x'%s'  '%s'}\n", (char*)$1, (char*)$2);
        }
#line 1423 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1 endif1 x'%s' }\n", (char*)$1);
        }
#line 1431 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
#line 1439 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{all1: num1 x '%s'  '%s'}\n", (char*)$1);
        }
#line 1447 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{def1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = push_symtab((char*)(yyvsp[-1].sym), "", "",  DECL_DEFINE, 0);
        }
#line 1456 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "ppre.y" /* yacc.c:1646  */
    { // Ignore
        }
#line 1463 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{undef1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE);
        if(st2)
            {
            //printf("UNDEF removing %s\n", (char*)$4);
            st2->name = strdup("");
            }
        else
            {
            printf("Preprocess Warning: '%s' not defined, cannot undefine.\n",
                (char *) (yyvsp[-1].sym));
            }
        }
#line 1482 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "ppre.y" /* yacc.c:1646  */
    { // Ignore
        }
#line 1489 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 19:
#line 175 "ppre.y" /* yacc.c:1646  */
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("Error: %s\n", tmp_strx);
            free(tmp_strx);
            }
        exit(1);
    }
#line 1507 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 20:
#line 191 "ppre.y" /* yacc.c:1646  */
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("%s\n", tmp_strx);
            free(tmp_strx);
            }
     }
#line 1524 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 21:
#line 205 "ppre.y" /* yacc.c:1646  */
    {
        // Erase quotes
        char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
        char *last = strrchr(tmp_strx, '\"');
        if(last)
            *last = '\0';

        Symbol  *st = lookup_symtab((char*)(yyvsp[-3].sym), DECL_MACRO);
        if(st)   // replace
            {
            if(st->var) free(st->var);
            st->var = strdup(tmp_strx);
            }
        else
            push_symtab((char*)(yyvsp[-3].sym), tmp_strx, "",  DECL_MACRO, 0);

        free(tmp_strx);
        }
#line 1547 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 22:
#line 225 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{ifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

        if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
#line 1564 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 23:
#line 240 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{elifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

        if(hasdefine == 1)
            {
            if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE) != NULL)
                {
                hasdefine = 2;
                }
            }
        else
            {
            hasdefine = 0;
            }
        }
#line 1584 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 24:
#line 258 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{endif1 '%s'}\n", (char*)$2);
        hasdefine = 2;
        }
#line 1593 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 25:
#line 265 "ppre.y" /* yacc.c:1646  */
    {
        //printf("{else1 '%s'}\n", (char*)$1);

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
#line 1606 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "ppre.y" /* yacc.c:1646  */
    {}
#line 1612 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 27:
#line 276 "ppre.y" /* yacc.c:1646  */
    {}
#line 1618 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 28:
#line 279 "ppre.y" /* yacc.c:1646  */
    {}
#line 1624 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 29:
#line 280 "ppre.y" /* yacc.c:1646  */
    {}
#line 1630 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 30:
#line 281 "ppre.y" /* yacc.c:1646  */
    {}
#line 1636 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 304 "ppre.y" /* yacc.c:1646  */
    {
      //printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1646 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 310 "ppre.y" /* yacc.c:1646  */
    { //printf("{ ID '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1655 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 45:
#line 315 "ppre.y" /* yacc.c:1646  */
    { //printf("{ SP '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1664 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 46:
#line 320 "ppre.y" /* yacc.c:1646  */
    { //printf("{ ops '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1673 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 325 "ppre.y" /* yacc.c:1646  */
    { //printf("{ NL '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1682 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 330 "ppre.y" /* yacc.c:1646  */
    { //printf("{ STR '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1691 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 335 "ppre.y" /* yacc.c:1646  */
    { //printf("{ COM '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1700 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 342 "ppre.y" /* yacc.c:1646  */
    {
    //printf("{ id1 : ID '%s}' ", (char*)$1);
    Symbol *sp = lookup_symtab((char*)(yyvsp[0].sym), DECL_MACRO);
    if(sp)
        {
        printf("Macro expansion '%s to %s'\n",  sp->name, sp->var);
        (yyval.sym) = (void*)strdup(sp->var);
        }
    else
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 1716 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 51:
#line 356 "ppre.y" /* yacc.c:1646  */
    {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)(yyvsp[0].sym)));

        str2int((char*)(yyvsp[0].sym));
        }
#line 1727 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 52:
#line 365 "ppre.y" /* yacc.c:1646  */
    {
    }
#line 1734 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 53:
#line 368 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) | str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1744 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 374 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) ^ str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1754 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) & str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1764 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 56:
#line 386 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) >> str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1774 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 57:
#line 392 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) << str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1784 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 400 "ppre.y" /* yacc.c:1646  */
    {
    }
#line 1791 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 59:
#line 403 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) + str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1801 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 60:
#line 409 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) - str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1811 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 417 "ppre.y" /* yacc.c:1646  */
    {
    }
#line 1818 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 420 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) * str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1828 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 426 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) / str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1838 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 432 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[-2].sym)) % str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1848 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 440 "ppre.y" /* yacc.c:1646  */
    {
    }
#line 1855 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 443 "ppre.y" /* yacc.c:1646  */
    {
        (yyval.sym) = (yyvsp[-3].sym);
        }
#line 1863 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 447 "ppre.y" /* yacc.c:1646  */
    {
        int val = str2int((char*)(yyvsp[0].sym)); val = -val;
        sprintf(tmp_str3, "%d", val);
        //printf("MINUS %d %s\n", val, tmp_str3);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1874 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 456 "ppre.y" /* yacc.c:1646  */
    {
        //printf("NUM %s\n", (char*)$2);
        (yyval.sym) = (yyvsp[-1].sym);
        }
#line 1883 "parser/ppre.yacc.c" /* yacc.c:1646  */
    break;


#line 1887 "parser/ppre.yacc.c" /* yacc.c:1646  */
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
#line 461 "ppre.y" /* yacc.c:1906  */


///////////////////////////////////////////////////////////////////////////

int     str2int(char *ptr)

{
    int ret = 0, base = 10, sign = 0;

    if(ptr[0] && ptr[1])    // If string is big enough
        {
        // Determine base
        char base1 = ptr[0], base2 = ptr[1];

        if(base1 == '0' && (base2 == 'x' || base2 == 'X'))
            base = 16, ptr += 2;

        if(base1 == '0' && (base2 == 'y' || base2 == 'Y'))
            base = 8, ptr += 2;

        if(base1 == '0' && (base2 == 'z' || base2 == 'Z'))
            base = 2, ptr += 2;
        }

    if(ptr[0])    // If string is big enough
        {
        // Determine sign
        char sign1 = ptr[0];
        if(sign1 == '-')
            sign = 1, ptr++;
        else if(sign1 == '+')
            ptr++;  // skip plus
        }

    //printf(" str2int(%s) ", ptr);

    while(1)
        {
        char digit = *ptr++;

        if(digit == 0)      // End of str
            break;

        if(digit >= '0' && digit <= '9')
            {
            ret *= base;
            ret += digit - '0';
            }
          else if(digit >= 'A' && digit <= ('A' + base))
            {
            ret *= base;
            ret += digit - 'A' + 10;
            }
          else if(digit >= 'a' && digit <= ('a' + base))
            {
            ret *= base;
            ret += digit - 'a' + 10;
            }
        else
            {
            // Not a valid number
            break;
            }
        }

    if(sign)
        ret = - ret;

    //printf("base=%d  ret=%d\n", base, ret);
    return ret;
}




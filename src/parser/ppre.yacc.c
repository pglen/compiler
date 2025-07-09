/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

/* First part of user prologue.  */
#line 17 "ppre.y"


#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>    /* for isatty */

// We are in a subdir ./parser
#include "../symtab.h"
#include "../xmalloc.h"
#include "../utils.h"

/* define this to see indivdual parsing. Controled by options -y -l */
#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern  FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

// Global that controls define results
int hasdefine   = 1;


#line 107 "parser/ppre.yacc.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int predebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS2 = 258,                   /* PLUS2  */
    MINUS2 = 259,                  /* MINUS2  */
    MULT2 = 260,                   /* MULT2  */
    DIV2 = 261,                    /* DIV2  */
    MOD2 = 262,                    /* MOD2  */
    OR2 = 263,                     /* OR2  */
    AND2 = 264,                    /* AND2  */
    XOR2 = 265,                    /* XOR2  */
    NOT2 = 266,                    /* NOT2  */
    LSHIFT2 = 267,                 /* LSHIFT2  */
    RSHIFT2 = 268,                 /* RSHIFT2  */
    PAREN12 = 269,                 /* PAREN12  */
    PAREN22 = 270,                 /* PAREN22  */
    SEMI2 = 271,                   /* SEMI2  */
    ENL2 = 272,                    /* ENL2  */
    CH2 = 273,                     /* CH2  */
    ID2 = 274,                     /* ID2  */
    ID3 = 275,                     /* ID3  */
    SP2 = 276,                     /* SP2  */
    NL2 = 277,                     /* NL2  */
    STR2 = 278,                    /* STR2  */
    COMMENT2 = 279,                /* COMMENT2  */
    NUM2 = 280,                    /* NUM2  */
    MAC2 = 281,                    /* MAC2  */
    IFDEF2 = 282,                  /* IFDEF2  */
    ENDIF2 = 283,                  /* ENDIF2  */
    ELSE2 = 284,                   /* ELSE2  */
    ELIFDEF2 = 285,                /* ELIFDEF2  */
    DEF2 = 286,                    /* DEF2  */
    UNDEF2 = 287,                  /* UNDEF2  */
    ERR2 = 288,                    /* ERR2  */
    MSG2 = 289                     /* MSG2  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "ppre.y"

    //char    *strval;
    Symbol  *sym ;

#line 193 "parser/ppre.yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE prelval;


int preparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS2 = 3,                      /* PLUS2  */
  YYSYMBOL_MINUS2 = 4,                     /* MINUS2  */
  YYSYMBOL_MULT2 = 5,                      /* MULT2  */
  YYSYMBOL_DIV2 = 6,                       /* DIV2  */
  YYSYMBOL_MOD2 = 7,                       /* MOD2  */
  YYSYMBOL_OR2 = 8,                        /* OR2  */
  YYSYMBOL_AND2 = 9,                       /* AND2  */
  YYSYMBOL_XOR2 = 10,                      /* XOR2  */
  YYSYMBOL_NOT2 = 11,                      /* NOT2  */
  YYSYMBOL_LSHIFT2 = 12,                   /* LSHIFT2  */
  YYSYMBOL_RSHIFT2 = 13,                   /* RSHIFT2  */
  YYSYMBOL_PAREN12 = 14,                   /* PAREN12  */
  YYSYMBOL_PAREN22 = 15,                   /* PAREN22  */
  YYSYMBOL_SEMI2 = 16,                     /* SEMI2  */
  YYSYMBOL_ENL2 = 17,                      /* ENL2  */
  YYSYMBOL_CH2 = 18,                       /* CH2  */
  YYSYMBOL_ID2 = 19,                       /* ID2  */
  YYSYMBOL_ID3 = 20,                       /* ID3  */
  YYSYMBOL_SP2 = 21,                       /* SP2  */
  YYSYMBOL_NL2 = 22,                       /* NL2  */
  YYSYMBOL_STR2 = 23,                      /* STR2  */
  YYSYMBOL_COMMENT2 = 24,                  /* COMMENT2  */
  YYSYMBOL_NUM2 = 25,                      /* NUM2  */
  YYSYMBOL_MAC2 = 26,                      /* MAC2  */
  YYSYMBOL_IFDEF2 = 27,                    /* IFDEF2  */
  YYSYMBOL_ENDIF2 = 28,                    /* ENDIF2  */
  YYSYMBOL_ELSE2 = 29,                     /* ELSE2  */
  YYSYMBOL_ELIFDEF2 = 30,                  /* ELIFDEF2  */
  YYSYMBOL_DEF2 = 31,                      /* DEF2  */
  YYSYMBOL_UNDEF2 = 32,                    /* UNDEF2  */
  YYSYMBOL_ERR2 = 33,                      /* ERR2  */
  YYSYMBOL_MSG2 = 34,                      /* MSG2  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_all1 = 36,                      /* all1  */
  YYSYMBOL_all2 = 37,                      /* all2  */
  YYSYMBOL_idd1 = 38,                      /* idd1  */
  YYSYMBOL_idd2 = 39,                      /* idd2  */
  YYSYMBOL_define1 = 40,                   /* define1  */
  YYSYMBOL_undef1 = 41,                    /* undef1  */
  YYSYMBOL_err1 = 42,                      /* err1  */
  YYSYMBOL_strx1 = 43,                     /* strx1  */
  YYSYMBOL_semib = 44,                     /* semib  */
  YYSYMBOL_semibm = 45,                    /* semibm  */
  YYSYMBOL_nl1 = 46,                       /* nl1  */
  YYSYMBOL_msg1 = 47,                      /* msg1  */
  YYSYMBOL_mac1 = 48,                      /* mac1  */
  YYSYMBOL_ifdef1 = 49,                    /* ifdef1  */
  YYSYMBOL_elifdef1 = 50,                  /* elifdef1  */
  YYSYMBOL_endif1 = 51,                    /* endif1  */
  YYSYMBOL_else1 = 52,                     /* else1  */
  YYSYMBOL_sp1 = 53,                       /* sp1  */
  YYSYMBOL_sp1b = 54,                      /* sp1b  */
  YYSYMBOL_sp1m = 55,                      /* sp1m  */
  YYSYMBOL_sp1mb = 56,                     /* sp1mb  */
  YYSYMBOL_expr1 = 57,                     /* expr1  */
  YYSYMBOL_expr2 = 58,                     /* expr2  */
  YYSYMBOL_expr3 = 59,                     /* expr3  */
  YYSYMBOL_expr4 = 60,                     /* expr4  */
  YYSYMBOL_expr5 = 61                      /* expr5  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   106,   115,   120,   126,   131,   136,   141,
     146,   151,   156,   161,   166,   171,   176,   197,   205,   211,
     212,   220,   229,   239,   248,   267,   271,   287,   290,   293,
     302,   310,   318,   327,   328,   329,   330,   331,   333,   339,
     346,   354,   362,   384,   402,   409,   417,   418,   420,   421,
     423,   424,   426,   430,   436,   440,   448,   454,   460,   466,
     473,   478,   486,   493,   498,   506,   512,   519,   522,   529
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS2", "MINUS2",
  "MULT2", "DIV2", "MOD2", "OR2", "AND2", "XOR2", "NOT2", "LSHIFT2",
  "RSHIFT2", "PAREN12", "PAREN22", "SEMI2", "ENL2", "CH2", "ID2", "ID3",
  "SP2", "NL2", "STR2", "COMMENT2", "NUM2", "MAC2", "IFDEF2", "ENDIF2",
  "ELSE2", "ELIFDEF2", "DEF2", "UNDEF2", "ERR2", "MSG2", "$accept", "all1",
  "all2", "idd1", "idd2", "define1", "undef1", "err1", "strx1", "semib",
  "semibm", "nl1", "msg1", "mac1", "ifdef1", "elifdef1", "endif1", "else1",
  "sp1", "sp1b", "sp1m", "sp1mb", "expr1", "expr2", "expr3", "expr4",
  "expr5", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,   134,   -92,   -20,   -92,   -10,   -92,   -92,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    27,    -4,
     -92,   -92,    11,   186,   186,    11,    11,   186,   186,   186,
     186,   -20,   -20,   -92,   -92,   -92,   -92,   -92,    29,   -20,
     -20,   -20,   -92,     1,   104,    15,    23,   -92,   -92,   -20,
     -92,   -92,   -20,   -20,   -20,   -20,   121,    -4,   -92,   -92,
     -92,    43,    38,   -20,   -20,   185,    35,    69,    11,   155,
      11,    11,    11,   -20,   -20,   -20,   -20,   -92,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -92,
     -20,   -92,   122,   -92,   -92,   -92,    -4,   189,   186,   -20,
      37,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,    11,     0,   -20,   -20,   -20,   191,   -20,    15,    15,
      15,    15,    15,    23,    23,   -92,   -92,   -92,   -92,   -92,
     185,    56,   -20,   -92,   -20,   -92,   -92,   186,   -92,   165,
     104,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    48,     1,    52,    16,    50,    47,    14,    52,    52,
      52,    52,    52,    52,    52,    52,     3,     4,     6,     7,
       8,     5,     9,    10,    11,    13,    12,    49,     0,    53,
      15,    50,    33,    52,    52,    33,    33,    52,    52,    52,
      52,     0,     0,    51,    36,    34,    38,    39,     0,    52,
      52,    52,    17,     0,    18,    54,    60,    63,    67,    52,
      44,    45,    52,    52,    52,    52,     0,    25,    37,    35,
      28,    27,     0,    52,    52,     0,     0,     0,    33,    33,
      33,    33,    33,     0,    52,    52,    52,    69,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    42,
      52,    22,     0,    24,    26,    40,    43,    52,    52,    52,
       0,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    33,    32,    52,    52,    52,     0,    52,    55,    57,
      56,    59,    58,    61,    62,    64,    65,    66,    23,    29,
      30,     0,    52,    31,    52,    68,    19,    52,    21,    33,
      20,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,     3,   -92,   -92,   -92,   -92,   -91,   -92,
     -12,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -36,    -1,   -82,   -11,   -31,    64,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    16,    51,   147,    17,    18,    19,    52,    46,
      47,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    53,    54,    55,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    32,   -52,   109,    66,    67,    33,    34,    35,
      36,    37,    38,    39,    40,    73,   123,    43,   -52,   -52,
     -46,    31,   -46,    60,    61,   124,    74,    44,   -52,   -52,
     -52,    48,    31,    45,    48,    48,    31,    59,    94,    95,
      62,    63,    64,    65,    31,    68,    84,   106,    70,    71,
      72,    69,    85,    75,    76,    77,   148,    41,    78,    42,
     127,    79,    80,    81,    82,   150,    99,   101,   103,   104,
     105,   144,    86,    87,    96,    97,    98,    48,   102,    48,
      48,    48,   100,   107,   108,   133,   134,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     128,   129,   130,   131,   132,     0,     0,   -52,   126,   138,
       0,   125,   -52,   -52,   -52,     0,   -52,   -52,     0,     0,
      48,    71,   139,   140,   141,    31,   143,    76,    76,    76,
      76,    76,    77,    77,     2,     0,    73,   151,    68,     0,
      83,   145,    43,   146,    69,     0,   149,    74,    48,    75,
       0,     3,     0,     0,     4,     5,     6,     0,     7,     0,
       8,     9,    10,    11,     0,    12,    13,    14,    15,   -52,
       0,    44,     0,     0,    49,     0,    31,    45,    50,    73,
     -52,    44,   135,   136,   137,     0,    31,    45,    88,     0,
      74,     0,     0,    89,    90,    91,     0,    92,    93,    89,
      90,    91,     0,    92,    93,    49,   142,    31,    49,    50,
      31,     0,   122
};

static const yytype_int16 yycheck[] =
{
       1,    21,     3,     3,    86,    41,    42,     8,     9,    10,
      11,    12,    13,    14,    15,    14,   107,    21,     3,     4,
      30,    21,    32,    35,    36,   107,    25,    16,     5,     6,
       7,    32,    21,    22,    35,    36,    21,    34,     3,     4,
      37,    38,    39,    40,    21,    16,     3,    83,    49,    50,
      51,    22,    14,    54,    55,    56,   147,    30,    59,    32,
      23,    62,    63,    64,    65,   147,    78,    79,    80,    81,
      82,    15,    73,    74,     5,     6,     7,    78,    79,    80,
      81,    82,    79,    84,    85,   116,   117,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     111,   112,   113,   114,   115,    -1,    -1,     3,   109,   121,
      -1,   108,     8,     9,    10,    -1,    12,    13,    -1,    -1,
     121,   122,   123,   124,   125,    21,   127,   128,   129,   130,
     131,   132,   133,   134,     0,    -1,    14,   149,    16,    -1,
      19,   142,    21,   144,    22,    -1,   147,    25,   149,   150,
      -1,    17,    -1,    -1,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    23,    14,
      25,    16,   118,   119,   120,    -1,    21,    22,     3,    -1,
      25,    -1,    -1,     8,     9,    10,    -1,    12,    13,     8,
       9,    10,    -1,    12,    13,    19,    15,    21,    19,    23,
      21,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,     0,    17,    20,    21,    22,    24,    26,    27,
      28,    29,    31,    32,    33,    34,    37,    40,    41,    42,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    21,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    30,    32,    21,    16,    22,    44,    45,    56,    19,
      23,    38,    43,    56,    57,    58,    59,    60,    61,    38,
      45,    45,    38,    38,    38,    38,    55,    55,    16,    22,
      56,    56,    56,    14,    25,    56,    56,    56,    56,    56,
      56,    56,    56,    19,     3,    14,    56,    56,     3,     8,
       9,    10,    12,    13,     3,     4,     5,     6,     7,    45,
      38,    45,    56,    45,    45,    45,    55,    56,    56,    57,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    23,    43,    57,    38,    56,    23,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    45,    56,
      56,    56,    15,    56,    15,    56,    56,    39,    43,    56,
      57,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    38,    38,    39,
      39,    39,    40,    40,    41,    41,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    60,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     5,     7,     5,     3,     5,     2,     2,     6,
       6,     6,     5,     0,     1,     2,     1,     2,     1,     3,
       5,    13,     5,     5,     3,     3,     1,     1,     0,     1,
       1,     2,     0,     1,     1,     5,     5,     5,     5,     5,
       1,     5,     5,     1,     5,     5,     5,     1,     7,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* all1: %empty  */
#line 100 "ppre.y"
        {
        if(config.testpreyacc > 3)
            {
            printf(" { all1 all2 root none } "); fflush(stdout);
            }
        }
#line 1343 "parser/ppre.yacc.c"
    break;

  case 3: /* all1: all1 all2  */
#line 107 "ppre.y"
        {
        if(config.testpreyacc > 3)
            {
            printf(" { all1 all2 root '%s'} ", (yyvsp[0].sym)->var); fflush(stdout);
            }
        }
#line 1354 "parser/ppre.yacc.c"
    break;

  case 4: /* all2: define1  */
#line 116 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf(" { all2 define '%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1363 "parser/ppre.yacc.c"
    break;

  case 5: /* all2: msg1  */
#line 121 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 msg1 '%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            //to_prev_state();
            }
#line 1373 "parser/ppre.yacc.c"
    break;

  case 6: /* all2: undef1  */
#line 127 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 undef1 x'%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1382 "parser/ppre.yacc.c"
    break;

  case 7: /* all2: err1  */
#line 132 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 err1 x'%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1391 "parser/ppre.yacc.c"
    break;

  case 8: /* all2: nl1  */
#line 137 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 nl1 '%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1400 "parser/ppre.yacc.c"
    break;

  case 9: /* all2: mac1  */
#line 142 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 mac1 x'%s' } ", (yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1409 "parser/ppre.yacc.c"
    break;

  case 10: /* all2: ifdef1  */
#line 147 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 ifdef1 x'%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1418 "parser/ppre.yacc.c"
    break;

  case 11: /* all2: elifdef1  */
#line 152 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 elifdef1 x'%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1427 "parser/ppre.yacc.c"
    break;

  case 12: /* all2: else1  */
#line 157 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 else1 x'%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1436 "parser/ppre.yacc.c"
    break;

  case 13: /* all2: endif1  */
#line 162 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 endif1 x'%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1445 "parser/ppre.yacc.c"
    break;

  case 14: /* all2: COMMENT2  */
#line 167 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 comment '%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1454 "parser/ppre.yacc.c"
    break;

  case 15: /* all2: sp1mb  */
#line 172 "ppre.y"
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 nl / blank '%s' } ", (char*)(yyvsp[0].sym)->var); fflush(stdout); }
            }
#line 1463 "parser/ppre.yacc.c"
    break;

  case 16: /* all2: ID3  */
#line 177 "ppre.y"
            {
            if(config.testpreyacc > 0)
                {
                //printf("{ all2 id3 '%s' } ", $1->var);
                //fflush(stdout);
                // Find in symtab
                }
            Symbol  *st2 = lookup_symtab((yyvsp[0].sym)->var, DECL_DEFINE);
            if(st2)
                {
                //printf("added %s=%s", st2->var, st2->res);
                addemitstr(st2->res);
                }
            else
                {
                //printf("added: '%s'", $1->var);
                addemitstr((yyvsp[0].sym)->var);
                }
            }
#line 1487 "parser/ppre.yacc.c"
    break;

  case 17: /* idd1: strx1  */
#line 197 "ppre.y"
                   {
                    //if(config.testpreyacc > 0)
                    //    if($1)
                    //        printf("{ idd1 strx1 '%p' } ", $1->var);

                    //if(hasdefine)
                    //    push_symtab("", $1->var, $1->res, DECL_MACITEM, 0);
                        }
#line 1500 "parser/ppre.yacc.c"
    break;

  case 18: /* idd1: expr1  */
#line 205 "ppre.y"
                   { if(config.testpreyacc > 0)
                        printf("{ idd1 expr1 %s } ", (yyvsp[0].sym)->var);
                    //if(hasdefine)
                    //        push_symtab("", $1->var, $1->res, DECL_MACITEM, 0);
                        }
#line 1510 "parser/ppre.yacc.c"
    break;

  case 20: /* idd2: idd2 expr1  */
#line 212 "ppre.y"
                        { if(config.testpreyacc > 0)
                            printf("{ idd2 expr1 %s } ", (yyvsp[0].sym)->var);
                        char tmp[32];
                        create_unique(tmp, "mac");
                        (yyval.sym)=make_symstr((yyvsp[0].sym)->var, tmp, (yyvsp[0].sym)->res);
                        if(hasdefine)
                            push_symtab(tmp, (yyvsp[0].sym)->var, (yyvsp[0].sym)->res, DECL_MACITEM, 0);
                        }
#line 1523 "parser/ppre.yacc.c"
    break;

  case 21: /* idd2: idd2 strx1  */
#line 220 "ppre.y"
                        { if(config.testpreyacc > 0)
                            printf("{ idd2 strx1 %s } ", (yyvsp[0].sym)->var);
                        char tmp[32];
                        create_unique(tmp, "mac");
                        (yyval.sym)=make_symstr((yyvsp[0].sym)->var, tmp, (yyvsp[0].sym)->res);
                        if(hasdefine)
                            push_symtab(tmp, (yyvsp[0].sym)->var, (yyvsp[0].sym)->res, DECL_MACITEM, 0);
                        }
#line 1536 "parser/ppre.yacc.c"
    break;

  case 22: /* define1: DEF2 sp1mb idd1 sp1mb semibm  */
#line 230 "ppre.y"
            {
            if(config.testpreyacc > 0)
                {
                printf("{ define1 '%s' } ", (yyvsp[-2].sym)->var);
                fflush(stdout);
                }
            if(hasdefine)
                push_symtab("", (yyvsp[-2].sym)->var, "", DECL_DEFINE, 0);
            }
#line 1550 "parser/ppre.yacc.c"
    break;

  case 23: /* define1: DEF2 sp1mb idd1 sp1mb idd1 sp1mb semibm  */
#line 240 "ppre.y"
            {
            if(config.testpreyacc > 0)
                { printf("{ define1 '%s' arg: %s } ", (yyvsp[-4].sym)->var, (yyvsp[-2].sym)->var);
                    fflush(stdout); }
            if(hasdefine)
                push_symtab("", (yyvsp[-4].sym)->var, (yyvsp[-2].sym)->var, DECL_DEFINE, 0);
            }
#line 1562 "parser/ppre.yacc.c"
    break;

  case 24: /* undef1: UNDEF2 sp1mb idd1 sp1mb semibm  */
#line 249 "ppre.y"
        {
        if(config.testpreyacc > 0)
            { printf("{ undef1 '%s' } ", (yyvsp[-2].sym)->var); fflush(stdout); }
        Symbol  *st2 = lookup_symtab((yyvsp[-2].sym)->var, DECL_DEFINE);
        if(st2)
            {
            printf(" { UNDEF removing %s } ", (yyvsp[-2].sym)->var); fflush(stdout);
            //dump_symtab();
            delitem_symtab(st2);
            //dump_symtab();
            }
        else
            {
            fprintf(stderr,
                "Preprocess Warning: %%undef '%s' is not defined\n",
                    (yyvsp[-2].sym)->var); fflush(stdout);
            }
        }
#line 1585 "parser/ppre.yacc.c"
    break;

  case 25: /* undef1: sp1b UNDEF2 sp1m  */
#line 268 "ppre.y"
        { // Ignore
        }
#line 1592 "parser/ppre.yacc.c"
    break;

  case 26: /* err1: ERR2 sp1mb idd1 sp1mb semibm  */
#line 272 "ppre.y"
            {
            printf(" { err1 %s } ", (yyvsp[-2].sym)->var); fflush(stdout);
            if(hasdefine == 1)
                {
                if(isatty(2) > 0)
                    fprintf(stderr, "\033[31;1mError Exit:\033[0m ");
                else
                    fprintf(stderr, "Error exit: ");

                fprintf(stderr, "%s\n", (yyvsp[-2].sym)->var);

                exit(1);
                }
            }
#line 1611 "parser/ppre.yacc.c"
    break;

  case 27: /* strx1: STR2 sp1mb  */
#line 288 "ppre.y"
            {
            }
#line 1618 "parser/ppre.yacc.c"
    break;

  case 28: /* strx1: ID2 sp1mb  */
#line 291 "ppre.y"
            {
            }
#line 1625 "parser/ppre.yacc.c"
    break;

  case 29: /* strx1: STR2 sp1mb PLUS2 sp1mb strx1 sp1mb  */
#line 294 "ppre.y"
            {
            if(config.testpreyacc > 0)
                { printf("msg str add' %s' '%s'\n", (char*)(yyvsp[-5].sym)->var, (char*)(yyvsp[-1].sym)->var); fflush(stdout); }
            char *sum = addstrs((yyvsp[-5].sym)->var, (yyvsp[-1].sym)->var);
            //printf("sum: '%s'\n", sum); fflush(stdout);
            Symbol *ss = make_symstr("", sum, STR2);
            (yyval.sym) = ss;
            }
#line 1638 "parser/ppre.yacc.c"
    break;

  case 30: /* strx1: STR2 sp1mb PLUS2 sp1mb expr1 sp1mb  */
#line 303 "ppre.y"
            {
            if(config.testpreyacc > 2)
                { printf("strx1 STR + expr1' %s' '%s'\n", (char*)(yyvsp[-5].sym)->var, (char*)(yyvsp[-1].sym)->var); fflush(stdout); fflush(stdout); fflush(stdout); fflush(stdout); fflush(stdout); }
            char *sum = addstrs((yyvsp[-5].sym)->var, (yyvsp[-1].sym)->var);
            Symbol *ss = make_symstr("", sum, STR2);
            (yyval.sym) = ss;
            }
#line 1650 "parser/ppre.yacc.c"
    break;

  case 31: /* strx1: expr1 sp1mb PLUS2 sp1mb STR2 sp1mb  */
#line 311 "ppre.y"
            {
            if(config.testpreyacc > 2)
                { printf("strx1 expr1 + str2 '%s' '%s'\n", (char*)(yyvsp[-5].sym)->var, (char*)(yyvsp[-1].sym)->var); }
            char *sum = addstrs((yyvsp[-5].sym)->var, (yyvsp[-1].sym)->var);
            Symbol *ss = make_symstr("", sum, STR2);
            (yyval.sym) = ss;
            }
#line 1662 "parser/ppre.yacc.c"
    break;

  case 32: /* strx1: STR2 sp1mb PLUS2 sp1mb STR2  */
#line 319 "ppre.y"
            {
            if(config.testpreyacc > 2)
                { printf("strx1 expr1 + str2 '%s' '%s'\n", (char*)(yyvsp[-4].sym)->var, (char*)(yyvsp[0].sym)->var); }
            char *sum = addstrs((yyvsp[-4].sym)->var, (yyvsp[0].sym)->var);
            Symbol *ss = make_symstr("", sum, STR2);
            (yyval.sym) = ss;
            }
#line 1674 "parser/ppre.yacc.c"
    break;

  case 38: /* semibm: semib  */
#line 333 "ppre.y"
                {
                if(config.testpreyacc > 0)
                    printf(" { semibm '%s' } ", (yyvsp[0].sym)->var); fflush(stdout);
                to_prev_state();
                }
#line 1684 "parser/ppre.yacc.c"
    break;

  case 39: /* nl1: ENL2 sp1mb semibm  */
#line 340 "ppre.y"
            {
            if(hasdefine == 1)
                fprintf(stderr, "\n");
            //to_prev_state();
            }
#line 1694 "parser/ppre.yacc.c"
    break;

  case 40: /* msg1: MSG2 sp1mb idd1 sp1mb semibm  */
#line 347 "ppre.y"
            {
            if(config.testpreyacc > 0)
                { printf(" { msg1: expr1 '%s' } ", (yyvsp[-2].sym)->var); }
            if(hasdefine)
                fprintf(stderr, "%s", (yyvsp[-2].sym)->var);
            }
#line 1705 "parser/ppre.yacc.c"
    break;

  case 41: /* mac1: MAC2 sp1mb idd1 sp1mb PAREN12 sp1mb idd1 sp1mb PAREN22 sp1mb idd2 sp1mb semibm  */
#line 356 "ppre.y"
        {
        if(config.testpreyacc > 0)
            { printf(" { mac1: idd1 '%s' ( '%s' ) '%s' } ",
                            (yyvsp[-10].sym)->var, (yyvsp[-6].sym)->var, (yyvsp[-2].sym)->var); }
        }
#line 1715 "parser/ppre.yacc.c"
    break;

  case 42: /* ifdef1: IFDEF2 sp1mb idd1 sp1mb semibm  */
#line 363 "ppre.y"
        {
        //to_emit_state();
        //emitprog = 0;
        if(config.testpreyacc > 0)
            { printf("{ ifdef1 '%s' } ", (yyvsp[-2].sym)->var); }
        if(lookup_symtab((yyvsp[-2].sym)->var, DECL_DEFINE) != NULL)
            {
            if(config.testpreyacc > 0)
              { printf("{ ifdef1 defined '%s' } ", (yyvsp[-2].sym)->var); }
            hasdefine = 1;
            }
         else
            {
            if(config.testpreyacc > 0)
              { printf("{ ifdef1 NOT defined '%s' } ", (yyvsp[-2].sym)->var); }
            //to_init_state();
            hasdefine = 0;
            }
        printf("Has define: %d\n", hasdefine);
        }
#line 1740 "parser/ppre.yacc.c"
    break;

  case 43: /* elifdef1: sp1b ELIFDEF2 sp1m ID2 sp1m  */
#line 385 "ppre.y"
        {
        if(config.testpreyacc > 0)
            { printf("{ elifdef1 '%s' '%s'} ", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym)); }

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
#line 1761 "parser/ppre.yacc.c"
    break;

  case 44: /* endif1: ENDIF2 sp1mb semibm  */
#line 403 "ppre.y"
        {
        if(config.testpreyacc > 0)
            { printf("{ endif1 '%s'} ", (char*)(yyvsp[-2].sym)->var); }
        hasdefine = 1;
        }
#line 1771 "parser/ppre.yacc.c"
    break;

  case 45: /* else1: ELSE2 sp1mb semibm  */
#line 410 "ppre.y"
        {
        if(config.testpreyacc > 0)
            { printf("{ else1 '%s'} ", (char*)(yyvsp[-2].sym)); }
        hasdefine = !hasdefine;
        }
#line 1781 "parser/ppre.yacc.c"
    break;

  case 46: /* sp1: SP2  */
#line 417 "ppre.y"
                {}
#line 1787 "parser/ppre.yacc.c"
    break;

  case 47: /* sp1: NL2  */
#line 418 "ppre.y"
                {}
#line 1793 "parser/ppre.yacc.c"
    break;

  case 48: /* sp1b: %empty  */
#line 420 "ppre.y"
                {}
#line 1799 "parser/ppre.yacc.c"
    break;

  case 49: /* sp1b: sp1  */
#line 421 "ppre.y"
                {}
#line 1805 "parser/ppre.yacc.c"
    break;

  case 50: /* sp1m: SP2  */
#line 423 "ppre.y"
                     {}
#line 1811 "parser/ppre.yacc.c"
    break;

  case 51: /* sp1m: sp1m SP2  */
#line 424 "ppre.y"
                     {}
#line 1817 "parser/ppre.yacc.c"
    break;

  case 52: /* sp1mb: %empty  */
#line 426 "ppre.y"
            {  /* empty */
            //printf(" spb ");
            //$$ = make_symstr("", " ", STR2);
            }
#line 1826 "parser/ppre.yacc.c"
    break;

  case 53: /* sp1mb: sp1m  */
#line 431 "ppre.y"
            {
            //printf(" spm ");
            //$$ = make_symstr("", " ", STR2);
            }
#line 1835 "parser/ppre.yacc.c"
    break;

  case 54: /* expr1: expr2  */
#line 437 "ppre.y"
        {
        //printf(" { expr1: %s } ", $1->var);
        }
#line 1843 "parser/ppre.yacc.c"
    break;

  case 55: /* expr1: expr1 sp1mb OR2 sp1mb expr2  */
#line 441 "ppre.y"
        {
        if(config.testpreyacc > 1)
            { printf("expr1 '%s' OR '%s'\n", (yyvsp[-4].sym)->var, (yyvsp[0].sym)->var); }
        int val = str2int((yyvsp[-4].sym)->var) | str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1855 "parser/ppre.yacc.c"
    break;

  case 56: /* expr1: expr1 sp1mb XOR2 sp1mb expr2  */
#line 449 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) ^ str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1865 "parser/ppre.yacc.c"
    break;

  case 57: /* expr1: expr1 sp1mb AND2 sp1mb expr2  */
#line 455 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) & str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1875 "parser/ppre.yacc.c"
    break;

  case 58: /* expr1: expr1 sp1mb RSHIFT2 sp1mb expr2  */
#line 461 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) >> str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1885 "parser/ppre.yacc.c"
    break;

  case 59: /* expr1: expr1 sp1mb LSHIFT2 sp1mb expr2  */
#line 467 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) << str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1895 "parser/ppre.yacc.c"
    break;

  case 60: /* expr2: expr3  */
#line 474 "ppre.y"
        {
        if(config.testpreyacc > 1)
            { printf("{ expr2 '%s'} ", (yyvsp[0].sym)->var); }
        }
#line 1904 "parser/ppre.yacc.c"
    break;

  case 61: /* expr2: expr2 sp1mb PLUS2 sp1mb expr3  */
#line 479 "ppre.y"
        {
        if(config.testpreyacc > 1)
           { printf(" { expr2 '%s' PLUS '%s } ", (yyvsp[-4].sym)->var, (yyvsp[0].sym)->var); }
        int val = str2int((yyvsp[-4].sym)->var) + str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1916 "parser/ppre.yacc.c"
    break;

  case 62: /* expr2: expr2 sp1mb MINUS2 sp1mb expr3  */
#line 487 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) - str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1926 "parser/ppre.yacc.c"
    break;

  case 63: /* expr3: expr4  */
#line 494 "ppre.y"
    {
    if(config.testpreyacc > 1)
        { printf("{ expr3 '%s' } ", (yyvsp[0].sym)->var); }
    }
#line 1935 "parser/ppre.yacc.c"
    break;

  case 64: /* expr3: expr3 sp1mb MULT2 sp1mb expr4  */
#line 499 "ppre.y"
        {
        //if(config.testpreyacc > 1)
        //  {  printf("expr3 '%s' MUL '%s'\n", $1->var, $5->var); }
        int val = str2int((yyvsp[-4].sym)->var) * str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1947 "parser/ppre.yacc.c"
    break;

  case 65: /* expr3: expr3 sp1mb DIV2 sp1mb expr4  */
#line 507 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) / str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1957 "parser/ppre.yacc.c"
    break;

  case 66: /* expr3: expr3 sp1mb MOD2 sp1mb expr4  */
#line 513 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) % str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1967 "parser/ppre.yacc.c"
    break;

  case 67: /* expr4: expr5  */
#line 520 "ppre.y"
    {
    }
#line 1974 "parser/ppre.yacc.c"
    break;

  case 68: /* expr4: sp1mb PAREN12 sp1mb expr1 sp1mb PAREN22 sp1mb  */
#line 523 "ppre.y"
        {
        if(config.testpreyacc > 1)
            { printf(" { paren: expr4 '%s' } ", (yyvsp[-3].sym)->var); }
        (yyval.sym) = make_symstr("", (yyvsp[-3].sym)->var, NUM2);
        }
#line 1984 "parser/ppre.yacc.c"
    break;

  case 69: /* expr5: sp1mb NUM2 sp1mb  */
#line 530 "ppre.y"
        {
        if(config.testpreyacc > 1)
            { printf(" { expr5 '%s' } ", (yyvsp[-1].sym)->var); }
        (yyval.sym) = make_symstr("", (yyvsp[-1].sym)->var, NUM2);
        }
#line 1994 "parser/ppre.yacc.c"
    break;


#line 1998 "parser/ppre.yacc.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 537 "ppre.y"


// EOF

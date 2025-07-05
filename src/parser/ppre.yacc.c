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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// It is in a subdir ./parser

#include "../symtab.h"

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

int hasdefine = 2;


#line 106 "parser/ppre.yacc.c"

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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULT = 260,                    /* MULT  */
    DIV = 261,                     /* DIV  */
    MOD = 262,                     /* MOD  */
    OR = 263,                      /* OR  */
    AND = 264,                     /* AND  */
    XOR = 265,                     /* XOR  */
    NOT = 266,                     /* NOT  */
    LSHIFT = 267,                  /* LSHIFT  */
    RSHIFT = 268,                  /* RSHIFT  */
    PAREN1 = 269,                  /* PAREN1  */
    PAREN2 = 270,                  /* PAREN2  */
    CH = 271,                      /* CH  */
    ID = 272,                      /* ID  */
    SP = 273,                      /* SP  */
    NL = 274,                      /* NL  */
    STR = 275,                     /* STR  */
    COMMENT = 276,                 /* COMMENT  */
    NUM = 277,                     /* NUM  */
    MAC = 278,                     /* MAC  */
    IFDEF = 279,                   /* IFDEF  */
    ENDIF = 280,                   /* ENDIF  */
    ELSE = 281,                    /* ELSE  */
    ELIFDEF = 282,                 /* ELIFDEF  */
    DEF = 283,                     /* DEF  */
    UNDEF = 284,                   /* UNDEF  */
    ERR = 285,                     /* ERR  */
    MSG = 286                      /* MSG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "ppre.y"
                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */

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
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULT = 5,                       /* MULT  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_MOD = 7,                        /* MOD  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_XOR = 10,                       /* XOR  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_LSHIFT = 12,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 13,                    /* RSHIFT  */
  YYSYMBOL_PAREN1 = 14,                    /* PAREN1  */
  YYSYMBOL_PAREN2 = 15,                    /* PAREN2  */
  YYSYMBOL_CH = 16,                        /* CH  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_SP = 18,                        /* SP  */
  YYSYMBOL_NL = 19,                        /* NL  */
  YYSYMBOL_STR = 20,                       /* STR  */
  YYSYMBOL_COMMENT = 21,                   /* COMMENT  */
  YYSYMBOL_NUM = 22,                       /* NUM  */
  YYSYMBOL_MAC = 23,                       /* MAC  */
  YYSYMBOL_IFDEF = 24,                     /* IFDEF  */
  YYSYMBOL_ENDIF = 25,                     /* ENDIF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_ELIFDEF = 27,                   /* ELIFDEF  */
  YYSYMBOL_DEF = 28,                       /* DEF  */
  YYSYMBOL_UNDEF = 29,                     /* UNDEF  */
  YYSYMBOL_ERR = 30,                       /* ERR  */
  YYSYMBOL_MSG = 31,                       /* MSG  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_all1 = 33,                      /* all1  */
  YYSYMBOL_all2 = 34,                      /* all2  */
  YYSYMBOL_define1 = 35,                   /* define1  */
  YYSYMBOL_undef1 = 36,                    /* undef1  */
  YYSYMBOL_err1 = 37,                      /* err1  */
  YYSYMBOL_msg1 = 38,                      /* msg1  */
  YYSYMBOL_mac1 = 39,                      /* mac1  */
  YYSYMBOL_ifdef1 = 40,                    /* ifdef1  */
  YYSYMBOL_elifdef1 = 41,                  /* elifdef1  */
  YYSYMBOL_endif1 = 42,                    /* endif1  */
  YYSYMBOL_else1 = 43,                     /* else1  */
  YYSYMBOL_sp1b = 44,                      /* sp1b  */
  YYSYMBOL_sp1m = 45,                      /* sp1m  */
  YYSYMBOL_sp1mb = 46,                     /* sp1mb  */
  YYSYMBOL_ch2 = 47,                       /* ch2  */
  YYSYMBOL_ch1 = 48,                       /* ch1  */
  YYSYMBOL_id1 = 49,                       /* id1  */
  YYSYMBOL_num1 = 50,                      /* num1  */
  YYSYMBOL_expr1 = 51,                     /* expr1  */
  YYSYMBOL_expr2 = 52,                     /* expr2  */
  YYSYMBOL_expr3 = 53,                     /* expr3  */
  YYSYMBOL_expr4 = 54,                     /* expr4  */
  YYSYMBOL_expr5 = 55,                     /* expr5  */
  YYSYMBOL_misc = 56                       /* misc  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    97,   104,   109,   114,   119,   124,   129,
     134,   139,   144,   149,   154,   160,   168,   176,   186,   202,
     207,   223,   237,   257,   273,   292,   300,   314,   315,   316,
     319,   320,   321,   322,   325,   326,   330,   331,   340,   347,
     353,   365,   371,   377,   385,   399,   408,   411,   417,   423,
     429,   435,   443,   446,   452,   460,   463,   469,   475,   483,
     486,   493,   503,   510
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "OR", "AND", "XOR", "NOT", "LSHIFT", "RSHIFT",
  "PAREN1", "PAREN2", "CH", "ID", "SP", "NL", "STR", "COMMENT", "NUM",
  "MAC", "IFDEF", "ENDIF", "ELSE", "ELIFDEF", "DEF", "UNDEF", "ERR", "MSG",
  "$accept", "all1", "all2", "define1", "undef1", "err1", "msg1", "mac1",
  "ifdef1", "elifdef1", "endif1", "else1", "sp1b", "sp1m", "sp1mb", "ch2",
  "ch1", "id1", "num1", "expr1", "expr2", "expr3", "expr4", "expr5",
  "misc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,   -71,   -71,   -14,    34,   -71,   -71,   -71,    19,   -71,
      19,    19,     5,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,    87,    14,    15,    69,   -71,   -71,   -71,
     109,   102,     2,   -71,   -71,   -71,   -71,    17,    20,    32,
     -71,   -71,   113,   113,   113,   113,   113,   113,   -71,   -71,
     113,   -71,   -71,   -71,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    19,   113,   113,   -71,   -71,   117,
     131,   120,   123,   126,    59,   131,    -2,    14,   102,   102,
     102,   102,   102,     2,     2,   -71,   -71,   -71,    44,   131,
     131,   113,   113,   113,   113,   -71,    91,   113,   131,   131,
     111,   131,    65,   131,   -71,    35,    37,    91,   113,   131,
     -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      27,    38,    44,    30,    31,    42,    43,    62,    27,    26,
      27,    27,    27,     2,     4,     5,     6,     7,     8,     9,
      10,    12,    11,     0,    15,     0,    13,    36,    39,    14,
      45,    46,    52,    55,    59,    28,    29,     0,     0,     0,
       1,     3,     0,     0,     0,     0,     0,     0,    32,    33,
      34,    40,    41,    37,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    27,     0,     0,    30,    31,     0,
      25,     0,     0,    19,     0,    35,    34,    35,    47,    49,
      48,    51,    50,    53,    54,    56,    57,    58,     0,    20,
      21,     0,     0,     0,     0,    61,    34,     0,    63,    24,
      17,    18,     0,    22,    23,    32,    33,     0,    34,    16,
      60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,    56,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,    -7,     0,   -48,   -71,    72,   -71,   -71,   -70,
      70,    92,    85,     8,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    77,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    37,    76,    38,    39,    40,    96,    61,    62,    63,
     -28,   -28,    24,   -28,   -28,   -28,    67,    68,    47,   -34,
       7,     1,     2,     3,     4,     5,     6,     7,     8,    50,
     107,     9,    48,    49,    64,    10,    11,    35,    36,   -30,
      65,   -31,    69,    70,    71,    72,    73,    74,   102,   -30,
      75,   -31,    66,   -30,   -30,   -31,   -31,    88,   -29,   -29,
     110,   -29,   -29,   -29,    97,    89,    90,   -34,    41,     1,
       2,     3,     4,     5,     6,     7,     8,    48,    49,     9,
     108,     7,    95,    10,    11,     1,     2,    51,    52,     5,
       6,    98,    99,   100,   101,     0,    75,   103,    53,    54,
      55,    56,     0,    57,    58,    59,    60,   109,    75,    67,
      68,    42,    43,     0,    44,    45,    46,    54,    55,    56,
       0,    57,    58,     0,    78,    79,    80,    81,    82,   105,
     106,    67,    68,     7,    91,    48,    49,    92,    48,    49,
      93,    48,    49,    94,    48,    49,    85,    86,    87,    48,
      49,    83,    84
};

static const yytype_int8 yycheck[] =
{
       0,     8,    50,    10,    11,     0,    76,     5,     6,     7,
      24,    25,    12,    27,    28,    29,    18,    19,     4,    14,
      22,    16,    17,    18,    19,    20,    21,    22,    23,    14,
     100,    26,    18,    19,    17,    30,    31,    18,    19,     4,
      20,     4,    42,    43,    44,    45,    46,    47,    96,    14,
      50,    14,    20,    18,    19,    18,    19,    64,    24,    25,
     108,    27,    28,    29,    20,    65,    66,    14,    12,    16,
      17,    18,    19,    20,    21,    22,    23,    18,    19,    26,
      15,    22,    74,    30,    31,    16,    17,    18,    19,    20,
      21,    91,    92,    93,    94,    -1,    96,    97,    26,     8,
       9,    10,    -1,    12,    13,     3,     4,   107,   108,    18,
      19,    24,    25,    -1,    27,    28,    29,     8,     9,    10,
      -1,    12,    13,    -1,    54,    55,    56,    57,    58,    18,
      19,    18,    19,    22,    17,    18,    19,    17,    18,    19,
      17,    18,    19,    17,    18,    19,    61,    62,    63,    18,
      19,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    18,    19,    44,    44,    44,
       0,    34,    24,    25,    27,    28,    29,     4,    18,    19,
      14,    18,    19,    48,     8,     9,    10,    12,    13,     3,
       4,     5,     6,     7,    17,    20,    20,    18,    19,    45,
      45,    45,    45,    45,    45,    45,    46,    45,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    54,    44,    45,
      45,    17,    17,    17,    17,    55,    51,    20,    45,    45,
      45,    45,    46,    45,    56,    18,    19,    51,    15,    45,
      46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    35,    35,    36,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    44,    44,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    55,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     5,     5,     3,
       4,     4,     6,     6,     5,     3,     1,     0,     1,     1,
       1,     1,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       7,     4,     1,     0
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
  case 2: /* all1: all2  */
#line 93 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all2 '%s' }\n ", (char*)(yyvsp[0].sym));
        }
#line 1311 "parser/ppre.yacc.c"
    break;

  case 3: /* all1: all1 all2  */
#line 98 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all1 all2 '%s' }\n ", (char*)(yyvsp[-1].sym), (char*)(yyvsp[0].sym));
        }
#line 1320 "parser/ppre.yacc.c"
    break;

  case 4: /* all2: define1  */
#line 105 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all1 define '%s' }\n ", (char*)(yyvsp[0].sym));
        }
#line 1329 "parser/ppre.yacc.c"
    break;

  case 5: /* all2: undef1  */
#line 110 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 undef1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1338 "parser/ppre.yacc.c"
    break;

  case 6: /* all2: err1  */
#line 115 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 err1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1347 "parser/ppre.yacc.c"
    break;

  case 7: /* all2: msg1  */
#line 120 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 msg1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1356 "parser/ppre.yacc.c"
    break;

  case 8: /* all2: mac1  */
#line 125 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 mac1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1365 "parser/ppre.yacc.c"
    break;

  case 9: /* all2: ifdef1  */
#line 130 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 ifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1374 "parser/ppre.yacc.c"
    break;

  case 10: /* all2: elifdef1  */
#line 135 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 elifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1383 "parser/ppre.yacc.c"
    break;

  case 11: /* all2: else1  */
#line 140 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 else1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1392 "parser/ppre.yacc.c"
    break;

  case 12: /* all2: endif1  */
#line 145 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 endif1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1401 "parser/ppre.yacc.c"
    break;

  case 13: /* all2: ch2  */
#line 150 "ppre.y"
        {
        //if(config.testpreyacc > 0)
        //    printf("{ all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
#line 1410 "parser/ppre.yacc.c"
    break;

  case 14: /* all2: num1  */
#line 155 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1: num1 x '%s' }\n", (char*)(yyvsp[0].sym));
        (yyval.sym) = strdup((yyvsp[0].sym));
        }
#line 1420 "parser/ppre.yacc.c"
    break;

  case 15: /* all2: sp1m  */
#line 161 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1: space x '%s' }\n", (char*)(yyvsp[0].sym));
        // Ignore
        }
#line 1430 "parser/ppre.yacc.c"
    break;

  case 16: /* define1: sp1b DEF sp1m ID sp1m expr1 sp1m  */
#line 169 "ppre.y"
        { // Ignore
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s' '%s'}\n",
                            (char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1442 "parser/ppre.yacc.c"
    break;

  case 17: /* define1: sp1b DEF sp1m ID sp1m  */
#line 177 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), "",  DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1453 "parser/ppre.yacc.c"
    break;

  case 18: /* undef1: sp1b UNDEF sp1m ID sp1m  */
#line 187 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ undef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
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
#line 1473 "parser/ppre.yacc.c"
    break;

  case 19: /* undef1: sp1b UNDEF sp1m  */
#line 203 "ppre.y"
        { // Ignore
        }
#line 1480 "parser/ppre.yacc.c"
    break;

  case 20: /* err1: ERR sp1b STR sp1m  */
#line 208 "ppre.y"
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
#line 1498 "parser/ppre.yacc.c"
    break;

  case 21: /* msg1: MSG sp1b STR sp1m  */
#line 224 "ppre.y"
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
#line 1515 "parser/ppre.yacc.c"
    break;

  case 22: /* mac1: MAC sp1b ID sp1b STR sp1m  */
#line 238 "ppre.y"
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
#line 1538 "parser/ppre.yacc.c"
    break;

  case 23: /* ifdef1: sp1b IFDEF sp1m ID sp1m misc  */
#line 258 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ ifdef1 '%s' '%s'}\n", (char*)(yyvsp[-4].sym), (char*)(yyvsp[-2].sym));

        if(lookup_symtab((char*)(yyvsp[-2].sym), DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
#line 1556 "parser/ppre.yacc.c"
    break;

  case 24: /* elifdef1: sp1b ELIFDEF sp1m ID sp1m  */
#line 274 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ elifdef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));

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
#line 1577 "parser/ppre.yacc.c"
    break;

  case 25: /* endif1: sp1b ENDIF sp1m  */
#line 293 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ endif1 '%s'}\n", (char*)(yyvsp[-1].sym));
        hasdefine = 2;
        }
#line 1587 "parser/ppre.yacc.c"
    break;

  case 26: /* else1: ELSE  */
#line 301 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ else1 '%s'}\n", (char*)(yyvsp[0].sym));

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
#line 1601 "parser/ppre.yacc.c"
    break;

  case 27: /* sp1b: %empty  */
#line 314 "ppre.y"
               {}
#line 1607 "parser/ppre.yacc.c"
    break;

  case 28: /* sp1b: SP  */
#line 315 "ppre.y"
               {}
#line 1613 "parser/ppre.yacc.c"
    break;

  case 29: /* sp1b: NL  */
#line 316 "ppre.y"
               {}
#line 1619 "parser/ppre.yacc.c"
    break;

  case 30: /* sp1m: SP  */
#line 319 "ppre.y"
                    {}
#line 1625 "parser/ppre.yacc.c"
    break;

  case 31: /* sp1m: NL  */
#line 320 "ppre.y"
                    {}
#line 1631 "parser/ppre.yacc.c"
    break;

  case 32: /* sp1m: sp1m SP  */
#line 321 "ppre.y"
                    {}
#line 1637 "parser/ppre.yacc.c"
    break;

  case 33: /* sp1m: sp1m NL  */
#line 322 "ppre.y"
                    {}
#line 1643 "parser/ppre.yacc.c"
    break;

  case 34: /* sp1mb: %empty  */
#line 325 "ppre.y"
                    {}
#line 1649 "parser/ppre.yacc.c"
    break;

  case 35: /* sp1mb: sp1m  */
#line 326 "ppre.y"
                    {}
#line 1655 "parser/ppre.yacc.c"
    break;

  case 38: /* ch1: CH  */
#line 341 "ppre.y"
      {
      //if(config.testpreyacc > 0)
      //      printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1666 "parser/ppre.yacc.c"
    break;

  case 39: /* ch1: id1  */
#line 348 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ ID '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1676 "parser/ppre.yacc.c"
    break;

  case 40: /* ch1: SP  */
#line 354 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ SP '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1686 "parser/ppre.yacc.c"
    break;

  case 41: /* ch1: NL  */
#line 366 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ NL '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1696 "parser/ppre.yacc.c"
    break;

  case 42: /* ch1: STR  */
#line 372 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ STR '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1706 "parser/ppre.yacc.c"
    break;

  case 43: /* ch1: COMMENT  */
#line 378 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ COMMENT '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1716 "parser/ppre.yacc.c"
    break;

  case 44: /* id1: ID  */
#line 386 "ppre.y"
    {
    if(config.testpreyacc > 0)
            printf("{ id1 : ID '%s}' ", (char*)(yyvsp[0].sym));
    Symbol *sp = lookup_symtab((char*)(yyvsp[0].sym), DECL_MACRO);
    if(sp)
        {
        printf("Macro expansion '%s to %s'\n",  sp->name, sp->var);
        (yyval.sym) = (void*)strdup(sp->var);
        }
    else
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 1733 "parser/ppre.yacc.c"
    break;

  case 45: /* num1: expr1  */
#line 400 "ppre.y"
        {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)(yyvsp[0].sym)));

        (yyval.sym) = str2int((char*)(yyvsp[0].sym));
        }
#line 1744 "parser/ppre.yacc.c"
    break;

  case 46: /* expr1: expr2  */
#line 409 "ppre.y"
    {
    }
#line 1751 "parser/ppre.yacc.c"
    break;

  case 47: /* expr1: expr1 OR expr2  */
#line 412 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) | str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1761 "parser/ppre.yacc.c"
    break;

  case 48: /* expr1: expr1 XOR expr2  */
#line 418 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) ^ str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1771 "parser/ppre.yacc.c"
    break;

  case 49: /* expr1: expr1 AND expr2  */
#line 424 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) & str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1781 "parser/ppre.yacc.c"
    break;

  case 50: /* expr1: expr1 RSHIFT expr2  */
#line 430 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) >> str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1791 "parser/ppre.yacc.c"
    break;

  case 51: /* expr1: expr1 LSHIFT expr2  */
#line 436 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) << str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1801 "parser/ppre.yacc.c"
    break;

  case 52: /* expr2: expr3  */
#line 444 "ppre.y"
    {
    }
#line 1808 "parser/ppre.yacc.c"
    break;

  case 53: /* expr2: expr2 PLUS expr3  */
#line 447 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) + str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1818 "parser/ppre.yacc.c"
    break;

  case 54: /* expr2: expr2 MINUS expr3  */
#line 453 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) - str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1828 "parser/ppre.yacc.c"
    break;

  case 55: /* expr3: expr4  */
#line 461 "ppre.y"
    {
    }
#line 1835 "parser/ppre.yacc.c"
    break;

  case 56: /* expr3: expr3 MULT expr4  */
#line 464 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-1].sym)) * str2int((char*)(yyvsp[-1].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1845 "parser/ppre.yacc.c"
    break;

  case 57: /* expr3: expr3 DIV expr4  */
#line 470 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) / str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1855 "parser/ppre.yacc.c"
    break;

  case 58: /* expr3: expr3 MOD expr4  */
#line 476 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) % str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1865 "parser/ppre.yacc.c"
    break;

  case 59: /* expr4: expr5  */
#line 484 "ppre.y"
    {
    }
#line 1872 "parser/ppre.yacc.c"
    break;

  case 60: /* expr4: sp1mb PAREN1 sp1mb expr1 sp1mb PAREN2 sp1mb  */
#line 487 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ paren: expr4 '%s}' ", (char*)(yyvsp[-3].sym));

        (yyval.sym) = (yyvsp[-3].sym);
        }
#line 1883 "parser/ppre.yacc.c"
    break;

  case 61: /* expr4: sp1m MINUS sp1m expr5  */
#line 494 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[0].sym)); val = -val;
        sprintf(tmp_str3, "%d", val);
        if(config.testpreyacc > 0)
            printf("MINUS %d %s\n", val, tmp_str3);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1895 "parser/ppre.yacc.c"
    break;

  case 62: /* expr5: NUM  */
#line 504 "ppre.y"
        {
         if(config.testpreyacc > 0)
            printf("expr5 NUM %s\n", (char*)(yyvsp[0].sym));
        (yyval.sym) = (yyvsp[0].sym);
        }
#line 1905 "parser/ppre.yacc.c"
    break;

  case 63: /* misc: %empty  */
#line 510 "ppre.y"
        {}
#line 1911 "parser/ppre.yacc.c"
    break;


#line 1915 "parser/ppre.yacc.c"

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

#line 514 "ppre.y"



// EOF

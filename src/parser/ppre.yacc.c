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
#line 18 "ppre.y"


#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We are in a subdir ./parser

#include "../symtab.h"
#include "../xmalloc.h"
#include "../utils.h"

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern  FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

int hasdefine = 2;


#line 108 "parser/ppre.yacc.c"

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
#line 57 "ppre.y"

    //char    *strval;
    Symbol  *sym ;

#line 191 "parser/ppre.yacc.c"

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
  YYSYMBOL_strx1 = 38,                     /* strx1  */
  YYSYMBOL_msg1 = 39,                      /* msg1  */
  YYSYMBOL_mac1 = 40,                      /* mac1  */
  YYSYMBOL_ifdef1 = 41,                    /* ifdef1  */
  YYSYMBOL_elifdef1 = 42,                  /* elifdef1  */
  YYSYMBOL_endif1 = 43,                    /* endif1  */
  YYSYMBOL_else1 = 44,                     /* else1  */
  YYSYMBOL_sp1b = 45,                      /* sp1b  */
  YYSYMBOL_sp1m = 46,                      /* sp1m  */
  YYSYMBOL_sp1mb = 47,                     /* sp1mb  */
  YYSYMBOL_ch2 = 48,                       /* ch2  */
  YYSYMBOL_ch1 = 49,                       /* ch1  */
  YYSYMBOL_id1 = 50,                       /* id1  */
  YYSYMBOL_num1 = 51,                      /* num1  */
  YYSYMBOL_expr1 = 52,                     /* expr1  */
  YYSYMBOL_expr2 = 53,                     /* expr2  */
  YYSYMBOL_expr3 = 54,                     /* expr3  */
  YYSYMBOL_expr4 = 55,                     /* expr4  */
  YYSYMBOL_expr5 = 56,                     /* expr5  */
  YYSYMBOL_misc = 57                       /* misc  */
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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

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
       0,   101,   101,   106,   113,   118,   123,   128,   133,   138,
     143,   148,   153,   158,   163,   178,   186,   196,   212,   217,
     233,   240,   245,   255,   264,   281,   301,   317,   336,   344,
     358,   359,   360,   363,   364,   365,   366,   369,   370,   374,
     375,   384,   391,   397,   409,   415,   421,   429,   443,   452,
     455,   461,   467,   473,   479,   487,   490,   496,   504,   507,
     513,   519,   527,   530,   537,   547,   554
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
  "$accept", "all1", "all2", "define1", "undef1", "err1", "strx1", "msg1",
  "mac1", "ifdef1", "elifdef1", "endif1", "else1", "sp1b", "sp1m", "sp1mb",
  "ch2", "ch1", "id1", "num1", "expr1", "expr2", "expr3", "expr4", "expr5",
  "misc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,   -74,   -74,    47,    93,   -74,   -74,   -74,    10,   -74,
      10,    49,     1,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -15,     7,   -12,   137,   -74,   -74,   -74,
     151,     4,    48,   -74,   -74,   -74,   -74,    -1,    13,   -74,
     -74,   -74,   115,    25,   -74,   -74,    49,    49,    49,    49,
      49,    49,   -74,   -74,    49,   -74,   -74,   -74,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    10,    49,
      49,    49,    97,   115,   119,   130,   148,    76,    51,     4,
       4,     4,     4,     4,    48,    48,   -74,   -74,   -74,    21,
     115,    83,   -74,    49,    49,    49,    49,   -74,   133,    49,
      49,   115,   115,    91,   115,    35,   115,   150,   -74,    30,
      38,   133,    49,    49,    49,   115,   -74,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      30,    41,    47,    43,    44,    45,    46,    65,    30,    29,
      30,    37,    30,     2,     4,     5,     6,     7,     8,     9,
      10,    12,    11,     0,    38,     0,    13,    39,    42,    14,
      48,    49,    55,    58,    62,    31,    32,     0,     0,    33,
      34,    24,    38,     0,     1,     3,     0,     0,     0,     0,
       0,     0,    35,    36,    37,    43,    44,    40,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    30,     0,
      37,    37,     0,    28,     0,     0,    18,     0,    37,    50,
      52,    51,    54,    53,    56,    57,    59,    60,    61,     0,
      19,    20,    21,     0,     0,     0,     0,    64,    37,     0,
      37,    66,    27,    16,    17,     0,    25,    37,    26,    35,
      36,     0,    37,    37,    37,    15,    63,    22,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,    79,   -74,   -74,   -74,   -14,   -74,   -74,   -74,
     -74,   -74,   -74,    -4,   -11,    -8,   -74,    82,   -74,   -74,
     -73,    19,   111,   106,    42,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    41,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    44,    54,    43,    37,    98,    38,    63,    64,    46,
      47,    51,    48,    49,    50,   -37,    68,     1,     2,     3,
       4,     5,     6,     7,     8,    52,    53,     9,    35,    36,
     111,    10,    11,    69,   -33,    72,    73,    74,    75,    76,
      77,    99,   -34,    42,   -33,    70,    78,    71,   -33,   -33,
     112,   -33,   -34,    65,    66,    67,   -34,   -34,    90,    42,
      42,   -33,    91,    92,    89,   -33,   -33,    39,    40,    39,
      40,   -31,   -31,     7,   -31,   -31,   -31,    79,    80,    81,
      82,    83,   101,   102,   103,   104,   100,    42,   106,    42,
     105,    45,   107,   114,    52,    53,    42,   -34,     7,    43,
     115,    42,    42,    42,   116,   117,   118,   -34,    57,   109,
     110,   -34,   -34,     7,    93,    52,    53,   -32,   -32,    97,
     -32,   -32,   -32,   -37,     0,     1,     2,     3,     4,     5,
       6,     7,     8,    52,    53,     9,    94,    52,    53,    10,
      11,    58,    59,    60,     0,    61,    62,    95,    52,    53,
       0,    39,    40,     1,     2,    55,    56,     5,     6,    58,
      59,    60,     0,    61,    62,    96,    52,    53,    39,    40,
     113,    86,    87,    88,    84,    85
};

static const yytype_int8 yycheck[] =
{
      11,     0,    14,    11,     8,    78,    10,     3,     4,    24,
      25,     4,    27,    28,    29,    14,    17,    16,    17,    18,
      19,    20,    21,    22,    23,    18,    19,    26,    18,    19,
     103,    30,    31,    20,     4,    46,    47,    48,    49,    50,
      51,    20,     4,    54,    14,    20,    54,    22,    18,    19,
      15,     4,    14,     5,     6,     7,    18,    19,    69,    70,
      71,    14,    70,    71,    68,    18,    19,    18,    19,    18,
      19,    24,    25,    22,    27,    28,    29,    58,    59,    60,
      61,    62,    93,    94,    95,    96,     3,    98,    99,   100,
      98,    12,   100,   107,    18,    19,   107,     4,    22,   107,
     111,   112,   113,   114,   112,   113,   114,    14,    26,    18,
      19,    18,    19,    22,    17,    18,    19,    24,    25,    77,
      27,    28,    29,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    18,    19,    26,    17,    18,    19,    30,
      31,     8,     9,    10,    -1,    12,    13,    17,    18,    19,
      -1,    18,    19,    16,    17,    18,    19,    20,    21,     8,
       9,    10,    -1,    12,    13,    17,    18,    19,    18,    19,
      20,    65,    66,    67,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      30,    31,    33,    34,    35,    36,    37,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    18,    19,    45,    45,    18,
      19,    38,    46,    47,     0,    34,    24,    25,    27,    28,
      29,     4,    18,    19,    14,    18,    19,    49,     8,     9,
      10,    12,    13,     3,     4,     5,     6,     7,    17,    20,
      20,    22,    46,    46,    46,    46,    46,    46,    47,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    45,
      46,    47,    47,    17,    17,    17,    17,    56,    52,    20,
       3,    46,    46,    46,    46,    47,    46,    47,    57,    18,
      19,    52,    15,    20,    38,    46,    47,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    35,    35,    36,    36,    37,
      38,    38,    38,    38,    39,    40,    41,    42,    43,    44,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    49,    50,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    56,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     5,     5,     3,     4,
       3,     3,     7,     7,     2,     6,     6,     5,     3,     1,
       0,     1,     1,     1,     1,     2,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     7,     4,     1,     0
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
#line 102 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all2 '%s' }\n ", (char*)(yyvsp[0].sym));
        }
#line 1314 "parser/ppre.yacc.c"
    break;

  case 3: /* all1: all1 all2  */
#line 107 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all1 all2 '%s' '%s'}\n ", (char*)(yyvsp[-1].sym), (char*)(yyvsp[0].sym));
        }
#line 1323 "parser/ppre.yacc.c"
    break;

  case 4: /* all2: define1  */
#line 114 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all1 define '%s' }\n ", (char*)(yyvsp[0].sym));
        }
#line 1332 "parser/ppre.yacc.c"
    break;

  case 5: /* all2: undef1  */
#line 119 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 undef1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1341 "parser/ppre.yacc.c"
    break;

  case 6: /* all2: err1  */
#line 124 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 err1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1350 "parser/ppre.yacc.c"
    break;

  case 7: /* all2: msg1  */
#line 129 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 msg1 x'%s'  }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1359 "parser/ppre.yacc.c"
    break;

  case 8: /* all2: mac1  */
#line 134 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 mac1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1368 "parser/ppre.yacc.c"
    break;

  case 9: /* all2: ifdef1  */
#line 139 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 ifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1377 "parser/ppre.yacc.c"
    break;

  case 10: /* all2: elifdef1  */
#line 144 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 elifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1386 "parser/ppre.yacc.c"
    break;

  case 11: /* all2: else1  */
#line 149 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 else1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1395 "parser/ppre.yacc.c"
    break;

  case 12: /* all2: endif1  */
#line 154 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1 endif1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1404 "parser/ppre.yacc.c"
    break;

  case 13: /* all2: ch2  */
#line 159 "ppre.y"
        {
        //if(config.testpreyacc > 0)
        //    printf("{ all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
#line 1413 "parser/ppre.yacc.c"
    break;

  case 14: /* all2: num1  */
#line 164 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all1: num1 x '%s' }\n", (char*)(yyvsp[0].sym));
        (yyval.sym) = strdup((yyvsp[0].sym));
        }
#line 1423 "parser/ppre.yacc.c"
    break;

  case 15: /* define1: sp1b DEF sp1m ID sp1m expr1 sp1m  */
#line 179 "ppre.y"
        { // Ignore
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s' '%s'}\n",
                            (char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1435 "parser/ppre.yacc.c"
    break;

  case 16: /* define1: sp1b DEF sp1m ID sp1m  */
#line 187 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), "",  DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1446 "parser/ppre.yacc.c"
    break;

  case 17: /* undef1: sp1b UNDEF sp1m ID sp1m  */
#line 197 "ppre.y"
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
#line 1466 "parser/ppre.yacc.c"
    break;

  case 18: /* undef1: sp1b UNDEF sp1m  */
#line 213 "ppre.y"
        { // Ignore
        }
#line 1473 "parser/ppre.yacc.c"
    break;

  case 19: /* err1: ERR sp1b STR sp1m  */
#line 218 "ppre.y"
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
#line 1491 "parser/ppre.yacc.c"
    break;

  case 20: /* strx1: sp1mb STR sp1mb  */
#line 234 "ppre.y"
            {
            printf("msg1 STR '%s'\n", (char*)(yyvsp[-1].sym)->var);

            //printf("msg1 STR $$ '%s'\n", $$->var);
            (yyval.sym)=(yyvsp[-1].sym);
            }
#line 1502 "parser/ppre.yacc.c"
    break;

  case 21: /* strx1: sp1mb NUM sp1mb  */
#line 241 "ppre.y"
            {
            printf("msg1 NUM '%s'\n", (yyvsp[-1].sym)->res);
            (yyval.sym)=(yyvsp[-1].sym);
            }
#line 1511 "parser/ppre.yacc.c"
    break;

  case 22: /* strx1: sp1mb STR sp1mb PLUS sp1mb STR sp1mb  */
#line 246 "ppre.y"
            {
            printf("double add' %s' '%s' %p\n", (yyvsp[-5].sym)->var, (yyvsp[-1].sym)->var, (yyval.sym));
            dump_symitem((yyval.sym));

            char *sum = addstrs((yyvsp[-5].sym), (yyvsp[-1].sym));
            //Symbol  *st2 = push_symtab((char*)$2, (char*)$6, sum,  STR, 0);
            Symbol  *st2 = make_symtab(sum, sum, sum,  STR, 0);
            (yyval.sym) = sum;
            }
#line 1525 "parser/ppre.yacc.c"
    break;

  case 23: /* strx1: sp1mb STR sp1mb PLUS sp1mb strx1 sp1mb  */
#line 256 "ppre.y"
            {
            printf("cumm add' %s' '%s'\n", (char*)(yyvsp[-5].sym), (char*)(yyvsp[-1].sym));
            char *sum = addstrs((yyvsp[-5].sym), (yyvsp[-1].sym));
            Symbol  *st2 = push_symtab((char*)(yyvsp[-5].sym), (char*)(yyvsp[-1].sym), sum,  STR, 0);
            (yyval.sym)=st2;
            }
#line 1536 "parser/ppre.yacc.c"
    break;

  case 24: /* msg1: MSG strx1  */
#line 265 "ppre.y"
        {
        printf("msg1: '%s'\n", (char *)(yyvsp[0].sym));
        }
#line 1544 "parser/ppre.yacc.c"
    break;

  case 25: /* mac1: MAC sp1b ID sp1b STR sp1m  */
#line 282 "ppre.y"
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
#line 1567 "parser/ppre.yacc.c"
    break;

  case 26: /* ifdef1: sp1b IFDEF sp1m ID sp1m misc  */
#line 302 "ppre.y"
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
#line 1585 "parser/ppre.yacc.c"
    break;

  case 27: /* elifdef1: sp1b ELIFDEF sp1m ID sp1m  */
#line 318 "ppre.y"
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
#line 1606 "parser/ppre.yacc.c"
    break;

  case 28: /* endif1: sp1b ENDIF sp1m  */
#line 337 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ endif1 '%s'}\n", (char*)(yyvsp[-1].sym));
        hasdefine = 2;
        }
#line 1616 "parser/ppre.yacc.c"
    break;

  case 29: /* else1: ELSE  */
#line 345 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ else1 '%s'}\n", (char*)(yyvsp[0].sym));

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
#line 1630 "parser/ppre.yacc.c"
    break;

  case 30: /* sp1b: %empty  */
#line 358 "ppre.y"
               {}
#line 1636 "parser/ppre.yacc.c"
    break;

  case 31: /* sp1b: SP  */
#line 359 "ppre.y"
               {}
#line 1642 "parser/ppre.yacc.c"
    break;

  case 32: /* sp1b: NL  */
#line 360 "ppre.y"
               {}
#line 1648 "parser/ppre.yacc.c"
    break;

  case 33: /* sp1m: SP  */
#line 363 "ppre.y"
                    {}
#line 1654 "parser/ppre.yacc.c"
    break;

  case 34: /* sp1m: NL  */
#line 364 "ppre.y"
                    {}
#line 1660 "parser/ppre.yacc.c"
    break;

  case 35: /* sp1m: sp1m SP  */
#line 365 "ppre.y"
                    {}
#line 1666 "parser/ppre.yacc.c"
    break;

  case 36: /* sp1m: sp1m NL  */
#line 366 "ppre.y"
                    {}
#line 1672 "parser/ppre.yacc.c"
    break;

  case 37: /* sp1mb: %empty  */
#line 369 "ppre.y"
                    {}
#line 1678 "parser/ppre.yacc.c"
    break;

  case 38: /* sp1mb: sp1m  */
#line 370 "ppre.y"
                    {}
#line 1684 "parser/ppre.yacc.c"
    break;

  case 41: /* ch1: CH  */
#line 385 "ppre.y"
      {
      //if(config.testpreyacc > 0)
      //      printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1695 "parser/ppre.yacc.c"
    break;

  case 42: /* ch1: id1  */
#line 392 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ ID '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1705 "parser/ppre.yacc.c"
    break;

  case 43: /* ch1: SP  */
#line 398 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ SP '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1715 "parser/ppre.yacc.c"
    break;

  case 44: /* ch1: NL  */
#line 410 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ NL '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1725 "parser/ppre.yacc.c"
    break;

  case 45: /* ch1: STR  */
#line 416 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ STR '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1735 "parser/ppre.yacc.c"
    break;

  case 46: /* ch1: COMMENT  */
#line 422 "ppre.y"
      { if(config.testpreyacc > 0)
            printf("{ COMMENT '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1745 "parser/ppre.yacc.c"
    break;

  case 47: /* id1: ID  */
#line 430 "ppre.y"
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
#line 1762 "parser/ppre.yacc.c"
    break;

  case 48: /* num1: expr1  */
#line 444 "ppre.y"
        {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)(yyvsp[0].sym)));

        (yyval.sym) = str2int((char*)(yyvsp[0].sym));
        }
#line 1773 "parser/ppre.yacc.c"
    break;

  case 49: /* expr1: expr2  */
#line 453 "ppre.y"
    {
    }
#line 1780 "parser/ppre.yacc.c"
    break;

  case 50: /* expr1: expr1 OR expr2  */
#line 456 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) | str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1790 "parser/ppre.yacc.c"
    break;

  case 51: /* expr1: expr1 XOR expr2  */
#line 462 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) ^ str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1800 "parser/ppre.yacc.c"
    break;

  case 52: /* expr1: expr1 AND expr2  */
#line 468 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) & str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1810 "parser/ppre.yacc.c"
    break;

  case 53: /* expr1: expr1 RSHIFT expr2  */
#line 474 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) >> str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1820 "parser/ppre.yacc.c"
    break;

  case 54: /* expr1: expr1 LSHIFT expr2  */
#line 480 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) << str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1830 "parser/ppre.yacc.c"
    break;

  case 55: /* expr2: expr3  */
#line 488 "ppre.y"
    {
    }
#line 1837 "parser/ppre.yacc.c"
    break;

  case 56: /* expr2: expr2 PLUS expr3  */
#line 491 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) + str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1847 "parser/ppre.yacc.c"
    break;

  case 57: /* expr2: expr2 MINUS expr3  */
#line 497 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) - str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1857 "parser/ppre.yacc.c"
    break;

  case 58: /* expr3: expr4  */
#line 505 "ppre.y"
    {
    }
#line 1864 "parser/ppre.yacc.c"
    break;

  case 59: /* expr3: expr3 MULT expr4  */
#line 508 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-1].sym)) * str2int((char*)(yyvsp[-1].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1874 "parser/ppre.yacc.c"
    break;

  case 60: /* expr3: expr3 DIV expr4  */
#line 514 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) / str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1884 "parser/ppre.yacc.c"
    break;

  case 61: /* expr3: expr3 MOD expr4  */
#line 520 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) % str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1894 "parser/ppre.yacc.c"
    break;

  case 62: /* expr4: expr5  */
#line 528 "ppre.y"
    {
    }
#line 1901 "parser/ppre.yacc.c"
    break;

  case 63: /* expr4: sp1mb PAREN1 sp1mb expr1 sp1mb PAREN2 sp1mb  */
#line 531 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ paren: expr4 '%s}' ", (char*)(yyvsp[-3].sym));

        (yyval.sym) = (yyvsp[-3].sym);
        }
#line 1912 "parser/ppre.yacc.c"
    break;

  case 64: /* expr4: sp1m MINUS sp1m expr5  */
#line 538 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[0].sym)); val = -val;
        sprintf(tmp_str3, "%d", val);
        if(config.testpreyacc > 0)
            printf("MINUS %d %s\n", val, tmp_str3);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1924 "parser/ppre.yacc.c"
    break;

  case 65: /* expr5: NUM  */
#line 548 "ppre.y"
        {
         if(config.testpreyacc > 0)
            printf("expr5 NUM %s\n", (char*)(yyvsp[0].sym));
        (yyval.sym) = (yyvsp[0].sym);
        }
#line 1934 "parser/ppre.yacc.c"
    break;

  case 66: /* misc: %empty  */
#line 554 "ppre.y"
        {}
#line 1940 "parser/ppre.yacc.c"
    break;


#line 1944 "parser/ppre.yacc.c"

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

#line 558 "ppre.y"



// EOF

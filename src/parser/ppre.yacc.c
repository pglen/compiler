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

int hasdefine = 2;


#line 105 "parser/ppre.yacc.c"

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
    CH2 = 272,                     /* CH2  */
    ID2 = 273,                     /* ID2  */
    SP2 = 274,                     /* SP2  */
    NL2 = 275,                     /* NL2  */
    STR2 = 276,                    /* STR2  */
    COMMENT2 = 277,                /* COMMENT2  */
    NUM2 = 278,                    /* NUM2  */
    MAC2 = 279,                    /* MAC2  */
    IFDEF2 = 280,                  /* IFDEF2  */
    ENDIF2 = 281,                  /* ENDIF2  */
    ELSE2 = 282,                   /* ELSE2  */
    ELIFDEF2 = 283,                /* ELIFDEF2  */
    DEF2 = 284,                    /* DEF2  */
    UNDEF2 = 285,                  /* UNDEF2  */
    ERR2 = 286,                    /* ERR2  */
    MSG2 = 287                     /* MSG2  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "ppre.y"

    //char    *strval;
    Symbol  *sym ;

#line 189 "parser/ppre.yacc.c"

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
  YYSYMBOL_CH2 = 17,                       /* CH2  */
  YYSYMBOL_ID2 = 18,                       /* ID2  */
  YYSYMBOL_SP2 = 19,                       /* SP2  */
  YYSYMBOL_NL2 = 20,                       /* NL2  */
  YYSYMBOL_STR2 = 21,                      /* STR2  */
  YYSYMBOL_COMMENT2 = 22,                  /* COMMENT2  */
  YYSYMBOL_NUM2 = 23,                      /* NUM2  */
  YYSYMBOL_MAC2 = 24,                      /* MAC2  */
  YYSYMBOL_IFDEF2 = 25,                    /* IFDEF2  */
  YYSYMBOL_ENDIF2 = 26,                    /* ENDIF2  */
  YYSYMBOL_ELSE2 = 27,                     /* ELSE2  */
  YYSYMBOL_ELIFDEF2 = 28,                  /* ELIFDEF2  */
  YYSYMBOL_DEF2 = 29,                      /* DEF2  */
  YYSYMBOL_UNDEF2 = 30,                    /* UNDEF2  */
  YYSYMBOL_ERR2 = 31,                      /* ERR2  */
  YYSYMBOL_MSG2 = 32,                      /* MSG2  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_all1 = 34,                      /* all1  */
  YYSYMBOL_all2 = 35,                      /* all2  */
  YYSYMBOL_define1 = 36,                   /* define1  */
  YYSYMBOL_undef1 = 37,                    /* undef1  */
  YYSYMBOL_err1 = 38,                      /* err1  */
  YYSYMBOL_strx1 = 39,                     /* strx1  */
  YYSYMBOL_msg1 = 40,                      /* msg1  */
  YYSYMBOL_mac1 = 41,                      /* mac1  */
  YYSYMBOL_ifdef1 = 42,                    /* ifdef1  */
  YYSYMBOL_elifdef1 = 43,                  /* elifdef1  */
  YYSYMBOL_endif1 = 44,                    /* endif1  */
  YYSYMBOL_else1 = 45,                     /* else1  */
  YYSYMBOL_sp1 = 46,                       /* sp1  */
  YYSYMBOL_sp1b = 47,                      /* sp1b  */
  YYSYMBOL_sp1m = 48,                      /* sp1m  */
  YYSYMBOL_sp1mb = 49,                     /* sp1mb  */
  YYSYMBOL_expr1 = 50,                     /* expr1  */
  YYSYMBOL_expr2 = 51,                     /* expr2  */
  YYSYMBOL_expr3 = 52,                     /* expr3  */
  YYSYMBOL_expr4 = 53,                     /* expr4  */
  YYSYMBOL_expr5 = 54                      /* expr5  */
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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   100,   107,   112,   117,   122,   127,   132,
     137,   142,   147,   152,   157,   164,   172,   181,   197,   202,
     218,   226,   235,   241,   248,   268,   283,   301,   308,   322,
     323,   325,   326,   328,   329,   330,   331,   333,   337,   343,
     347,   355,   361,   367,   373,   380,   385,   393,   401,   406,
     414,   420,   427,   430,   436,   444
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
  "RSHIFT2", "PAREN12", "PAREN22", "SEMI2", "CH2", "ID2", "SP2", "NL2",
  "STR2", "COMMENT2", "NUM2", "MAC2", "IFDEF2", "ENDIF2", "ELSE2",
  "ELIFDEF2", "DEF2", "UNDEF2", "ERR2", "MSG2", "$accept", "all1", "all2",
  "define1", "undef1", "err1", "strx1", "msg1", "mac1", "ifdef1",
  "elifdef1", "endif1", "else1", "sp1", "sp1b", "sp1m", "sp1mb", "expr1",
  "expr2", "expr3", "expr4", "expr5", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,   -25,   -25,   -25,    -1,   -25,    -1,     8,     2,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
      28,   -25,   -15,   -16,   -25,   -25,    68,    59,   -25,   -25,
       8,     8,     8,     8,     8,    -1,     8,   -25,   -25,     8,
     -25,     7,     0,    29,    27,    99,   -25,   -25,   103,    68,
     127,   130,   133,     4,    68,    32,   -25,     8,     8,   -25,
     131,   104,   149,     8,     8,     8,     8,     8,     8,    39,
      39,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,    68,    68,    -3,    68,    68,    31,   -25,     8,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    70,
      72,     8,     8,    60,    27,    27,    27,    27,    27,    99,
      99,   -25,   -25,   -25,   118,   -25,     8,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      31,    29,    14,    13,    31,    28,    31,    37,    31,     2,
       4,     5,     6,     7,     8,     9,    10,    12,    11,    32,
       0,    30,     0,     0,    33,    34,    38,    37,     1,     3,
       0,     0,     0,     0,     0,    31,     0,    35,    36,    37,
      55,     0,     0,    37,    39,    45,    48,    52,     0,    27,
       0,     0,    18,     0,    19,    20,    22,    37,    37,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    25,    26,    16,    17,    24,     0,    54,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    35,
      36,    37,    37,     0,    40,    42,    41,    44,    43,    46,
      47,    49,    50,    51,    15,    21,    37,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,    47,   -25,   -25,   -25,    10,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,     9,   -24,    -7,    33,    43,    16,
      61,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    41,    13,    14,    15,
      16,    17,    18,    19,    20,    26,    42,    43,    44,    45,
      46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,   -37,    28,    35,    57,    36,    48,    49,    50,    51,
      52,   -37,    54,    22,    58,    23,    99,   100,     1,    21,
      40,     1,     2,    56,     3,    67,     4,    24,    25,     5,
     -37,   -37,    55,     6,     7,    68,    60,    61,    62,    81,
      82,    83,    84,    85,    53,    59,    24,    25,    24,    25,
      69,    70,    39,    30,    31,    29,    32,    33,    34,    24,
      25,    86,    40,    40,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   -33,   116,   -34,   114,    24,    25,
      39,   103,    40,     0,   -33,     0,   -34,    37,    38,   -33,
     -33,   -34,   -34,     0,    60,   115,   102,    61,    61,    61,
      61,    61,    62,    62,   -37,   -37,   -37,    76,    77,   117,
     109,   110,     1,     2,     0,     3,   101,     4,    24,    25,
       5,    63,    37,    38,     6,     7,   -38,   -38,   -38,     0,
     -38,   -38,   104,   105,   106,   107,   108,    37,    38,    71,
      72,    73,     0,    74,    75,    64,    37,    38,    65,    37,
      38,    66,    37,    38,    78,    79,    80,   111,   112,   113,
      87,    88
};

static const yytype_int8 yycheck[] =
{
       7,     4,     0,    18,     4,    21,    30,    31,    32,    33,
      34,    14,    36,     4,    14,     6,    19,    20,    19,    20,
      23,    19,    20,    16,    22,    21,    24,    19,    20,    27,
       3,     4,    39,    31,    32,     3,    43,    44,    45,    63,
      64,    65,    66,    67,    35,    16,    19,    20,    19,    20,
      57,    58,    21,    25,    26,     8,    28,    29,    30,    19,
      20,    68,    23,    23,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     4,    15,     4,   101,    19,    20,
      21,    88,    23,    -1,    14,    -1,    14,    19,    20,    19,
      20,    19,    20,    -1,   101,   102,    86,   104,   105,   106,
     107,   108,   109,   110,     5,     6,     7,     3,     4,   116,
      94,    95,    19,    20,    -1,    22,    83,    24,    19,    20,
      27,    18,    19,    20,    31,    32,     8,     9,    10,    -1,
      12,    13,    89,    90,    91,    92,    93,    19,    20,     8,
       9,    10,    -1,    12,    13,    18,    19,    20,    18,    19,
      20,    18,    19,    20,     5,     6,     7,    96,    97,    98,
      69,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    22,    24,    27,    31,    32,    34,    35,
      36,    37,    38,    40,    41,    42,    43,    44,    45,    46,
      47,    20,    47,    47,    19,    20,    48,    49,     0,    35,
      25,    26,    28,    29,    30,    18,    21,    19,    20,    21,
      23,    39,    49,    50,    51,    52,    53,    54,    48,    48,
      48,    48,    48,    47,    48,    49,    16,     4,    14,    16,
      49,    49,    49,    18,    18,    18,    18,    21,     3,    49,
      49,     8,     9,    10,    12,    13,     3,     4,     5,     6,
       7,    48,    48,    48,    48,    48,    49,    54,    54,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    19,
      20,    50,    39,    49,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    48,    49,    15,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    36,    36,    37,    37,    38,
      39,    39,    40,    40,    41,    42,    43,    44,    45,    46,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    53,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     5,     5,     3,     4,
       2,     6,     4,     4,     6,     5,     5,     3,     1,     1,
       1,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       5,     5,     5,     5,     5,     1,     5,     5,     1,     5,
       5,     5,     1,     7,     4,     1
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
#line 96 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all2 root '%s' }\n ", (char*)(yyvsp[0].sym)->var);
        }
#line 1304 "parser/ppre.yacc.c"
    break;

  case 3: /* all1: all1 all2  */
#line 101 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all1 all2 root '%s' '%s'}\n ", (yyvsp[-1].sym)->var, (yyvsp[0].sym)->var);
        }
#line 1313 "parser/ppre.yacc.c"
    break;

  case 4: /* all2: define1  */
#line 108 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { all2 define '%s' }\n ", (yyvsp[0].sym)->var);
        }
#line 1322 "parser/ppre.yacc.c"
    break;

  case 5: /* all2: undef1  */
#line 113 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 undef1 x'%s' }\n", (yyvsp[0].sym)->var);
        }
#line 1331 "parser/ppre.yacc.c"
    break;

  case 6: /* all2: err1  */
#line 118 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 err1 x'%s' }\n", (yyvsp[0].sym)->var);
        }
#line 1340 "parser/ppre.yacc.c"
    break;

  case 7: /* all2: msg1  */
#line 123 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 msg1 '%s' }\n", (yyvsp[0].sym)->var);
        }
#line 1349 "parser/ppre.yacc.c"
    break;

  case 8: /* all2: mac1  */
#line 128 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 mac1 x'%s' }\n", (yyvsp[0].sym)->var);
        }
#line 1358 "parser/ppre.yacc.c"
    break;

  case 9: /* all2: ifdef1  */
#line 133 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 ifdef1 x'%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1367 "parser/ppre.yacc.c"
    break;

  case 10: /* all2: elifdef1  */
#line 138 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 elifdef1 x'%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1376 "parser/ppre.yacc.c"
    break;

  case 11: /* all2: else1  */
#line 143 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 else1 x'%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1385 "parser/ppre.yacc.c"
    break;

  case 12: /* all2: endif1  */
#line 148 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 endif1 x'%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1394 "parser/ppre.yacc.c"
    break;

  case 13: /* all2: COMMENT2  */
#line 153 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 comment '%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1403 "parser/ppre.yacc.c"
    break;

  case 14: /* all2: NL2  */
#line 158 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ all2 newline '%s' }\n", (char*)(yyvsp[0].sym)->var);
        }
#line 1412 "parser/ppre.yacc.c"
    break;

  case 15: /* define1: sp1b DEF2 sp1m ID2 sp1m expr1 sp1m  */
#line 165 "ppre.y"
        { // Ignore
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s' '%s'}\n",
                            (char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-5].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1424 "parser/ppre.yacc.c"
    break;

  case 16: /* define1: sp1b DEF2 sp1m ID2 sp1m  */
#line 173 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), "",  DECL_DEFINE, 0);
        //$$ = $2;
        }
#line 1435 "parser/ppre.yacc.c"
    break;

  case 17: /* undef1: sp1b UNDEF2 sp1m ID2 sp1m  */
#line 182 "ppre.y"
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
#line 1455 "parser/ppre.yacc.c"
    break;

  case 18: /* undef1: sp1b UNDEF2 sp1m  */
#line 198 "ppre.y"
        { // Ignore
        }
#line 1462 "parser/ppre.yacc.c"
    break;

  case 19: /* err1: ERR2 sp1b STR2 sp1m  */
#line 203 "ppre.y"
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
#line 1480 "parser/ppre.yacc.c"
    break;

  case 20: /* strx1: STR2 sp1mb  */
#line 219 "ppre.y"
            {
            //printf("strx1 '%s'\n", $1->var);
            //Symbol *ss = make_symstr("", $1->var, STR2);
            //$$->var = $1->var;
            //$$->var = $1->var;
            //$$ = $1;
            }
#line 1492 "parser/ppre.yacc.c"
    break;

  case 21: /* strx1: STR2 sp1mb PLUS2 sp1mb strx1 sp1mb  */
#line 227 "ppre.y"
            {
            //printf("msg add' %s' '%s'\n", (char*)$1->var, (char*)$5->var);
            char *sum = addstrs((yyvsp[-5].sym)->var, (yyvsp[-1].sym)->var);
            //printf("sum: '%s'\n", sum);
            Symbol *ss = make_symstr("", sum, STR2);
            (yyval.sym) = ss;
            }
#line 1504 "parser/ppre.yacc.c"
    break;

  case 22: /* msg1: MSG2 sp1mb strx1 SEMI2  */
#line 236 "ppre.y"
            {
            if(config.testpreyacc > 0)
                printf(" { msg1: '%s' } ", (yyvsp[-1].sym)->var);
            printf(""mmm" %s\n", (yyvsp[-1].sym)->var);
            }
#line 1514 "parser/ppre.yacc.c"
    break;

  case 23: /* msg1: MSG2 sp1mb expr1 SEMI2  */
#line 242 "ppre.y"
            {
            if(config.testpreyacc > 0)
                printf(" { msg1: numx1 '%s' } ", (yyvsp[-1].sym)->var);
            printf("%s\n", (yyvsp[-1].sym)->var);
            }
#line 1524 "parser/ppre.yacc.c"
    break;

  case 24: /* mac1: MAC2 sp1b ID2 sp1b STR2 sp1m  */
#line 249 "ppre.y"
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
#line 1547 "parser/ppre.yacc.c"
    break;

  case 25: /* ifdef1: sp1b IFDEF2 sp1m ID2 sp1m  */
#line 269 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ ifdef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));

        if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
#line 1565 "parser/ppre.yacc.c"
    break;

  case 26: /* elifdef1: sp1b ELIFDEF2 sp1m ID2 sp1m  */
#line 284 "ppre.y"
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
#line 1586 "parser/ppre.yacc.c"
    break;

  case 27: /* endif1: sp1b ENDIF2 sp1m  */
#line 302 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ endif1 '%s'}\n", (char*)(yyvsp[-1].sym));
        hasdefine = 2;
        }
#line 1596 "parser/ppre.yacc.c"
    break;

  case 28: /* else1: ELSE2  */
#line 309 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ else1 '%s'}\n", (char*)(yyvsp[0].sym));

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
#line 1610 "parser/ppre.yacc.c"
    break;

  case 29: /* sp1: SP2  */
#line 322 "ppre.y"
                {}
#line 1616 "parser/ppre.yacc.c"
    break;

  case 30: /* sp1: NL2  */
#line 323 "ppre.y"
                {}
#line 1622 "parser/ppre.yacc.c"
    break;

  case 31: /* sp1b: %empty  */
#line 325 "ppre.y"
                {}
#line 1628 "parser/ppre.yacc.c"
    break;

  case 32: /* sp1b: sp1  */
#line 326 "ppre.y"
                {}
#line 1634 "parser/ppre.yacc.c"
    break;

  case 33: /* sp1m: SP2  */
#line 328 "ppre.y"
                     {}
#line 1640 "parser/ppre.yacc.c"
    break;

  case 34: /* sp1m: NL2  */
#line 329 "ppre.y"
                     {}
#line 1646 "parser/ppre.yacc.c"
    break;

  case 35: /* sp1m: sp1m SP2  */
#line 330 "ppre.y"
                     {}
#line 1652 "parser/ppre.yacc.c"
    break;

  case 36: /* sp1m: sp1m NL2  */
#line 331 "ppre.y"
                     {}
#line 1658 "parser/ppre.yacc.c"
    break;

  case 37: /* sp1mb: %empty  */
#line 333 "ppre.y"
            {  /* empty */
            printf(" spb ");
            //$$ = make_symstr("", " ", STR2);
            }
#line 1667 "parser/ppre.yacc.c"
    break;

  case 38: /* sp1mb: sp1m  */
#line 338 "ppre.y"
            {
            printf(" spm ");
            //$$ = make_symstr("", " ", STR2);
            }
#line 1676 "parser/ppre.yacc.c"
    break;

  case 39: /* expr1: expr2  */
#line 344 "ppre.y"
        {
        printf(" { expr1: %s } ", (yyvsp[0].sym)->var);
        }
#line 1684 "parser/ppre.yacc.c"
    break;

  case 40: /* expr1: expr1 sp1mb OR2 sp1mb expr2  */
#line 348 "ppre.y"
        {
        if(config.testpreyacc > 1)
            printf("expr1 '%s' OR '%s'\n", (yyvsp[-4].sym)->var, (yyvsp[0].sym)->var);
        int val = str2int((yyvsp[-4].sym)->var) | str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1696 "parser/ppre.yacc.c"
    break;

  case 41: /* expr1: expr1 sp1mb XOR2 sp1mb expr2  */
#line 356 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) ^ str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1706 "parser/ppre.yacc.c"
    break;

  case 42: /* expr1: expr1 sp1mb AND2 sp1mb expr2  */
#line 362 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) & str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1716 "parser/ppre.yacc.c"
    break;

  case 43: /* expr1: expr1 sp1mb RSHIFT2 sp1mb expr2  */
#line 368 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) >> str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1726 "parser/ppre.yacc.c"
    break;

  case 44: /* expr1: expr1 sp1mb LSHIFT2 sp1mb expr2  */
#line 374 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) << str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1736 "parser/ppre.yacc.c"
    break;

  case 45: /* expr2: expr3  */
#line 381 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf("{ expr2 '%s'} ", (yyvsp[0].sym)->var);
        }
#line 1745 "parser/ppre.yacc.c"
    break;

  case 46: /* expr2: expr2 sp1mb PLUS2 sp1mb expr3  */
#line 386 "ppre.y"
        {
        if(config.testpreyacc > 0)
           printf(" { expr2 '%s' PLUS '%s } ", (yyvsp[-4].sym)->var, (yyvsp[0].sym)->var);
        int val = str2int((yyvsp[-4].sym)->var) + str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1757 "parser/ppre.yacc.c"
    break;

  case 47: /* expr2: expr2 sp1mb MINUS2 sp1mb expr3  */
#line 394 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) - str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1767 "parser/ppre.yacc.c"
    break;

  case 48: /* expr3: expr4  */
#line 402 "ppre.y"
    {
    if(config.testpreyacc > 0)
        printf("{ expr3 '%s' } ", (yyvsp[0].sym)->var);
    }
#line 1776 "parser/ppre.yacc.c"
    break;

  case 49: /* expr3: expr3 sp1mb MULT2 sp1mb expr4  */
#line 407 "ppre.y"
        {
        //if(config.testpreyacc > 1)
        //    printf("expr3 '%s' MUL '%s'\n", $1->var, $5->var);
        int val = str2int((yyvsp[-4].sym)->var) * str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1788 "parser/ppre.yacc.c"
    break;

  case 50: /* expr3: expr3 sp1mb DIV2 sp1mb expr4  */
#line 415 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) / str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1798 "parser/ppre.yacc.c"
    break;

  case 51: /* expr3: expr3 sp1mb MOD2 sp1mb expr4  */
#line 421 "ppre.y"
        {
        int val = str2int((yyvsp[-4].sym)->var) % str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1808 "parser/ppre.yacc.c"
    break;

  case 52: /* expr4: expr5  */
#line 428 "ppre.y"
    {
    }
#line 1815 "parser/ppre.yacc.c"
    break;

  case 53: /* expr4: sp1mb PAREN12 sp1mb expr5 sp1mb PAREN22 sp1mb  */
#line 431 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { paren: expr4 '%s} '", (yyvsp[-3].sym)->var);
        (yyval.sym) = make_symstr("", (yyvsp[-3].sym)->var, NUM2);
        }
#line 1825 "parser/ppre.yacc.c"
    break;

  case 54: /* expr4: sp1mb MINUS2 sp1mb expr5  */
#line 437 "ppre.y"
        {
        int val = str2int((yyvsp[0].sym)->var);
        sprintf(tmp_str3, "%d", -val);
        (yyval.sym) = make_symstr("", strdup(tmp_str3), NUM2);
        }
#line 1835 "parser/ppre.yacc.c"
    break;

  case 55: /* expr5: NUM2  */
#line 445 "ppre.y"
        {
        if(config.testpreyacc > 0)
            printf(" { expr5 '%s' } ", (yyvsp[0].sym)->var);
        //$$ = make_symstr("", $1->var, NUM2);
        //$$ = $1;
        }
#line 1846 "parser/ppre.yacc.c"
    break;


#line 1850 "parser/ppre.yacc.c"

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

#line 453 "ppre.y"


// EOF

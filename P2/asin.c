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




/* First part of user prologue.  */
#line 1 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"

#line 78 "asin.c"

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

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPSUMA_ = 3,                    /* OPSUMA_  */
  YYSYMBOL_OPRESTA_ = 4,                   /* OPRESTA_  */
  YYSYMBOL_OPMULT_ = 5,                    /* OPMULT_  */
  YYSYMBOL_OPDIV_ = 6,                     /* OPDIV_  */
  YYSYMBOL_OPAND_ = 7,                     /* OPAND_  */
  YYSYMBOL_OPDECREASE_ = 8,                /* OPDECREASE_  */
  YYSYMBOL_OPIGUAL_ = 9,                   /* OPIGUAL_  */
  YYSYMBOL_OPINCREASE_ = 10,               /* OPINCREASE_  */
  YYSYMBOL_OPNOT_ = 11,                    /* OPNOT_  */
  YYSYMBOL_OPOR_ = 12,                     /* OPOR_  */
  YYSYMBOL_COMPDIF_ = 13,                  /* COMPDIF_  */
  YYSYMBOL_COMPIGUAL_ = 14,                /* COMPIGUAL_  */
  YYSYMBOL_COMPMAYOR_ = 15,                /* COMPMAYOR_  */
  YYSYMBOL_COMPMAYORIG_ = 16,              /* COMPMAYORIG_  */
  YYSYMBOL_COMPMENOR_ = 17,                /* COMPMENOR_  */
  YYSYMBOL_COMPMENORIG_ = 18,              /* COMPMENORIG_  */
  YYSYMBOL_OPENCORCH_ = 19,                /* OPENCORCH_  */
  YYSYMBOL_OPENLLAVE_ = 20,                /* OPENLLAVE_  */
  YYSYMBOL_OPENPAR_ = 21,                  /* OPENPAR_  */
  YYSYMBOL_CLOSECORCH_ = 22,               /* CLOSECORCH_  */
  YYSYMBOL_CLOSELLAVE_ = 23,               /* CLOSELLAVE_  */
  YYSYMBOL_CLOSEPAR_ = 24,                 /* CLOSEPAR_  */
  YYSYMBOL_SEMICOLON_ = 25,                /* SEMICOLON_  */
  YYSYMBOL_COMA_ = 26,                     /* COMA_  */
  YYSYMBOL_PUNTO_ = 27,                    /* PUNTO_  */
  YYSYMBOL_FOR_ = 28,                      /* FOR_  */
  YYSYMBOL_IF_ = 29,                       /* IF_  */
  YYSYMBOL_ELSE_ = 30,                     /* ELSE_  */
  YYSYMBOL_WHILE_ = 31,                    /* WHILE_  */
  YYSYMBOL_STRUCT_ = 32,                   /* STRUCT_  */
  YYSYMBOL_READ_ = 33,                     /* READ_  */
  YYSYMBOL_RETURN_ = 34,                   /* RETURN_  */
  YYSYMBOL_PRINT_ = 35,                    /* PRINT_  */
  YYSYMBOL_TRUE_ = 36,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 37,                    /* FALSE_  */
  YYSYMBOL_BOOL_ = 38,                     /* BOOL_  */
  YYSYMBOL_CTE_ = 39,                      /* CTE_  */
  YYSYMBOL_INT_ = 40,                      /* INT_  */
  YYSYMBOL_ID_ = 41,                       /* ID_  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_listDecla = 45,                 /* listDecla  */
  YYSYMBOL_decla = 46,                     /* decla  */
  YYSYMBOL_declaVar = 47,                  /* declaVar  */
  YYSYMBOL_tipoSimp = 48,                  /* tipoSimp  */
  YYSYMBOL_listCamp = 49,                  /* listCamp  */
  YYSYMBOL_declaFunc = 50,                 /* declaFunc  */
  YYSYMBOL_51_2 = 51,                      /* @2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_paramForm = 53,                 /* paramForm  */
  YYSYMBOL_listParamForm = 54,             /* listParamForm  */
  YYSYMBOL_declaVarLocal = 55,             /* declaVarLocal  */
  YYSYMBOL_listInst = 56,                  /* listInst  */
  YYSYMBOL_inst = 57,                      /* inst  */
  YYSYMBOL_instExpre = 58,                 /* instExpre  */
  YYSYMBOL_instEntSal = 59,                /* instEntSal  */
  YYSYMBOL_instSelec = 60,                 /* instSelec  */
  YYSYMBOL_instIter = 61,                  /* instIter  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_expre = 63,                     /* expre  */
  YYSYMBOL_expreLogic = 64,                /* expreLogic  */
  YYSYMBOL_expreIgual = 65,                /* expreIgual  */
  YYSYMBOL_expreRel = 66,                  /* expreRel  */
  YYSYMBOL_expreAd = 67,                   /* expreAd  */
  YYSYMBOL_expreMul = 68,                  /* expreMul  */
  YYSYMBOL_expreUna = 69,                  /* expreUna  */
  YYSYMBOL_expreSufi = 70,                 /* expreSufi  */
  YYSYMBOL_const = 71,                     /* const  */
  YYSYMBOL_paramAct = 72,                  /* paramAct  */
  YYSYMBOL_listParamAct = 73,              /* listParamAct  */
  YYSYMBOL_opLogic = 74,                   /* opLogic  */
  YYSYMBOL_opIgual = 75,                   /* opIgual  */
  YYSYMBOL_opRel = 76,                     /* opRel  */
  YYSYMBOL_opAd = 77,                      /* opAd  */
  YYSYMBOL_opMul = 78,                     /* opMul  */
  YYSYMBOL_opUna = 79,                     /* opUna  */
  YYSYMBOL_opIncre = 80                    /* opIncre  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    30,    30,    30,    41,    42,    46,    47,    51,    58,
      71,    81,    82,    86,    96,   104,   111,   103,   140,   144,
     151,   159,   169,   170,   174,   175,   178,   179,   180,   181,
     182,   186,   187,   190,   199,   207,   214,   214,   222,   223,
     238,   258,   274,   275,   288,   289,   302,   303,   318,   319,
     334,   335,   350,   351,   352,   365,   366,   367,   377,   389,
     407,   420,   437,   438,   439,   442,   443,   448,   451,   456,
     457,   460,   461,   464,   465,   466,   467,   470,   471,   474,
     475,   478,   479,   480,   483,   484
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
  "\"end of file\"", "error", "\"invalid token\"", "OPSUMA_", "OPRESTA_",
  "OPMULT_", "OPDIV_", "OPAND_", "OPDECREASE_", "OPIGUAL_", "OPINCREASE_",
  "OPNOT_", "OPOR_", "COMPDIF_", "COMPIGUAL_", "COMPMAYOR_",
  "COMPMAYORIG_", "COMPMENOR_", "COMPMENORIG_", "OPENCORCH_", "OPENLLAVE_",
  "OPENPAR_", "CLOSECORCH_", "CLOSELLAVE_", "CLOSEPAR_", "SEMICOLON_",
  "COMA_", "PUNTO_", "FOR_", "IF_", "ELSE_", "WHILE_", "STRUCT_", "READ_",
  "RETURN_", "PRINT_", "TRUE_", "FALSE_", "BOOL_", "CTE_", "INT_", "ID_",
  "$accept", "programa", "$@1", "listDecla", "decla", "declaVar",
  "tipoSimp", "listCamp", "declaFunc", "@2", "$@3", "paramForm",
  "listParamForm", "declaVarLocal", "listInst", "inst", "instExpre",
  "instEntSal", "instSelec", "instIter", "$@4", "expre", "expreLogic",
  "expreIgual", "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi",
  "const", "paramAct", "listParamAct", "opLogic", "opIgual", "opRel",
  "opAd", "opMul", "opUna", "opIncre", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,    26,    18,  -129,   -10,  -129,  -129,    18,  -129,  -129,
       2,  -129,   -29,  -129,   -13,    16,   -21,    21,  -129,    40,
      39,    25,    31,    52,   -29,  -129,    54,    55,    57,    44,
      38,  -129,  -129,  -129,  -129,    61,  -129,   -29,    77,  -129,
    -129,    18,  -129,    58,    34,   -13,  -129,  -129,  -129,  -129,
    -129,  -129,    10,  -129,    79,    80,    82,    10,    84,  -129,
    -129,  -129,   109,  -129,  -129,  -129,  -129,  -129,    86,    15,
      11,    74,    37,    47,  -129,  -129,  -129,   151,    66,    73,
      89,    10,    10,    83,    96,    10,    10,    10,    10,    85,
    -129,  -129,  -129,  -129,   151,  -129,  -129,   151,  -129,  -129,
    -129,  -129,   151,  -129,  -129,   151,  -129,  -129,   151,   119,
    -129,  -129,  -129,  -129,   101,  -129,   107,   111,   115,  -129,
     113,   116,   120,  -129,   141,    11,    74,    37,    47,  -129,
      10,   117,   112,   128,   131,  -129,   132,   154,    10,  -129,
      10,   138,  -129,   134,   112,  -129,  -129,    10,  -129,  -129,
    -129,   112,  -129,  -129,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    12,    11,     3,     4,     6,
       0,     7,     0,     5,    15,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    18,    14,     0,     0,     0,     0,
       0,    19,    10,    13,     9,    20,    16,     0,     0,    21,
      22,    24,    23,     0,     0,     0,    81,    82,    85,    84,
      83,    24,     0,    32,     0,     0,     0,     0,     0,    63,
      64,    62,    57,    25,    27,    28,    29,    30,     0,    38,
      42,    44,    46,    48,    50,    52,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
      58,    31,    69,    70,     0,    72,    71,     0,    75,    76,
      73,    74,     0,    77,    78,     0,    79,    80,     0,    57,
      53,    54,    26,    56,     0,    36,     0,     0,     0,    39,
       0,    67,     0,    66,    59,    43,    45,    47,    49,    51,
       0,     0,     0,     0,     0,    17,     0,    60,     0,    61,
       0,     0,    59,     0,     0,    33,    34,     0,    68,    41,
      60,     0,    37,    40,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,   158,   125,    -9,  -129,  -129,  -129,
    -129,  -129,   130,  -129,   118,  -128,  -129,  -129,  -129,  -129,
    -129,   -52,  -129,    76,    71,    69,    68,   -69,  -129,  -129,
    -129,    36,  -129,  -129,  -129,  -129,  -129,  -129,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    16,    11,    19,
      38,    30,    31,    41,    44,    63,    64,    65,    66,    67,
     133,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     122,   123,    94,    97,   102,   105,   108,    77,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      80,    90,    21,    15,   143,    84,    17,    22,   110,     5,
      12,     6,    18,    46,    47,    29,   152,     5,    48,     6,
      49,    50,    92,   154,    95,    96,     3,    93,    29,   114,
     115,    52,    43,   118,   119,   120,   121,    46,    47,   129,
     103,   104,    48,    14,    49,    50,    59,    60,    90,    61,
       4,    62,   106,   107,    51,    52,     5,    20,     6,    53,
      23,    24,    36,    54,    25,    55,    26,    56,    57,    58,
      59,    60,    27,    61,    28,    62,    46,    47,   141,    32,
      33,    48,    34,    49,    50,    35,   121,    37,   149,    98,
      99,   100,   101,    51,    52,   153,   112,    40,    53,    45,
      81,    82,    54,    83,    55,    85,    56,   111,    58,    59,
      60,    91,    61,   113,    62,    46,    47,    48,    86,    49,
      48,   117,    49,    50,   116,   132,   124,    48,    87,    49,
      88,   134,    51,    52,   135,   137,    89,    53,   130,   136,
      88,    54,   138,    55,   139,    56,   131,    58,    59,    60,
     140,    61,   144,    62,    46,    47,   145,   146,   142,    48,
     150,    49,    50,   147,   151,    13,    42,    39,   126,    79,
     125,   127,    52,   128,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,     0,
      61,     0,   109
};

static const yytype_int16 yycheck[] =
{
      52,    62,    23,    12,   132,    57,    19,    16,    77,    38,
      20,    40,    25,     3,     4,    24,   144,    38,     8,    40,
      10,    11,     7,   151,    13,    14,     0,    12,    37,    81,
      82,    21,    41,    85,    86,    87,    88,     3,     4,   108,
       3,     4,     8,    41,    10,    11,    36,    37,   109,    39,
      32,    41,     5,     6,    20,    21,    38,    41,    40,    25,
      39,    21,    24,    29,    25,    31,    41,    33,    34,    35,
      36,    37,    41,    39,    22,    41,     3,     4,   130,    25,
      25,     8,    25,    10,    11,    41,   138,    26,   140,    15,
      16,    17,    18,    20,    21,   147,    23,    20,    25,    41,
      21,    21,    29,    21,    31,    21,    33,    41,    35,    36,
      37,    25,    39,    24,    41,     3,     4,     8,     9,    10,
       8,    25,    10,    11,    41,    24,    41,     8,    19,    10,
      21,    24,    20,    21,    23,    22,    27,    25,    19,    24,
      21,    29,    26,    31,    24,    33,    27,    35,    36,    37,
       9,    39,    24,    41,     3,     4,    25,    25,    41,     8,
      22,    10,    11,     9,    30,     7,    41,    37,    97,    51,
      94,   102,    21,   105,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,    32,    38,    40,    45,    46,    47,
      48,    50,    20,    46,    41,    48,    49,    19,    25,    51,
      41,    23,    48,    39,    21,    25,    41,    41,    22,    48,
      53,    54,    25,    25,    25,    41,    24,    26,    52,    54,
      20,    55,    47,    48,    56,    41,     3,     4,     8,    10,
      11,    20,    21,    25,    29,    31,    33,    34,    35,    36,
      37,    39,    41,    57,    58,    59,    60,    61,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    79,    80,    56,
      63,    21,    21,    21,    63,    21,     9,    19,    21,    27,
      80,    25,     7,    12,    74,    13,    14,    75,    15,    16,
      17,    18,    76,     3,     4,    77,     5,     6,    78,    41,
      69,    41,    23,    24,    63,    63,    41,    25,    63,    63,
      63,    63,    72,    73,    41,    65,    66,    67,    68,    69,
      19,    27,    24,    62,    24,    23,    24,    22,    26,    24,
       9,    63,    41,    57,    24,    25,    25,     9,    73,    63,
      22,    30,    57,    63,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    51,    52,    50,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    62,    61,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       6,     1,     1,     4,     3,     0,     0,    14,     0,     1,
       2,     4,     0,     2,     0,     2,     3,     1,     1,     1,
       1,     2,     1,     5,     5,     7,     0,     6,     1,     3,
       6,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     2,     1,     3,     1,     2,     3,
       4,     4,     1,     1,     1,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 30 "src/asin.y"
         { dvar = 0; niv = 0; cargaContexto(niv); }
#line 1260 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 31 "src/asin.y"
       {
              if((yyvsp[0].cent) >= 0){
                     yyerror("No hay una función main");
              } else if ((yyvsp[0].cent) < -1) {
                     yyerror("Hay más de una función main");
              }
       }
#line 1272 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 42 "src/asin.y"
                         {(yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1278 "asin.c"
    break;

  case 6: /* decla: declaVar  */
#line 46 "src/asin.y"
                  {(yyval.cent) = 0;}
#line 1284 "asin.c"
    break;

  case 7: /* decla: declaFunc  */
#line 47 "src/asin.y"
                   {(yyval.cent) = (yyvsp[0].cent);}
#line 1290 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ SEMICOLON_  */
#line 51 "src/asin.y"
                                 {
		if(!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += TALLA_TIPO_SIMPLE;
		}
       }
#line 1302 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ OPENCORCH_ CTE_ CLOSECORCH_ SEMICOLON_  */
#line 58 "src/asin.y"
                                                             {
		int numelem = (yyvsp[-2].cent);
		if((yyvsp[-2].cent)<=0) {
                	yyerror("Talla inapropiada del array");
			numelem = 0;
		}
		int refe = insTdA((yyvsp[-5].cent), numelem);
		if ( ! insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe) ) {
                	yyerror ("Identificador repetido");
		} else {
			dvar += numelem * TALLA_TIPO_SIMPLE;
		}
       }
#line 1320 "asin.c"
    break;

  case 10: /* declaVar: STRUCT_ OPENLLAVE_ listCamp CLOSELLAVE_ ID_ SEMICOLON_  */
#line 71 "src/asin.y"
                                                                {
		if(!insTdS((yyvsp[-1].ident), VARIABLE, T_RECORD, niv, dvar, (yyvsp[-3].dosv).ref1)) {
			yyerror("Identificador repetido");
		} else {
			dvar += (yyvsp[-3].dosv).ref2;
		}
       }
#line 1332 "asin.c"
    break;

  case 11: /* tipoSimp: INT_  */
#line 81 "src/asin.y"
              { (yyval.cent) = T_ENTERO; }
#line 1338 "asin.c"
    break;

  case 12: /* tipoSimp: BOOL_  */
#line 82 "src/asin.y"
               { (yyval.cent) = T_LOGICO; }
#line 1344 "asin.c"
    break;

  case 13: /* listCamp: listCamp tipoSimp ID_ SEMICOLON_  */
#line 86 "src/asin.y"
                                          {
        (yyval.dosv).ref1 = insTdR((yyvsp[-3].dosv).ref1, (yyvsp[-1].ident), (yyvsp[-2].cent), (yyval.dosv).ref2);
        (yyval.dosv).ref2 = (yyvsp[-3].dosv).ref2;
		if((yyval.dosv).ref1 == -1) {
            (yyval.dosv).ref1 = (yyvsp[-3].dosv).ref1;
			yyerror("Identificador repetido");
		} else {
              (yyval.dosv).ref2 = (yyvsp[-3].dosv).ref2 + TALLA_TIPO_SIMPLE;
		}
	}
#line 1359 "asin.c"
    break;

  case 14: /* listCamp: tipoSimp ID_ SEMICOLON_  */
#line 96 "src/asin.y"
                                 {
		(yyval.dosv).ref1 = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0);
		(yyval.dosv).ref2 = TALLA_TIPO_SIMPLE;
       	}
#line 1368 "asin.c"
    break;

  case 15: /* @2: %empty  */
#line 104 "src/asin.y"
         {
              niv++;
              cargaContexto(niv);
              (yyval.cent) = dvar;
              dvar = 0;
         }
#line 1379 "asin.c"
    break;

  case 16: /* $@3: %empty  */
#line 111 "src/asin.y"
         {
              if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv-1, -1, (yyvsp[-1].dosv).ref1)){
                     yyerror("Identificador repetido");
              }
         }
#line 1389 "asin.c"
    break;

  case 17: /* declaFunc: tipoSimp ID_ @2 OPENPAR_ paramForm CLOSEPAR_ $@3 OPENLLAVE_ declaVarLocal listInst RETURN_ expre SEMICOLON_ CLOSELLAVE_  */
#line 117 "src/asin.y"
         {
              if(verTdS) {
                      mostrarTdS();
              }
              descargaContexto(niv);
              niv--;
              dvar = (yyval.cent);

              if(strcmp((yyvsp[-12].ident), "main") == 0){
                     //printf("Main detectado");
                     (yyval.cent) = -1;
              } else {
                     //printf("Funcion que no es main");
                     (yyval.cent) = 0;
              }

              if((yyvsp[-2].tipo).t != (yyvsp[-13].cent)){
                     yyerror("Tipo de return distinto al de la función");
              }
         }
#line 1414 "asin.c"
    break;

  case 18: /* paramForm: %empty  */
#line 140 "src/asin.y"
         {
		(yyval.dosv).ref1 = insTdD(-1, T_VACIO);
		(yyval.dosv).ref2 = 0;
       }
#line 1423 "asin.c"
    break;

  case 19: /* paramForm: listParamForm  */
#line 144 "src/asin.y"
                       {
		(yyval.dosv).ref1 = (yyvsp[0].dosv).ref1;
		(yyval.dosv).ref2 = (yyvsp[0].dosv).ref2 - TALLA_SEGENLACES;
       }
#line 1432 "asin.c"
    break;

  case 20: /* listParamForm: tipoSimp ID_  */
#line 151 "src/asin.y"
                      {
		(yyval.dosv).ref1 = insTdD(-1, (yyvsp[-1].cent));
		(yyval.dosv).ref2 = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;

		if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.dosv).ref2, (yyval.dosv).ref1)){
              yyerror("Identificador repetido");
		}
	}
#line 1445 "asin.c"
    break;

  case 21: /* listParamForm: tipoSimp ID_ COMA_ listParamForm  */
#line 159 "src/asin.y"
                                          {
		(yyval.dosv).ref1 = insTdD((yyvsp[0].dosv).ref1, (yyvsp[-3].cent));
		(yyval.dosv).ref2 = (yyvsp[0].dosv).ref2 + TALLA_TIPO_SIMPLE;
		if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.dosv).ref2, (yyval.dosv).ref1)){
              yyerror("Identificador repetido");
		}
	}
#line 1457 "asin.c"
    break;

  case 33: /* instEntSal: READ_ OPENPAR_ ID_ CLOSEPAR_ SEMICOLON_  */
#line 190 "src/asin.y"
                                                 {
              SIMB sim = obtTdS((yyvsp[-2].ident));
              if(sim.t == T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if(sim.t != T_ENTERO){
                     yyerror("El objeto a leer no es de tipo entero.");
              }
       }
#line 1471 "asin.c"
    break;

  case 34: /* instEntSal: PRINT_ OPENPAR_ expre CLOSEPAR_ SEMICOLON_  */
#line 199 "src/asin.y"
                                                   {

              if( (yyvsp[-2].tipo).t != T_ERROR && (yyvsp[-2].tipo).t != T_ENTERO){
                      yyerror("El objeto no es de tipo entero.");
              }
       }
#line 1482 "asin.c"
    break;

  case 35: /* instSelec: IF_ OPENPAR_ expre CLOSEPAR_ inst ELSE_ inst  */
#line 207 "src/asin.y"
                                                      {
              if((yyvsp[-4].tipo).t!=T_ERROR && (yyvsp[-4].tipo).t!=T_LOGICO){
                     yyerror("La expresión debe ser de tipo lógico.");
              }
       }
#line 1492 "asin.c"
    break;

  case 36: /* $@4: %empty  */
#line 214 "src/asin.y"
                               {
                     if((yyvsp[0].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_LOGICO){
                            yyerror("La expresión debe ser de tipo lógico.");
                     }
              }
#line 1502 "asin.c"
    break;

  case 38: /* expre: expreLogic  */
#line 222 "src/asin.y"
                    {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1508 "asin.c"
    break;

  case 39: /* expre: ID_ OPIGUAL_ expre  */
#line 223 "src/asin.y"
                            {
              SIMB sim = obtTdS((yyvsp[-2].ident));
              (yyval.tipo).t = T_ERROR;
              if(sim.t == T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if((yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[0].tipo).t!=sim.t){
                            yyerror("Incompatibilidad de tipos.");
                     }
                     else {
                            (yyval.tipo).t=sim.t;
                     }
              }
       }
#line 1528 "asin.c"
    break;

  case 40: /* expre: ID_ OPENCORCH_ expre CLOSECORCH_ OPIGUAL_ expre  */
#line 238 "src/asin.y"
                                                         {
              SIMB sim = obtTdS((yyvsp[-5].ident));
              (yyval.tipo).t = T_ERROR;
              if(sim.t==T_ERROR){
                     yyerror("Objeto no declarado.");
              }
              else if(sim.t!=T_ARRAY){
                     yyerror("La variable debe ser de tipo array.");
              } else if((yyvsp[0].tipo).t!=T_ERROR){
                     DIM dim = obtTdA(sim.ref);
                     if((yyvsp[-3].tipo).t != T_ENTERO){
                            yyerror("El índice del array debe ser un número entero.");
                     }
                     else if(dim.telem!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles.");
                     } else{
                            (yyval.tipo).t = dim.telem;
                     }
              }
       }
#line 1553 "asin.c"
    break;

  case 41: /* expre: ID_ PUNTO_ ID_ OPIGUAL_ expre  */
#line 258 "src/asin.y"
                                       {
              SIMB sim = obtTdS((yyvsp[-4].ident));
              (yyval.tipo).t = T_ERROR;
              CAMP camp = obtTdR(sim.ref,(yyvsp[-2].ident));
              if(sim.t==T_ERROR || camp.t==T_ERROR){
                     yyerror("Objeto no declarado.");
              } else if((yyvsp[0].tipo).t!=T_ERROR){
                     if(camp.t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles.");
                     } else{
                            (yyval.tipo).t = (yyvsp[0].tipo).t;
                     }
              }
       }
#line 1572 "asin.c"
    break;

  case 42: /* expreLogic: expreIgual  */
#line 274 "src/asin.y"
                    {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1578 "asin.c"
    break;

  case 43: /* expreLogic: expreLogic opLogic expreIgual  */
#line 275 "src/asin.y"
                                       {
              (yyval.tipo).t = T_ERROR;
              if((yyvsp[-2].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[-2].tipo).t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles");
                     }
                     else{
                            (yyval.tipo).t = T_LOGICO;
                     }
              }
       }
#line 1594 "asin.c"
    break;

  case 44: /* expreIgual: expreRel  */
#line 288 "src/asin.y"
                  {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1600 "asin.c"
    break;

  case 45: /* expreIgual: expreIgual opIgual expreRel  */
#line 289 "src/asin.y"
                                     {
              (yyval.tipo).t = T_ERROR;
              if((yyvsp[-2].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[-2].tipo).t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles");
                     }
                     else{
                            (yyval.tipo).t = T_LOGICO;
                     }
              }
       }
#line 1616 "asin.c"
    break;

  case 46: /* expreRel: expreAd  */
#line 302 "src/asin.y"
                 {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1622 "asin.c"
    break;

  case 47: /* expreRel: expreRel opRel expreAd  */
#line 303 "src/asin.y"
                                {
              (yyval.tipo).t = T_ERROR;
              if((yyvsp[-2].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[-2].tipo).t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles");
                     } else if((yyvsp[-2].tipo).t!=T_ENTERO){
                            yyerror("Las expresiones deben ser de tipo entero");
                     }
                     else{
                            (yyval.tipo).t = T_LOGICO;
                     }
              }
       }
#line 1640 "asin.c"
    break;

  case 48: /* expreAd: expreMul  */
#line 318 "src/asin.y"
                  {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1646 "asin.c"
    break;

  case 49: /* expreAd: expreAd opAd expreMul  */
#line 319 "src/asin.y"
                               {
              (yyval.tipo).t = T_ERROR;
              if((yyvsp[-2].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[-2].tipo).t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles");
                     } else if((yyvsp[-2].tipo).t!=T_ENTERO){
                            yyerror("Las expresiones deben ser de tipo entero");
                     }
                     else{
                            (yyval.tipo).t = (yyvsp[-2].tipo).t;
                     }
              }
       }
#line 1664 "asin.c"
    break;

  case 50: /* expreMul: expreUna  */
#line 334 "src/asin.y"
                  {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1670 "asin.c"
    break;

  case 51: /* expreMul: expreMul opMul expreUna  */
#line 335 "src/asin.y"
                                 {
              (yyval.tipo).t = T_ERROR;
              if((yyvsp[-2].tipo).t!=T_ERROR && (yyvsp[0].tipo).t!=T_ERROR){
                     if((yyvsp[-2].tipo).t!=(yyvsp[0].tipo).t){
                            yyerror("Tipos incompatibles.");
                     } else if((yyvsp[-2].tipo).t!=T_ENTERO){
                            yyerror("Las expresiones deben ser de tipo entero");
                     }
                     else{
                            (yyval.tipo).t = (yyvsp[-2].tipo).t;
                     }
              }
       }
#line 1688 "asin.c"
    break;

  case 52: /* expreUna: expreSufi  */
#line 350 "src/asin.y"
                   {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1694 "asin.c"
    break;

  case 53: /* expreUna: opUna expreUna  */
#line 351 "src/asin.y"
                        {(yyval.tipo).t=(yyvsp[0].tipo).t;}
#line 1700 "asin.c"
    break;

  case 54: /* expreUna: opIncre ID_  */
#line 352 "src/asin.y"
                     {
              SIMB sim = obtTdS((yyvsp[0].ident));
              (yyval.tipo).t = T_ERROR;
              if(sim.t==T_ERROR){
                     yyerror("Objeto no declarado");
              } else if (sim.t != T_ENTERO){
                     yyerror("Error en expresión unaria. La variable no es entera.");
              }else{
                     (yyval.tipo).t = sim.t;
              }
       }
#line 1716 "asin.c"
    break;

  case 55: /* expreSufi: const  */
#line 365 "src/asin.y"
                                  {(yyval.tipo).t = (yyvsp[0].tipo).t;}
#line 1722 "asin.c"
    break;

  case 56: /* expreSufi: OPENPAR_ expre CLOSEPAR_  */
#line 366 "src/asin.y"
                                  {(yyval.tipo).t = (yyvsp[-1].tipo).t;}
#line 1728 "asin.c"
    break;

  case 57: /* expreSufi: ID_  */
#line 368 "src/asin.y"
              {
              (yyval.tipo).t = T_ERROR;
              SIMB sim = obtTdS((yyvsp[0].ident));
              if (sim.t == T_ERROR) {
                     yyerror("No existe ninguna variable con ese identificador.");
              } else {
                     (yyval.tipo).t = sim.t;
			 }
		}
#line 1742 "asin.c"
    break;

  case 58: /* expreSufi: ID_ opIncre  */
#line 378 "src/asin.y"
              {
			(yyval.tipo).t = T_ERROR;
			SIMB sim = obtTdS((yyvsp[-1].ident));
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.t == T_ENTERO) {
				(yyval.tipo).t = sim.t;
			} else {
				yyerror("Incompatibilidad de tipos, solo se puede aplicar el operador \"++\" o \"--\" a una expresion entera.");
			}
		}
#line 1758 "asin.c"
    break;

  case 59: /* expreSufi: ID_ PUNTO_ ID_  */
#line 390 "src/asin.y"
                {
			(yyval.tipo).t = T_ERROR;
			SIMB sim = obtTdS((yyvsp[-2].ident));
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (sim.t != T_RECORD) {
				yyerror("El identificador debe ser de tipo struct.");
			} else{
              CAMP cam = obtTdR(sim.ref, (yyvsp[0].ident));
              if (cam.t == T_ERROR) {
                     yyerror("No existe ninguna variable con ese identificador en ese campo.");
              } else {
                     (yyval.tipo).t = cam.t;
              }
			}

		}
#line 1780 "asin.c"
    break;

  case 60: /* expreSufi: ID_ OPENCORCH_ expre CLOSECORCH_  */
#line 408 "src/asin.y"
                {
			(yyval.tipo).t = T_ERROR;
			SIMB sim = obtTdS((yyvsp[-3].ident));
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if ((yyvsp[-1].tipo).t != T_ENTERO) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else {
				DIM dim = obtTdA(sim.ref);
				(yyval.tipo).t = dim.telem;
			}
		}
#line 1797 "asin.c"
    break;

  case 61: /* expreSufi: ID_ OPENPAR_ paramAct CLOSEPAR_  */
#line 421 "src/asin.y"
                {
			(yyval.tipo).t = T_ERROR;
			SIMB sim = obtTdS((yyvsp[-3].ident));
			INF inf = obtTdD(sim.ref);
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (inf.tipo == T_ERROR) {
				yyerror("No existe ninguna funcion con ese identificador.");
			} else if (!cmpDom(sim.ref, (yyvsp[-1].cent))) {
                yyerror("Parámetros de la función incorrectos");
			} else {
				(yyval.tipo).t = inf.tipo;
			}
		}
#line 1816 "asin.c"
    break;

  case 62: /* const: CTE_  */
#line 437 "src/asin.y"
                            {(yyval.tipo).t = T_ENTERO;}
#line 1822 "asin.c"
    break;

  case 63: /* const: TRUE_  */
#line 438 "src/asin.y"
                            {(yyval.tipo).t = T_LOGICO;}
#line 1828 "asin.c"
    break;

  case 64: /* const: FALSE_  */
#line 439 "src/asin.y"
                            {(yyval.tipo).t = T_LOGICO;}
#line 1834 "asin.c"
    break;

  case 65: /* paramAct: %empty  */
#line 442 "src/asin.y"
         {(yyval.cent) = insTdD(-1,T_VACIO);}
#line 1840 "asin.c"
    break;

  case 66: /* paramAct: listParamAct  */
#line 443 "src/asin.y"
                      {
              (yyval.cent) = (yyvsp[0].cent);
       }
#line 1848 "asin.c"
    break;

  case 67: /* listParamAct: expre  */
#line 448 "src/asin.y"
               {
              (yyval.cent)=insTdD(-1, (yyvsp[0].tipo).t);
       }
#line 1856 "asin.c"
    break;

  case 68: /* listParamAct: expre COMA_ listParamAct  */
#line 451 "src/asin.y"
                                  {
              (yyval.cent)=insTdD((yyvsp[0].cent), (yyvsp[-2].tipo).t);
       }
#line 1864 "asin.c"
    break;

  case 69: /* opLogic: OPAND_  */
#line 456 "src/asin.y"
                             {(yyval.cent) = OP_AND;}
#line 1870 "asin.c"
    break;

  case 70: /* opLogic: OPOR_  */
#line 457 "src/asin.y"
                             {(yyval.cent) = OP_OR;}
#line 1876 "asin.c"
    break;

  case 71: /* opIgual: COMPIGUAL_  */
#line 460 "src/asin.y"
                             {(yyval.cent) = OP_IGUAL;}
#line 1882 "asin.c"
    break;

  case 72: /* opIgual: COMPDIF_  */
#line 461 "src/asin.y"
                             {(yyval.cent) = OP_NOTIGUAL;}
#line 1888 "asin.c"
    break;

  case 73: /* opRel: COMPMENOR_  */
#line 464 "src/asin.y"
                             {(yyval.cent) = OP_MENOR;}
#line 1894 "asin.c"
    break;

  case 74: /* opRel: COMPMENORIG_  */
#line 465 "src/asin.y"
                             {(yyval.cent) = OP_MENORIG;}
#line 1900 "asin.c"
    break;

  case 75: /* opRel: COMPMAYOR_  */
#line 466 "src/asin.y"
                             {(yyval.cent) = OP_MAYOR;}
#line 1906 "asin.c"
    break;

  case 76: /* opRel: COMPMAYORIG_  */
#line 467 "src/asin.y"
                             {(yyval.cent) = OP_MAYORIG;}
#line 1912 "asin.c"
    break;

  case 77: /* opAd: OPSUMA_  */
#line 470 "src/asin.y"
                             {(yyval.cent) = OP_SUMA;}
#line 1918 "asin.c"
    break;

  case 78: /* opAd: OPRESTA_  */
#line 471 "src/asin.y"
                             {(yyval.cent) = OP_RESTA;}
#line 1924 "asin.c"
    break;

  case 79: /* opMul: OPMULT_  */
#line 474 "src/asin.y"
                             {(yyval.cent) = OP_MULT;}
#line 1930 "asin.c"
    break;

  case 80: /* opMul: OPDIV_  */
#line 475 "src/asin.y"
                             {(yyval.cent) = OP_DIV;}
#line 1936 "asin.c"
    break;

  case 81: /* opUna: OPSUMA_  */
#line 478 "src/asin.y"
                             {(yyval.cent) = OP_SUMA;}
#line 1942 "asin.c"
    break;

  case 82: /* opUna: OPRESTA_  */
#line 479 "src/asin.y"
                             {(yyval.cent) = OP_RESTA;}
#line 1948 "asin.c"
    break;

  case 83: /* opUna: OPNOT_  */
#line 480 "src/asin.y"
                             {(yyval.cent) = OP_NOT;}
#line 1954 "asin.c"
    break;

  case 84: /* opIncre: OPINCREASE_  */
#line 483 "src/asin.y"
                             {(yyval.cent) = OP_INCR;}
#line 1960 "asin.c"
    break;

  case 85: /* opIncre: OPDECREASE_  */
#line 484 "src/asin.y"
                             {(yyval.cent) = OP_DECR;}
#line 1966 "asin.c"
    break;


#line 1970 "asin.c"

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

#line 486 "src/asin.y"


/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/frontend/syntactic-analysis/bison-grammar.y"


#include "bison-actions.h"


#line 76 "../src/frontend/syntactic-analysis/bison-parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_FRONTEND_SYNTACTIC_ANALYSIS_BISON_PARSER_H_INCLUDED
# define YY_YY_SRC_FRONTEND_SYNTACTIC_ANALYSIS_BISON_PARSER_H_INCLUDED
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
    BOX = 258,
    ENDBOX = 259,
    START = 260,
    END = 261,
    TITLE = 262,
    TITLE_SIZE = 263,
    COLOR = 264,
    POSITION = 265,
    DEF_DELIMITER = 266,
    COMMA = 267,
    TABLE = 268,
    ENDTABLE = 269,
    LINK = 270,
    RANDOM = 271,
    IMAGE = 272,
    HYPERLINK = 273,
    ID = 274,
    IDREF = 275,
    SOURCE = 276,
    BOLD = 277,
    ITALIC = 278,
    UNDERLINED = 279,
    NUMBER = 280,
    ROW = 281,
    ENDROW = 282,
    DATA = 283,
    TIMES = 284,
    TEXT = 285,
    CONTENT = 286,
    ADD = 287,
    SUB = 288,
    MUL = 289,
    DIV = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_FRONTEND_SYNTACTIC_ANALYSIS_BISON_PARSER_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  274
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  414

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    48,    49,    50,    51,    52,    53,    54,
      55,    58,    59,    63,    64,    65,    68,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   101,   102,   103,   104,   105,
     106,   107,   108,   111,   112,   115,   116,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   129,   130,   131,   132,
     133,   134,   135,   136,   138,   139,   140,   141,   142,   143,
     144,   145,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   160,   161,   162,   163,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   175,   176,   177,
     178,   179,   180,   181,   183,   184,   185,   189,   190,   191,
     192,   193,   196,   197,   198,   199,   202,   203,   204,   205,
     206,   207,   208,   209,   211,   212,   213,   214,   215,   216,
     217,   218,   220,   221,   222,   223,   224,   225,   226,   227,
     229,   230,   231,   232,   233,   234,   235,   236,   238,   239,
     240,   241,   242,   243,   244,   245,   248,   249,   250,   251,
     252,   253,   254,   255,   257,   258,   259,   260,   261,   262,
     263,   264,   266,   267,   268,   269,   270,   271,   272,   273,
     276,   277,   278,   279,   280,   281,   282,   283,   285,   286,
     287,   288,   289,   290,   291,   292,   294,   295,   296,   297,
     298,   299,   300,   301,   303,   304,   305,   306,   307,   308,
     309,   310,   312,   313,   314,   315,   316,   317,   318,   319,
     321,   322,   323,   324,   325,   326,   327,   328,   330,   331,
     332,   333,   334,   335,   336,   337,   340,   343,   344,   347,
     350,   351,   354,   355,   358,   359,   360,   361,   362,   364,
     365,   366,   367,   369,   370,   371,   372,   374,   375,   376,
     377,   378,   379,   380,   381
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOX", "ENDBOX", "START", "END", "TITLE",
  "TITLE_SIZE", "COLOR", "POSITION", "DEF_DELIMITER", "COMMA", "TABLE",
  "ENDTABLE", "LINK", "RANDOM", "IMAGE", "HYPERLINK", "ID", "IDREF",
  "SOURCE", "BOLD", "ITALIC", "UNDERLINED", "NUMBER", "ROW", "ENDROW",
  "DATA", "TIMES", "TEXT", "CONTENT", "ADD", "SUB", "MUL", "DIV",
  "$accept", "program", "web_expression", "img_expression", "img_attrs",
  "link_expression", "link_attrs", "div_expression", "div_attrs",
  "text_expression", "text_attrs", "simple_expression", "title_expression",
  "title_attrs", "table_expression", "table_resolve", "row_resolve",
  "row_expression", "row_data", "data_attrs", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    40,    29,    -1,   182,     2,    25,   -20,    18,    15,
     120,    10,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    75,
      34,    39,    51,    59,    67,    -9,    69,    41,   -20,    44,
      84,   -20,    68,    98,   160,   165,   111,   112,   122,   129,
     -20,   -20,   -20,   115,   -20,    40,   -20,   -20,    55,   -20,
      57,   -20,   -20,    75,   126,   136,   175,   -20,   -20,   109,
      -7,   118,   -20,   -20,   123,   169,   148,   178,   -20,   285,
     272,   273,   -20,   268,   151,   181,   208,   270,   -20,    90,
     -20,   292,    93,    95,    73,   286,   288,   290,   291,   293,
     -20,   294,   295,   296,   297,   -20,   298,   299,   300,   -20,
     301,   302,   -20,   -20,   -20,   279,   -20,   211,   303,   -20,
     214,   304,   -20,   -20,   305,   306,   307,   308,   -20,   309,
     310,   311,   -20,   312,   313,   -20,   -20,   -20,   -20,   -20,
     110,   -20,   322,   157,   187,   217,    31,   314,   193,   220,
      65,   315,   223,    72,   316,    92,   317,   289,   319,   320,
     -20,   -20,   323,   321,   -20,   -20,   199,   226,   114,   324,
     229,   133,   325,   139,   326,   -20,   -20,   318,   331,   335,
     339,   -20,   340,   341,   342,   -20,   343,   344,   -20,   345,
     -20,   -20,   232,   346,   347,   -20,   348,   349,   -20,   350,
     -20,   -20,   351,   352,   -20,   353,   -20,   -20,   354,   -20,
     -20,   356,   289,   -20,   355,   -20,   357,   -20,   235,   358,
     359,   -20,   360,   361,   -20,   362,   -20,   -20,   363,   364,
     -20,   365,   -20,   -20,   366,   -20,   -20,   205,   238,   145,
     367,   241,   162,   368,   172,   369,   370,   184,   371,   -20,
     190,   372,   196,   373,   374,   202,   375,   376,   377,   378,
     -20,   -20,   -20,   249,   379,   -20,   251,   380,   253,   381,
     383,   255,   384,   385,   386,   390,   399,   400,   -20,   401,
     402,   -20,   403,   -20,   -20,   404,   405,   -20,   406,   -20,
     -20,   407,   -20,   -20,   -20,   396,   -20,   -20,   409,   -20,
     -20,   410,   -20,   -20,   -20,   411,   -20,   -20,   -20,   -20,
     142,    14,   -20,   408,   -20,   -20,   412,   -20,   -20,   413,
     -20,   -20,   -20,   414,   -20,   -20,   -20,   -20,   244,   257,
     415,   259,   416,   417,   261,   418,   419,   420,   -20,   421,
     422,   423,   424,   425,   337,   -20,   -20,   -20,   427,   -20,
     -20,   -20,   426,   428,   429,   436,   437,   -20,   439,   -20,
     -20,   442,   -20,   -20,   -20,   443,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,    -3,    96,   -20,   338,   -20,   -20,   -20,
     263,   432,   433,   434,   435,   448,   449,   450,   451,   452,
     -20,   453,   -20,   -20,   -20,   -20,   -20,   247,   265,   444,
     267,   445,   446,   454,   455,   -20,   459,   -20,   -20,   460,
     -20,   -20,   -20,   269,   456,   457,   458,   461,   -20,   -20,
     -20,   -20,   462,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
      57,     0,     5,     6,    10,     4,     3,     1,    53,     0,
       0,     0,   174,   206,   222,     0,   238,     0,    56,     0,
       0,    14,    13,    11,    17,    38,     0,    74,    90,   106,
     114,   115,   116,     0,     2,     7,   120,   121,     0,   117,
       0,   118,    54,     0,     0,     0,     0,   124,   122,     0,
       0,     0,     8,    15,     0,     0,    18,    21,    23,     0,
      39,    42,    44,     0,     0,     0,     0,     0,    46,     0,
      47,     0,   119,     0,     0,   150,   158,   182,   175,   180,
     181,   190,   214,   207,   212,   213,   230,   223,   228,   229,
     239,   244,   245,   125,   123,     0,    12,    24,    19,    22,
      31,    40,    43,    16,    58,    82,    75,    80,    81,    98,
      91,    96,    97,   107,   112,   113,    55,    49,    51,    45,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    28,
      30,    20,    32,    35,    37,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    52,   126,   142,   151,
     156,   157,   166,   159,   164,   165,   183,   188,   189,   176,
     177,   179,   198,   191,   196,   197,   215,   220,   221,   208,
     209,   211,   231,   236,   237,   224,   225,   227,   240,   241,
     243,     0,   246,   247,    26,    29,    33,    36,    66,    59,
      64,    65,    83,    88,    89,    76,    77,    79,    99,   104,
     105,    92,    93,    95,   108,   109,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,    27,    34,    67,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   127,   132,   133,   143,
     148,   149,   152,   153,   155,   167,   172,   173,   160,   161,
     163,   184,   185,   187,   178,   200,   201,   203,   192,   193,
     195,   216,   217,   219,   210,   232,   233,   235,   226,   242,
       0,     0,   250,    68,    69,    71,    60,    61,    63,    84,
      85,    87,    78,   100,   101,   103,    94,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,     0,   254,   255,     0,   256,   257,   258,     0,   249,
     251,    70,     0,     0,     0,   135,   140,   141,   128,   129,
     131,   144,   145,   147,   154,   168,   169,   171,   162,   186,
     194,   218,   234,     0,     0,   252,     0,    62,    86,   102,
       0,     0,     0,     0,     0,   267,     0,     0,     0,     0,
     253,   136,   137,   139,   130,   146,   170,     0,     0,     0,
       0,     0,     0,   268,   273,   274,   260,   261,   262,   264,
     265,   266,   138,     0,     0,     0,     0,   269,   270,   272,
     259,   263,     0,   271
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -20,   -20,   328,     0,   -20,     1,   -20,   -19,   -20,     3,
     -20,   -16,     4,   -20,   -20,   -20,   130,   -20,    30,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    45,    46,    33,    47,    36,    14,    21,    49,
      43,    82,    51,    27,    30,   202,   203,   301,   302,   338
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    12,    13,    50,    15,    16,    57,   375,   103,    18,
      19,    12,    13,     3,    15,    16,    44,     4,    20,   376,
     377,     5,    58,     6,   104,     1,     7,     8,     9,    17,
      34,    81,    79,    28,    83,    35,    29,    84,    31,    32,
      10,   339,   300,     3,    52,    12,    13,     4,    15,    16,
      53,     5,    60,     6,   179,   180,     7,     8,     9,    78,
       3,    80,     4,    54,     4,   132,     5,   130,     5,    61,
      10,    55,     8,     9,     8,     9,     3,   131,     3,    56,
       4,    59,     4,    63,     5,    10,     5,    10,   189,   190,
       8,     9,     8,     9,   127,   195,   196,     4,    62,   129,
       4,     5,     4,    10,     5,    10,     5,     8,     9,    64,
       8,     9,     8,     9,   165,   198,   199,     4,   378,   379,
      10,     5,    73,    10,    74,    10,    77,     8,     9,    37,
      38,   100,   101,   102,    75,    85,    86,   215,   216,    39,
      10,    76,    40,    41,    42,    87,    91,   105,    88,    89,
      90,   332,   333,   334,   106,    92,   221,   222,    93,    94,
      95,   114,   224,   225,   335,   336,   337,   167,   272,   273,
     115,   108,    65,   116,   117,   118,   168,    69,   107,   169,
     170,   171,    66,    67,    68,   278,   279,    70,    71,    72,
      22,    23,    24,    25,    96,   281,   282,    97,    98,    99,
     119,    26,   109,   120,   121,   122,   172,   285,   286,   173,
     174,   175,   182,   288,   289,   183,   184,   185,   208,   291,
     292,   209,   210,   211,   265,   295,   296,   266,   267,   268,
     123,   124,   125,   148,   149,   150,   152,   153,   154,   176,
     177,   178,   186,   187,   188,   192,   193,   194,   212,   213,
     214,   218,   219,   220,   237,   238,   239,   253,   254,   255,
     269,   270,   271,   275,   276,   277,   345,   346,   347,   393,
     394,   395,   303,   304,   306,   307,   309,   310,   313,   314,
     348,   349,   351,   352,   355,   356,   381,   382,   396,   397,
     399,   400,   407,   408,   110,   111,   128,   112,   133,   113,
     134,   126,   135,   136,   147,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   201,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   166,   151,   155,    11,
     227,   340,   250,     0,     0,     0,     0,     0,   181,   191,
     197,   200,   204,   228,   205,   207,   206,   229,   217,   223,
     226,   230,   231,   232,   233,   234,   235,   236,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   365,   380,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   251,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   280,   283,   284,   287,   290,   293,   294,   297,
     298,   299,   318,   305,   308,   311,   300,   312,   315,   316,
     317,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   342,   343,   344,     0,     0,     0,
       0,     0,   341,     0,     0,     0,   363,   364,   366,   350,
     353,   354,   357,   358,   359,   360,   361,   362,   370,   371,
     367,   372,   368,   369,   373,   374,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   403,   404,   398,   401,
     402,   405,   406,   412,     0,     0,     0,     0,     0,     0,
     409,   410,   411,     0,     0,     0,   413
};

static const yytype_int16 yycheck[] =
{
      19,     1,     1,    19,     1,     1,    15,    10,    15,    10,
      11,    11,    11,     3,    11,    11,     6,     7,    19,    22,
      23,    11,    31,    13,    31,     5,    16,    17,    18,     0,
      15,    50,    48,    31,    53,    20,    11,    53,    20,    21,
      30,    27,    28,     3,    10,    45,    45,     7,    45,    45,
      11,    11,    11,    13,    23,    24,    16,    17,    18,     4,
       3,     4,     7,    12,     7,    84,    11,    83,    11,    25,
      30,    12,    17,    18,    17,    18,     3,     4,     3,    12,
       7,    12,     7,    15,    11,    30,    11,    30,    23,    24,
      17,    18,    17,    18,     4,    23,    24,     7,    14,     4,
       7,    11,     7,    30,    11,    30,    11,    17,    18,    11,
      17,    18,    17,    18,     4,    23,    24,     7,    22,    23,
      30,    11,    11,    30,    12,    30,    11,    17,    18,     9,
      10,    22,    23,    24,    12,     9,    10,    23,    24,    19,
      30,    12,    22,    23,    24,    19,    10,    29,    22,    23,
      24,     9,    10,    11,    31,    19,    23,    24,    22,    23,
      24,    10,    23,    24,    22,    23,    24,    10,    23,    24,
      19,    23,    12,    22,    23,    24,    19,    12,     9,    22,
      23,    24,    22,    23,    24,    23,    24,    22,    23,    24,
       8,     9,    10,    11,    19,    23,    24,    22,    23,    24,
      19,    19,    24,    22,    23,    24,    19,    23,    24,    22,
      23,    24,    19,    23,    24,    22,    23,    24,    19,    23,
      24,    22,    23,    24,    19,    23,    24,    22,    23,    24,
      22,    23,    24,    22,    23,    24,    22,    23,    24,    22,
      23,    24,    22,    23,    24,    22,    23,    24,    22,    23,
      24,    22,    23,    24,    22,    23,    24,    22,    23,    24,
      22,    23,    24,    22,    23,    24,    22,    23,    24,    22,
      23,    24,    23,    24,    23,    24,    23,    24,    23,    24,
      23,    24,    23,    24,    23,    24,    23,    24,    23,    24,
      23,    24,    23,    24,     9,    23,     4,    24,    12,    31,
      12,    31,    12,    12,    25,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    26,    -1,    12,    12,    12,
      12,    12,    12,    12,    12,    12,     4,    24,    24,     1,
      12,   301,   202,    -1,    -1,    -1,    -1,    -1,    24,    24,
      24,    24,    23,    12,    24,    24,    23,    12,    24,    24,
      24,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    11,    31,    31,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    24,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    12,    24,    24,    24,    28,    24,    24,    24,
      24,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      24,    12,    12,    12,    12,    12,    12,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    12,    12,    11,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    12,    12,
      24,    12,    24,    24,    12,    12,    24,    24,    24,    24,
      12,    12,    12,    12,    12,    12,    12,    12,    24,    24,
      24,    12,    12,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    24,    24,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    37,     3,     7,    11,    13,    16,    17,    18,
      30,    38,    39,    41,    43,    45,    48,     0,    10,    11,
      19,    44,     8,     9,    10,    11,    19,    49,    31,    11,
      50,    20,    21,    40,    15,    20,    42,     9,    10,    19,
      22,    23,    24,    46,     6,    38,    39,    41,    43,    45,
      47,    48,    10,    11,    12,    12,    12,    15,    31,    12,
      11,    25,    14,    15,    11,    12,    22,    23,    24,    12,
      22,    23,    24,    11,    12,    12,    12,    11,     4,    47,
       4,    43,    47,    43,    47,     9,    10,    19,    22,    23,
      24,    10,    19,    22,    23,    24,    19,    22,    23,    24,
      22,    23,    24,    15,    31,    29,    31,     9,    23,    24,
       9,    23,    24,    31,    10,    19,    22,    23,    24,    19,
      22,    23,    24,    22,    23,    24,    31,     4,     4,     4,
      47,     4,    43,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    25,    22,    23,
      24,    24,    22,    23,    24,    24,    12,    12,    12,    12,
      12,    12,    12,    12,    12,     4,     4,    10,    19,    22,
      23,    24,    19,    22,    23,    24,    22,    23,    24,    23,
      24,    24,    19,    22,    23,    24,    22,    23,    24,    23,
      24,    24,    22,    23,    24,    23,    24,    24,    23,    24,
      24,    26,    51,    52,    23,    24,    23,    24,    19,    22,
      23,    24,    22,    23,    24,    23,    24,    24,    22,    23,
      24,    23,    24,    24,    23,    24,    24,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    22,    23,    24,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    11,
      52,    24,    24,    22,    23,    24,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    19,    22,    23,    24,    22,
      23,    24,    23,    24,    24,    22,    23,    24,    23,    24,
      24,    23,    24,    24,    24,    23,    24,    24,    23,    24,
      24,    23,    24,    24,    24,    23,    24,    24,    24,    24,
      28,    53,    54,    23,    24,    24,    23,    24,    24,    23,
      24,    24,    24,    23,    24,    24,    24,    24,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    24,    12,
      12,    12,     9,    10,    11,    22,    23,    24,    55,    27,
      54,    24,    12,    12,    12,    22,    23,    24,    23,    24,
      24,    23,    24,    24,    24,    23,    24,    24,    24,    24,
      24,    24,    24,    12,    12,    31,    11,    24,    24,    24,
      12,    12,    12,    12,    12,    10,    22,    23,    22,    23,
      31,    23,    24,    24,    24,    24,    24,    12,    12,    12,
      12,    12,    12,    22,    23,    24,    23,    24,    24,    23,
      24,    24,    24,    12,    12,    12,    12,    23,    24,    24,
      24,    24,    12,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    40,    40,    40,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     1,     2,     3,     1,
       1,     2,     4,     1,     1,     2,     4,     1,     2,     3,
       4,     2,     3,     2,     3,     4,     5,     6,     4,     5,
       4,     3,     4,     5,     6,     4,     5,     4,     1,     2,
       3,     4,     2,     3,     2,     5,     4,     4,     5,     5,
       6,     5,     6,     1,     2,     4,     2,     0,     3,     5,
       7,     7,     9,     7,     5,     5,     5,     6,     7,     7,
       8,     7,     6,     6,     1,     3,     5,     5,     7,     5,
       3,     3,     3,     5,     7,     7,     9,     7,     5,     5,
       1,     3,     5,     5,     7,     5,     3,     3,     3,     5,
       7,     7,     9,     7,     5,     5,     1,     3,     5,     5,
       7,     5,     3,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     4,     3,     4,     5,     7,     9,     9,
      11,     9,     7,     7,     7,     9,    11,    11,    13,    11,
       9,     9,     5,     7,     9,     9,    11,     9,     7,     7,
       3,     5,     7,     7,     9,     7,     5,     5,     3,     5,
       7,     7,     9,     7,     5,     5,     5,     7,     9,     9,
      11,     9,     7,     7,     1,     3,     5,     5,     7,     5,
       3,     3,     3,     5,     7,     7,     9,     7,     5,     5,
       3,     5,     7,     7,     9,     7,     5,     5,     5,     6,
       7,     7,     8,     7,     6,     6,     1,     3,     5,     5,
       7,     5,     3,     3,     3,     5,     7,     7,     9,     7,
       5,     5,     1,     3,     5,     5,     7,     5,     3,     3,
       3,     5,     7,     7,     9,     7,     5,     5,     1,     3,
       5,     5,     7,     5,     3,     3,     5,     1,     2,     4,
       1,     2,     3,     4,     1,     1,     1,     1,     1,     7,
       5,     5,     5,     7,     5,     5,     5,     3,     5,     7,
       7,     9,     7,     5,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 45 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                { yyval = ProgramGrammarAction(0); }
#line 1638 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 3:
#line 48 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                { yyval = WebGrammarAction(0);}
#line 1644 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 5:
#line 50 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                { yyval = WebGrammarAction(1);}
#line 1650 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 6:
#line 51 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                { yyval = WebGrammarAction(2);}
#line 1656 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 7:
#line 52 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                { yyval = WebGrammarAction(3);}
#line 1662 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 8:
#line 53 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                { yyval = WebGrammarAction(4);}
#line 1668 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 9:
#line 54 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        { yyval = WebGrammarAction(6);}
#line 1674 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 10:
#line 55 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                { yyval = WebGrammarAction(7);}
#line 1680 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 11:
#line 58 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 1686 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 12:
#line 59 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                        {}
#line 1692 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 45:
#line 101 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1698 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 46:
#line 102 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                        {}
#line 1704 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 47:
#line 103 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 1710 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 48:
#line 104 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1716 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 49:
#line 105 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1722 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 50:
#line 106 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1728 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 51:
#line 107 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1734 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 52:
#line 108 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1740 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 53:
#line 111 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 1746 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 54:
#line 112 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 1752 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 58:
#line 120 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1758 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 59:
#line 121 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1764 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 60:
#line 122 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1770 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 61:
#line 123 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1776 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 62:
#line 124 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1782 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 63:
#line 125 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1788 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 64:
#line 126 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1794 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 65:
#line 127 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1800 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 66:
#line 129 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1806 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 67:
#line 130 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1812 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 68:
#line 131 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1818 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 69:
#line 132 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1824 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 70:
#line 133 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 1830 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 71:
#line 134 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1836 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 72:
#line 135 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1842 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 73:
#line 136 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1848 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 74:
#line 138 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1854 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 75:
#line 139 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1860 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 76:
#line 140 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1866 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 77:
#line 141 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1872 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 78:
#line 142 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                {}
#line 1878 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 79:
#line 143 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 1884 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 80:
#line 144 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1890 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 81:
#line 145 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1896 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 82:
#line 147 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 1902 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 83:
#line 148 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1908 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 84:
#line 149 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1914 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 85:
#line 150 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1920 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 86:
#line 151 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 1926 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 87:
#line 152 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1932 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 88:
#line 153 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1938 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 89:
#line 154 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1944 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 90:
#line 156 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 1950 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 91:
#line 157 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1956 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 92:
#line 158 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 1962 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 93:
#line 159 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1968 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 94:
#line 160 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 1974 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 95:
#line 161 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 1980 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 96:
#line 162 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1986 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 97:
#line 163 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 1992 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 98:
#line 165 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 1998 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 99:
#line 166 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2004 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 100:
#line 167 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2010 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 101:
#line 168 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2016 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 102:
#line 169 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2022 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 103:
#line 170 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2028 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 104:
#line 171 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2034 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 105:
#line 172 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2040 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 106:
#line 174 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 2046 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 107:
#line 175 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2052 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 108:
#line 176 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2058 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 109:
#line 177 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2064 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 110:
#line 178 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                        {}
#line 2070 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 111:
#line 179 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2076 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 112:
#line 180 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2082 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 113:
#line 181 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2088 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 114:
#line 183 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2094 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 115:
#line 184 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2100 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 116:
#line 185 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                {}
#line 2106 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 117:
#line 189 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 2112 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 118:
#line 190 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 2118 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 119:
#line 191 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                        {}
#line 2124 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 120:
#line 192 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 2130 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 121:
#line 193 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                                                {}
#line 2136 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 122:
#line 196 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                { yyval = TitleGrammarAction(0); }
#line 2142 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 123:
#line 197 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        { yyval = TitleGrammarAction(1); }
#line 2148 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 124:
#line 198 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        { yyval = TitleGrammarAction(2); }
#line 2154 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 125:
#line 199 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        { yyval = TitleGrammarAction(3); }
#line 2160 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 126:
#line 202 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2166 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 127:
#line 203 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2172 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 128:
#line 204 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2178 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 129:
#line 205 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2184 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 130:
#line 206 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2190 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 131:
#line 207 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2196 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 132:
#line 208 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2202 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 133:
#line 209 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2208 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 134:
#line 211 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2214 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 135:
#line 212 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2220 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 136:
#line 213 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2226 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 137:
#line 214 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2232 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 138:
#line 215 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2238 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 139:
#line 216 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2244 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 140:
#line 217 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2250 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 141:
#line 218 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2256 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 142:
#line 220 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 2262 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 143:
#line 221 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2268 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 144:
#line 222 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2274 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 145:
#line 223 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2280 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 146:
#line 224 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2286 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 147:
#line 225 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2292 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 148:
#line 226 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2298 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 149:
#line 227 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2304 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 150:
#line 229 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2310 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 151:
#line 230 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2316 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 152:
#line 231 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2322 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 153:
#line 232 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2328 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 154:
#line 233 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2334 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 155:
#line 234 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2340 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 156:
#line 235 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2346 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 157:
#line 236 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2352 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 158:
#line 238 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2358 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 159:
#line 239 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2364 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 160:
#line 240 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2370 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 161:
#line 241 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2376 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 162:
#line 242 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2382 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 163:
#line 243 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2388 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 164:
#line 244 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2394 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 165:
#line 245 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2400 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 166:
#line 248 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2406 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 167:
#line 249 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2412 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 168:
#line 250 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2418 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 169:
#line 251 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2424 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 170:
#line 252 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2430 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 171:
#line 253 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2436 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 172:
#line 254 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2442 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 173:
#line 255 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2448 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 174:
#line 257 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2454 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 175:
#line 258 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2460 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 176:
#line 259 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2466 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 177:
#line 260 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2472 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 178:
#line 261 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2478 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 179:
#line 262 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2484 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 180:
#line 263 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2490 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 181:
#line 264 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2496 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 182:
#line 266 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2502 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 183:
#line 267 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2508 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 184:
#line 268 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2514 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 185:
#line 269 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2520 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 186:
#line 270 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2526 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 187:
#line 271 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2532 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 188:
#line 272 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2538 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 189:
#line 273 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2544 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 190:
#line 276 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2550 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 191:
#line 277 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2556 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 192:
#line 278 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2562 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 193:
#line 279 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2568 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 194:
#line 280 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2574 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 195:
#line 281 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2580 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 196:
#line 282 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2586 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 197:
#line 283 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2592 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 198:
#line 285 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2598 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 199:
#line 286 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2604 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 200:
#line 287 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2610 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 201:
#line 288 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2616 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 202:
#line 289 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2622 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 203:
#line 290 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2628 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 204:
#line 291 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2634 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 205:
#line 292 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2640 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 206:
#line 294 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2646 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 207:
#line 295 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2652 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 208:
#line 296 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2658 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 209:
#line 297 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2664 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 210:
#line 298 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                {}
#line 2670 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 211:
#line 299 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2676 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 212:
#line 300 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2682 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 213:
#line 301 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2688 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 214:
#line 303 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 2694 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 215:
#line 304 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2700 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 216:
#line 305 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2706 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 217:
#line 306 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2712 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 218:
#line 307 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2718 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 219:
#line 308 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2724 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 220:
#line 309 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2730 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 221:
#line 310 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2736 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 222:
#line 312 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 2742 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 223:
#line 313 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2748 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 224:
#line 314 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2754 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 225:
#line 315 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2760 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 226:
#line 316 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2766 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 227:
#line 317 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2772 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 228:
#line 318 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2778 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 229:
#line 319 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2784 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 230:
#line 321 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2790 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 231:
#line 322 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2796 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 232:
#line 323 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2802 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 233:
#line 324 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2808 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 234:
#line 325 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2814 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 235:
#line 326 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2820 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 236:
#line 327 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                        {}
#line 2826 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 237:
#line 328 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2832 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 238:
#line 330 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                                {}
#line 2838 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 239:
#line 331 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2844 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 240:
#line 332 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2850 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 241:
#line 333 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2856 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 242:
#line 334 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                        {}
#line 2862 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 243:
#line 335 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2868 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 244:
#line 336 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2874 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 245:
#line 337 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2880 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 246:
#line 340 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                        {}
#line 2886 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 268:
#line 375 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                                {}
#line 2892 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 269:
#line 376 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2898 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 270:
#line 377 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2904 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 271:
#line 378 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2910 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 272:
#line 379 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2916 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 273:
#line 380 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                        {}
#line 2922 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;

  case 274:
#line 381 "../src/frontend/syntactic-analysis/bison-grammar.y"
                                                                                {}
#line 2928 "../src/frontend/syntactic-analysis/bison-parser.c"
    break;


#line 2932 "../src/frontend/syntactic-analysis/bison-parser.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 384 "../src/frontend/syntactic-analysis/bison-grammar.y"


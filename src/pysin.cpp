/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "pysin.y"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../lib/MAST.hpp"
#include <string>


using namespace std;
#define YYDEBUG 1
int yylex(); 
int yyerror(const char *s) { printf ("\nError: %s\n", s); }

extern "C" FILE *yyin;


//SymbolTable *st = new SymbolTable();
MAST *asTree = new MAST();






/* Line 268 of yacc.c  */
#line 96 "pysin.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 25 "pysin.y"

#include "../lib/Nodos.hpp"




/* Line 288 of yacc.c  */
#line 127 "pysin.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FLOATNUMBER = 258,
     INTEGER = 259,
     STRING = 260,
     NAME = 261,
     DEDENT = 262,
     INDENT = 263,
     NEWLINE = 264,
     MAS = 265,
     MENOS = 266,
     POR = 267,
     ENTRE = 268,
     MOD = 269,
     DIV = 270,
     POT = 271,
     FALSE = 272,
     CLASS = 273,
     FINALLY = 274,
     IS = 275,
     RETURN = 276,
     NONE = 277,
     CONTINUE = 278,
     FOR = 279,
     LAMBDA = 280,
     TRY = 281,
     TRUE = 282,
     DEF = 283,
     FROM = 284,
     WHILE = 285,
     AND = 286,
     DEL = 287,
     NOT = 288,
     WITH = 289,
     AS = 290,
     ELIF = 291,
     IF = 292,
     OR = 293,
     ELSE = 294,
     IMPORT = 295,
     PASS = 296,
     BREAK = 297,
     EXCEPT = 298,
     IN = 299,
     PRINT = 300,
     COMMA = 301,
     DOT = 302,
     ASSIGN = 303,
     TWODOTS = 304,
     DOTCOMMA = 305,
     BINLEFT = 306,
     BINRIGHT = 307,
     ANDPAND = 308,
     PIPE = 309,
     EXP = 310,
     TILDE = 311,
     LESSTHAN = 312,
     MORETHAN = 313,
     LESSEQUAL = 314,
     MOREEQUAL = 315,
     EQUALS = 316,
     DIFFERENT = 317,
     PICOPARENTESIS = 318,
     OPENPAR = 319,
     CLOSEPAR = 320,
     OPENCOR = 321,
     CLOSECOR = 322,
     OPENKEY = 323,
     CLOSEKEY = 324,
     AT = 325,
     RIGHT = 326,
     MASIGUAL = 327,
     MENOSIGUAL = 328,
     PORIGUAL = 329,
     ENTREIGUAL = 330,
     DIVIGUAL = 331,
     MODIGUAL = 332,
     ANDIGUAL = 333,
     ORIGUAL = 334,
     EXPIGUAL = 335,
     BINRIGHTIGUAL = 336,
     BINLEFTIGUAL = 337,
     POTIGUAL = 338,
     GLOBAL = 339,
     APOSTROFE = 340
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 31 "pysin.y"

	int entero;
	double flotante;
	char caracter;
	char* cadena;
	Node* nodo;



/* Line 293 of yacc.c  */
#line 239 "pysin.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 251 "pysin.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   908

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNRULES -- Number of states.  */
#define YYNSTATES  359

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    14,    16,    22,
      24,    27,    29,    33,    36,    38,    42,    45,    47,    50,
      54,    56,    58,    60,    62,    64,    66,    68,    70,    72,
      75,    77,    80,    83,    85,    89,    92,    94,    98,   101,
     103,   107,   110,   112,   116,   120,   123,   125,   129,   133,
     136,   138,   142,   146,   150,   154,   157,   160,   163,   165,
     168,   173,   175,   178,   181,   185,   189,   192,   195,   197,
     201,   203,   206,   210,   217,   220,   222,   226,   229,   231,
     235,   241,   246,   248,   250,   253,   257,   260,   264,   268,
     270,   274,   276,   281,   285,   288,   292,   296,   299,   302,
     304,   307,   309,   313,   316,   320,   322,   325,   328,   332,
     336,   339,   343,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   368,   371,   375,   378,   380,   383,   385,   387,
     393,   396,   398,   401,   404,   408,   411,   415,   420,   426,
     428,   430,   432,   435,   439,   442,   446,   449,   453,   455,
     457,   459,   461,   470,   476,   478,   484,   492,   497,   507,
     514,   516,   521,   524,   526,   528,   530,   535,   539,   543,
     545,   547,   549,   551,   553,   555,   558,   561,   563,   567,
     569,   571,   573,   575,   577,   579,   581,   583,   585,   587,
     589,   591,   593,   596,   599,   601,   605,   607,   611,   614,
     619,   621,   623,   626,   630,   634,   637,   639,   641,   643,
     645,   647,   649,   652,   654,   660,   663,   667,   672,   678,
     682,   685,   689,   695,   697,   699,   703,   707,   710,   714
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    89,    -1,    88,     9,    -1,
      88,   151,    -1,    -1,    92,    -1,    92,    37,    92,    39,
      90,    -1,    92,    -1,    94,    93,    -1,    89,    -1,    93,
      38,    94,    -1,    96,    95,    -1,    89,    -1,    95,    31,
      96,    -1,    33,    96,    -1,    97,    -1,   100,    98,    -1,
      98,    99,   100,    -1,    89,    -1,    57,    -1,    58,    -1,
      61,    -1,    60,    -1,    59,    -1,    62,    -1,    63,    -1,
      44,    -1,    33,    44,    -1,    20,    -1,    20,    33,    -1,
     102,   101,    -1,    89,    -1,   101,    54,   102,    -1,   104,
     103,    -1,    89,    -1,   103,    55,   104,    -1,   106,   105,
      -1,    89,    -1,   105,    53,   106,    -1,   108,   107,    -1,
      89,    -1,   107,    52,   108,    -1,   107,    51,   108,    -1,
     110,   109,    -1,    89,    -1,   109,    10,   110,    -1,   109,
      11,   110,    -1,   112,   111,    -1,    89,    -1,   111,    12,
     112,    -1,   111,    13,   112,    -1,   111,    14,   112,    -1,
     111,    15,   112,    -1,    10,   112,    -1,    11,   112,    -1,
      56,   112,    -1,   113,    -1,   130,   114,    -1,   130,   114,
      16,   112,    -1,    89,    -1,   114,   115,    -1,    64,    65,
      -1,    64,   116,    65,    -1,    66,   124,    67,    -1,    47,
       6,    -1,   117,   118,    -1,    89,    -1,   117,   120,    46,
      -1,   120,    -1,   120,    46,    -1,    12,    90,   119,    -1,
      12,    90,   119,    46,    16,    90,    -1,    16,    90,    -1,
      89,    -1,   119,    46,   120,    -1,    90,   121,    -1,    90,
      -1,    90,    48,    90,    -1,    24,   128,    44,    92,   122,
      -1,    24,   128,    44,    92,    -1,   121,    -1,   123,    -1,
      37,    91,    -1,    37,    91,   122,    -1,   126,   125,    -1,
     126,   125,    46,    -1,   125,    46,   126,    -1,    89,    -1,
      47,    47,    47,    -1,    90,    -1,    90,    49,    90,   127,
      -1,    90,    49,    90,    -1,    90,    49,    -1,    90,    49,
     127,    -1,    49,    90,   127,    -1,    49,    90,    -1,    49,
     127,    -1,    49,    -1,    49,    90,    -1,    49,    -1,   100,
     129,    46,    -1,   100,   129,    -1,   129,    46,   100,    -1,
      89,    -1,    64,    65,    -1,    66,    67,    -1,    64,   138,
      65,    -1,    66,   137,    67,    -1,    68,    69,    -1,    68,
     132,    69,    -1,    85,   135,    85,    -1,     6,    -1,     4,
      -1,     3,    -1,   136,    -1,    22,    -1,   131,    -1,    27,
      -1,    17,    -1,    90,    49,    90,   133,    -1,    90,   121,
      -1,    90,   161,    46,    -1,    90,   161,    -1,   121,    -1,
     134,    46,    -1,   134,    -1,    89,    -1,   134,    46,    90,
      49,    90,    -1,    90,   161,    -1,     5,    -1,     5,   136,
      -1,    90,   139,    -1,    90,   161,   163,    -1,    90,   121,
      -1,    90,   161,   163,    -1,    24,   128,    44,   141,    -1,
      24,   128,    44,   141,   140,    -1,   139,    -1,   143,    -1,
      91,    -1,    91,   142,    -1,    91,   142,    46,    -1,    46,
      91,    -1,   142,    46,    91,    -1,    37,    91,    -1,    37,
      91,   140,    -1,   145,    -1,   147,    -1,   148,    -1,   172,
      -1,    37,    90,    49,   149,   146,    39,    49,   149,    -1,
      37,    90,    49,   149,   146,    -1,    89,    -1,   146,    36,
      90,    49,   149,    -1,    30,    90,    49,   149,    39,    49,
     149,    -1,    30,    90,    49,   149,    -1,    24,   128,    44,
     165,    49,   149,    39,    49,   149,    -1,    24,   128,    44,
     165,    49,   149,    -1,   152,    -1,     9,     8,   150,     7,
      -1,   150,   151,    -1,   151,    -1,   152,    -1,   144,    -1,
     154,   153,    50,     9,    -1,   154,   153,     9,    -1,   153,
      50,   154,    -1,    89,    -1,   155,    -1,   159,    -1,   166,
      -1,   167,    -1,   168,    -1,   165,   156,    -1,   158,   165,
      -1,   157,    -1,   157,    48,   165,    -1,    89,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    76,    -1,    45,   160,    -1,    45,   162,    -1,    89,
      -1,    90,   161,   163,    -1,    89,    -1,   161,    46,    90,
      -1,    52,    90,    -1,    52,    90,   164,   163,    -1,    89,
      -1,    46,    -1,    46,    90,    -1,   164,    46,    90,    -1,
      90,   161,   163,    -1,    32,   128,    -1,    41,    -1,   169,
      -1,   170,    -1,   171,    -1,    42,    -1,    23,    -1,    21,
     165,    -1,    21,    -1,    28,     6,   173,    49,   149,    -1,
      64,    65,    -1,    64,   174,    65,    -1,   176,    48,    90,
     175,    -1,   176,    48,    90,   175,    46,    -1,   176,   175,
      46,    -1,   176,   175,    -1,   175,    46,   176,    -1,   175,
      46,   176,    48,    90,    -1,    89,    -1,     6,    -1,    64,
     177,    65,    -1,   176,   178,    46,    -1,   176,   178,    -1,
     178,    46,   176,    -1,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    62,    63,    69,    80,    83,    84,    86,
      89,   100,   101,   109,   120,   121,   129,   135,   139,   151,
     156,   159,   164,   169,   174,   179,   184,   189,   190,   191,
     192,   193,   197,   208,   209,   217,   228,   229,   237,   248,
     249,   257,   259,   260,   261,   264,   276,   277,   285,   297,
     302,   303,   310,   317,   320,   332,   338,   344,   345,   348,
     349,   351,   352,   355,   356,   357,   358,   361,   363,   364,
     366,   367,   368,   369,   370,   372,   373,   376,   377,   378,
     386,   392,   400,   401,   404,   409,   416,   417,   419,   420,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     435,   436,   439,   440,   442,   443,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   464,
     465,   469,   470,   471,   472,   475,   476,   477,   479,   480,
     483,   486,   487,   491,   492,   495,   496,   499,   505,   513,
     514,   517,   518,   519,   521,   522,   525,   531,   539,   540,
     541,   542,   545,   554,   563,   564,   574,   582,   591,   601,
     611,   612,   614,   615,   618,   619,   622,   634,   652,   657,
     661,   662,   663,   664,   665,   670,   679,   680,   683,   691,
     699,   701,   703,   705,   707,   709,   711,   713,   715,   717,
     719,   721,   724,   725,   727,   728,   739,   740,   747,   748,
     750,   751,   753,   754,   757,   761,   763,   766,   767,   768,
     770,   772,   775,   776,   790,   801,   802,   810,   815,   822,
     827,   843,   848,   855,   861,   865,   868,   873,   879,   884
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOATNUMBER", "INTEGER", "STRING",
  "NAME", "DEDENT", "INDENT", "NEWLINE", "MAS", "MENOS", "POR", "ENTRE",
  "MOD", "DIV", "POT", "FALSE", "CLASS", "FINALLY", "IS", "RETURN", "NONE",
  "CONTINUE", "FOR", "LAMBDA", "TRY", "TRUE", "DEF", "FROM", "WHILE",
  "AND", "DEL", "NOT", "WITH", "AS", "ELIF", "IF", "OR", "ELSE", "IMPORT",
  "PASS", "BREAK", "EXCEPT", "IN", "PRINT", "COMMA", "DOT", "ASSIGN",
  "TWODOTS", "DOTCOMMA", "BINLEFT", "BINRIGHT", "ANDPAND", "PIPE", "EXP",
  "TILDE", "LESSTHAN", "MORETHAN", "LESSEQUAL", "MOREEQUAL", "EQUALS",
  "DIFFERENT", "PICOPARENTESIS", "OPENPAR", "CLOSEPAR", "OPENCOR",
  "CLOSECOR", "OPENKEY", "CLOSEKEY", "AT", "RIGHT", "MASIGUAL",
  "MENOSIGUAL", "PORIGUAL", "ENTREIGUAL", "DIVIGUAL", "MODIGUAL",
  "ANDIGUAL", "ORIGUAL", "EXPIGUAL", "BINRIGHTIGUAL", "BINLEFTIGUAL",
  "POTIGUAL", "GLOBAL", "APOSTROFE", "$accept", "file_input", "filein",
  "epsilon", "test", "old_test", "or_test", "or_andtest", "and_test",
  "and_nottest", "not_test", "comparison", "comp_op_expr_kleene",
  "comp_op", "expr", "pipexor_expr", "xor_expr", "andxor_expr", "and_expr",
  "andpandshift_expr", "shift_expr", "leftright_shift_expr",
  "arithmetic_expr", "sign_term", "term", "factor_operation", "factor",
  "power", "trailer_kleene", "trailer", "arglist", "argument_comma",
  "argument_multiple", "comma_argument", "argument", "comp_for",
  "comp_iter", "comp_if", "subscriptlist", "comma_subscript", "subscript",
  "sliceop", "exprlist", "expr_kleene", "atom", "boolean",
  "dictorsetmaker", "dictor_set_help", "dictor_set_help2", "testlist1",
  "string_plus", "listmaker", "testlist_comp", "list_for", "list_iter",
  "testlist_safe", "comma_old_test_plus", "list_if", "compound_stmt",
  "if_stmt", "elif_test_td_suite_kleene", "while_stmt", "for_stmt",
  "suite", "stmt_plus", "stmt", "simple_stmt", "more_simple_stmt",
  "small_stmt", "expr_stmt", "expr_stmt_at", "assign_testlist_kleene",
  "augassign", "print_stmt", "print_stmt1", "comma_test_kleene",
  "print_stmt2", "comma_one", "comma_test_plus", "testlist", "del_stmt",
  "pass_stmt", "flow_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "funcdef", "parameters", "varargslist", "d", "fpdef", "fplist",
  "fpdef_kleene", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    88,    89,    90,    90,    91,
      92,    93,    93,    94,    95,    95,    96,    96,    97,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   101,   101,   102,   103,   103,   104,   105,
     105,   106,   107,   107,   107,   108,   109,   109,   109,   110,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   115,   116,   117,   117,
     118,   118,   118,   118,   118,   119,   119,   120,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   132,   132,   132,   132,   133,   133,   133,   134,   134,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   154,   154,   155,   156,   156,   157,   157,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   159,   159,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   165,   166,   167,   168,   168,   168,
     169,   170,   171,   171,   172,   173,   173,   174,   174,   174,
     174,   175,   175,   175,   176,   176,   177,   177,   178,   178
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     0,     1,     5,     1,
       2,     1,     3,     2,     1,     3,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     1,     3,     2,     1,     3,     2,     1,
       3,     2,     1,     3,     3,     2,     1,     3,     3,     2,
       1,     3,     3,     3,     3,     2,     2,     2,     1,     2,
       4,     1,     2,     2,     3,     3,     2,     2,     1,     3,
       1,     2,     3,     6,     2,     1,     3,     2,     1,     3,
       5,     4,     1,     1,     2,     3,     2,     3,     3,     1,
       3,     1,     4,     3,     2,     3,     3,     2,     2,     1,
       2,     1,     3,     2,     3,     1,     2,     2,     3,     3,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     3,     2,     1,     2,     1,     1,     5,
       2,     1,     2,     2,     3,     2,     3,     4,     5,     1,
       1,     1,     2,     3,     2,     3,     2,     3,     1,     1,
       1,     1,     8,     5,     1,     5,     7,     4,     9,     6,
       1,     4,     2,     1,     1,     1,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     1,     3,     2,     4,
       1,     1,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     5,     2,     3,     4,     5,     3,
       2,     3,     5,     1,     1,     3,     3,     2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     3,     1,   115,   114,   131,   113,     4,
       0,     0,   120,   213,   117,   211,     0,   119,     0,     0,
       0,     0,     0,   206,   210,     6,     0,     0,     0,     0,
       0,     6,     7,     6,     6,    17,     6,     6,     6,     6,
       6,     6,     6,    58,     6,   118,   116,   165,   148,   149,
     150,     5,   164,     6,   170,   171,     6,   172,   173,   174,
     207,   208,   209,   151,   132,    55,    56,   212,     6,     0,
       0,     0,   205,    16,     0,     0,   194,     6,   192,   193,
      57,   106,     6,     0,   107,     6,     0,   110,     6,     0,
       6,     0,   196,     6,     0,    11,    10,    14,    13,    20,
      18,    33,    32,    36,    35,    39,    38,    42,    41,    46,
      45,    50,    49,    61,    59,   169,     0,   180,   181,   182,
     183,   191,   184,   185,   186,   187,   188,   189,   190,   179,
     175,   177,     0,   105,   103,     0,     0,     0,     0,     0,
     198,     6,     0,   135,     6,   108,     0,   133,     6,   109,
       0,   122,   124,   111,   130,   112,   201,   200,   204,     0,
       0,     0,    30,     0,    28,    21,    22,    25,    24,    23,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    62,   167,
       0,     0,   176,   102,     0,   224,     0,   215,     0,     6,
       0,     0,   157,   160,     6,     0,     6,   195,     0,   136,
       0,   134,     6,   123,     0,   197,     0,    12,    15,    31,
      29,    19,    34,    37,    40,    44,    43,    47,    48,    51,
      52,    53,    54,    60,    66,    63,    68,     0,     0,     0,
      99,    91,     0,     6,   166,   168,   178,   104,     0,     6,
       0,   216,     0,   223,   220,   214,     0,     0,   154,   153,
     202,   201,   199,     0,     0,   128,   125,   121,   127,     8,
      64,     0,     0,    78,    67,    70,     0,   101,    97,    98,
      94,    65,    89,    86,   159,   229,   227,   225,     6,   219,
       0,   163,     0,     0,     0,   203,    81,   141,     9,   137,
     126,     6,    74,     0,    77,    69,    90,   100,    96,    93,
      95,    87,     0,   226,   217,   221,   161,   162,   156,     0,
       0,     0,    82,    80,    83,     0,   142,     0,   139,   138,
     140,     0,    75,    72,    79,    92,    88,     0,   228,   218,
       0,     0,   152,    84,   144,   143,   146,     0,     0,   158,
     222,   155,    85,   145,   147,   129,     0,    76,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    92,    31,   297,    32,    96,    33,    98,
      34,    35,   100,   172,    36,   102,    37,   104,    38,   106,
      39,   108,    40,   110,    41,   112,    42,    43,   114,   188,
     237,   238,   274,   333,   275,   322,   323,   324,   242,   283,
     243,   279,    69,   134,    44,    45,    89,   267,   268,    91,
      46,    86,    83,   328,   329,   299,   326,   330,    47,    48,
     259,    49,    50,   202,   290,    51,   203,   116,    53,    54,
     130,   131,   132,    55,    78,    93,    79,   158,   206,    56,
      57,    58,    59,    60,    61,    62,    63,   137,   198,   254,
     315,   250,   286
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -262
static const yytype_int16 yypact[] =
{
    -262,    33,   290,  -262,  -262,  -262,  -262,    31,  -262,  -262,
     823,   823,  -262,   808,  -262,  -262,   823,  -262,    38,   808,
     823,   808,   808,  -262,  -262,   587,   823,   627,   653,   696,
     808,  -262,    28,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,   822,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,    48,
      13,    44,  -262,  -262,    50,   808,  -262,  -262,  -262,  -262,
    -262,  -262,    58,    36,  -262,    80,     5,  -262,    22,    37,
    -262,    27,  -262,    61,   808,  -262,    72,  -262,    84,  -262,
     207,  -262,    62,  -262,    63,  -262,    64,  -262,    -4,  -262,
      40,  -262,    74,  -262,    12,  -262,     8,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,    75,   808,  -262,    76,   808,    10,    71,   470,   470,
      82,    61,   823,  -262,    61,  -262,   823,  -262,    61,  -262,
     808,  -262,    83,  -262,    86,  -262,   808,  -262,  -262,    87,
     808,   808,    97,    89,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   128,    70,    92,  -262,  -262,
     518,   808,  -262,   823,    98,  -262,    15,  -262,    73,    88,
     470,   143,   113,  -262,  -262,   808,   107,  -262,   110,  -262,
     115,  -262,    58,   808,   808,  -262,   808,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,    96,   561,   116,
     722,   108,    95,  -262,  -262,  -262,  -262,  -262,   470,  -262,
      99,  -262,   808,  -262,   120,  -262,   422,   118,  -262,   -14,
    -262,   808,  -262,   808,   808,  -262,  -262,  -262,   123,  -262,
    -262,   808,   808,     7,  -262,   125,   129,   808,   126,  -262,
     722,  -262,  -262,   132,   133,  -262,   134,  -262,  -262,    15,
     356,  -262,   470,   808,   130,  -262,    25,   135,  -262,    46,
     808,  -262,  -262,   808,  -262,   117,  -262,  -262,  -262,   126,
    -262,    92,   136,    15,   142,   141,  -262,  -262,  -262,   147,
     470,   808,  -262,  -262,  -262,   808,   144,   808,  -262,  -262,
    -262,   149,  -262,   146,  -262,  -262,  -262,   470,  -262,    15,
     808,   470,  -262,    25,  -262,   808,    46,   808,   788,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,   808,  -262,  -262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,  -262,     1,   -19,  -261,   -90,  -262,    39,  -262,
      -6,  -262,  -262,  -262,    -2,  -262,    29,  -262,    32,  -262,
      26,  -262,   -96,  -262,   -88,  -262,    42,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -145,   -69,  -135,  -262,  -262,  -262,
    -102,  -248,     4,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     204,  -262,  -262,   127,  -131,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -127,  -262,  -227,     0,  -262,    30,  -262,
    -262,  -262,  -262,  -262,  -262,    23,  -262,  -121,  -262,    -8,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,   -72,
    -129,  -262,  -262
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      71,     3,    52,    74,   159,    67,    77,   199,    82,    85,
      88,    90,   204,   143,    68,    73,   195,   189,    68,   151,
     207,   195,   293,   209,    72,   294,    76,   211,   184,   291,
     308,   142,   310,     4,    95,    97,     7,    99,   101,   103,
     105,   107,   109,   111,    70,   113,   142,   176,   177,   142,
     178,   179,    65,    66,   115,   303,   140,   129,   190,   185,
     343,   335,   321,   317,   344,    94,   346,   249,    80,   133,
     146,   150,   149,   255,   196,   197,   186,   136,   187,   196,
     225,   226,   142,   327,   353,   262,   180,   181,   182,   183,
     227,   228,   135,   138,   157,     5,     6,     7,     8,   139,
     141,   145,    10,    11,   146,   144,   153,   156,   148,    12,
     160,   152,   155,   154,    14,   161,   173,   175,   174,    17,
     200,   284,   193,   191,   192,    21,   216,   194,   205,   213,
     219,   212,   214,   220,   234,   235,   252,   215,   251,   239,
      68,   240,   157,   266,    68,   157,   208,   248,    26,   157,
     210,   256,   257,   261,   263,   218,    27,   280,    28,   264,
      29,   270,   281,   276,   287,   318,   289,   292,   241,   300,
     221,   305,   312,   296,   298,   277,   306,    30,   311,   320,
     313,   325,   -71,   246,   338,   337,   260,   236,   339,   340,
     345,   247,   348,   342,   215,   215,   341,   269,   347,   217,
     253,   224,   222,   357,   304,   258,   223,   157,   352,   336,
     349,    64,   147,   265,   351,   354,   314,     0,     0,   273,
     245,   278,   229,   230,   231,   232,   233,   162,     0,     0,
       0,   298,     0,   288,     0,   298,     0,   298,     0,     0,
     163,     0,   295,     0,   282,     0,     0,     0,     0,     0,
     285,   164,   301,   302,     0,   298,    52,     0,   307,     0,
       0,   309,     0,     0,   165,   166,   167,   168,   169,   170,
     171,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,   331,     0,     0,   334,     0,     0,     0,     0,   253,
      52,     0,   241,     5,     6,     7,     8,     0,     0,     9,
      10,    11,   332,     0,     0,     0,     0,    12,     0,     0,
       0,    13,    14,    15,    16,     0,     0,    17,    18,     0,
      19,   350,    20,    21,     0,     0,     0,    22,   355,   273,
       0,    23,    24,     0,     0,    25,     0,   358,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     5,
       6,     7,     8,   316,     0,     0,    10,    11,     0,     0,
       0,     0,     0,    12,     0,    30,     0,    13,    14,    15,
      16,     0,     0,    17,    18,     0,    19,     0,    20,    21,
       0,     0,     0,    22,     0,     0,     0,    23,    24,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,     5,     6,     7,     8,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,    12,
       0,    30,     0,    13,    14,    15,    16,     0,     0,    17,
      18,     0,    19,     0,    20,    21,     0,     0,     0,    22,
       0,     0,     0,    23,    24,     0,     0,    25,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     0,    26,   201,
      10,    11,     0,     0,     0,     0,    27,    12,    28,     0,
      29,    13,    14,    15,     0,     0,     0,    17,     0,     0,
       0,     0,    20,    21,     0,     0,     0,    30,     0,     0,
       0,    23,    24,     0,     0,    25,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,    26,   244,    10,    11,
       0,     0,     0,     0,    27,    12,    28,     0,    29,    13,
      14,    15,     0,     0,     0,    17,     0,     0,     0,     0,
      20,    21,     0,     0,     0,    30,     0,     0,     0,    23,
      24,     0,     0,    25,     5,     6,     7,     8,     0,     0,
       0,    10,    11,   271,    26,     0,     0,   272,    12,     0,
       0,     0,    27,    14,    28,     0,    29,     0,    17,     0,
       5,     6,     7,     8,    21,     0,     0,    10,    11,     0,
       0,     0,     0,    30,    12,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    17,     0,     0,    26,     0,     0,
      21,     0,     0,     0,     0,    27,     0,    28,     0,    29,
       5,     6,     7,     8,     0,     0,     0,    10,    11,    75,
       0,     0,     0,    26,    12,     0,    30,     0,     0,    14,
       0,    27,     0,    28,    17,    29,     5,     6,     7,     8,
      21,     0,     0,    10,    11,     0,     0,     0,     0,     0,
      12,     0,    30,     0,     0,    14,     0,     0,     0,     0,
      17,     0,     0,    26,     0,     0,    21,     0,     0,     0,
       0,    27,    81,    28,     0,    29,     0,     0,     0,     5,
       6,     7,     8,     0,     0,     0,    10,    11,     0,    26,
       0,     0,    30,    12,     0,     0,     0,    27,    14,    28,
      84,    29,     0,    17,     0,     5,     6,     7,     8,    21,
       0,     0,    10,    11,     0,     0,     0,     0,    30,    12,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    17,
       0,     0,    26,     0,     0,    21,     0,     0,     0,     0,
      27,     0,    28,     0,    29,    87,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,     0,     0,    26,     0,
       0,    30,     0,     0,     0,     0,    27,     0,    28,     0,
      29,     5,     6,     7,     8,     0,     0,     0,    10,    11,
       0,     0,     0,     0,   356,    12,     0,    30,     0,     0,
      14,     5,     6,     7,     8,    17,     0,     0,    10,    11,
       0,    21,     0,     0,     0,    12,     5,     6,     7,     8,
      14,     0,     0,    10,    11,    17,     0,     0,     0,     0,
      12,    21,     0,     0,    26,    14,     0,     0,     0,     0,
      17,     0,    27,     0,    28,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,    27,    30,    28,     0,    29,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    29,     0,    30,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,    30
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-262))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      19,     0,     2,    22,    94,    13,    25,   136,    27,    28,
      29,    30,   139,    82,    16,    21,     6,     9,    20,    88,
     141,     6,    36,   144,    20,    39,    25,   148,    16,   256,
     278,    24,   280,     0,    33,    34,     5,    36,    37,    38,
      39,    40,    41,    42,     6,    44,    24,    51,    52,    24,
      10,    11,    10,    11,    53,    48,    75,    56,    50,    47,
     321,   309,    37,   290,   325,    37,   327,   196,    26,    68,
      24,    49,    67,   200,    64,    65,    64,    64,    66,    64,
     176,   177,    24,    37,   345,   206,    12,    13,    14,    15,
     178,   179,    44,    49,    93,     3,     4,     5,     6,    49,
      77,    65,    10,    11,    24,    82,    69,    46,    85,    17,
      38,    88,    85,    90,    22,    31,    54,    53,    55,    27,
      49,   248,    46,    48,   132,    33,    39,   135,    46,    46,
      33,   150,    46,    44,     6,    65,    48,   156,    65,    47,
     142,    49,   141,   212,   146,   144,   142,    49,    56,   148,
     146,     8,    39,    46,    44,   161,    64,    49,    66,    44,
      68,    65,    67,    47,    65,   292,    46,    49,   187,    46,
     172,    46,    39,   263,   264,    49,    47,    85,    46,    49,
      46,    46,    65,   191,   313,    49,   205,   186,    46,    48,
      46,   193,    46,   320,   213,   214,    49,   216,    49,   160,
     199,   175,   173,   348,   273,   204,   174,   206,   343,   311,
     337,     7,    85,   212,   341,   346,   288,    -1,    -1,   238,
     190,   240,   180,   181,   182,   183,   184,    20,    -1,    -1,
      -1,   321,    -1,   252,    -1,   325,    -1,   327,    -1,    -1,
      33,    -1,   261,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,    44,   271,   272,    -1,   345,   256,    -1,   277,    -1,
      -1,   280,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,   300,    -1,    -1,   303,    -1,    -1,    -1,    -1,   288,
     290,    -1,   311,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,   301,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    -1,
      30,   340,    32,    33,    -1,    -1,    -1,    37,   347,   348,
      -1,    41,    42,    -1,    -1,    45,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,     3,
       4,     5,     6,     7,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    85,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    -1,    30,    -1,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    85,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    -1,    30,    -1,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    56,     9,
      10,    11,    -1,    -1,    -1,    -1,    64,    17,    66,    -1,
      68,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    41,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    56,     9,    10,    11,
      -1,    -1,    -1,    -1,    64,    17,    66,    -1,    68,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    85,    -1,    -1,    -1,    41,
      42,    -1,    -1,    45,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    56,    -1,    -1,    16,    17,    -1,
      -1,    -1,    64,    22,    66,    -1,    68,    -1,    27,    -1,
       3,     4,     5,     6,    33,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    85,    17,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    56,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    52,
      -1,    -1,    -1,    56,    17,    -1,    85,    -1,    -1,    22,
      -1,    64,    -1,    66,    27,    68,     3,     4,     5,     6,
      33,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    85,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    56,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    68,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    -1,    56,
      -1,    -1,    85,    17,    -1,    -1,    -1,    64,    22,    66,
      67,    68,    -1,    27,    -1,     3,     4,     5,     6,    33,
      -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    85,    17,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    56,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    16,    17,    -1,    85,    -1,    -1,
      22,     3,     4,     5,     6,    27,    -1,    -1,    10,    11,
      -1,    33,    -1,    -1,    -1,    17,     3,     4,     5,     6,
      22,    -1,    -1,    10,    11,    27,    -1,    -1,    -1,    -1,
      17,    33,    -1,    -1,    56,    22,    -1,    -1,    -1,    -1,
      27,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    85,    66,    -1,    68,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    85,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,    89,     0,     3,     4,     5,     6,     9,
      10,    11,    17,    21,    22,    23,    24,    27,    28,    30,
      32,    33,    37,    41,    42,    45,    56,    64,    66,    68,
      85,    90,    92,    94,    96,    97,   100,   102,   104,   106,
     108,   110,   112,   113,   130,   131,   136,   144,   145,   147,
     148,   151,   152,   154,   155,   159,   165,   166,   167,   168,
     169,   170,   171,   172,   136,   112,   112,   165,   100,   128,
       6,    90,   128,    96,    90,    52,    89,    90,   160,   162,
     112,    65,    90,   138,    67,    90,   137,    69,    90,   132,
      90,   135,    89,   161,    37,    89,    93,    89,    95,    89,
      98,    89,   101,    89,   103,    89,   105,    89,   107,    89,
     109,    89,   111,    89,   114,    89,   153,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    89,
     156,   157,   158,    89,   129,    44,    64,   173,    49,    49,
      90,   161,    24,   121,   161,    65,    24,   139,   161,    67,
      49,   121,   161,    69,   161,    85,    46,    89,   163,    92,
      38,    31,    20,    33,    44,    57,    58,    59,    60,    61,
      62,    63,    99,    54,    55,    53,    51,    52,    10,    11,
      12,    13,    14,    15,    16,    47,    64,    66,   115,     9,
      50,    48,   165,    46,   165,     6,    64,    65,   174,   176,
      49,     9,   149,   152,   149,    46,   164,   163,   128,   163,
     128,   163,    90,    46,    46,    90,    39,    94,    96,    33,
      44,   100,   102,   104,   106,   108,   108,   110,   110,   112,
     112,   112,   112,   112,     6,    65,    89,   116,   117,    47,
      49,    90,   124,   126,     9,   154,   165,   100,    49,   176,
     177,    65,    48,    89,   175,   149,     8,    39,    89,   146,
      90,    46,   163,    44,    44,    89,   121,   133,   134,    90,
      65,    12,    16,    90,   118,   120,    47,    49,    90,   127,
      49,    67,    89,   125,   149,    89,   178,    65,    90,    46,
     150,   151,    49,    36,    39,    90,    92,    91,    92,   141,
      46,    90,    90,    48,   121,    46,    47,    90,   127,    90,
     127,    46,    39,    46,   175,   176,     7,   151,   149,    90,
      49,    37,   121,   122,   123,    46,   142,    37,   139,   140,
     143,    90,    89,   119,    90,   127,   126,    49,   176,    46,
      48,    49,   149,    91,    91,    46,    91,    49,    46,   149,
      90,   149,   122,    91,   140,    90,    16,   120,    90
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 55 "pysin.y"
    {
				Node *sstmtln = asTree->bSStmtListNode();
				sstmtln->addFChild((yyvsp[(1) - (1)].nodo));
				(yyval.nodo) = sstmtln;
				cout<<"\nCOMPILATION COMPLETE :)\n";
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 63 "pysin.y"
    {
							Node *stmtln = asTree->bStmtListNode();
							stmtln->addFChild((yyvsp[(1) - (2)].nodo));
							(yyval.nodo) = stmtln;
							cout<<"\n";
						}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 69 "pysin.y"
    {
							Node *stmtn = asTree->bExprNode();
							stmtn->addFChild((yyvsp[(1) - (2)].nodo));

							Node *stmtln = asTree->bStmtListNode();
							stmtln->addFChild((yyvsp[(1) - (2)].nodo));
							(yyval.nodo) = stmtln;
						}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 80 "pysin.y"
    {/*Nada xD*/}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 83 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 84 "pysin.y"
    {cout<<"IF __ ELSE __ ";}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 86 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 89 "pysin.y"
    {
										if ((yyvsp[(2) - (2)].nodo) != NULL)
										{
											Node *orn = (yyvsp[(2) - (2)].nodo);
											orn->setFChild((yyvsp[(1) - (2)].nodo));
											(yyval.nodo) = orn;
										} else {
											(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
										}
									}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 100 "pysin.y"
    {}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 101 "pysin.y"
    {
										Node *orn = asTree->bOrNode();
										orn->setSChild((yyvsp[(3) - (3)].nodo));
										(yyval.nodo) = orn;
										cout<<"OR";
									}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 109 "pysin.y"
    {
											if ((yyvsp[(2) - (2)].nodo) != NULL)
											{
												Node *andn = (yyvsp[(2) - (2)].nodo);
												andn->setFChild((yyvsp[(1) - (2)].nodo));
												(yyval.nodo) = andn;
											} else {
												(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
											}
										}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 120 "pysin.y"
    {}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 121 "pysin.y"
    {
											Node *andn = asTree->bAndNode();
											andn->setSChild((yyvsp[(3) - (3)].nodo));
											(yyval.nodo) = andn;
											cout<<"AND";
										}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 129 "pysin.y"
    {
								Node *notn = asTree->bNotNode();
								notn->setFChild((yyvsp[(2) - (2)].nodo));
								(yyval.nodo) = notn;
								cout<<"NOT";
							}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 135 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 139 "pysin.y"
    {
									if ((yyvsp[(2) - (2)].nodo) != NULL)
									{
										Node *compn = (yyvsp[(2) - (2)].nodo);
										compn->setFChild((yyvsp[(1) - (2)].nodo));
										(yyval.nodo) = compn;
									} else {
										(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
									}
								}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 151 "pysin.y"
    {
											Node *compn = (yyvsp[(2) - (3)].nodo);
											compn->setSChild((yyvsp[(3) - (3)].nodo));
											(yyval.nodo) = compn;
										}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 159 "pysin.y"
    {
							Node *compn = asTree->bLTNode();
							(yyval.nodo) = compn;
							cout<<"<";
						}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 164 "pysin.y"
    {
							Node *compn = asTree->bGTNode();
							(yyval.nodo) = compn;
							cout<<">";
						}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 169 "pysin.y"
    {
							Node *compn = asTree->bEqNode();
							(yyval.nodo) = compn;
							cout<<"==";
						}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 174 "pysin.y"
    {
							Node *compn = asTree->bGTEqNode();
							(yyval.nodo) = compn;
							cout<<">=";
						}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 179 "pysin.y"
    {
							Node *compn = asTree->bLTEqNode();
							(yyval.nodo) = compn;
							cout<<"<=";
						}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 184 "pysin.y"
    {
							Node *compn = asTree->bNEqNode();
							(yyval.nodo) = compn;
							cout<<"!=";
						}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 189 "pysin.y"
    {cout<<"<>";}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 190 "pysin.y"
    {cout<<"IN";}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 191 "pysin.y"
    {cout<<"NOT IN";}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 192 "pysin.y"
    {cout<<"IS";}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 193 "pysin.y"
    {cout<<"IS NOT";}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 197 "pysin.y"
    {
									if ((yyvsp[(2) - (2)].nodo) != NULL)
									{
										Node *orn = (yyvsp[(2) - (2)].nodo);
										orn->setFChild((yyvsp[(1) - (2)].nodo));
										(yyval.nodo) = orn;
									} else {
										(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
									}
								}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 208 "pysin.y"
    {}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 209 "pysin.y"
    {
										Node *orn = asTree->bOrNode();
										orn->setFChild((yyvsp[(1) - (3)].nodo));
										orn->setSChild((yyvsp[(3) - (3)].nodo));
										(yyval.nodo) = orn;
									}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 217 "pysin.y"
    {
								if ((yyvsp[(2) - (2)].nodo) != NULL)
								{
									Node *andn = (yyvsp[(2) - (2)].nodo);
									andn->setFChild((yyvsp[(1) - (2)].nodo));
									(yyval.nodo) = andn;
								} else {
									(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
								}
							}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 228 "pysin.y"
    {}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 229 "pysin.y"
    {
									Node *andn = asTree->bAndNode();
									andn->setFChild((yyvsp[(1) - (3)].nodo));
									andn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = andn;
								}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 237 "pysin.y"
    {
												if ((yyvsp[(2) - (2)].nodo) != NULL)
												{
													Node *andn = (yyvsp[(2) - (2)].nodo);
													andn->setFChild((yyvsp[(1) - (2)].nodo));
													(yyval.nodo) = andn;
												} else {
													(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
												}
											}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 248 "pysin.y"
    {}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 249 "pysin.y"
    {
												Node *andn = asTree->bAndNode();
												andn->setFChild((yyvsp[(1) - (3)].nodo));
												andn->setSChild((yyvsp[(3) - (3)].nodo));
												(yyval.nodo) = andn;
											}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 257 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 260 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo); cout<<">>";}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 261 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo); cout<<"<<";}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 264 "pysin.y"
    {
										// Node *exprn = asTree->bExprNode();
										if ((yyvsp[(2) - (2)].nodo) != NULL)
										{
											Node *termn = (yyvsp[(2) - (2)].nodo);
											termn->setFChild((yyvsp[(1) - (2)].nodo));
											(yyval.nodo) = termn;
										} else {
											(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
										}
									}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 276 "pysin.y"
    {}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 277 "pysin.y"
    {
									Node *plusn = asTree->bPlusNode();
									plusn->setFChild((yyvsp[(1) - (3)].nodo));
									plusn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = plusn;
									cout<<"Suma";
								}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 285 "pysin.y"
    {
									Node *minusn = asTree->bMinusNode();
									minusn->setFChild((yyvsp[(1) - (3)].nodo));
									minusn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = minusn;
									cout<<"Resta";
								}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 297 "pysin.y"
    {
									Node *exprn = asTree->bExprNode();
									exprn->addFChild((yyvsp[(2) - (2)].nodo));
								}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 302 "pysin.y"
    {}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 303 "pysin.y"
    {
												Node *multn = asTree->bMultNode();
												multn->setFChild((yyvsp[(1) - (3)].nodo));
												multn->setSChild((yyvsp[(3) - (3)].nodo));
												(yyval.nodo) = multn;
												cout<<"Multiplicacion"<<endl;
											}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 310 "pysin.y"
    {
												Node *divn = asTree->bDiviNode();
												divn->setFChild((yyvsp[(1) - (3)].nodo));
												divn->setSChild((yyvsp[(3) - (3)].nodo));
												(yyval.nodo) = divn;
												cout<<"Division"<<endl;
											}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 317 "pysin.y"
    {
												cout<<"Modulo"<<endl;
											}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 320 "pysin.y"
    {
												Node *divn = asTree->bDiviNode();
												divn->setFChild((yyvsp[(1) - (3)].nodo));
												divn->setSChild((yyvsp[(3) - (3)].nodo));
												(yyval.nodo) = divn;
												cout<<"Division Entera"<<endl;
											}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 332 "pysin.y"
    {
							Node *plusn = asTree->bPlusNode();
							plusn->setSChild((yyvsp[(2) - (2)].nodo));
							(yyval.nodo) = plusn;
							cout<<"SUMA"<<endl;
						}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 338 "pysin.y"
    {
							Node *minusn = asTree->bMinusNode();
							minusn->setSChild((yyvsp[(2) - (2)].nodo));
							(yyval.nodo) = minusn;
							cout<<"RESTA"<<endl;
						}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 344 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 345 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 348 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 349 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (4)].nodo);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 351 "pysin.y"
    {}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 352 "pysin.y"
    {}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 355 "pysin.y"
    {cout<<"()"<<endl;}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 356 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<"(ARGLIST)"<<endl;}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 357 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<"(SUBSCRIPTLIST)"<<endl;}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 358 "pysin.y"
    {Node *identn = asTree->bIdentNode((yyvsp[(2) - (2)].cadena)); (yyval.nodo)=identn; cout<<".NAME"<<endl;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 361 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 364 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<",";}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 366 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 367 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo); cout<<","<<endl;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 368 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<"*"<<endl;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 369 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (6)].nodo); cout<<"*"<<endl;}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 370 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo); cout<<"**"<<endl;}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 373 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 376 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 377 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 378 "pysin.y"
    {
								Node *assignn = asTree->bAssignNode();
								assignn->setFChild((yyvsp[(1) - (3)].nodo));
								assignn->setFChild((yyvsp[(3) - (3)].nodo));
								(yyval.nodo) = assignn;
							}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 386 "pysin.y"
    {
											Node *forn = asTree->bForNode();
											forn->addFChild((yyvsp[(2) - (5)].nodo));
											forn->addFChild((yyvsp[(4) - (5)].nodo));
											cout<<"FOR"<<endl;
										}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 392 "pysin.y"
    {
											Node *forn = asTree->bForNode();
											forn->addFChild((yyvsp[(2) - (4)].nodo));
											forn->addFChild((yyvsp[(4) - (4)].nodo));
											cout<<"FOR"<<endl;
										}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 400 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 401 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 404 "pysin.y"
    {
									Node *ifn = asTree->bIfNode();
									ifn->addFChild((yyvsp[(2) - (2)].nodo));
									cout<<"IF"<<endl;
								}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 409 "pysin.y"
    {
									Node *ifn = asTree->bIfNode();
									ifn->addFChild((yyvsp[(2) - (3)].nodo));
									cout<<"IF"<<endl;
								}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 416 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 417 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 419 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo);}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 423 "pysin.y"
    {}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 424 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 425 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (4)].nodo);}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 426 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 427 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 428 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 429 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 430 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 431 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 432 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 435 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 436 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 450 "pysin.y"
    {(yyval.nodo)=NULL;}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 451 "pysin.y"
    {(yyval.nodo)=NULL;}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 452 "pysin.y"
    {(yyval.nodo)=(yyvsp[(2) - (3)].nodo);}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 453 "pysin.y"
    {(yyval.nodo)=(yyvsp[(2) - (3)].nodo);}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 454 "pysin.y"
    {(yyval.nodo)=NULL;}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 455 "pysin.y"
    {(yyval.nodo)=(yyvsp[(2) - (3)].nodo);}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 456 "pysin.y"
    {(yyval.nodo)=(yyvsp[(2) - (3)].nodo);}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 457 "pysin.y"
    {Node *identn = asTree->bIdentNode((yyvsp[(1) - (1)].cadena)); (yyval.nodo)=identn;}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 458 "pysin.y"
    {Node *intn = asTree->bIntNode((yyvsp[(1) - (1)].entero)); (yyval.nodo)=intn;}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 459 "pysin.y"
    {Node *floatn = asTree->bFloatNode((yyvsp[(1) - (1)].flotante)); (yyval.nodo)=floatn;}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 460 "pysin.y"
    {(yyval.nodo)=(yyvsp[(1) - (1)].nodo);}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 461 "pysin.y"
    {(yyval.nodo)=NULL;}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 462 "pysin.y"
    {(yyval.nodo)=(yyvsp[(1) - (1)].nodo);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 464 "pysin.y"
    {Node *booln = asTree->bIntNode(1); (yyval.nodo)=booln;}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 465 "pysin.y"
    {Node *booln = asTree->bIntNode(0); (yyval.nodo)=booln;}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 469 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (4)].nodo); cout<<":"<<endl<<endl;}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 470 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 471 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 472 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 475 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 476 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 477 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 479 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 480 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (5)].nodo); cout<<":"<<endl;}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 483 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 486 "pysin.y"
    {Node *strn = asTree->bStrNode((yyvsp[(1) - (1)].cadena)); (yyval.nodo)=strn;}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 487 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 491 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 492 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 495 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 496 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 499 "pysin.y"
    {
													Node *forn = asTree->bForNode();
													forn->addFChild((yyvsp[(2) - (4)].nodo));
													forn->addLChild((yyvsp[(4) - (4)].nodo));
													cout<<"FOR"<<endl;
												}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 505 "pysin.y"
    {
													Node *forn = asTree->bForNode();
													forn->addFChild((yyvsp[(2) - (5)].nodo));
													forn->addLChild((yyvsp[(4) - (5)].nodo));
													cout<<"FOR"<<endl;
												}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 513 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 514 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 517 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 518 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 519 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 521 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 522 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo);}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 525 "pysin.y"
    {
									Node *ifn = asTree->bIfNode();
									ifn->addFChild((yyvsp[(2) - (2)].nodo));
									(yyval.nodo) = ifn;
									cout<<"IF___"<<endl;
								}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 531 "pysin.y"
    {
									Node *ifn = asTree->bIfNode();
									ifn->addFChild((yyvsp[(2) - (3)].nodo));
									(yyval.nodo) = ifn;
									cout<<"IF___"<<endl;
								}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 539 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 540 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 541 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 542 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 545 "pysin.y"
    {
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild((yyvsp[(2) - (8)].nodo));
																			ifn->addLChild((yyvsp[(4) - (8)].nodo));
																			ifn->addLChild((yyvsp[(5) - (8)].nodo));
																			ifn->addLChild((yyvsp[(8) - (8)].nodo));
																			(yyval.nodo) = ifn;
																			cout<<"IF___:___ELSE:"<<endl;
																		}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 554 "pysin.y"
    {
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild((yyvsp[(2) - (5)].nodo));
																			ifn->addLChild((yyvsp[(4) - (5)].nodo));
																			ifn->addLChild((yyvsp[(5) - (5)].nodo));
																			(yyval.nodo) = ifn;
																			cout<<"IF___:___"<<endl;
																		}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 564 "pysin.y"
    {
																Node *ifn = asTree->bIfNode();
																ifn->addFChild((yyvsp[(3) - (5)].nodo));
																ifn->addLChild((yyvsp[(5) - (5)].nodo));
																ifn->addLChild((yyvsp[(1) - (5)].nodo));
																(yyval.nodo) = ifn;
																cout<<"ELIF___:"<<endl<<endl;
															}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 574 "pysin.y"
    {
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild((yyvsp[(2) - (7)].nodo));
														whilen->addLChild((yyvsp[(4) - (7)].nodo));
														whilen->addLChild((yyvsp[(7) - (7)].nodo));
														(yyval.nodo) = whilen;
														cout<<"WHILE___:___ ELSE :"<<endl;
													}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 582 "pysin.y"
    {
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild((yyvsp[(2) - (4)].nodo));
														whilen->addLChild((yyvsp[(4) - (4)].nodo));
														(yyval.nodo) = whilen;
														cout<<"WHILE___:"<<endl;
													}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 591 "pysin.y"
    {
																	Node *forn = asTree->bForNode();
																	forn->addFChild((yyvsp[(2) - (9)].nodo));
																	forn->addLChild((yyvsp[(4) - (9)].nodo));
																	forn->addLChild((yyvsp[(6) - (9)].nodo));
																	forn->addLChild((yyvsp[(6) - (9)].nodo));
																	forn->addLChild((yyvsp[(9) - (9)].nodo));
																	(yyval.nodo) = forn;
																	cout<<"FOR"<<endl;
																}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 601 "pysin.y"
    {
																	Node *forn = asTree->bForNode();
																	forn->addFChild((yyvsp[(2) - (6)].nodo));
																	forn->addLChild((yyvsp[(4) - (6)].nodo));
																	forn->addLChild((yyvsp[(6) - (6)].nodo));
																	(yyval.nodo) = forn;
																	cout<<"FOR"<<endl;
																}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 611 "pysin.y"
    {Node* stmtn = asTree->bExprNode(); stmtn->addFChild((yyvsp[(1) - (1)].nodo)); (yyval.nodo) = stmtn;}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 612 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (4)].nodo); cout<<"\nINDENT___DEDENT"<<endl;}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 614 "pysin.y"
    {Node* stmtln = (yyvsp[(1) - (2)].nodo); stmtln->addLChild((yyvsp[(2) - (2)].nodo)); (yyval.nodo) = stmtln;}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 615 "pysin.y"
    {Node* stmtln = asTree->bStmtListNode(); stmtln->addFChild((yyvsp[(1) - (1)].nodo)); (yyval.nodo) = stmtln;}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 618 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 619 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 622 "pysin.y"
    {
														if ((yyvsp[(2) - (4)].nodo) != NULL)
														{
															Node* sstmtln = (yyvsp[(2) - (4)].nodo);
															sstmtln->addFChild((yyvsp[(1) - (4)].nodo));
															(yyval.nodo) = sstmtln;
														} else {
															(yyval.nodo) = (yyvsp[(1) - (4)].nodo);
														}
														cout<<";\n"<<endl;
													}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 634 "pysin.y"
    {
														SStmtListNode* stmtn = dynamic_cast<SStmtListNode*> ((yyvsp[(2) - (3)].nodo));
														if ((yyvsp[(2) - (3)].nodo) == NULL)
														{
															cout << "IM RIGHT HERE!" << endl;
															Node* sstmtln = (yyvsp[(2) - (3)].nodo);
															sstmtln->addFChild((yyvsp[(1) - (3)].nodo));
															(yyval.nodo) = sstmtln;
														} else {
															Node* sstmtln = asTree->bSStmtListNode();
															sstmtln->addFChild((yyvsp[(1) - (3)].nodo));
															(yyval.nodo) = sstmtln;
															// $$ = $1;
														}
														cout<<"\n"<<endl;
													}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 652 "pysin.y"
    {
													Node* sstmtln = asTree->bSStmtListNode();
													sstmtln->addLChild((yyvsp[(3) - (3)].nodo));
													(yyval.nodo) = sstmtln;
												}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 657 "pysin.y"
    {}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 661 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 662 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 663 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 664 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 665 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 670 "pysin.y"
    {
								Node* assignn = (yyvsp[(1) - (2)].nodo);
								assignn->addFChild((yyvsp[(1) - (2)].nodo));
								Node* stmtn = asTree->bStmtNode();
								stmtn->addFChild(assignn);
								(yyval.nodo) = stmtn;
							}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 679 "pysin.y"
    {Node* assignn = (yyvsp[(1) - (2)].nodo); assignn->addLChild((yyvsp[(2) - (2)].nodo)); (yyval.nodo) = assignn;}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 680 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 683 "pysin.y"
    {
													Node* assignn = asTree->bAssignNode();
													assignn->addFChild((yyvsp[(1) - (3)].nodo));
													// assignn->addLChild($2);
													assignn->addLChild((yyvsp[(3) - (3)].nodo));
													(yyval.nodo) = assignn;
													cout<<"="<<endl;
												}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 691 "pysin.y"
    {
													Node* assignn = asTree->bAssignNode();
													(yyval.nodo) = assignn;
												}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 699 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"+=";}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 701 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"-=";}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 703 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"*=";}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 705 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"/=";}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 707 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"%=";}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 709 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"&=";}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 711 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"|=";}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 713 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"^=";}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 715 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<">>=";}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 717 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"<<=";}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 719 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"**=";}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 721 "pysin.y"
    {Node* assignn = asTree->bAssignNode(); (yyval.nodo) = assignn; cout<<"//=";}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 724 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo); cout<<"PRINT"<<endl;}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 725 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo); cout<<"PRINT"<<endl;}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 727 "pysin.y"
    {}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 728 "pysin.y"
    {
											if ((yyvsp[(2) - (3)].nodo) != NULL)
											{
												Node* stmtn = (yyvsp[(2) - (3)].nodo);
												stmtn->addFChild((yyvsp[(1) - (3)].nodo));
												(yyval.nodo) = stmtn;
											} else {
												(yyval.nodo) = (yyvsp[(1) - (3)].nodo);
											}
										}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 739 "pysin.y"
    {}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 740 "pysin.y"
    {
										Node* stmtn = asTree->bStmtNode();
										stmtn->addLChild((yyvsp[(3) - (3)].nodo));
										(yyval.nodo) = stmtn;
										cout<<",";
									}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 747 "pysin.y"
    {cout<<">>";}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 748 "pysin.y"
    {cout<<">>";}
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 751 "pysin.y"
    {cout<<",";}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 753 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); stmtn->addFChild((yyvsp[(2) - (2)].nodo)); (yyval.nodo) = stmtn;}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 754 "pysin.y"
    {Node* stmtn = (yyvsp[(1) - (3)].nodo); stmtn->addLChild((yyvsp[(3) - (3)].nodo)); (yyval.nodo) = stmtn;}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 757 "pysin.y"
    {Node* stmtn = (yyvsp[(2) - (3)].nodo); stmtn->addFChild((yyvsp[(1) - (3)].nodo)); (yyval.nodo) = stmtn;}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 761 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); stmtn->addFChild((yyvsp[(2) - (2)].nodo)); (yyval.nodo) = stmtn;}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 763 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); (yyval.nodo) = stmtn;}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 766 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 767 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 768 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 770 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); (yyval.nodo) = stmtn;}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 772 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); (yyval.nodo) = stmtn;}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 775 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); stmtn->addFChild((yyvsp[(2) - (2)].nodo)); (yyval.nodo) = stmtn; cout<<"RETURN __"<<endl;}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 776 "pysin.y"
    {Node* stmtn = asTree->bStmtNode(); (yyval.nodo) = stmtn; cout<<"RETURN"<<endl;}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 790 "pysin.y"
    {
											Node *funcn = asTree->bFuncNode();
											Node *identn = asTree->bIdentNode((yyvsp[(2) - (5)].cadena));
											funcn->addFChild(identn);
											funcn->addLChild((yyvsp[(3) - (5)].nodo));
											funcn->addLChild((yyvsp[(5) - (5)].nodo));
											(yyval.nodo) = funcn;
											cout<<"DEF NAME(_):_\n"<<endl;
										}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 801 "pysin.y"
    {Node *argsn = asTree->bArgsNode(); (yyval.nodo) = argsn;}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 802 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 810 "pysin.y"
    {
										Node *argsn = (yyvsp[(4) - (4)].nodo);
										argsn->addFChild((yyvsp[(1) - (4)].nodo));
										(yyval.nodo) = argsn;
									}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 815 "pysin.y"
    {
										Node *argsn = (yyvsp[(4) - (5)].nodo);
										Node *identn = (yyvsp[(1) - (5)].nodo);
										identn->setSChild((yyvsp[(3) - (5)].nodo));
										argsn->addFChild(identn);
										(yyval.nodo) = argsn;
									}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 822 "pysin.y"
    {
										Node *argsn = (yyvsp[(2) - (3)].nodo);
										argsn->addFChild((yyvsp[(1) - (3)].nodo));
										(yyval.nodo) = argsn;
									}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 827 "pysin.y"
    {
										Node *argsn = (yyvsp[(2) - (2)].nodo);
										argsn->addFChild((yyvsp[(1) - (2)].nodo));
										(yyval.nodo) = argsn;
									}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 843 "pysin.y"
    {
									Node *argsn = (yyvsp[(1) - (3)].nodo);
									argsn->addLChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = (yyvsp[(3) - (3)].nodo);
								}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 848 "pysin.y"
    {
									Node *argsn = (yyvsp[(1) - (5)].nodo);
									Node *identn = (yyvsp[(3) - (5)].nodo);
									identn->setSChild((yyvsp[(5) - (5)].nodo));
									argsn->addLChild(identn);
									(yyval.nodo) = argsn;
								}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 855 "pysin.y"
    {
									Node *argsn = asTree->bArgsNode();
									(yyval.nodo) = argsn;
								}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 861 "pysin.y"
    {
									Node *identn = asTree->bIdentNode((yyvsp[(1) - (1)].cadena));
									(yyval.nodo) = identn;
								}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 865 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 868 "pysin.y"
    {
									Node *argsn = (yyvsp[(2) - (3)].nodo);
									argsn->addLChild((yyvsp[(1) - (3)].nodo));
									(yyval.nodo) = argsn;
								}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 873 "pysin.y"
    {
									Node *argsn = (yyvsp[(2) - (2)].nodo);
									argsn->addLChild((yyvsp[(1) - (2)].nodo));
									(yyval.nodo) = argsn;
								}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 879 "pysin.y"
    {
											Node *argsn = (yyvsp[(1) - (3)].nodo);
											argsn->addLChild((yyvsp[(3) - (3)].nodo));
											(yyval.nodo) = argsn;
										}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 884 "pysin.y"
    {
											Node *argsn = asTree->bArgsNode();
											(yyval.nodo) = argsn;
										}
    break;



/* Line 1806 of yacc.c  */
#line 3876 "pysin.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 889 "pysin.y"



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
VisitorNode *visitor = new VisitorNode;



/* Line 268 of yacc.c  */
#line 94 "pysin.cpp"

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
#line 23 "pysin.y"

#include "../lib/Nodos.hpp"




/* Line 288 of yacc.c  */
#line 125 "pysin.cpp"

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
#line 29 "pysin.y"

	int entero;
	double flotante;
	char caracter;
	char* cadena;
	Node* nodo;



/* Line 293 of yacc.c  */
#line 237 "pysin.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 249 "pysin.cpp"

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
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

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
      25,    27,    31,    34,    36,    40,    43,    45,    48,    52,
      54,    56,    58,    60,    62,    64,    66,    68,    70,    73,
      75,    78,    81,    83,    87,    90,    92,    96,    99,   101,
     105,   108,   110,   114,   118,   121,   123,   127,   131,   134,
     136,   140,   144,   148,   152,   155,   158,   161,   163,   166,
     171,   173,   176,   179,   183,   187,   190,   193,   195,   199,
     201,   204,   208,   215,   218,   220,   224,   226,   230,   233,
     237,   241,   243,   247,   249,   254,   258,   261,   265,   269,
     272,   275,   277,   280,   282,   286,   289,   293,   295,   298,
     302,   305,   309,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   332,   334,   337,   340,   344,   346,   348,   350,
     352,   361,   367,   369,   375,   383,   388,   398,   405,   407,
     412,   415,   417,   419,   421,   426,   430,   434,   436,   438,
     440,   442,   445,   448,   451,   453,   455,   457,   459,   462,
     464,   467,   469,   473,   475,   477,   481,   483,   485,   487,
     489,   491,   494,   496,   502,   505,   509,   512,   516
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    89,    -1,    88,     9,    -1,
      88,   139,    -1,    -1,    91,    -1,    91,    37,    91,    39,
      90,    -1,    93,    92,    -1,    89,    -1,    92,    38,    93,
      -1,    95,    94,    -1,    89,    -1,    94,    31,    95,    -1,
      33,    95,    -1,    96,    -1,    99,    97,    -1,    97,    98,
      99,    -1,    89,    -1,    57,    -1,    58,    -1,    61,    -1,
      60,    -1,    59,    -1,    62,    -1,    63,    -1,    44,    -1,
      33,    44,    -1,    20,    -1,    20,    33,    -1,   101,   100,
      -1,    89,    -1,   100,    54,   101,    -1,   103,   102,    -1,
      89,    -1,   102,    55,   103,    -1,   105,   104,    -1,    89,
      -1,   104,    53,   105,    -1,   107,   106,    -1,    89,    -1,
     106,    52,   107,    -1,   106,    51,   107,    -1,   109,   108,
      -1,    89,    -1,   108,    10,   109,    -1,   108,    11,   109,
      -1,   111,   110,    -1,    89,    -1,   110,    12,   111,    -1,
     110,    13,   111,    -1,   110,    14,   111,    -1,   110,    15,
     111,    -1,    10,   111,    -1,    11,   111,    -1,    56,   111,
      -1,   112,    -1,   126,   113,    -1,   126,   113,    16,   111,
      -1,    89,    -1,   113,   114,    -1,    64,    65,    -1,    64,
     115,    65,    -1,    66,   120,    67,    -1,    47,     6,    -1,
     116,   117,    -1,    89,    -1,   116,   119,    46,    -1,   119,
      -1,   119,    46,    -1,    12,    90,   118,    -1,    12,    90,
     118,    46,    16,    90,    -1,    16,    90,    -1,    89,    -1,
     118,    46,   119,    -1,    90,    -1,    90,    48,    90,    -1,
     122,   121,    -1,   122,   121,    46,    -1,   121,    46,   122,
      -1,    89,    -1,    47,    47,    47,    -1,    90,    -1,    90,
      49,    90,   123,    -1,    90,    49,    90,    -1,    90,    49,
      -1,    90,    49,   123,    -1,    49,    90,   123,    -1,    49,
      90,    -1,    49,   123,    -1,    49,    -1,    49,    90,    -1,
      49,    -1,    99,   125,    46,    -1,    99,   125,    -1,   125,
      46,    99,    -1,    89,    -1,    64,    65,    -1,    64,   131,
      65,    -1,    66,    67,    -1,    66,   130,    67,    -1,    85,
     128,    85,    -1,   129,    -1,   127,    -1,    22,    -1,     6,
      -1,     3,    -1,     4,    -1,    27,    -1,    17,    -1,    90,
     148,    -1,     5,    -1,     5,   129,    -1,    90,   148,    -1,
      90,   148,   149,    -1,   133,    -1,   135,    -1,   136,    -1,
     155,    -1,    37,    90,    49,   137,   134,    39,    49,   137,
      -1,    37,    90,    49,   137,   134,    -1,    89,    -1,   134,
      36,    90,    49,   137,    -1,    30,    90,    49,   137,    39,
      49,   137,    -1,    30,    90,    49,   137,    -1,    24,   124,
      44,   150,    49,   137,    39,    49,   137,    -1,    24,   124,
      44,   150,    49,   137,    -1,   140,    -1,     9,     8,   138,
       7,    -1,   138,   139,    -1,   139,    -1,   140,    -1,   132,
      -1,   142,   141,    50,     9,    -1,   142,   141,     9,    -1,
     141,    50,   142,    -1,    89,    -1,   143,    -1,   146,    -1,
     151,    -1,    90,   144,    -1,   145,    90,    -1,    48,    90,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    45,
     147,    -1,    89,    -1,    90,   148,    -1,    89,    -1,   148,
      46,    90,    -1,    89,    -1,    46,    -1,    90,   148,   149,
      -1,   152,    -1,   153,    -1,   154,    -1,    42,    -1,    23,
      -1,    21,   150,    -1,    21,    -1,    28,     6,   156,    49,
     137,    -1,    64,    65,    -1,    64,   157,    65,    -1,     6,
     158,    -1,   158,    46,     6,    -1,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    62,    68,    72,    84,    87,    88,    91,
     103,   104,   112,   124,   125,   133,   139,   143,   161,   167,
     170,   175,   180,   185,   190,   195,   200,   201,   202,   203,
     204,   208,   220,   221,   229,   241,   242,   250,   262,   263,
     272,   282,   283,   287,   293,   310,   311,   323,   336,   352,
     353,   364,   375,   378,   391,   398,   405,   406,   409,   428,
     432,   433,   437,   438,   439,   440,   449,   460,   465,   477,
     478,   479,   480,   481,   484,   485,   489,   490,   502,   503,
     506,   507,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   522,   523,   526,   535,   546,   555,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   578,   583,   590,
     595,   602,   605,   612,   616,   619,   622,   623,   624,   625,
     628,   638,   649,   650,   661,   670,   680,   691,   702,   708,
     711,   733,   741,   742,   745,   755,   766,   775,   781,   787,
     793,   803,   829,   840,   873,   878,   883,   888,   895,   906,
     911,   925,   930,   944,   945,   948,   974,   975,   976,   979,
     986,   993,   999,  1007,  1021,  1026,  1036,  1049,  1058
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
  "epsilon", "test", "or_test", "or_andtest", "and_test", "and_nottest",
  "not_test", "comparison", "comp_op_expr_kleene", "comp_op", "expr",
  "pipexor_expr", "xor_expr", "andxor_expr", "and_expr",
  "andpandshift_expr", "shift_expr", "leftright_shift_expr",
  "arithmetic_expr", "sign_term", "term", "factor_operation", "factor",
  "power", "trailer_kleene", "trailer", "arglist", "argument_comma",
  "argument_multiple", "comma_argument", "argument", "subscriptlist",
  "comma_subscript", "subscript", "sliceop", "exprlist", "expr_kleene",
  "atom", "boolean", "testlist1", "string_plus", "listmaker",
  "testlist_comp", "compound_stmt", "if_stmt", "elif_test_td_suite_kleene",
  "while_stmt", "for_stmt", "suite", "stmt_plus", "stmt", "simple_stmt",
  "small_stmt_kleene", "small_stmt", "expr_stmt", "expr_stmt_at",
  "augassign", "print_stmt", "print_args", "comma_test_kleene",
  "comma_one", "testlist", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "funcdef", "parameters", "varargslist", "args_kleene", 0
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
      92,    92,    93,    94,    94,    95,    95,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,   100,   100,   101,   102,   102,   103,   104,   104,
     105,   106,   106,   106,   107,   108,   108,   108,   109,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   115,   116,   116,   117,
     117,   117,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   129,   129,   130,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   143,   144,   144,   145,   145,   145,   145,   146,   147,
     147,   148,   148,   149,   149,   150,   151,   151,   151,   152,
     153,   154,   154,   155,   156,   156,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     0,     1,     5,     2,
       1,     3,     2,     1,     3,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     1,     3,     2,     1,     3,     2,     1,     3,
       2,     1,     3,     3,     2,     1,     3,     3,     2,     1,
       3,     3,     3,     3,     2,     2,     2,     1,     2,     4,
       1,     2,     2,     3,     3,     2,     2,     1,     3,     1,
       2,     3,     6,     2,     1,     3,     1,     3,     2,     3,
       3,     1,     3,     1,     4,     3,     2,     3,     3,     2,
       2,     1,     2,     1,     3,     2,     3,     1,     2,     3,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     3,     1,     1,     1,     1,
       8,     5,     1,     5,     7,     4,     9,     6,     1,     4,
       2,     1,     1,     1,     4,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     2,     1,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     5,     2,     3,     2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     3,     1,   107,   108,   112,   106,     4,
       0,     0,   110,   162,   105,   160,     0,   109,     0,     0,
       0,     0,   159,     6,     0,     0,     0,     0,     0,     7,
       6,     6,    16,     6,     6,     6,     6,     6,     6,     6,
      57,     6,   104,   103,   133,   116,   117,   118,     5,   132,
       6,   138,   139,   140,   156,   157,   158,   119,   113,    54,
      55,     6,   161,     6,     0,     0,     0,    15,     0,   149,
       6,   148,    56,    98,     6,     0,   100,     6,     0,     6,
       0,     0,   144,   145,   146,   147,   141,     0,     0,    10,
       9,    13,    12,    19,    17,    32,    31,    35,    34,    38,
      37,    41,    40,    45,    44,    49,    48,    60,    58,   137,
       0,   151,     6,    97,    95,     0,     0,     0,     0,     0,
     150,     6,    99,   114,   101,   111,   102,   143,   142,     0,
       0,     0,    29,     0,    27,    20,    21,    24,    23,    22,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    61,   135,
       0,   154,   153,   155,    94,     0,     6,   164,     0,     0,
       0,   125,   128,     6,     0,   115,     0,    11,    14,    30,
      28,    18,    33,    36,    39,    43,    42,    46,    47,    50,
      51,    52,    53,    59,    65,    62,    67,     0,     0,     0,
      91,    83,     0,     6,   134,   136,   152,    96,     0,   168,
     166,   165,   163,     0,     0,   122,   121,     8,    63,     0,
       0,    76,    66,    69,     0,    93,    89,    90,    86,    64,
      81,    78,   127,     0,     0,   131,     0,     0,     0,     6,
      73,     0,    68,    82,    92,    88,    85,    87,    79,     0,
     167,   129,   130,   124,     0,     0,    74,    71,    77,    84,
      80,     0,     0,   120,     0,   126,   123,     0,    75,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   111,    28,    29,    90,    30,    92,    31,
      32,    94,   142,    33,    96,    34,    98,    35,   100,    36,
     102,    37,   104,    38,   106,    39,    40,   108,   158,   197,
     198,   222,   257,   223,   202,   231,   203,   227,    64,   114,
      41,    42,    80,    43,    78,    75,    44,    45,   216,    46,
      47,   171,   234,    48,   172,   110,    50,    51,    86,    87,
      52,    71,   112,   163,    62,    53,    54,    55,    56,    57,
     117,   168,   210
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
    -207,     9,   238,  -207,  -207,  -207,  -207,    14,  -207,  -207,
     173,   173,  -207,   619,  -207,  -207,   173,  -207,    20,   619,
     619,   619,  -207,   619,   173,   132,   533,   619,    24,    -4,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,    12,   -20,     3,  -207,    13,  -207,
    -207,  -207,  -207,  -207,  -207,     2,  -207,  -207,     6,  -207,
      16,   619,  -207,  -207,  -207,  -207,  -207,   619,   619,  -207,
      67,  -207,    72,  -207,    25,  -207,    50,  -207,    51,  -207,
      54,  -207,     8,  -207,    65,  -207,    66,  -207,    -1,  -207,
       7,  -207,    63,  -207,    68,   619,     5,    62,   416,   416,
      69,    63,  -207,    69,  -207,    69,  -207,  -207,  -207,    73,
     619,   619,    84,    74,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   113,    56,    44,  -207,  -207,
     464,   619,  -207,  -207,   173,    75,  -207,  -207,    58,   416,
     117,    87,  -207,  -207,   619,  -207,   619,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,    76,   507,    80,
     542,    79,    64,  -207,  -207,  -207,  -207,  -207,   416,  -207,
      86,  -207,  -207,   368,    85,  -207,   -19,  -207,  -207,   619,
     619,    92,  -207,   101,   103,   619,   102,  -207,   542,  -207,
    -207,   107,    94,   149,   303,  -207,   416,   619,   109,  -207,
    -207,   619,    91,  -207,  -207,  -207,   102,  -207,    44,   111,
    -207,  -207,  -207,  -207,   115,   416,  -207,   116,  -207,  -207,
    -207,   416,   416,  -207,   599,  -207,  -207,   619,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,     1,   -13,    78,  -207,    38,  -207,   -15,
    -207,  -207,  -207,   -12,  -207,    32,  -207,    36,  -207,    37,
    -207,   -57,  -207,   -54,  -207,    19,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,   -83,  -207,  -207,   -62,  -205,  -207,  -207,
    -207,  -207,  -207,   182,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -116,  -207,  -206,     0,  -207,    31,  -207,  -207,  -207,
    -207,  -207,   -52,    71,    88,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -71
static const yytype_int16 yytable[] =
{
      61,     3,    49,   173,    63,    67,    66,   235,    68,     4,
      70,   166,    74,    77,    79,   154,   159,   237,   120,     7,
     238,   245,   121,   247,    69,   123,    65,   125,   252,    59,
      60,    89,    91,    88,    93,    95,    97,    99,   101,   103,
     105,   259,   107,    72,   116,   132,   155,     5,     6,     7,
       8,   109,   118,   212,    10,    11,   115,   160,   133,   146,
     147,    12,   119,   156,   113,   157,    14,   122,   127,   134,
     167,    17,    81,   124,   128,   148,   149,    20,   150,   151,
     152,   153,   135,   136,   137,   138,   139,   140,   141,   185,
     186,   199,   232,   200,   187,   188,    82,    83,    84,    85,
      24,   126,    61,   131,   143,   130,   144,   145,    25,   161,
      26,   169,   176,   162,   164,   174,   178,   179,   180,   194,
     253,   195,   162,   211,   208,   213,   214,   224,   228,    27,
     181,   229,   233,   249,   236,     5,     6,     7,     8,   263,
     241,   218,    10,    11,   201,   265,   266,   242,   206,    12,
     243,   225,   207,   248,    14,   250,   -70,   196,   255,    17,
     261,   206,   264,   217,   262,    20,   129,   209,   177,   189,
     190,   191,   192,   193,   215,   182,     5,     6,     7,     8,
     183,   268,   184,    10,    11,   221,   260,   226,    24,    58,
      12,   205,   175,     0,     0,    14,    25,    73,    26,     0,
      17,     0,     0,   165,   230,     0,   239,   240,     0,     0,
       0,     0,   244,    49,     0,   246,     0,    27,     0,     0,
       0,     0,     0,     0,   254,     0,     0,     0,   258,    24,
       0,     0,     0,     0,    49,   201,     0,    25,     0,    26,
     256,     5,     6,     7,     8,     0,     0,     9,    10,    11,
       0,   221,     0,     0,   269,    12,     0,     0,    27,    13,
      14,    15,    16,     0,     0,    17,    18,     0,    19,     0,
       0,    20,     0,     0,     0,    21,     0,     0,     0,     0,
      22,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,     0,     5,     6,     7,     8,
     251,     0,     0,    10,    11,     0,     0,     0,     0,     0,
      12,     0,     0,    27,    13,    14,    15,    16,     0,     0,
      17,    18,     0,    19,     0,     0,    20,     0,     0,     0,
      21,     0,     0,     0,     0,    22,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    26,
       0,     5,     6,     7,     8,     0,     0,     0,    10,    11,
       0,     0,     0,     0,     0,    12,     0,     0,    27,    13,
      14,    15,    16,     0,     0,    17,    18,     0,    19,     0,
       0,    20,     0,     0,     0,    21,     0,     0,     0,     0,
      22,     0,     0,    23,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,    24,   170,    10,    11,     0,     0,
       0,     0,    25,    12,    26,     0,     0,    13,    14,    15,
       0,     0,     0,    17,     0,     0,     0,     0,     0,    20,
       0,     0,     0,    27,     0,     0,     0,     0,    22,     0,
       0,    23,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,    24,   204,    10,    11,     0,     0,     0,     0,
      25,    12,    26,     0,     0,    13,    14,    15,     0,     0,
       0,    17,     0,     0,     0,     0,     0,    20,     0,     0,
       0,    27,     0,     0,     0,     0,    22,     0,     0,    23,
       5,     6,     7,     8,     0,     0,     0,    10,    11,   219,
      24,     0,     0,   220,    12,     0,     0,     0,    25,    14,
      26,     0,     0,     0,    17,     0,     5,     6,     7,     8,
      20,     0,     0,    10,    11,     5,     6,     7,     8,    27,
      12,     0,    10,    11,     0,    14,     0,     0,     0,    12,
      17,     0,     0,    24,    14,     0,    20,     0,     0,    17,
       0,    25,     0,    26,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   225,    27,     0,     0,     0,     0,    25,    24,    26,
      76,     0,     5,     6,     7,     8,    25,     0,    26,    10,
      11,     0,     0,     0,     0,   267,    12,     0,    27,     0,
       0,    14,     5,     6,     7,     8,    17,    27,     0,    10,
      11,     0,    20,     0,     0,     0,    12,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,    20,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    25,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    25,    27,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-207))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,     0,     2,   119,    16,    20,    19,   213,    21,     0,
      23,     6,    25,    26,    27,    16,     9,    36,    70,     5,
      39,   226,    74,   228,    23,    77,     6,    79,   234,    10,
      11,    30,    31,    37,    33,    34,    35,    36,    37,    38,
      39,   246,    41,    24,    64,    20,    47,     3,     4,     5,
       6,    50,    49,   169,    10,    11,    44,    50,    33,    51,
      52,    17,    49,    64,    63,    66,    22,    65,    81,    44,
      65,    27,    48,    67,    87,    10,    11,    33,    12,    13,
      14,    15,    57,    58,    59,    60,    61,    62,    63,   146,
     147,    47,   208,    49,   148,   149,    72,    73,    74,    75,
      56,    85,   115,    31,    54,    38,    55,    53,    64,    46,
      66,    49,    39,   112,    46,    46,   131,    33,    44,     6,
     236,    65,   121,    65,    49,     8,    39,    47,    49,    85,
     142,    67,    46,    39,    49,     3,     4,     5,     6,   255,
      48,    65,    10,    11,   157,   261,   262,    46,   161,    17,
      47,    49,   164,    46,    22,     6,    65,   156,    49,    27,
      49,   174,    46,   176,    49,    33,    88,   166,   130,   150,
     151,   152,   153,   154,   173,   143,     3,     4,     5,     6,
     144,   264,   145,    10,    11,   198,   248,   200,    56,     7,
      17,   160,   121,    -1,    -1,    22,    64,    65,    66,    -1,
      27,    -1,    -1,   115,   203,    -1,   219,   220,    -1,    -1,
      -1,    -1,   225,   213,    -1,   228,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   241,    56,
      -1,    -1,    -1,    -1,   234,   248,    -1,    64,    -1,    66,
     239,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      -1,   264,    -1,    -1,   267,    17,    -1,    -1,    85,    21,
      22,    23,    24,    -1,    -1,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    85,    21,    22,    23,    24,    -1,    -1,
      27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    85,    21,
      22,    23,    24,    -1,    -1,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    56,     9,    10,    11,    -1,    -1,
      -1,    -1,    64,    17,    66,    -1,    -1,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    56,     9,    10,    11,    -1,    -1,    -1,    -1,
      64,    17,    66,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      56,    -1,    -1,    16,    17,    -1,    -1,    -1,    64,    22,
      66,    -1,    -1,    -1,    27,    -1,     3,     4,     5,     6,
      33,    -1,    -1,    10,    11,     3,     4,     5,     6,    85,
      17,    -1,    10,    11,    -1,    22,    -1,    -1,    -1,    17,
      27,    -1,    -1,    56,    22,    -1,    33,    -1,    -1,    27,
      -1,    64,    -1,    66,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    49,    85,    -1,    -1,    -1,    -1,    64,    56,    66,
      67,    -1,     3,     4,     5,     6,    64,    -1,    66,    10,
      11,    -1,    -1,    -1,    -1,    16,    17,    -1,    85,    -1,
      -1,    22,     3,     4,     5,     6,    27,    85,    -1,    10,
      11,    -1,    33,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    85,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,    89,     0,     3,     4,     5,     6,     9,
      10,    11,    17,    21,    22,    23,    24,    27,    28,    30,
      33,    37,    42,    45,    56,    64,    66,    85,    90,    91,
      93,    95,    96,    99,   101,   103,   105,   107,   109,   111,
     112,   126,   127,   129,   132,   133,   135,   136,   139,   140,
     142,   143,   146,   151,   152,   153,   154,   155,   129,   111,
     111,    90,   150,    99,   124,     6,    90,    95,    90,    89,
      90,   147,   111,    65,    90,   131,    67,    90,   130,    90,
     128,    48,    72,    73,    74,    75,   144,   145,    37,    89,
      92,    89,    94,    89,    97,    89,   100,    89,   102,    89,
     104,    89,   106,    89,   108,    89,   110,    89,   113,    89,
     141,    89,   148,    89,   125,    44,    64,   156,    49,    49,
     148,   148,    65,   148,    67,   148,    85,    90,    90,    91,
      38,    31,    20,    33,    44,    57,    58,    59,    60,    61,
      62,    63,    98,    54,    55,    53,    51,    52,    10,    11,
      12,    13,    14,    15,    16,    47,    64,    66,   114,     9,
      50,    46,    89,   149,    46,   150,     6,    65,   157,    49,
       9,   137,   140,   137,    46,   149,    39,    93,    95,    33,
      44,    99,   101,   103,   105,   107,   107,   109,   109,   111,
     111,   111,   111,   111,     6,    65,    89,   115,   116,    47,
      49,    90,   120,   122,     9,   142,    90,    99,    49,    89,
     158,    65,   137,     8,    39,    89,   134,    90,    65,    12,
      16,    90,   117,   119,    47,    49,    90,   123,    49,    67,
      89,   121,   137,    46,   138,   139,    49,    36,    39,    90,
      90,    48,    46,    47,    90,   123,    90,   123,    46,    39,
       6,     7,   139,   137,    90,    49,    89,   118,    90,   123,
     122,    49,    49,   137,    46,   137,   137,    16,   119,    90
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
#line 50 "pysin.y"
    {
				cout << endl << "file_input" << endl;
				if ((yyvsp[(1) - (1)].nodo) != NULL)
				{
					Node* node = (yyvsp[(1) - (1)].nodo);
					node->accept(*visitor); cout << endl;
				}
				cout<<"\nCOMPILATION COMPLETE :)\n";
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 62 "pysin.y"
    {
							cout << "filein epsilon..." << endl;
							Node* stmtln = asTree->bStmtListNode();
							stmtln->accept(*visitor);
							(yyval.nodo) = stmtln;
						}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 68 "pysin.y"
    {
							cout << "filein newline" << endl;
							(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
						}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 72 "pysin.y"
    {
							cout << "filein stmt" << endl;
							if ((yyvsp[(1) - (2)].nodo) != NULL)
							{
								Node *stmtln = (yyvsp[(1) - (2)].nodo);
								stmtln->addLChild((yyvsp[(2) - (2)].nodo));
								(yyval.nodo) = stmtln;
							}
						}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 84 "pysin.y"
    {/*Nada xD*/}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 87 "pysin.y"
    {cout<<"test"<<endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 88 "pysin.y"
    {cout<<"IF __ ELSE __ ";}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 91 "pysin.y"
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

  case 10:

/* Line 1806 of yacc.c  */
#line 103 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 104 "pysin.y"
    {
									Node *orn = asTree->bOrNode();
									orn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = orn;
									cout<<"OR";
								}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 112 "pysin.y"
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

  case 13:

/* Line 1806 of yacc.c  */
#line 124 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 125 "pysin.y"
    {
									Node *andn = asTree->bAndNode();
									andn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = andn;
									cout<<"AND";
								}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 133 "pysin.y"
    {
						Node *notn = asTree->bNotNode();
						notn->setFChild((yyvsp[(2) - (2)].nodo));
						(yyval.nodo) = notn;
						cout<<"NOT";
					}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 139 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 143 "pysin.y"
    {
									cout << "expr comp_op_expr_kleene" << endl;
									if ((yyvsp[(2) - (2)].nodo) != NULL)
									{
										cout << "($2 != NULL)" << endl;
										Node *compn = (yyvsp[(2) - (2)].nodo);
										compn->setFChild((yyvsp[(1) - (2)].nodo));
										compn->accept(*visitor); cout << endl;
										(yyval.nodo) = compn;
									} else {
										cout << "($2 == NULL)" << endl;
										Node* node = (yyvsp[(1) - (2)].nodo);
										node->accept(*visitor);
										(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
									}
								}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 161 "pysin.y"
    {
											Node *compn = (yyvsp[(2) - (3)].nodo);
											compn->setSChild((yyvsp[(3) - (3)].nodo));
											compn->accept(*visitor); cout << endl;
											(yyval.nodo) = compn;
										}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 167 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 170 "pysin.y"
    {
							Node *compn = asTree->bLTNode();
							(yyval.nodo) = compn;
							cout<<"<";
						}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 175 "pysin.y"
    {
							Node *compn = asTree->bGTNode();
							(yyval.nodo) = compn;
							cout<<">";
						}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 180 "pysin.y"
    {
							Node *compn = asTree->bEqNode();
							(yyval.nodo) = compn;
							cout<<"==";
						}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 185 "pysin.y"
    {
							Node *compn = asTree->bGTEqNode();
							(yyval.nodo) = compn;
							cout<<">=";
						}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 190 "pysin.y"
    {
							Node *compn = asTree->bLTEqNode();
							(yyval.nodo) = compn;
							cout<<"<=";
						}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 195 "pysin.y"
    {
							Node *compn = asTree->bNEqNode();
							(yyval.nodo) = compn;
							cout<<"!=";
						}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 200 "pysin.y"
    {cout<<"<>";}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 201 "pysin.y"
    {cout<<"IN";}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 202 "pysin.y"
    {cout<<"NOT IN";}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 203 "pysin.y"
    {cout<<"IS";}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 204 "pysin.y"
    {cout<<"IS NOT";}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 208 "pysin.y"
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

  case 32:

/* Line 1806 of yacc.c  */
#line 220 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 221 "pysin.y"
    {
										Node *orn = asTree->bOrNode();
										orn->setFChild((yyvsp[(1) - (3)].nodo));
										orn->setSChild((yyvsp[(3) - (3)].nodo));
										(yyval.nodo) = orn;
									}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 229 "pysin.y"
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

  case 35:

/* Line 1806 of yacc.c  */
#line 241 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 242 "pysin.y"
    {
									Node *andn = asTree->bAndNode();
									andn->setFChild((yyvsp[(1) - (3)].nodo));
									andn->setSChild((yyvsp[(3) - (3)].nodo));
									(yyval.nodo) = andn;
								}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 250 "pysin.y"
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

  case 38:

/* Line 1806 of yacc.c  */
#line 262 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 263 "pysin.y"
    {
												Node *andn = asTree->bAndNode();
												andn->setFChild((yyvsp[(1) - (3)].nodo));
												andn->setSChild((yyvsp[(3) - (3)].nodo));
												andn->accept(*visitor); cout << endl;
												(yyval.nodo) = andn;
											}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 272 "pysin.y"
    {
												if ((yyvsp[(2) - (2)].nodo) != NULL)
												{
													/* Asignar hijo izq de operador (<< | >>) */
												} else {
													(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
												}
											}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 282 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 283 "pysin.y"
    {
														cout<<">>";
														(yyval.nodo) = (yyvsp[(3) - (3)].nodo);
													}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 287 "pysin.y"
    {
														cout<<"<<";
														(yyval.nodo) = (yyvsp[(3) - (3)].nodo);
													}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 293 "pysin.y"
    {
						cout << "term sign_term" << endl;
						Node *termn = (yyvsp[(1) - (2)].nodo);
						termn->accept(*visitor); cout << endl;
						if ((yyvsp[(2) - (2)].nodo) != NULL)
						{
							Node *termn = (yyvsp[(2) - (2)].nodo);
							termn->setFChild((yyvsp[(1) - (2)].nodo));
							termn->accept(*visitor); cout << endl;
							(yyval.nodo) = termn;
						} else {
							(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
						}
						cout << "END < arithmetic_expr" << endl;
					}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 310 "pysin.y"
    { (yyval.nodo) = NULL; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 311 "pysin.y"
    {
									cout<<"Suma"<<endl;
									Node *plusn = asTree->bPlusNode();
									plusn->setSChild((yyvsp[(3) - (3)].nodo));
									if ((yyvsp[(1) - (3)].nodo) != NULL)
									{
										plusn->setFChild((yyvsp[(1) - (3)].nodo));
									}
									plusn->accept(*visitor);
									(yyval.nodo) = plusn;
								}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 323 "pysin.y"
    {
									cout<<"Resta"<<endl;
									Node *minusn = asTree->bMinusNode();
									minusn->setSChild((yyvsp[(3) - (3)].nodo));
									if ((yyvsp[(1) - (3)].nodo) != NULL)
									{
										minusn->setFChild((yyvsp[(1) - (3)].nodo));
									}
									minusn->accept(*visitor);
									(yyval.nodo) = minusn;
								}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 336 "pysin.y"
    {
									cout << "factor factor_operation" << endl;
									Node* node = (yyvsp[(1) - (2)].nodo);
									node->accept(*visitor); cout << endl;
									if ((yyvsp[(2) - (2)].nodo) != NULL)
									{
										Node* factorn = (yyvsp[(2) - (2)].nodo);
										factorn->setFChild((yyvsp[(1) - (2)].nodo));
										factorn->accept(*visitor); cout << endl;
										(yyval.nodo) = factorn;
									} else {
										(yyval.nodo) = (yyvsp[(1) - (2)].nodo);
									}
								}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 352 "pysin.y"
    { (yyval.nodo)=NULL; }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 353 "pysin.y"
    {
												cout<<"Multiplicacion"<<endl;
												Node *multn = asTree->bMultNode();
												multn->setSChild((yyvsp[(3) - (3)].nodo));
												if ((yyvsp[(1) - (3)].nodo) != NULL)
												{
													multn->setFChild((yyvsp[(1) - (3)].nodo));
												}
												multn->accept(*visitor);
												(yyval.nodo) = multn;
											}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 364 "pysin.y"
    {
												cout<<"Division"<<endl;
												Node *divn = asTree->bDiviNode();
												divn->setSChild((yyvsp[(3) - (3)].nodo));
												if ((yyvsp[(1) - (3)].nodo) != NULL)
												{
													divn->setFChild((yyvsp[(1) - (3)].nodo));
												}
												divn->accept(*visitor);
												(yyval.nodo) = divn;
											}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 375 "pysin.y"
    {
												cout<<"Modulo"<<endl;
											}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 378 "pysin.y"
    {
												cout<<"Division Entera"<<endl;
												Node *divn = asTree->bDiviNode();
												divn->setSChild((yyvsp[(3) - (3)].nodo));
												if ((yyvsp[(1) - (3)].nodo) != NULL)
												{
													divn->setFChild((yyvsp[(1) - (3)].nodo));
												}
												divn->accept(*visitor);
												(yyval.nodo) = divn;
											}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 391 "pysin.y"
    {
							cout<<"SUMA"<<endl;
							Node *plusn = asTree->bPlusNode();
							plusn->setSChild((yyvsp[(2) - (2)].nodo));
							plusn->accept(*visitor); cout << endl;
							(yyval.nodo) = plusn;
						}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 398 "pysin.y"
    {
							cout<<"RESTA"<<endl;
							Node *minusn = asTree->bMinusNode();
							minusn->setSChild((yyvsp[(2) - (2)].nodo));
							minusn->accept(*visitor); cout << endl;
							(yyval.nodo) = minusn;
						}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 405 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 406 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);cout<<"power"<<endl; Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 409 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);cout << "atom trailer_kleene" << endl; 
											Node* node = (yyvsp[(1) - (2)].nodo); node->accept(*visitor); cout << endl;
											/*
											if ($1 != NULL)
											{
												cout << "$1 IS NOT NULL" << endl;
												StrNode* strn = dynamic_cast<StrNode*> ($1);
												if (strn!=0)
												{
													cout << "cast done "<< endl;
													//strn->accept(*visitor); cout << endl;
												} else {
													cout << "couldnt cast "<< endl;
												}
											} else {
												cout << "$1 IS NULL!!!!!" << endl;
											}
											*/
										}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 428 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (4)].nodo);cout << "atom trailer_kleene POT factor" << endl;
											Node* node = (yyvsp[(1) - (4)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 432 "pysin.y"
    {cout << "epsilon trailer_kleene" << endl;}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 433 "pysin.y"
    {cout << "trailer_kleene trailer" << endl;}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 437 "pysin.y"
    {cout<<"()"<<endl;}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 438 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<"(ARGLIST)"<<endl;}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 439 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo); cout<<"(SUBSCRIPTLIST)"<<endl;}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 440 "pysin.y"
    {
											cout<<".NAME"<<endl;
											string* id = new string((yyvsp[(2) - (2)].cadena));
											Node *identn = asTree->bIdentNode(id);
											identn->accept(*visitor); cout << endl;
											(yyval.nodo)=identn; 
										}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 449 "pysin.y"
    {
											if ((yyvsp[(1) - (2)].nodo) != NULL)
											{
												Node *argsn = (yyvsp[(1) - (2)].nodo);
												argsn->addLChild((yyvsp[(2) - (2)].nodo));
												argsn->accept(*visitor); cout << endl;
												(yyval.nodo) = argsn;
											}
										}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 460 "pysin.y"
    {
											Node *argsn = asTree->bArgsNode();
											argsn->accept(*visitor); cout << endl;
											(yyval.nodo) = argsn;
										}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 465 "pysin.y"
    {
											if ((yyvsp[(1) - (3)].nodo) != NULL)
											{
												Node *argsn = (yyvsp[(1) - (3)].nodo);
												argsn->addLChild((yyvsp[(2) - (3)].nodo));
												argsn->accept(*visitor); cout << endl;
												(yyval.nodo) = argsn;
											}
										}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 477 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 478 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 479 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 480 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (6)].nodo);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 481 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 485 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo);}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 489 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 490 "pysin.y"
    {
							cout << "********************************************************" << endl;
							cout << "Argumentos con asignacion i.e. foo(x=3) no tiene soporte" << endl;
							cout << "********************************************************" << endl;
							Node *assignn = asTree->bAssignNode();
							assignn->setFChild((yyvsp[(1) - (3)].nodo));
							assignn->setFChild((yyvsp[(3) - (3)].nodo));
							(yyval.nodo) = assignn;
						}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 502 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 503 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 506 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (3)].nodo);}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 510 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 511 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 512 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (4)].nodo);}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 513 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 514 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 515 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 516 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 517 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 518 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo);}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 519 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 522 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 523 "pysin.y"
    {cout<<":"<<endl;}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 526 "pysin.y"
    {
								if ((yyvsp[(2) - (3)].nodo) != NULL)
								{
									Node* exprln = (yyvsp[(2) - (3)].nodo);
									exprln->addFChild((yyvsp[(1) - (3)].nodo));
									exprln->accept(*visitor); cout << endl;
									(yyval.nodo) = exprln;
								}
							}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 535 "pysin.y"
    {
								if ((yyvsp[(2) - (2)].nodo) != NULL)
								{
									Node* exprln = (yyvsp[(2) - (2)].nodo);
									exprln->addFChild((yyvsp[(1) - (2)].nodo));
									exprln->accept(*visitor); cout << endl;
									(yyval.nodo) = exprln;
								}
							}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 546 "pysin.y"
    {
								if ((yyvsp[(1) - (3)].nodo) != NULL)
								{
									Node* exprln = (yyvsp[(1) - (3)].nodo);
									exprln->addLChild((yyvsp[(3) - (3)].nodo));
									exprln->accept(*visitor); cout << endl;
									(yyval.nodo) = exprln;
								}
							}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 555 "pysin.y"
    {
								Node* exprln = asTree->bArgsNode();
								exprln->accept(*visitor); cout << endl;
								(yyval.nodo) = exprln;
							}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 563 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 564 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 565 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 566 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 567 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (3)].nodo);}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 568 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 569 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 570 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 571 "pysin.y"
    {
						cout << ";;;" << (yyvsp[(1) - (1)].cadena) << ";;;" << endl;
						string* id = new string((yyvsp[(1) - (1)].cadena));
						Node *identn = asTree->bIdentNode(id);
						identn->accept(*visitor); cout << endl;
						(yyval.nodo)=identn;
					}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 578 "pysin.y"
    {
						Node *floatn = asTree->bFloatNode((yyvsp[(1) - (1)].flotante));
						floatn->accept(*visitor); cout << endl;
						(yyval.nodo)=floatn;
					}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 583 "pysin.y"
    {
						Node *intn = asTree->bIntNode((yyvsp[(1) - (1)].entero));
						(yyval.nodo)=intn;
						intn->accept(*visitor); cout << endl;
					}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 590 "pysin.y"
    {
				Node *booln = asTree->bBoolNode(true);
				booln->accept(*visitor); cout << endl;
				(yyval.nodo) = booln;
			}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 595 "pysin.y"
    {
				Node *booln = asTree->bBoolNode(false);
				booln->accept(*visitor); cout << endl;
				(yyval.nodo) = booln;
			}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 602 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 605 "pysin.y"
    {
									// cout << ":::" << $1 << ":::" << endl;
									string* str = new string((yyvsp[(1) - (1)].cadena));
									Node *strn = asTree->bStrNode(str);
									strn->accept(*visitor); cout << endl;
									(yyval.nodo) = strn;
								}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 612 "pysin.y"
    {(yyval.nodo) = (yyvsp[(2) - (2)].nodo); cout << "not here please......" << endl;}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 616 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (2)].nodo);}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 619 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (3)].nodo);}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 622 "pysin.y"
    {cout<<"compound_stmt"<<endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 623 "pysin.y"
    {cout<<"compound_stmt"<<endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 624 "pysin.y"
    {cout<<"compound_stmt"<<endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 625 "pysin.y"
    {cout<<"compound_stmt"<<endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 628 "pysin.y"
    {
																			cout << "if _ : _ else : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild((yyvsp[(2) - (8)].nodo));
																			ifn->addLChild((yyvsp[(4) - (8)].nodo));
																			ifn->addLChild((yyvsp[(5) - (8)].nodo));
																			ifn->addLChild((yyvsp[(8) - (8)].nodo));
																			ifn->accept(*visitor); cout << endl;
																			(yyval.nodo) = ifn;
																		}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 638 "pysin.y"
    {
																			cout << "if _ : _" << endl;
																			Node *ifn = asTree->bIfNode();
																			ifn->addFChild((yyvsp[(2) - (5)].nodo));
																			ifn->addLChild((yyvsp[(4) - (5)].nodo));
																			ifn->addLChild((yyvsp[(5) - (5)].nodo));
																			ifn->accept(*visitor); cout << endl;
																			(yyval.nodo) = ifn;
																		}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 650 "pysin.y"
    {
															cout << "elif _ : _" << endl;
															Node *ifn = asTree->bIfNode();
															ifn->addFChild((yyvsp[(3) - (5)].nodo));
															ifn->addLChild((yyvsp[(5) - (5)].nodo));
															ifn->addLChild((yyvsp[(1) - (5)].nodo));
															ifn->accept(*visitor); cout << endl;
															(yyval.nodo) = ifn;
														}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 661 "pysin.y"
    {
														cout << "while _ : _ else : _" << endl;
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild((yyvsp[(2) - (7)].nodo));
														whilen->addLChild((yyvsp[(4) - (7)].nodo));
														whilen->addLChild((yyvsp[(7) - (7)].nodo));
														whilen->accept(*visitor); cout << endl;
														(yyval.nodo) = whilen;
													}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 670 "pysin.y"
    {
														cout << "while _ : _" << endl;
														Node *whilen = asTree->bWhileNode();
														whilen->addFChild((yyvsp[(2) - (4)].nodo));
														whilen->addLChild((yyvsp[(4) - (4)].nodo));
														whilen->accept(*visitor); cout << endl;
														(yyval.nodo) = whilen;
													}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 680 "pysin.y"
    {
																	cout << "for _ in _ : _ else : _" << endl;
																	Node *forn = asTree->bForNode();
																	forn->addFChild((yyvsp[(2) - (9)].nodo));
																	forn->addLChild((yyvsp[(4) - (9)].nodo));
																	forn->addLChild((yyvsp[(6) - (9)].nodo));
																	forn->addLChild((yyvsp[(6) - (9)].nodo));
																	forn->addLChild((yyvsp[(9) - (9)].nodo));
																	forn->accept(*visitor); cout << endl;
																	(yyval.nodo) = forn;
																}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 691 "pysin.y"
    {
																	cout << "for _ in _ : _" << endl;
																	Node *forn = asTree->bForNode();
																	forn->addFChild((yyvsp[(2) - (6)].nodo));
																	forn->addLChild((yyvsp[(4) - (6)].nodo));
																	forn->addLChild((yyvsp[(6) - (6)].nodo));
																	forn->accept(*visitor); cout << endl;
																	(yyval.nodo) = forn;
																}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 702 "pysin.y"
    {
											Node *stmtln = asTree->bStmtListNode();
											stmtln->addFChild((yyvsp[(1) - (1)].nodo));
											stmtln->accept(*visitor); cout << endl;
											(yyval.nodo) = stmtln;
										}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 708 "pysin.y"
    {(yyval.nodo) = (yyvsp[(3) - (4)].nodo);}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 711 "pysin.y"
    {
						if ((yyvsp[(1) - (2)].nodo) != NULL)
						{
							Node *stmtln = (yyvsp[(1) - (2)].nodo);
							stmtln->addLChild((yyvsp[(2) - (2)].nodo));
							stmtln->accept(*visitor); cout << endl;
							(yyval.nodo) = stmtln;
						}
						/*
						StmtListNode* stmtlnc = dynamic_cast<StmtListNode*> ($1);
						if (stmtlnc != 0)
						{
							Node *stmtln = $1;
							stmtln->addLChild($2);
							$$ = stmtln;
						} else {
							Node *stmtln = asTree->bStmtListNode();
							stmtln->addLChild($2);
							$$ = stmtln;
						}
						*/
					}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 733 "pysin.y"
    {
						Node* stmtln = asTree->bStmtListNode();
						stmtln->addFChild((yyvsp[(1) - (1)].nodo));
						stmtln->accept(*visitor); cout << endl;
						(yyval.nodo) = stmtln;
					}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 741 "pysin.y"
    {cout << "stmt:" <<endl; Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 742 "pysin.y"
    {cout << "stmt:" <<endl; Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl; (yyval.nodo) = (yyvsp[(1) - (1)].nodo);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 745 "pysin.y"
    {
														if ((yyvsp[(2) - (4)].nodo) != NULL)
														{
															Node* sstmtln = (yyvsp[(2) - (4)].nodo);
															sstmtln->addFChild((yyvsp[(1) - (4)].nodo));
															sstmtln->accept(*visitor); cout << endl;
															(yyval.nodo) = sstmtln;
														}
													}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 755 "pysin.y"
    {
														if ((yyvsp[(2) - (3)].nodo) != NULL)
														{
															Node* sstmtln = (yyvsp[(2) - (3)].nodo);
															sstmtln->addFChild((yyvsp[(1) - (3)].nodo));
															sstmtln->accept(*visitor); cout << endl;
															(yyval.nodo) = sstmtln;
														}
													}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 766 "pysin.y"
    {
													if ((yyvsp[(1) - (3)].nodo) != NULL)
													{
														Node* sstmtln = (yyvsp[(1) - (3)].nodo);
														sstmtln->addLChild((yyvsp[(3) - (3)].nodo));
														sstmtln->accept(*visitor); cout << endl;
														(yyval.nodo) = sstmtln;
													}
												}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 775 "pysin.y"
    {
													Node* sstmtln = asTree->bSStmtListNode();
													(yyval.nodo) = sstmtln;
												}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 781 "pysin.y"
    {
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild((yyvsp[(1) - (1)].nodo));
						sstmtn->accept(*visitor); cout << endl;
						(yyval.nodo) = sstmtn;
					}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 787 "pysin.y"
    {
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild((yyvsp[(1) - (1)].nodo));
						sstmtn->accept(*visitor); cout << endl;
						(yyval.nodo) = sstmtn;
					}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 793 "pysin.y"
    {
						Node *sstmtn = asTree->bSStmtNode();
						sstmtn->addFChild((yyvsp[(1) - (1)].nodo));
						sstmtn->accept(*visitor); cout << endl;
						(yyval.nodo) = sstmtn;
					}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 803 "pysin.y"
    {
								AssignNode* assignn = dynamic_cast<AssignNode*> ((yyvsp[(2) - (2)].nodo));
								if (assignn != 0)
								{
									Node* assignn = (yyvsp[(2) - (2)].nodo);
									assignn->setFChild((yyvsp[(1) - (2)].nodo));
									assignn->accept(*visitor); cout << endl;
									(yyval.nodo) = assignn;
								} else {
									Node* augassign = (yyvsp[(2) - (2)].nodo);
									augassign->setFChild((yyvsp[(1) - (2)].nodo));

									Node* exprn = asTree->bExprNode();
									exprn->addFChild(augassign);

									Node* assignn = asTree->bAssignNode();
									assignn->setFChild((yyvsp[(1) - (2)].nodo));
									assignn->setSChild(exprn);
									assignn->accept(*visitor); cout << endl;
									(yyval.nodo) = assignn;
								}
							}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 829 "pysin.y"
    {
									// Node* exprn = asTree->bExprNode();
									// exprn->addFChild($2);

									Node* assignn = (yyvsp[(1) - (2)].nodo);
									assignn->setSChild((yyvsp[(2) - (2)].nodo));
									// assignn->setSChild(exprn);
									(yyval.nodo) = assignn;
								}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 840 "pysin.y"
    {
									Node* exprn = asTree->bExprNode();
									exprn->addFChild((yyvsp[(2) - (2)].nodo));
									cout<<"="<<endl;
									Node* assignn = asTree->bAssignNode();
									assignn->setSChild(exprn);

									// ArgsNode* exprn = dynamic_cast<ArgsNode*> ($2);
									// if (exprn != 0)
									// {
										// assignn->setSChild($2);
									// } else {
									// 	assignn->setSChild($2);
									// }
									// assignn->accept(*visitor); cout << endl;
									(yyval.nodo) = assignn;
								}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 873 "pysin.y"
    {
						cout<<"+="<<endl;
						Node* assignn = asTree->bPlusNode();
						(yyval.nodo) = assignn;
					}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 878 "pysin.y"
    {
						cout<<"-="<<endl;
						Node* assignn = asTree->bMinusNode();
						(yyval.nodo) = assignn;
					}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 883 "pysin.y"
    {
						cout<<"*="<<endl;
						Node* assignn = asTree->bMultNode();
						(yyval.nodo) = assignn;
					}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 888 "pysin.y"
    {
						cout<<"/="<<endl;
						Node* assignn = asTree->bDiviNode();
						(yyval.nodo) = assignn;
					}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 895 "pysin.y"
    {
							Node *printn = asTree->bPrintNode();
							if ((yyvsp[(2) - (2)].nodo) != NULL)
							{
								printn->addFChild((yyvsp[(2) - (2)].nodo));
								(yyval.nodo) = printn;
							}
							printn->accept(*visitor); cout << endl;
						}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 906 "pysin.y"
    {
									Node *argsn = asTree->bArgsNode();
									argsn->accept(*visitor); cout << endl;
									(yyval.nodo) = argsn;
								}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 911 "pysin.y"
    {
									Node *exprn = asTree->bExprNode();
									exprn->addFChild((yyvsp[(1) - (2)].nodo));
									exprn->accept(*visitor); cout << endl;
									if ((yyvsp[(2) - (2)].nodo) != NULL)
									{
										Node *argsn = (yyvsp[(2) - (2)].nodo);
										argsn->addFChild(exprn);
										argsn->accept(*visitor); cout << endl;
										(yyval.nodo) = argsn;
									}
								}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 925 "pysin.y"
    {
										Node *argsn = asTree->bArgsNode();
										argsn->accept(*visitor); cout << endl;
										(yyval.nodo) = argsn;
									}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 930 "pysin.y"
    {
										Node* exprn = asTree->bExprNode();
										exprn->addFChild((yyvsp[(3) - (3)].nodo));
										exprn->accept(*visitor); cout << endl;
										if ((yyvsp[(1) - (3)].nodo) != NULL)
										{
											Node *argsn = (yyvsp[(1) - (3)].nodo);
											argsn->addLChild(exprn);
											argsn->accept(*visitor); cout << endl;
											(yyval.nodo) = argsn;
										}
									}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 945 "pysin.y"
    {(yyval.nodo) = NULL;}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 948 "pysin.y"
    {
											Node* exprn = asTree->bExprNode();
											exprn->addFChild((yyvsp[(1) - (3)].nodo));
											exprn->accept(*visitor); cout << endl;

											// ArgsNode* argsn = dynamic_cast<ArgsNode*> ($2);
											// bool hasNoChildren = argsn->getChildren().empty();
											// if (!hasNoChildren)
											if ((yyvsp[(2) - (3)].nodo) != NULL)
											{
												Node* argsn = (yyvsp[(2) - (3)].nodo);
												argsn->addFChild(exprn);
												argsn->accept(*visitor); cout << endl;
												(yyval.nodo) = argsn;
												// cout << "comma_test_kleene was not null" << endl;
											} else {
												// $$ = exprn;
												// cout << "comma_test_kleene was null!!!" << endl;
											}
										}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 974 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 975 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 976 "pysin.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo); Node* node = (yyvsp[(1) - (1)].nodo); node->accept(*visitor); cout << endl;}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 979 "pysin.y"
    {
				Node* breakn = asTree->bBreakNode();
				breakn->accept(*visitor); cout << endl;
				(yyval.nodo) = breakn;
			}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 986 "pysin.y"
    {
					Node* contn = asTree->bContinueNode();
					contn->accept(*visitor); cout << endl;
					(yyval.nodo) = contn;
				}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 993 "pysin.y"
    {
						Node* returnn = asTree->bReturnNode();
						returnn->addFChild((yyvsp[(2) - (2)].nodo));
						returnn->accept(*visitor); cout << endl;
						(yyval.nodo) = returnn;
					}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 999 "pysin.y"
    {
						Node* returnn = asTree->bReturnNode(); 
						returnn->accept(*visitor); cout << endl;
						(yyval.nodo) = returnn;
					}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1007 "pysin.y"
    {
											cout << "def name(_):\n" << endl;
											Node *funcn = asTree->bFuncNode();
											string* id = new string((yyvsp[(2) - (5)].cadena));
											Node *identn = asTree->bIdentNode(id);
											identn->accept(*visitor); cout << endl;
											funcn->addFChild(identn);
											funcn->addLChild((yyvsp[(3) - (5)].nodo));
											funcn->addLChild((yyvsp[(5) - (5)].nodo));
											funcn->accept(*visitor); cout << endl;
											(yyval.nodo) = funcn;
										}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1021 "pysin.y"
    {
										Node *argsn = asTree->bArgsNode();
										argsn->accept(*visitor); cout << endl;
										(yyval.nodo) = argsn;
									}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1026 "pysin.y"
    {
										if ((yyvsp[(2) - (3)].nodo) != NULL)
										{
											Node* node = (yyvsp[(2) - (3)].nodo);
											node->accept(*visitor); cout << endl;
											(yyval.nodo) = (yyvsp[(2) - (3)].nodo);
										}
									}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1036 "pysin.y"
    {
							string* id = new string((yyvsp[(1) - (2)].cadena));
							Node *identn = asTree->bIdentNode(id);
							identn->accept(*visitor); cout << endl;
							if ((yyvsp[(2) - (2)].nodo) != NULL)
							{
								Node *argsn = (yyvsp[(2) - (2)].nodo);
								argsn->addFChild(identn);
								argsn->accept(*visitor); cout << endl;
								(yyval.nodo) = argsn;
							}
						}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1049 "pysin.y"
    {
								string* id = new string((yyvsp[(3) - (3)].cadena));
								Node *identn = asTree->bIdentNode(id);
								identn->accept(*visitor); cout << endl;
								Node *argsn = (yyvsp[(1) - (3)].nodo);
								argsn->addLChild(identn);
								argsn->accept(*visitor); cout << endl;
								(yyval.nodo) = argsn;
							}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1058 "pysin.y"
    {
								Node *argsn = asTree->bArgsNode();
								argsn->accept(*visitor); cout << endl;
								(yyval.nodo) = argsn;
							}
    break;



/* Line 1806 of yacc.c  */
#line 3657 "pysin.cpp"
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
#line 1063 "pysin.y"



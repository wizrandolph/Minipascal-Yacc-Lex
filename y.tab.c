/* A Bison parser, made by GNU Bison 3.6.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "pascal_yacc.y"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "ast.h"
#include "ir.h"
#include "table.h"
#include "lex.yy.h"

#define MAXMEMBER 200
int yyerror(char*);

extern int VarCount;
extern table_variable VarList[TABLE_MAX_VAR_NUM];

extern int count;
extern int NXQ;
extern char str_lex[20];
extern int line_no;
extern struct node ast_root;
extern char str_extern[20];
int flag_var_def = 0;


#line 99 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 601,                 /* "invalid token"  */
    Iden = 300,                    /* Iden  */
    UnsignedIntNo = 301,           /* UnsignedIntNo  */
    UnsignedRealNo = 302,          /* UnsignedRealNo  */
    Program = 400,                 /* Program  */
    Begin = 401,                   /* Begin  */
    End = 402,                     /* End  */
    Var = 403,                     /* Var  */
    Integer = 404,                 /* Integer  */
    Real = 405,                    /* Real  */
    While = 406,                   /* While  */
    Do = 407,                      /* Do  */
    If = 408,                      /* If  */
    Then = 409,                    /* Then  */
    Else = 410,                    /* Else  */
    Or = 411,                      /* Or  */
    And = 412,                     /* And  */
    Not = 413,                     /* Not  */
    Of = 414,                      /* Of  */
    Array = 415,                   /* Array  */
    LE = 500,                      /* LE  */
    GE = 501,                      /* GE  */
    NE = 502,                      /* NE  */
    AssignOp = 503,                /* AssignOp  */
    DotDot = 504,                  /* DotDot  */
    PtrArrow = 505,                /* PtrArrow  */
    ErrorChar = 600,               /* ErrorChar  */
    UMINUS = 602                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 601
#define Iden 300
#define UnsignedIntNo 301
#define UnsignedRealNo 302
#define Program 400
#define Begin 401
#define End 402
#define Var 403
#define Integer 404
#define Real 405
#define While 406
#define Do 407
#define If 408
#define Then 409
#define Else 410
#define Or 411
#define And 412
#define Not 413
#define Of 414
#define Array 415
#define LE 500
#define GE 501
#define NE 502
#define AssignOp 503
#define DotDot 504
#define PtrArrow 505
#define ErrorChar 600
#define UMINUS 602

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "pascal_yacc.y"

 struct {
	 union{
		 int Iv;
		 int CH;
		 int NO;
		 struct { int TC,FC;} _BExpr;
		 struct { int QUAD,CH;} _WBD;
		 struct { int type,place; union{int Iv;float Rv;} Value;} _Expr;
		 char _Rop[5];
		 int First;	
		 char str[20];//连续定义时，符号链的头指针（在符号表中的序号）
		 //该定义用来区别在图中生成的节点的名称
		 /*
		  *var是简单变量时，place:变量在符号表中的序号；offset:0
		  *var是下标变量时，place:存放constpart临时变量地址（在表中的序号），offset:存放varpart临时变量地址（在表中的序号）
		  */
		 struct { int PLACE, OFFSET;} _Var;
		 /*
		  *NO：数组名在符号表中的序号
		  *DIM：用于记录已处理数组下标表达式的个数（最后值代表维数）
		  *place:在计算varpart时，记录存放中间结果的临时变量名（地址）
		  */ 
		 struct { int NO, DIM, PLACE;} _Elist;
		 struct { int QUAD,CH,place;} _Loop;
	 } attr;
	 int B; int E;//记录某个语块的起始和结尾
 	struct node *Node;
 } ast_node;
 char str[20];

#line 241 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Iden = 3,                       /* Iden  */
  YYSYMBOL_UnsignedIntNo = 4,              /* UnsignedIntNo  */
  YYSYMBOL_UnsignedRealNo = 5,             /* UnsignedRealNo  */
  YYSYMBOL_Program = 6,                    /* Program  */
  YYSYMBOL_Begin = 7,                      /* Begin  */
  YYSYMBOL_End = 8,                        /* End  */
  YYSYMBOL_Var = 9,                        /* Var  */
  YYSYMBOL_Integer = 10,                   /* Integer  */
  YYSYMBOL_Real = 11,                      /* Real  */
  YYSYMBOL_While = 12,                     /* While  */
  YYSYMBOL_Do = 13,                        /* Do  */
  YYSYMBOL_If = 14,                        /* If  */
  YYSYMBOL_Then = 15,                      /* Then  */
  YYSYMBOL_Else = 16,                      /* Else  */
  YYSYMBOL_Or = 17,                        /* Or  */
  YYSYMBOL_And = 18,                       /* And  */
  YYSYMBOL_Not = 19,                       /* Not  */
  YYSYMBOL_Of = 20,                        /* Of  */
  YYSYMBOL_Array = 21,                     /* Array  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_AssignOp = 25,                  /* AssignOp  */
  YYSYMBOL_DotDot = 26,                    /* DotDot  */
  YYSYMBOL_PtrArrow = 27,                  /* PtrArrow  */
  YYSYMBOL_ErrorChar = 28,                 /* ErrorChar  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_UMINUS = 40,                    /* UMINUS  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_ProgDef = 46,                   /* ProgDef  */
  YYSYMBOL_SubProg = 47,                   /* SubProg  */
  YYSYMBOL_VarDef = 48,                    /* VarDef  */
  YYSYMBOL_VarDefList = 49,                /* VarDefList  */
  YYSYMBOL_VarDefState = 50,               /* VarDefState  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_VarList = 52,                   /* VarList  */
  YYSYMBOL_StateList = 53,                 /* StateList  */
  YYSYMBOL_S_L = 54,                       /* S_L  */
  YYSYMBOL_Statement = 55,                 /* Statement  */
  YYSYMBOL_CompStatement = 56,             /* CompStatement  */
  YYSYMBOL_AsignStatement = 57,            /* AsignStatement  */
  YYSYMBOL_ISE = 58,                       /* ISE  */
  YYSYMBOL_IBT = 59,                       /* IBT  */
  YYSYMBOL_WBD = 60,                       /* WBD  */
  YYSYMBOL_Wh = 61,                        /* Wh  */
  YYSYMBOL_BoolExpr = 62,                  /* BoolExpr  */
  YYSYMBOL_Expr = 63,                      /* Expr  */
  YYSYMBOL_ExprList = 64,                  /* ExprList  */
  YYSYMBOL_Variable = 65,                  /* Variable  */
  YYSYMBOL_ArrayVar = 66,                  /* ArrayVar  */
  YYSYMBOL_ArrayLeft = 67,                 /* ArrayLeft  */
  YYSYMBOL_UnsignedConst = 68,             /* UnsignedConst  */
  YYSYMBOL_RelationOp = 69                 /* RelationOp  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

#define YYMAXUTOK   602


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
      38,    36,    34,    32,    44,    33,    42,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
      29,    31,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    39,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    24,    25,    26,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,    40
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   145,   145,   168,   183,   198,   211,   222,   263,   284,
     300,   315,   330,   343,   356,   368,   381,   394,   429,   441,
     454,   465,   471,   487,   518,   538,   556,   572,   587,   603,
     618,   632,   648,   659,   672,   685,   698,   710,   717,   729,
     749,   764,   774,   794,   808,   816,   827,   849,   870,   891,
     913,   924,   934,   943,   952,   961
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
  "\"end of file\"", "error", "\"invalid token\"", "Iden",
  "UnsignedIntNo", "UnsignedRealNo", "Program", "Begin", "End", "Var",
  "Integer", "Real", "While", "Do", "If", "Then", "Else", "Or", "And",
  "Not", "Of", "Array", "LE", "GE", "NE", "AssignOp", "DotDot", "PtrArrow",
  "ErrorChar", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "')'",
  "'['", "'('", "']'", "UMINUS", "';'", "'.'", "':'", "','", "$accept",
  "ProgDef", "SubProg", "VarDef", "VarDefList", "VarDefState", "Type",
  "VarList", "StateList", "S_L", "Statement", "CompStatement",
  "AsignStatement", "ISE", "IBT", "WBD", "Wh", "BoolExpr", "Expr",
  "ExprList", "Variable", "ArrayVar", "ArrayLeft", "UnsignedConst",
  "RelationOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   601,   300,   301,   302,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   500,   501,   502,   503,   504,   505,   600,    60,
      62,    61,    43,    45,    42,    47,    41,    91,    40,    93,
     602,    59,    46,    58,    44
};
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    26,    31,    -1,   -39,    54,    72,    23,    76,   -39,
      66,   -39,    11,    -6,    77,    62,    17,   -39,    18,   -39,
      72,    13,    72,   -39,     9,     9,   -39,   -39,   -39,    95,
     106,   -39,     3,    -4,    18,   -39,   -39,   -39,    18,    18,
      18,     3,   -20,   -39,    79,   -39,    77,   -39,   -39,     9,
       9,    63,    77,   -39,    63,   -39,    92,     3,     3,    91,
      70,   -39,   -39,   -39,   -39,   101,   -39,    -2,     9,   106,
     -39,    35,     9,     9,     9,     9,   106,   -39,    -8,    55,
     -39,     3,     3,   -39,   -39,   -39,   -39,   -39,   -39,     9,
     -39,   -39,    63,    93,   -39,    78,    78,   -39,   -39,   -39,
     -39,   102,   -39,    63,   106,   -39
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,    43,
       0,     6,     0,     0,    12,     0,     0,     2,    21,     3,
       4,     0,     0,    44,     0,     0,     9,    10,     8,     0,
       0,    27,     0,     0,    21,    14,    20,    16,    21,    21,
      21,     0,     0,     5,     0,     7,    11,    48,    49,     0,
       0,    42,    39,    40,    41,    45,     0,     0,     0,     0,
       0,    22,    15,    13,    17,    18,    19,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      25,     0,     0,    55,    53,    54,    50,    51,    52,     0,
      24,    26,    23,     0,    37,    33,    34,    35,    36,    47,
      32,    30,    29,    28,     0,    46
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   103,   100,   -39,   -39,   -39,
      19,   114,   -39,   -39,   -39,   -39,   -39,   -38,   -23,   -39,
      42,   -39,   -39,   -30,   -39
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    10,    11,    28,    12,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    59,    60,    13,
      52,    15,    16,    53,    89
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    51,    54,    67,    61,    68,     9,    47,    48,    81,
      82,    91,     9,    47,    48,    81,    82,    25,     1,    77,
      78,     9,    57,    26,    27,    18,    70,    71,   100,     3,
      31,     4,    32,    23,    44,    79,    49,    62,    24,    93,
       5,    58,    49,   101,   102,    92,    99,    50,    14,    95,
      96,    97,    98,    63,    21,    22,    29,    64,    65,    66,
      42,    30,    14,     6,    46,    17,   103,    72,    73,    74,
      75,    94,    26,    27,   105,     9,    42,    83,    84,    85,
      42,    42,    42,    18,    86,    87,    88,    72,    73,    74,
      75,    94,    83,    84,    85,    72,    73,    74,    75,    86,
      87,    88,    72,    73,    74,    75,    80,    20,    81,    82,
      47,    48,    74,    75,    25,    55,    69,    90,    76,   104,
      82,    45,    19,    43
};

static const yytype_int8 yycheck[] =
{
      30,    24,    25,    41,     8,    25,     3,     4,     5,    17,
      18,    13,     3,     4,     5,    17,    18,    37,     6,    57,
      58,     3,    19,    10,    11,     7,    49,    50,    36,     3,
      12,     0,    14,    39,    21,    58,    33,    41,    44,    69,
      41,    38,    33,    81,    82,    68,    76,    38,     6,    72,
      73,    74,    75,    34,    43,    44,    39,    38,    39,    40,
      18,    44,    20,     9,    22,    42,    89,    32,    33,    34,
      35,    36,    10,    11,   104,     3,    34,    22,    23,    24,
      38,    39,    40,     7,    29,    30,    31,    32,    33,    34,
      35,    36,    22,    23,    24,    32,    33,    34,    35,    29,
      30,    31,    32,    33,    34,    35,    15,    41,    17,    18,
       4,     5,    34,    35,    37,    20,    37,    16,    26,    26,
      18,    21,     8,    20
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    46,     3,     0,    41,     9,    47,    48,     3,
      49,    50,    52,    64,    65,    66,    67,    42,     7,    56,
      41,    43,    44,    39,    44,    37,    10,    11,    51,    39,
      44,    12,    14,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    65,    50,    21,    51,    65,     4,     5,    33,
      38,    63,    65,    68,    63,    20,    68,    19,    38,    62,
      63,     8,    41,    55,    55,    55,    55,    62,    25,    37,
      63,    63,    32,    33,    34,    35,    26,    62,    62,    63,
      15,    17,    18,    22,    23,    24,    29,    30,    31,    69,
      16,    13,    63,    68,    36,    63,    63,    63,    63,    68,
      36,    62,    62,    63,    26,    68
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    55,    55,    55,    55,
      55,    55,    56,    57,    58,    59,    60,    61,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     3,     3,     1,     3,     2,     1,
       1,     3,     1,     2,     1,     2,     1,     2,     2,     2,
       1,     0,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     3,     3,     1,     2,     3,     7,     5,     1,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 146 "pascal_yacc.y"
          {
			// ProgDef: Program Iden ';' SubProg '.'
			// 文法符号Program对应关键字"program"，程序
			//debug
			//printf("yacc program\n");
			//ast
			struct node *tmp_node = NULL;
			tmp_node = (yyvsp[-1].ast_node).Node;
			ast_root.seq = count + 1;
			new_node(&((yyval.ast_node).Node));
			set_node_var_str(&ast_root, "Root");
			(yyval.ast_node).Node->type = e_program;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "ProgDef");
			add_son_node(&ast_root, (yyval.ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			system("pause");
			init_astgraph(&ast_root);
			printf("\n***********************COMPILED SUCCESSFULLY**********************\n");
			  
          }
#line 1421 "y.tab.c"
    break;

  case 3:
#line 169 "pascal_yacc.y"
                {
			// SubProg: VarDef CompStatement
			//debug
			printf("yacc subprog\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_sub_prog;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "SubProg");
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			
		}
#line 1439 "y.tab.c"
    break;

  case 4:
#line 184 "pascal_yacc.y"
        {
			// VarDef:	Var VarDefList ';'
			// 变量声明
			//debug
			printf("yacc vardef\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_var_def;
			set_node_var_str((yyval.ast_node).Node, "Var");
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			
		}
#line 1457 "y.tab.c"
    break;

  case 5:
#line 199 "pascal_yacc.y"
        {
			// VarDefList : VarDefList ';' VarDefState
			// 不同类型的多个变量声明
			//debug
			printf("yacc vardeflist\n");
			//ast
			struct node *last_node = get_last_node((yyvsp[-2].ast_node).Node);
			add_brother_node((yyvsp[-2].ast_node).Node, (yyvsp[0].ast_node).Node);
			if((yyvsp[0].ast_node).Node)
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
			
		}
#line 1474 "y.tab.c"
    break;

  case 6:
#line 212 "pascal_yacc.y"
            {
			// VarDefList : VarDefState
			//debug
			printf("yacc vardeflist2\n");
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			
			
        }
#line 1488 "y.tab.c"
    break;

  case 7:
#line 223 "pascal_yacc.y"
                {
			// VarDefState: VarList ':' Type
			// VarList记录的多个
			//变量指定类型
			//debug
			printf("yacc vardefstate\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, "VarDefState");
			(yyvsp[-2].ast_node).Node->type = e_varlist;
			(yyval.ast_node).Node->seq = count++;
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			//table
			struct node* tmpnode = (yyvsp[-2].ast_node).Node;
			while(tmpnode->next != NULL)				//这里type的语法树节点不能串入符号表中，与数组不同
			{
				(yyval.ast_node).attr._Expr.place = entry(tmpnode->val.str);
				VarList[(yyval.ast_node).attr._Expr.place].type = (yyvsp[0].ast_node).Node->type-4;
				if(VarList[(yyval.ast_node).attr._Expr.place].defined == 1){
					yyerror("\n***************ALREADY DEFINED VARIABLE******************\n");
					return 0;
				}
					
				VarList[(yyval.ast_node).attr._Expr.place].defined = 1;
				tmpnode = tmpnode->next;
			}
			//ir
			int check = 0;
			while ((yyvsp[-2].ast_node).attr.First) {
				VarList[(yyvsp[-2].ast_node).attr.First].type = (yyvsp[0].ast_node).attr.Iv;
				(yyvsp[-2].ast_node).attr.First = VarList[(yyvsp[-2].ast_node).attr.First].addr;

				if(check++ > MAXMEMBER) {
					printf("** overdefine variable **\n");
					exit(0);
				}
			}
			
		}
#line 1533 "y.tab.c"
    break;

  case 8:
#line 264 "pascal_yacc.y"
                {
			//debug
			printf("vardefstate array\n");
			//
			struct node *tmpnode = (yyvsp[-1].ast_node).Node;
			while(tmpnode != NULL)
			{
				int place = entry(tmpnode->val.str);
				VarList[place].type = (yyvsp[0].ast_node).Node->type-2;
				if(VarList[place].defined == 1){
					yyerror("\n***************ALREADY DEFINED VARIABLE******************\n");
					return 0;
				}
				VarList[place].defined = 1;
				tmpnode = tmpnode->next;
				printf("yacc array while\n");
			}

		}
#line 1557 "y.tab.c"
    break;

  case 9:
#line 285 "pascal_yacc.y"
                {
			// Type: Integer
			// 整数类型
			//debug
			printf("yacc type\n");
			//ir
			(yyval.ast_node).attr.Iv = 0;
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_type_int;
			set_node_var_str((yyval.ast_node).Node,  "Integer");
			

		}
#line 1577 "y.tab.c"
    break;

  case 10:
#line 301 "pascal_yacc.y"
                {
			// 实数类型
			//debug
			printf("yacc type\n");
			//ir
			(yyval.ast_node).attr.Iv = 1;
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_type_real;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "Real");
			
		}
#line 1595 "y.tab.c"
    break;

  case 11:
#line 316 "pascal_yacc.y"
                {
			// VarList:	VarList ',' Variable
			// 同一类型的多个变量通过逗号分割
			//debug
			printf("yacc varlist1\n");
			//ir
			(yyval.ast_node).attr.First = (yyvsp[0].ast_node).attr._Var.PLACE;
			VarList[(yyvsp[0].ast_node).attr._Var.PLACE].addr = (yyvsp[-2].ast_node).attr.First;
			//ast
			struct node *last_node = get_last_node((yyvsp[-2].ast_node).Node);
			add_brother_node(last_node, (yyvsp[0].ast_node).Node);
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
			
		}
#line 1614 "y.tab.c"
    break;

  case 12:
#line 331 "pascal_yacc.y"
                {
			// VarList:	Variable
			//debug
			printf("yacc varlist2\n");
			//ir
			(yyval.ast_node).attr.First = (yyvsp[0].ast_node).attr._Var.PLACE;
			VarList[(yyvsp[0].ast_node).attr._Var.PLACE].addr = 0;
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			
		}
#line 1630 "y.tab.c"
    break;

  case 13:
#line 344 "pascal_yacc.y"
                {
			// StateList:	S_L Statement
			//debug
			printf("yacc statelist1\n");
			//ir
			(yyval.ast_node).attr.CH = (yyvsp[0].ast_node).attr.CH;
			//ast
			struct node *last_node = get_last_node((yyvsp[-1].ast_node).Node);
			add_brother_node(last_node, (yyvsp[0].ast_node).Node);
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			
		}
#line 1647 "y.tab.c"
    break;

  case 14:
#line 357 "pascal_yacc.y"
                {
			// StateList:	Statement
			//debug
			printf("yacc statelist2\n");
			//ir
			(yyval.ast_node).attr.CH = (yyvsp[0].ast_node).attr.CH;
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			
		}
#line 1662 "y.tab.c"
    break;

  case 15:
#line 369 "pascal_yacc.y"
                {
			// S_L:	StateList ';'
			// 多个语句之间通过分号分割
			//debug
			printf("yacc s_l\n");
			//ir
			//backPatch($1.attr.CH, NXQ);
			//ast
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			
		}
#line 1678 "y.tab.c"
    break;

  case 16:
#line 382 "pascal_yacc.y"
                {
			// Statement:	AsignStatement
			// 赋值语句是句子的一种
			//debug
			printf("yacc statement\n");
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			//ir
			//$$.attr.CH = $1.attr.CH;
			
			
		}
#line 1695 "y.tab.c"
    break;

  case 17:
#line 395 "pascal_yacc.y"
                {
			// If Else语句是句子的一种,ISE=IF+STATEMENT+ELSE, Statement是else后的语句
			//debug
			printf("yacc statement ise\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node,"ISES");
			(yyval.ast_node).Node->seq = count++;

			struct node *tmpif;
			new_node(&(tmpif));
			add_son_node((yyval.ast_node).Node, tmpif);
			tmpif->seq = count++;
			set_node_var_str(tmpif, "If");
			add_son_node(tmpif, (yyvsp[-1].ast_node).Node->son->son);

			struct node *tmpthen;
			new_node(&(tmpthen));
			add_son_node((yyval.ast_node).Node, tmpthen);
			tmpthen->seq = count++;
			set_node_var_str(tmpthen, "Then");
			add_son_node(tmpthen, (yyvsp[-1].ast_node).Node->son->next);

			struct node *tmpelse;
			new_node(&(tmpelse));
			add_son_node((yyval.ast_node).Node, tmpelse);
			tmpelse->seq = count++;
			set_node_var_str(tmpelse, "Else");
			add_son_node(tmpelse, (yyvsp[0].ast_node).Node);

			//ir
			//$$.attr.CH = merge($1.attr.CH, $2.attr.CH);
			
		}
#line 1734 "y.tab.c"
    break;

  case 18:
#line 430 "pascal_yacc.y"
                {
			// If then语句是句子的一种IBT=IF+BOOL+THEN
			//debug
			printf("yacc statement ibt\n");
			//ast
			add_son_node((yyvsp[-1].ast_node).Node, (yyvsp[0].ast_node).Node);
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			//ir
			//$$.attr.CH = merge($1.attr.CH, $2.attr.CH);
		}
#line 1749 "y.tab.c"
    break;

  case 19:
#line 442 "pascal_yacc.y"
                {
			// While语句是句子的一种
			//debug
			printf("yacc statement wbd\n");
			//ast
			add_son_node((yyvsp[-1].ast_node).Node, (yyvsp[0].ast_node).Node);
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			//ir
			backPatch((yyvsp[-1].ast_node).attr._WBD.CH, NXQ+1);			//把
			gen("j", 0, 0, (yyvsp[-1].ast_node).attr._WBD.QUAD);					//跳回while循环
			(yyval.ast_node).attr.CH = (yyvsp[-1].ast_node).attr._WBD.CH;
		}
#line 1766 "y.tab.c"
    break;

  case 20:
#line 455 "pascal_yacc.y"
            {
			// Begin End语句块
			//debug
			printf("yacc statement compstatement\n");
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			//ir
			(yyval.ast_node).attr.CH = (yyvsp[0].ast_node).attr.CH;
			
		}
#line 1781 "y.tab.c"
    break;

  case 21:
#line 465 "pascal_yacc.y"
                {
			// Statement : 
			//debug
			printf("yacc statement\n");
	    }
#line 1791 "y.tab.c"
    break;

  case 22:
#line 472 "pascal_yacc.y"
                {
			// CompStatement:	Begin StateList End
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
			//debug
			printf("yacc compstatement\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_compstat;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "begin_end");
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			//ir
			(yyval.ast_node).attr.CH = (yyvsp[-1].ast_node).attr.CH;
		}
#line 1810 "y.tab.c"
    break;

  case 23:
#line 488 "pascal_yacc.y"
                {
			// AsignStatement:	Variable AssignOp  Expr
			// 赋值语句
			//debug
			printf("yacc asignstatement\n");
			//table
			if( VarList[(yyvsp[-2].ast_node).attr._Var.PLACE].defined == 0 )
			{
				yyerror("Unclared Variable:");
				printf("%s !\n",(yyvsp[-2].ast_node).Node->val.str);
				return 0;
			}
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_assign_stat;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, ":=");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			
			//ir
			if (!(yyvsp[-2].ast_node).attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
				gen(":=", (yyvsp[0].ast_node).attr._Expr.place, 0, (yyvsp[-2].ast_node).attr._Var.PLACE);
			} else {  /*OFFSET不为0，下标变量*/ 
				gen("[]=", (yyvsp[0].ast_node).attr._Expr.place, 0, (yyvsp[-2].ast_node).attr._Var.PLACE);
			}
			(yyval.ast_node).attr.CH = (yyvsp[-2].ast_node).attr._Var.PLACE;
		}
#line 1843 "y.tab.c"
    break;

  case 24:
#line 519 "pascal_yacc.y"
                {
			// If Else语句
			//debug
			printf("yacc ise\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_if_then_else_stat;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "if_then");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			printf("yacc ise\n");
			//ir
			//int q = NXQ;
			//gen("j", 0, 0, 0);
			backPatch((yyvsp[-2].ast_node).attr._BExpr.FC, NXQ);
			//$$.attr.CH = merge($2.attr.CH, q);
		}
#line 1866 "y.tab.c"
    break;

  case 25:
#line 539 "pascal_yacc.y"
                {
			// If Then 语句
			//debug
			printf("yacc ibt\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_if_then_stat;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "if_then");
			add_son_node((yyval.ast_node).Node, (yyvsp[-1].ast_node).Node);
			//ir
			(yyval.ast_node).attr.CH = (yyvsp[-1].ast_node).attr._BExpr.FC;
			
		}
#line 1885 "y.tab.c"
    break;

  case 26:
#line 557 "pascal_yacc.y"
                {
			// while循环
			//debug
			printf("yacc wbd\n");
			//ast
			add_son_node((yyvsp[-2].ast_node).Node, (yyvsp[-1].ast_node).Node);
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
			//ir
			backPatch((yyvsp[-1].ast_node).attr._BExpr.TC, NXQ);
			setJump((yyvsp[-1].ast_node).attr._BExpr.FC, 0);
			(yyval.ast_node).attr._WBD.CH = (yyvsp[-1].ast_node).attr._BExpr.FC;
			(yyval.ast_node).attr._WBD.QUAD = (yyvsp[-2].ast_node).attr.CH;
		}
#line 1903 "y.tab.c"
    break;

  case 27:
#line 573 "pascal_yacc.y"
        {
			// 文法符号While对应关键字"while"
			//debug
			printf("yacc wh\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type =e_while_stat;
			set_node_var_str((yyval.ast_node).Node, "while");
			(yyval.ast_node).Node->seq = count++;
			//ir
			(yyval.ast_node).attr.CH = NXQ;
        }
#line 1920 "y.tab.c"
    break;

  case 28:
#line 588 "pascal_yacc.y"
                {
			// 布尔表达式
			//debug
			printf("yacc boolexpr1\n");
			//ast
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			(yyval.ast_node).Node->type = e_bool_exp;
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			//ir
			(yyval.ast_node).attr._BExpr.TC = NXQ;
			(yyval.ast_node).attr._BExpr.FC = NXQ+1;
			gen((yyvsp[-1].ast_node).attr._Rop, (yyvsp[-2].ast_node).attr._Expr.place, (yyvsp[0].ast_node).attr._Expr.place, 0);	//NXQ
			gen("j", 0, 0, NXQ+1);											//NXQ+1
		}
#line 1940 "y.tab.c"
    break;

  case 29:
#line 604 "pascal_yacc.y"
                {	
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "BoolexprAnd");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			printf("yacc boolexpr2\n");
			//ir
			printf("%d %d\n",(yyvsp[-2].ast_node).attr._BExpr.FC, (yyvsp[0].ast_node).attr._BExpr.FC);
			(yyval.ast_node).attr._BExpr.FC=merge((yyvsp[-2].ast_node).attr._BExpr.FC, (yyvsp[0].ast_node).attr._BExpr.FC);
			(yyval.ast_node).attr._BExpr.TC=NXQ;
			setJump((yyvsp[-2].ast_node).attr._BExpr.TC, (yyvsp[0].ast_node).attr._BExpr.TC);
		}
#line 1959 "y.tab.c"
    break;

  case 30:
#line 619 "pascal_yacc.y"
                {
			//debug
			printf("yacc boolepxr3\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "BoolexprOr");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			//ir
			(yyval.ast_node).attr._BExpr.TC=merge((yyvsp[-2].ast_node).attr._BExpr.TC, (yyvsp[0].ast_node).attr._BExpr.TC);
			(yyval.ast_node).attr._BExpr.FC=(yyvsp[0].ast_node).attr._BExpr.FC;
		}
#line 1977 "y.tab.c"
    break;

  case 31:
#line 633 "pascal_yacc.y"
                {
			//debug
			printf("yacc boolexpr4\n");
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_bool_exp;
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, "Not");
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			
			//ir
			(yyval.ast_node).attr._BExpr.TC = (yyvsp[0].ast_node).attr._BExpr.FC;
			(yyval.ast_node).attr._BExpr.FC = (yyvsp[0].ast_node).attr._BExpr.TC;
			
		}
#line 1997 "y.tab.c"
    break;

  case 32:
#line 649 "pascal_yacc.y"
                {
			//ast
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
			printf("yacc boolexpr5\n");
			//ir
			(yyval.ast_node).attr._BExpr.TC = (yyvsp[-1].ast_node).attr._BExpr.TC;
			(yyval.ast_node).attr._BExpr.FC = (yyvsp[-1].ast_node).attr._BExpr.FC;
		}
#line 2010 "y.tab.c"
    break;

  case 33:
#line 660 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = newTemp();
			gen("+", (yyvsp[-2].ast_node).attr._Expr.place, (yyvsp[0].ast_node).attr._Expr.place, (yyval.ast_node).attr._Expr.place);
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_exp;
			set_node_var_str((yyval.ast_node).Node, "+");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
		}
#line 2027 "y.tab.c"
    break;

  case 34:
#line 673 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = newTemp();
			gen("-", (yyvsp[-2].ast_node).attr._Expr.place, (yyvsp[0].ast_node).attr._Expr.place, (yyval.ast_node).attr._Expr.place);
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_exp;
			set_node_var_str((yyval.ast_node).Node, "-");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
		}
#line 2044 "y.tab.c"
    break;

  case 35:
#line 686 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = newTemp();
			gen("*", (yyvsp[-2].ast_node).attr._Expr.place, (yyvsp[0].ast_node).attr._Expr.place, (yyval.ast_node).attr._Expr.place);
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_exp;
			set_node_var_str((yyval.ast_node).Node, "*");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
		}
#line 2061 "y.tab.c"
    break;

  case 36:
#line 699 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = newTemp();
			gen("/", (yyvsp[-2].ast_node).attr._Expr.place, (yyvsp[0].ast_node).attr._Expr.place, (yyval.ast_node).attr._Expr.place);
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->type = e_exp;
			set_node_var_str((yyval.ast_node).Node, "/");
			add_son_node((yyval.ast_node).Node, (yyvsp[-2].ast_node).Node);
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
		}
#line 2077 "y.tab.c"
    break;

  case 37:
#line 711 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = (yyvsp[-1].ast_node).attr._Expr.place;
			//ast
			(yyval.ast_node).Node = (yyvsp[-1].ast_node).Node;
		}
#line 2088 "y.tab.c"
    break;

  case 38:
#line 718 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.place = newTemp();
			gen("-", (yyvsp[0].ast_node).attr._Expr.place, 0, (yyval.ast_node).attr._Expr.place);
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			(yyval.ast_node).Node->type = e_exp;
			set_node_var_str((yyval.ast_node).Node, "-");
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
		}
#line 2104 "y.tab.c"
    break;

  case 39:
#line 730 "pascal_yacc.y"
                {
			//ir
			if(!(yyvsp[0].ast_node).attr._Var.OFFSET)
				(yyval.ast_node).attr._Expr.place = (yyvsp[0].ast_node).attr._Var.PLACE;
			else
				{
					int T = newTemp();
					gen("=[]", (yyvsp[0].ast_node).attr._Var.PLACE, 0, T);
					(yyval.ast_node).attr._Expr.place = T;
				}
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
			//error	这种写法将所有定义或未定义的变量全部存放于符号表中 
			if(VarList[(yyvsp[0].ast_node).attr._Var.PLACE].defined == 0) {
				yyerror("\nUndefined Variable :");
				printf("%s\n", VarList[(yyvsp[0].ast_node).attr._Var.PLACE].name);
				return 0;
			}
		}
#line 2128 "y.tab.c"
    break;

  case 40:
#line 750 "pascal_yacc.y"
                {
			//ir
			(yyval.ast_node).attr._Expr.type = (yyvsp[0].ast_node).attr._Expr.type;
			(yyval.ast_node).attr._Expr.place = (yyvsp[0].ast_node).attr._Expr.place;
			if ((yyval.ast_node).attr._Expr.type) {
				(yyval.ast_node).attr._Expr.Value.Rv = (yyvsp[0].ast_node).attr._Expr.Value.Rv;
			} else {
				(yyval.ast_node).attr._Expr.Value.Iv = (yyvsp[0].ast_node).attr._Expr.Value.Iv;
			}
			//ast
			(yyval.ast_node).Node = (yyvsp[0].ast_node).Node;
		}
#line 2145 "y.tab.c"
    break;

  case 41:
#line 765 "pascal_yacc.y"
                {
			//debug
			printf("ExprList1\n");
			(yyval.ast_node).attr._Elist.PLACE = (yyvsp[-2].ast_node).attr._Expr.place;
			(yyval.ast_node).attr._Elist.DIM = 1;
			(yyval.ast_node).attr._Elist.NO = (yyvsp[-2].ast_node).attr._Var.PLACE;
			//ast
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
		}
#line 2159 "y.tab.c"
    break;

  case 42:
#line 775 "pascal_yacc.y"
                {
			//debug
			printf("ExprList2\n");
			char num[5];
			int k,d;
			int T = newTemp();
			k = (yyvsp[-2].ast_node).attr._Elist.DIM + 1;
			d = Access_d((yyvsp[-2].ast_node).attr._Elist.NO, k);
			sprintf(num, "%d", d);	//将d转化为字符形式，结果存在num
			gen("*", (yyvsp[-2].ast_node).attr._Elist.PLACE, entry(num), T);
			gen("+", (yyvsp[0].ast_node).attr._Expr.place, T, T); 					//相当于VARPART=VARPART*d+ik
			(yyval.ast_node).attr._Elist.NO = (yyvsp[-2].ast_node).attr._Elist.NO;;					//传递Entry(iden)
			(yyval.ast_node).attr._Elist.PLACE = T;								//传递存放VARPART中间结果的T
			(yyval.ast_node).attr._Elist.DIM = k;
			//ast
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
			//
		}
#line 2182 "y.tab.c"
    break;

  case 43:
#line 795 "pascal_yacc.y"
                {
			// Variable: Iden
			// 文法符号Iden对应标识符，以字母或下划线开头后面是字母、数字或下划线组成的符号串
			//debug
			printf("yacc Variable1\n");
			//table
			(yyval.ast_node).attr._Var.PLACE = entry(yylval.str);
			(yyval.ast_node).attr._Var.OFFSET = 0;
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, yylval.str);
		}
#line 2200 "y.tab.c"
    break;

  case 44:
#line 809 "pascal_yacc.y"
                {
			//debug
			printf("yacc Variable2\n");
			//ast

		}
#line 2211 "y.tab.c"
    break;

  case 45:
#line 817 "pascal_yacc.y"
                {
			//debug
			printf("yacc ArrayVar\n");
			//
			(yyval.ast_node).attr._Expr.place = (yyvsp[-2].ast_node).attr._Expr.place;
			//ast
			(yyval.ast_node).Node = (yyvsp[-2].ast_node).Node;
			printf("%s\n",(yyval.ast_node).Node->val.str);
		}
#line 2225 "y.tab.c"
    break;

  case 46:
#line 828 "pascal_yacc.y"
                {
			//debug
			printf("arrayleft1\n");
			//一维数组
			int NO = (yyval.ast_node).attr.NO;
			int low = (yyvsp[-2].ast_node).attr._Expr.Value.Iv, high = (yyvsp[0].ast_node).attr._Expr.Value.Iv;
			(yyval.ast_node).attr.NO = (yyvsp[-6].ast_node).attr.First;	//连续定义的情形
			//
			(yyval.ast_node).attr._Expr.place = (yyvsp[-6].ast_node).attr.First;

			//内情向量表的构造
			VarList[NO].arrayaddr = malloc(sizeof(struct arr_info));
			VarList[NO].arrayaddr->DIM = 1;
			VarList[NO].arrayaddr->Vector = malloc(5*sizeof(int));		
			VarList[NO].arrayaddr->Vector[2] = low;
			VarList[NO].arrayaddr->Vector[3] = high;
			VarList[NO].arrayaddr->Vector[4] = (high - low) + 1;

			//ast
			(yyval.ast_node).Node = (yyvsp[-6].ast_node).Node;
		}
#line 2251 "y.tab.c"
    break;

  case 47:
#line 850 "pascal_yacc.y"
                {
			//多维数组
			//debug
			printf("arrayleft2\n");
			int NO = (yyvsp[-4].ast_node).attr.NO;
			int dim = VarList[NO].arrayaddr->DIM+1;
			int low = (yyvsp[-2].ast_node).attr._Expr.Value.Iv, high = (yyvsp[0].ast_node).attr._Expr.Value.Iv;
			(yyval.ast_node).attr.NO = NO;

			//内情向量表的构造			
			VarList[NO].arrayaddr->DIM++;
			VarList[NO].arrayaddr->Vector = realloc(VarList[NO].arrayaddr->Vector, (3 * dim + 2) * sizeof(int));
			VarList[NO].arrayaddr->Vector[3*dim - 1] = low;
			VarList[NO].arrayaddr->Vector[3*dim] = high;
			VarList[NO].arrayaddr->Vector[3*dim + 1] = (high - low) + 1;

			//ast
			(yyval.ast_node).Node = (yyvsp[-4].ast_node).Node;
		}
#line 2275 "y.tab.c"
    break;

  case 48:
#line 871 "pascal_yacc.y"
                {
			// UnsignedConst:	UnsignedIntNo
			// 常数，无符号整数
			//table
			(yyval.ast_node).attr._Expr.type = 0;						//记录常量类型
			(yyval.ast_node).attr._Expr.place = entry(str_lex);		//记录常量在字符表中的位置
			VarList[(yyval.ast_node).attr._Expr.place].type = 0;		//将字符表中该常量的类型设为INTEGER：0
			VarList[(yyval.ast_node).attr._Expr.place].defined = 1;	//常量被视为已定义
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, str_lex);
			new_node(&((yyvsp[0].ast_node).Node));
			(yyvsp[0].ast_node).Node->seq = count++;
			set_node_var_str((yyvsp[0].ast_node).Node, "UnsignedIntNo");
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			//ir
			(yyval.ast_node).attr._Expr.Value.Iv = atoi(str_lex);	//记录该常量的值

		}
#line 2300 "y.tab.c"
    break;

  case 49:
#line 892 "pascal_yacc.y"
                {
			// 常数，无符号实数
			//table
			(yyval.ast_node).attr._Expr.type = 1;						//记录常量类型
			(yyval.ast_node).attr._Expr.place = entry(yylval.str);		//记录常量在字符表中的位置
			VarList[(yyval.ast_node).attr._Expr.place].type = 1;		//将字符表中该常量的类型设为REAL：1
			VarList[(yyval.ast_node).attr._Expr.place].defined = 1;
			//ast
			new_node(&((yyval.ast_node).Node));
			(yyval.ast_node).Node->seq = count++;
			set_node_var_str((yyval.ast_node).Node, yylval.str);
			new_node(&((yyvsp[0].ast_node).Node));
			(yyvsp[0].ast_node).Node->seq = count++;
			set_node_var_str((yyvsp[0].ast_node).Node, "UnsignedRealNo");
			add_son_node((yyval.ast_node).Node, (yyvsp[0].ast_node).Node);
			printf("yacc UnsignedRealNo\n");
			//ir
			(yyval.ast_node).attr._Expr.Value.Iv = atoi(yylval.str);	//记录该常量的值
		}
#line 2324 "y.tab.c"
    break;

  case 50:
#line 914 "pascal_yacc.y"
                {
			// 小于
			//ast
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, "<");
			(yyval.ast_node).Node->seq = count++;
			printf("<\n");
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j<");
		}
#line 2339 "y.tab.c"
    break;

  case 51:
#line 925 "pascal_yacc.y"
                {
			// 大于
			//ast
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, ">");
			(yyval.ast_node).Node->seq = count++;
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j>");
		}
#line 2353 "y.tab.c"
    break;

  case 52:
#line 935 "pascal_yacc.y"
                {
			// 等于
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, "=");
			(yyval.ast_node).Node->seq = count++;
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j=");
		}
#line 2366 "y.tab.c"
    break;

  case 53:
#line 944 "pascal_yacc.y"
                {
			// 文法符号GE对应大于等于，符号串为">=
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, ">=");
			(yyval.ast_node).Node->seq = count++;
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j>=");
		}
#line 2379 "y.tab.c"
    break;

  case 54:
#line 953 "pascal_yacc.y"
                {
			// 文法符号NE对应不等于，符号串为"<>""
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, "<>");
			(yyval.ast_node).Node->seq = count++;
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j!=");
		}
#line 2392 "y.tab.c"
    break;

  case 55:
#line 962 "pascal_yacc.y"
                {
			// 文法符号LE对应小于等于，符号串为"<=""
			new_node(&((yyval.ast_node).Node));
			set_node_var_str((yyval.ast_node).Node, "<=");
			(yyval.ast_node).Node->seq = count++;
			//ir
			strcpy((yyval.ast_node).attr._Rop, "j<=");
		}
#line 2405 "y.tab.c"
    break;


#line 2409 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 971 "pascal_yacc.y"


int yyerror(char *errstr)
{
	printf("LineNo:%d, Reason:%s\n", line_no, errstr);
	return 0;
}

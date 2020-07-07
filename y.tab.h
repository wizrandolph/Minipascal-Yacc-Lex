/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

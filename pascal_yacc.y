%{
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

%}
%start    ProgDef

%union 
{
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
}


/* 注意内容 */
/* 语言不区分大小写 */

/* 指定终结符的种类，也可不指定，由yacc工具设置 */

/* 定义标识符 */
%token <str> Iden    300 /* 标识符，如变量名、程序名等 */

/* 定义常量 */
%token <ast_node> UnsignedIntNo	 301 /* 非负整数 */
%token <ast_node> UnsignedRealNo  302 /* 非负实数，小数 */

/* 定义关键字 */
%token	Program 	400 /* 关键字 program */
%token	Begin		401 /* 关键字 begin */
%token	End			402 /* 关键字 end */
%token	Var			403 /* 关键字 var */
%token	Integer 	404 /* 关键字 integer */
%token	Real		405 /* 关键字 real */
%token	While		406 /* 关键字 while */
%token	Do			407 /* 关键字 do */
%token	If			408 /* 关键字 if */
%token	Then		409 /* 关键字 then */
%token	Else		410 /* 关键字 else */
%token	Or			411 /* 关键字 or */
%token	And			412 /* 关键字 and */
%token	Not			413 /* 关键字 not */
%token  Of			414
%token  Array		415

/* 定义两个字符以上的分隔符或算符等 */
%token	LE			500  /* <= */
%token	GE			501  /* >= */
%token	NE			502  /* <> */
%token  AssignOp    503  /* := */
%token  DotDot	    504  /* .. */
%token	PtrArrow	505  /* -> */ 

/* 其它错误符号，如中文符号 */
%token	ErrorChar 	600  /* 错误符号 */

%left 	Or
%left	And
%nonassoc  	Not
%nonassoc '<' '>' '=' LE GE NE
%left '+' '-'
%left '*' '/'
%left ')' '['
%right '(' ']'
%left UMINUS

/* 文法符号的属性请根据自己的实现进行调整，这个只是简单的标记，可能存在错误，需自行调整 */
%type <ast_node> ProgDef
%type <ast_node> SubProg
%type <ast_node> VarDef
%type <ast_node> VarDefList
%type <ast_node> Type
%type <ast_node> VarDefState
%type <ast_node> VarList
%type <ast_node> Statement
%type <ast_node> StateList
%type <ast_node> S_L
%type <ast_node> CompStatement
%type <ast_node> AsignStatement
%type <ast_node> ISE
%type <ast_node> IBT
%type <ast_node> WBD
%type <ast_node> RelationOp
%type <ast_node> Expr
%type <ast_node> ExprList
%type <ast_node> Wh
%type <ast_node> Variable 
%type <ast_node> UnsignedConst 
%type <ast_node> BoolExpr
%type <ast_node> ArrayVar
%type <ast_node> ArrayLeft



%%
//程序定义，其中Program Iden为程序声明，SubProg为程序主体，'.'标志程序结束
ProgDef: Program Iden ';' SubProg '.'
          {
			// ProgDef: Program Iden ';' SubProg '.'
			// 文法符号Program对应关键字"program"，程序
			//debug
			//printf("yacc program\n");
			//ast
			struct node *tmp_node = NULL;
			tmp_node = $4.Node;
			ast_root.seq = count + 1;
			new_node(&($$.Node));
			set_node_var_str(&ast_root, "Root");
			$$.Node->type = e_program;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "ProgDef");
			add_son_node(&ast_root, $$.Node);
			add_son_node($$.Node, $4.Node);
			system("pause");
			init_astgraph(&ast_root);
			printf("\n***********************COMPILED SUCCESSFULLY**********************\n");
			  
          }
	;
SubProg: VarDef CompStatement
		{
			// SubProg: VarDef CompStatement
			//debug
			printf("yacc subprog\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_sub_prog;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "SubProg");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $2.Node);
			
		}
	;
VarDef:	Var VarDefList ';'
        {
			// VarDef:	Var VarDefList ';'
			// 变量声明
			//debug
			printf("yacc vardef\n");
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_var_def;
			set_node_var_str($$.Node, "Var");
			add_son_node($$.Node, $2.Node);
			
		}
	;
VarDefList:	VarDefList ';' VarDefState
        {
			// VarDefList : VarDefList ';' VarDefState
			// 不同类型的多个变量声明
			//debug
			printf("yacc vardeflist\n");
			//ast
			struct node *last_node = get_last_node($1.Node);
			add_brother_node($1.Node, $3.Node);
			if($3.Node)
			$$.Node = $1.Node;
			
		}
	|	VarDefState
	    {
			// VarDefList : VarDefState
			//debug
			printf("yacc vardeflist2\n");
			//ast
			$$.Node = $1.Node;
			
			
        }
	;
VarDefState: VarList ':' Type
		{
			// VarDefState: VarList ':' Type
			// VarList记录的多个
			//变量指定类型
			//debug
			printf("yacc vardefstate\n");
			//ast
			new_node(&($$.Node));
			set_node_var_str($$.Node, "VarDefState");
			$1.Node->type = e_varlist;
			$$.Node->seq = count++;
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
			//table
			struct node* tmpnode = $1.Node;
			while(tmpnode->next != NULL)				//这里type的语法树节点不能串入符号表中，与数组不同
			{
				$$.attr._Expr.place = entry(tmpnode->val.str);
				VarList[$$.attr._Expr.place].type = $3.Node->type-4;
				if(VarList[$$.attr._Expr.place].defined == 1){
					yyerror("\n***************ALREADY DEFINED VARIABLE******************\n");
					return 0;
				}
					
				VarList[$$.attr._Expr.place].defined = 1;
				tmpnode = tmpnode->next;
			}
			//ir
			int check = 0;
			while ($1.attr.First) {
				VarList[$1.attr.First].type = $3.attr.Iv;
				$1.attr.First = VarList[$1.attr.First].addr;

				if(check++ > MAXMEMBER) {
					printf("** overdefine variable **\n");
					exit(0);
				}
			}
			
		}
	|	ArrayVar Type
		{
			//debug
			printf("vardefstate array\n");
			//
			struct node *tmpnode = $1.Node;
			while(tmpnode != NULL)
			{
				int place = entry(tmpnode->val.str);
				VarList[place].type = $2.Node->type-2;
				if(VarList[place].defined == 1){
					yyerror("\n***************ALREADY DEFINED VARIABLE******************\n");
					return 0;
				}
				VarList[place].defined = 1;
				tmpnode = tmpnode->next;
				printf("yacc array while\n");
			}

		}
	;
Type: Integer
		{
			// Type: Integer
			// 整数类型
			//debug
			printf("yacc type\n");
			//ir
			$$.attr.Iv = 0;
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_type_int;
			set_node_var_str($$.Node,  "Integer");
			

		}
	|	Real
		{
			// 实数类型
			//debug
			printf("yacc type\n");
			//ir
			$$.attr.Iv = 1;
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_type_real;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "Real");
			
		}
	;
VarList:	VarList ',' Variable
		{
			// VarList:	VarList ',' Variable
			// 同一类型的多个变量通过逗号分割
			//debug
			printf("yacc varlist1\n");
			//ir
			$$.attr.First = $3.attr._Var.PLACE;
			VarList[$3.attr._Var.PLACE].addr = $1.attr.First;
			//ast
			struct node *last_node = get_last_node($1.Node);
			add_brother_node(last_node, $3.Node);
			$$.Node = $1.Node;
			
		}
	|	Variable
		{
			// VarList:	Variable
			//debug
			printf("yacc varlist2\n");
			//ir
			$$.attr.First = $1.attr._Var.PLACE;
			VarList[$1.attr._Var.PLACE].addr = 0;
			//ast
			$$.Node = $1.Node;
			
		}
	;
StateList:	S_L Statement
		{
			// StateList:	S_L Statement
			//debug
			printf("yacc statelist1\n");
			//ir
			$$.attr.CH = $2.attr.CH;
			//ast
			struct node *last_node = get_last_node($1.Node);
			add_brother_node(last_node, $2.Node);
			$$.Node = $1.Node;
			
		}
	|	Statement
		{
			// StateList:	Statement
			//debug
			printf("yacc statelist2\n");
			//ir
			$$.attr.CH = $1.attr.CH;
			//ast
			$$.Node = $1.Node;
			
		}
	;
S_L:	StateList ';'
		{
			// S_L:	StateList ';'
			// 多个语句之间通过分号分割
			//debug
			printf("yacc s_l\n");
			//ir
			//backPatch($1.attr.CH, NXQ);
			//ast
			$$.Node = $1.Node;
			
		}
	;
Statement:	AsignStatement
		{
			// Statement:	AsignStatement
			// 赋值语句是句子的一种
			//debug
			printf("yacc statement\n");
			//ast
			$$.Node = $1.Node;
			//ir
			//$$.attr.CH = $1.attr.CH;
			
			
		}
	|	ISE Statement
		{
			// If Else语句是句子的一种,ISE=IF+STATEMENT+ELSE, Statement是else后的语句
			//debug
			printf("yacc statement ise\n");
			//ast
			new_node(&($$.Node));
			set_node_var_str($$.Node,"ISES");
			$$.Node->seq = count++;

			struct node *tmpif;
			new_node(&(tmpif));
			add_son_node($$.Node, tmpif);
			tmpif->seq = count++;
			set_node_var_str(tmpif, "If");
			add_son_node(tmpif, $1.Node->son->son);

			struct node *tmpthen;
			new_node(&(tmpthen));
			add_son_node($$.Node, tmpthen);
			tmpthen->seq = count++;
			set_node_var_str(tmpthen, "Then");
			add_son_node(tmpthen, $1.Node->son->next);

			struct node *tmpelse;
			new_node(&(tmpelse));
			add_son_node($$.Node, tmpelse);
			tmpelse->seq = count++;
			set_node_var_str(tmpelse, "Else");
			add_son_node(tmpelse, $2.Node);

			//ir
			//$$.attr.CH = merge($1.attr.CH, $2.attr.CH);
			
		}
	|	IBT Statement
		{
			// If then语句是句子的一种IBT=IF+BOOL+THEN
			//debug
			printf("yacc statement ibt\n");
			//ast
			add_son_node($1.Node, $2.Node);
			$$.Node = $1.Node;
			//ir
			//$$.attr.CH = merge($1.attr.CH, $2.attr.CH);
		}

	|	WBD Statement
		{
			// While语句是句子的一种
			//debug
			printf("yacc statement wbd\n");
			//ast
			add_son_node($1.Node, $2.Node);
			$$.Node = $1.Node;
			//ir
			backPatch($1.attr._WBD.CH, NXQ+1);			//把
			gen("j", 0, 0, $1.attr._WBD.QUAD);					//跳回while循环
			$$.attr.CH = $1.attr._WBD.CH;
		}
	|	CompStatement
	    {
			// Begin End语句块
			//debug
			printf("yacc statement compstatement\n");
			//ast
			$$.Node = $1.Node;
			//ir
			$$.attr.CH = $1.attr.CH;
			
		}
	|	{
			// Statement : 
			//debug
			printf("yacc statement\n");
	    }
	;
CompStatement:	Begin StateList End
		{
			// CompStatement:	Begin StateList End
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
			//debug
			printf("yacc compstatement\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_compstat;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "begin_end");
			add_son_node($$.Node, $2.Node);
			//ir
			$$.attr.CH = $2.attr.CH;
		}
	;
AsignStatement:	Variable AssignOp  Expr
		{
			// AsignStatement:	Variable AssignOp  Expr
			// 赋值语句
			//debug
			printf("yacc asignstatement\n");
			//table
			if( VarList[$1.attr._Var.PLACE].defined == 0 )
			{
				yyerror("Unclared Variable:");
				printf("%s !\n",$1.Node->val.str);
				return 0;
			}
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_assign_stat;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, ":=");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
			
			//ir
			if (!$1.attr._Var.OFFSET) { /*OFFSET=0，简单变量*/ 
				gen(":=", $3.attr._Expr.place, 0, $1.attr._Var.PLACE);
			} else {  /*OFFSET不为0，下标变量*/ 
				gen("[]=", $3.attr._Expr.place, 0, $1.attr._Var.PLACE);
			}
			$$.attr.CH = $1.attr._Var.PLACE;
		}
	;

ISE:	IBT Statement Else
		{
			// If Else语句
			//debug
			printf("yacc ise\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_if_then_else_stat;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "if_then");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $2.Node);
			printf("yacc ise\n");
			//ir
			//int q = NXQ;
			//gen("j", 0, 0, 0);
			backPatch($1.attr._BExpr.FC, NXQ);
			//$$.attr.CH = merge($2.attr.CH, q);
		}
	;
IBT:	If BoolExpr Then
		{
			// If Then 语句
			//debug
			printf("yacc ibt\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_if_then_stat;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "if_then");
			add_son_node($$.Node, $2.Node);
			//ir
			$$.attr.CH = $2.attr._BExpr.FC;
			
		}

	;
		
WBD: Wh BoolExpr Do
		{
			// while循环
			//debug
			printf("yacc wbd\n");
			//ast
			add_son_node($1.Node, $2.Node);
			$$.Node = $1.Node;
			//ir
			backPatch($2.attr._BExpr.TC, NXQ);
			setJump($2.attr._BExpr.FC, 0);
			$$.attr._WBD.CH = $2.attr._BExpr.FC;
			$$.attr._WBD.QUAD = $1.attr.CH;
		}
	;

Wh:	 While
        {
			// 文法符号While对应关键字"while"
			//debug
			printf("yacc wh\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type =e_while_stat;
			set_node_var_str($$.Node, "while");
			$$.Node->seq = count++;
			//ir
			$$.attr.CH = NXQ;
        }
	;

BoolExpr: Expr RelationOp Expr
		{
			// 布尔表达式
			//debug
			printf("yacc boolexpr1\n");
			//ast
			$$.Node = $2.Node;
			$$.Node->type = e_bool_exp;
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
			//ir
			$$.attr._BExpr.TC = NXQ;
			$$.attr._BExpr.FC = NXQ+1;
			gen($2.attr._Rop, $1.attr._Expr.place, $3.attr._Expr.place, 0);	//NXQ
			gen("j", 0, 0, NXQ+1);											//NXQ+1
		}
	| BoolExpr And BoolExpr
		{	
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "BoolexprAnd");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
			printf("yacc boolexpr2\n");
			//ir
			printf("%d %d\n",$1.attr._BExpr.FC, $3.attr._BExpr.FC);
			$$.attr._BExpr.FC=merge($1.attr._BExpr.FC, $3.attr._BExpr.FC);
			$$.attr._BExpr.TC=NXQ;
			setJump($1.attr._BExpr.TC, $3.attr._BExpr.TC);
		}
	| BoolExpr Or BoolExpr
		{
			//debug
			printf("yacc boolepxr3\n");
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "BoolexprOr");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
			//ir
			$$.attr._BExpr.TC=merge($1.attr._BExpr.TC, $3.attr._BExpr.TC);
			$$.attr._BExpr.FC=$3.attr._BExpr.FC;
		}
	| Not BoolExpr
		{
			//debug
			printf("yacc boolexpr4\n");
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_bool_exp;
			$$.Node->seq = count++;
			set_node_var_str($$.Node, "Not");
			add_son_node($$.Node, $2.Node);
			
			//ir
			$$.attr._BExpr.TC = $2.attr._BExpr.FC;
			$$.attr._BExpr.FC = $2.attr._BExpr.TC;
			
		}
	| '(' BoolExpr ')' 
		{
			//ast
			$$.Node = $2.Node;
			printf("yacc boolexpr5\n");
			//ir
			$$.attr._BExpr.TC = $2.attr._BExpr.TC;
			$$.attr._BExpr.FC = $2.attr._BExpr.FC;
		}

	;
Expr: Expr '+' Expr
		{
			//ir
			$$.attr._Expr.place = newTemp();
			gen("+", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_exp;
			set_node_var_str($$.Node, "+");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
		}
	| Expr '-' Expr
		{
			//ir
			$$.attr._Expr.place = newTemp();
			gen("-", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_exp;
			set_node_var_str($$.Node, "-");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
		}
	| Expr '*' Expr
		{
			//ir
			$$.attr._Expr.place = newTemp();
			gen("*", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_exp;
			set_node_var_str($$.Node, "*");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
		}
	| Expr '/' Expr
		{
			//ir
			$$.attr._Expr.place = newTemp();
			gen("/", $1.attr._Expr.place, $3.attr._Expr.place, $$.attr._Expr.place);
			//ast
			new_node(&($$.Node));
			$$.Node->type = e_exp;
			set_node_var_str($$.Node, "/");
			add_son_node($$.Node, $1.Node);
			add_son_node($$.Node, $3.Node);
		}
	| '(' Expr ')'
		{
			//ir
			$$.attr._Expr.place = $2.attr._Expr.place;
			//ast
			$$.Node = $2.Node;
		}
	| '-' Expr %prec UMINUS
		{
			//ir
			$$.attr._Expr.place = newTemp();
			gen("-", $2.attr._Expr.place, 0, $$.attr._Expr.place);
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			$$.Node->type = e_exp;
			set_node_var_str($$.Node, "-");
			add_son_node($$.Node, $2.Node);
		}
	| Variable
		{
			//ir
			if(!$1.attr._Var.OFFSET)
				$$.attr._Expr.place = $1.attr._Var.PLACE;
			else
				{
					int T = newTemp();
					gen("=[]", $1.attr._Var.PLACE, 0, T);
					$$.attr._Expr.place = T;
				}
			//ast
			$$.Node = $1.Node;
			//error	这种写法将所有定义或未定义的变量全部存放于符号表中 
			if(VarList[$1.attr._Var.PLACE].defined == 0) {
				yyerror("\nUndefined Variable :");
				printf("%s\n", VarList[$1.attr._Var.PLACE].name);
				return 0;
			}
		}
	| UnsignedConst
		{
			//ir
			$$.attr._Expr.type = $1.attr._Expr.type;
			$$.attr._Expr.place = $1.attr._Expr.place;
			if ($$.attr._Expr.type) {
				$$.attr._Expr.Value.Rv = $1.attr._Expr.Value.Rv;
			} else {
				$$.attr._Expr.Value.Iv = $1.attr._Expr.Value.Iv;
			}
			//ast
			$$.Node = $1.Node;
		}

	;
ExprList: Variable '[' Expr
		{
			//debug
			printf("ExprList1\n");
			$$.attr._Elist.PLACE = $1.attr._Expr.place;
			$$.attr._Elist.DIM = 1;
			$$.attr._Elist.NO = $1.attr._Var.PLACE;
			//ast
			$$.Node = $1.Node;
		}
	|	ExprList ',' Expr
		{
			//debug
			printf("ExprList2\n");
			char num[5];
			int k,d;
			int T = newTemp();
			k = $1.attr._Elist.DIM + 1;
			d = Access_d($1.attr._Elist.NO, k);
			sprintf(num, "%d", d);	//将d转化为字符形式，结果存在num
			gen("*", $1.attr._Elist.PLACE, entry(num), T);
			gen("+", $3.attr._Expr.place, T, T); 					//相当于VARPART=VARPART*d+ik
			$$.attr._Elist.NO = $1.attr._Elist.NO;;					//传递Entry(iden)
			$$.attr._Elist.PLACE = T;								//传递存放VARPART中间结果的T
			$$.attr._Elist.DIM = k;
			//ast
			$$.Node = $1.Node;
			//
		}
	;
Variable: Iden
		{
			// Variable: Iden
			// 文法符号Iden对应标识符，以字母或下划线开头后面是字母、数字或下划线组成的符号串
			//debug
			printf("yacc Variable1\n");
			//table
			$$.attr._Var.PLACE = entry(yylval.str);
			$$.attr._Var.OFFSET = 0;
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			set_node_var_str($$.Node, yylval.str);
		}
	|	ExprList ']'
		{
			//debug
			printf("yacc Variable2\n");
			//ast

		}
	;
ArrayVar: ArrayLeft ']' Of
		{
			//debug
			printf("yacc ArrayVar\n");
			//
			$$.attr._Expr.place = $1.attr._Expr.place;
			//ast
			$$.Node = $1.Node;
			printf("%s\n",$$.Node->val.str);
		}
	;
ArrayLeft: VarList ':' Array '[' UnsignedConst DotDot UnsignedConst
		{
			//debug
			printf("arrayleft1\n");
			//一维数组
			int NO = $$.attr.NO;
			int low = $5.attr._Expr.Value.Iv, high = $7.attr._Expr.Value.Iv;
			$$.attr.NO = $1.attr.First;	//连续定义的情形
			//
			$$.attr._Expr.place = $1.attr.First;

			//内情向量表的构造
			VarList[NO].arrayaddr = malloc(sizeof(struct arr_info));
			VarList[NO].arrayaddr->DIM = 1;
			VarList[NO].arrayaddr->Vector = malloc(5*sizeof(int));		
			VarList[NO].arrayaddr->Vector[2] = low;
			VarList[NO].arrayaddr->Vector[3] = high;
			VarList[NO].arrayaddr->Vector[4] = (high - low) + 1;

			//ast
			$$.Node = $1.Node;
		}
	|		ArrayLeft ',' UnsignedConst DotDot UnsignedConst
		{
			//多维数组
			//debug
			printf("arrayleft2\n");
			int NO = $1.attr.NO;
			int dim = VarList[NO].arrayaddr->DIM+1;
			int low = $3.attr._Expr.Value.Iv, high = $5.attr._Expr.Value.Iv;
			$$.attr.NO = NO;

			//内情向量表的构造			
			VarList[NO].arrayaddr->DIM++;
			VarList[NO].arrayaddr->Vector = realloc(VarList[NO].arrayaddr->Vector, (3 * dim + 2) * sizeof(int));
			VarList[NO].arrayaddr->Vector[3*dim - 1] = low;
			VarList[NO].arrayaddr->Vector[3*dim] = high;
			VarList[NO].arrayaddr->Vector[3*dim + 1] = (high - low) + 1;

			//ast
			$$.Node = $1.Node;
		}
	;	
UnsignedConst:	UnsignedIntNo
		{
			// UnsignedConst:	UnsignedIntNo
			// 常数，无符号整数
			//table
			$$.attr._Expr.type = 0;						//记录常量类型
			$$.attr._Expr.place = entry(str_lex);		//记录常量在字符表中的位置
			VarList[$$.attr._Expr.place].type = 0;		//将字符表中该常量的类型设为INTEGER：0
			VarList[$$.attr._Expr.place].defined = 1;	//常量被视为已定义
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			set_node_var_str($$.Node, str_lex);
			new_node(&($1.Node));
			$1.Node->seq = count++;
			set_node_var_str($1.Node, "UnsignedIntNo");
			add_son_node($$.Node, $1.Node);
			//ir
			$$.attr._Expr.Value.Iv = atoi(str_lex);	//记录该常量的值

		}
	|	UnsignedRealNo
		{
			// 常数，无符号实数
			//table
			$$.attr._Expr.type = 1;						//记录常量类型
			$$.attr._Expr.place = entry(yylval.str);		//记录常量在字符表中的位置
			VarList[$$.attr._Expr.place].type = 1;		//将字符表中该常量的类型设为REAL：1
			VarList[$$.attr._Expr.place].defined = 1;
			//ast
			new_node(&($$.Node));
			$$.Node->seq = count++;
			set_node_var_str($$.Node, yylval.str);
			new_node(&($1.Node));
			$1.Node->seq = count++;
			set_node_var_str($1.Node, "UnsignedRealNo");
			add_son_node($$.Node, $1.Node);
			printf("yacc UnsignedRealNo\n");
			//ir
			$$.attr._Expr.Value.Iv = atoi(yylval.str);	//记录该常量的值
		}
	;

RelationOp:	'<'
		{
			// 小于
			//ast
			new_node(&($$.Node));
			set_node_var_str($$.Node, "<");
			$$.Node->seq = count++;
			printf("<\n");
			//ir
			strcpy($$.attr._Rop, "j<");
		}
	|	'>'
		{
			// 大于
			//ast
			new_node(&($$.Node));
			set_node_var_str($$.Node, ">");
			$$.Node->seq = count++;
			//ir
			strcpy($$.attr._Rop, "j>");
		}	
	|	'='
		{
			// 等于
			new_node(&($$.Node));
			set_node_var_str($$.Node, "=");
			$$.Node->seq = count++;
			//ir
			strcpy($$.attr._Rop, "j=");
		}
	|	GE
		{
			// 文法符号GE对应大于等于，符号串为">=
			new_node(&($$.Node));
			set_node_var_str($$.Node, ">=");
			$$.Node->seq = count++;
			//ir
			strcpy($$.attr._Rop, "j>=");
		}
	|	NE 
		{
			// 文法符号NE对应不等于，符号串为"<>""
			new_node(&($$.Node));
			set_node_var_str($$.Node, "<>");
			$$.Node->seq = count++;
			//ir
			strcpy($$.attr._Rop, "j!=");
		}
	|	LE
		{
			// 文法符号LE对应小于等于，符号串为"<=""
			new_node(&($$.Node));
			set_node_var_str($$.Node, "<=");
			$$.Node->seq = count++;
			//ir
			strcpy($$.attr._Rop, "j<=");
		}
	;
%%

int yyerror(char *errstr)
{
	printf("LineNo:%d, Reason:%s\n", line_no, errstr);
	return 0;
}

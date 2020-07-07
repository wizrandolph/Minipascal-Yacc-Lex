#include <stdio.h>
#include <stdlib.h>

//#include "pascal_lex.h"
#include "y.tab.h"

#include "ast.h"
#include "table.h"
#include "ir.h"
#include "lex.yy.h"

extern int yyparse();

int main()
{
	FILE *fp = fopen("test.pas","r");
	//FILE * fp = fopen(".\\test\\test_while.pas","r");
	//FILE * fp = fopen(".\\test\\test_if_then_else.pas","r");
	
	// 如果指定文件名参数，则从文件中获取字符串
	// 如果没有指定参数，则默认从终端获取字符串
		if (fp == NULL) {
			printf("open file error");
		}

	// 词法分析的输入文件，必须由外部设置
	yyset_in(fp);

	// 抽象语法树AST初始化
	init_ast();

	// 进行词法分析、语法分析以及语法分析，同时产生分析树或者抽象语法树等
	yyparse();

	// 输出四元式
	//OutputQuaterList();

	// 输出符号表(变量名）
	OutputVarList();

	// 输出抽象语法树
	// TODO 实现通过Graphviz输出抽象语法树
	system("pause");

	// 输出四元式
	OutputQuaterList();
	OutputOriginQL();
	system("pause");
	return 0;
}

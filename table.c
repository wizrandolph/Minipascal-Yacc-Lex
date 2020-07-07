#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "table.h"
#include "y.tab.h"
/*
 * 请在本文件中编写有关词法与语法分析中所需要用到有关符号表相关的函数
 */


int VarCount = 1;

static char KeyWord[][TABLE_MAX_IDENT_NAME_LEN] = {
		"PROGRAM",
		"BEGIN",
		"END",
		"VAR",
		"INTEGER",
		"REAL",
		"WHILE",
		"DO",
		"IF",
		"THEN",
		"ELSE",
		"OR",
		"AND",
		"NOT"
	};

int id_or_keyword(char *str)
{
	unsigned int i, j;
	char *p, buf[TABLE_MAX_IDENT_NAME_LEN];

	for (i = 0; i < sizeof(KeyWord) / sizeof(KeyWord[0]); i++) {
		p = str;

		for (j = 0; j < strlen(str); j++)
			buf[j] = (char)toupper(p[j]);
		
		buf[j] = '\0';

		if (!strcmp(KeyWord[i], buf)) {
			break;
		}
	}

	if (i < sizeof(KeyWord) / sizeof(KeyWord[0]))
		return i + 400;

	return Iden;
}

void OutputVarList(void)
{
	int i = 1;

	printf(" No.\t name \t\t defined\t type\n");

	if (i >= VarCount) {
		printf("Symbol Table is NULL!\n");
		return;
	}

	for (i = 1; i < VarCount; i++) {
		printf("%4d\t%6s\t\t%d\t", i, VarList[i].name, VarList[i].defined);
		switch(VarList[i].type)
		{
			case 0: {
				printf("INTEGER\n");
				break;
			}
			case 1:{
				printf("REAL\n");
				break;
			}
			case 2:{
				printf("ARRAY INTEGER\n");
				break;
			}
			case 3:{
				printf("ARRAY REAL\n");
				break;
			}
			default:{
				break;
			}
		}
	}

	return;
}

int lookUp(char *Name)
{
	int i;
	for (i = 1; i < VarCount; ++i) {
		if (!strcmp(Name, VarList[i].name)) {
			return i;
		}
	}
	return 0;
}

int enter(char *Name)
{
	strcpy(VarList[VarCount].name, Name);
	VarList[VarCount].type = 0; // default type is INTEGER
	return VarCount++;
}

int entry(char *Name)
{
	if(id_or_keyword(Name)==1)
	{
		printf("Unavailable Var Name\n");
		exit(0);
	}
	int i = lookUp(Name);
	if (i > 0) {
		return i;
	} else {
		return enter(Name);
	}
}


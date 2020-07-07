#include <stdio.h>
#include <string.h>
#include "ir.h"
#include "table.h"


/*
 * 请在本文件中编写有关四元式创建与维护、打印等相关的函数接口
 */
#define MAXMEMBER 200
int NXQ = 1;  /* 下一行的序号*/
char* str_extern[20];
int tempVarCount = 0;
table_variable VarList[MAXMEMBER];

ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];

void gen(char *op, int arg1, int arg2, int result)
{
	strcpy(QuaterList[NXQ].op, op);
	QuaterList[NXQ].arg1 = arg1;
	QuaterList[NXQ].arg2 = arg2;
	QuaterList[NXQ].result = result;
	NXQ++;
}

int newTemp(void)                       
{
	char temp[5];
	sprintf(temp, "T%d", tempVarCount);
	strcpy(VarList[MAXMEMBER - tempVarCount].name, temp);
	VarList[MAXMEMBER - tempVarCount].type = 0;
	return MAXMEMBER-tempVarCount++;
}

void backPatch(int p, int t)
{
    int q = p, q1;

	while (q) {
		q1 = QuaterList[q].result;
		QuaterList[q].result = t;
		q = q1;
	}
	return;
}

void FillArrMSG_C(int NO)
{
	int n = VarList[NO].arrayaddr->DIM;
	int C = 0, j, k, mul;
	for (j = 1; j < n; ++j) {
		mul = 1;
		for (k = j + 1; k < n + 1; ++k) {
			mul *= VarList[NO].arrayaddr->Vector[3*k + 1];
		}
		C += VarList[NO].arrayaddr->Vector[3 * j - 1] * mul;
	}
	VarList[NO].arrayaddr->Vector[0] = C;
}

int merge(int p1, int p2)
{
	int p;
	if (!p2) { // p2 = 0????????????
		return p1;
	} else {
		//find the last quadruple of chain p2
		p = p2;
		while (QuaterList[p].result) {
			p = QuaterList[p].result;
		}
		// append p1 to p2
		QuaterList[p].result = p1;
		return p2;
	}
}

void OutputQuaterList(void)
{
	int i = 1;

	if (i >= NXQ) {
		printf("no quater exists!\n");
	}
	printf("\n**** Quaters Table ****\n");
	for (i = 1;i<NXQ;i++) {
		printf("(%3d) ( %5s, ", i, QuaterList[i].op);
		if (QuaterList[i].arg1)
			printf("%6s, ", VarList[QuaterList[i].arg1].name);
		else
			printf("      , ");

		if (QuaterList[i].arg2)
			printf("%6s, ", VarList[QuaterList[i].arg2].name);
		else printf("      , ");

		if (QuaterList[i].op[0] == 'j')
			printf("%6d )\n", QuaterList[i].result);
		else if (QuaterList[i].result)
			printf("%6s )\n", VarList[QuaterList[i].result].name);
		else printf("null-\t )\n");
	}
	printf("(%3d) (return,      0,       0,     0 )\n",i);

	return;
}
void OutputOriginQL(void)
{
	int i = 1;

	if (i >= NXQ) {
		printf("no quater exists!\n");
	}
	printf("\n**** Quaters Table ****\n");
	for (i = 1;i<NXQ;i++) {
		printf("%d %5s, ", i, QuaterList[i].op);
		printf("%d,",QuaterList[i].arg1);
		printf("%d,",QuaterList[i].arg2);
		printf("%d,\n",QuaterList[i].result);
	}
	printf("(%3d) (return,      0,       0,     0 )\n",i);

	return;
}

//插入，为while等跳出循环
int cutIn(int q, int jump)
{
	for(int i=NXQ; i>q; i--)
	{
		QuaterList[i]=QuaterList[i-1];
	}
	strcpy(QuaterList[q].op,"j");
	QuaterList[q].arg1=0;
	QuaterList[q].arg2=0;
	QuaterList[q].result=jump;
}

int setJump(int q, int jump)
{
	QuaterList[q].result = jump;
}

/*****************************
* 从符号表第no 项的arrayaddr域所指示的内情向量中取出C值。
*****************************/
int Access_C(int no)
{
	return VarList[no].arrayaddr->Vector[0];
}

/*****************************
 * no含义同上, 取内情向量中的a值
 *****************************/
int Access_a(int no)
{
	return VarList[no].addr;
}

/*****************************
 * no含义 同上,取数组的第k维界差。
 *****************************/
int Access_d(int no, int k)
{
	return VarList[no].arrayaddr->Vector[3 * k + 1];
}

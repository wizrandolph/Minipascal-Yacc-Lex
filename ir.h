#ifndef __IR_H__
#define __IR_H__

#define MAX_IR_EXP_NUM 100

enum ir_op {
	IR_OP_UNKNOWN,
	IR_OP_ADD,
	IR_OP_SUB,
	IR_OP_MINUS,
	IR_OP_MUL,
	IR_OP_DIV,
};

/**
 * 四元式信息
 */
typedef struct ir_quarter_expression_ {
#if 0
	enum ir_op op;	// 操作码
#else
	char op[6];
#endif
	int arg1;		// 源操作数1
	int arg2;		// 源操作数2
	int result;		// 目的操作数或结果
} ir_quarter_expression;


extern int NXQ;

void OutputQuaterList(void);

void gen(char *op, int arg1, int arg2, int result);

int newTemp(void);

void backPatch(int p, int t);

int merge(int p1, int p2);

int cutIn(int q, int jump);

int setJump(int q, int jump);

void OutputOriginQL(void);

void FillArrMSG_C(int NO);
// 从符号表第no 项的ADDR域所指示的内情向量 中取出C值。
int Access_C(int no);
//  no含义同上, 取内情向量中的a值
int Access_a(int no);
// no含义 同上,取数组的第k维界差。
int Access_d(int no, int k);

#endif
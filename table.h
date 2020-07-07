#ifndef __TABLE_H__
#define __TABLE_H__

#define TABLE_MAX_IDENT_NAME_LEN 20
#define TABLE_MAX_VAR_NUM 200

struct arr_info {
	int DIM;
	int *Vector;
};

typedef struct table_variable__ {
	char name[TABLE_MAX_IDENT_NAME_LEN]; // 变量名
	int type; 	// 类型
	int addr; 	// 地址
	int defined;// 定义变量是否已声明
	struct arr_info *arrayaddr;
} table_variable;

extern table_variable VarList[TABLE_MAX_VAR_NUM];

void OutputVarList(void);

int id_or_keyword(char *);

int lookUp(char *Name);
int enter(char *Name);
int entry(char *Name);


#endif

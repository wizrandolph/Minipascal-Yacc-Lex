#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

/*
 * 请在本文件中编写有关抽象语法树创建、添加节点、图形输出语法树的接口函数
 */

/* 整个AST的根节点。该节点不允许有兄弟节点，即root.next==NULL */
struct node ast_root;
//用来区别各个同名变量，显示在前缀处
int count = 0;

/***************************************
  init_node函数负责对nd节点进行初始化
****************************************/
int init_node(struct node *nd)
{
  nd->type = e_null_node;
  nd->val.str = NULL;
  nd->son = NULL;
  nd->parent = NULL;
  nd->next = NULL;
  nd->seq = -1;
  return RET_SUCCESS;
}

// AST抽象语法树初始化
void init_ast()
{
  init_node(&ast_root);
}

int add_son_node(struct node *parent, struct node *son)
{
  if(parent != NULL && son != NULL)
  {
    if(parent->son == NULL)
    {
      parent->son = son;
      son->parent = parent;
    }
    else
    {
      struct node *tmpnode = parent->son;
      /*while内查找到当前父节点的最后一个子节点*/
      while(tmpnode->next != NULL)
      {
        tmpnode = tmpnode->next;
      }
      tmpnode->next = son;
      son->parent = parent;
    }
    return RET_SUCCESS;
  }
  else
  {
    return RET_ERROR;
  }
}

//为当前兄弟节点插入一个兄弟节点
int add_brother_node(struct node *last, struct node *next)
{
  if(last != NULL && next != NULL)
  {
    struct node *tmpparent = NULL;
    last->next = next;
    next->parent = last->parent;
    return RET_SUCCESS;
  }
  else
  {
    return RET_ERROR;
  }
  
}

int set_node_var_str(struct node *node, char *str)
{
  if(node != NULL && str != NULL)
  {
    if(node->val.str != NULL)
    {
      free(node->val.str);
    }
    node->val.str = (char*)malloc(strlen(str)+1);
    strcpy(node->val.str, str);
    return RET_SUCCESS;
  }
  else
  {
    return RET_ERROR;
  }
}

/*函数返回成功的标志，而获得的子节点将被存放在result中*/
int get_son_node(struct node *parent, struct node **result)
{
  //printf("get son node: parent =");
  //non(parent);
  if(parent != NULL)
  {
    *result = parent->son;
    return RET_SUCCESS;
  }
  else
  {
    return RET_ERROR;
  }
}

/*同上*/
int get_next_brother_node(struct node *node, struct node **result)
{
  if(node != NULL)
  {
    *result = node->next;
    return RET_SUCCESS;
  }
  else
  {
    return RET_ERROR;
  }
}

int new_node(struct node **result)
{
  if(result != NULL)
  {
    *result = (struct node *)malloc(sizeof(struct node));
    if(init_node(*result) == RET_SUCCESS)
    {
      return RET_SUCCESS;
    }
    else
    {
      return RET_ERROR;
    }
  }
  else
  {
    return RET_ERROR;
  }
}
void init_astgraph(struct node *root)
{
  FILE *fp = fopen("graphviz.dot","w");
  printf("\n********************OUTPUT AST TO FILE \"GRAPHVIZ.DOT\"**********************\n");
  fprintf(fp,"digraph ast{\n");
  struct node *son;
  //
  if(root == NULL) printf("root=null\n");
  get_son_node(root, &son);
  get_ast_graph(son, fp);
  fprintf(fp,"}\n");
  fclose(fp);
}

void get_ast_graph(struct node *node, FILE *fp)
{
  if(node != NULL)
  {
    draw_ast(node, fp);
    struct node *tmpparent = node;
    struct node *tmpson;
    struct node *tmpbro;


    if(get_son_node(tmpparent, &tmpson))
    {
      //为该节点修复父节点
      if(tmpson != NULL)
        tmpson->parent = tmpparent;
      get_ast_graph(tmpson, fp);

      while(get_next_brother_node(tmpson, &tmpbro))
      {
        if(tmpbro!=NULL)
        {
          //为该节点修复父节点
          tmpbro->parent = tmpson->parent;
        }
        get_ast_graph(tmpbro, fp);
        tmpson = tmpbro;
      }
    }
  }
}

void draw_ast(struct node *son, FILE *fp)
{
  struct node *parent = son->parent;
  int seq_p = parent->seq;
  int seq_s = son->seq;

  if(parent != NULL)
  {
    char string[16] = {0};
		itoa(seq_p, string, 10);

    if(parent->val.str != NULL) fprintf(fp, "\"%s\"",str_connect(string, parent->val.str));
    else fprintf(fp, "\"Null\"");

    fprintf(fp, "->");

    if(son != NULL)
    {
      itoa(seq_s, string, 10);
      if(son->val.str != NULL) fprintf(fp,"\"%s\";\n", str_connect(string, son->val.str));
      else fprintf(fp,"\"Null\";\n");
    } 
  }
}

struct node* get_last_node(struct node *node)
{
  struct node *tmpnode = node;
  if(node == NULL)
  {
    return NULL;
  }
  else
  while(tmpnode->next != NULL)
  {
    tmpnode = tmpnode->next;
  }
  return tmpnode;
}

int non(struct node *node)
{
  if(node == NULL)
    printf("Null Node\n");
  else
    printf("Real Node\n");

}

char* str_connect(char *str_a, char *str_b)
{
    //printf("strc start");

    char *str_rst = (char *) malloc(strlen(str_a) + strlen(str_b));
    strcpy(str_rst, str_a);
    strcat(str_rst, "|  ");
    strcat(str_rst, str_b);
    //printf("strc stop");
    //printf("%s\n", str_rst);
    return str_rst;
}




#include<stdio.h>
#include<conio.h>	//控制台输入输出头文件
#include<stdlib.h>
#include<math.h>

void Copy_node(struct node *p1, struct node *p2);
void Calculate_f(int deepth,struct node *p);
void Add_to_open(struct node *p);
void Add_to_closed(struct node *p);
void Remove_p(struct node *name, struct node *p);
int Test_A_B(struct node *p1, struct node*p2);
struct node* Search_A(struct node *name, struct node *temp);
void Print_result(struct node *p);

struct node
{
	int s[3][3];
	int i_0;
	int j_0;
	int f;
	int d;
	int h;
	struct node *father;
	struct node *next;
};

struct node s_0 = { {2,8,3,1,6,4,7,0,5},2,1,0,0,0,NULL,NULL };
struct node s_g = { { 1,2,3,8,0,4,7,6,5},1,1,0,0,0,NULL,NULL };
struct node *open = NULL;
struct node *closed = NULL;
int sum_node = 0;


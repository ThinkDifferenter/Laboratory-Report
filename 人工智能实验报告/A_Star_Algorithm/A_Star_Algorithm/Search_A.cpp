#include"head.h"

//在open表或closed表中搜索temp指向节点相同的节点
struct node* Search_A(struct node *name, struct node *temp)
{
	struct node *p1;
	p1 = name;
	while(p1 != NULL)
	{
		if (Test_A_B(p1, temp))
		{
			return p1;
		}
		else
		{
			p1 = p1->next;
		}
	}
	return NULL;
}


#include"head.h"

//将p1指向的节点状态拷贝p2指向的节点中
void Copy_node(struct node *p1, struct node *p2)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p2->s[i][j] = p1->s[i][j];
		}
	}

	p2->i_0 = p1->i_0;
	p2->j_0 = p1->j_0;
	p2->f = p1->f;
	p2->d = p1->d;
	p2->h = p1->h;
	p2->next = p1->next;
	p2->father = p1->father;
}
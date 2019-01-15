#include "head.h"


//添加p指向的节点到open表中
void Add_to_open(struct node *p)
{
	struct node *p1, *p2;
	p1 = open;
	p2 = NULL;
	if (open == NULL)
	{
		p->next = NULL;
		open = p;
	}
	else
	{
		while (p1 != NULL&&p->f > p1->f)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == NULL)
		{
			p->next = open;
			open = p;
		}
		else if (p1 == NULL)
		{
			p->next = NULL;
			p2->next = p;
		}
		else
		{
			p2->next = p;
			p->next = p1;
		}
	}
}
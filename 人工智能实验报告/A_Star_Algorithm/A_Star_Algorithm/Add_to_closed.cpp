#include "head.h"

//添加p指向的节点到closed表中
void Add_to_closed(struct node *p)
{
	if (closed == NULL)
	{
		p->next = NULL;
		closed = p;
	}
	else
	{
		p->next = closed;
		closed = p;
	}
}
#include "head.h"

//���pָ��Ľڵ㵽closed����
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
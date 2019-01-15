#include"head.h"

//从open表或者closed表中删除指定节点
void Remove_p(struct node *name, struct node *p)
{
	struct node *p1, *p2;
	p1 = NULL;
	p2 = NULL;
	if (name == NULL)
	{
		return;
	}
	else if(Test_A_B(name,p)&&name->f==p->f)
	{
		open = name->next;
		name->next - NULL;
		return;
	}
	else
	{
		p1 = name;
		p1 = p2->next;

		while (p1)
		{
			if (Test_A_B(p1, p) && p1->f == p->f)
			{
				p2->next = p1->next;
				return;
			}
			else
			{
				p2 = p1;
				p1 = p1->next;
			}
		}

		return;
	}
}
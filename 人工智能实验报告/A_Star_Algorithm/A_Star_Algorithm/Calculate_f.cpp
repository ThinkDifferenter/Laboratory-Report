#include "head.h"


//计算某个节点状态的代价值
void Calculate_f(int deepth, struct node *p)
{
	int temp = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if ((p->s[i][j]) != (s_g.s[i][j]))
			{
				temp++;
			}
		}
	}
	p->h = temp;
	p->f = deepth + p->h;
}
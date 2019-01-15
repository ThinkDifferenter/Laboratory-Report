#include"head.h"

//判断两个节点状态是否相同，相同则返回1，否则返回0
int Test_A_B(struct node *p1, struct node*p2)
{
	int flag = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((p2->s[i][j]) != (p1->s[i][j]))
			{
				flag = 0;
				return flag;
			}
		}
	}

	return flag;
}




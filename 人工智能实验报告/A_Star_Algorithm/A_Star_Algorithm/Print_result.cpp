#include"head.h"

void Print_result(struct node *p)
{
	struct node *path[100];
	struct node *temp, *temp_father;
	
	for (int i = 0; i < 100; i++)
	{
		path[i] = 0;
	}
	temp = p;
	printf("总共扩展%d个节点\n", sum_node);
	printf("总共扩展%d层\n", temp->d);
	printf("解路径如下:\n");

	for (int i = p->d; i >= 0; i--)
	{
		path[i] = temp;
		temp = temp->father;
	}

	for (int k = 0; k <= p->d; k++)
	{
		temp = path[k];
		printf("第%d步", temp->d);
		if (k - 1 >= 0)
		{
			temp_father = path[k - 1];
			if (temp->i_0 < temp_father->i_0)
			{
				printf("->上移\n");
			}
			if (temp->i_0 > temp_father->i_0)
			{
				printf("->下移\n");
			}
			if (temp->j_0 < temp_father->j_0)
			{
				printf("->左移\n");
			}
			if (temp->j_0 > temp_father->j_0)
			{
				printf("->右移\n");
			}
		}
		else
		{
			printf("\n");
		}

		printf("当前节点状态为:\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d", temp->s[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
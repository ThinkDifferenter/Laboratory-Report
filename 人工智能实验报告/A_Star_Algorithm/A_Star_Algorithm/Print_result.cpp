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
	printf("�ܹ���չ%d���ڵ�\n", sum_node);
	printf("�ܹ���չ%d��\n", temp->d);
	printf("��·������:\n");

	for (int i = p->d; i >= 0; i--)
	{
		path[i] = temp;
		temp = temp->father;
	}

	for (int k = 0; k <= p->d; k++)
	{
		temp = path[k];
		printf("��%d��", temp->d);
		if (k - 1 >= 0)
		{
			temp_father = path[k - 1];
			if (temp->i_0 < temp_father->i_0)
			{
				printf("->����\n");
			}
			if (temp->i_0 > temp_father->i_0)
			{
				printf("->����\n");
			}
			if (temp->j_0 < temp_father->j_0)
			{
				printf("->����\n");
			}
			if (temp->j_0 > temp_father->j_0)
			{
				printf("->����\n");
			}
		}
		else
		{
			printf("\n");
		}

		printf("��ǰ�ڵ�״̬Ϊ:\n");

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
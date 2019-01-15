#include"head.h"

//主函数
void main()
{
	int bingo = 0;
	struct node s;
	struct node *target, *n, *ls, *temp, *same;
	Copy_node(&s_0, &s);
	Calculate_f(0, &s);
	Add_to_open(&s);

	while (open!=NULL)
	{
		n = open;
		ls = open->next;
		Add_to_closed(n);
		open = ls;

		//判断是否成功
		if (Test_A_B(n, &s_g))
		{
			bingo = 1;
			break;
		}
		if (n->j_0 >= 1)//左移
		{
			temp = n->father;
			if ( temp != NULL && temp->i_0 == n->i_0&&temp->j_0-1 == n->j_0)
			{
				;
			}
			else
			{
				temp = (struct node*)malloc(sizeof(struct node));
				Copy_node(n, temp);
				temp->s[temp->i_0][temp->j_0] = temp->s[temp->i_0][temp->j_0 - 1];
				temp->s[temp->i_0][temp->j_0 - 1] = 0;
				temp->j_0--;
				temp->d++;
				Calculate_f(temp->d, temp);
				temp->father = n;
				if (same = Search_A(closed, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(closed, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else if (same == Search_A(open, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(open, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else
				{
					Add_to_open(temp);
					sum_node++;
				}
			}
			
		}//end move left


		if (n->j_0 <= 1)//右移
		{
			temp = n->father;
			if (temp != NULL && temp->i_0 == n->i_0&&temp->j_0 + 1 == n->j_0)
			{
				;
			}
			else
			{
				temp = (struct node*)malloc(sizeof(struct node));
				Copy_node(n, temp);
				temp->s[temp->i_0][temp->j_0] = temp->s[temp->i_0][temp->j_0 + 1];
				temp->s[temp->i_0][temp->j_0 + 1] = 0;
				temp->j_0++;
				temp->d++;
				Calculate_f(temp->d, temp);
				temp->father = n;
				if (same = Search_A(closed, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(closed, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else if (same == Search_A(open, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(open, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else
				{
					Add_to_open(temp);
					sum_node++;
				}
			}

		}//end move right


		if (n->i_0 >= 1)//上移
		{
			temp = n->father;
			if (temp != NULL && temp->i_0 == n->i_0 - 1&&temp->j_0 == n->j_0)
			{
				;
			}
			else
			{
				temp = (struct node*)malloc(sizeof(struct node));
				Copy_node(n, temp);
				temp->s[temp->i_0][temp->j_0] = temp->s[temp->i_0 - 1][temp->j_0];
				temp->s[temp->i_0 - 1][temp->j_0] = 0;
				temp->j_0--;
				temp->d++;
				Calculate_f(temp->d, temp);
				temp->father = n;
				if (same = Search_A(closed, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(closed, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else if (same == Search_A(open, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(open, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else
				{
					Add_to_open(temp);
					sum_node++;
				}
			}

		}//end move up


		if (n->j_0 <= 1)//下移
		{
			temp = n->father;
			if (temp != NULL && temp->i_0 == n->i_0 + 1 && temp->j_0 == n->j_0)
			{
				;
			}
			else
			{
				temp = (struct node*)malloc(sizeof(struct node));
				Copy_node(n, temp);
				temp->s[temp->i_0][temp->j_0] = temp->s[temp->i_0 + 1][temp->j_0];
				temp->s[temp->i_0 + 1][temp->j_0] = 0;
				temp->j_0++;
				temp->d++;
				Calculate_f(temp->d, temp);
				temp->father = n;
				if (same = Search_A(closed, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(closed, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else if (same == Search_A(open, temp))
				{
					if (temp->f < same->f)
					{
						Remove_p(open, same);
						Add_to_open(temp);
						sum_node++;
					}
				}
				else
				{
					Add_to_open(temp);
					sum_node++;
				}
			}

		}//end move down

	}//end while

	if (bingo = 1)
	{
		Print_result(n);
	}
	else
	{
		printf("问题求解失败!");
	}
	
}// end main function
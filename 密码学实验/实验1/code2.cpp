#include <stdio.h>
#include <windows.h>


//��������
void Encrypt(char s[], char key[]);
void Decrypt(char s[], char key[]);
void Chocie();
void Run();


int main()
{	
	Run();
	return 0;
}


//���к���
void Run() {
	
	while(1){
		Chocie();
	}
}

//ѡ����
void Chocie() {

	//���ġ���Կ�����ı���
	char s[1024], key[1024], e[1024];

	//���ܽ���ѡ��
	int m = 0;
	printf("������ѡ��(1.���� 2.���� 3.�˳�)��");
	scanf("%d", &m);

	if (m == 1)
	{
		printf("��������Կ��\n");
		scanf("%s", &key);
	
		fflush(stdin);
		
		printf("���������ģ�\n");
		scanf("%s", &s);

		Encrypt(s, key);
	}

	if (m == 2)
	{
		printf("��������Կ��\n");
		scanf("%s", &key);

		fflush(stdin);
		
		printf("����������:\n");
		scanf("%s", &s);

		Decrypt(s, key);
	}

	if (m == 3)
	{
		exit(0);
	}
}


//���ܺ���
void Encrypt(char s[],char key[]) {
	char e[1024];
	int l = 0, i = 0, k = 0, j = 0;
	
	for (l = 0; s[l] != '\0'; l++)
		;

	for (i = 0; i<l; i++)
	{
		e[k] = (s[i] - 'a' + key[j] - 'a') % 26 + 'a';
		j++;
		k++;
	}
	
	printf("��������Ϊ��\n");
	puts(e);
	//system("pause");
}

//���ܺ���
void Decrypt(char s[], char key[]) {
	char e[1024];
	int l = 0, i = 0, k = 0, j = 0;
	for (l = 0; s[l] != '\0'; l++)
		;

	for (i = 0; i<l; i++)
	{
		e[k] = (s[i] - key[j] + 26) % 26 + 'a';
		j++;
		k++;
	}
	
	printf("��������Ϊ��\n"); 
	puts(e);
	//system("pause");
}

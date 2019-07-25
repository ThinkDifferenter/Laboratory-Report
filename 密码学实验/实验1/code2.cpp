#include <stdio.h>
#include <windows.h>


//函数声明
void Encrypt(char s[], char key[]);
void Decrypt(char s[], char key[]);
void Chocie();
void Run();


int main()
{	
	Run();
	return 0;
}


//运行函数
void Run() {
	
	while(1){
		Chocie();
	}
}

//选择函数
void Chocie() {

	//明文、密钥、密文保存
	char s[1024], key[1024], e[1024];

	//加密解密选项
	int m = 0;
	printf("请输入选项(1.加密 2.解密 3.退出)：");
	scanf("%d", &m);

	if (m == 1)
	{
		printf("请输入密钥：\n");
		scanf("%s", &key);
	
		fflush(stdin);
		
		printf("请输入明文：\n");
		scanf("%s", &s);

		Encrypt(s, key);
	}

	if (m == 2)
	{
		printf("请输入密钥：\n");
		scanf("%s", &key);

		fflush(stdin);
		
		printf("请输入密文:\n");
		scanf("%s", &s);

		Decrypt(s, key);
	}

	if (m == 3)
	{
		exit(0);
	}
}


//加密函数
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
	
	printf("加密密文为：\n");
	puts(e);
	//system("pause");
}

//解密函数
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
	
	printf("解密明文为：\n"); 
	puts(e);
	//system("pause");
}

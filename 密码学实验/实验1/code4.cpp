#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run();
char VigenereCrypt(char *alphabet, int *key, char message, int pos);
char VigenereDecrypt(char *alphabet, int *key, char message, int pos);

int main()
{
	while(1)
	{
		run();
		printf("\n======================================\n");
	} 
	 
	return 0;
}

void run()
{
	char message[50], messageEncrypted[50], messageDecrypted[50], key[15], alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int x, i, j, messageLenght, keyLength, pos = 0, _key[50];

	printf("请输入信息:");
	gets(message);

	printf("请输入密钥: ");
	gets(key);

	messageLenght = strlen(message);
	keyLength = strlen(key);

	for (j = 0; j < keyLength; j++)
	{
		for (i = 0; i <= 25; i++)
		{
			if (key[j] == alphabet[i])
			{
				_key[j] = i;
			}
		}
	}

	printf("\n1 = 加密信息.\n");
	printf("2 = 解密信息.\n");
	printf("3 = 退出系统.\n");
	scanf("%d", &x);

	switch (x)
	{
		case 1:
			for (i = 0; i < messageLenght; i++)
			{
				if (pos >= keyLength)
				{
					pos = 0;
				}
				messageEncrypted[i] = VigenereCrypt(alphabet, _key, message[i], pos);
				pos++;
			}
			messageEncrypted[messageLenght] = '\0';
			printf("\n加密密文为: %s\n", messageEncrypted);
			break;
	
		case 2:
			for (i = 0; i <= messageLenght; i++)
			{
				if (pos >= keyLength)
				{
					pos = 0;
				}
				messageDecrypted[i] = VigenereDecrypt(alphabet, _key, message[i], pos);
				pos++;
			}
			messageDecrypted[messageLenght] = '\0';
			printf("\n解密明文为: %s\n", messageDecrypted);
			break;
			
		case 3:
			exit(0); 
	
		default:
			printf("\n 输入错误!!! \n");
	}
	
	getchar();
}

char VigenereCrypt(char *alphabet, int *_key, char message, int pos)
{
	int i, messageEncrypted;

	for (i = 0; i <= 25; i++)
	{
		if (message == alphabet[i])
		{
			messageEncrypted = (i + _key[pos]) % 26;
			return alphabet[messageEncrypted];
		}
	}
}



char VigenereDecrypt(char *alphabet, int *_key, char message, int pos)
{
	int i, messageDecrypted;

	for (i = 0; i <= 25; i++)
	{
		if (message == alphabet[i])
		{
			messageDecrypted = (i - _key[pos]) % 26;
			return alphabet[messageDecrypted];
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char VigenereCrypt(char *alphabet, int *key, char message, int pos);
char VigenereDecrypt(char *alphabet, int *key, char message, int pos);

int main()
{
	char message[1024], messageEncrypted[1024], messageDecrypted[1024], key[15], alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int choice, i, j, messageLenght, keyLength, pos = 0, _key[50];

	

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

	printf("输入选项(1.加密 2.解密 3.退出)：");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
			printf("请输入明文: ");
			scanf("%s",&message);
//			gets(message);
			
			fflush(stdin);
			
			printf("请输入密钥: ");
			scanf("%s",&key);
//			gets(key);
	
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
			printf("\n密文为: %s\n", messageEncrypted);
			break;
	
		case 2:
			printf("请输入密文: ");
			scanf("%s",&message);
			
			fflush(stdin);
		
			printf("请输入密钥: ");
			scanf("%s",&key);
			
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
			printf("\n明文为: %s\n", messageDecrypted);
			break;
			
		case 3:
			exit(0); 
	
		default:
			printf("\n 输入错误!!! \n");
	}

	getchar();
	return 0;
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

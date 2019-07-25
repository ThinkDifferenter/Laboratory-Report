#include <stdio.h>
#include <windows.h>

int main()
{ 
  char s[500],key[500],e[500];
  

  int l,m,i,j=0,k=0;
  printf("please choice: 1)Encrypt 2)Decrypt\n");
  scanf("%d",&m);
  
  
  if(m==1)
  {
      	printf("please input the key:\n");
      	scanf("%s",&key);
   
      	printf("please input the message:\n");
       	scanf("%s",&s);
      
        for(l=0;s[l]!='\0';l++)
            ;
               
        for(i=0;i<l;i++)
    	{   
           e[k]=(s[i]-'a'+key[j]-'a')%26+'a';  
           j++;
           k++;
        }
        puts(e);
        system("pause");
  }
  
  if(m==2)
  {
       	printf("please input the key:\n");
        scanf("%s",&key);
          
       	printf("please input the ciphertext:\n");
          scanf("%s",&s);
         
        for(l=0;s[l]!='\0';l++)
                ;
               
       for(i=0;i<l;i++)
       {   
           e[k]=(s[i]-key[j]+26)%26+'a';
           j++;
           k++;
       }
        puts(e);
        system("pause");
   }
    
    
}

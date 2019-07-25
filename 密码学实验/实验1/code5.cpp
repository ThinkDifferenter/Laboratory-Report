#include<stdio.h>   
#include<math.h>   
//Ѱ����Կ����   
int find_key_lenth(char*pass,int len)     
{   
    //pass����,len ���ĳ��ȣ���λͳ����ȵ����ģ�ȡ�����Ĳ���Ϊd;   
    int d=0,count,MaxCount=0;   
    for(int step=1;step<10;step++)      //�ƶ�������1-10;   
    {   
        count=0;                           
        for(int j=0;j<len&&(j+step)<len;j++)   
        {   
            if(pass[j]==pass[j+step])      
                count++;   
        }   
        if(count>MaxCount)   
        {   
            MaxCount=count;   
            d=step;   
        }   
    }   
    return d;   
}   
// ������Կ�����ܡ�����   
void decode(char*pass,char*ming,int d,int len)   
{   
    float v[26]={0};               //V��W�����飻   
    int per_len=len/d;             //ÿ�鳤�ȣ�   
    double A[26]={0.082,0.015,0.028,0.043,0.127,              //Ӣ����ĸƵ�ʱ�A   
              0.022,0.02,0.061,0.07,0.002,0.008,   
              0.04,0.024,0.067,0.075,0.019,0.001,   
              0.06,0.063,0.091,0.028,0.01,0.023,0.001,0.02,0.001};   
                      
    double B[26]={0};              //�洢W*Aֵ   
    char*key;                      //��Կ   
    key=new char[d];     
    for(int i=0;i<d;i++)   
    {   
        int j=0;   
        while(true)                     //ͳ��ÿ��a--z���ֵ�Ƶ�ʴ���V[26]��   
        {   
            if((i+d*j)>=len) break;   
            v[pass[i+d*j]-'a']+=1;   
            j++;               
        }              
        for(int k=0;k<26;k++)          //����W   
            v[k]=v[k]/per_len;   
  
        for(int k=0;k<26;k++)              //����B[i]=Ai*V;   
        {   
            for(int l=0;l<26;l++)         
                B[k]+=A[l]*v[(l+k)%26];        
        }   
        //�ҳ�B�е���0.065��ӽ���ֵ����±꼴Ϊ��Կ   
        double max=1;                       
        int c;   
        for(int k=0;k<26;k++)               
        {      
            if(fabs(B[k]-0.065)<max)   
            {   
            max=fabs(B[k]-0.065);c=k;          
            }   
        }   
        key[i]=c;           
        //���B��V��   
        for(int k=0;k<26;k++)   
        {   
            B[k]=0;   
            v[k]=0;   
        }   
        printf("%c",'a'+key[i]);   
    }      
    //���ܲ���ʾ   
    printf("\n\n����:\n");   
    for(int i=0;i<len;i++)   
    {   
      int tmp;   
      tmp=pass[i]-'a';   
      ming[i]=(tmp-key[i%d]+26)%26+'a';   
      printf("%c",ming[i]);   
    }    
    printf("\n\n");    
    return ;   
}   

int main()   
{   
    char password[1000]={0}; //����   
    char mingwen[1000]={0};  //����   
    FILE* fp;   
    if((fp=fopen("message.txt","r+"))==NULL)   
    {   
        printf("�ļ��򿪴���!\n");   
        return 1;   
    }   
    int i=0,d;   
    printf("����:");   
    while((password[i++]=fgetc(fp))!=EOF);   
    for(int j=0;j<i;j++)   
    {   
        if(j%59==0) printf("\n");   
        printf("%c",password[j]);   
    }     
    d=find_key_lenth(password,i-1);   
//	d=5;
    printf("\n\nd==%d\n",d);   
    printf("��Կ:");   
    decode(password,mingwen,d,i-1);     
    fclose(fp);   
    return 0;   
}   

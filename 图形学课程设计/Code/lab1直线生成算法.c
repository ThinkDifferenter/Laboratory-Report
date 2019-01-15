#include <graphics.h>       //中点画线法
void linedda(int x0, int y0, int x1, int y1, int color)
{
    int x,y,a,b,d,d1,d2;
	a=y0-y1;
	b=x1-x0;
	y=y0;
	d=2*a+b;
	d1=2*a;
	d2=2*(a+b);
	for(x=x0;x<=x1;x++)
	{
		if(d<0)
		{
			y++;
			d+=d2;
		}else{
			d+=d1;
		}
		putpixel(x,y,color);
     }

}
main()
{
	int a,b,c,d,e;
	int graphdriver=DETECT;
	int graphmode=0;
	initgraph(&graphdriver,&graphmode,"C:\\JMSOFT\\DRV");
	cleardevide();
	a=0;
	b=0;
	c=300;
	d=300;
	e=2;
	linedda(a,b,c,d,e);
	getch();
	closegraph();
}

#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void lineDAA(int x1,int y1,int x2,int y2,int color)
{	
	int dm=0;
	if(abs(x2-x1)>=abs(y1-y2)){
		dm=abs(x2-x1);
	} else{
		dm=abs(y2-y1);
	}
	float dx = (float)(x2-x1)/dm;
	float dy = (float)(y2-y1)/dm;
	float x=x1+0.5;
	float y=y1+0.5;
	
	for(int i=0;i<dm;i++)
	{
		putpixel((int)x,(int)y,color);
		x+=dx;
		y+=dy;
	}
}


void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void MidPLine(int x1,int y1,int x2, int y2,int color)
{
	int a,b,d,x,y,tag=0;
	if(abs(x2-x1)<abs(y2-y1)){
		swap(&x1,&y1);
		swap(&x2,&y2);
		tag=1;
	}
	
	if(x1>x2){
		swap(&x1,&x2);
		swap(&y1,&y2);
	}
	
	a=y1-y2;
	b=x2-x1;
	d=a+b/2;
	
	if(y1<y2){
		x=x1;y=y1;
		putpixel(x,y,color);
		while(x<x2){
			if(d<0){
				x++;y++;d=d+a+b;
			}else{
				x++;d+=a;
			}
			
			if(tag){
				putpixel(y,x,color);
			}else{
				putpixel(x,y,color);
			}
			//sleep(1);
		}
	}else{
		x=x2;y=y2;
		putpixel(x,y,color);
		//sleep(1);
		while(x>x1){
			if(d<0){
				x--;y++;d=d-a+b;
			}else{
				x--;d-=a;
			}
			
			if(tag){
				putpixel(y,x,color);
			}else{
				putpixel(x,y,color);
			}
			//sleep(1);
		}
	}
}


void main()
{
    int gd=0,gm=0;
	initgraph(&gd,&gm,"C:\\JMSOFT\\DRV");
	//lineDAA(10,30,90,150,255);
	MidPLine(10,30,90,100,255);
	getch();
}




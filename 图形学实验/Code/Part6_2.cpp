#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>

void orbit(float x0,float y0,float a,float b,float st,float et,int n,int ic);
void globe(int color);


void main()
{
	int gd=DETECT,gmode;
	int color;
	printf("Select back-color&planet color,please(except 0)!");
	scanf("%d",&color);
	initgraph(&gd,&gmode,"C:\\JMSOFT\\DRV");
	settextstyle(1,0,4);
	outtextxy(115,10,"Satellite Animation Display");
	settextstyle(3,0,4);
	outtextxy(138,60,"int the Wrinkle Star Sky");
	globe(color);
	orbit(320.,300.,250.,100.,-57.,237.,60.,color-3);
	getch();
	closegraph();
}


void orbit(float x0,float y0,float a,float b,float st,float et,int n,int ic)
{
	float dt,t,fst,fet,xs,ys,x,y;
	int i;
	fst=st*0.01745329;
	fet=et*0.01745329;
	dt=(fet-fst)/(float)n;
	setcolor(ic);
	ellipse((int)x0,(int)y0,-240,60,250,100);
	setcolor(ic+3);
		
	for(i=0;i<=n;i++)
	{
		putpixel(random(639),random(479),i);
		delay(20000);
		t=fst+i*dt;
		putpixel(random(639),random(479),i);
		delay(20000);
		x=x0+a*cos(t);
		putpixel(random(639),random(479),i);
		delay(20000);
		y=y0+b*sin(t);
		putpixel(random(639),random(479),i);
		delay(20000);
		setfillstyle(9,i);
		putpixel(random(639),random(479),i);
		delay(20000);
		sector((int)x,(int)y,0,360,5,2);
		pieslice(random(600),random(400),0,360,2);
		delay(20000);
		
	}	
}



void globe(int color)
{
	int i;
	setcolor(color+1);
	for(i=0;i<=6;i++)
	{
		ellipse(320,300,0,360,150-i*20-i,150);
	}
	line(320,150,320,450);
	ellipse(320,280,185,355,150,50);
	ellipse(320,170,175,365,70,30);
	ellipse(320,215,180,360,122,45);
	ellipse(320,330,195,345,147,60);
	ellipse(320,370,220,320,120,65);
	
}


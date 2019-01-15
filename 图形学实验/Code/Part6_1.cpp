#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void orbit(float x0,float y0,float a,float b,float st,float et,int n,int bk,int ic);
void globe(int color);
int bkcolor,color;

void main()
{
	int gd=DETECT,gmode;
	char select;
	
	redraw:
	
	printf("Select back-color&planet color,please(except 0)!");
	scanf("%d%d",&bkcolor,&color);
	initgraph(&gd,&gmode,"C:\\JMSOFT\\DRV");
	setbkcolor(bkcolor);
	settextstyle(1,0,4);
	settextxy(115,60,"satellite animation display");
	globe(color);
	orbit(320.,300.,250.,100.,-60.,240.,60.,bkcolor,color+2);
	outtextxy(10,20,"would you like to display again ?(Y/N)\n");
	select=toupper(getch());
	cleardevice();
	if(select=='Y'||select=='y')
	{
		goto redraw;
	}
	else
	{
		closegraph();
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




void orbit(float x0,float y0,float a,float b,float st,float et,int n,int bk,int ic)
{
	float dt,t,fst,fet,xs,ys,x,y;
	int i;
	fst=st*0.01745329;
	fet=et*0.01745329;
	dt=(fet-fst)/(float)n;
	setcolor(ic);
	
	for(i=0;i<=n;i++)
	{
		ellipse((int)x0,(int)y0,-240,60,250,100);
		t=fst+i*dt;
		x=x0+a*cos(t);
		y=y0+b*sin(t);
		setfillstyle(1,ic+3);
		pieslice((int)x,(int)y,0,360,4);
		delay(300);
		setcolor(bk);
		setfillstyle(1,bk);
		pieslice((int)x,(int)y,0,360,4);
		setcolor(ic+3);
	}	
}


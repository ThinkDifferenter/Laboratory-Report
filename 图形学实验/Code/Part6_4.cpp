#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<alloc.h>

float rad=0.0174532925;
void crank(float x0,float y0,float r,float l,float e,float t,int color);
void text(int row,int col,char *string,int color);
void name();

void main()
{
	int gd=DETECT,gmode,select,i;
	float t0,t,dt;
	initgraph(&gd,&gmode,"C:\\JMSOFT\\DRV");
	settextstyle(1,0,3);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	text(320,2,"Would you want to input paramters(1)",11);
	text(320,25,"or use the default value to display the animation(0)?",11);
	scanf("%d",&select);
	
	if(select==1)
	{
		text(28,2,"Input staring angle(65.)&increment angle(7.)",7);
		scanf("%f,%f",&t0,&dt);
	}
	else
	{
		t0=35;
		dt=6;
	}
	cleardevice();
	settextstyle(3,0,3);
	name();
	text(300,400,"Press any key to stop...",2);
	i=0;
	while(1)
	{
		t=t0-i*dt;
		crank(100.,250.,90.,400.,-80.,t,10);
		crank(100.,250.,90.,400.,-80.,t,0);
		i++;
		if(kbhit())
		{
			break;
		}	
	}
	setwritemode(XOR_PUT);
}

void crank(float x0,float y0,float r,float l,float e,float t,int color)
{
	float xa,ya,xb,yb;
	xa=x0+r*cos(t*rad);
	ya=y0+r*sin(t*rad);
	xb=xa+sqrt(l*l-(e+ya-y0)*(e+ya-y0));
	yb=y0-e;
	setcolor(color+7);
	moveto((int)x0+100,(int)(y0-e+8));
	lineto((int)(x0+2*l),(int)(y0-e+8));
	setcolor(color+8);
	setlinestyle(3,0,1);
	moveto((int)x0-100,(int)y0);
	lineto((int)x0+100,(int)y0);
	moveto((int)x0,(int)y0-100);
	lineto((int)x0,(int)y0+100);
	setlinestyle(0,0,1);
	circle(x0,y0,90);
	setcolor(color);
	moveto((int)x0,(int)y0);
	lineto((int)xa,(int)ya);
	lineto((int)xb,(int)yb);
	circle(x0,y0,3);
	circle(x0,y0,3);
	rectangle(xb-10,yb-7,xb+10,yb+7);
}

void text(int row,int col,char *string,int color)
{
	setcolor(color);
	outtextxy(row,col,string);	
}

void name()
{
	text(320,10,"Jiangxi University of Science and Technology",10);
	text(320,35,"Information and Computing Science",12);
	text(320,60,"Class 151 JiangJun",14);
}

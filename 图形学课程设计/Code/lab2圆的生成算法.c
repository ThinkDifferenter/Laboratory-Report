#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void Cirpot(int x0,int y0,int x,int y,int color)
{
	putpixel(x0+x,y0+y,color);
	putpixel(x0+y,y0+x,color);
	putpixel(x0+y,y0-x,color);
	putpixel(x0+x,y0-y,color);
	putpixel(x0-x,y0-y,color);
	putpixel(x0-y,y0-x,color);
	putpixel(x0-y,y0+x,color);
	putpixel(x0-x,y0+y,color);
}

void Bres_Circle(int x0,int y0,double r)
{
	int x,y,d;
	x=0;
	y=(int)r;
	d=(int)(3-2*r);
	while(x<y)
	{
		Cirpot(x0,y0,x,y,255);
		//sleep(1);
		if(d<0){
			d+=4*x+6;
		} else{
			d+=4*(x-y)+10;
			y--;
		}
		x++;	
	}
	if(x==y)
		Cirpot(x0,y0,x,y,255);
}

void MidPoint_Circle(int x0,int y0,int r,int color)
{
	int x=0;
	int y=r;
	int d=1-r;
	Cirpot(x0,y0,x,y,color);
	//sleep(1);
	while(x<y)
	{
		if(d<0){
			d+=2*x+3;
		}else{
			d+=2*(x-y)+5;
			y--;
		}
		x++;
		Cirpot(x0,y0,x,y,color);
		//sleep(1);
	}
	
}
/*
void Arc_OpenGL(int xc,int yc,double r,double ts,double te)
{
	double pi=3.1415926;
	if(te<ts)
		te+=2*pi;
	double dt=0.4/r;
	int n=(int)((te-ts)/dt+0.5);
	double ta=ts;
	int x=xc+int(r*cos(ts));
	int y=yc+int(r*sin(ts));
	glBegin(GL_LINE_STRIP);
	glVertex2f(x,y);
	for(int i=1;i<=n;i++)
	{
		ta+=dt;
		double cost=cos(ta);
		double sint=sin(ta);
		x=int(xc+r*cost);
		y=int(yc+r*sint);
		glVertex2f(x,y);
		sleep(1);
	}
	glEnd();
}*/


void main()
{
    int gd=0,gm=0;
	initgraph(&gd,&gm,"C:\\JMSOFT\\DRV");
	//Bres_Circle(200,200,100);
	MidPoint_Circle(200,200,100,255);
	//Arc_OpenGL(100,100,50,0,3.1415);
	getch();
}

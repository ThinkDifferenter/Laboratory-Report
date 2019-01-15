#include<stdio.h>
#include<math.h>
#include<graphics.h>
void anleft(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,int n,int icolor);
void anright(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,int n,int icolor);


void main()
{
	int gd=DETECT,gmode;
	int n,icolor;
	float x0,y0,x1,y1,x2,y2,x3,y3;
	initgraph(&gd,&gmode,"C:\\JMSOFT\\DRV");
	settextstyle(1,0,4);
	outtextxy(115,60,"Genration of Saddle Surface");
	anleft(10,10,460,440,600,20,150,320,40,1);
	anright(10,10,460,440,600,20,150,320,40,4);
	getch();
	closegraph();
}


void anleft(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,int n,int icolor)
{
	float dt,xs,ys,xe,ye,t;
	int i;
	setcolor(8);
	moveto((int)x1,(int)y1);
	lineto((int)x0,(int)y0);
	lineto((int)x0,(int)y1);
	lineto((int)x1,(int)y1);
	lineto((int)x2,(int)y3);
	lineto((int)x2,(int)y2);
	lineto((int)x1,(int)y1);
	setlinestyle(3,0,1);
	moveto((int)x0,(int)y1);
	lineto((int)x3,(int)y3);
	lineto((int)x2,(int)y3);
	dt=1/(float)n;
	setcolor(icolor);
	
	for(i=0;i<=n;i++)
	{
		t=i*dt;
		xs=x0+(x3-x0)*t;
		ys=y0+(y3-y0)*t;
		xe=x1+(x3-x1)*t;
		ye=y1+(y2-y1)*t;
		line((int)xs,(int)ys,(int)xe,(int)ye);
		delay(2000000);
	}
		
}


void anright(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,int n,int icolor)
{
	float dt,xs,ys,xe,ye,t;
	int i;
	dt=1/(float)n;
	setcolor(icolor);
	setlinestyle(0,0,1);
	
	for(i=0;i<=n;i++)
	{
		t=i*dt;
		xs=x0+(x1-x0)*t;
		ys=y0+(y1-y0)*t;
		xe=x1+(x2-x3)*t;
		ye=y1+(y2-y3)*t;
		line((int)xs,(int)ys,(int)xe,(int)ye);
		delay(2000000);
	}	
}


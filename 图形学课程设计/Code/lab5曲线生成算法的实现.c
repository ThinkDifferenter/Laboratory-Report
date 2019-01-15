
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
char msg[1];
float px[10]={30,60,90,120,150,190,220,250,280,310};
float py[10]={150,200,200,170,100,100,170,200,200,180};

main()
{
    float a0,a1,a2,a3,b0,b1,b2,b3;
    int k,m,y,w;
    float i,t,dt,n=10;
    int graphdriver=DETECT;
	int graphmode=0;
	initgraph(&graphdriver,&graphmode,"C:\\JMSOFT\\DRV"); 
	setbkcolor(BLACK);
	setcolor(RED);
	dt=1/n;
	for(k=0;k<10-1;k++)
	{
		moveto(px[k],py[k]);
		lineto(px[k+1],py[k+1]);
	}
	setlinestyle(0,0,3);
	for(k=0;k<10-3;k+=3)
	{
		a0=px[k];
		a1=-3*px[k]+3*px[k+1];
		a2=3*px[k]-6*px[k+1]+3*px[k+2];
		a3=-px[k]+3*px[k+1]-3*px[k+2]+px[k+3];
		b0=py[k];
		b1=-3*py[k]+3*py[k+1];
		b2=3*py[k]-6*py[k+1]+3*py[k+2];
		b3=-py[k]+3*py[k+1]-3*py[k+2]+py[k+3];
		for(i=0;i<=n;i+=0.1)
		{
			t=i*dt;
			m=a0+a1*t+a2*t*t+a3*t*t*t;
			y=b0+b1*t+b2*t*t+b3*t*t*t;
			if(i==0)
			moveto(m,y);
			lineto(m,y);
			sleep(0.1);
		}
	}
	getch();
	closegraph();
}

#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void initjuzhen(int m[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=0;
	for(i=0;i<3;i++)
		m[i][i]=1;
}

void main()
{
    int x0,y0,x1,y1,i,j,x2,y2,x3,y3,x4,y4,x5,y5;
    int a[3][3];
    char key;
    int graphdriver=DETECT;
	int graphmode=0;
	initgraph(&graphdriver,&graphmode,"C:\\JMSOFT\\DRV"); 
	cleardevice();
	x0=250;y0=120;x1=350;y1=220;
	x2=250;y2=120;x3=350;y3=120;
	x4=350;y4=120;x5=350;y5=220;
	line(x0,y0,x1,y1);
	line(x2,y2,x3,y3);
	line(x4,y4,x5,y5);
	for(;;)
	{
		outtextxy(100,400,"<-:left->:right:up v:down Esc->exit");
		key=getch();
		initjuzhen(a);
		switch(key)
		{
			case 75:a[2][0]=-10;break;
			case 77:a[2][0]=10;break;
			case 72:a[2][1]=-10;break;
			case 80:a[2][1]=10;break;
			case 27:break;
		}
		/*x0=x0*a[0][0]+y0*a[1][0]+a[2][0];
		y0=x0*a[0][1]+y0*a[1][1]+a[2][1];
		x1=x1*a[0][0]+y1*a[1][0]+a[2][0];
		y1=x1*a[0][1]+y0*a[1][1]+a[2][1];*/
		x2=x2*a[0][0]+y2*a[1][0]+a[2][0];
		y2=x2*a[0][1]+y2*a[1][1]+a[2][1];
		x3=x3*a[0][0]+y3*a[1][0]+a[2][0];
		y3=x3*a[0][1]+y3*a[1][1]+a[2][1];
		x4=x4*a[0][0]+y4*a[1][0]+a[2][0];
		y4=x4*a[0][1]+y4*a[1][1]+a[2][1];
		x5=x5*a[0][0]+y5*a[1][0]+a[2][0];
		y5=x5*a[0][1]+y5*a[1][1]+a[2][1];
		clearviewport();
		line(x2,y2,x3,y3);
	    line(x4,y4,x5,y5);
	    line(x2,y2,x5,y5);
	}
	closegraph();
}

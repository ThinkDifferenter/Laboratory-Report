#include <stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define Nba 20

static float plane[Nba][3]={
	97,270,1,
	175,258,1,
	435,226,1,
	298,170,1,
	234,177,1,
	305,243,1,
	545,217,1,
	562,231,1,
	607,235,1,
	630,255,1,
	596,278,1,
	475,315,1,
	313,328,1,
	225,444,1,
	297,442,1,
	440,318,1,
	117,338,1,
	65,163,1,
	116,158,1,
	176,258,1
};

static float picture[Nba][3]={
	24,34,1,
	44,33,1,
	109,29,1,
	75,21,1,
	69,23,1,
	77,32,1,
	137,27,1,
	141,29,1,
	152,30,1,
	158,32,1,
	149,35,1,
	119,40,1,
	79,41,1,
	57,56,1,
	74,55,1,
	110,40,1,
	30,43,1,
	17,21,1,
	29,20,1,
	44,33,1
};
	

void mut2d(float a[][3],float b[3][3],float c[][3],int row);
void doing2d(float cc1[][3],float cc2[][3],float mat[][3],int n);
void drawplane();
void trans2d(float m,float n,float matrix[][3]);
void minit2d(float mat[][3]);
void scaling2(float x0,float y0,float sx,float sy,float matrix[][3]);
void minit2d(float mat[][3]);
void saw(float pict[][3],int m1,int m2,int lk);
void equalmat(float a[][3],float b[][3],float row);
void rotat2d(float x0,float y0,float alfa,float matrix[][3]);


void main()
{
	float cc1[Nba][3],cc2[Nba][3],cc3[Nba][3];
	int gd=DETECT,gmode;
	initgraph(&gd,&gmode,"C:\\JMSOFT\\DRV");
	setbkcolor(0);
	settextstyle(3,0,2);
	outtextxy(190,4,"2D GRAPHICS TRANSFORMATION");
	saw(plane,0,Nba,3);
	getch();
	cleardevice();
	setcolor(4);
	outtextxy(190,430,"2D GRAPHICS TRANSFORTMATION");
	setwritemode(1);
	drawplane();
	settextstyle(3,0,4);
	setcolor(15);
	outtextxy(165,3,"Junbo Jet Propulsion");
	getch();
	closegraph();
}

void drawplane()
{
	float cc1[Nba][3],cc2[Nba][3],cc3[Nba][3],cc4[Nba][3];
	float mat[3][3];
	saw(picture,0,Nba,3);
	delay(30);
	trans2d(20,0,mat);
	equalmat(cc2,picture,Nba);
	doing2d(cc1,cc2,mat,22);
	trans2d(0,20,mat);
	doing2d(cc1,cc2,mat,15);
	equalmat(cc4,cc1,Nba);
	trans2d(-20,0,mat);
	doing2d(cc1,cc2,mat,22);
	rotat2d(0,0,0.2,mat);
	doing2d(cc1,cc2,mat,3);
	equalmat(cc1,cc3,Nba);
	scaling2(20,100,0.9,0.75,mat);
	doing2d(cc1,cc2,mat,4);
	scaling2(100.,-20.,1.1,1.3,mat);
	doing2d(cc3,cc2,mat,3);
	rotat2d(400,0,-0.15,mat);
	doing2d(cc4,cc4,mat,4);
	equalmat(cc2,cc1,Nba);
	scaling2(800,200,0.9,0.75,mat);
	doing2d(cc4,cc1,mat,4);
	scaling2(20,100,1.1,1.3,mat);
	doing2d(cc1,cc2,mat,1);
}

void doing2d(float cc1[][3],float cc2[][3],float mat[][3],int n)
{
	int i;
	mut2d(cc2,mat,cc1,Nba);
	for(i=0;i<n;i++)
	{
		saw(cc1,0,Nba,1);
		delay(30);
		saw(cc1,0,Nba,18);
		mut2d(cc1,mat,cc2,Nba);
		equalmat(cc1,cc2,Nba);
	}
	saw(cc1,0,Nba,1);
	delay(30);
}
void equalmat(float a[][3],float b[][3],float row)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=b[i][j];
		}
	}
}

void trans2d(float m,float n,float matrix[][3])
{
	minit2d(matrix);
	matrix[2][0]=m;
	matrix[2][1]=n;
}
void minit2d(float mat[][3])
{
	int count;
	for(count=0;count<3;count++)
	{
		mat[count][0]=0;
		mat[count][1]=0;
		mat[count][2]=0;
		mat[count][count]=1;
	}
}

void scaling2(float x0,float y0,float sx,float sy,float matrix[][3])
{
	minit2d(matrix);
	matrix[0][0]=sx;
	matrix[1][1]=sy;
	matrix[2][0]=-sx*x0+x0;
	matrix[2][1]=-sx*y0+y0;
}

void rotat2d(float x0,float y0,float alfa,float matrix[][3])
{
	minit2d(matrix);
	matrix[0][0]=cos(alfa);
	matrix[1][0]=sin(alfa);
	matrix[0][1]=-sin(alfa);
	matrix[1][1]=cos(alfa);
	matrix[2][0]=x0-x0*matrix[0][0]-y0*matrix[1][0];
	matrix[2][1]=y0-x0*matrix[1][0]-y0*matrix[0][0];
}

void saw(float pict[][3],int m1,int m2,int lk)
{
	int i;
	setlinestyle(0,0,lk);
	setcolor(10);
	moveto((int)pict[m1][0],(int)pict[m1][1]);
	for(i=m1;i<m2;i++)
	{
		lineto((int)pict[i][0],(int)pict[i][1]);
	}
}

void mut2d(float a[][3],float b[3][3],float c[][3],int row)
{
	int i,j,k;
	for(i=0;i<row;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0.0;
			for(k=0;k<3;k++)
			    c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
}

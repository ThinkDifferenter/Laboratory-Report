/* Note:Your choice is C IDE */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

#define rad 0.0174532925
#define NUMBER 24

float
u[NUMBER]={60.,20.,20.,80.,80.,60.,60.,0.,0.,60.,80.,0.,0.,0.,0.,0.,20.,20.,0.,0.,0.,80.,0.,0.},
v[NUMBER]={20.,60.,60.,0.,0.,20.,20.,20.,20.,20.,0.,0.,20.,20.,60.,60.,60.,60.,60.,60.,0.,0.,0.,0.},
w[NUMBER]={30.,30.,0.,0.,90.,90.,30.,30.,90.,90.,90.,90.,90.,30.,30.,0.,0.,30.,30.,0.,0.,0.,0.,90.};
int ipen[NUMBER]={3,2,2,2,2,2,2,2,2,2,3,2,2,3,2,2,2,3,2,3,2,2,3,2};
int kind[NUMBER]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1};
void draw(float sf,float xc,float yc,float tranm[][4]);
void axono2d(float sf,float ox,float oy,float bta,float afa,float x[],float y[],float z[],int kp[],int kl[],int mp);
void plot(float x,float y,int ip,int lk);
void initm(float unitm[][4]);
void mult4x4(float ma[][4],float mb[][4],float mc[][4]);
void transform(float x0,float y0,float z0,float *x,float *y,float *z,float tranm[][4]);
void translation(float l,float m,float n,float tranm[][4]);
void scaling(float sx,float sy,float sz,float tranm[][4]);
void rotationx(float xc,float yc,float zc,float alta,float tranm[][4]);
void rotationy(float xc,float yc,float zc,float beta, float tranm[][4]);
void rotationz(float xc,float yc,float zc,float gama, float tranm[][4]);
void projectx(float i,float m,float n,float tranm[][4]);
void projecty(float i,float m,float n,float tranm[][4]);
void projectz(float i,float m,float n,float tranm[][4]);
void mirrxoy(float l,float m,float n,float tranm[][4]);
void mirrxoz(float l,float m,float n,float tranm[][4]);
void mirryoz(float l,float m,float n,float tranm[][4]);
void shearing(float a,float b,float c,float d,float e,float f,float tranm[][4]);

main()
{
	int j,m=NUMBER;
	int gd=DETECT,gm;
	float tm[4][4]={0.};
	initgraph(&gd,&gm,"C:\\JMSOFT\\DRV");
	settextstyle(3,0,2);
	outtextxy(170,4,"3D GRAPHICS TRANSFORMATION");
	setwritemode(1);
	initm(tm);
	
	for(j=1;j<=15;j++)
	{
		setcolor(j);
		translation(0.,0.,-10.*j,tm);
		draw(1.,300.,350.,tm);
	}
	
	for(j=1;j<=15;j++)
	{
		setcolor(j);
		translation(-10.*j,0.,0.,tm);
		draw(1.,300.,350.,tm);
	}
	
    for(j=1;j<=15;j++)
	{
		setcolor(j);
		translation(0.,10.*j,0.,tm);
		draw(1.,300.,250.,tm);
	}
	
	for(j=1;j<=15;j++)
	{
		setcolor(j);
	    rotationx(0.,0.,0.,24.*j,tm);
		draw(1.,320.,240.,tm);
	}
	
	for(j=1;j<=15;j++)
	{
		setcolor(j);
	    rotationy(0.,0.,10.,24.*j,tm);
		draw(1.,320.,240.,tm);
	}
	for(j=1;j<=15;j++)
	{
		setcolor(j);
	    rotationz(0.,0.,10.,24.*j,tm);
		draw(1.,320.,240.,tm);
	}
	for(j=1;j<=15;j++)
	{
		setcolor(j);
	    scaling(0.2*j,0.2*j,0.2*j,tm);
		draw(1.,320.,240.,tm);
	}
	
	setwritemode(0);
	axono2d(1.,320.,240.,-45.,35.2667,u,v,w,ipen,kind,NUMBER);
	projectx(-80.,0.,0.,tm);
	draw(1.,320.,240.,tm);
	projecty(0.,-80.,0.,tm);
	draw(1.,320.,240.,tm);
	projectz(0.,0.,-80.,tm);
	draw(1.,320.,240.,tm);
	getch();
	cleardevice();
	axono2d(1.,320.,240.,-45.,35.2667,u,v,w,ipen,kind,NUMBER);
	mirrxoy(0.,0.,-60.,tm);
	draw(1.,320.,240.,tm);
	mirrxoz (0.,-60.,0.,tm);
	draw(1.,320.,240.,tm);
	mirryoz(-60.,0.,0.,tm);
	draw(1.,320.,240.,tm);
	
	getch();
	closegraph();
}
   

void draw(float sf,float xc,float yc,float tranm[][4])
{
	int i,m=NUMBER;
	float *px,*py,*pz,xu,yv,zw;
	float ul[NUMBER],vl[NUMBER],wl[NUMBER];
	px=&xu;
	py=&yv;
	pz=&zw;
	for(i=0;i<m;i++)
	{
		transform(u[i],v[i],w[i],px,py,pz,tranm);
		ul[i]=*px;
		vl[i]=*py;
		wl[i]=*pz;
	}
	axono2d(sf,xc,yc,-45.,35.2667,ul,vl,wl,ipen,kind,m);
	getch();
	axono2d(sf,xc,yc,-45.,35.2667,ul,vl,wl,ipen,kind,m);	
}

void axono2d(float sf,float ox,float oy,float bta,float afa,float x[],float y[],float z[],int kp[],int kl[],int mp)
{
	float bf,af,ca,cb,cg,sg,xp,yp,zp;
	int i;
	bf=bta*rad;
	af=afa*rad;
	cb=cos(bf);
	ca=cos(af);
	for(i=0;i<mp;i++)
	{
		if(x[i]==0)
		     xp=ox-sf*z[i]*cb;
	    else
	         xp=ox+sf*(x[i]-z[i]*cb);
	    if(y[i]==0)
	         yp=oy+sf*z[i]*ca;
	    else
	         yp=oy-sf*(y[i]-z[i]*ca);
	    plot(xp,yp,kp[i],kl[i]);
	}
}

void plot(float x,float y,int ip,int lk)
{
	if(ip==3)
	    moveto((int)x,(int)y);
	else
	{
		if(lk==0)
		   setlinestyle(USERBIT_LINE,0xFFFF,3);
		else
		   setlinestyle(USERBIT_LINE,0xF00F,1);
		lineto((int)x,(int)y);
	}
}

void initm(float unitm[][4])
{
	int n;
	for(n=0;n<4;n++)
	{
		unitm[n][0]=0;
		unitm[n][1]=0;
		unitm[n][2]=0;
		unitm[n][3]=0;
		unitm[n][n]=1;  
	}
}

void mult4x4(float ma[][4],float mb[][4],float mc[][4])
{
	int mi,mj,mk;
	for(mi=0;mi<4;mi++)
	{
		for(mj=0;mj<4;mj++)
		{
			mc[mi][mj]=0;
			for(mk=0;mk<4;mk++)
			    mc[mi][mj]=mc[mi][mj]+ma[mi][mk]*mb[mk][mj];
		}
	}
}

void transform(float x0,float y0,float z0,float *x,float *y,float *z,float tranm[][4])
{
	float xu,yv,zw,h;
	xu=tranm[0][0]*x0+tranm[1][0]*y0+tranm[2][0]*z0+tranm[3][0];
	yv=tranm[0][1]*x0+tranm[1][1]*y0+tranm[2][1]*z0+tranm[3][1];
	zw=tranm[0][2]*x0+tranm[1][2]*y0+tranm[2][2]*z0+tranm[3][2];
	h=tranm[0][3]*x0+tranm[1][3]*y0+tranm[2][3]*z0+tranm[3][3];
	(*x)=xu/h;
	(*y)=yv/h;
	(*z)=zw/h;
}

void translation(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void scaling(float sx,float sy,float sz,float tranm[][4])
{
	initm(tranm);
	tranm[0][0]=sx;
	tranm[1][1]=sy;
	tranm[2][2]=sz;
}

void rotationx(float xc,float yc,float zc,float alfa,float tranm[][4])
{
	initm(tranm);
	tranm[1][1]=cos(rad*alfa);
	tranm[1][2]=sin(rad*alfa);
	tranm[2][1]=-tranm[1][2];
	tranm[2][2]=tranm[1][1];
	tranm[3][1]=-yc*tranm[1][1]+zc*tranm[1][2]+yc;
	tranm[3][2]=yc*tranm[1][2]+zc*tranm[1][1]+zc;
}

void rotationy(float xc,float yc,float zc,float beta,float tranm[][4])
{
	initm(tranm);
	tranm[0][0]=cos(rad*beta);
	tranm[2][0]=sin(rad*beta);
	tranm[0][2]=-tranm[2][0];
	tranm[2][2]=tranm[0][0];
	tranm[3][0]=-xc*tranm[0][0]-zc*tranm[2][0]+xc;
	tranm[3][2]=xc*tranm[2][0]-zc*tranm[0][0]+zc;
}

void rotationz(float xc,float yc,float zc,float gama,float tranm[][4])
{
	
	initm(tranm);
	tranm[0][0]=cos(rad*gama);
	tranm[0][1]=sin(rad*gama);
	tranm[1][0]=-tranm[0][1];
	tranm[1][1]=tranm[0][0];
	tranm[3][0]=-xc*tranm[0][0]+yc*tranm[0][1]+xc;
	tranm[3][1]=-xc*tranm[0][1]+yc*tranm[0][0]+yc;
}

void projectx(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[0][0]=0;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void projecty(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[1][1]=0;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void projectz(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[2][2]=0;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void mirrxoy(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[2][2]=-1.;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void mirrxoz(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[1][1]=-1.;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void mirryoz(float l,float m,float n,float tranm[][4])
{
	initm(tranm);
	tranm[0][0]=-1.;
	tranm[3][0]=l;
	tranm[3][1]=m;
	tranm[3][2]=n;
}

void shearing(float a,float b,float c,float d,float e,float f,float tranm[][4])
{
	initm(tranm);
	tranm[0][1]=a;
	tranm[0][2]=b;
	tranm[1][0]=c;
	tranm[1][2]=e;
	tranm[2][0]=d;
	tranm[2][1]=f;
}

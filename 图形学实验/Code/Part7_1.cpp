#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<string.h>

#define XSize 520
#define YSize 460
#define LineLnc 1
#define ColonInc 1

float X1,X2,Y1,Y2;
float IncX,IncY,Sec;
int Limit,MaxX,MaxY;

void Initialize()
{
	int GraphDriver,GraphMode,ErrorCode;
	GraphDriver=DETECT;
	initgraph(&GraphDriver,&GraphMode,"C:\\JMSOFT\\DRV");
	ErrorCode=graphresult();
	
	if(ErrorCode!=0)
	{
		printf("Erreur graphique :%s",grapherrormsg(ErrorCode));
		exit(1);
	}
	
	MaxX=getmaxx();
	MaxY=getmaxy();
	setcolor(WHITE);
	
}

void Pause()
{
	getch();
}

void TextMode()
{
	closegraph();
}

void Initation()
{
	clrscr();

	X1=-1.5;
	X2=1.5;

	Y1=-1.25;
	Y2=1.25;
	Limit=350;
	IncX=(X2-X1)/XSize;
	IncY=(Y2-Y1)/YSize;
}

float distance(XVal,YVal) float  XVal,YVal;
{
	float F;
	if((XVal!=0.0)&&(YVal!=0.0))
	{
		F=sqrt(XVal*XVal+YVal*YVal);
	}
	else if(XVal==0.0)
	{
		F=fabs(YVal);	
	}
	else
	{
		F=fabs(XVal);
	}
	
	return F;
}


float *calculate(XPos,YPos,XIter,YIter) float XPos,YPos,XIter,YIter ;
{
	float XTemp,YTemp,XY[2];
	XTemp=XIter*XIter-YIter*YIter+XPos;
	YTemp=2*(XIter*YIter)+YPos;
	XY[0]=XTemp;
	XY[1]=YTemp;
	
	return XY;
}


void DrawMode()
{
	int Line,Colomn,Compt;
	float P0,Q0,Model,X,Y,Aux;
	float *fp;
	Colomn=0;
	while(Colomn<=YSize)
	{
		P0=X1+Colomn*IncX;
		Line=0;
		while(Line<=YSize)
		{
			Q0=Y1+Line*IncY;
			X=0;
			Y=0;
			Compt=1;
			Model=0;
			while((Compt<=Limit)&&(Model<2))
			{
				fp=calculate(P0,Q0,X,Y);
				X=*fp;
				Y=*(fp+1);
				Compt=Compt+1;
				Model=distance(X,Y);
			}
			
			if(Model>=2)
			{
				putpixel(Colomn,Line,Compt);
			}
			Line=Line+LineLnc;
		}
		Colomn=Colomn+ColonInc;
	}
}


void DisplayData()
{
	unsigned int Hour,Min;
	int MaxX,MaxY;
	char Ch[14],Ch2[8],Ch1[4],Chh[4],Chm[4];
	MaxX=getmaxx();
	MaxY=getmaxy();
	setcolor(WHITE);
	moveto(0,0);
	lineto(MaxX,0);
	lineto(MaxX,MaxY);
	lineto(0,MaxY);
 	moveto(460,0);
	lineto(460,MaxY);
	Min=floor(Sec/60.0);
	Hour=floor(Min/60.0);
	Min=fmod(Min,60.0);
	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	gcvt(X1,7,Ch2);
	strcpy(Ch,"X1=");
	strcat(Ch,Ch2);
	outtextxy(480,100,Ch);
	
	gcvt(X2,7,Ch2);
	strcpy(Ch,"X2=");
	strcat(Ch,Ch2);
	outtextxy(480,130,Ch);
	
	gcvt(Y1,7,Ch2);
	strcpy(Ch,"Y1=");
	strcat(Ch,Ch2);
	outtextxy(480,160,Ch);
	
	
	gcvt(Y2,7,Ch2);
	strcpy(Ch,"Y2=");
	strcat(Ch,Ch2);
	outtextxy(480,190,Ch);
	
	itoa(Limit,Ch1,10);
	strcpy(Ch,"Limit=");
	strcat(Ch,Ch1);
	outtextxy(480,220,Ch);
	
	itoa(Hour,Chh,10);
	itoa(Min,Chm,10);
	
	strcat(Chh,"H");
	strcat(Chm,"M");
	
	strcpy(Ch,"Time=");
	
	strcat(Ch,Chh);
	strcat(Ch,Chm);
	
	moveto(480,250);
	outtext(Ch);
}

void main()
{
	time_t start,end;
	Initation();
	Initialize();
	cleardevice();
	start=time(NULL);
	DrawMode();
	end=time(NULL);
	Sec=difftime(start,end);
	DisplayData();
	Pause();
	TextMode();
}
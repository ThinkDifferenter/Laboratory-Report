#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<string.h>

#define ScreenBase 460
#define ScreenTop 346
#define LncLine 1
#define IncColonm 1

float X1,X2,Y1,Y2;
float IncX,IncY;
float P,Q,Sec;
int Limit;


void Initialize()
{
	int GraphDriver,GraphMode,ErrorCode;
	GraphDriver=DETECT;
	initgraph(&GraphDriver,&GraphMode,"C:\\JMSOFT\\DRV");
	ErrorCode=graphresult();
	
	if(ErrorCode!=0)
	{
		printf("Erreur graphique : %s",grapherrormsg(ErrorCode));
		exit(1);
	}
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
	X1=-1.5000000;
	X2=1.5000000;
	Y1=-1.5000000;
	Y2=1.500000;
	Limit=200;
	P=0.3200000;
	Q=0.0430000;
	
	IncX=(X2-X1)/ScreenBase;
	IncY=(Y2-Y1)/ScreenTop;
}


void JuliaAsember()
{
	int Line,Colomn,Compt,MaxColors,Colors;
	float P0,Q0,Model,X,Y,Aux;
	Colomn=0;
	MaxColors=getmaxcolor();
	Colors=MaxColors+1;
	
	while(Colomn<=ScreenBase)
	{
		Line=0;
		
		while(Line<=(ScreenTop/2))
		{
			X=X1+Colomn*IncX;
			Y=Y1+Line+IncY;
			Compt=0;
			Model=0;
			
			while((Compt<=Limit)&&(Model<=0))
			{
				Aux=X;
				X=X*X-Y*Y+P;
				Y=2*Y*Aux+Q;
				Model=X*X+Y*Y;
				Compt=Compt+1;
			}
			
			if(Model>4)
			{
				setcolor(fmod(Compt,Colors));
				moveto(Colomn,ScreenTop-Line);
				lineto(Colomn,ScreenTop-Line);
				moveto(ScreenBase-Colomn,Line);
				lineto(ScreenBase-Colomn,Line);
			}
			Line=Line+LncLine;
		}
		Colomn=Colomn+IncColonm;
	}
}
	
void DisplayData()
{
	unsigned int Hour,Min;
	
	char Ch[14],Ch2[18],Ch1[4],Chh[4],Chm[4];
	Min=floor(Sec/60.0);
	Hour=floor(Min/60.0);
	Min=fmod(Min,60.0);	
	

	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	gcvt(X1,8,Ch2);
	strcpy(Ch,"X1=");
	strcat(Ch,Ch2);
	outtextxy(500,50,Ch);
	
	gcvt(X2,8,Ch2);
	strcpy(Ch,"X2=");
	strcat(Ch,Ch2);
	outtextxy(500,80,Ch);
	
	gcvt(Y1,8,Ch2);
	strcpy(Ch,"Y1=");
	strcat(Ch,Ch2);
	outtextxy(500,110,Ch);
	
	
	gcvt(Y2,8,Ch2);
	strcpy(Ch,"Y2=");
	strcat(Ch,Ch2);
	outtextxy(500,140,Ch);
	
	itoa(Limit,Ch1,10);
	strcpy(Ch,"Limit=");
	strcat(Ch,Ch1);
	outtextxy(500,170,Ch);
	
	
	gcvt(P,6,Ch2);
	strcpy(Ch,"P=");
	strcat(Ch,Ch2);
	outtextxy(500,230,Ch);
	
	
	itoa(Hour,Chh,10);
	itoa(Min,Chm,10);
	
	strcat(Chh,"H");
	strcat(Chm,"M");
	
	strcpy(Ch,"Time=");
	
	strcat(Ch,Chh);
	strcat(Ch,Chm);
	
	moveto(500,260);
	outtextxy(500,260,Ch);
}

void main()
{
	time_t start,end;
	Initation();
	Initialize();
	cleardevice();
	start=time(NULL);
	JuliaAsember();
	end=time(NULL);
	Sec=difftime(start,end);
	DisplayData();
	Pause();
	TextMode();
}


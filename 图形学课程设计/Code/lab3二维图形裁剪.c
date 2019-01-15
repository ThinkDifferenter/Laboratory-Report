#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8


void encode(float x,float y,float XL,float XR,float YB,float YT,int *code)
{
	int c=0;
	if(x<XL)	c=c|LEFT;
	else if(x>XR)	c=c|RIGHT;
	//printf("code=%d\n",c);
	if(y>YB) 	c=c|BOTTOM;
	else if(y<YT)	c=c|TOP;
	//printf("code=%d\n",c);
	*code=c;
	
	return;
}    

void C_S_LineClip(float *x1,float *y1,float *x2,float *y2,float XL,float XR,float YB,float YT)
{
	int code1,code2,code;
	//int flag=1;
	
	float x,y;
	encode(*x1,*y1,XL,XR,YB,YT,&code1);
	encode(*x2,*y2,XL,XR,YB,YT,&code2);
	//printf("code1=%d code2=%d\n",code1,code2);
	while(code1!=0||code2!=0)
	{
		
		if((code1&code2)!=0) return;
		code=code1;
		if(code1==0) code=code2;
		if((LEFT&code)!=0) 
		{
			x=XL;
			y=*y1+(*y2-*y1)*(XL-*x1)/(*x2-*x1);
		}
		if((RIGHT&code)!=0)
		{
			x=XR;
			y=*y1+(*y2-*y1)*(XR-*x1)/(*x2-*x1);
		}
		if((BOTTOM&code)!=0)
		{
			y=YB;
			x=*x1+(*x2-*x1)*(YB-*y1)/(*y2-*y1);
		}
		if((TOP&code)!=0)
		{
			y=YT;
			x=*x1+(*x2-*x1)*(YT-*y1)/(*y2-*y1);
		}
		
		if(code==code1){
			*x1=x;*y1=y;
			encode(x,y,XL,XR,YB,YT,&code1);
		}
		else{
			*x2=x;*y2=y;
			encode(x,y,XL,XR,YB,YT,&code2);
		}
	}
	//printf("x1=%f y1=%f x2=%f y2=%f\n",*x1,*y1,*x2,*y2);
}



void main()
{
	int gd=0,gm=0;
	initgraph(&gd,&gm,"C:\\JMSOFT\\DRV");
	float XL=50,XR=300,YB=300,YT=50;
	rectangle(XL,YT,XR,YB);
	float x1=40,y1=360,x2=320,y2=60;
	line((int)x1,(int)y1,(int)x2,(int)y2);
	float *px1=&x1,*py1=&y1;
	float *px2=&x2,*py2=&y2;
    C_S_LineClip(px1,py1,px2,py2,XL,XR,YB,YT); 
    //printf("x1=%f y1=%f x2=%f y2=%f \n",*px1,*py1,*px2,*py2);
    getch();
	//line(*px1,*py1,*px2,*py2);
	//lineDAA(*px1,*py1,*px2,*py2,2 );
	clearviewport();
	rectangle(XL,YT,XR,YB);
	line(*px1,*py1,*px2,*py2);
	getch();
    closegraph();
    
}


#include<graphics.h>
typedef struct
{
	unsigned all;
	unsigned left,right,top,bottom;
}outcode;

typedef struct
{
	float xmin,xmax,ymin,ymax;
}Rectangle;
Rectangle * rect;

void cohensu(float x0,float y0,float x1,float y1,Rectangle * rect)
{
     void compoutcode(float,float,Rectangle *,outcode * );
     int accept,done;
     outcode outcode0,outcode1;
     outcode * outcodeout;
     float x,y;
     accept = 0;
     done = 0;
     compoutcode(x0,y0,rect,&outcode0);
     compoutcode(x1,y1,rect,&outcode1);
     do{
     	if(outcode0.all == 0 && outcode1.all == 0)
     	{
     		accept = 1;
     		done = 1;
     	}
     	else if(outcode0.all&outcode1.all!=0)
     	    done = 1;
     	else
     	{
     	    if(outcode0.all!= 0)
     	        outcodeout =&outcode0;
     	    else
     	        outcodeout =&outcode1;
     	    if(outcodeout -> left)
     	    {
     	    	y = y0 + (y1 - y0) * (rect -> xmin-x0)/(x1 - x0);
     	    	x = (float)rect -> xmin;
     	    }
     	    else if(outcodeout -> top)
     	    {
     	    	x = x0 + (x1 - x0) * (rect -> ymax-y0)/(y1 - y0);
     	    	y = (float)rect -> ymax;
     	    }
     	    else if(outcodeout -> right)
     	    {
     	    	y = y0 + (y1 - y0) * (rect -> xmax-x0)/(x1 - x0);
     	    	x = (float)rect -> xmax;
     	    }
     	    else if(outcodeout -> bottom)
     	    {
     	    	x = x0 + (x1 - x0) * (rect -> ymin-y0)/(y1 - y0);
     	    	y = (float)rect -> ymin;
     	    }
     	     if(outcodeout -> all == outcode0.all)
     	     {
     	     	x0 = x;
     	     	y0 = y;
     	        compoutcode(x0,y0,rect,&outcode0);
     	     }
     	     else
     	     {
     	     	x1 = x;
     	     	y1 = y;
     	     	compoutcode(x1,y1,rect,&outcode1);
     	     }
     	}
     }while(!done);
     if(accept)
          line((int)x0,(int)y0,(int)x1,(int)y1);
}

void compoutcode(float x,float y,Rectangle *rect,outcode * outcode)
{
	outcode -> all = 0;
	outcode -> top =outcode ->bottom = 0;
	if(y > (float)rect ->ymax)
	{
		outcode ->top = 1;
		outcode ->all +=1;
	}
	else if(y < (float)rect ->ymin)
	{
		outcode ->bottom = 1;
		outcode ->all +=1;
	}
	outcode -> right = outcode ->left = 0;
	if(x > (float)rect ->xmax)
	{
		outcode ->right = 1;
		outcode ->all +=1;
	}
	else if(x < (float)rect ->xmin)
	{
		outcode ->left = 1;
		outcode ->all +=1;
	}
}
main()
{
	float
	 x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
	int i;
	int graphdriver = DETECT;
	int graphmode = 0;
	initgraph(&graphdriver,&graphmode,"C:\\JMSOFT\\DRV");
	cleardevice();
	x0 = 450;y0 = 0;x1 = 0;y1 = 450;
   

	
	rect ->xmin = 100;
	rect ->xmax = 300;
	rect ->ymin = 100;
	rect ->ymax = 300;
	
	setcolor(2);
	rectangle(rect ->xmin,rect ->ymin,rect ->xmax,rect ->ymax);
	line(x0,y0,x1,y1);
	
	line(0,0,300,500);
    outtextxy(100,400,"press any key to clip!");
    i= getch();    
    clearviewport();

    rectangle(rect ->xmin,rect ->ymin,rect ->xmax,rect ->ymax);
    cohensu(x0,y0,x1,y1,rect);
    cohensu(0,0,300,500,rect);
    outtextxy(100,400,"press any key to clip!");
    getch();
    closegraph();
} 


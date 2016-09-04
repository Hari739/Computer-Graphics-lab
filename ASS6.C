#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "MYFUN.H"

/*MID
 *POINT 
 *LNE
 *Algorithm
 */
 void MidPointLine(int x1,int y1,int x2,int y2,int gridsize,int cellsize){

 	int i,j,x,y,s1,s2,inter;
	int  deltax,deltay,temp;
	int d,deltaE,deltaNE
		x=x1;
		y=y1;
	deltay=abs(y2-y1);
	deltax=abs(x1-x2);
	s1= sign(x2-x1);
	s2 =sign(y2-y1);

	if(deltax==0){
		for(i=1;i<=deltay;i++){
			setpixel(x,y,gridsize,cellsize);
			y+=s2;
		}
		return;
	}
	if(deltay==0){
		for(i=1;i<=deltax;i++){
			setpixel(x,y,gridsize,cellsize);
			x+=s1;
			
		}
		return;
	}
	if(deltay==deltax){
		for(i=1;i<=deltax;i++){
			setpixel(x,y,gridsize,cellsize);
			x+=s1;
			y+=s2;
		}
		return;
	}
	if(deltax < deltay){
		temp=deltay;
		deltay=deltax;
		deltax=temp;
		inter=1;
	}
	else
		inter=0;

	deltaE=2*deltay;
	deltaNE=2*(deltay-deltax);
	d= 2*deltay-deltax;
	setpixel(x,y,gridsize,cellsize);
	for (i = 1; i <= deltax; ++i)
	{
		if(d<=0)
		d+=deltaE;
		else
		{
			if(inter==1)
				x+=s1;
			else
				y+=s2;
			d+=deltaNE;
		}
		if (inter==1){
				y+=s2;
			}
		else
			x+=s1;
			setpixel(x,y,gridsize,cellsize);	
	}
 }
 void MidPointExpected(int x1,int y1,int x2,int y2){
 	int i,j,x,y,s1,s2,inter;
	int  deltax,deltay,temp;
	int d,deltaE,deltaNE
	x=x1;y=y1;
	deltay=abs(y2-y1);
	deltax=abs(x1-x2);
	s1= sign(x2-x1);
	s2 =sign(y2-y1);

	if(deltax==0){
		for(i=1;i<=deltay;i++){
			//setpixel(x,y,gridsize,cellsize);
			y+=s2;
		}
		return;
	}
	if(deltay==0){
		for(i=1;i<=deltax;i++){
			//setpixel(x,y,gridsize,cellsize);
			x+=s1;
			
		}
		return;
	}
	if(deltay==deltax){
		for(i=1;i<=deltax;i++){
			//setpixel(x,y,gridsize,cellsize);
			x+=s1;
			y+=s2;
		}
		return;
	}
	if(deltax < deltay){
		temp=deltay;
		deltay=deltax;
		deltax=temp;
		inter=1;
	}
	else
		inter=0;

	deltaE=2*deltay;
	deltaNE=2*(deltay-deltax);
	d= 2*deltay-deltax;
	//setpixel(x,y,gridsize,cellsize);
	for (i = 1; i <= deltax; ++i)
	{
		if(d<=0)
		d+=deltaE;
		else
		{
			if(inter==1)
				x+=s1;
			else
				y+=s2;
			d+=deltaNE;
		}
		if (inter==1){
				y+=s2;
			}
		else
			x+=s1;
			//setpixel(x,y,gridsize,cellsize);	
	}
 
 }
 
 int main()
{
	float x1,y1,x2,y2;
	int gd =DETECT,gm,gridsize,cellsize;
	clock_t time1,time2;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	grid(30,10);
	printf("         MID POINT LINE BRESENHAM RASTERRIZATION ROUTINE                \n");
	printf("=========================================================\n");
	printf("Enter gridsize:\t");
	scanf("%d",&gridsize);
	printf("Enter cellsize:\t");
	scanf("%d",&cellsize);
	printf("Enter the points as x1\ty1\tx2\ty2\n");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	cleardevice();
	grid(gridsize,cellsize);
	time1= clock();
	MidPointLine(x1,y1,x2,y2,gridsize,cellsize);
	
	MidPointExpected(x1,y1,x2,y2);
	time2=clock();
	drawLine(x1,y1,x2,y2,gridsize,cellsize);
	getch();

	closegraph();
	printf("\nThe time taken by MId point BRESENHAM is %ld decisecond",(long)(time2-time1) );
	system("pause");
	return 0;
}

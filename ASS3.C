//DDA ALGO for LINE

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)>=0?(a):(-(a)))
//gridsize=no. of cells per row or column
//cellsize = width of a cell in pixel


void grid(int gridsize,int cellsize){
	int i;
	for (i = 0; i < gridsize; ++i)
	{
		if (i==gridsize/2)
		{
			setlinestyle(CENTER_LINE,0,3);
			line(0,i*cellsize,gridsize*cellsize,i*cellsize);
			line(i*cellsize,0,i*cellsize,gridsize*cellsize);
			setlinestyle(SOLID_LINE,0,1);

		}
		line(0,i*cellsize,gridsize*cellsize,i*cellsize);
		line(i*cellsize,0,i*cellsize,gridsize*cellsize);

	}

} 

void drawLine(int x1,int y1,int x2,int y2,int gridsize,int cellsize){
	setcolor(YELLOW);
	line((gridsize/2+x1)*cellsize,(gridsize/2-y1)*cellsize,(gridsize/2+x2)*cellsize,(gridsize/2-y2)*cellsize);

}

int sign(float x){
	if (x>0)
	{
		return 1;
	}
	else if (x<0)
	{
		return -1;
	}
	else
		return 0;
}
void setpixel(int x,int y,int gridsize,int cellsize){
	int x1,y1;
	x1= (int) ((gridsize/2+x+0.5)*cellsize);
	y1= (int) ((gridsize/2-y-0.5)*cellsize);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(x1,y1,WHITE);
}



void delay(long t){
	time_t time1,time2;
	time1=clock();
	time2=clock();
	while((long)time2<(long)time1+t)
		time2=clock();
}



void dda(float x1,float y1,float x2,float y2,int gridsize,int cellsize){

		int i;
		float x,y,deltax,deltay,length;
		length=MAX(abs(x2-x1),abs(y2-y1));
		deltax=(x2-x1)/length;
		deltay= (y2-y1)/length;

		x= x1+0.5*sign(deltax);
		y=y1+0.5*sign(deltay);

		if (deltax==0)
		{
			for (i = 0; i < length; ++i)
			{
				setpixel(floor(x),floor(y),gridsize,cellsize);
				y+=deltay;
			}
        return;
		}
		if (deltay==0)
		{
			for (i = 0; i < length; ++i)
			{
				setpixel(floor(x),floor(y),gridsize,cellsize);
				x+=deltax;
			}
		return;

		}
		if (abs(deltax)==abs(deltay))
		{
			for (i = 0; i < length; ++i)
			{
				setpixel(floor(x),floor(y),gridsize,cellsize);
				x++;
				y++;
			}
		return;	
		}
		for (i = 0; i < length; ++i)
			{
				setpixel(floor(x),floor(y),gridsize,cellsize);
				x+=deltax;
				y+=deltay;
			}

}

void ddaExpected(float x1,float y1,float x2,float y2){

		int i;
		float x,y,deltax,deltay,length;
		length=MAX(abs(x2-x1),abs(y2-y1));
		deltax=(x2-x1)/length;
		deltay= (y2-y1)/length;

		x= x1+0.5*sign(deltax);
		y=y1+0.5*sign(deltay);

		for (i = 0; i < length; ++i)
			{
				//setpixel(floor(x),floor(y));
				x+=deltax;
				y+=deltay;
			}
}

int main()
{

	int gd=DETECT,gm,gridsize,cellsize;
	clock_t time1,time2;
	float x2,x1,y2,y1;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	grid(30,10);
	printf("             DDA RASTERRIZATION ROUTINE                \n");
	printf("=========================================================\n");
	printf("Enter gridsize:\t");
	scanf("%d",&gridsize);
	printf("Enter cellsize:\t");
	scanf("%d",&cellsize);
	printf("Enter the points as x1\ty1\tx2\ty2\n");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	cleardevice();
	grid(gridsize,cellsize);
	dda(x1,y1,x2,y2,gridsize,cellsize);
	time1=clock();
	ddaExpected(x1,y1,x2,y2);
	time2=clock();
	drawLine(x1,y1,x2,y2,gridsize,cellsize);
	getch();
	closegraph();
	printf("The time taken by dda is %ld deciseconds\n",(long) (time2-time1));
	system("pause");
	return 0;
}
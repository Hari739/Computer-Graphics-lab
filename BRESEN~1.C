#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "MYFUN.H"

/*
 *Bresenham's Circle
 */
 void moveHorizontal(int *x,int *delta){

	(*x)++;
	(*delta) = (*delta) +2*(*x)+1;
 }
 void moveDiagonal(int *x,int *y,int *delta){

	(*x)++;
	(*y)--;
	(*delta) = (*delta) +2*(*x)-2*(*y)+2;
 }
 void moveVertical(int *y,int *delta){

	(*y)--;
	(*delta) = (*delta) -2*(*y)+1;
 }
 void BresCircle(int radius ,int x,int y,int gridsize ,int cellsize){
	int x1=0,y1=radius;
	int delta =2*(1-radius);
	int dell,del, limit=0;
	while(y1>=limit){
		setpixel(x+x1,y+y1,gridsize,cellsize);
		setpixel(x-x1,y+y1,gridsize,cellsize);
		setpixel(x-x1,y-y1,gridsize,cellsize);
		setpixel(x+x1,y-y1,gridsize,cellsize);

		if (delta<0)
		{
			 dell = 2*(delta+y1)-1;
				if (dell<=0){
					moveHorizontal(&x1,&delta);
				}

				else{
					moveDiagonal(&x1,&y1,&delta);
				}
		}
		else if (delta>0){

			 del = 2*(delta -x1)-1;
				if (del<=0){
					moveDiagonal(&x1,&y1,&delta);

				}

				else{
					moveVertical(&y1,&delta);
				}

		}
		else{
			moveDiagonal(&x1,&y1,&delta);
		}
	}

 }

 int main()
{
	int x1,y1,radius;
	int gd =DETECT,gm,gridsize,cellsize;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("           BRESENHAM MID POINT Circle GENERATION ALGORITHM              \n");
	printf("==========================================================================\n");
	printf("Enter gridsize:\t");
	scanf("%d",&gridsize);
	printf("Enter cellsize:\t");
	scanf("%d",&cellsize);
	printf("Enter the centre points as x1\ty1\n");

	scanf("%d%d",&x1,&y1);
	printf("Enter the Radius :\n");
	scanf("%d",&radius);
	cleardevice();
	grid(gridsize,cellsize);
	BresCircle(radius,x1,y1,gridsize,cellsize);
	drawCircle(x1,y1,radius,gridsize,cellsize);
	getch();

	closegraph();

	return 0;
}
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

//define a structure for a Point
typedef struct{
    int x;
    int y;
}Point;
int gridwidth;

int initMainGraph(){
    int cwidth=gridwidth;

    int i;

    int gdriver=DETECT,gmode,errorcode;

    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");


    
    //draw axes
    setlinestyle(SOLID_LINE,0,RED);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    //draw graph
    setlinestyle(SOLID_LINE,0,1);
    for(i=getmaxx()/2-1;i>=0;i-=cwidth)
  line(i,0,i,getmaxy());
    for(i=getmaxx()/2+1;i<=getmaxx();i+=cwidth)
  line(i,0,i,getmaxy());

    for(i=getmaxy()/2-1;i>=0;i-=cwidth)
  line(0,i,getmaxx(),i);
    for(i=getmaxy()/2+1;i<=getmaxy();i+=cwidth)
  line(0,i,getmaxx(),i);

    return 0;
}

//returns 1 for arguments >=0 and -1 for <0
int sign(float f){
    if(f>=0)
  return 1;
    else
  return -1;
}

//maps the point and returns the Point structure
Point mapPoint(float x1,float y1){
    int x0=getmaxx()/2, y0=getmaxy()/2;
    Point p;
    p.x=x0+(int)(gridwidth*x1);
    p.y=y0-(int)(gridwidth*y1);
    return p;

}

//plots the corresponding pixel
void plot(int x,int y){
    Point p=mapPoint(x,y);
    setfillstyle(SOLID_FILL,BLUE);
    setcolor(BLUE);
    rectangle(p.x,p.y-gridwidth,p.x+gridwidth,p.y);
    floodfill(p.x+gridwidth/2,p.y-gridwidth/2,BLUE);
    setcolor(WHITE);
}

//draws the original line which was rasterized
void drawLine(float x0,float y0,float x1,float y1){
    Point p0,p1;
    p0=mapPoint(x0,y0);
    p1=mapPoint(x1,y1);
    setlinestyle(SOLID_LINE,0,3);
    setcolor(RED);
    line(p0.x,p0.y,p1.x,p1.y);
    setlinestyle(SOLID_LINE,0,1);
    setcolor(WHITE);
}



int main()
{
      //	clrscr();
    int d,r,x,y,xc,yc;
    Point m;
    gridwidth = 5;
    clrscr();
	printf("Enter Radius\n");
    scanf("%d",&r);
    printf("enter the centre coordinates :");
    scanf("%d%d",&xc,&yc);
    initMainGraph();
  //  xc=0;yc=0;

   d=3-2*r;
//d=1-r
    x=0;

     y=r;

while(x<=y)
{
plot(xc+x,yc+y);
plot(xc-y,yc-x);
plot(xc+y,yc-x);
plot(xc-y,yc+x);
plot(xc+y,yc+x);
plot(xc-x,yc-y);
plot(xc+x,yc-y);
plot(xc-x,yc+y);
//sleep(1);
if(d<=0)
{
  d=d+4*x+6;
}
else
{
   d=d+4*x-4*y+10;
   y=y-1;
}
  x=x+1;
}
m=mapPoint(xc,yc);
circle(m.x+gridwidth/2,m.y-gridwidth/2,r*gridwidth);
getch();
closegraph();
return(0);
}

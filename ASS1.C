#include <graphics.h>
# include <conio.h>
# define  x_0 400
# define y_0 400
int main(){
	int gd=DETECT, gm;

	int i,j;
	initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
	while(1){
	for(i=0;i<520;i++){
		setcolor(RED);
		outtextxy(100,100,"MOVING CAR >Refrence Fixed") ;
		setcolor(WHITE) ;
		line(200+i,200,250+i,200);
		line(170+i,230,200+i,200);
		line(250+i,200,280+i,230);
		line(100+i,230,400+i,230);
		line(100+i,260,170+i,260);
		line(210+i,260,280+i,260);
		line(320+i,260,400+i,260);
		line(100+i,230,100+i,260);
		line(400+i,230,400+i,260);
	       //	line(100+i,260,170+i,260);
		line(280+i,230,400+i,230);
		line(320+i,260,400+i,260);
		circle(190+i,260,20);
		circle(300+i,260,20);
		line(0,280,900,280);
		pieslice(190+i,260,0-i,1-i,20);
		pieslice(190+i,260,90-i,91-i,20);
		pieslice(190+i,260,180-i,181-i,20);
		pieslice(190+i,260,270-i,271-i,20);
		pieslice(300+i,260,0-i,1-i,20);
		pieslice(300+i,260,90-i,91-i,20);
		pieslice(300+i,260,180-i,181-i,20);
		pieslice(300+i,260,270-i,271-i,20);
		delay(10);

		cleardevice();

		}
		if(kbhit())
			break;
	   }


	getch();
	closegraph();
	return 0;
}

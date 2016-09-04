// Analog clock and digital clock

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>

//void Analog_Clock(){

//}

void Digital_Clock(){
	 time_t now=time(NULL);

     struct tm *temp=localtime(&now);
	int hrs=temp->tm_hour,min=temp->tm_min,sec=temp->tm_sec;
    char time[256];
	while(!kbhit()){
		if(sec>59){
			min++;
			sec=0;
		}
		if(min>59){
			hrs++;
			min=0;
		}
		if(hrs>11){
			hrs=0;
			min=0;
			sec=0;
		}

		delay(1000);
		cleardevice();

		sec++;
		sprintf(time,"%d hours : %d minutes : %d seconds",hrs,min,sec);
		outtextxy(100,100,time);

	}
}

int main(){
	int gd=DETECT,gm,i,j;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	Digital_Clock();
	closegraph();
	getch();
	return 0;
}
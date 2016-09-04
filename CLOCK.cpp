
#include <iostream.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <dos.h>	// for kbhit()
#include <stdlib.h>	// for exit()

	// Set the path where your graphics files are located here
#define BGI_PATH "c:\\tc3"

	// Constants
const double PI = 3.14159265;
const double DEGS_PER_SEC = 6.0; // Angle by which seconds hand moves in a sec
const double DEGS_PER_MIN = 6.0;
const double DEGS_PER_HOUR = 30.0;
const double SEC_PER_MIN = 60.0;
const double MIN_PER_HOUR = 60.0;

int maxx, maxy; 	// Maximum x and y coordinates for current graph mode

void Initialize( void );	// Init graphics system
void ShowFrame( void );		// Show clock frame

	// Convert degrees ro radians
inline double ToRadians( double theta )
{
	return (theta*PI)/180.0;
}

	// A hand class
class HAND
{
	int length, color;
	double angle,
		prev_angle;		// Holds prev position, needed to erase hand
 public:
	HAND( int len, int clr ) { length = len; color = clr; prev_angle = angle = 0;}	// Constructor
	void SetAngle( double theta ) { angle = theta; }
	void Copy(){ prev_angle = angle ;}
	int Change(){ return ( angle != prev_angle ); }
	void Display( int x, int y );
	void Erase( int x, int y );
};

	// Display hand with origin x,y
void HAND::Display( int x, int y  )
{
	int x1, y1;

	x1 = x + length*sin( angle );
	y1 = y - length*cos( angle );	// y increases from top to bottom

	setcolor( color );
	setfillstyle( EMPTY_FILL, color );
	line( x,y,x1,y1 );
}

	// Erase previously drawn hand
void HAND::Erase( int x, int y )
{

	int x1, y1;
	x1 = x + length*sin( prev_angle );
	y1 = y - length*cos( prev_angle );	// y increases from top to bottom

	setcolor( BLACK );		// Backgnd color
	line( x,y,x1,y1 );
}


int main()
{
	struct tm* ptr_curtime;	// Pointer to current time
	time_t curtime;			// Holds cuurent time

	HAND hour( 55, RED ), minute( 85, GREEN ), second( 70, BLUE );
	int h_angle, m_angle, s_angle;
	int center_x, center_y;		// Clock center

	Initialize();
	ShowFrame();

	center_x = (maxx+1)/2;
	center_y = (maxy+1)/2;

	while( !kbhit())
	{
		hour.Copy();	// Store previous values
		minute.Copy();
		second.Copy();

			// Get current time
		curtime = time(&curtime);
		ptr_curtime = localtime(&curtime);

			// Calculate the angles of hands
		h_angle = ( ptr_curtime->tm_hour%12 * DEGS_PER_HOUR ) + ( ptr_curtime->tm_min * ( DEGS_PER_HOUR / MIN_PER_HOUR ));	// Ignore change in seconds
		m_angle = ( ptr_curtime->tm_min * DEGS_PER_MIN ) + ( ptr_curtime->tm_sec *  ( DEGS_PER_MIN / SEC_PER_MIN )) ;	// Minute hand's position also changes with secs
		s_angle = ptr_curtime->tm_sec * DEGS_PER_SEC;


		hour.SetAngle( ToRadians(h_angle));
		minute.SetAngle( ToRadians( m_angle));
		second.SetAngle( ToRadians( s_angle));

			// Display all hands if seconds position has changed
		if( second.Change())
		{
			second.Erase( center_x, center_y );
			second.Display( center_x, center_y );

			minute.Erase( center_x, center_y );
			minute.Display( center_x, center_y );

			hour.Erase( center_x, center_y );
			hour.Display( center_x, center_y );

		}

	} // End of while( !kbhit())

	closegraph();
	restorecrtmode();
	return 0;
} // End of main

	// Initialize graphics system
void Initialize( void )
{
	int GraphDriver	= DETECT, GraphMode;
	int ErrorCode;

	initgraph( &GraphDriver, &GraphMode, BGI_PATH );
	ErrorCode = graphresult();
	if( ErrorCode != grOk )
	{
		cout<<"\nGraphics system error: "<<grapherrormsg( ErrorCode );
		exit( 1 );
	}
	maxx = getmaxx();
	maxy =  getmaxy();
}

	// Shows the clock frame
void ShowFrame( void )
{
      setcolor( WHITE );
      int x1,y1;
      circle( (maxx+1)/2, ( maxy+1)/2, 100 );
      circle( (maxx+1)/2, ( maxy+1)/2, 105 );

      for( int angle = 0; angle < 360; angle+=30 )
      {
	    x1 = (maxx+1)/2 + 90*cos(ToRadians(angle));
	    y1 = (maxy+1)/2 - 90*sin(ToRadians(angle));
	    putpixel( x1, y1, CYAN );
     }
}
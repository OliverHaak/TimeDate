#include <stdio.h>
#include <time.h>
#include <ext.h>
#include <ctype.h>

int main( )
{
	time_t current_time;
	int c, result = 0;
	struct date set_date;
	struct time set_time;
	unsigned int day, month, year, hour, minute;
	
	do
	{
	  current_time = time( NULL );

	  printf("Current date/time:\n%s\n", ctime( &current_time ));
	  printf("Hit S to set system date & time\n");
	  c = tolower(getch());
	  rewind( stdin );
	  if( (char)c == 's')
	  {
	    printf("Input date & time (DD.MM.YYYY HH:MM) : ");
	    result = scanf("%2d.%2d.%4d %2d:%2d", &day, &month, &year, &hour, &minute);

	    set_date.da_day = day;
	    set_date.da_mon = month;
	    set_date.da_year = year;

	    set_time.ti_hour = hour;
	    set_time.ti_min = minute;
	    set_time.ti_sec = set_time.ti_hund = 0;

	    
	    settime( &set_time );
	    setdate( &set_date );
	  }
	} while( c == 's' );
	
      return 0;
}

/****************************************************************
 * File: Timer1.c                                               *
 *                                                              *
 ****************************************************************/

#include "ClkTimer.h"

/****************************************************************
*   File: Time_Count                                            *
*   May 6, 2021                                                 *
*   Modified:                                                   *
*   Description: this section keeps track of timing from        *
*                timer 3, it is called from file, tmr3.c        * 
*                "TMR1_CallBack", it is called every 100ms      *  
****************************************************************/
void Time_Count(void)
{
    if(++m1_sec_100 == 10)
    {
        m1_sec_100 = 0;     // reset m1_sec_100 counter
        ++seconds;          // increment seconds counter
//        Timers._sec = 1;      // set seconds flag
        
        if(TimeOut)
            --TimeOut;
//        if(SwCounter)
//            --SwCounter;
    }

	if(seconds == 60)
    {
        seconds = 0;	// reset seconds timer
       // ++minutes;
    }
    
//    if(minutes == 60)
//    {
//        minutes = 0;    // reset minutes timer
//    }
}
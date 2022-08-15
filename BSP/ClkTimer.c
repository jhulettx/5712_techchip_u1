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
//    if(Timers._HB_LED)
//    {
//        if(m1_sec_100 >= 3)
//        {
//            HB_LED_SetLow();   // turn off HB LED
//            Timers._HB_LED = 0;   // clear HB flag
//        }
//    }
    
//    if(Timers._HS)
//    {
//        ++PwrTimer;
//        if(PwrTimer >= 5)   // wait for 500ms to pass 
//            Timers._HS = 0;   // reset half second flag
//    }
    
    if(++m1_sec_100 == 10)
    {
        m1_sec_100 = 0;     // reset m1_sec_100 counter
        ++seconds;          // increment seconds counter
        HB_LED_SetHigh();   // turn on HB LED
//        Timers._HB_LED = 1;   // set HB flag
//        Timers._sec = 1;      // set seconds flag
        
//        if(timer)
//            --timer;
//        if(TimerMain)
//            --TimerMain;        
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
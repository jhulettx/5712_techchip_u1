/*******************************************************************************
* FileName:        Working.c
* Processor:       PIC18F45K22
* Compiler:        XC8 ver 2.05
*
* Author           Date:        Modified:      Comments:
* Jeff Hulett    06/13/2022                    
*******************************************************************************/

#include "Working.h"

//#include <stdint.h>

FLAGS flag;
stateflags stateflag;

uint8_t counter;

/****************************************************************************
 *                         STATES                                           *
 ****************************************************************************/
void states(void)
{
    test = 4;
        // TODO: finish this section 8-11-22
//    if(state == CurState)
//    {
    if(state == 0)  // starting state
    {
        if(stateflag._state0 == SET)
        {
            SendCommand(DispClr);    // clear display
            LCD_xy(1,2);            // line 1, 1st slot
            text_display(arr1);     // 5712 TEST
            LCD_xy(2,2);            // line 2, 2nd slot
            text_display(arr2);     // Next to start
            stateflag._state0 = CLEAR;
        }
        if(flag._Nxt == SET)
        {
            state = 4;
            stateflag._state4 = SET;
        }
    }
    
    if(state == 1)
    {
        
    }
    
    if(state == 2)
    {
        
    }
    
    if(state == 3)
    {
        
    }
    
    if(state == 4)  // speed test
    {
        test = 8;   // delete after testing
        
        if(stateflag._state4 == SET)
        {        
            // TODO: this does not display properly on line-1 8-22-22
            SendCommand(DispClr);   // clear display
            LCD_xy(1,1);            // line 1, 1st slot
            text_display(arr13);    // Fan Speed Test
            LCD_xy(2,1);            // line 2, 1st slot
            text_display(arr14);    // Turn on G Start
            test = 0;   // delete after testing
            SwCounter = SwTime;     // load timer for 3 seconds
            TimeOut = Time10s;      // load timer for 10 seconds
            nextCnt++;
            stateflag._state4 = CLEAR;
        }
         
        while((SwCounter) && (flag._Nxt == SET)){}; // TODO: rework this line 8-22-22
//        {
//          if(flag._Sel == SET)
//          {
//              TimeOut = 0;
//              FanSpeed();
//          }
            test = 1;
        
            if(flag._Nxt == SET)
            {
                TimeOut = 0;
                SwCounter = SwTime;     // load timer for 3 seconds
//                state = 0; 
//                stateflag._state0 = SET;
            }
            
            if((0 == SwCounter) || (flag._Nxt == CLEAR))
            {
                if(0 == TimeOut)  // yes.. 
                {
                    state = 0;
                    stateflag._state0 = SET;
                }
            }
//        }
//        if(TimeOut) // did the time run out?
//            wast(); // no.. 
//        else if(0 == TimeOut)  // yes..
//        if((0 == SwCounter) || (flag._Nxt == CLEAR))
//        {
//            if(0 == TimeOut)  // yes.. 
//            {
//                state = 0;
//                stateflag._state0 = SET;
//            }
//        }
    } // end of state 4
//    }
} // end of states
    
void Buttons(void)
{
    test = 5;
    //TODO finish this function 8-11-22
    if(flag._W)
    {
        // do something
    }
    if(0 == flag._W)
    {
        // turn something off
    }
    
    if(flag._Nxt)
    {
//        LCD_xy(1,1);            // line 1, 1st slot
//        text_display(arr13);    // Fan Speed Test
//        LCD_xy(2,1);            // line 2, 1st slot
//        text_display(arr14);    // Turn on G Start
//  TODO: start timer here, wait to see if select button is pushed or next button 
//        is pushed, if no button is pushed and the timer runs out, go back to the start. 8-15-22
//        if(0 == TimeOut)
//            TimeOut = Time10s;  // load timer for 10 seconds
        
//        if(flag._Sel)
//        {
//            FanSpeed();
//        }
    }
    if(0 == flag._Nxt)
    {
        //
    }
    
    if(flag._Sel)
    {
        //
    }
    if(0 == flag._Sel)
    {
        //
    }
}

/************************************************************************
 *                      FAN SPEED TEST                                  *
 ************************************************************************/
void FanSpeed(void)
{
    
    
}

/********************************
 *      Dummy function          *
 ********************************/
void wast(void)
{
    test = 100; // delete after testing
}
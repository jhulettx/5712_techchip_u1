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

uint8_t Reg_old;

/****************************************************************************
 *                         STATES                                           *
 ****************************************************************************/
void states(void)
{
    test = 4;
        // TODO: finish this section 8-11-22
    if(state == 0)  // starting state
    {
        
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
        if(flag._Busy == CLEAR) // is a test running?
        {                       // no..
            LCD_xy(1,1);            // line 1, 1st slot
            text_display(arr13);    // Fan Speed Test
            LCD_xy(2,1);            // line 2, 1st slot
            text_display(arr14);    // Turn on G Start

            if(flag._Nxt == SET)    // wait until next button is 
                return;
            else if(flag._Nxt == CLEAR)
            {
                TimeOut = Time10s;      // load timer for 10 seconds
                flag._Busy = SET;       // tell system we are running a test
            }
        }
        
        if(flag._Sel == SET)
            return;
        else if(flag._Sel == CLEAR)
        {
            TimeOut = 0;
            FanSpeed();
        }
        
        if(flag._Nxt == SET)
            return;
        else if(flag._Nxt == CLEAR)
        {
            TimeOut = 0;
            state = 0;
        }
        
        if(TimeOut)
            return;
        else if(0 == TimeOut)
        {
            state = 0;
            flag._Busy = CLEAR;
        }
    }
}

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
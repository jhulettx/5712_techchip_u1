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
    
    if(state == 5)  // speed test
    {
        
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
    
//    if(flag._G)
//    {
//        // 
//    }
//    if(0 == flag._G)
//    {
//        //
//    }
    
    if(flag._Nxt)
    {
        LCD_xy(1,1);            // line 1, 1st slot
        text_display(arr13);
        LCD_xy(2,1);            // line 2, 1st slot
        text_display(arr14);
//  TODO: start timer here, wait to see if select button is pushed or next button 
//        is pushed, if no button is pushed and the timer runs out, go back to the start. 8-15-22
        if(0 == TimeOut)
            TimeOut = Time10s;  // load timer for 10 seconds
        
        if(flag._Sel)
        {
            FanSpeed();
        }
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
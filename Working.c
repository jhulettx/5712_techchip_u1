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
        if(stateflag._state4 == SET)
        {        
            // TODO: this does not display properly on line-1 8-22-22
            SendCommand(DispClr);   // clear display
            LCD_xy(1,1);            // line 1, 1st slot
            text_display(arr13);    // Fan Speed Test
            LCD_xy(2,2);            // line 2, 2nd slot
            text_display(arr8);     // Press Select
//            SwCounter = SwTime;     // load timer for 3 seconds
            TimeOut = Time10s;      // load timer for 10 seconds
            stateflag._state4 = CLEAR;
            _stay = 1;
            state = 5;
            BtnTimer = Tmr100ms;
        }
        
        test = 2;   // delete after testing
        if(0 == BtnTimer)
        {
            if(flag._Sel == SET)
            {
                TimeOut = 0;
                BtnTimer = Tmr100ms;
                stateflag._state6 = SET;
//                FanSpeed();
            }
            test = 1;
            if(state == 4)
            {
                nextCnt++;  // delete after testing
                if(flag._Nxt == SET)
                {
                    state = 5;
                    _wait = 1;  // set wait flag
                }
                if(_out == 1)   // is out flag set?
                {               // yes..
                    TimeOut = 0;
                    state = 0; 
                    stateflag._state0 = SET;
                }
            }
        }
        
        if(0 == TimeOut)    // did the time run out? 
        {                   // yes..
            state = 0;
            stateflag._state0 = SET;
        }
    } // end of state 4
    
    if(state == 5)  // next button held down state "TESTING" 8-25-22
    {
        if(flag._Nxt == CLEAR && _stay == 1)
            state = 4;
        
        if(flag._Nxt == CLEAR && _wait == 1)
        {
            state = 4;
            _out = 1;
        }
    } // end of state 5
    
    if(state == 6)
    {
        if(stateflag._state6 == SET)
        {
            SendCommand(DispClr);   // clear display
            LCD_xy(1,1);            // line 1, 1st slot
            text_display(arr13);    // Fan Speed Test
            LCD_xy(2,1);            // line 2, 1st slot
            text_display(arr14);    // Turn on G Start
            stateflag._state6 = CLEAR;
        }
    }
} // end of states
    
void Buttons(void)
{

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
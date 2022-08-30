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
        // TODO: finish this section 8-11-22    
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
        if(0 == BtnTimer)
        {
            test = 1;
            wast();
//            if(flag._Nxt == SET)
//            {
//                state = 4;
//                stateflag._state4 = SET;
//            }
        }
    } // end of state 0
    
    if(state == 1)
    {
       test = 1;
       wast();
    }
    
    if(state == 2)
    {
        test = 2;
        wast();
    }
    
    if(state == 3)  
    {
        test = 3;
        wast();
    }
    
    if(state == 4)  // speed test
    {        
        if(stateflag._state4 == SET)
        {        
            // TODO: this does not display properly there is a stray char on line-1, slot 1 8-22-22
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
        
        test = 1;   // delete after testing
        if(0 == BtnTimer)
        {
            if(flag._Sel == SET)
            {
                //TimeOut = 0;
                BtnTimer = Tmr100ms;
                state = 6;
                stateflag._state6 = SET;
                setCnt++;   // delete after testing
            }
            test = 2;
            if(state == 4)
            {
                if(flag._Nxt == SET)
                {
                //    state = 5;
                    _wait = 1;  // set wait flag
                //}
                //if(_out == 1)   // is out flag set?
                //{               // yes..
                    //TimeOut = 0;
                    state = 0; 
                    stateflag._state0 = SET;
                    BtnTimer = Tmr100ms;
                    nextCnt++;  // delete after testing
                }
            }
        }
        
        if(0 == TimeOut)    // did the time run out? 
        {                   // yes..
            state = 0;
            stateflag._state0 = SET;
            timeCnt++;
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
    
/************************************************************************
 *                      FAN SPEED TEST                                  *
 ************************************************************************/
void FanSpeed(void)
{
    
    
}

/********************************
 *      Dummy function          *
 ********************************/
void wast(void) // TODO: test this section and see if it works 8-30-22
{    
    if(flag._Nxt == SET)
    {
         Cstate++;
         
        if(Cstate > MaxState)
            Cstate = 0;
        state = Cstate;
    }
            
//   uint8_t i;
//   
//    for(i = 0; i < MaxState; ++i)
//    {
//        Cstate[i];        
//    } 
   
//   if(flag._Nxt == SET)
//    {
//        state = 4;
//        stateflag._state4 = SET;
//    }
}
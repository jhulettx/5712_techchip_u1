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
    if(state == 0)  // wait state
    {
        NxtBtn();   // go check next button
        
        if(swFlag._Ncycle == SET)   // has the next button cycled?
        {                           // yes..
            state = prvState;
            state++;
            swFlag._Ncycle = CLEAR;
        }
    } // end of state 0
    
//************************ STATE 1 ********************************
    if(state == 1)
    {
       test = 1; // delete after testing
//       NxtBtn();
//       if(stateflag._state1 == SET)
//       {
//           if(swFlag._Ncycle == SET)
//           {
               test = 1;    // delete after testing
//               swFlag._Ncycle = CLEAR;
               SendCommand(DispClr);    // clear display
               LCD_xy(1,1);             // line 1, 1st slot
//               sprintf(ste, "%s", arr13);
               text_display(arr13);      // print "fan speed test"
//               stateflag._state4 = CLEAR;
               prvState = state;    // copy current state to previous state
               state = 0;   // return to wait state
//           }
//        }
    } // end of state 1
    
//********************* STATE 2 *********************************
    if(state == 2)
    {
        test = 2;   // delete after testing
        SendCommand(DispClr);    // clear display
        LCD_xy(1,1);             // line 1, 1st slot
        sprintf(ste, "%s%d", arr15, state);
        text_display(ste);     // print state
        prvState = state;    // copy current state to previous state
        state = 0;   // return to wait state
        
//        if(stateflag._state2 = SET)
//        {
//            SendCommand(DispClr);    // clear display
//            LCD_xy(1,1);            // line 1, 1st slot
//            text_display(tst1);     // 
//            stateflag._state2 = CLEAR;
//            state = 1;
//        }
    }
    
//********************* STATE 3 ***************************
    if(state == 3)  
    {
        test = 3;
        SendCommand(DispClr);    // clear display
        LCD_xy(1,1);             // line 1, 1st slot
        sprintf(ste, "%s%d", arr15, state);
        text_display(ste);     // print state
        prvState = state;    // copy current state to previous state
        state = 0;   // return to wait state
    } // end of state 3
    
//************************ STATE 4 ********************************
    if(state == 4)  // speed test
    {        
        if(stateflag._state4 == SET)
        {        
            // TODO: this does not display properly there is a stray char on line-1, slot 1 8-22-22
            SendCommand(DispClr);   // clear display
//            LCD_xy(1,1);            // line 1, 1st slot
//            text_display(arr13);    // Fan Speed Test
//            LCD_xy(2,2);            // line 2, 2nd slot
//            text_display(arr8);     // Press Select
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
    
//********************* STATE 5 ****************************
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
    
//********************** STATE 6 ***************************
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
    } // end of state 6
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
//    if(flag._Nxt == SET)
//    {
//         Cstate++;
//         
//        if(Cstate > MaxState)
//            Cstate = 0;
//        state = Cstate;
//    }
            
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

/************************************************************************
 *                  NxtBtn                                              *
 ************************************************************************/
void NxtBtn(void)
{
    if(flag._Nxt == SET)
        swFlag._Ndown = SET;
    
    if(swFlag._Ndown == SET)
    {
        if(flag._Nxt == CLEAR)
        {
            swFlag._Ncycle = SET;
            swFlag._Ndown = CLEAR;
        }
    }
}

/************************************************************************
 *                  SelBtn                                              *
 ************************************************************************/
void SelBtn(void)
{
    if(flag._Sel == SET)
        swFlag._Sdown = SET;
    
    if(swFlag._Sdown = SET)
    {
        if(flag._Sel == CLEAR)
        {
            swFlag._Scycle = SET;
            swFlag._Sdown = CLEAR;
        }
    }
}
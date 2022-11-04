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
            if(stateflag._lock_state == CLEAR)
            {
                state++;
                switch(state)
                {
                    case 1:
                        stateflag._state1 = SET;
                        break;
                    case 2:
                        stateflag._state2 = SET;
                        break;
                    default:
                        break;
                }
            }
            swFlag._Ncycle = CLEAR;
        }
    } // end of state 0
    
//****** STATE 1 ****** FAN SPEED TEST **************************
    if(state == 1)
    {
        test = 1; // delete after testing
        if(stateflag._state1 == SET)
        {    
            LCDclear();             // clear display   
            LCD_xy(1,1);            // line 1, 1st slot
            text_display(arr13);    // Fan Speed Test
            LCD_xy(2,2);            // line 2, 2nd slot
            text_display(arr8);     // Press Select
            stateflag._state1 = CLEAR;
        }
            
        NxtBtn();  // see is next button has cycled
        SelBtn();  // see if select button has cycled 
        
        if(swFlag._Ncycle == SET)   // has the next button cycled?
        {                           // yes..
            prvState = state;       // copy current state to previous state
            state = 0;   // return to wait state
            swFlag._Ncycle = CLEAR;
        }
        
        if(swFlag._Scycle == SET)   // has the select button cycled?
        {                           // Yes..
            stateflag._lock_state = SET;
            prvState = state;       // copy current state to previous state
            swFlag._Scycle = CLEAR;
            stateflag._speed = SET; // signal start of speed test
        }
    test = 1;    // delete after testing
        if(stateflag._lock_state == SET)
            FanSpeed(); // go run fan speed test                   
    } // end of state 1
    
//********************* STATE 2 *********************************
    if(state == 2)
    {
        test = 2;   // delete after testing
//        SendCommand(DispClr);    // clear display
//        LCD_xy(1,1);             // line 1, 1st slot
//        sprintf(ste, "%s%d", arr15, state);
//        text_display(ste);     // print state
//        prvState = state;    // copy current state to previous state
//        state = 0;   // return to wait state
    }
    
//********************* STATE 3 ***************************
    if(state == 3)  
    {

    } // end of state 3
    
//************************ STATE 4 ********************************
    if(state == 4)  // speed test
    {        
        
    } // end of state 4
    
//********************* STATE 5 ****************************
    if(state == 5)  
    {
        
    } // end of state 5
    
//********************** STATE 6 ***************************
    if(state == 6)
    {
        
    } // end of state 6
} // end of states
    
/************************************************************************
 *                      FAN SPEED TEST                                  *
 ************************************************************************/
void FanSpeed(void)
{
    if(stateflag._speed == SET)
    {
        LCDclear();             // clear display
        LCD_xy(1,1);            // line 1, 1st slot
        text_display(arr13);    // Fan Speed Test
        LCD_xy(2,1);            // line 2, 1st slot
        text_display(arr14);    // Start Turn on G
        stateflag._speed = CLEAR;
        flag._LMH = SET;    // ok to put Low, Med, High on LCD screen
    }
    
    if(flag._G == SET)  // is the G input active?
    {                   // yes..
        if(flag._LMH == SET)    // is low medium high flag set?
        {                       // yes..
            LCDclear();             // clear display
            LCD_xy(1, 2);
            CG_print(0);            // down arrow
            LCD_xy(2, 1);           // line 2, 1st slot
            text_display(arr15);    // Low, Med, High
            flag._LMH = CLEAR;      // stop output to LCD
        }
        speed = Cspeed[z] = 1;
        test = 1;   // delete when done testing
    } 
    
    SelBtn();  // see if select button has cycled 
    
    if(swFlag._Scycle == SET)
    {
//TODO: if the select button cycles, increment the speed, if the speed goes 
//      to HI, reset it to LO, move down arrow over what ever speed is selected 11/4/22
        swFlag._Scycle = CLEAR;
    }
        if(speed == LO)
        {
            K4_SetHigh();
            K3_SetLow();
            K2_SetLow();
        } 

        if(speed == MED)
        {
            K4_SetHigh();
            K3_SetLow();
            K2_SetHigh();
        }

        if(speed == HI)
        {
            K4_SetHigh();
            K3_SetHigh();
            K2_SetHigh();
        }
}   // END of FanSpeed

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
    
    if(swFlag._Sdown == SET)
    {
        if(flag._Sel == CLEAR)
        {
            swFlag._Scycle = SET;
            swFlag._Sdown = CLEAR;
        }
    }
}
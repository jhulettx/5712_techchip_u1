/*******************************************************************************
* FileName:        Inputs.c
* Processor:       PIC18F45K22
* Compiler:        XC8 ver 2.05
*
* Author           Date:        Modified:      Comments:
* Jeff Hulett    07/12/2022                    
*******************************************************************************/

#include "Inputs.h"

FLAGS flag;

/*******************************************************************
 * Function: void ChkInput_sw(void)
 * Overview: check inputs for any changes
 * PreCondition: None
 * Input: None
 * Output: None 
 ********************************************************************/
void ChkInput_sw(void)
{   
    test = 1;   // delete when done testing.
    uint8_t xyz;
    
    if(flag._DeBouncing == false)
    {
        test = 0;   // delete when done testing
        if(LcdNext_GetValue() == 1)
        {
            Reg = 1;
            Reg = Reg << 1;
            flag._Nxt = OFF;    // next button is up
        }
        if(LcdNext_GetValue() == 0)
        {
            Reg = 0;
            Reg = Reg << 1;
            flag._Nxt = ON; // next button is down
        }
        
        if(LcdSel_GetValue() == 1)
        {
            Reg = Reg |= 1;
            Reg = Reg << 1;
            flag._Sel = OFF;    // selection button is up
        }
        if(LcdSel_GetValue() == 0)
        {
            Reg = Reg |= 0;
            Reg = Reg << 1;
            flag._Sel = ON; // selection button is down
        }

        if(W_GetValue() == 1)
        {
            Reg = Reg |= 1;
            Reg = Reg << 1;
            flag._W = OFF;
        }
        if(W_GetValue() == 0)
        {
            Reg = Reg |= 0;
            Reg = Reg << 1;
            flag._W = ON;   // W is active
        }

        if(GIN_GetValue() == 1)
        {
            Reg = Reg |= 1;
            flag._G = OFF;
        }
        if(GIN_GetValue() == 0)
        {
            Reg = Reg | 0;
            flag._G = ON;   // G is active
        }
 // TODO: set up states for the switch 
        switch(Reg_Cur)
        {
            case 0x0F:  // nothing active
                 state = 0;
                break;
            case 0x0D:  // W active
                state = 1;
                break;
            case 0x0E:  // G active 
                state = 2;
                break;
            case 0x0B:  // Select button pushed
                state = 3;
                break;
            case 0x05:  // W on, next pushed
                state = 4;
                break;
            case 0x07:  // Next button pushed
                state = 5;
                break;
            case 0x09:  // W on, select button pushed
                state = 6;
                break;
            default:
                break;
        }
        
        if(Reg_old != Reg) // is the new read same as the old read?
        {                  // NO..
            flag._DeBouncing = true;
            DebounceTime = DB_TIMER;
            Reg_old = Reg;  // move current reading to old reading
//            Reg_Cur = Reg;  // copy new reading to Reg_Cur
        }
        else
        {
            Reg_Cur = Reg;  // copy new reading to Reg_Cur
            return;
        }
    }
    test = 2;   // delete when done testing.
    if(DebounceTime)
        return;
    else
    {
        flag._DeBouncing = false;
    }
}
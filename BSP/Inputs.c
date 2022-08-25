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
    if(flag._DeBouncing == false)
    {
        test = 0;   // delete when done testing
        if(LcdNext_GetValue() == 1)
        {
            Reg = 1;
            Reg = Reg << 1;
//            flag._Nxt = OFF;    // next button is up
        }
        if(LcdNext_GetValue() == 0)
        {
            Reg = 0;
            Reg = Reg << 1;
//            flag._Nxt = ON; // next button is down
        }
        
        if(LcdSel_GetValue() == 1)
        {
            Reg = Reg |= 1;
            Reg = Reg << 1;
//            flag._Sel = OFF;    // selection button is up
        }
        if(LcdSel_GetValue() == 0)
        {
            Reg = Reg |= 0;
            Reg = Reg << 1;
//            flag._Sel = ON; // selection button is down
        }

        if(W_GetValue() == 1)
        {
            Reg = Reg |= 1;
            Reg = Reg << 1;
//            flag._W = OFF;
        }
        if(W_GetValue() == 0)
        {
            Reg = Reg |= 0;
            Reg = Reg << 1;
//            flag._W = ON;   // W is active
        }

        if(GIN_GetValue() == 1)
        {
            Reg = Reg |= 1;
//            flag._G = OFF;
        }
        if(GIN_GetValue() == 0)
        {
            Reg = Reg | 0;
//            flag._G = ON;   // G is active
        }
        
        if(Reg_old != Reg) // is the new read same as the old read?
        {                  // NO..
            flag._DeBouncing = true;
            DebounceTime = DB_TIMER;
            Reg_old = Reg;  // move current reading to old reading
        }
        else
        {
            Reg_Cur = Reg;  // copy new reading to Reg_Cur
        // TODO: set up flags 
        switch(Reg_Cur)
        {
            case 0x0F:  // nothing active
                flag._Nxt = OFF;    // next button is up
                flag._Sel = OFF;    // selection button is up
                flag._W = OFF;      // W switch is open
                flag._G = OFF;      // G switch is open
                break;
//            case 0x0D:  // W active

//                break;
//            case 0x0E:  // G active 

//                break;
            case 0x0B:  // Select button pushed
                flag._Sel = ON;     // selection button is down
                flag._Nxt = OFF;    // next button is up
                flag._W = OFF;      // W switch is open
                flag._G = OFF;      // G switch is open
                break;
            case 0x07:  // Next button pushed
                flag._Nxt = ON;     // next button is down
                flag._Sel = OFF;    // selection button is up
                flag._W = OFF;      // W switch is open
                flag._G = OFF;      // G switch is open
                break;
            default:
                break;
        }
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
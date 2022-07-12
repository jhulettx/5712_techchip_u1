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
//static void ChkInput_sw(void)
void ChkInput_sw(void)
{   
//    test = 1;   // delete when done testing.
    uint8_t xyz;
    
    if(flag._DeBouncing == false)
    {
        if(LcdNext_GetValue())
        {
            Reg = 1;
            Reg = Reg << 1;
//            flag._Nxt = OFF;    // next button is up
        }
        else
        {
            Reg = 0;
            Reg = Reg << 1;
//            flag._Nxt = ON; // next button is down
        }

        if(LcdSel_GetValue())
        {
//            Reg = Reg |= 1;
//            Reg = Reg << 1;
            flag._Sel = OFF;    // selection button is up
        }
        else
        {
//            Reg = Reg |= 0;
//            Reg = Reg << 1;
            flag._Sel = ON; // selection button is down
        }

        if(W_GetValue())
        {
//            Reg = Reg |= 1;
//            Reg = Reg << 1;
            flag._W = OFF;
        }
        else
        {
//            Reg = Reg |= 0;
//            Reg = Reg << 1;
            flag._W = ON;   // W is active
        }

        if(GIN_GetValue())
        {
//            Reg = Reg |= 1;
            flag._G = OFF;
        }
        else
        {
//            Reg = Reg | 0;
            flag._G = ON;   // G is active
        }
 // TODO: add flag setting to the switch    
        switch(Reg_Cur)
        {
            case 0x0F:  // nothing active
                flag._G = OFF;
                flag._W = OFF;
                flag._Sel = OFF;
                flag._Nxt = OFF;
                break;
            case 0x0D:  // W active
                
                break;
            case 0x0E:  // G active 
                
                break;
            case 0x0B:  // Select button pushed
                
                break;
            case 0x05:  // W on, next pushed
                
                break;
            case 0x07:  // Next button pushed
                
                break;
            case 0x09:  // W on, select button pushed
                
                break;
            default:
                break;
        }
        
        if(Reg_old != Reg) // is the new read same as the old read?
        {                  // NO..
            flag._DeBouncing = true;
            DebounceTime = DB_TIMER;
            Reg_old = Reg;  // move current reading to old reading
            //Reg_Cur = Reg;  // copy new reading to Reg_Cur
        }
        else
            return;
    }
    test = 2;   // delete when done testing.
    if(DebounceTime)
        return;
    else
    {
        flag._DeBouncing = false;
    }
}
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
 *                         SWITCHES                                         *
 ****************************************************************************/
void switches(void)
{
    test = 4;
    uint8_t data;
    
    if(Reg_Cur != Reg_old)  
    {                       // does reg cur = reg old?
        Reg_Cur = Reg_old;  // no.. make them the same
        flag._RegDiff = true; // turn on difference flag
        
        switch(Reg_Cur)
        {
            case 0x0F:  // nothing active
                data = 0x0F; //
                display(data);
                break;
            case 0x0D:  // W active
                data = 0x0D; //
                K1_SetHigh();
                display(data);   //
                break;
            case 0x0E:  // G active 
                data = 0x0E; //
                display(data); //
                break;
            case 0x0B:  // Select button pushed
                data = 0x0B; //
                display(data); //
                break;
            case 0x05:  // W on, next pushed
                data = 0x05;
                break;
            case 0x07:  // Next button pushed
                data = 0x07; //
                display(data); //
                break;
            case 0x09:  // W on, select button pushed
                data = 0x09;
                break;
            default:
                break;
        }
    }
    if(flag._RegDiff)
        flag._RegDiff = false;   // turn off flag
}

void Buttons(void)
{
    //TODO finish this function
}

/************************************************************************
 *              display                                                 *
 ************************************************************************/
void display(uint8_t data)
{
    if(data == 0x0F)
    {
        LCD_xy(2,2);            // line 2, 2nd slot
        text_display(arr10);    // normal
    }
    if(data == 0x0D)
    {
        LCD_xy(2,2);            // line 2, 2nd slot
        text_display(arr11);    // W active
    }
    if(data == 0x0E)
    {
        LCD_xy(2,2);            // line 2, 2nd slot
        text_display(arr12);    // G active
    }
    if(data == 0x0B)
    {
        LCD_xy(2,2);            // line 2, 2nd slot
        text_display(arr8);     // select button pushed
    }
    if(data == 0x07)
    {
        LCD_xy(2,2);            // line 2, 2nd slot
        text_display(arr9);     // next button pushed
    }
}
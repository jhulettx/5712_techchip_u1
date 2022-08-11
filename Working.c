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
    if(state == 0)
    {
        
    }
    
    if(state == 1)
    {
        
    }
}

void Buttons(void)
{
    //TODO finish this function
    if(flag._W)
    {
        // turn something on
    }
    if(0 == flag._W)
    {
        // turn something off
    }
    
    if(flag._G)
    {
        // 
    }
    if(0 == flag._G)
    {
        //
    }
    
    if(flag._Nxt)
    {
        //
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
/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K22
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"
#include "Application/Global.h"
#include "BSP/Timer_1ms.h"

//#include <stdint.h>
//#include <stdbool.h>
//#include <stdio.h>

void rd_state(void);
void LCDinit(void);
void text_display(char *);
void LCD_xy( unsigned int X, unsigned int Y);
void controlInitialize(void);

uint8_t state;

extern void switches(void);

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    LCDinit();
    controlInitialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptDisable();
    
    TMR1_SetInterruptHandler(TMR1_CallBack);
    // wait for W to turn on, if W is turned on, k1 and k4 turn on,
	// when jumper j23 is shorted, k2 turns on.
    
    state = 0;

    LCD_xy(1,2);            // line 1, 1st slot
    text_display(arr1);
    LCD_xy(2,2);            // line 2, 2nd slot
    text_display(arr2);
    
    while (1)
    {  
        __delay_ms(50); // delete after testing
        switches(); // handle switch press
//        rd_state();
//        if(1 == state)
//        {
//            K4_SetHigh();
//            __delay_ms(10);
//            K1_SetHigh();
//            LED_SetHigh();
//        }
//        else if(0 == state)
//        {
//            LED_SetLow();
//            K4_SetLow();
//            __delay_ms(10);
//            K1_SetLow();
//        }
//        __delay_ms(200);
//        if(!EP_GetValue())
//            K2_SetHigh();
//        else
//            K2_SetLow();
    }
}
/**
 End of File
*/

void rd_state(void)
{
    if(W_GetValue())    // see if W is on
        state = 0;      // W is off
    
    if(!W_GetValue())   // see if W is on
        state = 1;      // W is on
}
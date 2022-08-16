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

void LCDinit(void);
extern void text_display(unsigned char *);
void LCD_xy( unsigned int X, unsigned int Y);
void controlInitialize(void);
//extern void ChkInput_sw(void);

uint8_t state;

extern void switches(void);
extern void Time_Count(void);

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
    TMR3_SetInterruptHandler(Time_Count);   // TODO: build timer 3 timer file
    // wait for W to turn on, if W is turned on, k1 and k4 turn on,
	// when jumper j23 is shorted, k2 turns on.
    
    state = 0;

    LCD_xy(1,2);            // line 1, 1st slot
    text_display(arr1);
    LCD_xy(2,2);            // line 2, 2nd slot
    text_display(arr2);
    
    while(1)
    {  
        __delay_ms(10); // delete after testing
//        ChkInput_sw();
//        switches(); // handle switch press
//        rd_state();
    }   // end of while(1)
}   // end of main
/**
 End of File
*/

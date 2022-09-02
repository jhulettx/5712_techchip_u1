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

stateflags stateflag;

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
    TMR3_SetInterruptHandler(Time_Count);   
        
    state = 0;  // start with state 0
    stateflag._state0 = SET;    // set state0 flag
    state = 1;  // delete after testing
    
    while(1)
    {  
        __delay_ms(10); // delete after testing

    }   // end of while(1)
}   // end of main
/**
 End of File
*/

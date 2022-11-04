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
//#include "Application/Control.h"
#include "BSP/Timer_1ms.h"
#include "BSP/ClkTimer.h"
#include "LCD.h"

//void LCDinit(void);
//extern void text_display(unsigned char *);
//void LCD_xy( unsigned int X, unsigned int Y);
void controlInitialize(void);
//extern void Create_Cust_Chars(int location, char *p);
//extern void createChar(uint8_t charmap[]);
//extern void switches(void);
extern void Time_Count(void);

uint8_t state;

//#define DispClr     0b00000001  // clear the display

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
    prvState = state;   // make sure prvState = current state
//    stateflag._state0 = SET;    // set state0 flag
    Create_Cust_Chars(0, arrow);
    Create_Cust_Chars(1, blank);
    
//    SendCommand(DispClr);    // clear display
    LCD_xy(1,2);            // line 1, 1st slot
    text_display(arr1);     // 5712 TEST
    LCD_xy(2,2);            // line 2, 2nd slot
    text_display(arr2);     // Next to start
    test = 0;   // delete after testing
    
    while(1)
    {  
        __delay_ms(10); // delete after testing

    }   // end of while(1)
}   // end of main
/**
 End of File
*/

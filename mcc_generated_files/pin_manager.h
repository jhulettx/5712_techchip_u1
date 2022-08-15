/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA1
#define POT_LAT                  LATAbits.LATA1
#define POT_PORT                 PORTAbits.RA1
#define POT_ANS                  ANSELAbits.ANSA1
#define POT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT_GetValue()           PORTAbits.RA1
#define POT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set HI aliases
#define HI_TRIS                 TRISAbits.TRISA2
#define HI_LAT                  LATAbits.LATA2
#define HI_PORT                 PORTAbits.RA2
#define HI_ANS                  ANSELAbits.ANSA2
#define HI_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HI_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HI_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HI_GetValue()           PORTAbits.RA2
#define HI_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HI_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HI_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define HI_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set ADREF aliases
#define ADREF_TRIS                 TRISAbits.TRISA3
#define ADREF_LAT                  LATAbits.LATA3
#define ADREF_PORT                 PORTAbits.RA3
#define ADREF_ANS                  ANSELAbits.ANSA3
#define ADREF_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define ADREF_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define ADREF_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define ADREF_GetValue()           PORTAbits.RA3
#define ADREF_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define ADREF_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define ADREF_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define ADREF_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set GIN aliases
#define GIN_TRIS                 TRISAbits.TRISA4
#define GIN_LAT                  LATAbits.LATA4
#define GIN_PORT                 PORTAbits.RA4
#define GIN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define GIN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define GIN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define GIN_GetValue()           PORTAbits.RA4
#define GIN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define GIN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set MED aliases
#define MED_TRIS                 TRISAbits.TRISA5
#define MED_LAT                  LATAbits.LATA5
#define MED_PORT                 PORTAbits.RA5
#define MED_ANS                  ANSELAbits.ANSA5
#define MED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define MED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define MED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define MED_GetValue()           PORTAbits.RA5
#define MED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define MED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define MED_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define MED_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set K5 aliases
#define K5_TRIS                 TRISBbits.TRISB0
#define K5_LAT                  LATBbits.LATB0
#define K5_PORT                 PORTBbits.RB0
#define K5_WPU                  WPUBbits.WPUB0
#define K5_ANS                  ANSELBbits.ANSB0
#define K5_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define K5_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define K5_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define K5_GetValue()           PORTBbits.RB0
#define K5_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define K5_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define K5_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define K5_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define K5_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define K5_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set K4 aliases
#define K4_TRIS                 TRISBbits.TRISB1
#define K4_LAT                  LATBbits.LATB1
#define K4_PORT                 PORTBbits.RB1
#define K4_WPU                  WPUBbits.WPUB1
#define K4_ANS                  ANSELBbits.ANSB1
#define K4_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define K4_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define K4_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define K4_GetValue()           PORTBbits.RB1
#define K4_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define K4_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define K4_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define K4_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define K4_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define K4_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set K3 aliases
#define K3_TRIS                 TRISBbits.TRISB2
#define K3_LAT                  LATBbits.LATB2
#define K3_PORT                 PORTBbits.RB2
#define K3_WPU                  WPUBbits.WPUB2
#define K3_ANS                  ANSELBbits.ANSB2
#define K3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define K3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define K3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define K3_GetValue()           PORTBbits.RB2
#define K3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define K3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define K3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define K3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define K3_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define K3_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set K2 aliases
#define K2_TRIS                 TRISBbits.TRISB3
#define K2_LAT                  LATBbits.LATB3
#define K2_PORT                 PORTBbits.RB3
#define K2_WPU                  WPUBbits.WPUB3
#define K2_ANS                  ANSELBbits.ANSB3
#define K2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define K2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define K2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define K2_GetValue()           PORTBbits.RB3
#define K2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define K2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define K2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define K2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define K2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define K2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set K1 aliases
#define K1_TRIS                 TRISBbits.TRISB4
#define K1_LAT                  LATBbits.LATB4
#define K1_PORT                 PORTBbits.RB4
#define K1_WPU                  WPUBbits.WPUB4
#define K1_ANS                  ANSELBbits.ANSB4
#define K1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define K1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define K1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define K1_GetValue()           PORTBbits.RB4
#define K1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define K1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define K1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define K1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define K1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define K1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISBbits.TRISB5
#define LED_LAT                  LATBbits.LATB5
#define LED_PORT                 PORTBbits.RB5
#define LED_WPU                  WPUBbits.WPUB5
#define LED_ANS                  ANSELBbits.ANSB5
#define LED_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LED_GetValue()           PORTBbits.RB5
#define LED_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LED_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RW aliases
#define RW_TRIS                 TRISCbits.TRISC0
#define RW_LAT                  LATCbits.LATC0
#define RW_PORT                 PORTCbits.RC0
#define RW_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RW_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RW_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RW_GetValue()           PORTCbits.RC0
#define RW_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISCbits.TRISC1
#define RS_LAT                  LATCbits.LATC1
#define RS_PORT                 PORTCbits.RC1
#define RS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RS_GetValue()           PORTCbits.RC1
#define RS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISCbits.TRISC2
#define E_LAT                  LATCbits.LATC2
#define E_PORT                 PORTCbits.RC2
#define E_ANS                  ANSELCbits.ANSC2
#define E_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define E_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define E_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define E_GetValue()           PORTCbits.RC2
#define E_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define E_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define E_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set W aliases
#define W_TRIS                 TRISCbits.TRISC5
#define W_LAT                  LATCbits.LATC5
#define W_PORT                 PORTCbits.RC5
#define W_ANS                  ANSELCbits.ANSC5
#define W_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define W_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define W_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define W_GetValue()           PORTCbits.RC5
#define W_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define W_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define W_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define W_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD0
#define D4_LAT                  LATDbits.LATD0
#define D4_PORT                 PORTDbits.RD0
#define D4_ANS                  ANSELDbits.ANSD0
#define D4_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define D4_GetValue()           PORTDbits.RD0
#define D4_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define D4_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISDbits.TRISD1
#define D5_LAT                  LATDbits.LATD1
#define D5_PORT                 PORTDbits.RD1
#define D5_ANS                  ANSELDbits.ANSD1
#define D5_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define D5_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define D5_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define D5_GetValue()           PORTDbits.RD1
#define D5_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define D5_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISDbits.TRISD2
#define D6_LAT                  LATDbits.LATD2
#define D6_PORT                 PORTDbits.RD2
#define D6_ANS                  ANSELDbits.ANSD2
#define D6_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define D6_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define D6_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define D6_GetValue()           PORTDbits.RD2
#define D6_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define D6_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISDbits.TRISD3
#define D7_LAT                  LATDbits.LATD3
#define D7_PORT                 PORTDbits.RD3
#define D7_ANS                  ANSELDbits.ANSD3
#define D7_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D7_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D7_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D7_GetValue()           PORTDbits.RD3
#define D7_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define D7_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set LcdNext aliases
#define LcdNext_TRIS                 TRISDbits.TRISD4
#define LcdNext_LAT                  LATDbits.LATD4
#define LcdNext_PORT                 PORTDbits.RD4
#define LcdNext_ANS                  ANSELDbits.ANSD4
#define LcdNext_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LcdNext_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LcdNext_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LcdNext_GetValue()           PORTDbits.RD4
#define LcdNext_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LcdNext_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LcdNext_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define LcdNext_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set LcdSel aliases
#define LcdSel_TRIS                 TRISDbits.TRISD5
#define LcdSel_LAT                  LATDbits.LATD5
#define LcdSel_PORT                 PORTDbits.RD5
#define LcdSel_ANS                  ANSELDbits.ANSD5
#define LcdSel_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LcdSel_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LcdSel_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LcdSel_GetValue()           PORTDbits.RD5
#define LcdSel_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LcdSel_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LcdSel_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define LcdSel_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set LO aliases
#define LO_TRIS                 TRISEbits.TRISE0
#define LO_LAT                  LATEbits.LATE0
#define LO_PORT                 PORTEbits.RE0
#define LO_ANS                  ANSELEbits.ANSE0
#define LO_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LO_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LO_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LO_GetValue()           PORTEbits.RE0
#define LO_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LO_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LO_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define LO_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
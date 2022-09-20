/* 
 * File: Control.h  
 * Author: loganbenda
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "Global.h"

extern void states(void);


//******************************************************************************
// Application related definitions
//******************************************************************************
#define SWITCH_DEBOUNCE_TIME_MS 10
#define TIMER_SEC   1000      // 1 second timer
//#define DB_TIMER    20        // debounce timer 20ms

//****************** RAM ***************************************
uint8_t DebounceTime;
uint8_t SW_inputs;  // switch inputs
uint8_t Jmp_inputs; // jumper inputs
uint8_t Reg;        // digital inputs register
uint8_t Reg_old;    // old reading of register

//volatile int32_t control;	//control variable


/*********************************************************************
* Function: void controlInitialize(void)
* Overview: Initializes the boiler control by configuring the required peripherals.
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void controlInitialize(void);

/*********************************************************************
* Function: void controlTasks(void)
* Overview: Control task function which updates the value of the
*           commanded PWM to enable proper temperature control
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void controlTasks(void);

/*********************************************************************
* Function: void adc_isr(void)
* Overview: TMR5 interrupt service routine (10ms) refresh
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void adc_isr(void);

/*********************************************************************
* Function: void GetInputStartValue(void)
* 
* Overview: get initial values from switch inputs
* PreCondition: None
* Input:  None
* Output: None
********************************************************************/
//void GetInputStartValue(void);

/************************************************************************
* Function: void debounceISR(void)
* 
* Overview: handle de bounce timer, clear flag when DebounceTime is zero
* PreCondition: None
* Input:  None
* Output: None
*************************************************************************/
void debounceISR(void);

//
void RdBtn(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


/***********************************************************************
 * File:   Control.c
 * Author: jhulett
 *
 * Created:  June 26, 2022
 *  
 ***********************************************************************/

//******************************************************************************
// Control Library Version 1.0.0
// 
// Revision: 1.0
// 
// Description: The main library for enabling boiler temperature control
//******************************************************************************

//******************************************************************************
// Headers
//******************************************************************************
//#include "../BSP/Inputs.h"
#include "../BSP/Timer_1ms.h"
//#include "../mcc_generated_files/adc1.h"
#include "../mcc_generated_files/pin_manager.h"
#include "../Application/Control.h"

//extern PINInputs pin;
//extern GlobalControl global;
//extern PINOutputs outputs;
FLAGS flag;

extern void display(uint8_t data);
void ChkInput_sw(void);

//***************************************************************************
// Function Prototypes
//***************************************************************************
//static void debounceISR(void);
//static void ChkInput_sw(void);

//***************************************************************************
// Global Variables
//***************************************************************************


/***************************************************************************
* Function: void controlInitialize(void)
*
* Overview: Initializes the boiler control by configuring the required 
 *          peripherals.
* PreCondition: None
*
* Input:  None
* Output: None
****************************************************************************/
void controlInitialize(void)
{   
    //Turn on a timer, to generate periodic interrupts.
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    
    flag._DeBouncing = false;
     
    //Register callback functions, so it gets called periodically
    //when the timer interrupts occur,
    //(in this case at 1:1 rate, so debounceISR()
    //executes once per 1ms).
    TIMER_RequestTick(&debounceISR, 1);
    TIMER_RequestTick(&controlTasks, 1);    
    TIMER_RequestTick(&states, 1);          // check states (Working.c)
}

/*********************************************************************
* Function: void controlTasks(void)
* Overview: Control task out to Inputs.c
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void controlTasks(void)
{ 
        ChkInput_sw();
}

/*********************************************************************
* Function: static void adc_isr(void)
*
* Overview: TMR5 interrupt service routine (10ms) refresh
*
* PreCondition: None
*
* Input:  None
*
* Output: None
********************************************************************/
void adc_isr(void)
{    
//    ADC1_SoftwareTriggerDisable();  
}

/****************************************************************************
 * Function: static void debounceISR(void)
 * Overview: for switch de-bouncing
 * Input: none
 * Output: none
 ****************************************************************************/
void debounceISR(void)
{
    test = 99;  // delete after testing.
    if(flag._DeBouncing == true)
    {
        DebounceTime--;
    }
    
    if(0 == DebounceTime)
        flag._DeBouncing = false;
    
    if(BtnTimer)
        --BtnTimer;
}

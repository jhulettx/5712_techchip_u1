/***********************************************************************
 * File:   Control.c
 * Author: jhulett
 *
 * Created:  June 26, 2022
 *  
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

//******************************************************************************
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
    GetInputStartValue();
//    ChkInput_sw();
    
    flag._DeBouncing = false;
     
    //Register callback functions, so it gets called periodically
    //when the timer interrupts occur,
    //(in this case at 1:1 rate, so debounceISR()
    //executes once per 1ms).
    TIMER_RequestTick(&debounceISR, 1);
    TIMER_RequestTick(&RdBtn, 1); 
    TIMER_RequestTick(&controlTasks, 1); 
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
    //if(flag._InputChg)
        ChkInput_sw();
}

/*********************************************************************
* Function: void RdBtn(void)
* Overview: send flow to Working.c
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void RdBtn(void)
{
    Buttons();
}

/********************************************************************
 * Function: GetInputStartValue.c                                   *
 * Input:  G, W, LCDNext, LCDSel                                    *
 * Output: Reg                                                      *
 * Overview: On start up this function is called to set initial     *
 *           states of inputs.                                      *
 ********************************************************************/
void GetInputStartValue(void)
{
    Reg = 0;    // make sure register is clear
//    test = 0; // delete when done testing
    if(LcdNext_GetValue())
    {
        flag._Nxt = OFF;    // next button is up
    }
    else
    {
        flag._Nxt = ON; // next button is down
    }
    
    if(LcdSel_GetValue())
    {
        flag._Sel = OFF;    // selection button is up
    }
    else
    {
        flag._Sel = ON; // selection button is down
    }
    
    if(W_GetValue())
    {
        flag._W = OFF;
    }
    else
    {
        flag._W = ON;   // W is active
    }
    
    if(GIN_GetValue())
    {
        flag._G = OFF;
    }
    else
    {
        flag._G = ON;   // G is active
    }
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
    if(flag._DeBouncing == true)
    {
        DebounceTime--;
    }
    
    if(0 == DebounceTime)
        flag._DeBouncing = false;
}

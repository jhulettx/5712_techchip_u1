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
//    GetInputStartValue();
    ChkInput_sw();
    
    flag._DeBouncing = false;
     
    //Register callback functions, so it gets called periodically
    //when the timer interrupts occur,
    //(in this case at 1:1 rate, so debounceISR()
    //executes once per 1ms).
    TIMER_RequestTick(&debounceISR, 1);
    TIMER_RequestTick(&ChkInput_sw, 1); 
}

/*********************************************************************
* Function: void controlTasks(void)
* Overview: Control task
*
* PreCondition: None
*
* Input:  None
* Output: None
********************************************************************/
void controlTasks(void)
{ 
    //if(flag._InputChg)
        //ChkInput_sw();
}

/*******************************************************************
 * Function: void ChkInput_sw(void)
 * Overview: check inputs for any changes
 * PreCondition: None
 * Input: None
 * Output: None 
 ********************************************************************/
static void ChkInput_sw(void)
{   
//    test = 1;   // delete when done testing.
    uint8_t data;
    
    if(flag._DeBouncing == false)
    {
        if(LcdNext_GetValue())
        {
            Reg = 1;
            Reg = Reg << 1;
//            flag._Nxt = OFF;    // next button is up
        }
        else
        {
            Reg = 0;
            Reg = Reg << 1;
//            flag._Nxt = ON; // next button is down
        }

        if(LcdSel_GetValue())
        {
//            Reg = Reg |= 1;
//            Reg = Reg << 1;
            flag._Sel = OFF;    // selection button is up
        }
        else
        {
//            Reg = Reg |= 0;
//            Reg = Reg << 1;
            flag._Sel = ON; // selection button is down
        }

        if(W_GetValue())
        {
//            Reg = Reg |= 1;
//            Reg = Reg << 1;
            flag._W = OFF;
        }
        else
        {
//            Reg = Reg |= 0;
//            Reg = Reg << 1;
            flag._W = ON;   // W is active
        }

        if(GIN_GetValue())
        {
//            Reg = Reg |= 1;
            flag._G = OFF;
        }
        else
        {
//            Reg = Reg | 0;
            flag._G = ON;   // G is active
        }
 // TODO: add flag setting to the switch    
        switch(Reg_Cur)
        {
            case 0x0F:  // nothing active
                flag._G = OFF;
                flag._W = OFF;
                flag._Sel = OFF;
                flag._Nxt = OFF;
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
        
        if(Reg_old != Reg) // is the new read same as the old read?
        {                  // NO..
            flag._DeBouncing = true;
            DebounceTime = DB_TIMER;
            Reg_old = Reg;  // move current reading to old reading
            //Reg_Cur = Reg;  // copy new reading to Reg_Cur
        }
        else
            return;
    }
    
//    test = 2;   // delete when done testing.
    if(DebounceTime)
        return;
    else
    {
        flag._DeBouncing = false;
    }
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
//        Reg = 1;
//        Reg = Reg << 1;
        flag._Nxt = OFF;    // next button is up
    }
    else
    {
//        Reg = 0;
//        Reg = Reg << 1;
        flag._Nxt = ON; // next button is down
    }
    
    if(LcdSel_GetValue())
    {
//        Reg = Reg |= 1;
//        Reg = Reg << 1;
        flag._Sel = OFF;    // selection button is up
    }
    else
    {
//        Reg = Reg |= 0;
//        Reg = Reg << 1;
        flag._Sel = ON; // selection button is down
    }
    
    if(W_GetValue())
    {
//        Reg = Reg |= 1;
//        Reg = Reg << 1;
        flag._W = OFF;
    }
    else
    {
//        Reg = Reg |= 0;
//        Reg = Reg << 1;
        flag._W = ON;   // W is active
    }
    
    if(GIN_GetValue())
    {
//        Reg = Reg |= 1;
        flag._G = OFF;
    }
    else
    {
//        Reg = Reg |= 0;
        flag._G = ON;   // G is active
    }
//    Reg_old = Reg;  // move Reg to Reg old
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

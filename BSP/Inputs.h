/* 
 * File:   Inputs.h
 * Author: jhulett
 *
 * Created on July 12, 2022, 12:25 PM
 */

#ifndef INPUTS_H
#define	INPUTS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../Application/Global.h"
#include "../mcc_generated_files/pin_manager.h"

//**** definitions ********************************************************
//    #define DB_TIMER    20        // debounce timer 20ms
    #define DB_TIMER    5        // delete after testing

//******************* RAM *************************************************
extern uint8_t Reg;        // digital inputs register
extern uint8_t Reg_old;    // old reading of register
extern uint8_t DebounceTime;    
    
///************************************************************************
//* Function: static void ChkInput_sw(void)
//* 
//* Overview: get values from switch inputs to see which ones changed state
// *          turn on or off LED's accordingly.
//* PreCondition: None
//* Input:  None
//* Output: None
//*************************************************************************/
//static void ChkInput_sw(void);
void ChkInput_sw(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INPUTS_H */


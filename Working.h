/* 
 * File:   Working.h
 * Author: jhulett
 *
 * Created on June 13, 2022, 3:01 PM
 */

#ifndef WORKING_H
#define	WORKING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Application/Global.h"
#include "LCD.h"
#include "mcc_generated_files/pin_manager.h"

    
    extern void ChkInput_sw(void);
    
#define Time10s 10  // used for time out in state section 10 seconds
#define Tmr100ms 100 // 100ms timer
#define SwTime 3    // used for switch timing, 3 seconds.
#define MaxState 7  // maximum number of states to cycle through
    
// ****************** RAM *******************************
    //uint8_t Reg_old;
    uint8_t nextCnt;    // how many times the next btn pushed delete after testing
    uint8_t setCnt;     // how many times the set btn pushed, delete after testing
    uint8_t timeCnt;    // how many times we went to time out, delete after testing
    uint8_t Cstate;     // holds the current state
    
//********************* FLAGS ***************************
    bool _wait;
    bool _out;
    bool _stay;
        
/***************************************************************************
* Function: void states(void)
* Overview: take the state from Inputs.c and find the corresponding state,
 *          and execute code. 
*
* PreCondition: None
*
* Input:  state
* Output: None
****************************************************************************/
void states(void);

/***************************************************************************
* Function: void FanSpeed(void)
* Overview: set up the fan speed control for low, med, hi 
*
* PreCondition: None
*
* Input:  None
* Output: None
****************************************************************************/
void FanSpeed(void);

/***************************************************************************
* Function: void Buttons(data)
* Overview:  
*
* PreCondition: None
*
* Input:  None
* Output: None
****************************************************************************/
void Buttons(void);

void wast(void);

#ifdef	__cplusplus
}
#endif

#endif	/* WORKING_H */


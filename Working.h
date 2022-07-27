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
    
// ****************** RAM *******************************
    uint8_t Reg_old;
    
/***************************************************************************
* Function: void switches(void)
* Overview: take Reg_Cur and compare to 4 choices, then execute that code. 
*
* PreCondition: None
*
* Input:  Reg_Cur
* Output: None
****************************************************************************/
void switches(void);

/***************************************************************************
* Function: void display(data)
* Overview: take data and display it on line 2 of the LCD display. 
*
* PreCondition: None
*
* Input:  data
* Output: None
****************************************************************************/
void display(uint8_t data);

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

#ifdef	__cplusplus
}
#endif

#endif	/* WORKING_H */


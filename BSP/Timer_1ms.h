/* 
 * File:   Timer_1ms.h
 * Author: loganbenda
 *
 * Created on February 28, 2022, 3:36 PM
 */

/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <xc.h>
#include <string.h>

#ifndef TIMER_1S_H
#define TIMER_1S_H


#define TIMER_TICK_INTERVAL_MICRO_SECONDS 1000

/* Type Definitions ***********************************************/
typedef void (*TICK_HANDLER)(void);
typedef void (*TICK_HANDLER_t)(void);

typedef enum
{
    TIMER_CONFIGURATION_1MS,
    TIMER_CONFIGURATION_OFF
} TIMER_CONFIGURATIONS;

//uint32_t MS_timer;

/*********************************************************************
* Function: void TIMER_CancelTick(TICK_HANDLER handle)
*
* Overview: Cancels a tick request.
*
* PreCondition: None
*
* Input:  handle - the function that was handling the tick request
*
* Output: None
*
********************************************************************/
void TIMER_CancelTick(TICK_HANDLER handle);

/*********************************************************************
* Function: bool TIMER_RequestTick(TICK_HANDLER handle, uint32_t rate)
*
* Overview: Requests to receive a periodic event.
*
* PreCondition: None
*
* Input:  handle - the function that will be called when the time event occurs
*         rate - the number of ticks per event.
*
* Output: bool - true if successful, false if unsuccessful
*
********************************************************************/
bool TIMER_RequestTick(TICK_HANDLER handle, uint32_t rate);

/*********************************************************************
* Function: bool TIMER_SetConfiguration(TIMER_CONFIGURATIONS configuration)
*
* Overview: Initializes the timer.
*
* PreCondition: TIMER_CONFIGURATIONS - configuration to run
*
* Input:  None
*
* Output: bool - true if successful, false if unsuccessful
*
********************************************************************/
bool TIMER_SetConfiguration(TIMER_CONFIGURATIONS configuration);

//************************************************************************
void TMR1_CallBack(void);

#endif //TIMER_1S_H


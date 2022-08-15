/* 
 * File: Timer1.h
 * Author: Jeff Hulett
 * Comments: keeps track on timer 1, called every 100ms, from interrupt.
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
//#include "mcc_generated_files/pin_manager.h"

//***************** definitions ********************
//#define HB_LED_SetHigh()          (_LATG3 = 1)  // from pin_manager.h
//#define HB_LED_SetLow()           (_LATG3 = 0)  // "            "

// RAM
uint8_t LED_TMR;
uint8_t volatile m1_sec_100, seconds;   // for timing in timer 3
uint8_t PwrTimer;
uint8_t TimerMain;  // main loop timer
uint8_t volatile CDT_1;      // count down timer 1, used for various timers

// external RAM
//extern uint8_t pwm_on_time; // holds how many seconds stage 1 is on
//extern uint8_t pwm_off_time;// holds how many seconds stage 1 is off
//extern uint8_t stg2_on_dly; // delay stage 2 turn on
//extern uint8_t stg2_cyc_dly;// stage 2 anticycling delay
//extern uint8_t timer;       // timer for set point read

// definitions
//#define DELAY_A 10  // used for PWM stuff
//#define DELAY_B 8   // used for PWM stuff

// TODO Insert declarations
void Time_Count(void);

// Flags
struct     // time keeping flags
{
    bool _HB_LED;   // heartbeat LED flag 
    bool _sec;      // one second has passed flag
    bool _HS;       // half second flag, for half second timing 
}Timers;

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


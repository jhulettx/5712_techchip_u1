/* 
 * File:   Global.h
 * Author: jhulett
 *
 * Created on May 17, 2022, 1:48 PM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

    typedef enum    
    {
        INACTIVE,
        ACTIVE
    }
    status;
    
    typedef enum    // used in inputs
    {
        OFF,
        ON
    }
    onn;
    
    typedef enum
    {
        CLEAR,
        SET
    } set;
    
//    typedef enum
//    {
//        state0,
//        state1,
//        state2,
//        state3,
//        state4
//    }Dstate;
    
    // RELAYS
    typedef struct
    {
        // state of inputs
        // INACTIVE:  Pin Input is off.
        // ACTIVE: Pin Input is on.
        bool _k1;
        bool _k2;
        bool _k3;
        bool _k4;
        bool _k5;
    }Relay;
    
    // FLAGES
    typedef struct
    {
        bool _BtnBusy;      // 1 = the button is pressed and held down, 0 = button is up
        bool _DeBouncing;   // 1 = debounce in progress
        bool _LMH;          // 1 = print Low, Med, High 0 = stop printing
        bool _W;            // 1 = no W call, 0 = W active
        bool _G;            // 1 = no G call, 0 = G active
        bool _Sel;          // 1 = select button is up, 0 = button is pressed
        bool _Nxt;          // 1 = next button is up, 0 = button is pressed
        bool _Busy;         // 1 = a test is in process, 0 = not running any test
        bool _First;        // 1 = this is the first time through the loop
    } FLAGS;

    typedef struct
    {
        bool _state0;       // 1 = state 0 LCD is being printed 0 = stop writing to LCD
        bool _state1;       // 1 = state 1 LCD is being printed 0 = stop writing to LCD
        bool _state2;       // 1 = state 2 LCD is being printed 0 = stop writing to LCD
        bool _state3;       // 1 = state 3 LCD is being printed 0 = stop writing to LCD
        bool _state4;       // 1 = state 4 LCD is being printed 0 = stop writing to LCD
        bool _state6;       // 1 = state 6 LCD is being printed 0 = stop writing to LCD
        bool _speed;        // 1 = speed test in progress 0 = speed test is done
        bool _lock_state;   // 1 = current state will not change 0 = resume normal state sequence
    } stateflags;
    
// RAM
uint8_t test;   // testing delete when done.
uint8_t Reg_Cur;    // current register value
uint8_t state;      // holds current state.
uint8_t CurState;   // holds the new state value
uint8_t TimeOut;    // holds time in seconds (ClkTimer.c)
uint8_t SwCounter;  // switch is held down timer in seconds uses (ClkTimer.c)
uint8_t BtnTimer;   // holds timer for when a button is down
uint8_t prvState;   // holds the previous state

// LCD strings
unsigned char arr1[] = "   5712 TEST";
unsigned char arr2[] = "Next to start";
unsigned char tst1[] = "Test 1";
unsigned char k1_on[] = "turn on k1";
unsigned char arr3[] = "Heat off active";
unsigned char arr4[] = "Heat off NA";
unsigned char arr5[] = "Press Next";
unsigned char arr6[] = "Man HL";
unsigned char arr7[] = "Auto HL";
unsigned char on[] = "On";
unsigned char off[] = "Off";
unsigned char arr8[] = "Press Select";
unsigned char arr9[] = "next down  ";
unsigned char arr10[] = "    Normal   ";
unsigned char arr11[] = " W active   ";
unsigned char arr12[] = " G active   ";
unsigned char arr13[] = "Fan Speed Test";
unsigned char arr14[] = "Start Turn on G";
unsigned char arr15[] = "Low  Med  High";
unsigned char arr16[] = "state: ";  // *** delete after testing ***

const uint8_t Arrow_down[] =
{
// Char Number 2 -- Down Arrow
	0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00010101,  // ...O.O.O 
	0b00001110,  // ....OOO. 
	0b00000100,  // .....O.. 
	0b00000000,  // ........ 
};

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBAL_H */


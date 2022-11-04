/*******************************************************************************
* FileName:        LCD.H
* Dependencies:    See INCLUDES section below
* Processor:       
* Compiler:        XC8
* Company:         Microchip Technology, Inc.
* Author           Date:        Modified:               Comment:
* jeff hulett     May-2-2006    oct-12-2022 
*******************************************************************************/

#define _XTAL_FREQ 8000000  // set to what ever the oscilator frequency is
#include <xc.h>
#include<stdint.h>

/************************ P R O T O T Y P E S *********************************/
void LCDinit(void);                   // Configures LCD for 4 bit interface
void WriteNibble(unsigned char);      // Used to write command (RS = 0) (Nibble)
void Check_LCDBusy(void);             // check LCD busy before proceeding     	  
void text_display(unsigned char *);   // Displays string of data on LCD
void LCD_xy( unsigned int X, unsigned int Y); // location of text start
void LCDclear(void);                       //clear the display
void Create_Cust_Chars(int location, char *p); // create custom chars
void clock(char data);  // clock out custom char to CG ram
void CG_print(char data);   // print custom char to LCD
void Write_LCD_Ram(char data);
void LCDsend(unsigned char value, uint8_t CD);  // send data or command to the LCD
void LCDclock(unsigned char value, uint8_t CD);     // send value to the LCD
void display_on(void);
void display_off(void);
void curser_on(void);
void curser_off(void);
void mov_displayleft(void);
void mov_displayright(void);
void shiftcursleft(void);
void shiftcursright(void);
void charblinkon(void);
void charblinkoff(void);

// Definitions | modified 10-11-22
//******************** Display commands *********************
#define DispClr     0x01        // clear the display
#define Home        0x02        // return to home position, stops other commands
#define FunctionSet 0x28        // initialise LCD to 4 bit mode, 2lines, 5x8 dots
#define EntryMode   0x06        // Entry Mode selection
#define DDRAM       0x80        // DD ram address
#define CGRAM       0x40        // CG ram address "not tested as of 1/26/2022"

/**************** Display Control *********************************/
// display, cursor, blink
#define DISPLAYON  0x0C     // turn display on
#define DISPLAYOFF 0x08     // turn display off
#define CURSORON   0x0E     // turn cursor on   
#define CURSOROFF  0x0C     // turn cursor off  
#define BLINKON    0x0D     // blink charactor on
#define BLINKOFF   0x0C     // blink charactor off

/*************** entry display / cursor shift *********************/
#define MOVE_CURS_LEFT  0x10    // move curser left  
#define MOVE_CURS_RIGHT 0x14    // move curser right
#define MOVE_DIS_LEFT   0x18    // move display left
#define MOVE_DIS_RIGHT  0x1C    // move display right

#define deg 0xDF    // degree character 

char arrow[] = 
{
    0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00000100,  // .....O.. 
	0b00010101,  // ...O.O.O 
	0b00001110,  // ....OOO. 
	0b00000100,  // .....O.. 
	0b00000000,  // ........ 
};

char blank[] =
{
    0b00000000,   
	0b00000000,   
	0b00000000,   
	0b00000000,   
	0b00000000,   
	0b00000000,   
	0b00000000,   
	0b00000000, 
};

//****************** P I N  D E F ***************************
#define TRISLCD_reg TRISD       // tristate LCD Data Port
#define LATLCD_reg LATD         // latch LCD DATA Port
#define LCD_DATA PORTD          // LCD data port

// 4 x 20
#define Line_1 0x80     // line 1 start address 80
#define Line_2 0xC0     // line 2 start address C0
#define Line_3 0x94     // line 3 start address 14
#define Line_4 0xD4     // line 4 start address

uint8_t z;      // used in for next loops
uint8_t test;   // delete when done testing
unsigned char hi_b, low_b;

typedef enum
{
    comm,
    s_data
}val;
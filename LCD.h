/*******************************************************************************
* FileName:        LCD.H
* Dependencies:    See INCLUDES section below
* Processor:       
* Compiler:        XC8
* Company:         Microchip Technology, Inc.
* Author           Date:        Modified:               Comment:
* Microchip       May-2-2006      
*******************************************************************************/

#define _XTAL_FREQ 16000000
#include <xc.h>

/************************ P R O T O T Y P E S *********************************/
void LCDinit(void);                   // Configures LCD for 4 bit interface
void WriteNibble(unsigned char);      // Used to write command (RS = 0) (Nibble)
void WriteNibbleRS_H(unsigned char);  // Used to write Data to LCD (RS = 1)
void Check_LCDBusy(void);             // check LCD busy before proceeding     	  
void FunctionSet(unsigned char);      // Function set for 4 bit mode            	 
void LCDwrite(unsigned char);	      // Writes a character to LCD
void DDRAMadrs(unsigned char);        // DDRAM address selection
void SetLine(unsigned char);          // LCD line selection					  
void curser_ONOFF(unsigned char );    // Cursor ON or OFF control
void set_curser(unsigned char);       // Cursor position set
void text_display(unsigned char *);            // Displays string of data on LCD
void Bin2BCD(unsigned char);	      // Converts 8 bit Binary to 3 digit BCD
void LCD_xy( unsigned int X, unsigned int Y); // location of text start
void SendCommand(unsigned char temp);    // sends command to LCD

// Definitions
//******************** Display control definitions *********************
#define CURSOR_OFF  0b00001101  // turn cursor off
#define CURSOR_ON   0b00001111  // turn cursor on
#define DON         0b00001111  // display on
#define DOFF        0b00001011  // display off
#define BLINK_ON    0b00001111  // cursor blinks
#define BLINK_OFF   0b00001110  // cursor does not blink
#define DispClr     0b00000001  // clear the display
#define Home        0b00000010  // return to home position, stops other commands
#define FunctionSet 0x28        // initialise LCD to 4 bit mode
#define EntryMode   0x06        // Entry Mode selection
#define DDRAM       0x80        // DD ram address
#define CGRAM       0x40        // CG ram address "not tested as of 1/26/2022"

#define deg 0xDF    // degree character 

//****************** cursor or display shift definitions ******************
#define SHIFT_CUR_LEFT   0b00010000   // Cursor shifts to the left   
#define SHIFT_CUR_RIGHT  0b00010100   // Cursor shifts to the right  
#define MOVE_DISP_RIGHT  0b00011100   // display rotates right
#define MOVE_DISP_LEFT   0b00011000   // display rotates

//****************** P I N  D E F ***************************
#define TRISLCD_reg TRISD       // tristate LCD Data Port
#define LATLCD_reg LATD         // latch LCD DATA Port
#define LCD_DATA PORTD          // LCD data port

// 4 x 20
#define Line_1 0x80     // line 1 start address 80
#define Line_2 0xC0     // line 2 start address C0
#define Line_3 0x94     // line 3 start address 14
#define Line_4 0xD4     // line 4 start address

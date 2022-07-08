/*******************************************************************************
* FileName:        LCD.C
* Dependencies:    See INCLUDES section below
* Processor:       PIC16F18857
* Compiler:        XC8
* Company:         Electro Industries.
* Files needed:    LCH.h, pin_manager.h
*
* Author           Date:        Modified:      Comments:
* Microchip     02-May-06       1/26/2022      clean up code, get rid of 
*                                              unnecessary stuff.
*
* This LCD library uses a 4 bit wide byte, so you will need 4 data lines, and 3
* control lines, D4 - D7 on the LCD module.
* Comments:
* LCD interface
*  You need to assign 3 pins for controlling the LCD
*  LCD EN   : LCD enable signal
*  RD/WR    : RW = 0 write to LCD.  RW = 1 write to LCD.
*  RS       : RS = 1 send data to LCD.  RS = 0 send command to LCD
*
* Data lines
*  Example: To write a byte.
*  Write High Nibble to the PORT you chose to assign it to.
*  Clock EN signal
*  Write Low Nibble to the same port as the high nibble.
*  Clock EN signal
*******************************************************************************/
#include "LCD.h"
#include "mcc_generated_files/pin_manager.h"

/******************************************************************************
* Function:        void LCDinit(void)
* PreCondition:    None
* Input:           None
* Output:          None
* Side Effects:    None
*
* Overview:   This function will perform necessary enumeration to LCD
*             for display and communication with the PIC
*             Refer to LCD data sheet for more information.
*
* Note:       All delay functions written here for 10.000000 MHz Clock
*             If using any other speed please tune the delay function
*             appropriately
*****************************************************************************/
void LCDinit(void)
{
    unsigned char i;
   __delay_ms(35);         // ~35 ms delay, power up delay

   TRISLCD_reg &= 0xF0;    // set LCD port to output
   RS_SetLow();
   RW_SetLow();
   E_SetLow();

   for(i = 1; i <= 3; ++i)
   {
        WriteNibble(3);    // control bytes #1 - 3
        __delay_ms(5);     // ~5 ms delay
   }

   WriteNibble(2);     // #4 sets control to 4 bit mode
   __delay_ms(5);      // ~5 ms delay
   
   Check_LCDBusy();    // Check whether LCD is free, if so continue operation
   SendCommand(FunctionSet); // #5 control byte Function set
   Check_LCDBusy();    // Check whether LCD is free, if so continue operation
   SendCommand(DON);   // Turn on Display
   __delay_us(1);
   SendCommand(DispClr);    // clear display
   __delay_us(1);
   SendCommand(EntryMode);  // Entry mode selection
   __delay_us(1);
   SendCommand(DDRAM);      // Initialize DDRAM address to 80h        
   __delay_ms(1);           // delay to make sure everything settles
} // end LCD Init

/*******************************************************************************
* Function:      void WriteNibble(unsigned char data)
* PreCondition:  None
* Input:         8 bit value (values are used to command LCD for an action)
* Output:        None
* Side Effects:  None
* Overview:      RS line of LCD is driven low to tell LCD to accept a command.
*                Write Hi Nibble first, Then Low Nibble
*
* Note:       This function is only for sending commands to the LCD.
*******************************************************************************/
void WriteNibble(unsigned char data)
{
    Check_LCDBusy();     // Check if lcd module is busy
    E_SetLow();
    LATLCD_reg = data;      // Write High Nibble to LAT
    RS_SetLow();
    RW_SetLow();
    __delay_us(10);
    E_SetHigh();        // toggle LCD enable pin
    __delay_us(10);
    E_SetLow();
}

/*******************************************************************************
* Function:      void WriteNibbleRS_H(unsigned char data)
* PreCondition:  None
* Input:         8 bits value (These values are used to Display on LCD segment)
* Output:        None
* Side Effects:  None
* Overview:      RS line of LCD is driven Hi to indicate LCD will accept a
*                Character to display on LCD.
*                Write Hi Nibble first, Then Low Nibble.
*
* Note:      This function is only for sending Data to be displayed on the LCD.
*******************************************************************************/
void WriteNibbleRS_H(unsigned char data)
{
   Check_LCDBusy();     // Check if lcd module is busy
   E_SetLow();
  // LATLCD_reg = (data &= 0xF0);  // Write High Nibble to LATCH
   LATLCD_reg = (data &= 0x0F);  // Write High Nibble to LATCH
   RS_SetHigh();
   RW_SetLow();
   __delay_us(1);
   E_SetHigh();    // toggle LCD enable pin
   __delay_us(1);  // delay add more or less delay time for given clock speed
   E_SetLow();
}

/***************** LCD write ***********************************************/
void LCDwrite(unsigned char temp)
{
   unsigned char i = 0, low, hi;

   Check_LCDBusy();     // Check if lcd module is busy
   i = temp;
   low = (i &= 0x0F);  // strip out low nibble
   i = temp >> 4;      // rotate 4 places to right
   hi = (i &= 0x0F);   // strip out hi nibble
   __delay_us(1);
   WriteNibbleRS_H(hi);  // go send hi nibble to LCD
   //i = temp<<4;
  // i = temp>>4;     // switch for 5644 board.
   //i &= 0xF0;
  // i &= 0x0F;       // switch for 5644 board.
   __delay_us(1);
   WriteNibbleRS_H(low);  // go send low nibble to LCD
}

/******************************************************************************
* Function:        void text_display(unsigned char* text)
* PreCondition:    None
* Input:           Address of string to display on LCD
* Output:          None
* Side Effects:    None
* Overview:        This function takes address of string and displays on LCD
*                  A single level pointer is used.
******************************************************************************/
void text_display(unsigned char * text)
{
   while (*text)        // Continue to display characters from STRING
   {                    // until NULL character appears.
      LCDwrite(*text);  // Display selected character from the STRING.
      text++;           // Increment character pointer addressed in STRING.
   }
}

/*******************************************************************************
* Function:      void SendCommand(unsigned char data)
* PreCondition:  None
* Input:         8 bit value (values are used to command LCD for an action)
* Output:        None
* Side Effects:  None
* Overview:      RS line of LCD is driven low to tell LCD to accept a command.
*                Write Hi Nibble first, Then Low Nibble
*
* Note:       This function is only for command.
*******************************************************************************/
void SendCommand(unsigned char temp)
{
   unsigned char i = 0, low, hi;

   Check_LCDBusy();
   i = temp;
   low = (i &= 0x0F);  // strip out low nibble
   i = temp >> 4;      // rotate 4 places to right
   hi = (i &= 0x0F);   // strip out hi nibble
   WriteNibble(hi);
   WriteNibble(low);
}

/*******************************************************************************
* Function:      LCD_xy(unsigned char X, unsigned char Y)
* PreCondition:  None
* Input:         two 8 bit values(line, position)
* Output:        None
* Side Effects:  None
* Overview:      This function adds the line number with the desired position -1
*                Example: "line 1 position 3" x = 1, Y = 3, X + Y - 1.
*                X = Line, Y = Position.
*******************************************************************************/
void LCD_xy( unsigned int X, unsigned int Y)
{
   unsigned int address;

    switch(X)
    {
        case 1:
            address = Line_1;
            break;
        case 2:
            address = Line_2;
            break;
        case 3:
            address = Line_3;
            break;
        case 4:
            address = Line_4;
            break;
        default:
            address = Line_1;
            break;
    }
    address += Y - 1;
    SendCommand(address);
}

/*******************************************************************************
* Function:        void Check_LCDBusy(void)
* PreCondition:    None
* Input:           None
* Output:          None
* Side Effects:    None
* Overview:        This function will read LCD to find if LCD is Busy.
*                  wait until LCD becomes free, LCD bit7 = 1;
* Note:            None
*******************************************************************************/
void Check_LCDBusy(void)
{
   unsigned char BUSY = 0;
   TRISLCD_reg = 0xFF;     // Make Data to read mode
   loop:
   RS_SetLow();
   RW_SetHigh();
   __delay_us(2);  // delay 2us 
   E_SetHigh();    // toggle LCD enable pin
   __delay_us(2);  // delay 2us 
   E_SetLow();
   E_SetHigh();
   
   BUSY = LCD_DATA;
   BUSY &= 0x08;        // test if LCD data port bit7 is high

   if (BUSY != 0) goto loop;    // loop until busy bit is 0
   TRISLCD_reg = 0xF0;          // Make LCD port an output 
} // END Check_LCDBusy

/********************************************************************
 *                                                                  *
 * fill the first 8 CGRAM locations with custom characters          *
 ********************************************************************/
//void createChar(uint8_t location, uint8_t charmap[]) 
//{
//    unsigned char i, low, hi;
//    unsigned char temp;
//    uint8_t x;
//    
//    location &= 0x7;     // we only have 8 locations 0-7
//    temp = (CGRAM | (location << 3));
//    
//    Check_LCDBusy();
//    i = temp;
//    low = (i &= 0x0F);   // strip out low nibble
//    i = temp >> 4;       // rotate 4 places to right
//    hi = (i &= 0x0F);    // strip out hi nibble
//    WriteNibble(hi);
//    WriteNibble(low);
//   
//    
//    for (int x=0; x<8; x++) 
//    {
//        //write(charmap[i]);
//        WriteNibbleRS_H(charmap[x]);
//    }
//}
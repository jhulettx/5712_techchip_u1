/*******************************************************************************
* FileName:        LCD.C
* Dependencies:    See INCLUDES section below
* Compiler:        XC8
* Company:         Electro Industries.
* Files needed:    LCH.h, pin_manager.h
*
* Author           Date:        Modified:      Comments:
* Microchip     02-May-06       10/18/2022     clean up code, combine functions 
*                                              add CG char stuff
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
*  Clock EN signal hi
*  Write Low Nibble to the same port as the high nibble.
*  Clock EN signal low
*******************************************************************************/
#include "LCD.h"
#include "mcc_generated_files/pin_manager.h"

/******************************************************************************
* Function:   void LCDinit(void)
*
* Overview:   This function will perform necessary enumeration to LCD
*             for display and communication with the PIC
*             Refer to LCD data sheet for more information.
*****************************************************************************/
void LCDinit(void)
{
    unsigned char i;
   __delay_ms(35);      // power up delay wait for voltage to get to 4.5vdc

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
   __delay_us(100);    // ~100us delay
   
   Check_LCDBusy();    // Check whether LCD is free, if so continue operation
   LCDsend(FunctionSet, comm); // #5 control byte Function set
   LCDsend(DISPLAYON, comm);   // Turn on Display
   __delay_us(1);
   LCDsend(DispClr, comm);    // clear display
   __delay_us(1);
   LCDsend(EntryMode, comm);  // Entry mode selection
   __delay_us(1);      
   LCDsend(DDRAM, comm);    // Initialize DDRAM address to 80h        
   __delay_ms(5);           // delay to make sure everything settles
} // end LCD Init

/*******************************************************************************
* Function:      void WriteNibble(unsigned char data)
* Input:         8 bit value (values are used to command LCD for an action)
* Output:        None
* Overview:      RS line of LCD is driven low to tell LCD to accept a command.
*                Write 8bit wide byte data to the display
*
* Note:       This function is only for sending commands to the LCD during LCD
 *            initialization.
*******************************************************************************/
void WriteNibble(unsigned char data)
{
    Check_LCDBusy();     // Check if lcd module is busy
    LATLCD_reg = data;  // Write High Nibble to LAT
    RS_SetLow();
    RW_SetLow();
    E_SetHigh();        // toggle LCD enable pin
    __delay_us(2);
    E_SetLow();
}

/**************************************************************************
 *                  LCD SEND    
 *  prepare the command or data to be sent to the LCD screen via 
 *  the LCDclock function. 
 *  this function sends the "CD" bit to the LCDclock function with the hi and 
 *  low nibbles.
 **************************************************************************/
void LCDsend(unsigned char value, uint8_t CD)
{        
    hi_b = value >> 4;          // move upper nibble to hi byte 
    low_b = (value &= 0x0F);    // strip off upper nibble put in low byte
    LCDclock(hi_b, CD);
    LCDclock(low_b, CD);
}

/***************************************************************************
 *                      SEND                                                            
 *  put data on the LCD screens data pins, and clock it in. 
 *  if CD = comm, rs pin = 0. if CD = s_data, rs pin = 1.
 *  comm = command,  s_data = character data.
 ***************************************************************************/
void LCDclock(unsigned char value, uint8_t CD)
{    
    Check_LCDBusy();       // Check if lcd module is busy
    LATLCD_reg = (value);  // Write High Nibble to LATCH
    
    if(CD == comm)
       RS_SetLow(); 
    else  RS_SetHigh();
    
    RW_SetLow();
    E_SetHigh();       // toggle LCD enable pin
    __delay_us(2);  
    E_SetLow();
}

/******************************************************************************
* Function:        void text_display(unsigned char* text)
* PreCondition:    None
* Input:           Address of string data to display on LCD
* Output:          None
* Side Effects:    None
* Overview:        This function uses A single level pointer and displays on LCD
*                  it continues until a NULL character is hit.
******************************************************************************/
void text_display(unsigned char * text)
{
   while (*text)        
   {                    
      LCDsend(*text, s_data);   // Display character STRING, s_data = sending data.
      text++;           // Increment character pointer addressed in STRING.
   }
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
   unsigned char address;

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
    LCDsend(address, comm);
}

/*******************************************************************************
* Function:        void Check_LCDBusy(void)
* Overview:        This function will read LCD.7 to find if LCD is Busy.
*                  wait until LCD becomes free, LCD bit7 = 0, then return;
*******************************************************************************/
void Check_LCDBusy(void)
{
   unsigned char BUSY = 0;
   TRISLCD_reg = 0xFF;     // Make LCD port an input to read busy flag D7
   loop:
   RS_SetLow();
   RW_SetHigh(); 
   E_SetHigh();    // toggle LCD enable pin
   __delay_us(2);  // delay 2us 
   E_SetLow();
   
   BUSY = LCD_DATA;
   BUSY &= 0x08;    // test if LCD data port bit7 is high

   if(BUSY != 0) goto loop;    // loop until busy bit is 0
   TRISLCD_reg = 0xF0;         // Make LCD port an output 
} // END Check_LCDBusy

/*******************************************************************************
* Function:        createChar
* PreCondition:    None
* Input:           location, pointer[]
* Output:          None
* Overview:        fill the first 8 CGRAM locations with custom characters 
*******************************************************************************/
void Create_Cust_Chars(int location, char *p)   
{
    uint8_t x;
    location = (location & 0x07) << 3;
    LCDsend((0x40 | location), comm);   // write to character ram address
    
        for(x = 0; x < 8; x++) 
        {
            Write_LCD_Ram(p[x]); // print custom char to LCD
        }

    LCDsend(DDRAM, comm);   // go back to normal ram address
}

//**************** WRITE LCD RAM *************************************
void Write_LCD_Ram(char data)
{ 
    Check_LCDBusy();           // Check if lcd module is busy
    
    hi_b = data >> 4;          // move upper nibble to hi byte 
    low_b = (data &= 0x0F);    // strip off upper nibble put in low byte
    
    RS_SetHigh();
    RW_SetLow();
    clock(hi_b);
    __delay_us(2);
    clock(low_b);
}

//***************** CLOCK CHAR DATA TO THE LCD ************************
void clock(char data)
{
    LATLCD_reg = data;
    E_SetHigh();    // toggle LCD enable pin
    __delay_us(2);  
    E_SetLow();
}

//***************** PRINT CUSTOM CHAR TO THE LCD SCREEN ****************
void CG_print(char data)
{
    Check_LCDBusy();        // Check if lcd module is busy
    RS_SetHigh();
    RW_SetLow();
    
    hi_b = data >> 4;          // move upper nibble to hi byte 
    low_b = (data &= 0x0F);    // strip off upper nibble put in low byte
    
    clock(hi_b);
    clock(low_b);
    __delay_ms(3);
}

/*******************************************************************************
* Function:        void LCDclear(void)
* Overview:        This function will clear the LCD screen.
*******************************************************************************/
void LCDclear(void)
{  
    LCDsend(DispClr, comm); // clear display, set cursor position to zero
    __delay_us(2000);       // this command takes a long time
}

/**************** DISPLAY ON ******************************************/
void display_on(void)
{
   LCDsend(DISPLAYON, comm); 
}

/**************** DISPLAY Off *****************************************/
void display_off(void)
{
   LCDsend(DISPLAYOFF, comm);
}

/*************** CURSER ON ********************************************/
void curser_on(void)
{
    LCDsend(CURSORON, comm); 
}

/*************** CURSER OFF ********************************************/
void curser_off(void)
{
    LCDsend(CURSOROFF, comm); 
}

/*************** MOVE DISPLAY LEFT *****************************************/
void mov_displayleft(void)
{
    LCDsend(MOVE_DIS_LEFT, comm); 
}

/*************** MOVE DISPLAY RIGHT ****************************************/
void mov_displayright(void)
{
    LCDsend(MOVE_DIS_RIGHT, comm); 
}

/*************** MOVE CURSER LEFT ****************************************/
void shiftcursleft(void)
{
    LCDsend(MOVE_CURS_LEFT, comm); 
}

/*************** MOVE CURSER RIGHT ****************************************/
void shiftcursright(void)
{
    LCDsend(MOVE_CURS_RIGHT, comm); 
}

/*************** BLINK CHARICTOR ******************************************/
void charblinkon(void)
{
    LCDsend(BLINKON, comm); 
}

/*************** STOP BLINKING CHARICTOR ***********************************/
void charblinkoff(void)
{
    LCDsend(BLINKOFF, comm); 
}
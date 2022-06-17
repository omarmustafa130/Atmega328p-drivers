/*
 * LCD_CONFIG.h
 *
 * Created: 8/18/2021 2:31:29 PM
 *  Author: AOM
 */ 
/********************************************************/
/* Title		 : LCD configuration file				*/
/* Author		 : Omar Mustafa							*/
/* Release		 : 1.0									*/
/* Last update  : Aug 18, 2021							*/
/********************************************************/

/*
***************************FuctionSet***************************
DL: Sets interface data length:
	Data is sent or received in 8-bit length (DB7 ~ DB0) when
	DL = 1, and in 4-bit length (DB7 ~ DB4) when DL = 0. When the 4-bit length is
	selected, data must be sent or received twice.
N: Sets the number of lines:
	N = 0 : 1 line display (1/8 duty)
	N = 1 : 2 line display (1/16 duty)
F: Sets character font.
	F = 0 : 5 x 7 dots
	F = 1 : 5 x 10 dots
*/

/*
***************************DisplayON/OFF***************************
D: The entire display is ON when D = 1 and OFF when D = 0. 
C: The cursor displays when C = 1 and does not display when C = 0.
B: The character indicated by the cursor blinks when B = 1, When B = 0, the blink is off.
*/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
//define pins
#define RS 0	
#define RW 1	
#define EN 2
#define PORTConrtol GPIO_PortC
#define PORTData    GPIO_PortB
#define FunctionSet_8BIT_2lines_5x7dots 0b00111000
#define FunctionSet_4BIT_2lines_5x7dots 0b00101000
#define CursorHome						0b00000010
#define CursorDir						0b00000111
#define DisplayON						0b00001100
#define DisplayOFF						0b00001010
#define DisplayClear					0b00000001
#define EntryMode						0b00000110
#define SetDDRAM						0b10000000
#endif /* LCD_CONFIG_H_ */
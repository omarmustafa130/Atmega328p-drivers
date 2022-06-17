/*
 * LCD_INT.h
 *
 * Created: 8/18/2021 1:23:45 PM
 */ 

/********************************************************/
/* Title		 : LCD interface file					*/
/* Author		 : Omar Mustafa							*/
/* Release		 : 1.0									*/
/* Last update  : Aug 18, 2021							*/
/********************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

void LCD_Vid_8BitInit(void);

void LCD_Vid_SendChar(u8 Copy_u8_Data);
void LCD_Vid_SendCommand(u8 Copy_u8_Command);

void LCD_Vid_SendString(u8* CopyPtrToString, u8 Copy_u8_Row, u8 Copy_u8_Col);
void LCD_Vid_SendNumber(u8 Copy_u16_Number);
void LCD_Vid_ClearScreen(void);
void LCD_Vid_GoToRowCol(u8 Copy_u8_Row, u8 Copy_u8_Col);
void LCD_Vid_StoreCustomChar(u8* Copy_u8_Pattern, u8 Copy_u8_CGRAMIndex);
void LCD_Vid_DisplayCustomChar(u8 Copy_u8_CGRAMIndex, u8 Copy_u8_Row, u8 Copy_u8_Col);

#endif /* LCD_INT_H_ */
/*
 * LCD_PROG.c
 *
 * Created: 8/18/2021 1:24:07 PM
 */ 

/********************************************************/
/* Title		 : LCD program file						*/
/* Author		 : Omar Mustafa							*/
/* Release		 : 1.0									*/
/* Last update  : Aug 18, 2021							*/
/********************************************************/
/*	
	RS: 0 -> Command mode
		1 -> Data mode 									
	RW: 0 -> Write
		1 -> Read 
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "LCD_CONFIG.h"
#include "LCD_INT.h"
#include <util/delay.h>

void LCD_Vid_8BitInit(void)
{

	_delay_ms(35);
	LCD_Vid_SendCommand(FunctionSet_8BIT_2lines_5x7dots);
	_delay_ms(1);
	LCD_Vid_SendCommand(DisplayON);
	_delay_ms(1);
	LCD_Vid_SendCommand(DisplayClear);
	_delay_ms(2);
	LCD_Vid_SendCommand(EntryMode);
}
void LCD_Vid_SendCommand(u8 Copy_u8_Command)
{	MGPIO_voidSetPIN_VALUE(PORTConrtol, RS, GPIO_LOW);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, RW, GPIO_LOW);
	_delay_ms(1);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_HIGH);
	_delay_ms(1);
	MGPIO_voidSetPORT_VALUE(PORTData, Copy_u8_Command);
	_delay_ms(2);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_LOW);
	_delay_ms(2);
}

void LCD_Vid_SendChar(u8 Copy_u8_Data)
{
	MGPIO_voidSetPIN_VALUE(PORTConrtol, RS, GPIO_HIGH);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, RW, GPIO_LOW);
	_delay_ms(1);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_HIGH);
	_delay_ms(1);
	MGPIO_voidSetPORT_VALUE(PORTData, Copy_u8_Data);
	_delay_ms(2);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_LOW);
	_delay_ms(2);

}



void LCD_Vid_SendString(u8* CopyPtrToString, u8 Copy_u8_Row, u8 Copy_u8_Col)
{
	u8 local_u8_index = 0;
	u8 local_u8_Row=0;
	while (CopyPtrToString[local_u8_index] != '\0' && ((Copy_u8_Row*16)+(local_u8_index+Copy_u8_Col))<32 ){
		if (((Copy_u8_Row*16)+(local_u8_index+Copy_u8_Col))<16){
			LCD_Vid_SendChar(CopyPtrToString[local_u8_index]);
			local_u8_index++;
		}

		else if (((Copy_u8_Row*16)+(local_u8_index+Copy_u8_Col))==16){
			LCD_Vid_GoToRowCol(1,0);
			local_u8_Row++;
		}
		else if (((Copy_u8_Row*16)+(local_u8_index+Copy_u8_Col))<32 && local_u8_Row==1){
			LCD_Vid_SendChar(CopyPtrToString[local_u8_index]);
			local_u8_index++;
		}
		
	}
}
void LCD_Vid_SendNumber(u8 Copy_u16_Number)
{
	MGPIO_voidSetPIN_VALUE(PORTConrtol, RS, GPIO_HIGH);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, RW, GPIO_LOW);
	_delay_ms(1);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_HIGH);
	_delay_ms(1);
	MGPIO_voidSetPORT_VALUE(PORTData, Copy_u16_Number);
	_delay_ms(2);
	MGPIO_voidSetPIN_VALUE(PORTConrtol, EN, GPIO_LOW);
	_delay_ms(2);

}
void LCD_Vid_ClearScreen(void)
{
	LCD_Vid_SendCommand(DisplayClear);
}

void LCD_Vid_GoToRowCol(u8 Copy_u8_Row, u8 Copy_u8_Col)
{
	u8 local_u8_address=0;
	switch (Copy_u8_Row){
		case 0:
		local_u8_address = 0x00 + Copy_u8_Col;
		case 1:
		local_u8_address = 0x40 + Copy_u8_Col;
	}
	local_u8_address = local_u8_address | 0x80;
	LCD_Vid_SendCommand(local_u8_address);
}


void LCD_Vid_StoreCustomChar(u8* Copy_u8_Pattern, u8 Copy_u8_CGRAMIndex)
{
	u8 local_u8_address = 0;
	if (Copy_u8_CGRAMIndex < 8){
		local_u8_address = Copy_u8_CGRAMIndex * 8;
		SET_BIT(local_u8_address, 6);
		LCD_Vid_SendCommand(local_u8_address);
		for (u8 local_u8_index =0; local_u8_index<8; local_u8_index++){
			LCD_Vid_SendChar(Copy_u8_Pattern[local_u8_index]);
		}
		LCD_Vid_SendCommand(0x02);
	}
}
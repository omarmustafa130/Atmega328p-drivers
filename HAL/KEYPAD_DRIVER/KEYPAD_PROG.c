/*
 * KEYPAD_PROG.c
 *
 * Created: 1/2/2022 12:49:17 PM
 *  Author: AOM
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../LCD/LCD_INT.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"

void HKeypad_Void_Init(void)
{
	for (u8 i=ROW_START; i<ROWS+ROW_START; i++)
	{
		MGPIO_voidSetPinDirection(KEYPAD_PORT, i, GPIO_INPUT_PULLUP);
	}
	for (u8 i = COL_START; i<COLS+COL_START; i++)
	{
		MGPIO_voidSetPinDirection(KEYPAD_PORT, i, GPIO_OUTPUT);
		MGPIO_voidSetPinValue(KEYPAD_PORT, i, GPIO_HIGH);
	}
	return;
}

u8 HKeypad_u8_GetKey(void)
{	
	u8 result;

	while (1){
		for (u8 i = COL_START; i<COLS+COL_START; i++)
		{
			MGPIO_voidSetPinValue(KEYPAD_PORT, i, GPIO_LOW);
			for ( u8 k = ROW_START; k<ROWS+ROW_START; k++)
			{
				if (MGPIO_u8GetPinValue(KEYPAD_PORT, k)==GPIO_LOW)
				{
					result = ArrKeypadValue [k][i];
					MGPIO_voidSetPinValue(KEYPAD_PORT, i, GPIO_HIGH);
					return result;
				}
			}
			MGPIO_voidSetPinValue(KEYPAD_PORT, i, GPIO_HIGH);
		}
	}
	
	return 0;
}
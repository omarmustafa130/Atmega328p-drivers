/*
 * UASRT_program.c
 *
 *  Created on: Sep 21, 2021
 *      Author: G2
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "UASRT_interface.h"
#include "UASRT_private.h"
#include <util/delay.h>

void MUSART_voidSet_BaudRate(u32 local_baudrate)
{	
	u16 temp_BaudRate;
	temp_BaudRate =((F_CPU)/(16*local_baudrate))-1;
	USART_REG->UBRR0H = (temp_BaudRate>>8);
	USART_REG->UBRR0L = temp_BaudRate;

}
void MUSART_voidInit(enum USART_Mode_t USART_Mode,enum USART_CharSize_t USART_CharSize,enum USART_StopBit_t USART_StopBit,enum USART_ParityMode_t USART_ParityMode)
{
	PUSART_Mode = USART_Mode;
	CLR_REG(USART_REG->UCSR0A);
	CLR_REG(USART_REG->UCSR0C);
	CLR_REG(USART_REG->UCSR0B);
	USART_REG->UCSR0C |= (USART_Mode<<6);
	if(USART_CharSize<=eight_bits)
	{
		USART_REG->UCSR0C |= (USART_CharSize<<1);
		
	}
	else if(USART_CharSize == nine_bits)
	{
		USART_REG->UCSR0C |= (3<<1);
		SET_BIT(USART_REG->UCSR0B,2);
	}
	USART_REG->UCSR0C |= (USART_StopBit<<3);
	USART_REG->UCSR0C |= (USART_ParityMode<<4);
	SET_BIT(USART_REG->UCSR0B,3);
	SET_BIT(USART_REG->UCSR0B,4);
}
void MUSART_voidTransmit_Char(u8 Copy_u8Transmit_Value)
{
	while(!(GET_BIT(USART_REG->UCSR0A,5)));
	USART_REG->UDR0 = Copy_u8Transmit_Value;
	SET_BIT(USART_REG->UCSR0A,5); 

}
u8 MUSART_u8Receive_Char(void)
{
	u8 Local_VAR =0;
	while(!(GET_BIT(USART_REG->UCSR0A,7)));
	Local_VAR = USART_REG->UDR0;
	SET_BIT(USART_REG->UCSR0A,7);
	return Local_VAR;

}
void MUSART_voidTransmit_Str(u8* Ptr_u8Transmit_Value)
{
	while(*Ptr_u8Transmit_Value != '\0')
	{
		MUSART_voidTransmit_Char(*Ptr_u8Transmit_Value);
		Ptr_u8Transmit_Value++;
	}
}
void MUSART_voidTX_EI(void(*LocalCallback)(void))
{
	GIE_voidEnable();
	while(GET_BIT(USART_REG->UCSR0A,6) == 0);
	USART_GlobalCallback = LocalCallback;
	SET_BIT(USART_REG->UCSR0B,6);
	SET_BIT(USART_REG->UCSR0B,3);
}
void MUSART_voidRX_EI(void(*LocalCallback)(void))
{
	GIE_voidEnable();
	while(GET_BIT(USART_REG->UCSR0A,7) == 0);
	USART_GlobalCallback = LocalCallback;
	SET_BIT(USART_REG->UCSR0B,7);
	SET_BIT(USART_REG->UCSR0B,4);
}
void MUSART_voidRE_EI(void(*LocalCallback)(void))
{
	GIE_voidEnable();
	while(GET_BIT(USART_REG->UCSR0A,5) == 0);
	USART_GlobalCallback = LocalCallback;
	SET_BIT(USART_REG->UCSR0B,5);
}

void USART_TX(void)
{
	USART_GlobalCallback();
}
void USART_RX(void)
{
	USART_GlobalCallback();
}
void USART_RE(void)
{
	USART_GlobalCallback();
}

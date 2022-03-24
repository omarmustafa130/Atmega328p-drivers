/*
 * GPIO_program.c
 *
 * Created: 9/15/2021 9:08:27 PM
 *  Author: The Warlock & Omar
 */
#include "../../Library/STD_TYPES.h" 
#include "../../Library/BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
volatile PORT_t* PGPIO_PORT_tPtrGetRegister (enum GPIO_PORT_ID PORT_ID)
{
	switch(PORT_ID){
		case GPIO_PortB:
			return PORTB_REG;
		case GPIO_PortC:
			return PORTC_REG;
		case GPIO_PortD:
			return PORTD_REG;
		default:
			return 0;
	}
}
void MGPIO_voidSetPORT_DIRECTION (enum GPIO_PORT_ID PORT_ID,enum GPIO_DIRECTION ONE_Direction)
{		
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
			
	switch(ONE_Direction)
	{
		case GPIO_INPUT:
			P->DDR = 0;
			break;
		case GPIO_OUTPUT:
			P->DDR = 255;
			break;	
		case GPIO_INPUT_PULLUP:
			P->DDR = 0;
			P->PORT = 255;
			break;
	}
}
void MGPIO_voidSetPIN_DIRECTION (enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber,enum GPIO_DIRECTION ONE_Direction)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
	switch(ONE_Direction)
	{
		case GPIO_INPUT:
			CLR_BIT(P->DDR, Copy_u8_PinNumber);
			break;
		case GPIO_OUTPUT:
			SET_BIT(P->DDR, Copy_u8_PinNumber);
			break;
		case GPIO_INPUT_PULLUP:
			CLR_BIT(P->DDR, Copy_u8_PinNumber);
			SET_BIT(P->PORT, Copy_u8_PinNumber);
			break;	
	}	
}
void MGPIO_voidSetPORT_VALUE (enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_Value)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
	P->PORT = Copy_u8_Value;
}
void MGPIO_voidSetPIN_VALUE (enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber,enum GPIO_VALUE_t GPIO_VALUE)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
	switch(GPIO_VALUE)
	{
		case GPIO_LOW:
			CLR_BIT(P->PORT, Copy_u8_PinNumber);
			break;
		case GPIO_HIGH:
			SET_BIT(P->PORT, Copy_u8_PinNumber);
			break;
	}
}
u8 MGPIO_u8GetPORT_VALUE(enum GPIO_PORT_ID PORT_ID)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return 0;
	return (P->PIN);
}
u8 MGPIO_u8GetPIN_VALUE(enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_PinNumber)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return 0;
	return (GET_BIT(P->PIN, Copy_u8_PinNumber));
}
void MGPIO_voidTOGGLE_PIN(enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_PinNumber)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
	TOG_BIT(P->PORT, Copy_u8_PinNumber);
}
void MGPIO_voidTOGGLE_PORT(enum GPIO_PORT_ID PORT_ID)
{
	volatile PORT_t* P = 0;
	P = PGPIO_PORT_tPtrGetRegister(PORT_ID);
	if (P == 0)
		return;
	P->PORT = ~ P->PORT;
}
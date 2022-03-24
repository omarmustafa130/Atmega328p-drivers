/*
 * EXTI.c
 *
 *  Created on: Sep 18, 2021
 *      Author: G2
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "LCD_INT.h"
#include "LCD_CONFIG.h"

void MEXTI_voidSetCallback		(enum EXTI_ID_t EXTI_ID,void (*Local_Callback)(void))
{
	Global_Callback[EXTI_ID]= Local_Callback;
}
void MEXTI_voidEnable			(enum EXTI_ID_t EXTI_ID,enum EXTI_Trigger_t EXTI_Trigger)
{
	GIE_voidEnable();
	switch(EXTI_ID)
	{
	case EXTI_INT0:
		EIMSK =0;
		EIMSK|= 1;
		EICRA = 0;
		EICRA = EXTI_Trigger;
		break;
	case EXTI_INT1:
		EIMSK = 0;
		EIMSK|= (1<<1);
		EICRA = 0;
		EICRA = (EXTI_Trigger<<2);
		break;
	}
}
void MEXTI_voidDisable			(enum EXTI_ID_t EXTI_ID)
{
	switch(EXTI_ID)
		{
		case EXTI_INT0:
			CLR_BIT(EIMSK,0);
			break;
		case EXTI_INT1:
			CLR_BIT(EIMSK,1);
			break;
		}
}
void MEXTI_voidEnablePCINT		(enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber)
{	
	switch(PORT_ID)
	{
		case GPIO_PortB:
			PCICR_reg = 1;
			PCMSK0 = 0;
			PCMSK0 |= (1<<Copy_u8_PinNumber);
			break;	
		case GPIO_PortC:
			PCICR_reg = 2;
			PCMSK0 = 0;
			PCMSK1 = 0;
			PCMSK1 |=(1<<Copy_u8_PinNumber);
			break;
		case GPIO_PortD:
			PCICR_reg = 4;
			PCMSK0 = 0;
			PCMSK1 = 0;
			PCMSK2 = 0;
			PCMSK2 |=(1<<Copy_u8_PinNumber);
			break;
				
	}
	GIE_voidEnable();

}
void MEXTI_voidDisablePCINT		(u8 Copy_u8_pinnumber)
{
	if(Copy_u8_pinnumber>=0 && Copy_u8_pinnumber<8)
	{
		CLR_BIT(PCMSK0,Copy_u8_pinnumber);
	}
	else if(Copy_u8_pinnumber>7 && Copy_u8_pinnumber<15)
	{
		CLR_BIT(PCMSK1,(Copy_u8_pinnumber-8));
	}
	else if(Copy_u8_pinnumber>15 && Copy_u8_pinnumber<24)
	{
		CLR_BIT(PCMSK2,(Copy_u8_pinnumber-16));
	}
	else
		return;
}
void MEXTI_voidSetCallbackPCINT		(enum EXTI_PCINT_num EXTI_PCINT,void (*Local_Callback)(void))
{
	Global_CallbackPCINT[EXTI_PCINT]= Local_Callback;
}


void EXTI_VEC1()
{
	if (Global_Callback[EXTI_INT0] != 0)
		Global_Callback[EXTI_INT0]();
	else
		return;
}
void EXTI_VEC2()
{
	if (Global_Callback[EXTI_INT1] != 0)
		Global_Callback[EXTI_INT1]();
	else
		return;

}

void EXTI_VEC_PCINT0()
{
	Global_CallbackPCINT[EXTI_PCINT0]();
}
void EXTI_VEC_PCINT1()
{
	Global_CallbackPCINT[EXTI_PCINT1]();
}
void EXTI_VEC_PCINT2()
{
	Global_CallbackPCINT[EXTI_PCINT2]();
}

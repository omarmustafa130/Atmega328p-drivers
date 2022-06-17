/*
 * TIMER0_program.c
 *
 * Created: 9/27/2021 3:37:11 PM
 *  Author: Omar Mustafa & The Warlock
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_confg.h"

void MTimer0_voidEnable_INT(void)
{
	Timer0_TIMSK |= 7;
}
void MTimer0_voidDisable_INT(void)
{
	Timer0_TIMSK &= ~7;
}
void MTimer0_voidInit_Channel(enum Timer0_WGM_t Timer0_WGM,u8 TIMER0_OC0Mode)
{
	CLR_REG(Timer0_REG->TCCR0A);
	CLR_BIT(Timer0_REG->TCCR0B,3);
	Timer0_REG->TCCR0A |= GET_BIT(Timer0_WGM,0);
	Timer0_REG->TCCR0A |= (GET_BIT(Timer0_WGM,1)<<1);
	Timer0_REG->TCCR0B |= (GET_BIT(Timer0_WGM,2)<<3);

	Timer0_REG->TCCR0A |= (TIMER0_OC0Mode<<4);
	Timer0_REG->TCCR0A |= (TIMER0_OC0Mode<<6);
}
void MTimer0_voidStartTimer(enum Timer0_Prescaler_t Timer0_Prescaler)	//{NoSrc,DivBy1,DivBy8,DivBy64,DivBy256,DivBy1024,EXT_Falling,EXT_Rising}
{
	switch (Timer0_Prescaler)
	{
		case DivBy1:
			PPrescaler = 1;
			break;
		case DivBy8:
			PPrescaler = 8;
			break;
		case DivBy64:
			PPrescaler = 64;
			break;
		case DivBy256:
			PPrescaler = 256;
			break;
		case DivBy1024:
			PPrescaler = 1024;
			break;
		default:
			return;
	}
	Timer0_REG->TCCR0B |= Timer0_Prescaler;
}
void MTimer0_voidStopTimer(void)
{
	Timer0_REG->TCCR0B &= ~7;
}
void MTimer0_voidSetPeriodic_INT(enum Timer0_WGM_t Timer0_Mode ,u32 Copy_u32Duration,void(*CallBack)(void))
{
 	u32 overflow_time = 256 * PPrescaler*1000000/ 8000000;//256
	u8 NeededTicks= 0;
	if (Timer0_Mode==7 || Timer0_Mode ==3)
	{
		Needed_OverFlows = Copy_u32Duration/overflow_time;
		if ((Needed_OverFlows - (u32)(Needed_OverFlows)) != 0)
			Needed_OverFlows++;
		PCounter = 3;
		GIE_voidEnable();
		Timer0_TIMSK |= 1;
		Timer0_GlobalCallback = CallBack;
		return;
	}
	
	if(Copy_u32Duration == overflow_time)
	{
		PCounter = 0;
	}
	else if(Copy_u32Duration < overflow_time)
	{
		PCounter =1;
		NeededTicks = (Copy_u32Duration/overflow_time)*256;
		PPreload = 255- NeededTicks;
	}
	else if(Copy_u32Duration > overflow_time)
	{
		PCounter = 2;
		Needed_OverFlows = Copy_u32Duration/overflow_time; //10-10.25
		PPreload = 256-((Needed_OverFlows - (u32)Needed_OverFlows)*256);
		if ((Needed_OverFlows - (u32)(Needed_OverFlows)) == 0)//2-2
		{
			PPreload =0;
		}
		else 
			Needed_OverFlows++;
	}
	Timer0_REG->TCNT0 = PPreload;
	GIE_voidEnable();
	Timer0_TIMSK |= 1;	
	Timer0_GlobalCallback = CallBack;

}
void MTimer0_voidSetFrequancey(enum Timer0_Channel_t Timer0_Channel,u32 Copy_u32Clock)
{
	if(Timer0_Channel)
	{
		Timer0_REG->OCR0B = (float)F_CPU/(2*PPrescaler*Copy_u32Clock)-1;
	}
	else
	{
		Timer0_REG->OCR0A = (float)F_CPU/(2*PPrescaler*Copy_u32Clock)-1;
	}
}
void MTimer0_voidSetDutyCycle(enum Timer0_Channel_t Timer0_Channel,u8 Copy_u8DutyCycle)
{
	if(Timer0_Channel)
		{
			Timer0_REG->OCR0B = Copy_u8DutyCycle;
		}
	else
		{
			Timer0_REG->OCR0A = Copy_u8DutyCycle;
		}

}

void MTimer0_voidSetPeriodic_Ticks_INT(u32 Copy_u32Ticks,void(*CallBack)(void))
{
	Timer0_GlobalCallback = CallBack;
	if (Copy_u32Ticks == 256)
	{
		PCounter = 0;
	}
	else if (Copy_u32Ticks < 256)
	{
		PPreload = 256 - Copy_u32Ticks;
		PCounter = 1;
	}
	else 
	{
		PCounter = 2;
		Needed_OverFlows = Copy_u32Ticks/256;
		PPreload = 0;
	}
	GIE_voidEnable();
	Timer0_TIMSK |= 1;
}

void MTimer0_voidSetCallback(void(*Callback)(void))
{
	Timer0_GlobalCallback = Callback;
}




void Timer0_COMPA(void)
{
	if (Timer0_GlobalCallback !=0)
		Timer0_GlobalCallback();
}
void Timer0_COMPB(void)
{
	if (Timer0_GlobalCallback !=0)
		Timer0_GlobalCallback();
}
void Timer0_OVF()
{
	if (Timer0_GlobalCallback ==0)
		return;
	PCounter_TOV++;
	switch(PCounter)
	{
	case 0:
		Timer0_GlobalCallback();
		return;
	case 1:
		Timer0_GlobalCallback();
		Timer0_REG->TCNT0 = PPreload;
		return;
	case 2:
		if(PCounter_TOV == (u32)Needed_OverFlows)
		{
			Timer0_GlobalCallback();
			Timer0_REG->TCNT0 = PPreload;
			PCounter_TOV = 0;
		}
		return;
	case 3:
		if(PCounter_TOV == (u32)Needed_OverFlows)
		{
			Timer0_GlobalCallback();
			PCounter_TOV = 0;
		}
		return;

	}
}

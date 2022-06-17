/*
 * SevenSegment_program.c
 *
 * Created: 9/7/2021 10:34:05 AM
 *  Author: ALL IN ONE
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../LED/LED_interface.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"

void HSevenSegment_voidInit(SevenSegment_t* SS)
{
	for(u8 x=0;x<7;x++)
	{
		SS->Segments[x].ConnectionType = SS->Type; //commonAnode == ActiveLow =0 ,, CommonCathode = ActiveHigh =1 
		HLED_voidInit(SS->Segments+x);
	}
	if(SS->DPState)
	{
		SS->Segments[7].ConnectionType = SS->Type; //commonAnode == ActiveLow =0 ,, CommonCathode = ActiveHigh =1
		HLED_voidInit(SS->Segments+7);
	}
	HSevenSegment_voidClear(SS);
}

void HSevenSegment_voidInitONSinglePORT(SevenSegment_t* SS ,GPIOPortID_t port)
{
	for(u8 x=0;x<7;x++)
	{
		SS->Segments[x]=HLED_LED_t_Initialization(port,x,SS->Type); //commonAnode == ActiveLow =0 ,, CommonCathode = ActiveHigh =1
	}
	if(SS->DPState)
	{
		SS->Segments[7]=HLED_LED_t_Initialization(port,7,SS->Type); //commonAnode == ActiveLow =0 ,, CommonCathode = ActiveHigh =1
	}
	HSevenSegment_voidClear(SS);
}

void HSevenSegment_voidInitOnPins(SevenSegment_t* SS,GPIOPortID_t port0 ,u8 pin0,GPIOPortID_t port1 ,u8 pin1,GPIOPortID_t port2 ,u8 pin2,GPIOPortID_t port3 ,u8 pin3,GPIOPortID_t port4 ,u8 pin4,GPIOPortID_t port5 ,u8 pin5,GPIOPortID_t port6 ,u8 pin6,GPIOPortID_t port7 ,u8 pin7)
{
	SS->Segments[0]=HLED_LED_t_Initialization(port0,pin0,SS->Type);
	SS->Segments[1]=HLED_LED_t_Initialization(port1,pin1,SS->Type);
	SS->Segments[2]=HLED_LED_t_Initialization(port2,pin2,SS->Type);
	SS->Segments[3]=HLED_LED_t_Initialization(port3,pin3,SS->Type);
	SS->Segments[4]=HLED_LED_t_Initialization(port4,pin4,SS->Type);
	SS->Segments[5]=HLED_LED_t_Initialization(port5,pin5,SS->Type);
	SS->Segments[6]=HLED_LED_t_Initialization(port6,pin6,SS->Type);
	if(SS->DPState)
		SS->Segments[7]=HLED_LED_t_Initialization(port7,pin7,SS->Type);
	HSevenSegment_voidClear(SS);
	
}

void HSevenSegment_voidDisplayDigit(SevenSegment_t* SS, u8 Digit)
{
	u8 DisplayCode= SevenSegment_DisplayCode[Digit];
	for(u8 x=0; x<7 ; x++)
	{
		if(GET_BIT(DisplayCode,x)==1)
			HLED_voidTurnOn(SS->Segments+x);
		else
			HLED_voidTurnOff(SS->Segments+x);
			
	}
}

void HSevenSegment_voidClear(SevenSegment_t* SS)
{
	for(u8 x=0 ; x<7 ; x++)
	{
		HLED_voidTurnOff(SS->Segments+x);
	}
	if(SS->DPState)
		HLED_voidTurnOff(SS->Segments+7);
}

void HSevenSegment_voidSetDP(SevenSegment_t* SS)
{
	if (SS->DPState)
		HLED_voidTurnOn(SS->Segments+7);
}

void HSevenSegment_voidClearDP(SevenSegment_t* SS)
{
	if (SS->DPState)
	HLED_voidTurnOff(SS->Segments+7);
}

//u8 HSevenSegment_u8GetDigit(SevenSegment_t* SS)
//{
	//u8 LocalDigid =0x00;
	//if (SS->Type == COMMON_CATHODE)
	//{
		//for(u8 x=0 ; x<7;x++)
			//if()
	//}
//}

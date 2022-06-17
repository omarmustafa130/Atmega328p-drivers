/*
 * SevenSegment_interface.h
 *
 * Created: 9/6/2021 1:22:52 PM
 *  Author: ALL IN ONE
 */ 


#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

typedef enum SevenSegmentType{COMMON_ANODE,COMMON_CATHODE}SevenSegmentType;
typedef enum SevenSegemntDP{DP_DISABLE,DP_ENABLE}SevenSegemntDP;

typedef struct{
	
	SevenSegmentType Type;
	LED_t Segments[8];
	enum SevenSegemntDP DPState;
	
}SevenSegment_t;

void HSevenSegment_voidInit(SevenSegment_t* SS);
void HSevenSegment_voidInitONSinglePORT(SevenSegment_t* SS ,GPIOPortID_t port);
void HSevenSegment_voidInitOnPins(SevenSegment_t* SS,GPIOPortID_t port0 ,u8 pin0,GPIOPortID_t port1 ,u8 pin1,GPIOPortID_t port2 ,u8 pin2,GPIOPortID_t port3 ,u8 pin3,GPIOPortID_t port4 ,u8 pin4,GPIOPortID_t port5 ,u8 pin5,GPIOPortID_t port6 ,u8 pin6,GPIOPortID_t port7 ,u8 pin7);


void HSevenSegment_voidDisplayDigit(SevenSegment_t* SS, u8 Digit);

void HSevenSegment_voidClear(SevenSegment_t* SS);

void HSevenSegment_voidSetDP(SevenSegment_t* SS);

void HSevenSegment_voidClearDP(SevenSegment_t* SS);

u8 HSevenSegment_u8GetDigit(SevenSegment_t* SS);





#endif /* SEVENSEGMENT_INTERFACE_H_ */
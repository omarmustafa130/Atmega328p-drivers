/*
 * TIMER0_private.h
 *
 * Created: 9/27/2021 3:36:50 PM
 *  Author: AOM
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
void(*Timer0_GlobalCallback)(void);
static u16 PPrescaler;
static u8 PCounter=2;
static u8 PPreload=0;
static u32 PCounter_TOV = 0;
static f32 Needed_OverFlows;
typedef struct
{
	u8 TCCR0A;
	u8 TCCR0B;
	u8 TCNT0;
	u8 OCR0A;
	u8 OCR0B;
}Timer0;

#define Timer0_REG			((volatile Timer0*)0x44)
#define Timer0_TIMSK		*((volatile u8*)0x6E)
#define Timer0_TIFR			*((volatile u8*)0x35)

#define Timer0_COMPA	__vector_14
#define Timer0_COMPB	__vector_15
#define Timer0_OVF		__vector_16

void Timer0_COMPA(void)		__attribute__((signal,used));
void Timer0_COMPB(void)		__attribute__((signal,used));
void Timer0_OVF(void)		__attribute__((signal,used));

#endif /* TIMER0_PRIVATE_H_ */

/*
 * EXTI_private.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Omar
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EICRA	(*(volatile u8*)0x69)
#define EIMSK	(*(volatile u8*)0x3D)
#define EIFR	(*(volatile u8*)0x3C)
#define PCICR_reg	(*(volatile u8*)0x68)
#define PCIFR	(*(volatile u8*)0x3B)




#define PCMSK0	*((volatile u8*)0x6B)
#define PCMSK1	*((volatile u8*)0x6C)
#define PCMSK2	*((volatile u8*)0x6D)

void (*Global_Callback[3])(void) = {0,0,0};
void (*Global_CallbackPCINT[3])(void) = {0,0,0};
	
#define EXTI_VEC1 		__vector_1
#define EXTI_VEC2 		__vector_2

void EXTI_VEC1()		__attribute__((signal,used));
void EXTI_VEC2()		__attribute__((signal,used));

#define  EXTI_VEC_PCINT0 		__vector_3
#define  EXTI_VEC_PCINT1 		__vector_4
#define  EXTI_VEC_PCINT2 		__vector_5

void EXTI_VEC_PCINT0()	__attribute__((signal,used));
void EXTI_VEC_PCINT1()	__attribute__((signal,used));
void EXTI_VEC_PCINT2()	__attribute__((signal,used));

#endif /* EXTI_PRIVATE_H_ */

/*
 * UASRT_private.h
 *
 *  Created on: Sep 21, 2021
 *      Author: G2
 */

#ifndef UASRT_PRIVATE_H_
#define UASRT_PRIVATE_H_

static u8 PUSART_Mode;

void (*USART_GlobalCallback)(void);

typedef struct
{
	u8 UCSR0A;
	u8 UCSR0B;
	u8 UCSR0C;
	u8 RESERVED;
	u8 UBRR0L;		//USART baud rate register low
	u8 UBRR0H;		//USART baud rate register high
	u8 UDR0;		//USART I/O data register
}USART_REGs;

#define USART_REG 		((volatile USART_REGs*)0xC0)

#define USART_RX		__vector_18
#define USART_RE		__vector_19
#define USART_TX		__vector_20

void USART_RX(void)__attribute__((signal,used));
void USART_RE(void)__attribute__((signal,used));
void USART_TX(void)__attribute__((signal,used));

#endif /* UASRT_PRIVATE_H_ */

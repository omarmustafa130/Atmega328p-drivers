/*
 * UASRT_interface.h
 *
 *  Created on: Sep 21, 2021
 *      Author: G2
 */

#ifndef UASRT_INTERFACE_H_
#define UASRT_INTERFACE_H_

//UCSR0C
#define F_CPU 8000000UL


enum USART_Mode_t{Asynchronous,Synchronous,MSPIM=3};						//bit 6 & 7
enum USART_ParityMode_t{Disabled,even=2,odd};							//bit 4 & 5
enum USART_StopBit_t{one_bit,two_bit};											//bit 3
enum USART_CharSize_t{five_bits,six_bits,se7en_bits,eight_bits,nine_bits};		//bit 1 & 2
enum USART_ClockPolarity_t{RisingTX_FallingRX,RisingRX_FallingTX};				//bit 0 			//Write this bit to zero when asynchronous mode

void MUSART_voidSet_BaudRate(u32 local_baudrate);								//tested
void MUSART_voidInit(enum USART_Mode_t USART_Mode,enum USART_CharSize_t USART_CharSize,enum USART_StopBit_t USART_StopBit,enum USART_ParityMode_t USART_ParityMode);	//tested
void MUSART_voidEnable_DSM(void);
void MUSART_voidTransmit_Char(u8 Copy_u8Transmit_Value);						//tested
u8 MUSART_u8Receive_Char(void);													//tested
void MUSART_voidTransmit_Str(u8* Ptr_u8Transmit_Value);							//tested
u8 MUSART_u8Receive_Str(void);
void MUSART_voidTX_EI(void(*LocalCallback)(void));
void MUSART_voidRX_EI(void(*LocalCallback)(void));
void MUSART_voidRE_EI(void(*LocalCallback)(void));





void USART_RX();
void USART_RE();
void USART_TX();
#endif /* UASRT_INTERFACE_H_ */

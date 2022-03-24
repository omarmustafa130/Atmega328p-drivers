/*
 * EXTI_interface.h
 *
 *  Created on: Sep 18, 2021
 *      Author: G2
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#define F_CPU 8000000UL

enum EXTI_Trigger_t					{low_level,logical_change,falling_edge,rising_edge};
enum EXTI_ID_t 						{EXTI_INT0,EXTI_INT1};
enum EXTI_PCINT_num 				{EXTI_PCINT0,EXTI_PCINT1,EXTI_PCINT2};
	
void MEXTI_voidSetCallback			(enum EXTI_ID_t EXTI_ID,void (*Local_Callback)(void));
void MEXTI_voidSetCallbackPCINT		(enum EXTI_PCINT_num EXTI_PCINT,void (*Local_Callback)(void));

void MEXTI_voidEnable				(enum EXTI_ID_t EXTI_ID,enum EXTI_Trigger_t EXTI_Trigger);
void MEXTI_voidDisable				(enum EXTI_ID_t EXTI_ID);

void MEXTI_voidEnablePCINT			(enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber);
void MEXTI_voidDisablePCINT			(u8 Copy_u8_pinnumber);


#endif /* EXTI_INTERFACE_H_ */

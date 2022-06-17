/*
 * KEYPAD_interface.h
 *
 * Created: 1/2/2022 12:48:43 PM
 *  Author: AOM
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "KEYPAD_interface.h"


void HKeypad_Void_Init(void);
u8 HKeypad_u8_GetKey(void);




#endif /* KEYPAD_INTERFACE_H_ */
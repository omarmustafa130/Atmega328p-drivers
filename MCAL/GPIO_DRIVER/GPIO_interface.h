/*
 * GPIO_interface.h
 *
 * Created: 9/15/2021 9:07:31 PM
 *  Author: The Warlock & Omar
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

enum GPIO_PORT_ID {GPIO_PortB,GPIO_PortC,GPIO_PortD};
enum GPIO_DIRECTION {GPIO_INPUT,GPIO_OUTPUT,GPIO_INPUT_PULLUP};
enum GPIO_VALUE_t {GPIO_LOW,GPIO_HIGH};
	
void MGPIO_voidSetPORT_DIRECTION (enum GPIO_PORT_ID PORT_ID,enum GPIO_DIRECTION ONE_Direction);
void MGPIO_voidSetPIN_DIRECTION (enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber,enum GPIO_DIRECTION ONE_Direction);
void MGPIO_voidSetPORT_VALUE (enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_Value);
void MGPIO_voidSetPIN_VALUE (enum GPIO_PORT_ID PORT_ID, u8 Copy_u8_PinNumber,enum GPIO_VALUE_t GPIO_VALUE);
u8 MGPIO_u8GetPORT_VALUE(enum GPIO_PORT_ID PORT_ID);
u8 MGPIO_u8GetPIN_VALUE(enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_PinNumber);
void MGPIO_voidTOGGLE_PIN(enum GPIO_PORT_ID PORT_ID,u8 Copy_u8_PinNumber);
void MGPIO_voidTOGGLE_PORT(enum GPIO_PORT_ID PORT_ID);




#endif /* GPIO_INTERFACE_H_ */
/*
 * LED_interface.h
 *
 * Created: 8/28/2021 1:50:29 PM
 *  Author: mario
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum{LED_ACTIVE_LOW,LED_ACTIVE_HIGH} LEDState_t;
typedef struct  
{
	GPIOPortID_t port;
	u8 pin;
	LEDState_t ConnectionType ;
} LED_t;

LED_t HLED_LED_t_Initialization(GPIOPortID_t led_port, u8 led_pin , LEDState_t connection);
void HLED_voidInit(LED_t *The_Led);
void HLED_voidTurnOn(LED_t* The_LED);
void HLED_voidTurnOff(LED_t* The_LED);
void HLED_voidToogle(LED_t* The_LED);



#endif /* LED_INTERFACE_H_ */
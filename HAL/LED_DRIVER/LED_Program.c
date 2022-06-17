/*
 * LED_Program.c
 *
 * Created: 8/30/2021 9:01:37 AM
 *  Author: mario
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"

LED_t HLED_LED_t_Initialization(GPIOPortID_t led_port, u8 led_pin , LEDState_t connection)
{
	LED_t The_LED;
	The_LED.port = led_port;
	The_LED.pin = led_pin;
	The_LED.ConnectionType = connection;
	MGPIO_voidSetPinDirection(led_port,led_pin,GPIO_OUTPUT);
	HLED_voidTurnOff(&The_LED);
	return The_LED;	
}

void HLED_voidInit(LED_t *The_Led)
{
	MGPIO_voidSetPinDirection(The_Led->port,The_Led->pin,GPIO_OUTPUT);
	HLED_voidTurnOff(The_Led);
}

void HLED_voidTurnOn(LED_t* The_LED)
{
	if(The_LED->ConnectionType == LED_ACTIVE_HIGH)
		MGPIO_voidSetPinValue(The_LED->port,The_LED->pin,GPIO_HIGH);
	else
		MGPIO_voidSetPinValue(The_LED->port,The_LED->pin,GPIO_LOW);
}

void HLED_voidTurnOff(LED_t* The_LED)
{
	if(The_LED->ConnectionType == LED_ACTIVE_LOW)
	MGPIO_voidSetPinValue(The_LED->port,The_LED->pin,GPIO_HIGH);
	else
	MGPIO_voidSetPinValue(The_LED->port,The_LED->pin,GPIO_LOW);
}

void HLED_voidToogle(LED_t* The_LED)
{
	MGPIO_voidTogglePin(The_LED->port,The_LED->pin);
}

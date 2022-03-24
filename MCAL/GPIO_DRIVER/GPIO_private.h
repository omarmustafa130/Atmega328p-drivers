/*
 * GPIO_private.h
 *
 * Created: 9/15/2021 9:08:09 PM
 *  Author: Omar
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct 
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;	
}PORT_t;

#define PORTB_REG	((volatile PORT_t*)(0x23))
#define PORTC_REG	((volatile PORT_t*)(0x26))
#define PORTD_REG	((volatile PORT_t*)(0x29))

volatile PORT_t* PGPIO_PORT_tPtrGetRegister (enum GPIO_PORT_ID PORT_ID);

#endif /* GPIO_PRIVATE_H_ */

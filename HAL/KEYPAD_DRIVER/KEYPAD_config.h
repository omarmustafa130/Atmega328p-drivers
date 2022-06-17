/*
 * KEYPAD_config.h
 *
 * Created: 1/2/2022 12:49:02 PM
 *  Author: AOM
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define ROWS 4
#define COLS 3

#define COL_START 0
#define ROW_START 3

#define KEYPAD_PORT GPIO_PORTC

unsigned char ArrKeypadValue [ROWS] [COLS] = {	{1,2,3},
{4,5,6},
{7,8,9},
{' ',0,'='}};


#endif /* KEYPAD_CONFIG_H_ */
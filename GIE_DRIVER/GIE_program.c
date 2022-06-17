/*
 * GIE_program.c
 *
 * Created: 9/19/2021 3:15:07 PM
 *  Author: AOM
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"
void GIE_voidEnable(void)
{
	SREG|= (1<<7);
}
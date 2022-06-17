/*
 * ADC_program.c
 *
 * Created: 9/19/2021 2:15:06 PM
 *  Author: AOM
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "ADC_interface.h"
#include "ADC_Confg.h"
#include "ADC_private.h"

void MADC_voidIntialize(enum ADC_REF_VSEL_t VREFF,enum ADC_ConversionMode_t ADC_ConversionMode)
{
	CLR_REG(ADC_REG->ADCSRA);
	CLR_REG(ADC_REG->ADMUX);
	ADC_REG->ADMUX |= (VREFF<<6);
	ADC_REG->ADCSRA |= Division_Factor;
	if (ADC_ConversionMode)
	{	
		GIE_voidEnable();
		SET_BIT(ADC_REG->ADCSRA,3);
		SET_BIT(ADC_REG->ADCSRA,5);
	}	
}

void MADC_voidStartContinuous(void)
{
	SET_BIT(ADC_REG->ADCSRA,7);
	if (PADC_FreeRunningMode==1)
		SET_BIT(ADC_REG->ADCSRA,6);
}
void MADC_voidStopContinuous(void)
{
	CLR_BIT(ADC_REG->ADCSRA,7);
}

void MADC_voidSetTriggerSource(enum ADC_Resulution_t ADC_Resulution,enum ADC_Trigger_t ADC_Trigger, enum ADC_Channel_SEL_t ADC_Channel,void (*Callback)(u16))
{	
	PADC_Resolution = ADC_Resulution;
	if (!ADC_Resulution)
		SET_BIT(ADC_REG->ADMUX, 5);
	if (ADC_Trigger == Free_running)
		PADC_FreeRunningMode = 1; 
	else 
		PADC_FreeRunningMode = 0;
	ADC_REG->ADCSRB &= ~(7);
	ADC_REG->ADMUX  &= ~(15);
    ADC_REG->ADCSRB |= ADC_Trigger;
	ADC_REG->ADMUX	|= ADC_Channel;
	ADCGlobalCallback   = Callback;
	
}
u16 MADC_voidReadValueASynch(enum ADC_Channel_SEL_t ADC_Channel, enum ADC_Resulution_t ADC_Resulution)
{	ADC_REG->ADMUX &= ~(15);
	ADC_REG->ADMUX |= ADC_Channel;
	u16 Local_RES=0;
	SET_BIT(ADC_REG->ADCSRA,7);
	SET_BIT(ADC_REG->ADCSRA,6);
	while (GET_BIT(ADC_REG->ADCSRA, 4) == 0);
	if(ADC_Resulution)
	{
		Local_RES = ADC_REG->ADCL;
		Local_RES |= (((u16)ADC_REG->ADCH)<<8);
		SET_BIT(ADC_REG->ADCSRA, 4);
	}
	else
	{
		Local_RES = ADC_REG->ADCH;
		SET_BIT(ADC_REG->ADCSRA, 4);
	}
	CLR_BIT(ADC_REG->ADCSRA,7);
	return Local_RES;
}

void ADC_ISR()
{	
	if (ADCGlobalCallback !=0)
	{
	u16 Local_RES =0;
	if (PADC_Resolution)
	{
		Local_RES = ADC_REG->ADCL;
		Local_RES |= (((u16)ADC_REG->ADCH)<<8);
	}
	else
	{
		Local_RES = ADC_REG->ADCH;
	}
		ADCGlobalCallback(Local_RES);
		if (PADC_FreeRunningMode)
			SET_BIT(ADC_REG->ADCSRA,6);
	}
}
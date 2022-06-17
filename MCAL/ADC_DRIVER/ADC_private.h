/*
 * ADC_private.h
 *
 * Created: 9/19/2021 2:14:41 PM
 *  Author: AOM
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

static u8 PADC_FreeRunningMode=0;
static u8 PADC_Resolution=0;

typedef struct 
{
	u8 ADCL;
	u8 ADCH;
	u8 ADCSRA;
	u8 ADCSRB;
	u8 ADMUX;	
}ADC_t;

#define ADC_REG		((volatile  ADC_t*)(0x78))
#define ADC_DIDR	*((volatile u8*)(0x7E))

void (*ADCGlobalCallback)(u16);
#define ADC_ISR		__vector_21
void ADC_ISR(void)	__attribute__((signal,used));

#endif /* ADC_PRIVATE_H_ */
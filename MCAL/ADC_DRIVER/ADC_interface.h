/*
 * ADC_interface.h
 *
 * Created: 9/19/2021 2:14:52 PM
 *  Author: AOM
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

enum ADC_ConversionMode_t{ADC_SingleConversion, ADC_ContinuousMode};
enum ADC_REF_VSEL_t{AREF,AVCC,RESERVED,Internal_V};
enum ADC_Channel_SEL_t{ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7,ADC8};
enum ADC_DivisionF_t{DIVby2_0,DIVby2_1,DIVby4,DIVby8,DIVby16,DIVby32,DIVby64,DIVby128};
enum ADC_Trigger_t{Free_running,AComparator,EXTI_0,TMR0_COMPA, TMR0_OVF,TMR1_COMPB, TMR1_OVF,TMR1_Capture};
enum ADC_Resulution_t{eight_bits,ten_bits};
	
void MADC_voidIntialize(enum ADC_REF_VSEL_t VREFF,enum ADC_ConversionMode_t ADC_ConversionMode);
void MADC_voidStartContinuous(void);
void MADC_voidStopContinuous(void);
u16 MADC_voidReadValueASynch(enum ADC_Channel_SEL_t ADC_Channel, enum ADC_Resulution_t ADC_Resulution);
void MADC_voidSetTriggerSource(enum ADC_Resulution_t ADC_Resulution,enum ADC_Trigger_t ADC_Trigger, enum ADC_Channel_SEL_t ADC_Channel,void (*Callback)(u16));

#endif /* ADC_INTERFACE_H_ */
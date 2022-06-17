/*
 * TIMER0_interface.h
 *
 * Created: 9/27/2021 3:36:28 PM
 *  Author: AOM
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#define F_CPU 8000000UL

enum COM0_CTC{NONPWM_OC0_Disconnected, NONPWM_TOG_OC0, NONPWM_CLR_OC0, NONPWM_SET_OC0};
enum COM0_FastPWM{FastPWM_OC0_Disconnected, FastPWM_TOG_OC0, FastPWM_0_NON_INVERTING, FastPWM_0_INVERTING};
enum COM0_PhaseCorrectPWM{PhaseCorrectPWM_OC0_Disconnected, PhaseCorrectPWM_TOG_OC0, PhaseCorrectPWM_0_NON_INVERTING, PhaseCorrectPWM_0_INVERTING};
enum Timer0_WGM_t{Normal,PPWM255,CTC,FPWM,PPWMC=5,FPWMC=7};
enum Timer0_Prescaler_t{NoSrc,DivBy1,DivBy8,DivBy64,DivBy256,DivBy1024,EXT_Falling,EXT_Rising};
enum Timer0_Channel_t{Timer0_ChannelA, Timer0_ChannelB};


void MTimer0_voidInit_Channel(enum Timer0_WGM_t Timer0_WGM,u8 TIMER0_OC0Mode );
void MTimer0_voidStartTimer(enum Timer0_Prescaler_t Timer0_Prescaler);
void MTimer0_voidStopTimer(void);
void MTimer0_voidSetPeriodic_INT(enum Timer0_WGM_t Timer0_Mode,u32 Copy_u32Duration,void(*CallBack)(void));
void MTimer0_voidSetPeriodic_Ticks_INT(u32 Copy_u32Ticks,void(*CallBack)(void));

void MTimer0_voidEnable_INT(void);
void MTimer0_voidDisable_INT(void);
void MTimer0_voidSetCallback(void(*Callback)(void));
void MTimer0_voidSetFrequancey(enum Timer0_Channel_t Timer0_Channel,u32 Copy_u32Clock);
void MTimer0_voidSetDutyCycle(enum Timer0_Channel_t Timer0_Channel,u8 Copy_u8DutyCycle);
void MTimer0_voidDelay(enum Timer0_Channel_t Timer0_Channel,u8 Copy_u8Duration);







#endif /* TIMER0_INTERFACE_H_ */

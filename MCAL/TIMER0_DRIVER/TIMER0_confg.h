/*
 * TIMER0_confg.h
 *
 *  Created on: Sep 28, 2021
 *      Author: G2
 */

#ifndef TIMER0_CONFG_H_
#define TIMER0_CONFG_H_

#define Normal_Mode_OC0			NONPWM_OC0_Disconnected
#define CTC_Mode_OC0			NONPWM_TOG_OC0				//{NONPWM_OC0_Disconnected, NONPWM_TOG_OC0, NONPWM_CLR_OC0, NONPWM_SET_OC0}
#define FastPWM_OC0				FastPWM_TOG_OC0				//{FastPWM_OC0_Disconnected, FastPWM_TOG_OC0, FastPWM_0_NON_INVERTING, FastPWM_0_INVERTING}
#define PCPWM_OC0				PhaseCorrectPWM_TOG_OC0		//{PhaseCorrectPWM_OC0_Disconnected, PhaseCorrectPWM_TOG_OC0, PhaseCorrectPWM_0_NON_INVERTING, PhaseCorrectPWM_0_INVERTING}


#endif /* TIMER0_CONFG_H_ */

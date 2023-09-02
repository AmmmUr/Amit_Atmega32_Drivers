/*
 * TMR_Config.h
 *
 * Created: 9/22/2022 12:37:49 PM
 *  Author: Ammar
 */ 


#ifndef TMR_CONFIG_H_
#define TMR_CONFIG_H_

/*
Options for TMR0 MODE
1- TMR_TMR0_NORMAL_MODE
2- TMR_TMR0_CTC_MODE
3- TMR_TMR0_FAST_PWM_MODE
*/

#define  TMR_TMR0_MODE     TMR_TMR0_FAST_PWM_MODE

#define  TMR_TMR0_CTC_COUNTER           965

#define TMR_TMR0_PRELOAD_VALUE          6

#define TMR_TMR0_OVERFLOW_COUNTER       965


#endif /* TMR_CONFIG_H_ */
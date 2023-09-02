/*
 * TMR_Interface.h
 *
 * Created: 9/22/2022 12:37:37 PM
 *  Author: Ammar
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

#define TMR_TMR0_NORMAL_MODE   1
#define TMR_TMR0_CTC_MODE      2
#define TMR_TMR0_FAST_PWM_MODE 3

void TMR_TMR0_OVF_SetCallBack(void(*ptr)(void));
void TMR_timer0Init(void);
void TMR_timer0start(void);
void TMR_timer0stop(void);
void TMR_timer0SetCompareMatchValue(u8 ocr0_value);
void TMR_TMR0_CTC_SetCallBack(void(*ptr)(void));



#endif /* TMR_INTERFACE_H_ */
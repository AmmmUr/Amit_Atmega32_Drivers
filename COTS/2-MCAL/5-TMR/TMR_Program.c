/*
 * TMR_Program.c
 *
 * Created: 9/22/2022 12:37:17 PM
 *  Author: NoUr MD
 */ 

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "TMR_Interface.h"
#include "TMR_Config.h"

static void(*TMR_TMR0_OVF_pCallBack)(void) = NULL;
static void(*TMR_TMR0_CTC_pCallBack)(void) = NULL;


void TMR_timer0Init(void){
	
#if  TMR_TMR0_MODE == TMR_TMR0_NORMAL_MODE
	//Select Mode = Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	//init timer 0 register
	TCNT0 = TMR_TMR0_PRELOAD_VALUE;
	//Enable Over Flow Interrupt
	SET_BIT(TIMSK,0);
#elif  TMR_TMR0_MODE == TMR_TMR0_CTC_MODE
    //Select Mode = CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//Enable CTC Interrupt
	SET_BIT(TIMSK,1);
	
#elif  TMR_TMR0_MODE == TMR_TMR0_FAST_PWM_MODE
	//Select Mode = Fast PWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//Select Non-Inverting Mode
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);


#endif
}

void TMR_timer0start(void){
		//Select Prescaler Value = 64
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
}
void TMR_timer0stop(void){
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void TMR_timer0SetCompareMatchValue(u8 ocr0_value){
	//Init Timer with Compare Value
	OCR0=ocr0_value;
}


void TMR_TMR0_OVF_SetCallBack(void(*ptr)(void)){
	if(ptr!=NULL){
		TMR_TMR0_OVF_pCallBack=ptr;
	}
}

//ISR Function ProtoTypbe for TMR0 Normal
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void){
	static u16 counterOVF=0;
	++counterOVF;
	TCNT0 = TMR_TMR0_PRELOAD_VALUE;
	if(TMR_TMR0_OVERFLOW_COUNTER==counterOVF){
		counterOVF=0;
		if(TMR_TMR0_CTC_pCallBack!=NULL){
			TMR_TMR0_CTC_pCallBack();
		}
		
	}
}
void TMR_TMR0_CTC_SetCallBack(void(*ptr)(void)){
	if(ptr!=NULL){
		TMR_TMR0_CTC_pCallBack=ptr;
	}
}

//ISR Function ProtoTypbe for TMR0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void){
	static u16 counterCTC=0;
	++counterCTC;
	if(TMR_TMR0_CTC_COUNTER==counterCTC){
		counterCTC=0;
		if(TMR_TMR0_CTC_pCallBack!=NULL){
			TMR_TMR0_CTC_pCallBack();
		}
		
	}
}
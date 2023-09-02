/*
 * ADC_Program.c
 *
 * Created: 9/20/2022 12:41:48 PM
 *  Author: NoUr MD
 */ 


//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "ADC_Interface.h"

void ADC_Init(void){
	
	//Select Verf = AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	//Select Right Adjustment
	CLR_BIT(ADMUX,5);
	//Single Conversation Mode
	CLR_BIT(ADCSRA,5);
	//Prescaler 128 for 16 Mega Hz
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	//ADC Enable
	SET_BIT(ADCSRA,7);
}
void ADC_GetDigitalValue(u8 ChannelNumber,u16* DigitalValue){
	
	if((ChannelNumber<32)&&(DigitalValue!=NULL)){
		//Clear ADMUX Channel Bits
		ADMUX&=0b11100000;
		//Select Channel Number
		ADMUX|=ChannelNumber;
		//Start Conversition
		SET_BIT(ADCSRA,6);
		//Wait For The Flag of ADC
		while(0 == GET_BIT(ADCSRA,4));
		//Clear Flag
		SET_BIT(ADCSRA,4);
		//Read Digital Value
		*DigitalValue = ADC_u16;
	}
}

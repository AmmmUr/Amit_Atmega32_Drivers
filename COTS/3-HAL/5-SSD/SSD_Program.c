/*
 * SSD_Program.c
 *
 * Created: 9/18/2022 12:38:38 PM
 *  Author: NoUr MD
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"

//HAL
#include "SSD_Interface.h"



void SSD_ON(u8 connection){
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	switch(connection){
		case SSD_BothSides:
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	break;
	
	case SSD_Left:
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	break;
	
	case SSD_Right:
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	break;
	}
}
void SSD_OFF(void){
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
}

void SSD_DisplyNumberTwoDigits(u8 Number){
	u16 counter;
	for(counter=0;counter<250;counter++){
	SSD_ON(SSD_Right);
	SSD_DisplyNumber(Number%10);
	_delay_ms(1);
	SSD_ON(SSD_Left);
	SSD_DisplyNumber(Number/10);
	_delay_ms(1);
	}
	SSD_OFF();
}


void SSD_DisplyNumber(u8 DesiredNumber){
	WriteHalfPort(DesiredNumber);
}

static void WriteHalfPort(u8 value){
	
	if(GET_BIT(value,0)==DIO_PIN_HIGH){
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
	}
	else{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}
	
	if(GET_BIT(value,1)==DIO_PIN_HIGH){
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
	}
	else{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	
	if(GET_BIT(value,2)==DIO_PIN_HIGH){
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
	}
	else{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	
	if(GET_BIT(value,3)==DIO_PIN_HIGH){
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	}
	else{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
	
}

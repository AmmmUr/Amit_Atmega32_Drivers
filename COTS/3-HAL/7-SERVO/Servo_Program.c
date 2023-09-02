/*
 * Servo_Program.c
 *
 * Created: 9/30/2022 10:40:22 PM
 *  Author: NoUr MD
 */ 


//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"
#include "TMR_Interface.h"
#include "TMR_Config.h"

void Servo_ON(void){
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	TMR_timer1Init();
	TMR_timer1start();
}

void Servo_OFF (void){
	TMR_timer1stop();
}

void Servo_RotateDegree(s16 Angle){

	if(Angle!=0){
	TMR_timer1SetCompareMatchAValue(374+((Angle*125)/90));
	}
	else{
		TMR_timer1SetCompareMatchAValue(375);
	}
}
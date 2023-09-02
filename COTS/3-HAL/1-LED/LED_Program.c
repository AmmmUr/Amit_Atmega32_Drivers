/*
 * LED_Program.c
 *
 * Created: 9/10/2022 8:42:44 PM
 *  Author: Ammar
 */ 

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"

//MHAL
#include "LED_Interface.h"

void LED_State(u8 PortId,u8 PinId,u8 Connection){
	switch(Connection)
	{
		case 0:
		DIO_SetPinDirection(PortId,PinId,DIO_PIN_OUTPUT);
		DIO_SetPinValue(PortId,PinId,DIO_PIN_LOW);
		break;
		
		case 1:
		DIO_SetPinDirection(PortId,PinId,DIO_PIN_OUTPUT);
		DIO_SetPinValue(PortId,PinId,DIO_PIN_HIGH);
		break;
		
	}
}
		
void LED_TOGGLE(u8 PortId,u8 PinId){
	
	DIO_SetPinDirection(PortId,PinId,DIO_PIN_OUTPUT);
	DIO_TogglePinValue (PortId,PinId);
}


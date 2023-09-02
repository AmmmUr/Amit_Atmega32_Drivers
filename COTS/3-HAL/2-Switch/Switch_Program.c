/*
 * Switch_Program.c
 *
 * Created: 9/10/2022 9:22:06 PM
 *  Author: Ammar
 */ 
//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"

//MHAL
#include "Switch_Interface.h"

u8 Switch_GetState(u8 PortId,u8 PinId){
	u8 State;
	DIO_SetPinDirection(PortId,PinId,DIO_PIN_INPUT);
    DIO_GetPinValue    (PortId,PinId,&State);
	return State;
}

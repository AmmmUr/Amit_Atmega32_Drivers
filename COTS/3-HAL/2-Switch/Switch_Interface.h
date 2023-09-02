/*
 * Switch_Interface.h
 *
 * Created: 9/10/2022 9:22:24 PM
 *  Author: Ammmar
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

//Button 0
#define  Button0_PORT  DIO_PORTB
#define  Button0_PIN   DIO_PIN0
//Button 1
#define  Button1_PORT  DIO_PORTD
#define  Button1_PIN   DIO_PIN6
//Button 2
#define  Button2_PORT  DIO_PORTD
#define  Button2_PIN   DIO_PIN2

u8 Switch_GetState(u8 PortId,u8 PinId);

#endif /* SWITCH_INTERFACE_H_ */
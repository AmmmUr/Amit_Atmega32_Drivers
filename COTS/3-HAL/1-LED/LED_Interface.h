/*
 * LED_Interface.h
 *
 * Created: 9/10/2022 8:43:19 PM
 *  Author: Ammar
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_ON_FW   1
#define LED_OFF_FW  0
#define LED_ON_REV  0
#define LED_OFF_REV 1

//LED 0
#define  LED0_PORT  DIO_PORTC
#define  LED0_PIN   DIO_PIN2
//LED 1
#define  LED1_PORT  DIO_PORTC
#define  LED1_PIN   DIO_PIN7
//LED 2
#define  LED2_PORT  DIO_PORTD
#define  LED2_PIN   DIO_PIN3



void LED_State(u8 PortId,u8 PinId,u8 Connection);

void LED_TOGGLE(u8 PortId,u8 PinId);



#endif /* LED_INTERFACE_H_ */
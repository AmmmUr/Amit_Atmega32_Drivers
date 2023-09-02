/*
 * SSD_Interface.h
 *
 * Created: 9/18/2022 12:38:55 PM
 *  Author: NoUr MD
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_BothSides 0
#define SSD_Left      1
#define SSD_Right     2

void SSD_ON(u8 connection);
void SSD_DisplyNumber(u8 DesiredNumber);
void SSD_DisplyNumberTwoDigits(u8 Number);
static void WriteHalfPort(u8 value);
void SSD_OFF(void);


#endif /* SSD_INTERFACE_H_ */
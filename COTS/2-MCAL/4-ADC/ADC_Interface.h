/*
 * ADC_Interface.h
 *
 * Created: 9/20/2022 12:42:02 PM
 *  Author: NoUr MD
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHAMMEL_0         0
#define ADC_CHAMMEL_1         1
#define ADC_CHAMMEL_2         2
#define ADC_CHAMMEL_3         3
#define ADC_CHAMMEL_4         4
#define ADC_CHAMMEL_5         5
#define ADC_CHAMMEL_6         6
#define ADC_CHAMMEL_7         7

void ADC_Init(void);
void ADC_GetDigitalValue(u8 ChannelNumber,u16* DigitalValue);




#endif /* ADC_INTERFACE_H_ */
/*
 * WDT_Program.c
 *
 * Created: 9/29/2022 1:29:13 PM
 *  Author: NoUr MD
 */ 

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "WDT_Interface.h"

void WDT_Start(void){
	//Select Prescaler Value 2.1 sec
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	//Enable WDT
	SET_BIT(WDTCR,3);
}
void WDT_Stop (void){
	
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<4) | (1<<3);
	/* Turn off WDT */
	WDTCR = 0x00;
	
}
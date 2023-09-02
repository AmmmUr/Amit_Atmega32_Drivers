/*
 * SPI_Program.c
 *
 * Created: 10/4/2022 1:22:48 PM
 *  Author: NoUr MD
 */ 

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "SPI_Interface.h"

void SPI_InitMaster(void){
	//Select Data order LSB Transmitted First
	SET_BIT(SPI->SPCR,5);
	
	//Select Master Mode
	SET_BIT(SPI->SPCR,4);
	
	//Select CLK Polarity Falling => Rising , Select CLK Pahse Setup => Sample 
	SET_BIT(SPI->SPCR,3);
	SET_BIT(SPI->SPCR,2);
	
	//Select CLK Rate = FCPU/16
	SET_BIT(SPI->SPCR,0);
	CLR_BIT(SPI->SPCR,1);
	CLR_BIT(SPI->SPSR,0);
	
	//Enable SPI
	SET_BIT(SPI->SPCR,6);
}

void SPI_InitSlave (void){
	//Select Data order LSB Transmitted First
	SET_BIT(SPI->SPCR,5);
	
	//Select Slave Mode
	CLR_BIT(SPI->SPCR,4);
	
	//Select CLK Polarity Falling => Rising , Select CLK Pahse Setup => Sample
	SET_BIT(SPI->SPCR,3);
	SET_BIT(SPI->SPCR,2);
	
	//Enable SPI
	SET_BIT(SPI->SPCR,6);
	
	
}

void SPI_TransieveMaster (u8 TxData,u8* RxData){
	if(RxData != NULL){
		
		SPI->SPDR =TxData;
		while(0 == GET_BIT(SPI->SPSR,7));
		*RxData = SPI->SPDR;
	}
}

void SPI_TransieveSlave (u8 TxData,u8* RxData){
	if (RxData != NULL){
		while(GET_BIT(SPI->SPSR,7) == 0);
		*RxData = SPI->SPDR;
		SPI->SPDR = TxData;
	}
}
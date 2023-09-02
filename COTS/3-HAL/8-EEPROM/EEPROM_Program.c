/*
 * EEPROM_Program.c
 *
 * Created: 10/11/2022 4:12:01 AM
 *  Author: NoUr MD
 */ 

#define F_CPU   16000000UL
#include <util/delay.h>

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "TWI_Interface.h"

//HAL
#include "EEPROM_Interface.h"



void EEPROM_WriteByte(u16 ByteAddress,u8 Data){
	
	u8 Address = (u8)(EEPROM_FIXED_ADDRESS | (u8)(ByteAddress>>8));
	
	//Send start condition
	TWI_SendStartCondition();
	
	//Send slave address with write operation
	TWI_SendSlaveAddwithWrite(Address);
	
	//Send byte address
	TWI_SendMasterDataByte((u8)ByteAddress);
	
	//Send byte data
	TWI_SendMasterDataByte(Data);
	
	//Send stop condition
	TWI_SendStopCondition();
	
	_delay_ms(5);
	
}


void EEPROM_ReadByte (u16 ByteAddress,u8* ReturnedData){
	
	u8 Address = (u8)(EEPROM_FIXED_ADDRESS | (u8)(ByteAddress>>8));
	
	//Send start condition
	TWI_SendStartCondition();
	
	//Send slave address with write operation
	TWI_SendSlaveAddwithWrite(Address);
	
	//Send byte address
	TWI_SendMasterDataByte((u8)ByteAddress);
	
	//Send repeated start
	TWI_SendRepStartCondition();
	
	//Send slave address with read operation
	TWI_SendSlaveAddwithRead(Address);
	
	//Read byte data
	TWI_ReadMasterDataByte(ReturnedData);
	
	//Send stop condition
	TWI_SendStopCondition();
	
	_delay_ms(5);
	
}
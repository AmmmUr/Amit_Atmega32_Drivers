/*
 * EEPROM_Interface.h
 *
 * Created: 10/11/2022 4:12:22 AM
 *  Author: NoUr MD
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


#define EEPROM_FIXED_ADDRESS          0x50

void EEPROM_WriteByte(u16 ByteAddress,u8 Data);
void EEPROM_ReadByte (u16 ByteAddress,u8* ReturnedData);


#endif /* EEPROM_INTERFACE_H_ */
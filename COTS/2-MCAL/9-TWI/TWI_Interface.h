/*
 * TWI_Interface.h
 *
 * Created: 10/6/2022 1:23:55 PM
 *  Author: NoUr MD
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



void TWI_InitMaster           (void);
void TWI_InitSlave            (u8 SlaveAdd);
void TWI_SendStartCondition   (void);
void TWI_SendRepStartCondition(void);
void TWI_SendStopCondition    (void);
void TWI_SendSlaveAddwithWrite(u8 SlaveAdd);
void TWI_SendSlaveAddwithRead (u8 SlaveAdd);
void TWI_SendMasterDataByte   (u8 Data);
void TWI_ReadMasterDataByte   (u8* ReturnedData);


#endif /* TWI_INTERFACE_H_ */
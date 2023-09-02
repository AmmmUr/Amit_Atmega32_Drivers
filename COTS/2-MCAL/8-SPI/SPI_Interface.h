/*
 * SPI_Interface.h
 *
 * Created: 10/4/2022 1:23:02 PM
 *  Author: NoUr MD
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_InitMaster(void);
void SPI_InitSlave (void);
void SPI_TransieveMaster (u8 TxData,u8* RxData);
void SPI_TransieveSlave  (u8 TxData,u8* RxData);

#endif /* SPI_INTERFACE_H_ */
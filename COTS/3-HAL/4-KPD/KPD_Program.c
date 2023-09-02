/*
 * KPD_Program.c
 *
 * Created: 9/13/2022 10:02:47 AM
 *  Author: NoUr MD
 */ 

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"

//HAL
#include "KPD_Interface.h"
#include "KPD_config.h"


void KPD_GetValue(u8* ReturnValue){
	u8 coloumnsPins[KPD_COLS_NUM]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 rowsPins[KPD_ROWS_NUM]    ={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
    u8 KPD_Char[KPD_COLS_NUM][KPD_ROWS_NUM] = KPD_KEYS;
	if(ReturnValue!=NULL){
		*ReturnValue = KPD_NOT_PRESSED;
		u8 colscounter,rowscounter,PinValue,PinFlag=0;
		for(colscounter=0;colscounter<KPD_COLS_NUM;colscounter++){
			DIO_SetPinValue(KPD_COLS_PORT,coloumnsPins[colscounter],DIO_PIN_LOW);
			for(rowscounter=0;rowscounter<KPD_ROWS_NUM;rowscounter++){
				DIO_GetPinValue(KPD_ROWS_PORT,rowsPins[rowscounter],&PinValue);
				if(PinValue==0){
					*ReturnValue=KPD_Char[rowscounter][colscounter];
					while(PinValue==0){
				     DIO_GetPinValue(KPD_ROWS_PORT,rowsPins[rowscounter],&PinValue);
					}
					PinFlag=1;
					break;
				}	
			}
			//Deactive counter col
			DIO_SetPinValue(KPD_COLS_PORT,coloumnsPins[colscounter],DIO_PIN_HIGH);
			if(PinFlag==1){
				break;
			}
		}
	}
}

void KPD_ACTIVE(void){
	
DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);
	
DIO_SetInputPinResistance(KPD_ROWS_PORT,KPD_ROW0_PIN);
DIO_SetInputPinResistance(KPD_ROWS_PORT,KPD_ROW1_PIN);
DIO_SetInputPinResistance(KPD_ROWS_PORT,KPD_ROW2_PIN);
DIO_SetInputPinResistance(KPD_ROWS_PORT,KPD_ROW3_PIN);
}	
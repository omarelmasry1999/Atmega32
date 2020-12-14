/*
 * UART.h
 *
 * Created: 7/17/2020 7:51:08 PM
 *  Author: Omar el Masry
 */ 


#ifndef UART_H_
#define UART_H_
#include "../HWregister/registers.h"
#include "UART_Config.h"
#define F_UART	 1000000
/*Function to Init UART take 3 parameters speed mode , and syncmode, baudrate*/
void UART_Init(UART_SpeedMode speedmode ,UART_SyncMode syncmode,uint32 baudrate);
//Function to send data via uart 
void UART_Transmit(uint8 data);
//function to receive data via uart 
uint8 UART_receive(void);
//function to receive data via uart
 char* UART_receiveString(void);
//Function to send data via uart 
void UART_TransmitString(char*data);
#endif /* UART_H_ */

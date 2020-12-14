/*
 * SPI.h
 *
 * Created: 7/28/2020 9:18:28 PM
 *  Author: Omar el Masry
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "SPI_Config.h"
#include "../HWregister/registers.h"
/*Function To Init SPI , Take SPI Mode and Clock Rate , Speed*/
void SPI_Init(SPI_Mode mode,Clock_Rate rate,Speed speed);
/*Function To Send data via SPI */
void SPI_Send(uint8 data);
void SPI_SendString(uint8*data);
//Function to receive data
uint8 SPI_Receive(void);
uint8* SPI_ReceiveString(void);




#endif /* SPI_H_ */

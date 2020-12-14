/*
 * SPI.c
 *
 * Created: 7/28/2020 9:18:06 PM
 *  Author: Omar el Masry
 */ 
#include "SPI.h"
#include "../GPIO/GPIO.h"
#include <util/delay.h>
uint8 str_SPI[100];
void SPI_Init(SPI_Mode mode,Clock_Rate rate,Speed speed)
{
	/*SPI_ControlRegister |=(1<<SPE);
	if(mode==Master)
	{
		
		GPIO_Init(B,5,Output);
		GPIO_Init(B,7,Output);
		GPIO_Init(B,4,Output);
		SPI_ControlRegister |=(1<<MSTR);
		if (speed==Double)
		{
			SPI_StatusRegister |=(1<<SPI2X);
		}
		switch(rate)
		{
			case Freq_4:
				SPI_ControlRegister &=~(1<<SPR0);
				SPI_ControlRegister &=~(1<<SPR1);
				break;
			case Freq_16:
				SPI_ControlRegister |=(1<<SPR0);
				SPI_ControlRegister &=~(1<<SPR1);
				break;
			case Freq_64:
				SPI_ControlRegister &=~(1<<SPR0);
				SPI_ControlRegister |=(1<<SPR1);
				break;
			case Freq_128:
				SPI_ControlRegister |=(1<<SPR0);
				SPI_ControlRegister |=(1<<SPR1);
				break;	
		}
	}
	if(mode==Slave)
	{
		
		GPIO_Init(B,6,Output);
		SPI_ControlRegister &=~(1<<MSTR);
	}
*/
		GPIO_Init(B,5,Output);
		GPIO_Init(B,7,Output);
		GPIO_Init(B,4,Output);
		GPIO_Write(B,4,HIGH);
		SPI_ControlRegister = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_Send(uint8 data)
{
	/* Start transmission */
	SPI_DataRegister = data;
	GPIO_Write(B,4,LOW);
	/* Wait for transmission complete */
	while(!(SPI_StatusRegister & (1<<SPIF)))
	;
	GPIO_Write(B,4,HIGH);
}
uint8 SPI_Receive(void)
{
	/* Wait for reception complete */
	while(!(SPI_StatusRegister & (1<<SPIF)))
	;
	/* Return data register */
	return SPI_DataRegister;
}
void SPI_SendString(uint8*ptrtodata)
{
uint8 j=0;
while (ptrtodata[j]!='\0')
{
	SPI_Send(ptrtodata[j]);
	j++;
	GPIO_Write(C,4,LOW);
	_delay_ms(500);
	GPIO_Write(C,4,HIGH);
	_delay_ms(500);
}	
ptrtodata[j]='\0';
SPI_Send(ptrtodata[j]);

}
uint8* SPI_ReceiveString(void)
{
	uint8 i=0;
	str_SPI[i]=SPI_Receive();
	while(str_SPI[i]!='\r')
	{
		i++;
		str_SPI[i]=SPI_Receive();
	}
	str_SPI[i]='\0';
	return str_SPI;
}

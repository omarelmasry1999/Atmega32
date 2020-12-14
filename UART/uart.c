/*
 * UART.c
 *
 * Created: 7/17/2020 11:09:35 PM
 *  Author: Omar el Masry
 */ 
#include "UART.h"
static uint8 str[100];
#include "../../ECUAL/LED/LED.h"
void UART_Init(UART_SpeedMode speedmode ,UART_SyncMode syncmode,unsigned long baudrate)
{
	unsigned long buadrate_val=0;
	
	
	//UART_ControlRegisterA |=(1<<U2X);
	//baud rate select
	
	if ((syncmode==Async)&&(speedmode==Normal_Speed))
	{
		buadrate_val=(unsigned long)((F_UART/(16*baudrate))-1);
	}
	else if ((syncmode==Async)&&(speedmode==Double_Speed))
	{
		buadrate_val=(unsigned long)((F_UART/(8*baudrate))-1);
	}
	else if (syncmode==	Sync)
	{
		buadrate_val = (unsigned long)((F_UART/(2*baudrate))-1) ;
	}
	BaudRateRegisterH =(uint8)(buadrate_val >> 8);
	BaudRateRegisterL= (uint8) (buadrate_val);
	UART_ControlRegisterA |=(1<<U2X);
	//enable receive and transmit
	UART_ControlRegisterB |=(1<<RXEN)|(1<<TXEN);
	
	//8 bit mode 
	UART_ControlRegisterC |=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UART_ControlRegisterB &=~(1<<UCSZ2);
	//UART_ControlRegisterC |=(1<<URSEL)|;
	
	//odd parity mode
	UART_ControlRegisterC &=~(1<<UPM0)|(1<<URSEL);
	UART_ControlRegisterC &=~(1<<UPM1)|(1<<URSEL);
	//1 STOP bits 
	UART_ControlRegisterC &=~(1<<USBS)|(1<<URSEL);
}
void UART_Transmit(uint8 data)
{
	while (!( UART_ControlRegisterA & (1 << UDRE)))
		;
	 UART_ControlRegisterA|=(1<<UDRE)	;
	UART_DataRegister=data;
} 
uint8 UART_receive(void)
{

	while(!(UART_ControlRegisterA & (1<<RXC)));
	 return UART_DataRegister;
}
 char* UART_receiveString()
{
	uint8 i=0;
	str[i]=UART_receive();
	while(str[i]!='\r')
	{
		i++;
		str[i]=UART_receive();
	}
	str[i]='\0';
	return str;
}
void UART_TransmitString(char*ldata)
{
	uint8 j=0;
	while (ldata[j]!='\0')
	{
		UART_Transmit(ldata[j]);
		j++;
	}
	ldata[j]='\0';
	UART_Transmit(ldata[j]);
}

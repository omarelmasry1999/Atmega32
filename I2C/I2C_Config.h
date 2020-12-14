/*
 * I2C_Config.h
 *
 * Created: 8/9/2020 12:30:16 PM
 *  Author: Omar el Masry
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

//TWI Control register
#define TWINT	7			//TWI Interrupt Flag
#define TWEA	6			//TWI Enable Ack Bit
#define TWSTA	5			//TWI Start Condition bit 
#define	TWSTO	4			//TWI STOP Condition Bit
#define	TWWC	3			//TWI Write Collision Flag
#define TWEN	2			//TWI Enable Bit
#define TWIE	0			//TWI Interrupt enable
//TWI Status Register
#define TWPS0	0			//TWI Prescale bit 0
#define TWPS1	1			//TWI Prescale bit 1
//




#endif /* I2C_CONFIG_H_ */

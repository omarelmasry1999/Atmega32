/*
 * I2C.h
 *
 * Created: 8/9/2020 12:25:28 PM
 *  Author: Omar el MASRY 
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "../HWregisters/registers.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWEN  2
#define TWPS0 0
#define TWPS1 1


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void I2C_init(void);
void I2C_start(void);
void I2c_stop(void);
void I2C_write_address(uint8 address);
void I2C_write_data(uint8 data);
uint8 I2C_read_address_with_ack(void); //read with send Ack
uint8 I2C_read_address_with_nack(void); //read without send Ack
uint8 I2C_read_data_with_ack(void); //read with send Ack
uint8 I2C_read_data_with_nack(void); //read without send Ack
uint8 I2C_getstatus(void);

#endif /* I2C_H_ */

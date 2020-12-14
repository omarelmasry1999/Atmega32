/*
 * GPIO.h
 *
 * Created: 6/5/2020 10:17:02 PM
 *  Author: Omar el Masry
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "../Registers/registers.h"

/*Function to Set GPIO PIN Into OUTPUT/INPUT Modes Takes three parameters Pin's Port , Pin's Number and Pin's Mode,And return Error State if there are Error happened or No Error happened*/
uint8 GPIO_Init(uint8 Port,uint8 Pin,Direction_State direction_state);

/*Function to Set GPIO PIN Into HIGH/LOW Mode Takes three parameters Pin's Port , Pin's Number and Pin's Mode,And return Error State if there are Error happened or No Error happened*/
uint8 GPIO_Write(uint8 Port,uint8 Pin,Logic_State logical_state);

/*Function to Read GPIO Pin Value Takes Two parameters Pin's Port and Pin's Number, And return Pin's Mode*/
uint8 GPIO_Read(uint8 Port,uint8 Pin,uint8*PtrToVal);


#endif /* GPIO_H_ */

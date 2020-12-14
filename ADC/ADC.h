/*
 * ADC.h
 *
 * Created: 8/28/2020 11:19:49 PM
 *  Author: Omar el Masry
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "ADC_Config.h"


void ADC_Init();
uint16 ADC_read(uint8 num_pin);


#endif /* ADC_H_ */

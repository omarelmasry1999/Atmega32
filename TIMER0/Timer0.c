/*
 * timer0.c
 *
 *  Created on: 12/6/2020
 *      Author: Omar Gamal
 */
#include "timer0.h"

void TIMER0_INIT(uint8_t option)
{
	switch (option)
	{
	case NORMAL:
		 TCCR0&=~(1<<WGM00);
		 TCCR0&=~(1<<WGM01);
		 break;
	case PWM_PHASE_CORRECT:
		 TCCR0|=(1<<WGM00);
         TCCR0&=~(1<<WGM01);
         break;
	case CTC:
		 TCCR0&=~(1<<WGM00);
		 TCCR0|=(1<<WGM01);
		 break;
	case FAST_PWM:
		 TCCR0|=(1<<WGM00);
		 TCCR0|=(1<<WGM01);
		 break;
	}
}
void TIMER0_START (uint8_t prescaler)
{
	switch (prescaler)
	{
	case NO_PRESCALER:
		 TCCR0|=(1<<CS00);
		 TCCR0&=~(1<<CS01);
		 TCCR0&=~(1<<CS02);
		 break;
	case  PRESCALER_8:
		 TCCR0&=~(1<<CS00);
	     TCCR0|=(1<<CS01);
		 TCCR0&=~(1<<CS02);
         break;
	case PRESCALER_64:
		 TCCR0|=(1<<CS00);
	     TCCR0|=(1<<CS01);
		 TCCR0&=~(1<<CS02);
		 break;
	case PRESCALER_256:
		 TCCR0&=~(1<<CS00);
	     TCCR0&=~(1<<CS01);
		 TCCR0|=(1<<CS02);
		 break;
	case PRESCALER_1024:
	     TCCR0|=(1<<CS00);
		 TCCR0&=~(1<<CS01);
	     TCCR0|=(1<<CS02);
	     break;
	case  EXTERNAL_CLOCK_ON_FALLING_EDGE:
		  TCCR0&=~(1<<CS00);
		  TCCR0|=(1<<CS01);
		  TCCR0|=(1<<CS02);
		  break;
	case  EXTERNAL_CLOCK_ON_RISING_EDGE:
		  TCCR0|=(1<<CS00);
		  TCCR0|=(1<<CS01);
		  TCCR0|=(1<<CS02);
		  break;
	}

}
void TIMER0_STOP ()
{
	 TCCR0&=~(1<<CS00);
	 TCCR0&=~(1<<CS01);
     TCCR0&=~(1<<CS02);
}

void TIMER0_Get_State (unsigned short* tick)
{
	if(TIFR&(1<<TOV0))
	{
		(*tick)++;
		TIFR&=~(1<<TOV0);
	}
}

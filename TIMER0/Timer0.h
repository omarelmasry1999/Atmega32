/*
 * timer0.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Almtgr
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_
#include "../DIO/dio.h"
#define NORMAL 0  // Timer0 normal mode //
#define PWM_PHASE_CORRECT 1  // Timer0 PWM phase correct mode //
#define CTC 2     // Timer0 compare mode //
#define FAST_PWM 3    // Timer0 fast PWM mode //
// TCCR0 PINS//
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOc0  7
// TIMSK PINS OF TIMER0//
#define TOIE0 0
#define OCIE0 1
// TIFR PINS OF TIMER0//
#define TOV0 0
#define OCF0 1
// TIMER0 PRESCALER //
#define NO_PRESCALER 0
#define PRESCALER_8  1
#define PRESCALER_64 2
#define PRESCALER_256  3
#define PRESCALER_1024 4
#define EXTERNAL_CLOCK_ON_FALLING_EDGE 5
#define EXTERNAL_CLOCK_ON_RISING_EDGE 6
//************* Timer0 functions prototype **********//
void TIMER0_INIT(uint8_t option);
void TIMER0_START (uint8_t prescaler);
void TIMER0_STOP ();
void TIMER0_Get_State (unsigned short* tick);

#endif /* MCAL_TIMER0_TIMER0_H_ */

/*
 * Config.h
 *
 * Created: 6/5/2020 10:22:03 PM
 *  Author: Omar el Masry
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

/*Data Types*/
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;


/*Error States*/
typedef enum Error_State
{
	Error_happened,
	No_Error
}Error_State;

/*Logic States*/
typedef enum Logic_State
{
	LOW,
	HIGH
}Logic_State;

/*Direction States*/
typedef enum Direction_State
{
	Input,
	Output
}Direction_State;



#define no_of_pins_on_port 8






#endif /* CONFIG_H_ */

/*
 * GPIO.c
 *
 * Created: 6/5/2020 10:16:44 PM
 *  Author: Omar el Masry
 */

 #include "GPIO.h"
 /*Function to Set GPIO PIN Into OUTPUT/INPUT Modes Takes three parameters Pin's Port , Pin's Number and Pin's Mode,And return Error State if there are Error happened or No Error happened*/
 uint8 GPIO_Init(uint8 Port,uint8 Pin,Direction_State direction_state)
 {
	 if (direction_state==Output)
	 {
		 *((volatile uint8*)(Port+Direction_Offset)) |= (1<<Pin);
		 return No_Error ;
	 }
	 else if (direction_state==Input)
	 {
		 *((volatile uint8*)(Port+Direction_Offset)) &= ~(1<<Pin);
		 return No_Error ;
	 }
	 else
	 {
		 return Error_happened ;
	 }
 }
 
 /*Function to Set GPIO PIN Into HIGH/LOW Mode Takes three parameters Pin's Port , Pin's Number and Pin's Mode,And return Error State if there are Error happened or No Error happened*/
 uint8 GPIO_Write(uint8 Port,uint8 Pin,Logic_State logical_state)
 {
	  uint8 API_Status ;
	  if(Pin < no_of_pins_on_port - 1)
	  {
		  if (logical_state==HIGH)
			{
				*((volatile uint8*)(Port+Output_Offset)) |= (1<<Pin);
				API_Status= No_Error ;
			}
		  else if (logical_state==LOW)
			{
				*((volatile uint8*)(Port+Output_Offset)) &= ~(1<<Pin);
				API_Status= No_Error ;
			}
		 else
			{
				API_Status= Error_happened ;
			}
	  }
	  else
	  {
		  API_Status= Error_happened ;
	  }
	  return API_Status;
		  
 }

 
 /*Function to Read GPIO Pin Value Takes Two parameters Pin's Port and Pin's Number, And return Pin's Mode*/
 uint8 GPIO_Read(uint8 Port,uint8 Pin,uint8*PtrToVal)
 { 
	uint8 API_Status ;

	if(Pin > no_of_pins_on_port - 1)
	{
		API_Status = Error_happened;
	}
	else
	{

		*PtrToVal =  ((*((volatile uint8*)(Port+Input_Offset))>>Pin)&1);
		API_Status = No_Error;
	}

	return API_Status ;

 }


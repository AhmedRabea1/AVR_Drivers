/*
 * SevSegment_prog.c
 *
 * Created: 3/6/2024 12:32:56 PM
 *  Author: Ahmed Rabea
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SevSegment_interface.h"
#include "SevSegment_config.h"


void SevSegment_voidInit(void)

{
	#if SEVEN_SEG_MODE == FOUR_BIT_MODE
	DIO_voidSetPinDirection(SEVEN_SEG_PORT,PIN_A,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEG_PORT,PIN_B,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEG_PORT,PIN_C,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEG_PORT,PIN_D,DIO_PIN_OUTPUT);
	#elif SEVEN_SEG_MODE == SEVEN_BIT_MODE
	DIO_voidSetPortDirection(SEVEN_SEG_PORT,DIO_PORT_OUTPUT);
	#endif
}
void SevSegment_voidPrint(u8 copy_u8Number)
{
	if(SEVEN_SEG_MODE == FOUR_BIT_MODE)
	{
		
	
	switch (copy_u8Number)
	{
		case 0:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_LOW);
		break;
		
		case 1:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_HIGH);
		break;
		
		case 2:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_LOW);
		break;
		
		case 3:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_HIGH);
		break;
		
		case 4:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_LOW);
		break;
		
		case 5:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_HIGH);
		break;
		
		case 6:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_LOW);
		break;
		
		case 7:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_HIGH);
		break;
		
		case 8:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_LOW);
		break;
		
		case 9:
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_A,DIO_PIN_HIGH);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_B,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_C,DIO_PIN_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_PORT,PIN_D,DIO_PIN_HIGH);
		break;
	}
	}
	else if( SEVEN_SEG_MODE==SEVEN_BIT_MODE)
	{
	#if SEVEN_SEG_TYPE == CATHODE
	switch(copy_u8Number)
	{
		case 1:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,ONE_CATHODE);
		break;
		
		case 2:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,TWO_CATHODE);
		break;
		
		case 3:
		
		DIO_voidSetPortValue(SEVEN_SEG_PORT,THREE_CATHODE);
		break;
		
		case 4:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,FOUR_CATHODE);
		break;
		
		case 5:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,FIVE_CATHODE);
		break;
		
		case 6:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,SIX_CATHODE);
		break;
		
		case 7:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,SVN_CATHODE);
		break;
		
		case 8:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,EIGHT_CATHODE);
		break;
		
		case 9:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,NINE_CATHODE);
		break;
	}
	#elif SEVEN_SEG_TYPE == ANODE
	switch(copy_u8Number)
	{
		case 1:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,ONE_ANODE);
		break;
		
		case 2:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,TWO_ANODE);
		break;
		
		case 3:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,THREE_ANODE);
		break;
		
		case 4:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,FOUR_ANODE);
		break;
		
		case 5:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,FIVE_ANODE);
		break;
		
		case 6:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,SIX_ANODE);
		break;
		
		case 7:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,SVN_ANODE);
		break;
		
		case 8:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,EIGHT_ANODE);
		break;
		
		case 9:
		DIO_voidSetPortValue(SEVEN_SEG_PORT,NINE_ANODE);
		break;
	}
	#endif
	}
}

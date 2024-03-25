/*
 * PWM_Prog.c
 *
 * Created: 3/17/2024 10:46:42 AM
 *  Author: Ahmed Rabea
 */ 

#include "../../../LIB/std_types.h"
#include "../../../LIB/bit_math.h"

#include "PWM_interface.h"
#include "PWM_config.h"
#include "PWM_private.h"
#include "PWM_register.h"


void PWM_voidInitChannel_0						(void)
{
	#if CHANNEL0_MODE == CHANNEL0_FAST_PWM_MODE
	//Select Mode = Fast PWM MOde
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	#elif CHANNEL0_MODE == CHANNEL0_PHASE_CORRECT_MODE
	SET_BIT(TCCR0_REG,WGM00);
	CLEAR_BIT(TCCR0_REG,WGM01);
	#endif
	#if CHANNEL0_PWM_MODE == CHANNEL0_NON_INVERTING_MODE
	//Fast PWM Mode --> Non Inverting
	CLEAR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#elif CHANNEL0_PWM_MODE == CHANNEL0_INVERTING_MODE
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#endif
}
void PWM_voidGenerate_PWM_Channel_0				(u8 copy_u8DutyCycle)
{
	//Check Duty cycle Smaller than or equal 100%
	if(copy_u8DutyCycle <= MAXIMUM_DUTY_CYCLES)
	{
		#if CHANNEL0_MODE == CHANNEL0_FAST_PWM_MODE
			#if CHANNEL0_PWM_MODE == CHANNEL0_NON_INVERTING_MODE
				//SET DUTY RATIO
				OCR0_REG = (((u16)copy_u8DutyCycle * 256) / 100) - 1;
			#elif CHANNEL0_PWM_MODE == CHANNEL0_INVERTING_MODE
				OCR0_REG = (255 - ((u16)(copy_u8DutyCycle * 256))/100);
			#endif
		#elif CHANNEL0_MODE == CHANNEL0_PHASE_CORRECT_MODE
			#if CHANNEL0_PWM_MODE ==  CHANNEL0_NON_INVERTING_MODE
			//SET DUTY RATIO
				OCR0_REG = ((255 * (u16)copy_u8DutyCycle)/100) - 1;
			#elif CHANNEL0_PWM_MODE == CHANNEL0_INVERTING_MODE
				OCR0_REG = 254 - ((255 * (u16)copy_u8DutyCycle))/100);
			#endif
		#endif
			
		//PRESCALER
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	}
	else
	{
		//ERROR STATE
	}
}

void PWM_voidInitChannel_1A						(void)
{
	//Select Mode --> Fast PWM --> Mode 14
	CLEAR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);
	
	//Non Inverting
	CLEAR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
}
void PWM_voidGenerate_PWM_Channel_1A			(u32 copy_u32Frequency_hz, f32 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle <= MAXIMUM_DUTY_CYCLES)
	{
		//Set Frequency Under condition tick time = 4 micro second
		ICR1_DATA_REG = ((1000000/copy_u32Frequency_hz)/ 4)	- 1;
		
		//Set Duty Cycle
		OCR1A_DATA_REG = ((copy_u8DutyCycle * (ICR1_DATA_REG +1)) / 100) - 1;
		
		//Set Prescaler 64
		SET_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLEAR_BIT(TCCR1B_REG,CS12);
	}
	else
	{
		//Error State
	}
}
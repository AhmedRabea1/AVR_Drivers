/*
 * Timer1_prog.c
 *
 * Created: 3/17/2024 9:04:31 AM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "Timer1_interface.h"
#include "Timer1_config.h"
#include "Timer1_private.h"
#include "Timer1_register.h"

void (*PRV_pFunCallBackOVF) (void) = NULL;
void (*PRV_pFunCallBackCTC) (void) = NULL;

void Timer1_voidInit(void)
{
	#if TIMER1_MODE == TIMER1_NORMAL_MODE
	CLEAR_BIT(TCCR1A_REG,WGM10);
	CLEAR_BIT(TCCR1A_REG,WGM11);
	CLEAR_BIT(TCCR1B_REG,WGM12);
	CLEAR_BIT(TCCR1B_REG,WGM13);
	
	//SET PRELOAD VALUE
	TCNT1_DATA_REG = TIMER1_PRELOAD_VALUE;
	
	// ENABLE OVF INTERRUPT
	SET_BIT(TIMSK_REG,TOIE1);
	
	#elif TIMER1_MODE == TIMER1_CTC_MODE
	CLEAR_BIT(TCCR1A_REG,WGM10);
	CLEAR_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	CLEAR_BIT(TCCR1B_REG,WGM13);	
	
	//SET COMPARE VALUE
	OCR1A_DATA_REG = TIMER1_COMPARE_VALUE;
	
	//ENABLE CTC INTERRUPT
	SET_BIT(TIMSK_REG,OCIE1A);
	#endif
}
void Timer1_voidStart(void)
{
	#if CLOCK_SELECT == NO_PRESCALING
	SET_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
	#elif CLOCK_SELECT == PRESCALER_8
	CLEAR_BIT(TCCR1B_REG,CS10);
	SET_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
	#elif CLOCK_SELECT == PRESCALER_64
	SET_BIT(TCCR1B_REG,CS10);
	SET_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
	#elif CLOCK_SELECT == PRESCALER_256
	CLEAR_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
	#elif CLOCK_SELECT == PRESCALER_1024
	SET_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
	#endif
}
void Timer1_voidStop(void)
{
	CLEAR_BIT(TCCR1B_REG,CS10);
	CLEAR_BIT(TCCR1B_REG,CS11);
	CLEAR_BIT(TCCR1B_REG,CS12);
}
void Timer1_voidSetCallBack(void (*copy_pFunAction) (void), u8 copy_u8InterruptSource)
{
	if(copy_pFunAction != NULL)
	{
		switch (copy_u8InterruptSource)
		{
			case TIMER1_NORMAL_OVER_FLOW_INTERRUPT_SOURCE:
			PRV_pFunCallBackOVF = copy_pFunAction;
			break;
			case TIMER1_CTC_COMPARE_MATCH_INTERRUPT_SOURCE:
			PRV_pFunCallBackCTC = copy_pFunAction;
			break;
		}
	}
	else
	{
		//Return Error State
	}
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	if(TIMER1_OVERFLOW_COUNTER == local_u16OVFCounter)
	{
		//SET PRELOAD VALUE AGAIN
		TCNT1_DATA_REG = TIMER1_PRELOAD_VALUE;
		
		local_u16OVFCounter = 0;
		
		//Call action
		
		if(PRV_pFunCallBackOVF != NULL)
		{
			PRV_pFunCallBackOVF();
		}
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u16 local_u16ctcCounter = 0;
	local_u16ctcCounter++;
	if(TIMER1_OUTPUT_COMPARE_VALUE == local_u16ctcCounter)
	{
		local_u16ctcCounter = 0;
		
		//Call Action
		if(PRV_pFunCallBackCTC != NULL)
		{
			PRV_pFunCallBackCTC();
		}
	}
}
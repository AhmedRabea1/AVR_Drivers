/*
 * TMRO_prog.c
 *
 * Created: 3/16/2024 10:29:57 AM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "TMR0_interface.h"
#include "TMR0_conig.h"
#include "TMR0_private.h"
#include "TMR0_register.h"

static void (*PRV_pFunCallBackOVF) (void) = NULL;
static void (*PRV_pFunCallBackCTC) (void) = NULL;
static u16 PRV_ctcCounter;

void TMR0_voidInit(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	//MODE = NORMAL MODE
	CLEAR_BIT(TCCR0_REG, WGM00);
	CLEAR_BIT(TCCR0_REG, WGM01);
	
	//Pre load Value
	TCNT0_REG = TMR0_PRELOAD_VALUE;
	
	//Enable OVF Interrupt Enable
	SET_BIT(TIMSK_REG,TOIE0);
	
#elif TMR0_MODE == TMR0_CTC_MODE
	//MODE = CTC MODE
	CLEAR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	
	// ASSIGN COMPARE VALUE TO OCR0
	OCR0_REG = TMR0_COMPARE_VALUE;
	
	SET_BIT(TIMSK_REG,OCIE0);
#endif
}
void TMR0_voidStart(void)
{
	#if CLOCK_SELECT == NO_PRESCALING
		SET_BIT(TCCR0_REG,CS00);
		CLEAR_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	#elif CLOCK_SELECT == PRESCALER_8
		CLEAR_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	#elif CLOCK_SELECT == PRESCALER_64
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
	#elif CLOCK_SELECT == PRESCALER_256
		CLEAR_BIT(TCCR0_REG,CS00);
		CLEAR_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS02);
	#elif CLOCK_SELECT == PRESCALER_1024
		SET_BIT(TCCR0_REG,CS00);
		CLEAR_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS02);
	#endif
}
void TMR0_voidStop(void)
{
	CLEAR_BIT(TCCR0_REG,CS00);
	CLEAR_BIT(TCCR0_REG,CS01);
	CLEAR_BIT(TCCR0_REG,CS02);
}

void TMR0_voidSetCallBack(void (*copy_pFunAction) (void) , u8 copy_u8InterruptSource)
{
	if(copy_pFunAction != NULL)
	{
	switch(copy_u8InterruptSource)
	{
		case TMR0_NORMAL_OVER_FLOW:
		PRV_pFunCallBackOVF = copy_pFunAction;
		break;
		case TMR0_CTC_COMPARE_MATCH:
		PRV_pFunCallBackCTC = copy_pFunAction;
		break;
	}
	}
	else
	{
		//Error State
	}
}
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms)
{
	// Under condition 4 microsecond
	#if CLOCK_SELECT == PRESCALER_8
	OCR0_REG = 199;
	PRV_ctcCounter = copy_u16Delay_ms / 100;
	#elif CLOCK_SELECT == PRESCALER_64
	OCR0_REG = 249;
	PRV_ctcCounter = copy_u16Delay_ms;
	#elif CLOCK_SELECT == PRESCALER_256
	OCR0_REG = 249;
	PRV_ctcCounter = copy_u16Delay_ms / 4000;
	#elif CLOCK_SELECT == PRESCALER_1024
	OCR0_REG = 249;
	PRV_ctcCounter = copy_u16Delay_ms / 16000;
	#endif
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	
	if(TMR0_OVER_FLOW_COUNTER == local_u16OVFCounter)
	{
		//Init Timer With Preload Value
		TCNT0_REG = TMR0_PRELOAD_VALUE;
		
		//Clear Counter	
		local_u16OVFCounter = 0;
		
		// Call Action
		if(PRV_pFunCallBackOVF != NULL)
		{
			PRV_pFunCallBackOVF();
		}
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16ctcCounter = 0;
	local_u16ctcCounter++;
	if (PRV_ctcCounter == local_u16ctcCounter)
	{
		local_u16ctcCounter = 0;
		
		PRV_pFunCallBackCTC();
		
	}
}
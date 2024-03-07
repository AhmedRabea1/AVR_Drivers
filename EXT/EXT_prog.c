/*
 * EXT_prog.c
 *
 * Created: 3/3/2024 1:01:12 PM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "EXT_interface.h"
#include "Ext_private.h"

void EXT_voidSetCallBackINT1(void (*copy_pFunAction) (void));
void (*Pri_copy) (void);

void EXT_voidEnable(EXT_source copy_enumInterruptSource, EXT_senseControl copy_enumSenseControl)
{
	switch(copy_enumInterruptSource)
	{
		case EXT_INT0:
		switch(copy_enumSenseControl)
		{
			case EXT_RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case EXT_FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case EXT_LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case EXT_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		}
		SET_BIT(GICR,INT0);
		break;
		case EXT_INT1:
			switch(copy_enumSenseControl)
			{
				case EXT_RISING_EDGE:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				case EXT_FALLING_EDGE:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				case EXT_LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
				case EXT_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
			}
			SET_BIT(GICR,INT1);
			break;
		case EXT_INT2:
			switch(copy_enumSenseControl)
			{
				case EXT_RISING_EDGE:
				SET_BIT(MCUCSR,ISC2);
				break;
				case EXT_FALLING_EDGE:
				CLEAR_BIT(MCUCSR,ISC2);
				break;
			}
			SET_BIT(GICR,INT2);
			break;
	}
}
void EXT_voidDisable(EXT_source copy_enumInterruptSource)
{
	//SWITCH ON SOURCE
	switch(copy_enumInterruptSource)
	{
		case EXT_INT0:
		CLEAR_BIT(GICR,INT0);
		break;
		case EXT_INT1:
		CLEAR_BIT(GICR,INT1);
		break;
		case EXT_INT2:
		CLEAR_BIT(GICR,INT2);
		break;
	}

}
/*This Function used to communicate with the upper layer [Call back]
Inputs : Pointer to func that points to the fn in the ISR
Return : void
*/
void EXT_voidSetCallBackINT1(void (*copy_pFunAction) (void))
{
	if(copy_pFunAction!=NULL)
	{
			Pri_copy = copy_pFunAction;
	}
	else
	{
		
	}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	Pri_copy();
}
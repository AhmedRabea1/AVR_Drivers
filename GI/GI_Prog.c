/*
 * GI_Prog.c
 *
 * Created: 3/3/2024 1:06:40 PM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "GI_inteface.h"
#include "GI_private.h"
#include "../../LIB/bit_math.h"
void GI_voidEnable(void)
{
	SET_BIT(SREG,I);
}
void GI_voidDisable(void)
{
	CLEAR_BIT(SREG,I);
}
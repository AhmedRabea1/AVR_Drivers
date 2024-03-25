/*
 * GI_Prog.c
 *
 * Created: 3/3/2024 1:06:40 PM
 *  Author: Ahmed Rabea
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "GI_inteface.h"
#include "GI_private.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG,I);
}
void GI_voidDisable(void)
{
	CLEAR_BIT(SREG,I);
}
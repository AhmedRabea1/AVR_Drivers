/*
 * WTD_config.c
 *
 * Created: 3/19/2024 10:19:29 AM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "WTD_interface.h"
#include "WTD_register.h"

void WTD_voidEnable			(u8 copy_u8Time)
{
	switch(copy_u8Time)
	{
		case WDT_TIME_16_3_MS:
		CLEAR_BIT(WDTCR_REG,WDP0);
		CLEAR_BIT(WDTCR_REG,WDP1);
		CLEAR_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_32_5_MS:
		SET_BIT(WDTCR_REG,WDP0);
		CLEAR_BIT(WDTCR_REG,WDP1);
		CLEAR_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_65_MS:
		CLEAR_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		CLEAR_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_0_13_S:
		SET_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		CLEAR_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_0_26_S:
		CLEAR_BIT(WDTCR_REG,WDP0);
		CLEAR_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_0_52_S:
		SET_BIT(WDTCR_REG,WDP0);
		CLEAR_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_1_0_S:
		CLEAR_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
		case WDT_TIME_2_1_S:
		SET_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
	}
	SET_BIT(WDTCR_REG,WDE);
}
void WTD_voidDisable		(void)
{
	WDTCR_REG = (1<<WDTOE) | (1<<WDE);
	WDTCR_REG = 0; 
}
/*
 * WTD_interface.h
 *
 * Created: 3/19/2024 10:19:56 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef WTD_INTERFACE_H_
#define WTD_INTERFACE_H_

#define WDT_TIME_16_3_MS			1
#define WDT_TIME_32_5_MS			2
#define WDT_TIME_65_MS				3
#define WDT_TIME_0_13_S				4
#define WDT_TIME_0_26_S				5
#define WDT_TIME_0_52_S				6
#define WDT_TIME_1_0_S				7
#define WDT_TIME_2_1_S				8

void WTD_voidEnable			(u8 copy_u8Time);
void WTD_voidDisable		(void);




#endif /* WTD_INTERFACE_H_ */
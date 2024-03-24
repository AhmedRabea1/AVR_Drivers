/*
 * WTD_register.h
 *
 * Created: 3/19/2024 10:21:13 AM
 *  Author: lenovo
 */ 


#ifndef WTD_REGISTER_H_
#define WTD_REGISTER_H_

#define WDTCR_REG							  *(volatile u8 *) 0x41
#define	WDP0											0
#define WDP1											1
#define WDP2											2
#define WDE												3
#define WDTOE											4


#endif /* WTD_REGISTER_H_ */
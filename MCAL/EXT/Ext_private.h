/*
 * Ext_private.h
 *
 * Created: 3/3/2024 1:00:48 PM
 *  Author: Ahmed Rabea
 */ 


#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_

#define	MCUCR		*(volatile u8 *) 0x55
#define ISC11				3
#define ISC10				2
#define ISC01				1
#define ISC00				0

#define MCUCSR		*(volatile u8 *) 0x54
#define ISC2				6

#define GICR		*(volatile u8 *) 0x5B
#define INT2				5
#define INT0				6
#define INT1				7

#define GIFR		*(volatile u8 *) 0x5A
#define INFT2				5
#define INTF0				6
#define INTF1				7



#endif /* EXT_PRIVATE_H_ */
/*
 * DIO_REGISTERS.h
 *
 * Created: 3/9/2024 3:33:32 PM
 *  Author: lenovo
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#include "STD_TYPES.h"

/*AUTOSAR Module version 4.3.1*/
#define DIO_REGS_AR_RELEASE_MAJOR_VERSION					4U
#define DIO_REGS_AR_RELEASE_MINOR_VERSION					4U
#define DIO_REGS_AR_RELEASE_PATCH_VERSION					0U

/*Module version 1.0.0*/
#define DIO_REGS_SW_MAJOR_VERSION						1U
#define DIO_REGS_SW_MINOR_VERSION						0U
#define DIO_REGS_SW_PATCH_VERSION						0U

#if   ((DIO_REGS_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
|| (DIO_REGS_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
|| (DIO_REGS_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif

typedef struct
{
	const volatile uint8 PIN;
	volatile uint8 DDR;
	volatile uint8 PORT;
}REGSS_Struct;

#define DIO_PORTA 				((volatile REGSS_Struct*) 0x39)
#define DIO_PORTB 				((volatile REGSS_Struct*) 0x36)
#define DIO_PORTC 				((volatile REGSS_Struct*) 0x33)
#define DIO_PORTD 				((volatile REGSS_Struct*) 0x30)




#endif /* DIO_REGISTERS_H_ */
/*
 * EXT_interface.h
 *
 * Created: 3/3/2024 1:00:28 PM
 *  Author: Ahmed Rabea
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

typedef enum
{
	EXT_INT0=0,
	EXT_INT1,
	EXT_INT2
}EXT_source;


typedef enum
{
	EXT_RISING_EDGE=0,
	EXT_FALLING_EDGE,
	EXT_LOW_LEVEL,
	EXT_ANY_LOGICAL_CHANGE	
}EXT_senseControl;

void EXT_voidEnable(EXT_source copy_enumInterruptSource, EXT_senseControl copy_enumSenseControl);
void EXT_voidDisable(EXT_source copy_enumInterruptSource);
void EXT_voidSetCallBackINT1(void (*copy_pFunAction) (void));


#endif /* EXT_INTERFACE_H_ */
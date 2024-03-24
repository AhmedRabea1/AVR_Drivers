/*
 * Servo_prog.c
 *
 * Created: 3/18/2024 1:05:35 PM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

#include "Servo_interface.h"

void Servo_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	PWM_voidInitChannel_1A();
}
void Servo_voidStart(u32 copy_u8Angle)
{
	static f32 local_f32DutyCycle;
	
	local_f32DutyCycle=(((copy_u8Angle)/180.0)*5)+5;
	
	PWM_voidGenerate_PWM_Channel_1A(SERVO_FREQUENCY,local_f32DutyCycle);
}
void Servo_voidStop(void)
{
	PWM_voidStopChannel_1A();
}

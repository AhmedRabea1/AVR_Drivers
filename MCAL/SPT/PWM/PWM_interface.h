/*
 * PWM_interface.h
 *
 * Created: 3/17/2024 10:46:09 AM
 *  Author: lenovo
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

void PWM_voidInitChannel_0						(void);
void PWM_voidGenerate_PWM_Channel_0				(u8 copy_u8DutyCycle);

void PWM_voidInitChannel_1A						(void);
void PWM_voidGenerate_PWM_Channel_1A			(u32 copy_u32Frequency_hz, f32 copy_u8DutyCycle);

void PWM_voidInitChannel_2						(void);
void PWM_voidGenerate_PWM_Channel_2				(u8 copy_u8DutyCycle);




#endif /* PWM_INTERFACE_H_ */
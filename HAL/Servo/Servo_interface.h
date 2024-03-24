/*
 * Servo_interface.h
 *
 * Created: 3/18/2024 1:05:50 PM
 *  Author: lenovo
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define REFERENCE_ANGLE_0			-90
#define REFERENCE_ANGLE_1			90

#define REFERENCE_DUTY_0			5
#define REFERENCE_DUTY_1			10

#define SERVO_FREQUENCY				50

void Servo_voidInit(void);
void Servo_voidStart(u32 copy_u8Angle);
void Servo_voidStop(void);



#endif /* SERVO_INTERFACE_H_ */
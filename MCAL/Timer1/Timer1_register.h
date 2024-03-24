/*
 * Timer1_register.h
 *
 * Created: 3/17/2024 9:05:10 AM
 *  Author: lenovo
 */ 


#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

#define TCCR1A_REG									(*(volatile u8 *) 0x4F)
#define WGM10											0
#define WGM11											1
#define FOC1B											2
#define FOC1A											3
#define COM1B0											4
#define COM1B1											5
#define COM1A0											6
#define COM1A1											7


#define TCCR1B_REG									(*(volatile u8 *) 0x4E)
#define CS10											0
#define CS11											1
#define CS12											2
#define WGM12											3
#define WGM13											4
#define ICES1											6
#define ICNC1											7

#define TCNT1_DATA_REG								(*(volatile u16 *) 0x4C)

#define OCR1A_DATA_REG								(*(volatile u16 *) 0x4A)

#define OCR1B_DATA_REG								(*(volatile u16 *) 0x48)

#define ICR1_DATA_REG								(*(volatile u16 *) 0x46)

#define TIMSK_REG									(*(volatile u8 *) 0x59)
#define TOIE1											2
#define OCIE1B											3
#define OCIE1A											4
#define TICIE1											5

#define TIFR_REG									(*(volatile u8 *) 0x58)
#define TOV1											2
#define OCF1B											3
#define OCF1A											4
#define ICF1											5							

#endif /* TIMER1_REGISTER_H_ */
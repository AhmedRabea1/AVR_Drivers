/*
 * Timer1_interface.h
 *
 * Created: 3/17/2024 9:05:27 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define TIMER1_NORMAL_OVER_FLOW_INTERRUPT_SOURCE			1
#define TIMER1_CTC_COMPARE_MATCH_INTERRUPT_SOURCE			2

void Timer1_voidInit(void);
void Timer1_voidStart(void);
void Timer1_voidStop(void);
void Timer1_voidSetCallBack(void (*copy_pFunAction) (void), u8 copy_u8InterruptSource);



#endif /* TIMER1_INTERFACE_H_ */
/*
 * Timer1_config.h
 *
 * Created: 3/17/2024 9:05:44 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*Options for TMR0 Mode:
1- TMR0_NORMAL_MODE
2- TMR0_CTC_MODE
*/

#define TIMER1_MODE									TIMER1_CTC_MODE

/*Options for TMR0 Prescaler:
1- NO_PRESCALING
2- PRESCALER_8
3- PRESCALER_64
4- PRESCALER_256
5- PRESCALER_1024
*/
#define CLOCK_SELECT							PRESCALER_64

#define TIMER1_OVERFLOW_COUNTER						1954

#define TIMER1_OUTPUT_COMPARE_VALUE					1500						
#define TIMER1_PRELOAD_VALUE							224


#define TIMER1_COMPARE_VALUE							249


#endif /* TIMER1_CONFIG_H_ */
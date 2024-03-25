/*
 * TMR0_config.h
 *
 * Created: 3/16/2024 10:30:18 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/*Options for TMR0 Mode:
1- TMR0_NORMAL_MODE
2- TMR0_CTC_MODE
3- TMR0_PHASE_CORRECT_MODE
4- TMRO_FAST_PWM_MODE
*/
#define TMR0_MODE								TMR0_CTC_MODE			


/*Options for TMR0 Prescaler:
1- NO_PRESCALING
2- PRESCALER_8
3- PRESCALER_64
4- PRESCALER_256
5- PRESCALER_1024
*/
#define CLOCK_SELECT							PRESCALER_64										

#define TMR0_PRELOAD_VALUE						224
#define TMR0_OVER_FLOW_COUNTER					1954

#define TMR0_COMPARE_VALUE						249
#define TMR0_OUTPUT_COMPARE_VALUE				1500




#endif /* TMR0_CONFIG_H_ */
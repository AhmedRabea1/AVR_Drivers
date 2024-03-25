/*
 * TMR0_interface.h
 *
 * Created: 3/16/2024 10:31:25 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

										/*******************************APIS PROTOTYPES******************************/
#define TMR0_NORMAL_OVER_FLOW				1
#define TMR0_CTC_COMPARE_MATCH				2
			
void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
void TMR0_voidSetCallBack(void (*copy_pFunAction) (void) , u8 copy_u8InterruptSource);
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);

#endif /* TMR0_INTERFACE_H_ */
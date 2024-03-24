/*
 * UART_program.c
 *
 * Created: 3/22/2024 10:12:36 AM
 *  Author: lenovo
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include <string.h>

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"
u8 Prv_u8TransmitString[100];
u8 Prv_u8ReceiveString[100];
u8 Prv_u8TransmitIndex=0;
u8 Prv_u8ReceiveIndex=0;
bool Str_Received = FALSE;
u8 LED_ON = 1;

void UART_voidInit(u16 copy_u16BaudRate)
{
	/******/
	#if UART_BAUDRATE == UART_BAUDRATE_1200
	UBRRL_REG = UART_BAUDRATE_1200;
	#elif UART_BAUDRATE == UART_BAUDRATE_2400
	UBRRL_REG = UART_BAUDRATE_2400;
	#elif UART_BAUDRATE == UART_BAUDRATE_4800
	UBRRL_REG = UART_BAUDRATE_4800;
	#elif UART_BAUDRATE == UART_BAUDRATE_9600
	UBRRL_REG = UART_BAUDRATE_9600;
	#elif UART_BAUDRATE == UART_BAUDRATE_19200
	UBRRL_REG = UART_BAUDRATE_19200;
	#elif UART_BAUDRATE == UART_BAUDRATE_115200
	UBRRL_REG = UART_BAUDRATE_115200;
	#endif

	//RECEIVER ENABLE
	SET_BIT(UCSRB_REG,RXEN);
	//TRANSMITTER ENABLE
	SET_BIT(UCSRB_REG,TXEN);
	SET_BIT(UCSRC_REG,URSEL);
	//CLEAR_BIT(UCSRB_REG,UCSZ2);
	//SET_BIT(UCSRC_REG,UCSZ0);
	//SET_BIT(UCSRC_REG,UCSZ1);
	//FRAME SIZE
	
	#if UART_FRAME_SIZE == FIVE_BIT_CHARACTER_SIZE
		CLEAR_BIT(UCSRC_REG,UCSZ0);
		CLEAR_BIT(UCSRC_REG,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);
	#elif UART_FRAME_SIZE == SIX_BIT_CHARACTER_SIZE
		SET_BIT(UCSRC_REG,UCSZ0);
		CLEAR_BIT(UCSRC_REG,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);	
	#elif UART_FRAME_SIZE == SEVEN_BIT_CHARACTER_SIZE
		CLEAR_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
		CLEAR_BIT(UCSRB_REG,UCSZ2);	
	#elif UART_FRAME_SIZE == EIGHT_BIT_CHARACTER_SIZE
		CLEAR_BIT(UCSRB_REG,UCSZ2);
		SET_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
	#elif UART_FRAME_SIZE == NINE_BIT_CHARACTER_SIZE
		SET_BIT(UCSRB_REG,UCSZ2);
		SET_BIT(UCSRC_REG,UCSZ0);
		SET_BIT(UCSRC_REG,UCSZ1);
	#endif
	
	//Set PARITY Bit
	#if UART_PARITY_MODE == PARITY_DISABLED
		CLEAR_BIT(UCSRC_REG,UPM0);
		CLEAR_BIT(UCSRC_REG,UPM1);
	#elif UART_PARITY_MODE == EVEN_PARITY
		CLEAR_BIT(UCSRC_REG,UPM0);
		SET_BIT(UCSRC_REG,UPM1);
	#elif UART_PARITY_MODE == ODD_PARITY
		SET_BIT(UCSRC_REG,UPM0);
		SET_BIT(UCSRC_REG,UPM1);
	#endif
	
	//STOP BIT
	#if UART_STOP_BITS == ONE_STOP_BIT
		CLEAR_BIT(UCSRC_REG,USBS);
	#elif UART_STOP_BITS == TWO_STOP_BITS
		SET_BIT(UCSRC_REG,USBS);
	#endif
	
	//ASYNCHRONOUS MODE
	CLEAR_BIT(UCSRC_REG,UMSEL);
	
	//ENABLE TX AND RX
	SET_BIT(UCSRB_REG,RXCIE);
	SET_BIT(UCSRB_REG,TXCIE);
	
	
	
}
void UART_voidSendByte(u8 copy_u8Byte)
{
	while(0 == GET_BIT(UCSRA_REG,UDRE));
	
	UDR_REG = copy_u8Byte;
}
u8 UART_voidReceiveByte()
{
	u8 local_u8Result;
	while(0 == GET_BIT(UCSRA_REG,RXC));
	local_u8Result = UDR_REG;
	return local_u8Result;
}
void UART_voidSendString(u8 * copy_u8String)
{
	while(*copy_u8String != '\0')
	{
		UART_voidSendByte(*copy_u8String);
		copy_u8String++;
	}
}
void UART_voidSendByteInterrupt(u8 copy_u8Byte)
{
	UDR_REG = copy_u8Byte;
}
void UART_voidSendStringInterrupt(u8* copy_u8String)
{
	u8 local_u8Counter;
	for(local_u8Counter = 0; local_u8Counter < 100 ; local_u8Counter++)
	{
		Prv_u8TransmitString[local_u8Counter] = copy_u8String[local_u8Counter];
	}
	UART_voidSendByteInterrupt(Prv_u8TransmitString[Prv_u8TransmitIndex]);
}
u8 UART_voidReceiveByteInterrupt()
{
	return UDR_REG;
}
bool UART_strIsReceived(void)
{
	if(Str_Received == TRUE)
	{
		Str_Received = FALSE;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
u8 * UART_voidReceivedString()
{
	return (Prv_u8ReceiveString);	
}
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	Prv_u8ReceiveString[Prv_u8ReceiveIndex] = UART_voidReceiveByteInterrupt();
	
	if(Prv_u8ReceiveString[Prv_u8ReceiveIndex] == '\r')
	{
		Prv_u8ReceiveString[Prv_u8ReceiveIndex] = NULL;
		Prv_u8ReceiveIndex = 0;
		Str_Received = TRUE;
		if(strcmp(Prv_u8ReceiveString,"Ahmed") == 0)
		{
			LED_ON = 2;
		}
		else
		{
			LED_ON = 1;
		}
	}
	else
	{
		Prv_u8ReceiveIndex++;
	}
}
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	Prv_u8TransmitIndex++;
	
	if(Prv_u8TransmitString[Prv_u8TransmitIndex] != NULL)
	{
		UART_voidSendByteInterrupt(Prv_u8TransmitString[Prv_u8TransmitIndex]);
	}
	else
	{
		Prv_u8TransmitIndex = 0;
	}
}
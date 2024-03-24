/*
 * UART_interface.h
 *
 * Created: 3/22/2024 10:12:57 AM
 *  Author: lenovo
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



void UART_voidInit(u16 copy_u16BaudRate);
void UART_voidSendByte(u8 copy_u8Byte);
u8 UART_voidReceiveByte();
void UART_voidSendString(u8 * copy_u8String);
void UART_voidSendByteInterrupt(u8 copy_u8Byte);
void UART_voidSendStringInterrupt(u8* copy_u8String);
u8 UART_voidReceiveByteInterrupt();
bool UART_strIsReceived(void);
u8 * UART_voidReceivedString(void);


#endif /* UART_INTERFACE_H_ */
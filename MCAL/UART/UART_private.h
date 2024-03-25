/*
 * UART_private.h
 *
 * Created: 3/22/2024 10:59:59 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define FIVE_BIT_CHARACTER_SIZE					1
#define SIX_BIT_CHARACTER_SIZE					2
#define SEVEN_BIT_CHARACTER_SIZE				3
#define EIGHT_BIT_CHARACTER_SIZE				4
#define NINE_BIT_CHARACTER_SIZE					5

#define PARITY_DISABLED							1
#define EVEN_PARITY								2
#define ODD_PARITY								3

#define ONE_STOP_BIT							1
#define TWO_STOP_BITS							2

#define UART_BAUDRATE_1200						0x340
#define UART_BAUDRATE_2400						0x1A0
#define UART_BAUDRATE_4800						0xCF
#define UART_BAUDRATE_9600						0x67
#define UART_BAUDRATE_19200						0x51
#define UART_BAUDRATE_115200					0x8


#endif /* UART_PRIVATE_H_ */
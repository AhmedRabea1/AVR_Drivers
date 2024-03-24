/*
 * UART_register.h
 *
 * Created: 3/22/2024 10:13:21 AM
 *  Author: lenovo
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UCSRA_REG   *(((volatile u8 *)0x2B))  // control A
#define UCSRB_REG   *(((volatile u8 *)0x2A))  // control B
#define UCSRC_REG   *(((volatile u8 *)0x40))  // control C
#define UDR_REG     *(((volatile u8 *)0x2C))  // data register
#define UBRRH_REG   *(((volatile u8 *)0x40))  // BR high
#define UBRRL_REG   *(((volatile u8 *)0x29))   // BR low

//UCSRC_REG

#define URSEL     7  // register select
#define UMSEL     6  // UART mode select
#define UPM1      5  // parity bit
#define UPM0      4  // parity bit
#define USBS      3  // stop bit
#define UCSZ1     2  // msg size
#define UCSZ0     1  // msg size
#define UCPOL     0  // clock polarity in synchrounse mode

//UCSRA_REG

#define RXC    7   // RX complete flag
#define TXC     6   // TX complete flag
#define UDRE    5   // data register empty
#define FE      4   // frame error
#define DOR     3   // data overrun error
#define PE      2   // parity error
#define U2X     1   // double speed mode
#define MPCM    0

//UCSRB_REG

#define  RXCIE  7   // RX complete Interrupt Enable
#define  TXCIE  6   // Tx complete Interrupt Enable
#define  UDRIE  5   // data register empty Interrupt Enable
#define  RXEN   4   // Enable Rx
#define  TXEN   3   // Enable Tx
#define  UCSZ2  2   // msg size
#define  RXB8   1   // bit8 in 9 bit mode (Rx)
#define  TXB8   0   // bit8 in 9 bit mode (Tx)

#endif /* UART_REGISTER_H_ */
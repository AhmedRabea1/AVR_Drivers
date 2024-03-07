/*
 * SevSegment_config.h
 *
 * Created: 3/6/2024 12:32:14 PM
 *  Author: lenovo
 */ 


#ifndef SEVSEGMENT_CONFIG_H_
#define SEVSEGMENT_CONFIG_H_



#define SEVEN_SEG_PORT	DIO_PORTB
#define PIN_A			DIO_PIN0
#define PIN_B			DIO_PIN1
#define PIN_C			DIO_PIN2
#define PIN_D			DIO_PIN4

#define ANODE		0
#define CATHODE		1



#define ZERO_CATHODE		0b01111110
#define ONE_CATHODE			0b00110000
#define TWO_CATHODE			0b01101101
#define THREE_CATHODE		0b01111001
#define FOUR_CATHODE		0b00110011
#define FIVE_CATHODE		0b01011011
#define SIX_CATHODE			0b01011111
#define SVN_CATHODE			0b01110000
#define EIGHT_CATHODE		0b01111111
#define NINE_CATHODE		0b01111011

#define ZERO_ANODE			0b0000001
#define ONE_ANODE			0b1001111
#define TWO_ANODE			0b0010010
#define THREE_ANODE			0b0000110
#define FOUR_ANODE			0b1001100
#define FIVE_ANODE			0b0100100
#define SIX_ANODE			0b1100000
#define SVN_ANODE			0b0001111
#define EIGHT_ANODE			0b0000000
#define NINE_ANODE			0b0001100


#define FOUR_BIT_MODE		4
#define SEVEN_BIT_MODE		7

#define SEVEN_SEG_TYPE		ANODE
#define SEVEN_SEG_MODE		FOUR_BIT_MODE


#endif /* SEVSEGMENT_CONFIG_H_ */
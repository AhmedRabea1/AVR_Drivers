

#ifndef KP_CONFIG_H_
#define KP_CONFIG_H_

#define ROW_PORT			DIO_PORTC

#define R1					DIO_PIN5
#define R2					DIO_PIN4
#define R3					DIO_PIN3
#define R4					DIO_PIN2

#define COLUMN_PORT			DIO_PORTD

#define C1					DIO_PIN7
#define C2					DIO_PIN6
#define C3					DIO_PIN5
#define C4					DIO_PIN3

#define KP_NO_PRESSED_KEY	0XFF

#define COLUMN_NUMBER		4
#define ROW_NUMBER			4

#define KP_ARR_VAL			{{' ',99,0,'+'},{'-',3,2,1},{'*',6,5,4},{'/',9,8,7}}

#endif /* KP_CONFIG_H_ */
/*
 * LCD_interface.h
 *
 * Created: 3/6/2024 2:54:53 PM
 *  Author: Ahmed Rabea
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#define LCD_Data	DIO_PORTB
#define LCD_Ctrl	DIO_PORTA

#define E	DIO_PIN2
#define W	DIO_PIN1
#define RS	DIO_PIN3

#define D0		DIO_PIN0
#define D1		DIO_PIN1
#define D2		DIO_PIN2
#define D3		DIO_PIN4
#define D4		DIO_PIN0
#define D5		DIO_PIN1
#define D6		DIO_PIN2
#define D7		DIO_PIN4




#define Eight_Bit_Mode		0x38
#define Four_Bit_Mode		0x28
#define CLEAR_COMMAND		0x01
#define CURSOR_OFF			0x0C
#define CURSOR_ON			0x0E
#define SET_CURSOR_LOCATION 0x80

#define CGRAM_COMMAND					0x40
#define CGRAM_COMMAND					0x40

#define NO_PRESSED_KEY					0xFF


void LCD_Init();
void LCD_SendCommand(u8 data);
void LCD_SendCharacter(u8 data);
void LCD_SendString(u8 *str);
void LCD_GoToRowCol(u8 row, u8 col);
void LCD_SendStringRowCol(u8 row, u8 col, u8 *str);
void LCD_ClearScreen();
void LCD_writeNumber(u32 Num);
void LCD_Send_Special_Char(u8 specialChar,u8 index);




#endif /* LCD_INTERFACE_H_ */
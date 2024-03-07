#include "../../LIB/std_types.h"
#include "../../LIB//bit_math.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"





void DIO_voidSetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
		switch(copy_u8PortId){
			case 0:
			CLEAR_BIT(DDRA,copy_u8PinId);
			break;
			case 1:
			CLEAR_BIT(DDRB,copy_u8PinId);
			break;
			case 2:
			CLEAR_BIT(DDRC,copy_u8PinId);
			break;
			case 3:
			CLEAR_BIT(DDRD,copy_u8PinId);
			break;
		}
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
		switch(copy_u8PortId){
			case 0:
			SET_BIT(DDRA,copy_u8PinId);
			break;
			case 1:
			SET_BIT(DDRB,copy_u8PinId);
			break;
			case 2:
			SET_BIT(DDRC,copy_u8PinId);
			break;
			case 3:
			SET_BIT(DDRD,copy_u8PinId);
			break;
		}
	}
}
void DIO_voidSetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if(copy_u8PinValue == DIO_PIN_HIGH)
	{
		switch(copy_u8PortId)
		{
			case 0:
			SET_BIT(PORTA,copy_u8PinId);
			break;
			case 1:
			SET_BIT(PORTB,copy_u8PinId);
			break;
			case 2:
			SET_BIT(PORTC,copy_u8PinId);
			break;
			case 3:
			SET_BIT(PORTD,copy_u8PinId);
			break;
		}
	}
	else if(copy_u8PinValue == DIO_PIN_LOW)
	{
		switch(copy_u8PortId)
		{
			case 0:
			CLEAR_BIT(PORTA,copy_u8PinId);
			break;
			case 1:
			CLEAR_BIT(PORTB,copy_u8PinId);
			break;
			case 2:
			CLEAR_BIT(PORTC,copy_u8PinId);
			break;
			case 3:
			CLEAR_BIT(PORTD,copy_u8PinId);
			break;
		}
	}
}
void DIO_voidGetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	switch(copy_u8PortId)
	{
		case 0:
		* copy_pu8PinValue = GET_BIT(PINA,copy_u8PinId);
		break;
		case 1:
		* copy_pu8PinValue = GET_BIT(PINB,copy_u8PinId);
		break;
		case 2:
		* copy_pu8PinValue = GET_BIT(PINC,copy_u8PinId);
		break;
		case 3:
		* copy_pu8PinValue = GET_BIT(PIND,copy_u8PinId);
		break;
	}
}
void DIO_voidTogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case 0:
		TOGGLE_BIT(PORTA,copy_u8PinId);
		break;
		case 1:
		TOGGLE_BIT(PORTB,copy_u8PinId);
		break;
		case 2:
		TOGGLE_BIT(PORTC,copy_u8PinId);
		break;
		case 3:
		TOGGLE_BIT(PORTD,copy_u8PinId);
		break;
	}
}
void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case 0:
		CLEAR_BIT(DDRA,copy_u8PinId);
		SET_BIT(PINA,copy_u8PinId);
		break;
		case 1:
		CLEAR_BIT(DDRB,copy_u8PinId);
		SET_BIT(PINB,copy_u8PinId);
		break;
		case 2:
		CLEAR_BIT(DDRC,copy_u8PinId);
		SET_BIT(PINC,copy_u8PinId);
		break;
		case 3:
		CLEAR_BIT(DDRD,copy_u8PinId);
		SET_BIT(PIND,copy_u8PinId);
		break;
	}
}

void DIO_voidSetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	if(copy_u8PortDirection == DIO_PIN_OUTPUT)
	{
		switch(copy_u8PortId)
		{
			case 0:
			DDRA = DIO_PORT_OUTPUT;
			break;
			case 1:
			DDRB = DIO_PORT_OUTPUT;
			break;
			case 2:
			DDRC = DIO_PORT_OUTPUT;
			break;
			case 3:
			DDRD = DIO_PORT_OUTPUT;
			break;
		}
	}
	else if(copy_u8PortDirection == DIO_PIN_INPUT)
	{
		switch(copy_u8PortId)
		{
			case 0:
			DDRA = DIO_PORT_INPUT;
			break;
			case 1:
			DDRB = DIO_PORT_INPUT;
			break;
			case 2:
			DDRC = DIO_PORT_INPUT;
			break;
			case 3:
			DDRD = DIO_PORT_INPUT;
			break;
		}
	}
}
void DIO_voidSetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue)
{
	if(copy_u8PortValue == DIO_PORT_HIGH)
	{
		switch(copy_u8PortId)
		{
			case 0:
			PORTA = DIO_PORT_HIGH;
			break;
			case 1:
			PORTB = DIO_PORT_HIGH;
			break;
			case 2:
			PORTC = DIO_PORT_HIGH;
			break;
			case 3:
			PORTD = DIO_PORT_HIGH;
			break;
		}
	}
	if(copy_u8PortValue == DIO_PORT_LOW)
	{
		switch(copy_u8PortId)
		{
			case 0:
			PORTA = DIO_PORT_LOW;
			break;
			case 1:
			PORTB = DIO_PORT_LOW;
			break;
			case 2:
			PORTC = DIO_PORT_LOW;
			break;
			case 3:
			PORTD = DIO_PORT_LOW;
			break;
		}
	}
	
}
void DIO_voidGetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	switch(copy_u8PortId)
	{
		case 0:
		* copy_pu8PortValue = PINA;
		break;
		case 1:
		* copy_pu8PortValue = PINB;
		break;
		case 2:
		* copy_pu8PortValue = PINC;
		break;
		case 3:
		* copy_pu8PortValue = PIND;
		break;
	}
}
void DIO_voidTogglePortValue             (u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case 0:
		TOGGLE_BIT(PORTA,DIO_PIN0);
		TOGGLE_BIT(PORTA,DIO_PIN1);
		TOGGLE_BIT(PORTA,DIO_PIN2);
		TOGGLE_BIT(PORTA,DIO_PIN3);
		TOGGLE_BIT(PORTA,DIO_PIN4);
		TOGGLE_BIT(PORTA,DIO_PIN5);
		TOGGLE_BIT(PORTA,DIO_PIN6);
		TOGGLE_BIT(PORTA,DIO_PIN7);
		break;
		case 1:
		TOGGLE_BIT(PORTA,DIO_PIN0);
		TOGGLE_BIT(PORTA,DIO_PIN1);
		TOGGLE_BIT(PORTA,DIO_PIN2);
		TOGGLE_BIT(PORTA,DIO_PIN3);
		TOGGLE_BIT(PORTA,DIO_PIN4);
		TOGGLE_BIT(PORTA,DIO_PIN5);
		TOGGLE_BIT(PORTA,DIO_PIN6);
		TOGGLE_BIT(PORTA,DIO_PIN7);
		break;
		case 2:
		TOGGLE_BIT(PORTA,DIO_PIN0);
		TOGGLE_BIT(PORTA,DIO_PIN1);
		TOGGLE_BIT(PORTA,DIO_PIN2);
		TOGGLE_BIT(PORTA,DIO_PIN3);
		TOGGLE_BIT(PORTA,DIO_PIN4);
		TOGGLE_BIT(PORTA,DIO_PIN5);
		TOGGLE_BIT(PORTA,DIO_PIN6);
		TOGGLE_BIT(PORTA,DIO_PIN7);
		break;
		case 3:
		TOGGLE_BIT(PORTA,DIO_PIN0);
		TOGGLE_BIT(PORTA,DIO_PIN1);
		TOGGLE_BIT(PORTA,DIO_PIN2);
		TOGGLE_BIT(PORTA,DIO_PIN3);
		TOGGLE_BIT(PORTA,DIO_PIN4);
		TOGGLE_BIT(PORTA,DIO_PIN5);
		TOGGLE_BIT(PORTA,DIO_PIN6);
		TOGGLE_BIT(PORTA,DIO_PIN7);
		break;
	}	
}
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case 0:
		DDRA = DIO_PORT_INPUT;
		PINA = DIO_PORT_HIGH;
		break;
		case 1:
		DDRB = DIO_PORT_INPUT;
		PINB = DIO_PORT_HIGH;
		break;
		case 2:
		DDRC = DIO_PORT_INPUT;
		PINC = DIO_PORT_LOW;
		break;
		case 3:
		DDRD = DIO_PORT_INPUT;
		PIND = DIO_PORT_LOW;
	}
}
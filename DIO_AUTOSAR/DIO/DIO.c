/*
 * DIO.c
 *
 * Created: 3/10/2024 2:04:56 PM
 *  Author: lenovo
 */ 
#include "Dio.h"
#include "Dio_Regs.h"


Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
	Dio_LevelType ReturnValue;
	volatile REGSS_Struct* DioPort;
		if(ChannelId < 8)
		{
			//PORTA
			DioPort = DIO_PORTA;
			if(GET_BIT(DioPort->PIN,ChannelId))
			{
				ReturnValue = STD_HIGH;
			}
			else
			ReturnValue = STD_LOW;
		}
		else if(ChannelId < 16)
		{
			//PORTB
			DioPort = DIO_PORTB;
			if(GET_BIT(DioPort->PIN,ChannelId-8))
			{
				ReturnValue = STD_HIGH;
			}
			else
			ReturnValue = STD_LOW;
		}
		else if(ChannelId < 24)
		{
			//PORTC
			DioPort = DIO_PORTC;
			if(GET_BIT(DioPort->PIN,ChannelId-16))
			{
				ReturnValue = STD_HIGH;
			}
			else
			ReturnValue = STD_LOW;
		}
		else if(ChannelId < DIO_CHANNELS)
		{
			//PORTD
			DioPort = DIO_PORTD;
			if(GET_BIT(DioPort->PIN,ChannelId-24))
			{
				ReturnValue = STD_HIGH;
			}
			else
			ReturnValue = STD_LOW;
		}
		return ReturnValue;
	}
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	volatile REGSS_Struct* DioPort;
	if(ChannelId < 8)
	{
		//PORTA
		DioPort = DIO_PORTA;
		if(Level == STD_HIGH)
		{
			SET_BIT(DioPort->PORT,ChannelId);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(DioPort->PORT,ChannelId);
		}
	}
	else if(ChannelId < 16)
	{
		//PORTB
		DioPort = DIO_PORTB;
		if(Level == STD_HIGH)
		{
			SET_BIT(DioPort->PORT,ChannelId-8);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(DioPort->PORT,ChannelId-8);
		}
	}
	else if(ChannelId < 24)
	{
		//PORTC
		DioPort = DIO_PORTC;
		if(Level == STD_HIGH)
		{
			SET_BIT(DioPort->PORT,ChannelId-16);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(DioPort->PORT,ChannelId-16);
		}
	}
	else if(ChannelId < DIO_CHANNELS)
	{
		//PORTD
		DioPort = DIO_PORTD;
		if(Level == STD_HIGH)
		{
			SET_BIT(DioPort->PORT,ChannelId-24);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(DioPort->PORT,ChannelId-24);
		}
	}
}
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )
{
	Dio_LevelType ReturnValue;
	volatile REGSS_Struct* DioPort;
	if(PortId == 0)
		{
			//PORTA
			DioPort = DIO_PORTA;
			ReturnValue = DioPort->PORT;
		}
		else if(PortId == 1)
		{
			//PORTB
			DioPort = DIO_PORTB;
			ReturnValue = DioPort->PORT;
		}
		else if(PortId == 2)
		{
			//PORTC
			DioPort = DIO_PORTC;
			ReturnValue = DioPort->PORT;
		}
		else if(PortId == 3)
		{
			//PORTD
			DioPort = DIO_PORTD;
			ReturnValue = DioPort->PORT;
		}
		return ReturnValue;
}
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{
	volatile REGSS_Struct* DioPort;
	if(PortId == 0)
	{
		//PORTA
		DioPort = DIO_PORTA;
		DioPort->PORT = Level;
	}
	else if(PortId == 1)
	{
		//PORTB
		DioPort = DIO_PORTB;
		DioPort->PORT = Level;
	}
	else if(PortId == 2)
	{
		//PORTC
		DioPort = DIO_PORTC;
		DioPort->PORT = Level;
	}
	else if(PortId == 3)
	{
		//PORTD
		DioPort = DIO_PORTD;
		DioPort->PORT = Level;
	}
}
Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	Dio_PortLevelType ReturnValue;
	volatile REGSS_Struct* DioPort;
	if(ChannelGroupIdPtr->port == 0)
	{
	//PORTA
	DioPort = DIO_PORTA;
	ReturnValue = ((DioPort->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}
	else if(ChannelGroupIdPtr->port == 1)
	{
	//PORTB
	DioPort = DIO_PORTB;
	ReturnValue = ((DioPort->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}
else if(ChannelGroupIdPtr->port == 2)
{
	//PORTC
	DioPort = DIO_PORTC;
	ReturnValue = ((DioPort->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
}
else if(ChannelGroupIdPtr->port == 3)
{
	//PORTD
	DioPort = DIO_PORTD;
	ReturnValue = ((DioPort->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
}

return ReturnValue;
}

void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	volatile REGSS_Struct* DioPort;
	if(ChannelGroupIdPtr->port == 0)
	{
		//PORTA
		DioPort = DIO_PORTA;
		DioPort->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 1)
	{
		//PORTB
		DioPort = DIO_PORTB;
		DioPort->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 2)
	{
		//PORTC
		DioPort = DIO_PORTC;
		DioPort->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 3)
	{
		//PORTD
		DioPort = DIO_PORTD;
		DioPort->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}

}

Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId )
{
	Dio_LevelType ReturnValue;
	volatile REGSS_Struct* DioPort;
	if(ChannelId < 8)
	{
		//PORTA
		DioPort = DIO_PORTA;
		TOGGLE_BIT(DioPort->PORT,ChannelId); 
	}
	else if(ChannelId < 16)
	{
		//PORTB
		DioPort = DIO_PORTB;
		TOGGLE_BIT(DioPort->PORT,ChannelId-8);
	}
	else if(ChannelId < 24)
	{
		//PORTC
		DioPort = DIO_PORTC;
		TOGGLE_BIT(DioPort->PORT,ChannelId-16);
	}
	else if(ChannelId < DIO_CHANNELS)
	{
		//PORTD
		DioPort = DIO_PORTD;
		TOGGLE_BIT(DioPort->PORT,ChannelId-24);
	}

	ReturnValue = Dio_ReadChannel(ChannelId);

	return ReturnValue;
}

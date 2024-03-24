/*
 * EEPROM_program.c
 *
 * Created: 3/24/2024 11:56:28 AM
 *  Author: lenovo
 */ 

#define F_CPU 16000000UL

#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "util/delay.h"
#include "../../MCAL/I2C/I2C_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"

void EEPROM_voidInit					(void)
{
	TWI_voidInitMaster();
}
void EEPROM_voidWriteByte				(u16 copy_u16WordAddress,u8 copy_u8Data)
{
	u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS ;
	TWI_voidSendStartCondition();
	
	//Send first 8 bits , if there is no casting it will also run correctly
	TWI_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
	
	TWI_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
	
	TWI_voidTransmitMasterDataByte(copy_u8Data);
	
	TWI_voidSendStopCondition();
	
	_delay_ms(5);
}
void EEPROM_voidReadByte				(u16 copy_u16WordAddress, u8 * copy_pu8Data)
{
	if(copy_pu8Data != NULL)
	{
		u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS ;
		TWI_voidSendStartCondition();
			
		//Send first 8 bits , if there is no casting it will also run correctly
		//Send Device Address with write operation
		TWI_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		// Send word address	
		TWI_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
		//Repeated start to change operation
		TWI_voidSendRepeatedStartCondition();
		//Send Address with read
		TWI_voidSendSlaveAddWithRead(local_u8DeviceAddress);
		
		TWI_voidReceiveMasterDataByteWithNack(copy_pu8Data);
		
		TWI_voidSendStopCondition();
		//Self time write cycles
		_delay_ms(5);
	}
	else
	{
		//Error State
	}
}
void EEPROM_voidWritePage				(u16 copy_u16WordAddress, u8* copy_pu8Data, u8 copy_u8DataSize)
{
	if(copy_pu8Data != NULL && copy_u8DataSize <= 16)
	{
		u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS ;
		TWI_voidSendStartCondition();
		
		//Send first 8 bits , if there is no casting it will also run correctly
		TWI_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		
		TWI_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
		
		for(u8 Counter = 0 ; Counter < copy_u8DataSize ;Counter++)
		{
			TWI_voidTransmitMasterDataByte(copy_pu8Data[Counter]);
			
		}
		TWI_voidSendStopCondition();
		
		_delay_ms(5);
	}
	else
	{
		//Error state
	}
}
void EEPROM_voidReadPage				(u16 copy_u16WordAddress, u8* copy_pu8Data, u8 copy_u8DataSize)
{
	if(copy_pu8Data != NULL && copy_u8DataSize <= 16)
	{
	
		u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS ;
		TWI_voidSendStartCondition();
	
		//Send first 8 bits , if there is no casting it will also run correctly
		//Send Device Address with write operation
		TWI_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		// Send word address
		TWI_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
		//Repeated start to change operation
		TWI_voidSendRepeatedStartCondition();
		//Send Address with read
		TWI_voidSendSlaveAddWithRead(local_u8DeviceAddress);
		u8 Counter;
		for(Counter = 0 ; Counter < copy_u8DataSize-1 ;Counter++)
		{
			TWI_voidReceiveMasterDataByteWithAck(&copy_pu8Data[Counter]);
		}
		
		TWI_voidReceiveMasterDataByteWithNack(&copy_pu8Data[Counter]);
		
		TWI_voidSendStopCondition();
		//Self time write cycles
		_delay_ms(5);
	}
	else
	{
		//Return Error State
	}
}
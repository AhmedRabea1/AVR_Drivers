/*
 * EEPROM_interface.h
 *
 * Created: 3/24/2024 11:56:11 AM
 *  Author: Ahmed Rabea
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit					(void);
void EEPROM_voidWriteByte				(u16 copy_u16WordAddress,u8 copy_u8Data);
void EEPROM_voidReadByte				(u16 copy_u16WordAddress, u8 * copy_pu8Data);
void EEPROM_voidWritePage				(u16 copy_u16WordAddress, u8* copy_u8Data, u8 copy_u8DataSize);
void EEPROM_voidReadPage				(u16 copy_u16WordAddress, u8* copy_u8Data, u8 copy_u8DataSize);


#endif /* EEPROM_INTERFACE_H_ */
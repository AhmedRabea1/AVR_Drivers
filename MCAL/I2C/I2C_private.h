/*
 * I2C_private.h
 *
 * Created: 3/24/2024 11:01:35 AM
 *  Author: lenovo
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWI_STATUS_VALUE				 (TWSR_REG&0xF8)

#define TWI_START_CONDITION_ACK          0x08
#define TWI_REP_START_CONDITION_ACK      0x10
#define TWI_SLAVE_ADDRESS_WRITE_ACK      0x18
#define TWI_SLAVE_ADDRESS_READ_ACK       0x40
#define TWI_MASTER_DATA_TRANSMIT_ACK     0x28
#define TWI_MASTER_DATA_RECIEVE_ACK      0x50
#define TWI_MASTER_DATA_RECIEVE_NACK     0x58



#endif /* I2C_PRIVATE_H_ */
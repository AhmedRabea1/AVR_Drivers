/*
 * I2C_interface.h
 *
 * Created: 3/23/2024 4:26:23 PM
 *  Author: Ahmed Rabea
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void TWI_voidInitMaster                   (void);
void TWI_voidSendStartCondition           (void);
void TWI_voidSendRepeatedStartCondition   (void);
void TWI_voidSendStopCondition            (void);
void TWI_voidSendSlaveAddWithWrite        (u8  copy_u8SlaveAdd);
void TWI_voidSendSlaveAddWithRead         (u8  copy_u8SlaveAdd);
void TWI_voidTransmitMasterDataByte       (u8  copy_u8TxData);
void TWI_voidReceiveMasterDataByteWithAck (u8* copy_pu8RxData);
void TWI_voidReceiveMasterDataByteWithNack(u8* copy_pu8RxData);


#endif /* I2C_INTERFACE_H_ */
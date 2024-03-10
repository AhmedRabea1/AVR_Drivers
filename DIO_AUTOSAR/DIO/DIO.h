/*
 * DIO_interface.h
 *
 * Created: 3/9/2024 7:45:21 PM
 *  Author: lenovo
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "bit_math.h"
#include "STD_TYPES.h"
#include "Dio_Cfg.h"

#define DIO_VENDOR_ID							100U

#define DIO_AR_RELEASE_MAJOR_VERSION				4U
#define DIO_AR_RELEASE_MINOR_VERSION				4U
#define DIO_AR_RELEASE_PATCH_VERSION				0U

/*Module version 1.0.0*/
#define DIO_SW_MAJOR_VERSION						1U
#define DIO_SW_MINOR_VERSION						0U
#define DIO_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Dio Modules */
#if   ((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
|| (DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
|| (DIO_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif

/*APIS ID*/
#define DIO_READ_CHANNEL					0x00
#define DIO_WRITE_CHANNEL					0x01
#define DIO_READ_PORT						0x02
#define DIO_WRITE_PORT						0x03
#define DIO_READ_CHANNEL_GROUP	     		0x04
#define DIO_WRITE_CHANNEL_GROUP				0x05
#define DIO_GET_VERSION_INFO				0x12
#define DIO_FLIP_CHANNEL					0x11
#define DIO_MASKED_WRITE_PORT				0x13

/*ERROR CLASSIFICATION*/

//Invalid channel
#define DIO_E_PARAM_INVALID_CHANNEL_ID					0x0A
//Invalid port 
#define DIO_E_PARAM_INVALID_PORT_ID						0x14
//Invalid channel group 
#define DIO_E_PARAM_INVALID_GROUP						0x1F
//NULL pointer
#define DIO_E_PARAM_POINTER								0x20

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;	

typedef struct
{
	uint8 mask;			//This element mask which defines the positions of the channel group.
	uint8 offset;		//This element shall be the position of the Channel Group on the port, counted from the LSB.
	Dio_PortType port;	//This shall be the port on which the Channel group is defined.
}Dio_ChannelGroupType;

typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;

typedef enum
{
	DIO_PORT0 = 0,
	DIO_PORT1,
	DIO_PORT2,
	DIO_PORT3,
}DIO_PORTS;

typedef enum
{
	DIO_CHANNEL0 = 0,
	DIO_CHANNEL1,
	DIO_CHANNEL2,
	DIO_CHANNEL3,
	DIO_CHANNEL4,
	DIO_CHANNEL5,
	DIO_CHANNEL6,
	DIO_CHANNEL7,
	DIO_CHANNEL8,
	DIO_CHANNEL9,
	DIO_CHANNEL10,
	DIO_CHANNEL11,
	DIO_CHANNEL12,
	DIO_CHANNEL13,
	DIO_CHANNEL14,
	DIO_CHANNEL15,
	DIO_CHANNEL16,
	DIO_CHANNEL17,
	DIO_CHANNEL18,
	DIO_CHANNEL19,
	DIO_CHANNEL20,
	DIO_CHANNEL21,
	DIO_CHANNEL22,
	DIO_CHANNEL23,
	DIO_CHANNEL24,
	DIO_CHANNEL25,
	DIO_CHANNEL26,
	DIO_CHANNEL27,
	DIO_CHANNEL28,
	DIO_CHANNEL29,
	DIO_CHANNEL30,
	DIO_CHANNEL31
}DIO_CHANNELS;

typedef struct
{
	Dio_ChannelType DioChannelId;
}Dio_Channel;

typedef struct
{
	Dio_PortType DioPortId;
	Dio_Channel DioChannel;
}Dio_Port;

typedef struct
{
	Dio_Port DioPort;
}Dio_Config;

/*Function Prototypes*/
/*This API Returns the value of the specified DIO channel*/
/*
Synchronous
Reentrant
Parameters in -> ChannelId
*/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
/*This API Service to set a level of a channel*/
/*
Synchronous
Reentrant
Parameters in -> ChannelId [ID of DIO Channel]
			  -> Level		[Value to be written]
*/
void Dio_WriteChannel (
Dio_ChannelType ChannelId,
Dio_LevelType Level
);

/*This API return the level of all channels of that port*/
/*
Synchronous
Reentrant
Parameters in -> PortId
*/
Dio_PortLevelType Dio_ReadPort (
Dio_PortType PortId
);
/*This API Service to set a value of a port */
/*
Synchronous
Reentrant
Parameters in -> PortId
			  -> Level
*/
void Dio_WritePort (
Dio_PortType PortId,
Dio_PortLevelType Level
);/*This API reads a subset of the adjoining bits of a port.*//*
Synchronous
Reentrant
Parameters in -> ChannelGroupIdPtr
*/Dio_PortLevelType Dio_ReadChannelGroup (
const Dio_ChannelGroupType* ChannelGroupIdPtr
);/*This API Service to set a subset of the adjoining bits of a port to a specified level.*//*
Synchronous
Reentrant
Parameters in -> ChannelGroupIdPtr
			  -> Level
*/void Dio_WriteChannelGroup (
const Dio_ChannelGroupType* ChannelGroupIdPtr,
Dio_PortLevelType Level
);/*This API Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
the level of the channel after flip.*/
/*
Synchronous
Reentrant
Parameters in -> ChannelId
*/
Dio_LevelType Dio_FlipChannel (
Dio_ChannelType ChannelId
);
#endif /* DIO_H_ */
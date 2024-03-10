/*
 * STD_TYPES.h
 *
 * Created: 3/9/2024 1:55:12 PM
 *  Author: lenovo
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_Types.h"

//Vendor ID according to the AUTOSAR vendor list
#define STD_TYPES_VENDOR_ID							50U

/*AUTOSAR Module version 4.3.1*/
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION				4U
#define STD_TYPES_AR_RELEASE_MINOR_VERSION				3U
#define STD_TYPES_AR_RELEASE_PATCH_VERSION				1U

/*Module version 1.0.0*/
#define STD_TYPES_SW_MAJOR_VERSION						1U
#define STD_TYPES_SW_MINOR_VERSION						0U
#define STD_TYPES_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Platform Types Modules */
#if   ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) \
|| (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION) \
|| (STD_TYPES_AR_RELEASE_REVISION_VERSION != PLATFORM_AR_RELEASE_PATCH_VERSION))

#error ("AUTOSAR Version of PlatformTypes.h doesn't match the expected version")
#endif

/* This type can be used as standard API return type which is shared between the RTE and the BSW
modules. It shall be defined as follows*/
typedef uint8 Std_ReturnType;

/*The type of the Std_TransformerError*/
typedef uint8 Std_TransformerErrorCode;

/*The type of the Std_TransformerClass*/
typedef uint8 Std_TransformerClass;

#define STD_TRANSFORMER_UNSPECIFIED 0x00 //Transformer of a unspecified transformer class
#define STD_TRANSFORMER_SAFETY		0x02 //Transformer of a safety class
#define STD_TRANSFORMER_SECURITY    0x03 //Transformer of a security class
typedef uint8 Std_TransformerForwardCode;

#define E_OK						0x00		//No specific error to be injected
#define E_SAFETY_INVALID_REP		0x01		//Repeat the last used sequence number
#define E_SAFETY_INVALID_SEQ		0x02		//Generate a deliberately wrong CRC.
#define E_SAFETY_INVALID_CRC		0x03		//Use a wrong sequence number.


/*This type shall be used to request the version of a BSW module using the <Module name>_Get
VersionInfo() function.*/
typedef struct
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

/*The data type Std_TransformerError is a struct which contains the error code and the
transformer class to which the error belongs.*/
typedef struct 
/*The data type Std_TransformerForward is a struct which contains the forwarded status
and the transformer class to which the forwarded status applies*/
encoding is limited to the distinction between OK and ERROR responses*/
the type of the message result of a transformer. - At the time being, this is limited to the types
used for C/S communication*/
const uint8* buffer,
uint32 bufferLength,
Std_MessageTypeType* messageType,
Std_MessageResultType* messageResult
);
#define STATUSTYPEDEFINED
#define E_OK						0x00u
typedef unsigned char StatusType;	/* OSEK compliance */
#endif

#define STD_HIGH					0x01u				/* Physical state 5V or 3.3V */

#define STD_IDLE					0x00u				/* Logical state idle*/
#define STD_ACTIVE					0x01u				/* Logical state active*/

#define STD_OFF						0x00u				/*Standard Off*/
#define STD_ON						0x01u				/*Standard On*/

#define NULL_PTR				((VoidPtr) 0)

#endif

#endif /* STD_TYPES_H_ */
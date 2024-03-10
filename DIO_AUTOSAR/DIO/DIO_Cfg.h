/*
 * DIO_Cfg.h
 *
 * Created: 3/9/2024 7:26:57 PM
 *  Author: lenovo
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "STD_TYPES.h"

/*AUTOSAR Module version 4.3.1*/
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION				4U
#define DIO_CFG_AR_RELEASE_MINOR_VERSION				3U
#define DIO_CFG_AR_RELEASE_REVISION_VERSION				1U

/*Module version 1.0.0*/
#define DIO_CFG_SW_MAJOR_VERSION						1U
#define DIO_CFG_SW_MINOR_VERSION						0U
#define DIO_CFG_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Dio Modules */
#if   ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
|| (DIO_CFG_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
|| (DIO_CFG_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif
/*Switches the development error detection and notification on or off.
? true: detection and notification is enabled.
? false: detection and notification is disabled*/
#define DIO_DEV_ERROR_DETECT							STD_ON

/*This conf parameter Adds / removes the service Dio_FlipChannel() from the code*/
#define DIO_FLIP_CHANNEL_API							STD_ON

/*This conf param Adds / removes the service Dio_MaskedWritePort() from the code*/
#define DIO_MASKSED_WRITE_PORT_API						STD_ON/*This conf param Adds / removes the service Dio_ GetVersionInfo() from the code.*/
#define DIO_VERSION_INFO_API							STD_ON#define PORTS											4#define CHANNELS										32

#endif /* DIO_CFG_H_ */
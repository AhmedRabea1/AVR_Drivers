/*
 * PLATFORM_TYPES.h
 *
 * Created: 3/9/2024 2:01:43 PM
 *  Author: lenovo
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

//Vendor ID according to the AUTOSAR vendor list
#define PLATFORM_VENDOR_ID							50U

/*AUTOSAR Module version 4.3.1*/
#define PLATFORM_AR_RELEASE_MAJOR_VERSION				4U
#define PLATFORM_AR_RELEASE_MINOR_VERSION				3U
#define PLATFORM_AR_RELEASE_PATCH_VERSION				1U

/*Module version 1.0.0*/
#define PLATFORM_SW_MAJOR_VERSION						1U
#define PLATFORM_SW_MINOR_VERSION						0U
#define PLATFORM_SW_PATCH_VERSION						0U

/*CPU Register width*/
#define CPU_TYPE_8				8U				//8 bit processor
#define CPU_TYPE_16				16U				//16 bit processor
#define CPU_TYPE_32				32U				//32 bit processor
#define CPU_TYPE_64				64U				//64 bit processor

/*BIT ORDERING*/
#define MSB_FIRST					0U				
#define LSB_FIRST					1U			
	
/*BYTE ORDERING */
#define HIGH_BYTE_FIRST				0U				
#define LOW_BYTE_FIRST				1U				

/*BOOLEAN VALUES*/
typedef unsigned char boolean;
#ifndef TRUE
#define TRUE				0x01U
#endif

#ifndef FALSE
#define FALSE				0x00U
#endif

typedef unsigned char 			uint8;				/*0		-->		255 */
#define UINT8_MIN				0x00
#define UINT8_MAX				0xFF

typedef unsigned short 			uint16;				/* 0		-->		65535 */
#define UINT16_MIN				0x00
#define UINT16_MAX				0xFFFF

typedef unsigned long		    uint32;				/* 0		-->		4294967295 */
#define UINT32_MIN				0x00
#define UINT32_MAX				0xFFFFFFFF

typedef unsigned long long 		uint64;				/* 0		-->		18446744073709551615 */
#define UINT64_MIN				0x00
#define UINT64_MAX				0xFFFFFFFFFFFFFFFF

typedef signed char 			sint8;				/*-128						-->		127 */
#define SINT8_MIN				0x80
#define SINT8_MAX				0x7F

typedef signed short 			sint16;				/*-32768						-->		32767 */
#define SINT16_MIN				0x8000
#define SINT16_MAX				0x7FFF

typedef signed long 			sint32;				/*-2147483648				-->		2147483647 */
#define SINT32_MIN				0x80000000
#define SINT32_MAX				0x7FFFFFFF

typedef signed long long 		sint64;				/*-9223372036854775808		-->		9223372036854775807 */
#define SINT64_MIN				0x8000000000000000
#define SINT64_MAX				0x7FFFFFFFFFFFFFFF

typedef float 					float32;				
typedef double 					float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;
	
#endif /* PLATFORM_TYPES_H_ */
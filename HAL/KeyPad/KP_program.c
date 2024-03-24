
#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"
#include "../DIO/DIO_interface.h"
#include "../DIO/DIO_config.h"
#include "KP_config.h"
#include "KP_interface.h"
void KP_voidINIT		(void)
{
	DIO_voidActivePinInPullUpResistance(ROW_PORT,R1);
	DIO_voidActivePinInPullUpResistance(ROW_PORT,R2);
	DIO_voidActivePinInPullUpResistance(ROW_PORT,R3);
	DIO_voidActivePinInPullUpResistance(ROW_PORT,R4);
	
	DIO_voidSetPinDirection(COLUMN_PORT,C1,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COLUMN_PORT,C2,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COLUMN_PORT,C3,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COLUMN_PORT,C4,DIO_PIN_OUTPUT);
	
	DIO_voidSetPinValue(COLUMN_PORT,C1,DIO_PIN_HIGH);
	DIO_voidSetPinValue(COLUMN_PORT,C2,DIO_PIN_HIGH);
	DIO_voidSetPinValue(COLUMN_PORT,C3,DIO_PIN_HIGH);
	DIO_voidSetPinValue(COLUMN_PORT,C4,DIO_PIN_HIGH);
	
	
}

u8 KP_u8GetPressedKey	(void)
{
	u8 PressedKeyVAL=KP_NO_PRESSED_KEY;
	u8 Column_CNTR,Row_CNTR;
	u8 KP_arr[ROW_NUMBER][COLUMN_NUMBER]=KP_ARR_VAL;
	
	
	u8 ColumnPINS	[COLUMN_NUMBER]	=	{C1,C2,C3,C4};
	u8 ROWPINS		[ROW_NUMBER]	=	{R1,R2,R3,R4};
	 
	for (Column_CNTR=0;Column_CNTR<COLUMN_NUMBER;Column_CNTR++)
	{
		DIO_voidSetPinValue(COLUMN_PORT,ColumnPINS[Column_CNTR],DIO_PIN_LOW);
		
		for (Row_CNTR=0;Row_CNTR<ROW_NUMBER;Row_CNTR++)
		{
			if (DIO_u8GetPinValue(ROW_PORT,ROWPINS[Row_CNTR])==DIO_PIN_LOW)
			{
				
				PressedKeyVAL=KP_arr[Row_CNTR][Column_CNTR];
				while(DIO_u8GetPinValue(ROW_PORT,ROWPINS[Row_CNTR])==DIO_PIN_LOW);
				DIO_voidSetPinValue(COLUMN_PORT,ColumnPINS[Column_CNTR],DIO_PIN_HIGH);
				return PressedKeyVAL;
			}
		}
				DIO_voidSetPinValue(COLUMN_PORT,ColumnPINS[Column_CNTR],DIO_PIN_HIGH);

	}
	return PressedKeyVAL;
}


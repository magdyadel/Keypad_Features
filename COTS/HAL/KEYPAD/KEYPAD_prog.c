/*
 * KEYPAD_PRG.c
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
//#include <avr/io.h>
#include "../../MCAL_AVR/DIO/DIO_interface.h"
#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"



u8 arrKeypadValue[4][4]={{0,1,2,3},
						 {4,5,6,7},
						 {8,9,10,11},
						 {12,13,14,15}};

void Keypad_vInit(void)
{
	DIO_vWritePinDirection(KeyoadPORT,R0,DIO_INPUT);
	DIO_vWritePinDirection(KeyoadPORT,R1,DIO_INPUT);
	DIO_vWritePinDirection(KeyoadPORT,R2,DIO_INPUT);
	DIO_vWritePinDirection(KeyoadPORT,R3,DIO_INPUT);

	DIO_vWritePinDirection(KeyoadPORT,C0,DIO_OUTPUT);
	DIO_vWritePinDirection(KeyoadPORT,C1,DIO_OUTPUT);
	DIO_vWritePinDirection(KeyoadPORT,C2,DIO_OUTPUT);
	DIO_vWritePinDirection(KeyoadPORT,C3,DIO_OUTPUT);

	DIO_vWritePortValue(KeyoadPORT, 0xff);
	
}


u8 Keypad_u8GetPressed()
{
	u8 res=-1;
	for (u8 c=0;c<4;c++)
	{
		DIO_vWritePinValue(KeyoadPORT ,c ,0);
		for(u8 r=0;r<4;r++)
		{
			if(DIO_u8ReadPinValue( KeyoadPORT, r+4) ==0)
			{
				res = arrKeypadValue[r][c];
				/*this while will break when user release the switch */
				while (DIO_u8ReadPinValue(KeyoadPORT,r+4)==0);
				break;
			}
		}
		DIO_vWritePinValue(KeyoadPORT ,c ,1);
	}
	return res;
}

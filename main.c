/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Magdy Adel
 */

#include "COTS/LIB/BIT_MATH.h"
#include "COTS/LIB/STD_TYPES.h"
#include "COTS/HAL/KEYPAD/KEYPAD_int.h"
#include "COTS/HAL/LCD_Driver/LCD_interface.h"
#include "COTS/MCAL_AVR/DIO/DIO_interface.h"

u8 u8GetChar(u8 r,u8 c);
u8* GetPassword();


int main()
{
#if 1
	LCD_Init();
	Keypad_vInit();
	LCD_WRITE_STRING("Hello ");

	GetPassword();
#endif
	while(1);
}

#if 1
u8* GetPassword()
{
	s8 count=0, num=0,old=0;
	u8 isFinished=0;


	u8* str="";
	u8 i=0;
	do{
		num=Keypad_u8GetPressed();
		if(num==15)
		{
			isFinished=1;
			LCD_clear_screen();
		}
		else if(num==3)
		{
			LCD_StepBack();
		}
		else if(num>=0)
		{
			if(num==old){
				count++;
				if(count==4)
					count=0;
				LCD_StepBack();
				LCD_WRITE_CHAR(u8GetChar(num,count));
			}
			else{
				old=num;
				count=0;
				LCD_WRITE_CHAR(u8GetChar(num,count));
			}
//			str[i]=u8GetChar(num,count);
//			i++;
		}


	}while(isFinished!=1);

	return str;
}


u8 u8GetChar(u8 r,u8 c)
{
	u8 symbol[][4]={{'1',':',';','/'}, {'2','a','b','c'},{'3','d','e','f'},{'+','-','{','}'},//0,1,2,3
					 {'4','g','h','i'}, {'5','j','k','l'},{'6','m','n','o'},{',','?','<','>'},//4,5,6,7
					 {'7','p','q','r'}, {'8','s','t','u'},{'9','v','w','x'},{'"','|','[',']'},//8,9,10,11
					 {'*','$','&','('}, {'0','y','z','.'},{'#','_','~',')'},{'\0','\0','\0','\0'}};//12,13,14,15

	return symbol[r][c];
}
#endif

/*
 * lcd.h
 *
 *  Author: MAGDY
 */ 


#ifndef LCD_DRIVER_LCD_PRIVATE_H_
#define LCD_DRIVER_LCD_PRIVATE_H_

//#include "../STD_TYPES.h"


void LCD_Init(void);
void LCD_WRITE_COMMAND(u8 command);
void LCD_WRITE_CHAR(u8 data);
void LCD_WRITE_STRING(u8 str[]);
void LCD_isBUSY(void);
void LCD_clear_screen();
void LCD_StepBack();
void LCD_KICK();
void LCD_GOTO_XY(u8 line , u8 position);
void LCD_WRITE_NUMBER(s32 num);
void LCD_save_CustomCHAR(u8 charArr[] ,u8 charID );
void LCD_disp_CustomCHAR(u8 charID );


#endif /* LCD_H_ */

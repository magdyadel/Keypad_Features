/*
 * lcd_private.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Kero
 */

#ifndef LCD_DRIVER_LCD_INERFACE_H_
#define LCD_DRIVER_LCD_INERFACE_H_



#define DATA_SHIFT 4


// Commands of LCD
#define LCD_CMD_FUNCTION_8BIT_2LINES   						(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   						(0x28)
#define LCD_CMD_MOVE_DISP_RIGHT       						(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   							(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   						(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  						(0x10)
#define LCD_CMD_DISP_OFF   									(0x08)
#define LCD_CMD_DISP_ON_CURSOR   							(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   						(0x0F)
#define LCD_CMD_DISP_ON_BLINK   							(0x0D)
#define LCD_CMD_DISP_ON   									(0x0C)
#define LCD_CMD_ENTRY_DEC   								(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   							(0x05)
//#define LCD_CMD_ENTRY_INC_   								(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   							(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW							(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW							(0xC0)
#define LCD_CMD_CLEAR_SCREEN								(0x01)
#define LCD_CMD_ENTRY_MODE									(0x06)
#define LCD_CMD_SET_CGRAM_ADDRESS							(0x40)
#define LCD_CMD_SET_DDRAM_ADDRESS							(0x80)




#endif /* LCD_DRIVER_LCD_INERFACE_H_ */

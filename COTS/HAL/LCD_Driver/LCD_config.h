/*
 * lcd_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Kero
 */

#ifndef LCD_DRIVER_LCD_CONFIG_H_
#define LCD_DRIVER_LCD_CONFIG_H_


//#define F_CPU 8000000UL


#define LCD_PORT		 	DIO_PORTD
#define DataDir_LCD_PORT 	DIO_PORTD

#define LCD_CTRL 		 	DIO_PORTD
#define DataDir_LCD_CTRL	DIO_PORTD

#define RS_SWITCH 			DIO_PIN2
#define RW_SWITCH 			DIO_PIN1
#define EN_SWITCH 			DIO_PIN3


//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#endif /* LCD_DRIVER_LCD_CONFIG_H_ */

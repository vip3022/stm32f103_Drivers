/*
 * stm32f103_LCD_16x2.h
 *
 *  Created on: 24-Dec-2020
 *      Author: vipulgupta
 */

#ifndef INC_STM32F103_LCD_16X2_H_
#define INC_STM32F103_LCD_16X2_H_

/*
 * including all the important headerFiles
 */

#include <stm32f103.h>
#include <stdint.h>
#include <string.h>
#include <GPIO_Drivers.h>

/***** Structure to give all the pins ********/

/*
 * member 1:- configPort(port in which RS,RW and en are connected)
 * member 2:- en (pin number of en)
 * member 3:- RS (pin number of RS)
 * member 4:- RW (pin number of RW)
 * member 5:- dataPort(port in which d0,d1,d2,d3,d4,d5,d6 and d7 are connected)
 * member 6-13:- d0-d7 (pin numbers of d0-d7)
 */

typedef struct {
	GPIO_RegDef_t* configPort;
	uint8_t en;
	uint8_t RS;
	uint8_t RW;
	GPIO_RegDef_t* dataPort;
	uint8_t d[8];
}LCD;

/****** Prototypes of each function in the .c file *******/

void LCD_INIT(LCD *lcd);
void LCD_Clear(LCD *lcd);
void LCD_Write(LCD *lcd, char msg[]);
void LCD_PrintChar(LCD *lcd,uint8_t alpha);
void LCD_ShiftCursor(void);


#endif /* INC_STM32F103_LCD_16X2_H_ */

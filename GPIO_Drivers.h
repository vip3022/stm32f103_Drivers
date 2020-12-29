/*
 * GPIO_Drivers.h
 *
 *  Created on: 22-Dec-2020
 *      Author: vipulgupta
 */

#ifndef INC_GPIO_DRIVERS_H_
#define INC_GPIO_DRIVERS_H_

/*
 * including all the important headerFiles
 */

#include <stm32f103.h>
#include <string.h>
#include <stdint.h>

/******function prototypes*****/

void GPIO_INIT(GPIO_RegDef_t* GPIOx, uint8_t pinNum, uint8_t mode, uint8_t config);
void GPIO_OUTPUT(GPIO_RegDef_t* GPIOx, uint8_t pinNum,uint8_t state);


/************defining the macros for MODE_GPIO************/

#define Input							0
#define Output_10MHz					1
#define Output_2MHz						2
#define Output_50MHz					3

/*#######defining the macros for CONFIGURATION_GPIO*******/

/***output***/

#define GPO_PushPull					0
#define GPO_OpenDrain					1
#define AFO_PushPull					2
#define AFO_OpenDrain					3

/***input***/

#define AnalogMode						0
#define FloatingInput 					1
#define InputPushPull					2

/*****High/Low/Set/Reset macros******/

#define HIGH							1
#define LOW								0
#define SET								1
#define RESET							0
#define enable							1
#define disable							0


#endif /* INC_GPIO_DRIVERS_H_ */

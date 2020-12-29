/*
 * GPIO_Driver.c
 *
 *  Created on: 23-Dec-2020
 *      Author: vipulgupta
 */

#include <GPIO_Drivers.h>

/*
 * function name:- 	GPIO_INIT
 * description:- 	initializing the the GPIO pin
 * parameter1:- 	GPIOx(structure GPIOx port's registers)
 * parameter2:- 	pinNum(pin number of the pin to configure)
 * parameter3:-		mode(input/output)
 * parameter4:- 	config(confifuration)
 */

void GPIO_INIT(GPIO_RegDef_t* GPIOx, uint8_t pinNum, uint8_t mode, uint8_t config){

	if(pinNum<=7){
		GPIOx->CRL &= ~(0b1111<<(4*pinNum)); 									/****** clear the 4 bits of that pin*******/
		GPIOx->CRL |= (mode<<(4*pinNum))|(config<<(4*pinNum +2));				/****** modifying the 4 bits*******/
	}
	else{
		pinNum -= 8;															/****** adjusting the pinNum for CRH******/
		GPIOx->CRH &= ~(0b1111<<(4*pinNum));									/****** clear the 4 bits of that pin*******/
		GPIOx->CRH |= (mode<<(4*pinNum))|(config<<(4*pinNum +2));
	}
}

/*
 * function name:- 	GPIO_OUTPUT
 * description:- 	to make a pin HIGH/LOW
 * parameter1:- 	GPIOx(structure GPIOx port's registers)
 * parameter2:-		pinNum(pin number of the pin to configure)
 * parameter3:-		state(HIGH/LOW)
 */

void GPIO_OUTPUT(GPIO_RegDef_t* GPIOx, uint8_t pinNum,uint8_t state){

	if(state == 1){
		GPIOx->ODR |= (1<<pinNum);												/****** Setting the BSRR register*****/
	}
	else{
		GPIOx->ODR &= ~(1<<pinNum);												/****** Resetting the BSRR register*****/
	}
}








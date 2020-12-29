/*
 * SPI_Drivers.c
 *
 *  Created on: 27-Dec-2020
 *      Author: vipulgupta
 */

#include <SPI_Drivers.h>

/*
 * function name:- 	SPI_INIT
 * description:- 	initialising the the SPI peripheral
 * parameter1:- 	*SPI_config(parameters to configure the SPI peripheral)
 */

void SPI_INIT(SPI_config_t* SPI_config){

	/**** preScaler for the clock ****/

	uint16_t tempVar = SPI_config->preScaler << 3;
	SPI_config->SPIx->CR1 |= tempVar;

	/**** clock polarity ****/

	if(SPI_config->CPOL == 1)SPI_config->SPIx->CR1 |= (1<<1);
	else SPI_config->SPIx->CR1 &= ~(1<<1);

	/**** clock phase ****/

	if(SPI_config->CPHA == 1)SPI_config->SPIx->CR1 |= (1<<0);
	else SPI_config->SPIx->CR1 &= ~(1<<0);

	/**** data frame format ****/

	if(SPI_config->dff16_8 == 1)SPI_config->SPIx->CR1 |= (1<<11);
	else SPI_config->SPIx->CR1 &= ~(1<<11);

	/**** msb or lsb configuration ****/

	if(SPI_config->frameFormat == 1)SPI_config->SPIx->CR1 |= (1<<7);
	else SPI_config->SPIx->CR1 &= ~(1<<7);

	/**** enabling half or full duplex ****/

	if(SPI_config->HDFD==1)SPI_config->SPIx->CR1 |= (1<<15);
	else SPI_config->SPIx->CR1 &= ~(1<<15);

	/**** Receive only and transmit only for half duplex ****/

	if(SPI_config->TxRxOnly == 1)SPI_config->SPIx->CR1 |= (1<<14);
	else SPI_config->SPIx->CR1 &= ~(1<<14);


	/**** software slave management ****/

	if(SPI_config->SSM ==1)SPI_config->SPIx->CR1 |= (1<<9);
	else SPI_config->SPIx->CR1 &= ~(1<<9);

	/**** turn SSOE to high for master and low for slave ****/

	if(SPI_config->masterSlave==1)SPI_config->SPIx->CR2 |= (1<<2);
	else SPI_config->SPIx->CR2 &= ~(1<<2);

	/**** master or slave ****/

	if(SPI_config->masterSlave == 1)SPI_config->SPIx->CR1 |= (1<<2);
	else SPI_config->SPIx->CR1 &= ~(1<<2);


}

/*
 * function name:- 	SPI_SSOE
 * description:- 	toggeling the SSOE
 * parameter1:- 	*SPI_config(parameters to configure the SPI peripheral)
 */

void SPI_SSOE(SPI_config_t* SPI_config){

	SPI_config->SPIx->CR2 |= (1<<2);
	SPI_config->SPIx->CR2 &= ~(1<<2);

}

/*
 * function name:- 	SPI_MasterWrite
 * description:- 	initialising the the SPI peripheral
 * parameter1:- 	*SPI_config(parameters to configure the SPI peripheral)
 */

void SPI_MasterWrite(SPI_RegDef_t* SPIx, uint8_t msg){

	while(!(SPI_FlagStatus(SPIx,TxEmptyFlag)));
	SPIx->DR = msg;

}

uint8_t SPI_FlagStatus(SPI_RegDef_t* SPIx, uint8_t flag){

	uint8_t tempVar = (SPIx->SR >> flag) & 0x01;
	return tempVar;

}

uint8_t SPI_SlaveRecieve(SPI_RegDef_t *SPIx){

	while(!(SPI_FlagStatus(SPIx,RxNotEmptyFlag)));
	uint8_t tempVar = SPIx->DR;
	return tempVar;

}

void SR_read(SPI_RegDef_t *SPIx){
	uint32_t a = SPIx->SR;
	(void)a;
}

void SPI_de(SPI_RegDef_t *SPIx){
	SPIx->CR1 &= (1<<6);
}

void SPI_en(SPI_RegDef_t *SPIx){
	SPIx->CR1 |= (1<<6);
}









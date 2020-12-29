/*
 * SPI_Drivers.h
 *
 *  Created on: 27-Dec-2020
 *      Author: vipulgupta
 */

#ifndef INC_SPI_DRIVERS_H_
#define INC_SPI_DRIVERS_H_

/**** including important drivers *****/

#include <GPIO_Drivers.h>

/***** macros for configuration SPI peripheral ****/

#define fullDuplex							0
#define halfDuplex							1

#define RxOnly								0
#define TxOnly								1

#define dff8								0
#define dff16								1

#define MSB									0
#define LSB									1

#define preScaler_2							0
#define preScaler_4							1
#define preScaler_8							2
#define preScaler_16						3
#define preScaler_32						4
#define preScaler_64						5
#define preScaler_128						6
#define preScaler_256						7

#define master								1
#define slave								0

/**** macros for flags in status register ****/

#define BusyFlag							7
#define OverRunFlag							6
#define ModeFlautFlag						5
#define CRC_ErrorFlag						4
#define UnderRunFlag						3
#define ChannelSideFlag						2
#define TxEmptyFlag							1
#define RxNotEmptyFlag						0


/**** structure defination for configuration of SPI ****/

/*
 * member 1:- *SPIx(structure of registers of SPIx)
 * member 2:- HDFD(half duplex and full duplex)
 * member 3:- TxRxOnly(for half duplex)
 * member 4:- dff16_8(16 bit data frame or 8 bit)
 * member
 */

typedef struct{
	SPI_RegDef_t* SPIx;
	uint8_t HDFD;
	uint8_t	TxRxOnly;
	uint8_t dff16_8;
	uint8_t SSM;
	uint8_t SSI;
	uint8_t frameFormat;
	uint8_t	SPI_en;
	uint8_t preScaler;
	uint8_t masterSlave;
	uint8_t CPOL;
	uint8_t CPHA;

}SPI_config_t;

/**** prototypes of the functions in .c files ****/

void SPI_INIT(SPI_config_t* SPI_config);
void SPI_SSOE(SPI_config_t* SPI_config);
void SPI_MasterWrite(SPI_RegDef_t* SPIx, uint8_t msg);
uint8_t SPI_FlagStatus(SPI_RegDef_t* SPIx, uint8_t flag);
uint8_t SPI_SlaveRecieve(SPI_RegDef_t* SPIx);
void SR_read(SPI_RegDef_t *SPIx);
void SPI_de(SPI_RegDef_t *SPIx);
void SPI_en(SPI_RegDef_t *SPIx);


#endif /* INC_SPI_DRIVERS_H_ */

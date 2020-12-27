/*
 * stm32f103.h
 *
 *  Created on: Oct 27, 2020
 *      Author: vipulgupta
 */

#ifndef INC_STM32F103_H_
#define INC_STM32F103_H_

#include <stdint.h>
#define __v volatile

/* initializing the NVIC base address */

#define NVIC_BASE_addr					(0xE000E100U)

/* NVIC registers(processor specific) */

typedef struct
{
	uint32_t   ISER[8];     /* Address offset: 0x000 - 0x01C */
	uint32_t  RES0[24];     /* Address offset: 0x020 - 0x07C */
	uint32_t   ICER[8];     /* Address offset: 0x080 - 0x09C */
	uint32_t  RES1[24];     /* Address offset: 0x0A0 - 0x0FC */
	uint32_t   ISPR[8];     /* Address offset: 0x100 - 0x11C */
	uint32_t  RES2[24];     /* Address offset: 0x120 - 0x17C */
	uint32_t   ICPR[8];     /* Address offset: 0x180 - 0x19C */
	uint32_t  RES3[24];     /* Address offset: 0x1A0 - 0x1FC */
	uint32_t   IABR[8];     /* Address offset: 0x200 - 0x21C */
	uint32_t  RES4[56];     /* Address offset: 0x220 - 0x2FC */
	uint8_t   IPR[240];     /* Address offset: 0x300 - 0x3EC */
	uint32_t RES5[644];     /* Address offset: 0x3F0 - 0xEFC */
	uint32_t      STIR;    /* Address offset:         0xF00 */
} NVIC_RegDef_t;

/* initialization of main memories */

#define Flash_base_addr 				0x08000000U				/* flash base address*/
#define SRAM1_base_addr 				0x20000000U				/* SRAM1 base address*/
#define SRAM 							SRAM1_base_addr			/* SRAM base address*/
#define ROM								0x1FFFF000U				/* ROM base address*/

/* initialization of all buses */

#define Peripheral_base 				0x40000000U				/* peripheral bus base address*/
#define APB1_base						Peripheral_base			/* APB1 base address*/
#define APB2_base						0x40010000U				/* APB2 base address*/
#define AHB_base						0x40018000U				/* AHB base address*/

/* initialization of APB2 peripherals */

#define GPIOA_addr						(APB2_base + 0x0800)	/* GPIOA base address using offset*/
#define GPIOB_addr						(APB2_base + 0x0C00)	/* GPIOB base address using offset*/
#define GPIOC_addr						(APB2_base + 0x1000)	/* GPIOC base address using offset*/
#define GPIOD_addr						(APB2_base + 0x1400)	/* GPIOD base address using offset*/
#define GPIOE_addr						(APB2_base + 0x1800)	/* GPIOE base address using offset*/
#define GPIOF_addr						(APB2_base + 0x1C00)	/* GPIOF base address using offset*/
#define GPIOG_addr						(APB2_base + 0x2000)	/* GPIOG base address using offset*/
#define SPI1_addr						(APB2_base + 0x3000)	/* SPI1 base address using offset*/
#define USART1_addr						(APB2_base + 0x3800)	/* USART1 base address using offset*/
#define EXTI_addr						(APB2_base + 0x0400)	/* EXTI base address using offset*/
#define AFIO_addr						(APB2_base + 0x0000)	/* AFIO peripheral*/

/* initialization of APB1 peripherals */

#define I2C1_addr						(APB1_base + 0x5400)	/* I2C1 base address using offset*/
#define I2C2_addr						(APB1_base + 0x5800)	/* I2C1 base address using offset*/
#define SPI2_addr						(APB1_base + 0x3800)	/* I2C1 base address using offset*/
#define SPI3_addr						(APB1_base + 0x3C00)	/* I2C1 base address using offset*/
#define USART2_addr						(APB1_base + 0x4400)	/* USART2 base address using offset*/
#define USART3_addr						(APB1_base + 0x4800)	/* USART3 base address using offset*/
#define UART4_addr						(APB1_base + 0x4C00)	/* UART4 base address using offset*/
#define UART5_addr						(APB1_base + 0x5000)	/* UART5 base address using offset*/

/*initialization of AHB peripherals */

#define RCC_base_addr					 0x40021000U

/* macros for all GPIOs*/

#define GPIOA 							((GPIO_RegDef_t*)GPIOA_addr)
#define GPIOB 							((GPIO_RegDef_t*)GPIOB_addr)
#define GPIOC 							((GPIO_RegDef_t*)GPIOC_addr)
#define GPIOD 							((GPIO_RegDef_t*)GPIOD_addr)
#define GPIOE 							((GPIO_RegDef_t*)GPIOE_addr)
#define GPIOF 							((GPIO_RegDef_t*)GPIOF_addr)
#define GPIOG 							((GPIO_RegDef_t*)GPIOG_addr)

/* macros for RCC_peripheral*/

#define RCC 							((RCC_RegDef_t*)RCC_base_addr)

/*macros for interrupts*/

#define AFIO							((AFIO_RegDef_t*)AFIO_addr)
#define EXTI 							((EXTI_RegDef_t*)EXTI_addr)
#define NVIC							((NVIC_RegDef_t*)NVIC_BASE_addr)

/* macros for initializing SPI */

#define SPI1							((SPI_RegDef_t*)SPI1_addr)
#define SPI2							((SPI_RegDef_t*)SPI2_addr)
#define SPI3							((SPI_RegDef_t*)SPI3_addr)

/* macros for I2C*/
#define I2C1							((I2C_RegDef_t*)I2C1_addr)
#define I2C2							((I2C_RegDef_t*)I2C2_addr)

/* structure for all registers under all GPIO pins */

typedef struct{

	__v uint32_t CRL;					/* Port configuration register low pin(0-7)  */
	__v uint32_t CRH;					/* Port configuration register high pin(8-15) */
	__v uint32_t IDR;					/* Port input data register */
	__v uint32_t ODR;					/* Port output data register */
	__v uint32_t BSRR;					/* Port bit set/reset register*/
	__v uint32_t BRR;					/* Port bit reset register*/
	__v uint32_t LCKR;					/* Port configuration lock register */

}GPIO_RegDef_t;

/* RCC registers*/

typedef struct{

	__v uint32_t CR;					/*Clock control register*/
	__v uint32_t CFGR;					/*Clock configuration register*/
	__v uint32_t CIR;					/*Clock interrupt register*/
	__v uint32_t APB2RSTR;				/*APB2 peripheral reset register*/
	__v uint32_t APB1RSTR;				/*APB1 peripheral reset register*/
	__v uint32_t AHBENR;				/*AHB peripheral clock enable register*/
	__v uint32_t APB2ENR;				/*APB2 peripheral clock enable register*/
	__v uint32_t APB1ENR;				/*APB1 peripheral clock enable register*/
	__v uint32_t RCC_BDCR;				/*Backup domain control register*/
	__v uint32_t CSR;					/*Control/status register*/

}RCC_RegDef_t;

/* registers of AFIO*/

typedef struct{

	__v uint32_t EVCR;
	__v uint32_t MAPR;
	__v uint32_t EXTICR1;
	__v uint32_t EXTICR2;
	__v uint32_t EXTICR3;
	__v uint32_t EXTICR4;
	__v uint32_t MAPR2;

}AFIO_RegDef_t;

/* registers of EXTI*/

typedef struct{

	__v uint32_t IMR;
	__v uint32_t EMR;
	__v uint32_t RTSR;
	__v uint32_t FTSR;
	__v uint32_t SWIER;
	__v uint32_t PR;

}EXTI_RegDef_t;

/* register of SPIx*/

typedef struct{

	__v uint32_t CR1;
	__v uint32_t CR2;
	__v uint32_t SR;
	__v uint32_t DR;
	__v uint32_t CRCPR;
	__v uint32_t RXCRCR;
	__v uint32_t TXCRCR;
	__v uint32_t I2SCFGR;
	__v uint32_t I2SPR;

}SPI_RegDef_t;

/* registers for I2C*/

typedef struct{

	__v uint32_t CR1;
	__v uint32_t CR2;
	__v uint32_t OAR1;
	__v uint32_t OAR2;
	__v uint32_t DR;
	__v uint32_t SR1;
	__v uint32_t SR2;
	__v uint32_t CCR;
	__v uint32_t TRISE;

}I2C_RegDef_t;

/* clock enable macros for GPIOx*/

#define GPIOA_PC_en() 					(RCC -> APB2ENR |= (1<<2))
#define GPIOB_PC_en() 					(RCC -> APB2ENR |= (1<<3))
#define GPIOC_PC_en() 					(RCC -> APB2ENR |= (1<<4))
#define GPIOD_PC_en() 					(RCC -> APB2ENR |= (1<<5))
#define GPIOE_PC_en() 					(RCC -> APB2ENR |= (1<<6))
#define GPIOF_PC_en() 					(RCC -> APB2ENR |= (1<<7))
#define GPIOG_PC_en() 					(RCC -> APB2ENR |= (1<<8))

/* clock disable macros for GPIOx*/

#define GPIOA_PC_di() 					(RCC -> APB2ENR &= ~(1<<2))
#define GPIOB_PC_di() 					(RCC -> APB2ENR &= ~(1<<3))
#define GPIOC_PC_di() 					(RCC -> APB2ENR &= ~(1<<4))
#define GPIOD_PC_di() 					(RCC -> APB2ENR &= ~(1<<5))
#define GPIOE_PC_di() 					(RCC -> APB2ENR &= ~(1<<6))
#define GPIOF_PC_di() 					(RCC -> APB2ENR &= ~(1<<7))
#define GPIOG_PC_di() 					(RCC -> APB2ENR &= ~(1<<8))

/* clock enable macros for I2Cx*/

#define I2C1_PC_en()					(RCC -> APB1ENR |= (1<<21))
#define I2C2_PC_en()					(RCC -> APB1ENR |= (1<<22))

/* macros for AFIO clock enable*/

#define AFIO_PC_en()					(RCC -> APB2ENR |= (1<<0))

/* macros for clock enabling SPI*/

#define SPI1_PC_en()						(RCC-> APB2ENR |= (1<<12));
#define SPI2_PC_en()						(RCC-> APB1ENR |= (1<<14));
#define SPI3_PC_en()						(RCC-> APB1ENR |= (1<<15));



#endif /* INC_STM32F103_H_ */

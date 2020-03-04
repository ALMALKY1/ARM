/*
 * GPIO_HW.h
 *
 *  Created on: Feb 6, 2020
 *      Author: ALMALKY
 */



#ifndef MCAL_GPIO_INC_GPIO_HW_H_
#define MCAL_GPIO_INC_GPIO_HW_H_
#include<stdint.h>


// BASE Adress for PORTS

#define PORTA_BASE 0x40004000
#define PORTB_BASE 0x40005000
#define PORTC_BASE 0x40006000
#define PORTD_BASE 0x40007000
#define PORTE_BASE 0x40024000
#define PORTF_BASE 0x40025000


// Offset

#define GPIO_DATA  0x000
#define GPIO_DIR  0x400
#define GPIO_AFSEL 0x420
#define GPIO_PUR 0x510
#define GPIO_LOCK 0x520
#define GPIO_AMSEL 0x528
#define GPIO_DEN 0x51C
#define GPIO_CR 0x524
#define GPIOPCTL 0x52C

#define SYSCTL_RCGC2 (*((volatile uint32_t *)0x400FE108))


typedef volatile uint32_t* const  GPIO_RegAddType;

/*Register memory map*/

#define PORTA_BASE_ADDRESS 0x40004000
#define PORTB_BASE_ADDRESS 0x40005000
#define PORTC_BASE_ADDRESS 0x40006000
#define PORTD_BASE_ADDRESS 0x40007000
#define PORTE_BASE_ADDRESS 0x40024000
#define PORTF_BASE_ADDRESS 0x40025000




static const uint32_t PortsBaseAddressLut[6] =
{   PORTA_BASE_ADDRESS,
    PORTB_BASE_ADDRESS,
    PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS,
    PORTE_BASE_ADDRESS,
    PORTF_BASE_ADDRESS
};


// THE best way

#define GPIO_REG_ADDRESS(PORT_ID,REG_OFFSET)     (PortsBaseAddressLut[PORT_ID] + REG_OFFSET)

#define GPIODATA_WRITE(DATA,MASK,PORT_ID)       *((GPIO_RegAddType)(GPIO_REG_ADDRESS(PORT_ID,0x000) + (MASK << 2))) = DATA

#define GPIO_DATA_READ(MASK,PORT_ID)         *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x000)+(MASK<<2));

#define GPIO_DIR_REG(PORT_ID)                    *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0X400))


/*Interrupt Control*/

#define GPIOIS_REG(PORT_ID)               *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x404))
#define GPIOIBE_REG(PORT_ID)              *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x408))
#define GPIOIEV_REG(PORT_ID)              *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x40C))
#define GPIOIM_REG(PORT_ID)               *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x410))
#define GPIORIS_REG(PORT_ID)              *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x414))
#define GPIOMIS_REG(PORT_ID)              *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x418))
#define GPIOICR_REG(PORT_ID)              *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x41C))


/*Mode Control*/
#define GPIOAFSEL_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x420))
#define GPIOPCTL_REG(PORT_ID)             *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x52C))
#define GPIOADCCTL_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x530))
#define GPIODMACTL_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x534))



/*Pad control*/
#define GPIODR2R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x500))
#define GPIODR4R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x504))
#define GPIODR8R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x508))
#define GPIOODR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x50C))
#define GPIOPUR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x510))
#define GPIOPDR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x514))
#define GPIOSLR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x518))
#define GPIODEN_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x51C))
#define GPIOAMSEL_REG(PORT_ID)          *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x528))


/*Commit control*/
#define GPIOLOCK_REG(PORT_ID)          *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x520))
#define GPIOCR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x524))



#define GPIO_UNLCOK_VALUE  0x4C4F434B





#endif /* MCAL_GPIO_INC_GPIO_HW_H_ */

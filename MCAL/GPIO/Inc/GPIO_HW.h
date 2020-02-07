/*
 * GPIO_HW.h
 *
 *  Created on: Feb 6, 2020
 *      Author: MELMA
 */

#ifndef MCAL_GPIO_INC_GPIO_HW_H_
#define MCAL_GPIO_INC_GPIO_HW_H_

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

#define SYSCTL_RCGC2 (*((volatile unsigned long int *)0x400FE108))

#define PIN0  0
#define PIN0  1
#define PIN0  2
#define PIN0  3
#define PIN0  4
#define PIN0  5
#define PIN0  6
#define PIN0  7



#endif /* MCAL_GPIO_INC_GPIO_HW_H_ */

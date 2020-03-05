/*
 * Clock_confg.h
 *
 *  Created on: Mar 5, 2020
 *      Author: ALMALKY
 */

#ifndef MCAL_CLOCK_CLOCK_CONFG_H_
#define MCAL_CLOCK_CLOCK_CONFG_H_
#include <stdint.h>


#define BASE_Address_of_clock(offset)    (*((volatile uint32_t *)0x400FE000+offset))

#define SYSCTL_RCC      (BASE_Address_of_clock(0x060))
#define SYSCTL_RCC_2    BASE_Address_of_clock(0x070)
#define SYS_RIS         (BASE_Address_of_clock(0x050))

void SYS_CLOK(void);

#endif /* MCAL_CLOCK_CLOCK_CONFG_H_ */

/*
 * TIMER.c
 *
 *  Created on: Mar 6, 2020
 *      Author: ALMALKY
 */

#ifndef MCAL_TIMER_32_SRC_TIMER_C_
#define MCAL_TIMER_32_SRC_TIMER_C_

#include <MCAL/TIMER_32/inc/TIMER.h>

void TIMER_Init (void){
//Enable The clock to Block
    SYS_RCGC_TIMER |=(1<<0);

// Disable timer to configuration
    GPTM_CTL &=~(1<<0);
// select 32-BIT to count 80000000 for 1sec in 80MHZ

    GPTM_CFG = 0x00000000;
// select 1-periodic mode 2- count UP
    GPTM_TAMR = 0x00000002;
    GPTM_TAMR |= 0x00000010;

// set interval load register value 80MHZ

    GPTM_TAILR = 0x04C4B400 ;

// Clear Timer flag

    GPTM_ICR |=(1<<0);
//Enable Timer
    GPTM_CTL |=(1<<0);

    }

    /* write this in main function TASK In 1 sec in 80MHZ
     *
     * wait to time out flag to set (plling)
     * if (GTM_RIS&0x00000001)==1)
     * {
     *    TASK .
     *    ..
     *    .
     *    ..
     *    ..
     *    ....
     *
     *    //Clear FLAG
     *
     *    GTM_TCR |= (1<<0);
     *
     *  }
     */
#endif /* MCAL_TIMER_32_SRC_TIMER_C_ */

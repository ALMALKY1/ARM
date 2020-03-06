/*
 * TMER.h
 *
 *  Created on: Mar 6, 2020
 *      Author: ALMALKY
 */

#ifndef MCAL_TIMER_32_INC_TIMER_H_
#define MCAL_TIMER_32_INC_TIMER_H_


#define     SYS_RCGC_TIMER       (*((volatile unsigned long *)0x400FE004))
#define     GPTM_CTL             (*((volatile unsigned long *)0x4003000C))
#define     GPTM_CFG             (*((volatile unsigned long *)0x40030000))
#define     GPTM_TAMR            (*((volatile unsigned long *)0x40030004))
#define     GPTM_TAILR           (*((volatile unsigned long *)0x40030028))
#define     GPTM_RIS             (*((volatile unsigned long *)0x4003001C))
#define     GPTM_ICR             (*((volatile unsigned long *)0x40030024))


void TIMER_Init (void);


#endif /* MCAL_TIMER_32_INC_TIMER_H_ */

/*
 * Clock.c
 *
 *  Created on: Mar 5, 2020
 *      Author: ALMALKY
 */
#include <MCAL/Clock/inc/CLOCK.h>



// Active advanced mode of RCC2
void SYS_CLOK(void){

SYSCTL_RCC_2 |= 0x80000000 ;

// BYPASS GAT
SYSCTL_RCC_2 |= 0x00000800 ;

//Select crystal  Clear then assign 16MHZ
SYSCTL_RCC_2 = (SYSCTL_RCC_2 &~ 0x000007c0)+(0x00000540);

//main oScilator

SYSCTL_RCC_2 &=~ 0x00000070;


//Active  PLL by cleaning PWRDN

SYSCTL_RCC_2 &=~ 0x00002000;

//select DIv400

SYSCTL_RCC_2 |=0x40000000;

//Active Div2
SYSCTL_RCC_2 = (SYSCTL_RCC_2 & ~ 0x1fc00000)+(4<<22);

//flag stable

while((SYS_RIS & 0x00000040)==0);

//Enable BYPass

SYSCTL_RCC_2  &=~ 0x00000800;


}

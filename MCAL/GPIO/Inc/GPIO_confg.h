/*
 * GPIO_confg.h
 *
 *  Created on: Feb 6, 2020
 *      Author: MELMA
 */
#ifndef MCAL_GPIO_INC_GPIO_CONFG_H_
#define MCAL_GPIO_INC_GPIO_CONFG_H_
#include "GPIO_HW.h"
#include "stdint.h"

typedef enum {
    GPIO_INPUT ,
    GPIO_OUTPUT ,
}enum_direction;

typedef enum {
    GPIO_LOW ,
    GPIO_HIGH ,
}enum_pin_value ;

typedef enum {
    PORTA = PORTA_BASE ,
    PORTB = PORTB_BASE ,
    PORTC = PORTC_BASE ,
    PORTD = PORTD_BASE ,
    PORTE = PORTE_BASE ,
    PORTF = PORTF_BASE ,
}enum_PORT;


void GPIO_INIT(enum_PORT port);

void Set_Pin_Direction (enum_PORT port  , uint8_t pin , enum_direction Direction) ;
void Set_PORT_Direction(enum_PORT port ,enum_direction direction );

uint8_t Read_PORT(enum_PORT port);
uint8_t Read_pin(enum_PORT, uint8_t pin );

void Write_Port(enum_PORT port , uint8_t value );
void write_pin(enum_PORT port , uint8_t pin , enum_pin_value value );



#endif /* MCAL_GPIO_INC_GPIO_CONFG_H_ */

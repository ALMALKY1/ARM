/*
 * GPIO_confg.h
 *
 *  Created on: Feb 6, 2020
 *      Author: MELMA
 */
#ifndef MCAL_GPIO_INC_GPIO_CONFG_H_
#define MCAL_GPIO_INC_GPIO_CONFG_H_
#include <MCAL/GPIO/Inc/GPIO_Hw.h>
#include <stdint.h>


typedef enum {
    GPIO_INPUT ,
    GPIO_OUTPUT ,
}enum_direction;

typedef enum {
    GPIO_LOW ,
    GPIO_HIGH ,
}enum_pin_value;

typedef enum PORT {
    PORT_A= PORTA_BASE ,
    PORT_B = PORTB_BASE ,
    PORT_C= PORTC_BASE ,
    PORT_D= PORTD_BASE ,
    PORT_E = PORTE_BASE ,
    PORT_F= PORTF_BASE
}struct_PORT;


void GPIO_INIT(struct_PORT port);

void Set_Pin_Direction (struct_PORT port  , uint8_t pin , enum_direction Direction) ;
void Set_PORT_Direction(struct_PORT port ,enum_direction direction );
uint8_t Read_pin(struct_PORT port , uint8_t MASK);

void Write_Port(struct_PORT port , uint8_t value ,uint8_t MASK);
void write_pin(struct_PORT port , uint8_t MASK , enum_pin_value value);



#endif /* MCAL_GPIO_INC_GPIO_CONFG_H_ */

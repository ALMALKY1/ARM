/*
 * Bit_op.h
 *
 *  Created on: Feb 6, 2020
 *      Author: MALMALY
 */

#ifndef COMMON_BIT_OP_H_
#define COMMON_BIT_OP_H_

#define Get_Bit(Reg,Bit) ((Reg>>Bit)& 0x01)
#define Clear_Bit(Reg,Bit)  Reg &= ~(1<<Bit)
#define Set_Bit(Reg,Bit)     Reg|=(1<<Bit)
#define Toggle_Bit(Reg,Bit)   Reg ^= (1<<Bit)


#endif /* COMMON_BIT_OP_H_ */

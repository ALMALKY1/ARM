/*
 * GPIO.c
 *
 *  Created on: 4/3/ 2020
 *      Author:  ALMALKY

 */
#include <common/BIT_op.h>
#include <MCAL/GPIO/Inc/GPIO_CONFG.h>
#include <MCAL/GPIO/Inc/GPIO_Hw.h>


void GPIO_INIT(struct_PORT port)
{

    switch (port) {

    case PORT_A :

        Set_Bit(SYSCTL_RCGC2,5);   //ACTIVE CLOCK FOR PORT A

            GPIOLOCK_REG(0) = 0x4C4F434B;
            GPIOCR_REG(0) = 0x1F;
            GPIOAFSEL_REG(0)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(0)= 0x00; //Disable analog on port
            GPIOPCTL_REG(0)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(0)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(0)=0xFFFFFFFF; //Enable digital value


        break;


    case PORT_B :
            Set_Bit(SYSCTL_RCGC2,4); //ACTIVE CLOCK FOR PORT B

            GPIOLOCK_REG(1) = 0x4C4F434B;
            GPIOCR_REG(1) = 0x1F;

            GPIOAFSEL_REG(1)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(1)= 0x00; //Disable analog on port
            GPIOPCTL_REG(1)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(1)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(1)=0xFFFFFFFF; //Enable digital value
            break;

    case PORT_C :
            Set_Bit(SYSCTL_RCGC2,3); //ACTIVE CLOCK FOR PORT C
            GPIOLOCK_REG(2) = 0x4C4F434B;
            GPIOCR_REG(2) = 0x1F;

            GPIOAFSEL_REG(2)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(2)= 0x00; //Disable analog on port
            GPIOPCTL_REG(2)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(2)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(2)=0xFFFFFFFF; //Enable digital value

            break;
    case PORT_D :
            Set_Bit(SYSCTL_RCGC2,2);
            GPIOLOCK_REG(3) = 0x4C4F434B;
            GPIOCR_REG(3) = 0x1F;
            GPIOAFSEL_REG(3)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(3)= 0x00; //Disable analog on port
            GPIOPCTL_REG(3)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(3)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(3)=0xFFFFFFFF; //Enable digital value

            break;
    case PORT_E :
            Set_Bit(SYSCTL_RCGC2,1);
            GPIOLOCK_REG(4) = 0x4C4F434B;
            GPIOCR_REG(4) = 0x1F;
            GPIOAFSEL_REG(4)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(4)= 0x00; //Disable analog on port
            GPIOPCTL_REG(4)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(4)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(4)=0xFFFFFFFF; //Enable digital value

            break;

    case PORT_F :
            Set_Bit(SYSCTL_RCGC2,0);
            GPIOLOCK_REG(5) = 0x4C4F434B;
            GPIOCR_REG(5) = 0x1F;
            GPIOAFSEL_REG(5)=0x00000000; //DISAble alternative function
            GPIOAMSEL_REG(5)= 0x00; //Disable analog on port
            GPIOPCTL_REG(5)=0X00000000; //SELECT FUNCTION
            GPIOPUR_REG(5)=0xFFFFFFF; //ENABLE PULL UP
            GPIODEN_REG(5)=0xFFFFFFFF; //Enable digital value

            break ;
    }






}
void Set_Pin_Direction (struct_PORT port  , uint8_t pin , enum_direction Direction)
{
   switch(port)
   {
   case PORT_A :
           if(Direction == GPIO_OUTPUT)
           {
               Set_Bit((GPIO_DIR_REG(0)),pin);
           }
       else if (Direction == GPIO_INPUT)
           {
               Clear_Bit((GPIO_DIR_REG(0)),pin);
           }
       break;

   case PORT_B :
           if(Direction == GPIO_OUTPUT)
           {
               Set_Bit((GPIO_DIR_REG(1)),pin);
           }
       else if (Direction == GPIO_INPUT)
           {
               Clear_Bit((GPIO_DIR_REG(1)),pin);
           }
       break;

   case PORT_C :
           if(Direction == GPIO_OUTPUT)
           {
               Set_Bit((GPIO_DIR_REG(2)),pin);
           }
       else if (Direction == GPIO_INPUT)
           {
               Clear_Bit((GPIO_DIR_REG(2)),pin);
           }
       break;

   case PORT_D :
           if(Direction == GPIO_OUTPUT)
           {
               Set_Bit((GPIO_DIR_REG(3)),pin);
           }
       else if (Direction == GPIO_INPUT)
           {
               Clear_Bit((GPIO_DIR_REG(3)),pin);
           }
       break;

   case PORT_E :
          if(Direction == GPIO_OUTPUT)
           {
        Set_Bit((GPIO_DIR_REG(4)),pin);
           }
      else if (Direction == GPIO_INPUT)
           {
           Clear_Bit((GPIO_DIR_REG(4)),pin);
           }
       break;

   case PORT_F :
         if(Direction == GPIO_OUTPUT)
       {
        Set_Bit((GPIO_DIR_REG(5)),pin);
       }
       else if (Direction == GPIO_INPUT)
        {
           Clear_Bit((GPIO_DIR_REG(5)),pin);
        }
       break;


   }
}

void Set_PORT_Direction (struct_PORT port  , enum_direction Direction)
{
    switch(port)
    {

    case PORT_A :
        if(Direction == GPIO_INPUT)
        {
           (GPIO_DIR_REG(0))=0X00000000;
        }

        else if (Direction==GPIO_OUTPUT)
        {
            (GPIO_DIR_REG(0))=0XFFFFFFFF;
        }
        break;

    case PORT_B :
        if(Direction == GPIO_INPUT)
            {
               (GPIO_DIR_REG(1))=0X00000000;
            }

            else if (Direction==GPIO_OUTPUT)
            {
                (GPIO_DIR_REG(1))=0XFFFFFFFF;
            }
            break;

    case PORT_C :
        if(Direction == GPIO_INPUT)
            {
               (GPIO_DIR_REG(2))=0X00000000;
            }

            else if (Direction==GPIO_OUTPUT)
            {
                (GPIO_DIR_REG(2))=0XFFFFFFFF;
            }
            break;
    case PORT_D:
        if(Direction == GPIO_INPUT)
            {
               (GPIO_DIR_REG(3))=0X00000000;
            }

            else if (Direction==GPIO_OUTPUT)
            {
                (GPIO_DIR_REG(3))=0XFFFFFFFF;
            }
            break;
    case PORT_E:
        if(Direction == GPIO_INPUT)
            {
               (GPIO_DIR_REG(4))=0X00000000;
            }

            else if (Direction==GPIO_OUTPUT)
            {
                (GPIO_DIR_REG(4))=0XFFFFFFFF;
            }
            break;

    case PORT_F :
            if(Direction == GPIO_INPUT)
            {
               (GPIO_DIR_REG(5))=0X00000000;
            }

            else if (Direction==GPIO_OUTPUT)
            {
                (GPIO_DIR_REG(5))=0XFFFFFFFF;
            }
            break;
    }
}


void write_pin(struct_PORT port , uint8_t MASK , enum_pin_value value)
{

    switch(port)
    {

    case PORT_A :
        if (value == GPIO_HIGH)
        {
            GPIODATA_WRITE(GPIO_HIGH,MASK,0);
        }
        else if (value == GPIO_LOW)
        {
            GPIODATA_WRITE(GPIO_LOW,MASK,0);
        }
        break;

    case PORT_B :

           if (value == GPIO_HIGH)
           {
               GPIODATA_WRITE(GPIO_HIGH,MASK,1);
           }
           else if (value == GPIO_LOW)
           {
               GPIODATA_WRITE(GPIO_LOW,MASK,1);
           }
           break;

    case PORT_C :

           if (value == GPIO_HIGH)
           {
               GPIODATA_WRITE(GPIO_HIGH,MASK,2);
           }
           else if (value == GPIO_LOW)
           {
               GPIODATA_WRITE(GPIO_LOW,MASK,2);
           }
           break;

    case PORT_D :

        if (value == GPIO_HIGH)
             {
                 GPIODATA_WRITE(GPIO_HIGH,MASK,3);
             }
             else if (value == GPIO_LOW)
             {
                 GPIODATA_WRITE(GPIO_LOW,MASK,3);
             }
             break;

    case PORT_E :

        if (value == GPIO_HIGH)
             {
                 GPIODATA_WRITE(GPIO_HIGH,MASK,4);
             }
             else if (value == GPIO_LOW)
             {
                 GPIODATA_WRITE(GPIO_LOW,MASK,4);
             }
             break;

    case PORT_F :
        if (value == GPIO_HIGH)
             {
                 GPIODATA_WRITE(GPIO_HIGH,MASK,5);
             }
             else if (value == GPIO_LOW)
             {
                 GPIODATA_WRITE(GPIO_LOW,MASK,5);
             }
             break;
    }

}


void Write_Port(struct_PORT port , uint8_t value ,uint8_t MASK)
{
    switch(port)
    {
    case PORT_A :
        GPIODATA_WRITE(value,MASK,0);
        break;

    case PORT_B :
        GPIODATA_WRITE(value,MASK,1);

        break;

    case PORT_C :
        GPIODATA_WRITE(value,MASK,2);
            break;
    case PORT_D :
        GPIODATA_WRITE(value,MASK,3);
            break;
    case PORT_E :
        GPIODATA_WRITE(value,MASK,4);
            break;
    case PORT_F :
        GPIODATA_WRITE(value,MASK,5);
            break;
    }
}

uint8_t Read_pin(struct_PORT port , uint8_t MASK)
{
    uint8_t  result = 0 ;
    switch (port)
    {
    case PORT_A :

                result = GPIO_DATA_READ(MASK,0);
                break;
    case PORT_B :
                result = GPIO_DATA_READ(MASK,1);
                break;
    case PORT_C :
                result = GPIO_DATA_READ(MASK,2);
                break;
    case PORT_D :
                result = GPIO_DATA_READ(MASK,3);
                break;
    case PORT_E :
                result = GPIO_DATA_READ(MASK,4);
                break;
    case PORT_F :
                result = GPIO_DATA_READ(MASK,5);
                break;
    }
    return result ;
}


uint8_t Read_PORT(struct_PORT port)
{
    uint32_t result ;

   switch(port)
   {
   case PORT_A :
       result = GPIO_DATA_READ(0xffff,0);
       break;
   case PORT_B :
       result = GPIO_DATA_READ(0xffff,1);
         break;
   case PORT_C :
       result = GPIO_DATA_READ(0xffff,2);
         break;
   case PORT_D :
       result = GPIO_DATA_READ(0xffff,3);
         break;
   case PORT_E :
       result = GPIO_DATA_READ(0xffff,4);
         break;
   case PORT_F :
       result = GPIO_DATA_READ(0xffff,5);
         break;
   }
   return result ;
}







/*
 * GPIO.c
 *
 *  Created on: Feb 6, 2020
 *      Author: Mohamed ALMALKY

 */

#include "GPIO_confg.h"
#include "Bit_op.h"


void GPIO_INIT(enum_PORT port)
{
    switch (port){
    case PORTA :
       Set_Bit(SYSCTL_RCGC2,5);   //ACTIVE CLOCK FOR PORT A
       delay = SYSCTL_RCGC2 ;
       (PORTA_BASE + GPIO_LOCK) = 0x4C4F434B;  //UNLOCK PORTA
       (PORTA_BASE + GPIO_CR) = 0x1F ; //ACTIVE  COMMIT REGITERS

       (PORTA_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
       (PORTA_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
       (PORTA_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
       (PORTA_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
       (PORTA_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value


        break;
    case PORTB :
            Set_Bit(SYSCTL_RCGC2,4); //ACTIVE CLOCK FOR PORT B
            delay = SYSCTL_RCGC2 ;
            (PORTB_BASE + GPIO_LOCK) = 0x4C4F434B;
            (PORTB_BASE + GPIO_CR ) = 0x1F; //ACTIVE  COMMIT REGITERS

            (PORTB_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
            (PORTB_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
            (PORTB_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
            (PORTB_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
            (PORTB_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value


            break;
    case PORTC :
            Set_Bit(SYSCTL_RCGC2,3); //ACTIVE CLOCK FOR PORT C
            delay = SYSCTL_RCGC2;
            (PORTC_BASE + GPIO_LOCK) = 0x4C4F434B;
            (PORTC_BASE + GPIO_CR ) = 0x1F;

            (PORTC_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
            (PORTC_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
            (PORTC_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
            (PORTC_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
            (PORTC_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value

            break;
    case PORTD :
            Set_Bit(SYSCTL_RCGC2,2);
            delay = SYSCTL_RCGC2 ;
            (PORTD_BASE + GPIO_LOCK) = 0x4C4F434B;
            (PORTD_BASE + GPIO_CR ) = 0x1F ;

            (PORTD_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
            (PORTD_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
            (PORTD_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
            (PORTD_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
            (PORTD_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value

            break;
    case PORTE :
            Set_Bit(SYSCTL_RCGC2,1);
            delay = SYSCTL_RCGC2 ;
            (PORTE_BASE + GPIO_LOCK) = 0x4C4F434B;
            (PORTE_BASE + GPIO_CR ) = 0x1F ;

            (PORTE_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
            (PORTE_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
            (PORTE_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
            (PORTE_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
            (PORTE_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value
            break;
    case PORTF :
            Set_Bit(SYSCTL_RCGC2,0);
            delay = SYSCTL_RCGC2 ;
           (PORTE_BASF + GPIO_LOCK) = 0x4C4F434B;
           (PORTE_BASE + GPIO_CR ) = 0x1F;

           (PORTE_BASE+GPIO_AFSEL)=0x00000000; //DISAble alternative function
           (PORTE_BASE+GPIO_AMSEL)= 0x00; //Disable analog on port
           (PORTE_BASE+GPIOPCTL)=0X00000000; //SELECT FUNCTION
           (PORTE_BASE+GPIO_PUR)=0xFFFFFFF; //ENABLE PULL UP
           (PORTE_BASE+GPIO_DEN)=0xFFFFFFFF; //Enable digital value
            break;
    }






}
void Set_Pin_Direction (enum_PORT port  , uint8_t pin , enum_direction Direction)
{
   switch(port)
   {
   case PORTA :
       if(Direction == GPIO_OUTPUT)
       {
           Set_Bit((PORTA_BASE+GPIO_DIR),pin);
       }
       else (Direction ==GPIO_INPUT)
        {
           Clear_Bit(PORTA_BASE=GPIO_DIR,pin);
        }
       break;

   case PORTB :
          if(Direction == GPIO_OUTPUT)
          {
              Set_Bit((PORTB_BASE+GPIO_DIR),pin);
          }
          else (Direction ==GPIO_INPUT)
           {
              Clear_Bit(PORTB_BASE=GPIO_DIR,pin);
           }
          break;
   case PORTC :
            if(Direction == GPIO_OUTPUT)
            {
                Set_Bit((PORTC_BASE+GPIO_DIR),pin);
            }
            else (Direction ==GPIO_INPUT)
             {
                Clear_Bit(PORTC_BASE=GPIO_DIR,pin);
             }
            break;
   case PORTD :
            if(Direction == GPIO_OUTPUT)
            {
                Set_Bit((PORTD_BASE+GPIO_DIR),pin);
            }
            else (Direction ==GPIO_INPUT)
             {
                Clear_Bit(PORTD_BASE=GPIO_DIR,pin);
             }
            break;
   case PORTE :
            if(Direction == GPIO_OUTPUT)
            {
                Set_Bit((PORTE_BASE+GPIO_DIR),pin);
            }
            else (Direction ==GPIO_INPUT)
             {
                Clear_Bit(PORTE_BASE=GPIO_DIR,pin);
             }
            break;

   case PORTF :
            if(Direction == GPIO_OUTPUT)
            {
                Set_Bit((PORTF_BASE+GPIO_DIR),pin);
            }
            else (Direction ==GPIO_INPUT)
             {
                Clear_Bit(PORTF_BASE=GPIO_DIR,pin);
             }
            break;

   }
}

void Set_PORT_Direction (enum_PORT port  , enum_direction Direction)
{
    switch(port)
    {

    case PORTA :
        if(Direction == GPIO_INPUT)
        {
            (PORTA_BASE+GPIO_DIR)=0X00000000;
        }

        else(Direction==GPIO_OUTPUT)
        {
            (PORTA_BASE+GPIO_DIR)=0XFFFFFFFF;
        }
        break;

    case PORTB :
            if(Direction == GPIO_INPUT)
            {
                (PORTB_BASE+GPIO_DIR)=0X00000000;
            }

            else(Direction==GPIO_OUTPUT)
            {
                (PORTB_BASE+GPIO_DIR)=0XFFFFFFFF;
            }
            break;

    case PORTC :
                if(Direction == GPIO_INPUT)
                {
                    (PORTC_BASE+GPIO_DIR)=0X00000000;
                }

                else(Direction==GPIO_OUTPUT)
                {
                    (PORTC_BASE+GPIO_DIR)=0XFFFFFFFF;
                }
                break;
    case PORTD:
                if(Direction == GPIO_INPUT)
                {
                    (PORTD_BASE+GPIO_DIR)=0X00000000;
                }

                else(Direction==GPIO_OUTPUT)
                {
                    (PORTD_BASE+GPIO_DIR)=0XFFFFFFFF;
                }
                break;
    case PORTE:
                if(Direction == GPIO_INPUT)
                {
                    (PORTE_BASE+GPIO_DIR)=0X00000000;
                }

                else(Direction==GPIO_OUTPUT)
                {
                    (PORTE_BASE+GPIO_DIR)=0XFFFFFFFF;
                }
                break;

    case PORTF :
                if(Direction == GPIO_INPUT)
                {
                    (PORTF_BASE+GPIO_DIR)=0X00000000;
                }

                else(Direction==GPIO_OUTPUT)
                {
                    (PORTF_BASE+GPIO_DIR)=0XFFFFFFFF;
                }
                break;
    }
}

void write_pin(enum_PORT port , uint8_t pin , enum_pin_value value )
{
    switch(port)
    {
    case PORTA :
        if (value == GPIO_HIGH)
        {
            Set_Bit((PORTA_BASE+GPIO_DATA),pin);
        }
        else (value == GPIO_LOW)
        {
            Clear_Bit((PORTA_BASE+GPIO_DATA),pin);
        }
        break;

    case PORTB :
           if (value == GPIO_HIGH)
           {
               Set_Bit((PORTB_BASE+GPIO_DATA),pin);
           }
           else (value == GPIO_LOW)
           {
               Clear_Bit((PORTB_BASE+GPIO_DATA),pin);
           }
           break;

    case PORTC :
           if (value == GPIO_HIGH)
           {
               Set_Bit((PORTC_BASE+GPIO_DATA),pin);
           }
           else (value == GPIO_LOW)
           {
               Clear_Bit((PORTC_BASE+GPIO_DATA),pin);
           }
           break;
    case PORTD :
           if (value == GPIO_HIGH)
           {
               Set_Bit((PORTD_BASE+GPIO_DATA),pin);
           }
           else (value == GPIO_LOW)
           {
               Clear_Bit((PORTD_BASE+GPIO_DATA),pin);
           }
           break;
    case PORTE :
           if (value == GPIO_HIGH)
           {
               Set_Bit((PORTE_BASE+GPIO_DATA),pin);
           }
           else (value == GPIO_LOW)
           {
               Clear_Bit((PORTE_BASE+GPIO_DATA),pin);
           }
           break;
    case PORTF :
           if (value == GPIO_HIGH)
           {
               Set_Bit((PORTF_BASE+GPIO_DATA),pin);
           }
           else (value == GPIO_LOW)
           {
               Clear_Bit((PORTF_BASE+GPIO_DATA),pin);
           }
           break;
    }

}


void Write_Port(enum_PORT port , uint8_t value )
{
    switch(port)
    {
    case PORTA :
        (PORTA_BASE+GPIO_DATA)= value;
        break;
    case PORTB :
            (PORTB_BASE+GPIO_DATA)= value;
            break;
    case PORTC :
            (PORTC_BASE+GPIO_DATA)= value;
            break;
    case PORTD :
            (PORTD_BASE+GPIO_DATA)= value;
            break;
    case PORTE :
            (PORTE_BASE+GPIO_DATA)= value;
            break;
    case PORTF :
            (PORTF_BASE+GPIO_DATA)= value;
            break;
    }
}

uint8_t Read_pin(enum_PORT port , uint8_t pin )
{
    uint8_t result = 0  ;

    switch (port)
    {
    case PORTA :
                result = Get_Bit(PORTA_BASE+GPIO_DATA,pin) ;
                break;
    case PORTB :
                result = Get_Bit(PORTB_BASE+GPIO_DATA,pin) ;
                break;
    case PORTC :
                result = Get_Bit(PORTC_BASE+GPIO_DATA,pin) ;
                break;
    case PORTD :
                result = Get_Bit(PORTD_BASE+GPIO_DATA,pin) ;
                break;
    case PORTE :
                result = Get_Bit(PORTE_BASE+GPIO_DATA,pin) ;
                break;
    case PORTF :
                result = Get_Bit(PORTF_BASE+GPIO_DATA,pin) ;
                break;
    }
    return result ;
}


uint8_t Read_PORT(enum_PORT port)
{
    uint32_t result ;

   switch(port)
   {
   case PORTA :
       result = (PORTA_BASE+GPIO_DATA);
       break;
   case PORTB :
         result = (PORTB_BASE+GPIO_DATA);
         break;
   case PORTC :
         result = (PORTC_BASE+GPIO_DATA);
         break;
   case PORTD :
         result = (PORTD_BASE+GPIO_DATA);
         break;
   case PORTE :
         result = (PORTE_BASE+GPIO_DATA);
         break;
   case PORTF :
         result = (PORTF_BASE+GPIO_DATA);
         break;
   }
   return result ;
}







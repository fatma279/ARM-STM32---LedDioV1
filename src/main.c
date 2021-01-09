/*
 * main.c
 *
 *  Created on: august 8, 2020
 *      Author: Fatma
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"DIO_interface.h"

void main(void)
{

RCC_voidInitSysClock();

/*Enable RCC for GPIOA*/
RCC_voidEnableClock( RCC_APB2 , 2);
/*Enable RCC for GPIOB*/
RCC_voidEnableClock( RCC_APB2 , 3);
/*Enable RCC for GPIOC*/
RCC_voidEnableClock( RCC_APB2 , 4);

/*PORTA output push pull  2 MHz*/
GPIO_VoidSetPortDirection(GPIOA, OUTPUT_SPEED_2MHZ_PP);
/*PORTB output push pull  2 MHz*/
GPIO_VoidSetPortDirection(GPIOB, OUTPUT_SPEED_2MHZ_PP);
/*PORTC output push pull  2 MHz*/
GPIO_VoidSetPortDirection(GPIOC, OUTPUT_SPEED_2MHZ_PP);

while(1)
{
	//set all port high
GPIO_VoidSetPortValue(GPIOA,0xffff);
}
}




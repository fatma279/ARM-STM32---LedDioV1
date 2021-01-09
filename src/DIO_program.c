/*
 * DIO_program.c
 *
 *  Created on: Augest 8, 2020
 *      Author: Fatma
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_private.h"
#include"DIO_config.h"

void GPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{//low
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}


void GPIO_VoidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
switch(Copy_u8Port)
{
   case GPIOA :
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOA_ODR , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
		}
		break;

   case GPIOB:
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOB_ODR , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLR_BIT(  GPIOB_ODR , Copy_u8Pin );
		}
		break;
   case GPIOC:
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOC_ODR , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLR_BIT(  GPIOC_ODR , Copy_u8Pin );
		}
		break;
}

}


u8 GPIO_VoidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}


void GPIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode)
{
switch(Copy_u8Port)
{
case GPIOA:

for(int Copy_u8Pin=0; Copy_u8Pin<=7; Copy_u8Pin++)
{

GPIOA_CRL &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOA_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );

GPIOA_CRH &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOA_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );

}
break;
case GPIOB:
for(int Copy_u8Pin=0; Copy_u8Pin<=15; Copy_u8Pin++)
{

GPIOB_CRL &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOB_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );

GPIOB_CRH &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOB_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
}

break;
case GPIOC:
for(int Copy_u8Pin=0; Copy_u8Pin<=15; Copy_u8Pin++)
{

GPIOC_CRL &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOC_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );

GPIOC_CRH &=~( (0b1111) << (Copy_u8Pin*4) );
GPIOC_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
}
break;
}
}


void GPIO_VoidSetPortValue(u8 Copy_u8Port, u16 Copy_u8Value)
{
switch(Copy_u8Port)
{
case GPIOA:
			GPIOA_ODR=Copy_u8Value;
		break;

case GPIOB:
			GPIOB_ODR=Copy_u8Value;
		break;
case GPIOC:
			GPIOC_ODR=Copy_u8Value;
		break;
}
}






/***************************************************/
/* Author  : fatma                                 */
/* Date    : 8 august 2020                         */
/* version : V01                                   */
/***************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options: RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL   */
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL



/*Options: RCC_PLL_IN_HSI_DIV/2
           RCC_PLL_IN_HSE_DIV/2
		   RCC_PLL_IN_HSE         */
/*NOTE: Select value if you have PLL as input clock source */		   
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV/2	
#endif   

/*options: 2 to 16 */
/*NOTE: Select value if you have PLL as input clock source */		   
#if RCC_CLOCK_TYPE 	== RCC_PLL

/*Options: RCC_HSE_CRYSTAL
           RCC_HSE_RC*/
#define RCC_PLL_IN_HSE_TYPE 	RCC_HSE_CRYSTAL
#define RCC_PLL_MUL_VAL   4	
#endif  


#endif

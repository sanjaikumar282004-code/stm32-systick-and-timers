#include "tim2.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>



int main(void)
{
    uart_init();

    tim2_1s_init();


    RCC->AHB1ENR |= (1U<<0);

    GPIOA->MODER  |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);



	while(1)
	{
		//wait for timer overflow
		while( (TIM2->SR & (1U<<0))==0);

		//CLEARING THE OVERFLOW FLAG
		TIM2->SR &= ~(1U<<0);

		//TOGGLING THE LED
		GPIOA->ODR ^= (1U<<5);

		printf("1 second is passed\r\n");
	}

}







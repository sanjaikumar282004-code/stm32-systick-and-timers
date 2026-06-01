#include "tim2.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>



int main(void)
{
    uart_init();

    tim2_10s_interrupt_init();


    RCC->AHB1ENR |= (1U<<0);

    GPIOA->MODER  |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);



	while(1)
	{
		for(int i=0;i<1000000;i++);
		printf("Normal\r\n");
	}

}

static void call_back(void)
{
	//TOGGLING THE LED
	GPIOA->ODR ^= (1U<<5);

	printf("10 second is passed from tim2 interrupt\r\n");

}

void TIM2_IRQHandler(void)
{
	//reset the overflow flag
	TIM2->SR &= ~(1U<<0);

	call_back();
}






#include "systick.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>

volatile uint32_t tick = 0;

int main(void)
{
    uart_init();



    RCC->AHB1ENR |= (1U<<0);

    GPIOA->MODER  |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);

    systick_init();

	while(1)
	{
		for(int i=0;i<1000000;i++);
		printf("Normal...\r\n");
	}

}

static void call_back(void)
{
	printf("Interrupted...\r\n");
	GPIOA->ODR ^= (1U<<5);
}

void SysTick_Handler(void)
{
	if(tick>10)
	{
		tick=0;
		call_back();
	}
	tick++;
}





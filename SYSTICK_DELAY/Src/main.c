#include "systick.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>

int main(void)
{
    uart_init();


	while(1)
	{
		printf("1 second delay\r\n");
		systick_ms(1000);
	}

}




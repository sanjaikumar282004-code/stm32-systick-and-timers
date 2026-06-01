/*
 * tim2.c
 *
 *  Created on: May 21, 2026
 *      Author: sanja
 */

#include "stm32f4xx.h"

void tim2_1s_init(void)
{
	//Enable clock for Timer 2 or APB1ENR
	RCC->APB1ENR |= (1U<<0);

	//SET PRESCALAR VALUE
	TIM2->PSC = 1599;

	//SET ARR or PERIOD VALUE
	TIM2->ARR = 9999;

	//CLEAR THE COUNTING REGISTER
	TIM2->CNT = 0;

	//ENABLE THE COUNTER
	TIM2->CR1 |= (1U<<0);

}



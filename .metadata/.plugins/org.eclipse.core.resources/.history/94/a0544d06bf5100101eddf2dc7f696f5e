#include "stm32l4xx_hal.h"
#include<stdio.h>
#include"uart.h"

int counter;
#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5


uint8_t bStatus;

char message[20] = "Hello from STM32\r\n";

int main()
{
	//add the array which is in screen short
	HAL_Init();
	usart_init();



//USART2 is attached to APB1 bus




	while(1)
	{
		printf("Printf is being used ! \n\r");
		HAL_Delay(10);
	}

}


void SysTick_Handler(void)
{
	HAL_IncTick();
}


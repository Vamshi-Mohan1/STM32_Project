
#include <stdint.h>
#include<stdio.h>
#include "stm32l4xx_hal.h"



void gpio_pc13_interrupt_init(void);
#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5

uint32_t sensor_value;
 ADC_HandleTypeDef hadc1;

int main(void)
{
   HAL_Init();
   usart_init();
   adc_interrupt_conv_init();

   HAL_ADC_Start(&hadc1);

   while(1)
   {
	   	   printf("read data %d  \n\r",(int)sensor_value);
   }

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	sensor_value = pc0_adc_read();
	HAL_ADC_Start(&hadc1);
}



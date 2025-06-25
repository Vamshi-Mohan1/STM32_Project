/*
 * adc.c
 *
 *  Created on: Jun 24, 2025
 *      Author: Vamshi
 */



//Note the ADC1 module is connected to AHB2 bus.

#include "stm32l4xx_hal.h"
#include "adc.h"


ADC_HandleTypeDef hadc1;

//Bus connected to adc1 is AHP2 80 Mhz
//pin is usind PC0 which have ADC1_1 channel.
void adc_cont_conv_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	//ADC_InitTypeDef


	//configure pc0 as analog pin
		__HAL_RCC_GPIOC_CLK_ENABLE();


		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	//config adc modle for ontinuous conversation
		__HAL_RCC_ADC1_CLK_ENABLE();


		hadc1.Instance = ADC1;
		hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
		hadc1.Init.Resolution = ADC_RESOLUTION_12B;
		hadc1.Init.ContinuousConvMode = ENABLE;
		hadc1.Init.DiscontinuousConvMode = DISABLE;
		hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
		hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
		hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
		hadc1.Init.NbrOfConversion = 1;
		hadc1.Init.DMAContinuousRequests = DISABLE;
		hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;


		HAL_ADC_Init(&hadc1);
}

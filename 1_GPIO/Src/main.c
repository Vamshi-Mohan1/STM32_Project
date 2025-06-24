#include "stm32l4xx_hal.h"
int counter;
// push button(BTN is onnecte to PC13
//LED is connectef to PA5 or PB13(user mannual).

//before you uses any module enable clock.
// BUS for both port are AHB2(datasheet)
//To enable AHB2EN bit0 bit 2

#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5


uint8_t bStatus;
int main()
{
	HAL_Init();
	pa5_led_init();
	pc13_btn_init();





	/* Loop forever */
	while(1)
	{
		bStatus=HAL_GPIO_ReadPin(BTN_PORT, BTN_PIN);
		HAL_GPIO_WritePin(LED_PORT, LED_PIN, !bStatus);
		counter++;
	}

}

void pa5_led_init(void)
{
	//1. config PA5 as output pin
	 GPIO_InitTypeDef GPIO_InitStruct={0};
		 __HAL_RCC_GPIOA_CLK_ENABLE();



		GPIO_InitStruct.Pin = LED_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;


		HAL_GPIO_Init (GPIOA, &GPIO_InitStruct );
		//2 config pc13 as input pin
}

void pc13_btn_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct={0};
	 __HAL_RCC_GPIOC_CLK_ENABLE();

			GPIO_InitStruct.Pin = BTN_PIN;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

			HAL_GPIO_Init (GPIOC, &GPIO_InitStruct );
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}


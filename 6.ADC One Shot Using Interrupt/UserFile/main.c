#include "stm8s.h"
#include "mystm8sxxx.h"


void external_interrupt_init();
void adc_single_init();

volatile uint16_t adc_value=0;

void delay(uint32_t time);

void main(void)
{

	clk_config_16MHz_hse();

	/* GPIO Init for LED */
	GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3),GPIO_MODE_OUT_PP_HIGH_FAST);

	external_interrupt_init();

	adc_single_init();

	enableInterrupts();

	while (1)
	{
		GPIO_WriteReverse(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3));
		delay(30000);
	}
}


void external_interrupt_init()
{
	GPIO_Init(GPIOE,GPIO_PIN_0,GPIO_MODE_IN_PU_IT);
	EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOE,EXTI_SENSITIVITY_FALL_ONLY);
}

void adc_single_init()
{
	ADC2_Init(ADC2_CONVERSIONMODE_SINGLE,
			ADC2_CHANNEL_0,
			ADC2_PRESSEL_FCPU_D2,
			ADC2_EXTTRIG_TIM,
			DISABLE,
			ADC2_ALIGN_RIGHT,
			ADC2_SCHMITTTRIG_CHANNEL0,
			DISABLE);
	ADC2_ITConfig(ENABLE);

	ADC2_ITConfig(ENABLE);
}


void delay(uint32_t time)
{
	while(time--);
}








#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8* file, u32 line)
{ 
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

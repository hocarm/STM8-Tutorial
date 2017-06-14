#include "stm8s.h"
#include "mystm8sxxx.h"




void main(void)
{

	clk_config_16MHz_hse();

	GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_OUT_PP_HIGH_FAST);

	TIM2_TimeBaseInit(TIM2_PRESCALER_512,3124);//100ms
	TIM2_ClearFlag(TIM2_FLAG_UPDATE);
	TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);

	enableInterrupts();
	TIM2_Cmd(ENABLE);

	while (1)
	{

	}

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

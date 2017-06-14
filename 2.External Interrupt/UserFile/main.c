#include "stm8s.h"
#include "mystm8sxxx.h"


void delay(uint16_t time);


void main(void)
{
  
  clk_config_16MHz_hse();
  
  /*Config PC1,PC2,PC3,PC4, as output for LED*/
  GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4),GPIO_MODE_OUT_PP_HIGH_FAST);
  
  /*Config PE0,PD0 as input pull up for external interrupt*/
  GPIO_Init(GPIOE,GPIO_PIN_0,GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOD,GPIO_PIN_0,GPIO_MODE_IN_PU_IT);
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOE,EXTI_SENSITIVITY_FALL_ONLY);
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD,EXTI_SENSITIVITY_FALL_ONLY);
  
  /*NOTE: PD7 is TLI, use INTERRUPT_HANDLER(TLI_IRQHandler, 0) */
  
  enableInterrupts();
  
  while (1)
  {
    
  }
  
}


void delay(uint16_t time)
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

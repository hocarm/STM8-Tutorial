#include "stm8s.h"
#include "mystm8sxxx.h"

/*	In this example I will use STM8S003F3 with SPI module to communicate with
	Analog to Digital Converter MCP3204
*/

/* MCU STM8S003F3P6	 		vs 			MCP3204 Chip		
 * PC5 - SPI CLock 		connect to 		CLK (pin 11 of MCP3204)
 * PC6 - SPI MOSI  		connect to		DIN (pin 9 of MCP3204)
 * PC7 - SPI MISO  		connect to 		DOUT pin 10 of MCP3204)
 * PD4 - GPIO CS   		connect to 		CS (pin 8 of MCP3204)
 *
 */

/* Declaring Global Variables */

#define	CS_PORT		GPIOD
#define CS_PIN		GPIO_PIN_4

uint8_t adc_send_data[]={0x06,0x00,0x00};
uint8_t adc_receive_data[3];
volatile uint16_t adc_value;
volatile float voltage=0;

/* Declaring Function Prototype */


void main(void)
{

	clk_config_16MHz_hse();
	delay_using_timer4_init();
	GPIO_Init(CS_PORT,CS_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);

	spi_master_initialize(SPI_BAUDRATEPRESCALER_256);


	while (1)
	{
		spi_master_transmit_receive(CS_PORT,CS_PIN,adc_send_data,adc_receive_data,3);
		adc_value=((adc_receive_data[1]&0x0f)<<8)|(adc_receive_data[2]);
		voltage=(adc_value/4095.0)*4.096;

		delay_ms(500);
	}
}

/* User Function */




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

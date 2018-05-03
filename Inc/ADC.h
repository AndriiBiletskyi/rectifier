#ifndef __ADC_H
#define __ADC_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#define ADC_CLK_1		GPIOC->BSRR = (uint32_t)GPIO_PIN_6 << 16U;//reset
#define ADC_CLK_0		GPIOC->BSRR = GPIO_PIN_6;//set
#define ADC_EN_0		GPIOC->BSRR = GPIO_PIN_7;
#define ADC_EN_1		GPIOC->BSRR = (uint32_t)GPIO_PIN_7 << 16U;
#define ADC_A1_1		GPIOC->BSRR = GPIO_PIN_0;
#define ADC_A1_0		GPIOC->BSRR = (uint32_t)GPIO_PIN_0 << 16U;
#define ADC_A0_1		GPIOC->BSRR = GPIO_PIN_2;
#define ADC_A0_0		GPIOC->BSRR = (uint32_t)GPIO_PIN_2 << 16U;
#define ADC_A2_1		GPIOC->BSRR = GPIO_PIN_8;
#define ADC_A2_0		GPIOC->BSRR = (uint32_t)GPIO_PIN_8 << 16U;
#define BIT1				(GPIOB->IDR & GPIO_PIN_0) != (uint32_t)GPIO_PIN_RESET
#define BIT2				(GPIOB->IDR & GPIO_PIN_1) != (uint32_t)GPIO_PIN_RESET
#define BIT3				(GPIOB->IDR & GPIO_PIN_2) != (uint32_t)GPIO_PIN_RESET
#define BIT4				(GPIOB->IDR & GPIO_PIN_3) != (uint32_t)GPIO_PIN_RESET
#define BIT5				(GPIOB->IDR & GPIO_PIN_4) != (uint32_t)GPIO_PIN_RESET
#define BIT6				(GPIOB->IDR & GPIO_PIN_5) != (uint32_t)GPIO_PIN_RESET
#define BIT7				(GPIOB->IDR & GPIO_PIN_6) != (uint32_t)GPIO_PIN_RESET
#define BIT8				(GPIOB->IDR & GPIO_PIN_7) != (uint32_t)GPIO_PIN_RESET
#define BIT9				(GPIOB->IDR & GPIO_PIN_8) != (uint32_t)GPIO_PIN_RESET
#define BIT10				(GPIOB->IDR & GPIO_PIN_9) != (uint32_t)GPIO_PIN_RESET
#define BIT11				(GPIOB->IDR & GPIO_PIN_10) != (uint32_t)GPIO_PIN_RESET
#define BIT12				(GPIOB->IDR & GPIO_PIN_11) != (uint32_t)GPIO_PIN_RESET
#define BIT13				(GPIOB->IDR & GPIO_PIN_12) != (uint32_t)GPIO_PIN_RESET
#define BIT14				(GPIOB->IDR & GPIO_PIN_13) != (uint32_t)GPIO_PIN_RESET


struct analog_inputs{
	uint16_t first_value;
	uint16_t second_value;
	uint16_t third_value;
	uint16_t fourth_value;
	uint16_t fifth_value;
	uint16_t sixth_value;
	uint16_t seventh_value;
	uint16_t eighth_value;
	int16_t buf_first[16];
	int16_t buf_second[16];
	int16_t buf_third[16];
	int16_t buf_fourth[16];
	int16_t buf_fifth[16];
	int16_t buf_sixth[16];
	int16_t buf_seventh[16];
	int16_t buf_eighth[16];
	int32_t first_average;
	int32_t second_average;
	int32_t third_average;
	int32_t fourth_average;
	int32_t fifth_average;
	int32_t sixth_average;
	int32_t seventh_average;
	int32_t eighth_average;
	int32_t first_all;
	int32_t second_all;
	int32_t third_all;
	int32_t fourth_all;
	int32_t fifth_all;
	int32_t sixth_all;
	int32_t seventh_all;
	int32_t eighth_all;
};
//----------------------------------------------------------------------------------------------------------
uint16_t adc_read(uint8_t number);
void measure_analog_inputs(struct analog_inputs *in);
//----------------------------------------------------------------------------------------------------------
#endif /* __ADC_H */

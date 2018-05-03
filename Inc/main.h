/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f4xx.h"
#include "string.h"
#include "PAGE.h"
#include "THYRISTORS.h"
#include "FLASH.h"
#include "ADC.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
#define AM0_Pin GPIO_PIN_0
#define AM0_GPIO_Port GPIOC
#define AM1_Pin GPIO_PIN_2
#define AM1_GPIO_Port GPIOC
#define AM2_Pin GPIO_PIN_3
#define AM2_GPIO_Port GPIOC
#define KN1_UP_Pin GPIO_PIN_3
#define KN1_UP_GPIO_Port GPIOA
#define KN2_DOWN_Pin GPIO_PIN_4
#define KN2_DOWN_GPIO_Port GPIOA
#define KN3_LEFT_Pin GPIO_PIN_5
#define KN3_LEFT_GPIO_Port GPIOA
#define KN4_RIGHT_Pin GPIO_PIN_6
#define KN4_RIGHT_GPIO_Port GPIOA
#define AD_Pin GPIO_PIN_0
#define AD_GPIO_Port GPIOB
#define ADB1_Pin GPIO_PIN_1
#define ADB1_GPIO_Port GPIOB
#define ADB2_Pin GPIO_PIN_2
#define ADB2_GPIO_Port GPIOB
#define In_summ5_Pin GPIO_PIN_12
#define In_summ5_GPIO_Port GPIOF
#define In_summ6_Pin GPIO_PIN_13
#define In_summ6_GPIO_Port GPIOF
#define In_summ7_Pin GPIO_PIN_14
#define In_summ7_GPIO_Port GPIOF
#define In_summ8_Pin GPIO_PIN_15
#define In_summ8_GPIO_Port GPIOF
#define In_summ4_Pin GPIO_PIN_0
#define In_summ4_GPIO_Port GPIOG
#define In_summ3_Pin GPIO_PIN_1
#define In_summ3_GPIO_Port GPIOG
#define ADB10_Pin GPIO_PIN_10
#define ADB10_GPIO_Port GPIOB
#define ADB11_Pin GPIO_PIN_11
#define ADB11_GPIO_Port GPIOB
#define ADB12_Pin GPIO_PIN_12
#define ADB12_GPIO_Port GPIOB
#define ADB13_Pin GPIO_PIN_13
#define ADB13_GPIO_Port GPIOB
#define In_summ2_Pin GPIO_PIN_2
#define In_summ2_GPIO_Port GPIOG
#define In_summ1_Pin GPIO_PIN_3
#define In_summ1_GPIO_Port GPIOG
#define clk_adc_Pin GPIO_PIN_6
#define clk_adc_GPIO_Port GPIOC
#define En1_multiplex_Pin GPIO_PIN_7
#define En1_multiplex_GPIO_Port GPIOC
#define En2_Pin GPIO_PIN_8
#define En2_GPIO_Port GPIOC
#define KN6_CLEAR_Pin GPIO_PIN_9
#define KN6_CLEAR_GPIO_Port GPIOC
#define KN5_OK_Pin GPIO_PIN_8
#define KN5_OK_GPIO_Port GPIOA
#define INT8_Pin GPIO_PIN_15
#define INT8_GPIO_Port GPIOA
#define INT7_Pin GPIO_PIN_9
#define INT7_GPIO_Port GPIOG
#define INT6_Pin GPIO_PIN_10
#define INT6_GPIO_Port GPIOG
#define INT5_Pin GPIO_PIN_11
#define INT5_GPIO_Port GPIOG
#define INT4_Pin GPIO_PIN_12
#define INT4_GPIO_Port GPIOG
#define INT3_Pin GPIO_PIN_13
#define INT3_GPIO_Port GPIOG
#define INT2_Pin GPIO_PIN_14
#define INT2_GPIO_Port GPIOG
#define INT1_Pin GPIO_PIN_15
#define INT1_GPIO_Port GPIOG
#define ADB3_Pin GPIO_PIN_3
#define ADB3_GPIO_Port GPIOB
#define ADB4_Pin GPIO_PIN_4
#define ADB4_GPIO_Port GPIOB
#define ADB5_Pin GPIO_PIN_5
#define ADB5_GPIO_Port GPIOB
#define ADB6_Pin GPIO_PIN_6
#define ADB6_GPIO_Port GPIOB
#define ADB7_Pin GPIO_PIN_7
#define ADB7_GPIO_Port GPIOB
#define ADB8_Pin GPIO_PIN_8
#define ADB8_GPIO_Port GPIOB
#define ADB9_Pin GPIO_PIN_9
#define ADB9_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
//----------------------------------------------------------------------------------------------------------
#define FREQ			180
#define FREQ_APB1 90
//----------------------------------------------------------------------------------------------------------



#define INT_S1			(GPIOG->IDR & GPIO_PIN_15) == (uint32_t)GPIO_PIN_RESET
#define INT_S2			(GPIOG->IDR & GPIO_PIN_14) == (uint32_t)GPIO_PIN_RESET
#define INT_S3			(GPIOG->IDR & GPIO_PIN_13) == (uint32_t)GPIO_PIN_RESET
#define INT_S4			(GPIOG->IDR & GPIO_PIN_12) == (uint32_t)GPIO_PIN_RESET
#define INT_S5			(GPIOG->IDR & GPIO_PIN_11) == (uint32_t)GPIO_PIN_RESET
#define INT_S6			(GPIOG->IDR & GPIO_PIN_10) == (uint32_t)GPIO_PIN_RESET
#define INT_S7			(GPIOG->IDR & GPIO_PIN_9)  == (uint32_t)GPIO_PIN_RESET
#define INT_S8			(GPIOA->IDR & GPIO_PIN_15) == (uint32_t)GPIO_PIN_RESET
//-------------------------------------------------------------
#define BUTTON_UP		 (GPIOA->IDR & GPIO_PIN_3) == (uint32_t)GPIO_PIN_RESET//UP
#define BUTTON_DOWN	 (GPIOA->IDR & GPIO_PIN_4) == (uint32_t)GPIO_PIN_RESET//DOWN
#define BUTTON_LEFT	 (GPIOA->IDR & GPIO_PIN_5) == (uint32_t)GPIO_PIN_RESET//LEFT
#define BUTTON_RIGHT (GPIOA->IDR & GPIO_PIN_6) == (uint32_t)GPIO_PIN_RESET//RIGHT
#define BUTTON_OK		 (GPIOA->IDR & GPIO_PIN_8) == (uint32_t)GPIO_PIN_RESET//OK
#define BUTTON_CLEAR (GPIOC->IDR & GPIO_PIN_9) == (uint32_t)GPIO_PIN_RESET//CLEAR
//-------------------------------------------------------------
#define _t_current_min	0//minimalnbly tok transformatorov
#define _t_current_max	50000//maximalnbly tok transformatorov
#define _k_min					0//minimalnbly k
#define _k_max					10000//maximalnbly k
//-------------------------------------------------------------

//-------------------------------------------------------------
#define	OUT_1_0					GPIOG->BSRR = (uint32_t)GPIO_PIN_7 << 16U;
#define	OUT_1_1					GPIOG->BSRR = GPIO_PIN_7;
#define	OUT_2_0					GPIOG->BSRR = (uint32_t)GPIO_PIN_6 << 16U;
#define	OUT_2_1					GPIOG->BSRR = GPIO_PIN_6;
#define	OUT_3_0					GPIOG->BSRR = (uint32_t)GPIO_PIN_5 << 16U;
#define	OUT_3_1					GPIOG->BSRR = GPIO_PIN_5;
#define	OUT_4_0					GPIOG->BSRR = (uint32_t)GPIO_PIN_4 << 16U;
#define	OUT_4_1					GPIOG->BSRR = GPIO_PIN_4;
//-------------------------------------------------------------
/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

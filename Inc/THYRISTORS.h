#ifndef __THYRISTORS_H
#define __THYRISTORS_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _VT1_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_0 << 16U;
#define _VT1_ON			GPIOD->BSRR = GPIO_PIN_0;
#define _VT2_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_1 << 16U;
#define _VT2_ON			GPIOD->BSRR = GPIO_PIN_1;
#define _VT3_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_2 << 16U;
#define _VT3_ON			GPIOD->BSRR = GPIO_PIN_2;
#define _VT4_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_3 << 16U;
#define _VT4_ON			GPIOD->BSRR = GPIO_PIN_3;
#define _VT5_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_4 << 16U;
#define _VT5_ON			GPIOD->BSRR = GPIO_PIN_4;
#define _VT6_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_5 << 16U;
#define _VT6_ON			GPIOD->BSRR = GPIO_PIN_5;
#define _ISM1_OFF		GPIOD->BSRR = (uint32_t)GPIO_PIN_6 << 16U;
#define _ISM1_ON		GPIOD->BSRR = GPIO_PIN_6;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//MODE 1
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _VT1_1_OFF	GPIOG->BSRR = (uint32_t)GPIO_PIN_0 << 16U;GPIOG->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOG->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_2 << 16U;
#define _VT1_1_ON		GPIOG->BSRR = GPIO_PIN_0;GPIOG->BSRR = GPIO_PIN_1;GPIOG->BSRR = GPIO_PIN_2;GPIOF->BSRR = GPIO_PIN_2;
#define _VT2_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_7 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_11 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_15 << 16U;
#define _VT2_1_ON		GPIOD->BSRR = GPIO_PIN_7;GPIOD->BSRR = GPIO_PIN_1;GPIOD->BSRR = GPIO_PIN_11;GPIOE->BSRR = GPIO_PIN_15;
#define _VT3_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_6 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_0 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_10 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_14 << 16U;
#define _VT3_1_ON		GPIOD->BSRR = GPIO_PIN_6;GPIOD->BSRR = GPIO_PIN_0;GPIOD->BSRR = GPIO_PIN_10;GPIOE->BSRR = GPIO_PIN_14;
#define _VT4_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_5 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_15 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_9 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_13 << 16U;
#define _VT4_1_ON		GPIOD->BSRR = GPIO_PIN_5;GPIOD->BSRR = GPIO_PIN_15;GPIOD->BSRR = GPIO_PIN_9;GPIOE->BSRR = GPIO_PIN_13;
#define _VT5_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_4 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_14 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_8 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_12 << 16U;
#define _VT5_1_ON		GPIOD->BSRR = GPIO_PIN_4;GPIOD->BSRR = GPIO_PIN_14;GPIOD->BSRR = GPIO_PIN_8;GPIOE->BSRR = GPIO_PIN_12;
#define _VT6_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_3 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_13 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_7 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_11 << 16U;
#define _VT6_1_ON		GPIOD->BSRR = GPIO_PIN_3;GPIOD->BSRR = GPIO_PIN_13;GPIOE->BSRR = GPIO_PIN_7;GPIOE->BSRR = GPIO_PIN_11;
#define _ISM1_1_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_12 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_6 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_10 << 16U;
#define _ISM1_1_ON	GPIOD->BSRR = GPIO_PIN_2;GPIOD->BSRR = GPIO_PIN_12;GPIOE->BSRR = GPIO_PIN_6;GPIOE->BSRR = GPIO_PIN_10;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//MODE 2
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _VT1_2_OFF	GPIOG->BSRR = (uint32_t)GPIO_PIN_0 << 16U;GPIOG->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_2 << 16U;
#define _VT1_2_ON		GPIOG->BSRR = GPIO_PIN_0;GPIOG->BSRR = GPIO_PIN_1;GPIOF->BSRR = GPIO_PIN_2;
#define _VT2_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_7 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_11 << 16U;
#define _VT2_2_ON		GPIOD->BSRR = GPIO_PIN_7;GPIOD->BSRR = GPIO_PIN_1;GPIOD->BSRR = GPIO_PIN_11;
#define _VT3_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_6 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_0 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_14 << 16U;
#define _VT3_2_ON		GPIOD->BSRR = GPIO_PIN_6;GPIOD->BSRR = GPIO_PIN_0;GPIOE->BSRR = GPIO_PIN_14;
#define _VT4_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_5 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_15 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_9 << 16U;
#define _VT4_2_ON		GPIOD->BSRR = GPIO_PIN_5;GPIOD->BSRR = GPIO_PIN_15;GPIOD->BSRR = GPIO_PIN_9;
#define _VT5_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_4 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_14 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_12 << 16U;
#define _VT5_2_ON		GPIOD->BSRR = GPIO_PIN_4;GPIOD->BSRR = GPIO_PIN_14;GPIOE->BSRR = GPIO_PIN_12;
#define _VT6_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_3 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_13 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_7 << 16U;
#define _VT6_2_ON		GPIOD->BSRR = GPIO_PIN_3;GPIOD->BSRR = GPIO_PIN_13;GPIOE->BSRR = GPIO_PIN_7;
#define _ISM1_2_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_12 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_6 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_10 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_4 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_1 << 16U;
#define _ISM1_2_ON	GPIOD->BSRR = GPIO_PIN_2;GPIOD->BSRR = GPIO_PIN_12;GPIOE->BSRR = GPIO_PIN_6;GPIOE->BSRR = GPIO_PIN_10;GPIOE->BSRR = GPIO_PIN_4;GPIOF->BSRR = GPIO_PIN_1;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//MODE 3
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _VT1_3_OFF	GPIOG->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOG->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_0 << 16U;
#define _VT1_3_ON		GPIOG->BSRR = GPIO_PIN_1;GPIOG->BSRR = GPIO_PIN_2;GPIOF->BSRR = GPIO_PIN_2;GPIOF->BSRR = GPIO_PIN_0;
#define _VT2_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_7 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_11 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_15 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_9 << 16U;
#define _VT2_3_ON		GPIOD->BSRR = GPIO_PIN_7;GPIOD->BSRR = GPIO_PIN_11;GPIOE->BSRR = GPIO_PIN_15;GPIOE->BSRR = GPIO_PIN_9;
#define _VT3_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_0 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_10 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_14 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_8 << 16U;
#define _VT3_3_ON		GPIOD->BSRR = GPIO_PIN_0;GPIOD->BSRR = GPIO_PIN_10;GPIOE->BSRR = GPIO_PIN_14;GPIOE->BSRR = GPIO_PIN_8;
#define _VT4_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_5 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_9 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_13 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_15 << 16U;
#define _VT4_3_ON		GPIOD->BSRR = GPIO_PIN_5;GPIOD->BSRR = GPIO_PIN_9;GPIOE->BSRR = GPIO_PIN_13;GPIOF->BSRR = GPIO_PIN_15;
#define _VT5_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_14 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_8 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_12 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_14 << 16U;
#define _VT5_3_ON		GPIOD->BSRR = GPIO_PIN_14;GPIOD->BSRR = GPIO_PIN_8;GPIOE->BSRR = GPIO_PIN_12;GPIOF->BSRR = GPIO_PIN_14;
#define _VT6_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_3 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_7 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_11 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_13 << 16U;
#define _VT6_3_ON		GPIOD->BSRR = GPIO_PIN_3;GPIOE->BSRR = GPIO_PIN_7;GPIOE->BSRR = GPIO_PIN_11;GPIOF->BSRR = GPIO_PIN_13;
#define _ISM1_3_OFF	GPIOD->BSRR = (uint32_t)GPIO_PIN_2 << 16U;GPIOD->BSRR = (uint32_t)GPIO_PIN_12 << 16U;GPIOE->BSRR = (uint32_t)GPIO_PIN_4 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_1 << 16U;GPIOF->BSRR = (uint32_t)GPIO_PIN_5 << 16U;
#define _ISM1_3_ON	GPIOD->BSRR = GPIO_PIN_2;GPIOD->BSRR = GPIO_PIN_12;GPIOE->BSRR = GPIO_PIN_4;GPIOF->BSRR = GPIO_PIN_1;GPIOF->BSRR = GPIO_PIN_5;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void VT1(uint32_t us);
void VT2(uint32_t us);
void VT3(uint32_t us);
void VT4(uint32_t us);
void VT5(uint32_t us);
void VT6(uint32_t us);
void VT_ON(uint8_t regum, uint8_t tyrystor);
void VT_OFF(uint8_t tyrystor);
void VT_OFF_ALL(void);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif /* __THYRISTORS_H */

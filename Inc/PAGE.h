#ifndef __PAGE_H
#define __PAGE_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

//----------------------------------------------------------------------------------------------------------
#define READY						1
#define ALARM						2
#define INPUT						3
#define OUTPUT					4
#define TRANSFORMS			5
#define SHUNT						9
#define SYNCHRONIZATION	6
#define _PI							8
#define VAR							7
#define PAGE_MIN				3
#define PAGE_MAX				9
#define SYNCHRO_MIN			0
#define SYNCHRO_MAX			12
//----------------------------------------------------------------------------------------------------------
void LCD_Input(uint8_t input);
void LCD_Output(uint8_t output);
void LCD_Transforms(uint8_t num,uint16_t t1,uint16_t t2,uint16_t t3,uint16_t t4,uint8_t blink,uint8_t alarm);
void LCD_Transforms_setting(uint8_t num,uint16_t posled,uint16_t posled_paral,uint16_t paral,uint8_t blink);
void LCD_Synchro(uint16_t synchro, uint8_t blink);
void LCD_PI(uint8_t num,uint32_t kp,uint32_t ki,uint8_t blink);
void LCD_Page(uint8_t page);
void LCD_Alarm(uint8_t alarm);
void LCD_Current(float t1,float t2,float t3,float t4,float shunt,float task,float alfa,uint8_t _en,uint8_t alarm,uint8_t regum,uint8_t sinchro);
//----------------------------------------------------------------------------------------------------------
#endif /* __PAGE_H */

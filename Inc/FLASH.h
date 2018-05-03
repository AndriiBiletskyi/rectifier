#ifndef __FLASH_H
#define __FLASH_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

struct variables{
	uint8_t	regum;
	uint8_t	_page;
	uint8_t	_transfor;
	uint8_t	_blink;
	int8_t	_synchro;
	uint8_t _input;
	uint8_t _output;
	uint8_t _pi;
	int32_t _t1_current;
	int32_t _t2_current;
	int32_t _t3_current;
	int32_t _t4_current;
	uint8_t _shunt;
	int32_t _posled;
	int32_t _posled_paral;
	int32_t _paral;
	uint8_t _enable;
	float PID;
	float Error;
	float Integral;
	float MAX_Ki;
	int32_t Kp;
	int32_t Ki;
	float Integralmax;
	uint8_t _tr_alarm;
	float _t1_current_lcd;
	float _t2_current_lcd;
	float _t3_current_lcd;
	float _t4_current_lcd;
	float shunt_lcd;
	float	task_lcd;
	float	alfa_lcd;
	uint8_t reset;
	uint8_t count_reset;
};


#define ADDRESS_SYNCHRONIZATION			0x080E0000
#define ADDRESS_KP									0x080E0000+4
#define ADDRESS_KI									0x080E0000+4*2
#define ADDRESS_T1_CURRENT					0x080E0000+4*3
#define ADDRESS_T2_CURRENT					0x080E0000+4*4
#define ADDRESS_T3_CURRENT					0x080E0000+4*5
#define ADDRESS_T4_CURRENT					0x080E0000+4*6
#define ADDRESS_SERIES							0x080E0000+4*7
#define ADDRESS_SERIES_PARALLEL			0x080E0000+4*8
#define ADDRESS_PARALLEL						0x080E0000+4*9
//----------------------------------------------------------------------------------------------------------
uint32_t flash_read(uint32_t address);
void write_parameters(const struct variables *disp);
//----------------------------------------------------------------------------------------------------------
#endif /* __FLASH_H */

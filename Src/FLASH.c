#include "FLASH.h"



//----------------------------------------------------------------------------------------------------------
uint32_t flash_read(uint32_t address) 
{
	return (*(__IO uint32_t*) address);
}
//----------------------------------------------------------------------------------------------------------
void write_parameters(const struct variables *disp)
{
	HAL_FLASH_Unlock();
	
	FLASH_Erase_Sector(FLASH_SECTOR_11,FLASH_VOLTAGE_RANGE_3);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_SYNCHRONIZATION,disp->_synchro);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_KP,disp->Kp);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_KI,disp->Ki);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_T1_CURRENT,disp->_t1_current);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_T2_CURRENT,disp->_t2_current);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_T3_CURRENT,disp->_t3_current);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_T4_CURRENT,disp->_t4_current);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_SERIES,disp->_posled);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_SERIES_PARALLEL,disp->_posled_paral);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ADDRESS_PARALLEL,disp->_paral);

	HAL_FLASH_Lock();
}
//----------------------------------------------------------------------------------------------------------

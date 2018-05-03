#include "THYRISTORS.h"

//----------------------------------------------------------------------------------------------------------
void VT1(uint32_t us)
{
	TIM2->ARR = us;
	TIM2->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT2(uint32_t us)
{
	TIM3->ARR = us;
	TIM3->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT3(uint32_t us)
{
	TIM4->ARR = us;
	TIM4->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT4(uint32_t us)
{
	TIM5->ARR = us;
	TIM5->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT5(uint32_t us)
{
	TIM6->ARR = us;
	TIM6->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT6(uint32_t us)
{
	TIM7->ARR = us;
	TIM7->CR1|=TIM_CR1_CEN|TIM_CR1_OPM;
}
//----------------------------------------------------------------------------------------------------------
void VT_ON(uint8_t mode, uint8_t thyristor)
{
	if(mode==1){
		if(thyristor==1){_VT1_1_ON}
		else	if(thyristor==2){_VT2_1_ON}
		else	if(thyristor==3){_VT3_1_ON}
		else	if(thyristor==4){_VT4_1_ON}
		else	if(thyristor==5){_VT5_1_ON}
		else	if(thyristor==6){_VT6_1_ON}
		_ISM1_1_ON	
	}else if(mode==2){
		if(thyristor==1){_VT1_2_ON}
		else	if(thyristor==2){_VT2_2_ON}
		else	if(thyristor==3){_VT3_2_ON}
		else	if(thyristor==4){_VT4_2_ON}
		else	if(thyristor==5){_VT5_2_ON}
		else	if(thyristor==6){_VT6_2_ON}
		_ISM1_2_ON
	}else	if(mode==3){
		if(thyristor==1){_VT1_3_ON}
		else	if(thyristor==2){_VT2_3_ON}
		else	if(thyristor==3){_VT3_3_ON}
		else	if(thyristor==4){_VT4_3_ON}
		else	if(thyristor==5){_VT5_3_ON}
		else	if(thyristor==6){_VT6_3_ON}
		_ISM1_3_ON
	}
}
//----------------------------------------------------------------------------------------------------------
void VT_OFF(uint8_t thyristor)
{
		if(thyristor==1){
			_VT1_1_OFF
			_VT1_2_OFF
			_VT1_3_OFF
		}else	if(thyristor==2){
			_VT2_1_OFF
			_VT2_2_OFF
			_VT2_3_OFF
		}else	if(thyristor==3){
			_VT3_1_OFF
			_VT3_2_OFF
			_VT3_3_OFF
		}else	if(thyristor==4){
			_VT4_1_OFF
			_VT4_2_OFF
			_VT4_3_OFF
		}else	if(thyristor==5){
			_VT5_1_OFF
			_VT5_2_OFF
			_VT5_3_OFF
		}else	if(thyristor==6){
			_VT6_1_OFF
			_VT6_2_OFF
			_VT6_3_OFF
		}
		_ISM1_1_OFF
		_ISM1_2_OFF
		_ISM1_3_OFF
}
//----------------------------------------------------------------------------------------------------------
void VT_OFF_ALL(void)
{
			_VT1_1_OFF
			_VT1_2_OFF
			_VT1_3_OFF
			_VT2_1_OFF
			_VT2_2_OFF
			_VT2_3_OFF
			_VT3_1_OFF
			_VT3_2_OFF
			_VT3_3_OFF
			_VT4_1_OFF
			_VT4_2_OFF
			_VT4_3_OFF
			_VT5_1_OFF
			_VT5_2_OFF
			_VT5_3_OFF
			_VT6_1_OFF
			_VT6_2_OFF
			_VT6_3_OFF
			_ISM1_1_OFF
			_ISM1_2_OFF
			_ISM1_3_OFF
}
//----------------------------------------------------------------------------------------------------------

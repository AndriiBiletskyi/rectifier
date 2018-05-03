#include "ADC.h"


//----------------------------------------------------------------------------------------------------------
uint16_t adc_read(uint8_t number)
{
	uint16_t adc_rezult = 0;
	 
	if(number&0x01){ADC_A0_1;}
	else {ADC_A0_0;}
	if(number&0x02){ADC_A1_1;}
	else {ADC_A1_0;}
	if(number&0x04){ADC_A2_1;}
	else {ADC_A2_0;}
	
	for(uint32_t i=0;i<50;i++){}
	ADC_EN_0
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_1 
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_0
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_1 
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_0
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_1 
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_0
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_1 
	for(uint32_t i=0;i<10;i++){}
	ADC_CLK_0
	for(uint32_t i=0;i<10;i++){}

	if(BIT1){adc_rezult|=(1<<13);}
	else	{adc_rezult&=~(1<<13);}
	if(BIT2){adc_rezult|=(1<<12);}
	else	{adc_rezult&=~(1<<12);}
	if(BIT3){adc_rezult|=(1<<11);}
	else	{adc_rezult&=~(1<<11);}
	if(BIT4){adc_rezult|=(1<<10);}
	else	{adc_rezult&=~(1<<10);}
	if(BIT5){adc_rezult|=(1<<9);}
	else	{adc_rezult&=~(1<<9);}
	if(BIT6){adc_rezult|=(1<<8);}
	else	{adc_rezult&=~(1<<8);}
	if(BIT7){adc_rezult|=(1<<7);}
	else	{adc_rezult&=~(1<<7);}
	if(BIT8){adc_rezult|=(1<<6);}
	else	{adc_rezult&=~(1<<6);}
	if(BIT9){adc_rezult|=(1<<5);}
	else	{adc_rezult&=~(1<<5);}
	if(BIT10){adc_rezult|=(1<<4);}
	else	{adc_rezult&=~(1<<4);}
	if(BIT11){adc_rezult|=(1<<3);}
	else	{adc_rezult&=~(1<<3);}
	if(BIT12){adc_rezult|=(1<<2);}
	else	{adc_rezult&=~(1<<2);}
	if(BIT13){adc_rezult|=(1<<1);}
	else	{adc_rezult&=~(1<<1);}
	if(BIT14){adc_rezult|=(1<<0);}
	else	{adc_rezult&=~(1<<0);}
		
	return adc_rezult;
}
//----------------------------------------------------------------------------------------------------------
void measure_analog_inputs(struct analog_inputs *in)
{
	static uint8_t count = 0;
	uint8_t count_max = 16;
	
	in->first_value 	= adc_read(0);
	in->second_value 	= adc_read(1);
	in->third_value		= adc_read(2);
	in->fourth_value 	= adc_read(3);
	in->fifth_value 	= adc_read(4);
	in->sixth_value 	= adc_read(5);
	in->seventh_value = adc_read(6);
	in->eighth_value 	= adc_read(7);
	
	
	in->first_all -= in->buf_first[count];
	in->buf_first[count] = in->first_value;
	in->first_all += in->buf_first[count];
	in->first_average = in->first_all/count_max;
	
	in->second_all -= in->buf_second[count];
	in->buf_second[count] = in->second_value;
	in->second_all += in->buf_second[count];
	in->second_average = in->second_all/count_max;
	
	in->third_all -= in->buf_third[count];
	in->buf_third[count] = in->third_value;
	in->third_all += in->buf_third[count];
	in->third_average = in->third_all/count_max;
	
	in->fourth_all -= in->buf_fourth[count];
	in->buf_fourth[count] = in->fourth_value;
	in->fourth_all += in->buf_fourth[count];
	in->fourth_average = in->fourth_all/count_max;
	
	in->fifth_all -= in->buf_fifth[count];
	in->buf_fifth[count] = in->fifth_value;
	in->fifth_all += in->buf_fifth[count];
	in->fifth_average = in->fifth_all/count_max;
	
	in->sixth_all -= in->buf_sixth[count];
	in->buf_sixth[count] = in->sixth_value;
	in->sixth_all += in->buf_sixth[count];
	in->sixth_average = in->sixth_all/count_max;
	
	in->seventh_all -= in->buf_seventh[count];
	in->buf_seventh[count] = in->seventh_value;
	in->seventh_all += in->buf_seventh[count];
	in->seventh_average = in->seventh_all/count_max;
	
	in->eighth_all -= in->buf_eighth[count];
	in->buf_eighth[count] = in->eighth_value;
	in->eighth_all += in->buf_eighth[count];
	in->eighth_average = in->eighth_all/count_max;
	
	count++;
	if(count>(count_max-1))count = 0;
}
//----------------------------------------------------------------------------------------------------------

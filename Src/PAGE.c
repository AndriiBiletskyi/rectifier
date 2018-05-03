#include "PAGE.h"
#include "TFT.h"

extern volatile uint16_t color_text;
extern volatile uint16_t color_background;
extern char version[];
//----------------------------------------------------------------------------------------------------------
void LCD_Page(uint8_t page)
{
	static uint8_t count = 1;
	static uint16_t number = 50;
	
	if(count){
		LCD_Init();
		LCD_SendCommand(ILI9341_MAC);
		LCD_SendData(0x28);//E8
		LCD_Fill(ILI9341_BLACK);
		LCD_DrawString(150, 180, version);
		HAL_Delay(2000);
		count = 0;
	}
	
	if(number!=page){
		if(page==INPUT){//Input
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c:",157,186-32,189-32,190-32,186-32,203-32,185-32,180-32,177-32,174-32,193-32,186-32,176-32,186-32,174-32);//SOSTOYANIE VXODOV
			LCD_DrawString(60,10,buf);
			sprintf(buf,"%c%c%c%c 1",174-32,193-32,186-32,176-32);//VXOD 1
			LCD_DrawString(30,15+24*1,buf);
			sprintf(buf,"%c%c%c%c 2",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*2,buf);
			sprintf(buf,"%c%c%c%c 3",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*3,buf);
			sprintf(buf,"%c%c%c%c 4",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*4,buf);
			sprintf(buf,"%c%c%c%c 5",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*5,buf);
			sprintf(buf,"%c%c%c%c 6",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*6,buf);
			sprintf(buf,"%c%c%c%c 7",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*7,buf);
			sprintf(buf,"%c%c%c%c 8",174-32,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*8,buf);
		}else if(page==TRANSFORMS){//Transforms
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c",159,189-32,190-32,172-32,174-32,182-32,172-32,184-32,172-32,182-32,189-32,180-32,184-32,172-32,183-32,200-32,185-32,186-32,175-32,186-32);//Ustavka maksimalnogo
			LCD_DrawString(25,10,buf);
			sprintf(buf,"  %c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c:",190-32,186-32,182-32,172-32,190-32,188-32,172-32,185-32,189-32,192-32,186-32,188-32,184-32,172-32,190-32,186-32,188-32,186-32,174-32);//toka transformatorov
			LCD_DrawString(22,10+24,buf);
			sprintf(buf,"  %c%c-%c%c%c 1",158,188-32,190-32,186-32,188-32);//tr-tor1
			LCD_DrawString(30,34+46,buf);
			sprintf(buf,"  %c%c-%c%c%c 2",158,188-32,190-32,186-32,188-32);//tr-tor2
			LCD_DrawString(30,34+46+40,buf);
			sprintf(buf,"  %c%c-%c%c%c 3",158,188-32,190-32,186-32,188-32);//tr-tor3
			LCD_DrawString(30,34+46+40*2,buf);
			sprintf(buf,"  %c%c-%c%c%c 4",158,188-32,190-32,186-32,188-32);//tr-tor4
			LCD_DrawString(30,34+46+40*3,buf);
		}else if(page==SYNCHRONIZATION){//Synchronization
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			volatile uint16_t x;
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c%c%c%c%c",157,180-32,185-32,193-32,188-32,186-32,185-32,180-32,179-32,172-32,194-32,180-32,203-32);
			LCD_DrawString(75,2*24,buf);
			LCD_Fill_Rectangle(ILI9341_GREEN,20, 137, 297, 140);//solid horizontal
			for(x=0;x<13;x++)
			{
				if(x%2==0)LCD_Fill_Rectangle(ILI9341_GREEN,20+x*23,121, 21+x*23, 156);//high vertical 0
				else LCD_Fill_Rectangle(ILI9341_GREEN,20+x*23, 127, 21+x*23, 149);//small vertical 0
			}
			LCD_DrawString(15,157,"0");
			LCD_DrawString(12+23*2,157,"10");
			LCD_DrawString(12+23*4,157,"20");
			LCD_DrawString(12+23*6,157,"30");
			LCD_DrawString(12+23*8,157,"40");
			LCD_DrawString(12+23*10,157,"50");
			LCD_DrawString(12+23*12,157,"60");
		}else if(page==READY){//Ready
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLUE;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c%c",143,154,158,154,142,153,154,157,158,168);
			LCD_DrawString(100,2*24,buf);
		}else if(page==ALARM){//Alarm
			color_text = ILI9341_WHITE;
			color_background = ILI9341_RED;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c",140,142,140,156,148,171);
			LCD_DrawString(125,2*24,buf);
		}else if(page==OUTPUT){//Output
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c:",157,186-32,189-32,190-32,186-32,203-32,185-32,180-32,177-32,174-32,167,193-32,186-32,176-32,186-32,174-32);//SOSTOYANIE VblXODOV
			LCD_DrawString(60,10,buf);
			sprintf(buf,"%c%c%c%c%c 1",174-32,167,193-32,186-32,176-32);//VXOD 1
			LCD_DrawString(30,15+24*1,buf);
			sprintf(buf,"%c%c%c%c%c 2",174-32,167,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*2,buf);
			sprintf(buf,"%c%c%c%c%c 3",174-32,167,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*3,buf);
			sprintf(buf,"%c%c%c%c%c 4",174-32,167,193-32,186-32,176-32);
			LCD_DrawString(30,15+24*4,buf);
		}else if(page==SHUNT){//Transforms ustavka
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"  %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c",159,189-32,190-32,172-32,174-32,182-32,172-32 ,154,143,156,140,153,148,163,145,153,148,171);//Ustavka ogranicheniya
			LCD_DrawString(25,10,buf);
			sprintf(buf,"       %c%c%c%c%c%c%c%c%c %c%c%c%c:",142,167,161,154,144,153,154,143,154 ,190-32,186-32,182-32,172-32);//vblxodnogo toka
			LCD_DrawString(22,10+24,buf);
			sprintf(buf,"  %c%c%c%c%c%c",155,186-32,189-32,183-32,177-32,176-32);//posled
			LCD_DrawString(30,34+46,buf);
			sprintf(buf,"  %c%c%c%c%c%c-%c%c%c%c%c",155,186-32,189-32,183-32,177-32,176-32,155,172-32,188-32,172-32,183-32);//posled-paral
			LCD_DrawString(30,34+46+40,buf);
			sprintf(buf,"  %c%c%c%c%c",155,172-32,188-32,172-32,183-32);//paral
			LCD_DrawString(30,34+46+40*2,buf);
		}else if(page==_PI){//PI
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c:",155,140,156,140,152,145,158,156,167, 156,145,143,159,151,171,158,154,156,140);//Parametrbl regulatora
			LCD_DrawString(40,30,buf);
		}else if(page==VAR){//Current
			color_text = ILI9341_WHITE;
			color_background = ILI9341_BLACK;
			LCD_SendCommand(ILI9341_MAC);
			LCD_SendData(0x28);//E8
			char buf[35] = {0};
			uint32_t poz_x_str = 30;
			uint32_t poz_x_si = 270;
			LCD_Fill(color_background);
			sprintf(buf,"%c%c%c%c%c%c%c%c%c:",155,140,156,140,152,145,158,156,167);//PARAMETRbl
			LCD_DrawString(100,10,buf);
			sprintf(buf,"%c%c-%c%c%c 1",158,188-32,190-32,186-32,188-32);//tr-tor1
			LCD_DrawString(poz_x_str,15+24*1,buf);
			sprintf(buf,"%c%c-%c%c%c 2",158,188-32,190-32,186-32,188-32);//tr-tor2
			LCD_DrawString(poz_x_str,15+24*2,buf);
			sprintf(buf,"%c%c-%c%c%c 3",158,188-32,190-32,186-32,188-32);//tr-tor3
			LCD_DrawString(poz_x_str,15+24*3,buf);
			sprintf(buf,"%c%c-%c%c%c 4",158,188-32,190-32,186-32,188-32);//tr-tor4
			LCD_DrawString(poz_x_str,15+24*4,buf);
			sprintf(buf,"%c%c%c%c",164,159,153,158);//shunt
			LCD_DrawString(poz_x_str,15+24*5,buf);
			sprintf(buf,"%c%c%c%c%c%c%c",147,140,144,140,153,148,145);//zadanie
			LCD_DrawString(poz_x_str,15+24*6,buf);
			sprintf(buf,"%c%c%c%c%c",140,151,168,160,140);//alfa
			LCD_DrawString(poz_x_str,15+24*7,buf);
			
			sprintf(buf,"A");
			LCD_DrawString(poz_x_si,15+24*1,buf);
			sprintf(buf,"A");
			LCD_DrawString(poz_x_si,15+24*2,buf);
			sprintf(buf,"A");
			LCD_DrawString(poz_x_si,15+24*3,buf);
			sprintf(buf,"A");
			LCD_DrawString(poz_x_si,15+24*4,buf);
			sprintf(buf,"%c",'%');
			LCD_DrawString(poz_x_si,15+24*5,buf);
			sprintf(buf,"%c",'%');
			LCD_DrawString(poz_x_si,15+24*6,buf);
			sprintf(buf,"%c.%c.",201,175);
			LCD_DrawString(poz_x_si,15+24*7,buf);

			LCD_Current(0,0,0,0,0,0,180,250,250,4,150);
		}
	}
	number = page;
}
//----------------------------------------------------------------------------------------------------------
void LCD_Alarm(uint8_t alarm)
{
	static uint8_t input_alarm = 0;
	if(alarm!=0 && input_alarm!=alarm){
		color_text = ILI9341_WHITE;
		color_background = ILI9341_RED;
		LCD_SendCommand(ILI9341_MAC);
		LCD_SendData(0x28);//E8
		char buf[35] = {0};
		LCD_Fill_Rectangle(color_background,125, 24*4, 320, 24*5);
		sprintf(buf,"%i %c%c-%c%c%c",alarm,158,188-32,190-32,186-32,188-32);
		LCD_DrawString(125,4*24,buf);
	}
	if(alarm==0){
		color_text = ILI9341_WHITE;
		color_background = ILI9341_RED;
		LCD_SendCommand(ILI9341_MAC);
		LCD_SendData(0x28);//E8
		LCD_Fill_Rectangle(color_background,125, 24*4, 320, 24*5);
	}
	input_alarm = alarm;
}
//----------------------------------------------------------------------------------------------------------
void LCD_Input(uint8_t input)
{
	LCD_SendCommand(ILI9341_MAC);
	LCD_SendData(0x28);//E8
	static uint8_t number = 0;
	char buf[35] = {0};
	if(number!=input){
		if((number&0x01)!=(input&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*1, 320, 14+24*2);
		}
		if(((number>>1)&0x01)!=((input>>1)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*2, 320, 14+24*3);
		}
		if(((number>>2)&0x01)!=((input>>2)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*3, 320, 14+24*4);
		}
		if(((number>>3)&0x01)!=((input>>3)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*4, 320, 14+24*5);
		}
		if(((number>>4)&0x01)!=((input>>4)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*5, 320, 14+24*6);
		}
		if(((number>>5)&0x01)!=((input>>5)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*6, 320, 14+24*7);
		}
		if(((number>>6)&0x01)!=((input>>6)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*7, 320, 14+24*8);
		}
		if(((number>>7)&0x01)!=((input>>7)&0x01)){
			LCD_Fill_Rectangle(color_background,100, 15+24*8, 320, 14+24*9);
		}
	}
	if(input&0x01){
		sprintf(buf,"%c%c%c%c%c%c",155,186-32,189-32,183-32,177-32,176-32);//VXOD 1 Posled 100x
		LCD_DrawString(210,15+24*1,buf);
	}else {
		sprintf(buf,"0");//VXOD 1 0 100x
		LCD_DrawString(280,15+24*1,buf);
	}
	if((input>>1)&0x01){
		sprintf(buf,"%c%c%c%c%c%c-%c%c%c%c%c",155,186-32,189-32,183-32,177-32,176-32,155,172-32,188-32,172-32,183-32);
		LCD_DrawString(136,15+24*2,buf);
	}else {
		sprintf(buf,"0");
		LCD_DrawString(280,15+24*2,buf);
	}
	if((input>>2)&0x01){
		sprintf(buf,"%c%c%c%c%c",155,172-32,188-32,172-32,183-32);
		LCD_DrawString(222,15+24*3,buf);
	}else {
		sprintf(buf,"0");
		LCD_DrawString(280,15+24*3,buf);
	}
	if((input>>3)&0x01){
		sprintf(buf,"%c%c%c%c%c%c%c%c%c%c",143,186-32,190-32,186-32,174-32,185-32,186-32,189-32,190-32,200-32);//gotovnost'
		LCD_DrawString(167,15+24*4,buf);
	}else {
		sprintf(buf,"%c%c%c%c%c%c",140,174-32,172-32,188-32,180-32,203-32);//avariya
		LCD_DrawString(211,15+24*4,buf);
	}
	if((input>>4)&0x01){
		sprintf(buf,"%c%c%c%c%c%c",156,140,141,154,158,140);//rabota
		LCD_DrawString(215,15+24*5,buf);
	}else {
		sprintf(buf,"%c%c%c%c",157,158,154,155);//stop
		LCD_DrawString(238,15+24*5,buf);
	}
	if((input>>5)&0x01){
		sprintf(buf,"1");
		LCD_DrawString(280,15+24*6,buf);
	}else {
		sprintf(buf,"0");
		LCD_DrawString(280,15+24*6,buf);
	}
	if((input>>6)&0x01){
		sprintf(buf,"1");
		LCD_DrawString(280,15+24*7,buf);
	}else {
		sprintf(buf,"0");
		LCD_DrawString(280,15+24*7,buf);
	}
	if((input>>7)&0x01){
		sprintf(buf,"1");
		LCD_DrawString(280,15+24*8,buf);
	}else {
		sprintf(buf,"0");
		LCD_DrawString(280,15+24*8,buf);
	}

	number = input;
}
//----------------------------------------------------------------------------------------------------------
void LCD_Output(uint8_t output)
{
	LCD_SendCommand(ILI9341_MAC);
	LCD_SendData(0x28);//E8
	static uint8_t number = 0;
	char buf[35] = {0};
	if(number!=output){
		if((number&0x01)!=(output&0x01)){
			LCD_Fill_Rectangle(color_background,115, 15+24*1, 320, 14+24*2);
		}
		if(((number>>1)&0x01)!=((output>>1)&0x01)){
			LCD_Fill_Rectangle(color_background,115, 15+24*2, 320, 14+24*3);
		}
		if(((number>>2)&0x01)!=((output>>2)&0x01)){
			LCD_Fill_Rectangle(color_background,115, 15+24*3, 320, 14+24*4);
		}
		if(((number>>3)&0x01)!=((output>>3)&0x01)){
			LCD_Fill_Rectangle(color_background,115, 15+24*4, 320, 14+24*5);
		}
	}
	if(output&0x01){
		sprintf(buf,"%c%c%c%c%c%c%c%c%c%c",143,186-32,190-32,186-32,174-32,185-32,186-32,189-32,190-32,200-32);//gotovnost'
		LCD_DrawString(182,15+24*1,buf);
	}else {
		sprintf(buf,"-----");//---------
		LCD_DrawString(265,15+24*1,buf);
	}
	if((output>>1)&0x01){
		sprintf(buf,"%c%c%c%c%c%c",140,174-32,172-32,188-32,180-32,203-32);//avariya
		LCD_DrawString(226,15+24*2,buf);
	}else {
		sprintf(buf,"-----");//---------
		LCD_DrawString(265,15+24*2,buf);
	}
	if((output>>2)&0x01){
		sprintf(buf,"%c%c%c%c%c%c%c %c%c%c%c%c%c",158,154,150,154,142,140,171,147,140,165,148,158,140);
		LCD_DrawString(130,15+24*3,buf);
	}else {
		sprintf(buf,"-----");//---------
		LCD_DrawString(265,15+24*3,buf);
	}
	if((output>>3)&0x01){
		sprintf(buf,"-----");//---------
		LCD_DrawString(265,15+24*4,buf);
	}else {
		sprintf(buf,"-----");//---------
		LCD_DrawString(265,15+24*4,buf);
	}

	number = output;
}
//----------------------------------------------------------------------------------------------------------
void LCD_Transforms(uint8_t num,uint16_t t1,uint16_t t2,uint16_t t3,uint16_t t4,uint8_t blink,uint8_t alarm)
{
	static uint8_t number = 0;
	static int32_t counter = 0;
	static int8_t increment = 1;
	static uint16_t current_t1 = 0;
	static uint16_t current_t2 = 0;
	static uint16_t current_t3 = 0;
	static uint16_t current_t4 = 0;
	char buf[35] = {0};
	uint32_t offset = 200;
	uint32_t offset_rec_1 = 200;
	uint32_t offset_rec_2 = 320;

	if(number!=num)LCD_Fill_Rectangle(color_background,11, 34+50, 37, 240);
	if(current_t1!=t1){LCD_Fill_Rectangle(color_background,offset_rec_1,34+46, offset_rec_2, 34+46+25);}
	if(current_t2!=t2){LCD_Fill_Rectangle(color_background,offset_rec_1, 34+46+40, offset_rec_2, 34+46+40+25);}
	if(current_t3!=t3){LCD_Fill_Rectangle(color_background,offset_rec_1, 34+46+40*2, offset_rec_2, 34+46+40*2+25);}
	if(current_t4!=t4){LCD_Fill_Rectangle(color_background,offset_rec_1, 34+50+40*3, offset_rec_2, 34+46+40*3+25);}
	if(blink==1 && counter>0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==3){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==4){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
		}
		if(num==1)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50+40*2, 35, 34+45+15+40*2);
		else if(num==4)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50+40*3, 35, 34+45+15+40*3);
	}
	if(blink==1 && counter<0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==3){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
		}
		if(num==4){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
			LCD_DrawString(offset,34+46+40*3,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
			LCD_DrawString(offset,34+46+40*2,buf);
		}

		if(num==1)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50+40*2, 35, 34+45+15+40*2);
		else if(num==4)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50+40*3, 35, 34+45+15+40*3);

	}
	if(blink==0){
		uint16_t color_rect;
		if(alarm==0){color_rect = ILI9341_WHITE;}
		else {color_rect = ILI9341_RED;}
		sprintf(buf,"%6.1f A",(float)t1/10);//tr-tor1
		LCD_DrawString(offset,34+46,buf);
		sprintf(buf,"%6.1f A",(float)t2/10);//tr-tor2
		LCD_DrawString(offset,34+46+40,buf);
		sprintf(buf,"%6.1f A",(float)t3/10);//tr-tor3
		LCD_DrawString(offset,34+46+40*2,buf);
		sprintf(buf,"%6.1f A",(float)t4/10);//tr-tor4
		LCD_DrawString(offset,34+46+40*3,buf);
		if(num==1)LCD_Fill_Rectangle(color_rect,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(color_rect,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(color_rect,11, 34+50+40*2, 35, 34+45+15+40*2);
		else if(num==4)LCD_Fill_Rectangle(color_rect,11, 34+50+40*3, 35, 34+45+15+40*3);
		counter = 0;
		increment = 1;
	}
	current_t1 = t1;
	current_t2 = t2;
	current_t3 = t3;
	current_t4 = t4;
	number = num;
	if(blink == 1){
		counter+=increment;
		if(counter>10)increment = -1;
		if(counter<-10)increment = 1;
	}
}
//----------------------------------------------------------------------------------------------------------
void LCD_Transforms_setting(uint8_t num,uint16_t posled,uint16_t posled_paral,uint16_t paral,uint8_t blink)
{
	static uint8_t number = 0;
	static int32_t counter = 0;
	static int8_t increment = 1;
	static uint16_t current_posled = 0;
	static uint16_t current_posled_paral = 0;
	static uint16_t current_paral = 0;
	uint32_t offset = 230;
	uint32_t offset_rec_1 = 230;
	uint32_t offset_rec_2 = 320;
	char buf[35] = {0};

	if(number!=num)LCD_Fill_Rectangle(color_background,11, 34+50, 37, 240);
	if(current_posled!=posled){LCD_Fill_Rectangle(color_background,offset_rec_1,34+46, offset_rec_2, 34+46+25);}
	if(current_posled_paral!=posled_paral){LCD_Fill_Rectangle(color_background,offset_rec_1, 34+46+40, offset_rec_2, 34+46+40+25);}
	if(current_paral!=paral){LCD_Fill_Rectangle(color_background,offset_rec_1, 34+46+40*2, offset_rec_2, 34+46+40*2+25);}
	if(blink==1 && counter>0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
		}
		if(num==3){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
		}
		if(num==1)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(ILI9341_RED,11, 34+50+40*2, 35, 34+45+15+40*2);
	}
	if(blink==1 && counter<0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
		}
		if(num==3){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%6.1f A",(float)paral/10);//paral
			LCD_DrawString(offset,34+46+40*2,buf);
			color_text = color1;
			sprintf(buf,"%6.1f A",(float)posled/10);//posled
			LCD_DrawString(offset,34+46,buf);
			sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
			LCD_DrawString(offset,34+46+40,buf);
		}

		if(num==1)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(ILI9341_GREEN,11, 34+50+40*2, 35, 34+45+15+40*2);
	}
	if(blink==0){
		sprintf(buf,"%6.1f A",(float)posled/10);//posled
		LCD_DrawString(offset,34+46,buf);
		sprintf(buf,"%6.1f A",(float)posled_paral/10);//posled_paral
		LCD_DrawString(offset,34+46+40,buf);
		sprintf(buf,"%6.1f A",(float)paral/10);//paral
		LCD_DrawString(offset,34+46+40*2,buf);
		if(num==1)LCD_Fill_Rectangle(ILI9341_WHITE,11, 34+50, 35, 34+45+15);
		else if(num==2)LCD_Fill_Rectangle(ILI9341_WHITE,11, 34+50+40, 35, 34+45+15+40);
		else if(num==3)LCD_Fill_Rectangle(ILI9341_WHITE,11, 34+50+40*2, 35, 34+45+15+40*2);
		counter = 0;
		increment = 1;
	}
	current_posled = posled;
	current_posled_paral = posled_paral;
	current_paral = paral;
	number = num;
	if(blink == 1){
		counter+=increment;
		if(counter>10)increment = -1;
		if(counter<-10)increment = 1;
	}
}
//----------------------------------------------------------------------------------------------------------
void LCD_Synchro(uint16_t synchro, uint8_t blink)
{
	LCD_SendCommand(ILI9341_MAC);
	LCD_SendData(0x28);//E8
	static uint16_t number = 0;
	uint16_t synchro_color;
	static uint8_t blink_before = 0;
	if(number!=synchro){
		LCD_Fill_Rectangle(ILI9341_BLACK,19+number*23, 90, 22+number*23, 137);//solid vertical
		if(number%2==0)LCD_Fill_Rectangle(ILI9341_GREEN,20+number*23,121, 21+number*23, 156);//high vertical 0
		else LCD_Fill_Rectangle(ILI9341_GREEN,20+number*23, 127, 21+number*23, 149);//small vertical 0
	}
	if(blink == 0){
		synchro_color = ILI9341_WHITE;
		LCD_Fill_Rectangle(ILI9341_GREEN,20, 137, 297, 137);//solid horizontal
		LCD_Fill_Rectangle(synchro_color,19+synchro*23, 90, 22+synchro*23, 137);//solid vertical
	}
	else {
		if(number!=synchro || blink_before!=blink){
			synchro_color = ILI9341_RED;
			LCD_Fill_Rectangle(ILI9341_GREEN,20, 137, 297, 140);//solid horizontal
			LCD_Fill_Rectangle(synchro_color,19+synchro*23, 90, 22+synchro*23, 137);//solid vertical
		}
	}
	blink_before = blink;
  number = synchro;
}
//----------------------------------------------------------------------------------------------------------
void LCD_PI(uint8_t num,uint32_t kp,uint32_t ki,uint8_t blink)
{
	static int32_t counter = 0;
	static int8_t increment = 1;
	char buf[35] = {0};
	static uint32_t kp_do = 0;
	static uint32_t ki_do = 0;
	
	if(kp_do!=kp){
		LCD_Fill_Rectangle(color_background,90, 34+46, 200, 34+46+15);
	}
	
	if(ki_do!=ki){
		LCD_Fill_Rectangle(color_background,90, 34+46+40, 200, 34+46+40+15);
	}
	
	kp_do = kp;
	ki_do = ki;
	
	if(blink==1 && counter>0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_RED;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
		}
	}
	if(blink==1 && counter<0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_GREEN;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
		}
	}
	if(blink==0){
		if(num==1){
			uint16_t color1 = color_text;
			color_text = ILI9341_BLUE;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
		}
		if(num==2){
			uint16_t color1 = color_text;
			color_text = ILI9341_BLUE;
			sprintf(buf,"%c%c = %6.2f",150,180,(float)ki/100);//ki
			LCD_DrawString(40,34+46+40,buf);
			color_text = color1;
			sprintf(buf,"%c%c = %6.2f",150,187,(float)kp/100);//kp
			LCD_DrawString(40,34+46,buf);
		}
		counter = 0;
		increment = 1;
	}
	//number = num;
	if(blink == 1){
		counter+=increment;
		if(counter>50)increment = -1;
		if(counter<-50)increment = 1;
	}
}
//----------------------------------------------------------------------------------------------------------
void LCD_Current(float t1,float t2,float t3,float t4,float shunt,float task,float alfa,uint8_t _en,uint8_t alarm,uint8_t _regum,uint8_t sinchro)
{
		static uint8_t cur_en = 250;
		static uint8_t cur_regum = 250;
		static uint8_t cur_sinchro = 250;
	
		LCD_SendCommand(ILI9341_MAC);
		LCD_SendData(0x28);//E8
		char buf[35] = {0};
		uint32_t poz_x = 220;
		uint16_t color = color_text;
		
		if(alarm==1){
			color_text = ILI9341_RED;
			sprintf(buf,"%4.1f",t1);
			LCD_DrawString_2(poz_x,15+24*1,buf);
			color_text = color;
		}else {
			sprintf(buf,"%4.1f",t1);
			LCD_DrawString_2(poz_x,15+24*1,buf);
		}
		
		if(alarm==2){
			color_text = ILI9341_RED;
			sprintf(buf,"%4.1f",t2);
			LCD_DrawString_2(poz_x,15+24*2,buf);
			color_text = color;
		}else {
			sprintf(buf,"%4.1f",t2);
			LCD_DrawString_2(poz_x,15+24*2,buf);
		}
		
		if(alarm==3){
			color_text = ILI9341_RED;
			sprintf(buf,"%4.1f",t3);
			LCD_DrawString_2(poz_x,15+24*3,buf);
			color_text = color;
		}else {
			sprintf(buf,"%4.1f",t3);
			LCD_DrawString_2(poz_x,15+24*3,buf);
		}
		
		if(alarm==4){
			color_text = ILI9341_RED;
			sprintf(buf,"%4.1f",t4);
			LCD_DrawString_2(poz_x,15+24*4,buf);
			color_text = color;
		}else {
			sprintf(buf,"%4.1f",t4);
			LCD_DrawString_2(poz_x,15+24*4,buf);
		}
		
		sprintf(buf,"%5.1f",shunt);
		LCD_DrawString_2(poz_x-10,15+24*5,buf);

		sprintf(buf,"%5.1f",task);
		LCD_DrawString_2(poz_x-10,15+24*6,buf);

		if(_regum==0 || _en==0){
			color_text = ILI9341_RED;	
			sprintf(buf,"%5.1f",alfa);
			LCD_DrawString_2(poz_x-10,15+24*7,buf);
			color_text = color;
		}else {
			color_text = ILI9341_GREEN;
			sprintf(buf,"%5.1f",alfa);
			LCD_DrawString_2(poz_x-10,15+24*7,buf);
			color_text = color;
		}
		
		if(cur_en!=_en){
			if(_en){color_text = ILI9341_GREEN;sprintf(buf,"%c%c%c%c%c ",175,186,190,186,174);}
			else {color_text = ILI9341_RED;sprintf(buf,"%c%c%c%c%c%c",172,174,172,188,180,203);}
			LCD_DrawString_2(30,15+24*8,buf);
			color_text = color;
		}
		
		if(cur_regum!=_regum){
			if(_regum){color_text = ILI9341_GREEN;sprintf(buf,"%i",_regum);}
			else {color_text = ILI9341_RED;sprintf(buf,"%i",_regum);}
			LCD_DrawString_2(125,15+24*8,buf);
			color_text = color;
		}

		if(sinchro<100)sinchro=0;
		if(cur_sinchro!=sinchro){	
			if(sinchro>=100){color_text = ILI9341_RED;sprintf(buf,"%c%c%c%c%c%c%c%c%c%c%c%c%c",189,180,185,193,188,186,185,180,179,172,194,180,203);}
			else {color_text = ILI9341_GREEN;sprintf(buf,"%c%c%c%c%c%c%c%c%c%c%c%c%c",189,180,185,193,188,186,185,180,179,172,194,180,203);}
			LCD_DrawString_2(180,15+24*8,buf);
			color_text = color;
		}
		
		cur_en = _en;
		cur_regum = _regum;
		cur_sinchro = sinchro;
}
//----------------------------------------------------------------------------------------------------------

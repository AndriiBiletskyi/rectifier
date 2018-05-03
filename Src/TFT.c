#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "stdlib.h"
#include "TFT.h"
#include "TEXT.h"

volatile uint16_t delay = 10000;
volatile uint32_t i = 0;
volatile uint16_t color_text = ILI9341_WHITE;
volatile uint16_t color_background = ILI9341_BLACK;
extern SPI_HandleTypeDef hspi3;
//-----------------------------------------------------
void LCD_Init()
{
		TFT_RST_RESET
		HAL_Delay(1000);
		TFT_RST_SET
		LCD_SendCommand(ILI9341_RESET);

		LCD_SendCommand(ILI9341_POWERA);
		LCD_SendData(0x39);
		LCD_SendData(0x2C);
		LCD_SendData(0x00);
		LCD_SendData(0x34);
		LCD_SendData(0x02);
		LCD_SendCommand(ILI9341_POWERB);
		LCD_SendData(0x00);
		LCD_SendData(0xC1);
		LCD_SendData(0x30);
		LCD_SendCommand(ILI9341_DTCA);
		LCD_SendData(0x85);
		LCD_SendData(0x00);
		LCD_SendData(0x78);
		LCD_SendCommand(ILI9341_DTCB);
		LCD_SendData(0x00);
		LCD_SendData(0x00);
	  LCD_SendCommand(ILI9341_POWER_SEQ);
	  LCD_SendData(0x64);
	  LCD_SendData(0x03);
	  LCD_SendData(0x12);
	  LCD_SendData(0x81);
	  LCD_SendCommand(ILI9341_PRC);
	  LCD_SendData(0x20);
	  LCD_SendCommand(ILI9341_POWER1);
	  LCD_SendData(0x23);
	  LCD_SendCommand(ILI9341_POWER2);
	  LCD_SendData(0x10);
	  LCD_SendCommand(ILI9341_VCOM1);
	  LCD_SendData(0x3E);
	  LCD_SendData(0x28);
	  LCD_SendCommand(ILI9341_VCOM2);
	  LCD_SendData(0x86);
	  LCD_SendCommand(ILI9341_MAC);
	  LCD_SendData(0x08);//0x08
	  LCD_SendCommand(ILI9341_PIXEL_FORMAT);
	  LCD_SendData(0x55);
	  LCD_SendCommand(ILI9341_FRC);
	  LCD_SendData(0x00);
	  LCD_SendData(0x18);
	  LCD_SendCommand(ILI9341_DFC);
	  LCD_SendData(0x08);
	  LCD_SendData(0x82);
	  LCD_SendData(0x27);
	  LCD_SendCommand(ILI9341_3GAMMA_EN);
	  LCD_SendData(0x00);
	  LCD_SendCommand(ILI9341_COLUMN_ADDR);
	  LCD_SendData(0x00);
	  LCD_SendData(0x00);
	  LCD_SendData(0x00);
	  LCD_SendData(0xEF);
	  LCD_SendCommand(ILI9341_PAGE_ADDR);
	  LCD_SendData(0x00);
	  LCD_SendData(0x00);
	  LCD_SendData(0x01);
	  LCD_SendData(0x3F);
	  LCD_SendCommand(ILI9341_GAMMA);
	  LCD_SendData(0x01);
	  LCD_SendCommand(ILI9341_PGAMMA);
	  LCD_SendData(0x0F);
	  LCD_SendData(0x31);
	  LCD_SendData(0x2B);
	  LCD_SendData(0x0C);
	  LCD_SendData(0x0E);
	  LCD_SendData(0x08);
	  LCD_SendData(0x4E);
	  LCD_SendData(0xF1);
	  LCD_SendData(0x37);
	  LCD_SendData(0x07);
	  LCD_SendData(0x10);
	  LCD_SendData(0x03);
	  LCD_SendData(0x0E);
	  LCD_SendData(0x09);
	  LCD_SendData(0x00);
	  LCD_SendCommand(ILI9341_NGAMMA);
	  LCD_SendData(0x00);
	  LCD_SendData(0x0E);
	  LCD_SendData(0x14);
	  LCD_SendData(0x03);
	  LCD_SendData(0x11);
	  LCD_SendData(0x07);
	  LCD_SendData(0x31);
	  LCD_SendData(0xC1);
	  LCD_SendData(0x48);
	  LCD_SendData(0x08);
	  LCD_SendData(0x0F);
	  LCD_SendData(0x0C);
	  LCD_SendData(0x31);
	  LCD_SendData(0x36);
	  LCD_SendData(0x0F);
	  LCD_SendCommand(ILI9341_SLEEP_OUT);
	  i = 0;
	  while(i<16800000){i++;}
	  LCD_SendCommand(ILI9341_DISPLAY_ON);
	  LCD_SendCommand(ILI9341_GRAM);
	  LCD_SendCommand(ILI9341_MAC);
	  LCD_SendData(0x48);//E8
	  delay = 1;
}
//-----------------------------------------------------
void LCD_Fill(uint16_t color)
{
	uint32_t n, i, j;
	i = color >> 8;
	j = color & 0xFF;
	LCD_SetCursorPosition(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

	LCD_SendCommand(ILI9341_GRAM);

	for (n = 0; n < LCD_PIXEL_COUNT; n++) {
		LCD_SendData(i);
		LCD_SendData(j);
	}
}
//-----------------------------------------------------
void LCD_Fill_Rectangle(uint16_t color,uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint32_t n, i, j;
	i = color >> 8;
	j = color & 0xFF;
	LCD_SetCursorPosition(x1, y1, x2, y2);

	LCD_SendCommand(ILI9341_GRAM);

	for (n = 0; n < 320*(y2-y1+1); n++) {
		LCD_SendData(i);
		LCD_SendData(j);
	}
}
//-----------------------------------------------------
void LCD_DrawString(uint32_t x, uint32_t y, char *str)
{
    while(*str) {
        x = LCD_Putchar(x,y,*str++);
    }
}
//-----------------------------------------------------
void LCD_DrawString_2(uint32_t x, uint32_t y, char *str)
{
    while(*str) {
        x = LCD_Putchar_2(x,y,*str++);
    }
}
//-----------------------------------------------------
void LCD_SendCommand(uint16_t com)
{
	TFT_DC_RESET
	spi3_send(com);
	for(i=0;i<delay;i++){}
}
//-----------------------------------------------------
void spi3_send(uint8_t com)
{
	HAL_SPI_Transmit(&hspi3, &com,1,0);
}
//-----------------------------------------------------
void LCD_SendData(uint8_t data)
{
	TFT_DC_SET
	spi3_send(data);
}
//-----------------------------------------------------
uint32_t LCD_Putchar(uint32_t x, uint32_t y, char c)
{
    uint32_t i, j;
    unsigned short Data;
    uint32_t offset = (c-32)*TimesNewRoman.height;
    uint16_t width = 0;

    if(offset==0)width=5;

    for (i = 0; i < TimesNewRoman.height; i++) {

        Data = TimesNewRoman.data_table[offset+i];


        for (j = 0; j < TimesNewRoman.width; j++) {//j < width
            if ((Data << j) & 0x8000) {
                LCD_DrawPixel(x + j, (y + i), color_text);  //text
                if(width<j)width=j;
            }
        }
    }

    return x+width+3;
}
//-----------------------------------------------------
uint32_t LCD_Putchar_2(uint32_t x, uint32_t y, char c)
{
    uint32_t i, j;
    unsigned short Data;
    uint32_t offset = (c-32)*TimesNewRoman.height;
    uint16_t width = 0;

    if(offset==0)width=5;

    for (i = 0; i < TimesNewRoman.height; i++) {

        Data = TimesNewRoman.data_table[offset+i];


        for (j = 0; j < TimesNewRoman.width; j++) {//j < width
            if ((Data << j) & 0x8000) {
                LCD_DrawPixel(x + j, (y + i), color_text);  //text
                if(width<j)width=j;
            } else {
                LCD_DrawPixel(x + j, (y + i), color_background);  //background
            }
        }
    }

    return x+width+3;
}
//-----------------------------------------------------
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color) 
{
    LCD_SetCursorPosition(x, y, x, y);
    LCD_SendCommand(ILI9341_GRAM);
    LCD_SendData(color >> 8);
    LCD_SendData(color & 0xFF);
}
//-----------------------------------------------------
void LCD_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    LCD_SendCommand(ILI9341_COLUMN_ADDR);
    LCD_SendData(x1 >> 8);
    LCD_SendData(x1 & 0xFF);
    LCD_SendData(x2 >> 8);
    LCD_SendData(x2 & 0xFF);

    LCD_SendCommand(ILI9341_PAGE_ADDR);
    LCD_SendData(y1 >> 8);
    LCD_SendData(y1 & 0xFF);
    LCD_SendData(y2 >> 8);
    LCD_SendData(y2 & 0xFF);
}
//-----------------------------------------------------
void LCD_Image(unsigned char const *img)
{
	LCD_SendCommand(ILI9341_MAC);
	LCD_SendData(0x48);//E8
	uint32_t n;
    LCD_SetCursorPosition(0, 0, LCD_HEIGHT - 1, LCD_WIDTH - 1);
    LCD_SendCommand(ILI9341_GRAM);
    for (n = 0; n < LCD_PIXEL_COUNT; n++) {
    	uint8_t color = *img;
    	img++;
        LCD_SendData(*img);
        LCD_SendData(color);
        img++;
    }
}
//-----------------------------------------------------

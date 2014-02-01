/*
 * oled.h
 *
 * Created: 02.11.2012 12:09:43
 *  Author: Are.Halvorsen
 */ 


#ifndef OLED_H_
#define OLED_H_

#include "sam.h"

/* Command table */

/* Single byte commands */

#define OLED_ENTIRE_DISPLAY_OFF		0xA4
#define OLED_ENTIRE_DISPLAY_ON		0xA5
#define OLED_SET_DISPLAY_NORMAL		0xA6
#define OLED_SET_DISPLAY_INVERSE	0xA6
#define OLED_SET_DISPLAY_OFF		0xAE
#define OLED_SET_DISPLAY_ON			0xAF
#define OLED_SCROLL_DEACTIVATE		0x2E
#define OLED_SCROLL_ACTIVATE		0x2F
#define OLED_SET_START_PAGE(_page)	(0xB0 | (_page & 0x07))
#define OLED_SET_START_LINE(_line)  (0x40 | (_line & 0x3F))
#define OLED_SET_SEG_REMAP_NORM		0xA0
#define OLED_SET_SEG_REMAP_REW		0xA1


// Multibyte commands
#define OLED_SET_CONTRAST			0x81  // 1 byte param
#define OLED_SCROLL_HZ_RIGHT		0x26  // 6 byte param, (dummy 0x00, start , interval, end, dummy 0x00, dummy 0xFF)
#define OLED_SCROLL_HZ_LEFT			0x27  // 6 byte param, (dummy 0x00, start , interval, end, dummy 0x00, dummy 0xFF)
#define OLED_SCROLL_VC_RIGHT		0x29  // 5 byte param, (dummy, start, interval, end, vertical offset)
#define OLED_SCROLL_VC_LEFT			0x2A  // 5 byte param, (dummy, start, interval, end, vertical offset)
#define OLED_SCROLL_SET_VC_AREA		0xA3  // 2 byte param, (rows fixed, rows scroll)
#define OLED_SET_ADDRESS_MODE		0x20  // 1 byte param,
#define OLED_SET_COL_ADDRESS		0x21  // 2 byte param, (start, stop)
#define OLED_SET_PAGE_ADDRESS		0x22  // 2 byte param, (start, stop)
#define OLED_SET_MUX_RATIO			0xA8  // 1 byte param

//Hardware Configuration
#define OLED_SET_COM_SCAN_DIR_NORM  0xC0
#define OLED_SET_COM_SCAN_DIR_REW   0xC8
#define OLED_SET_DISP_OFFSET		0xD3  // 1 byte param
#define OLED_SET_COM_HW_CONF		0xDA  // 1 byte param

//Timing & Driving Scheme Setting Command Table
#define OLED_SET_FREQUENCY  		0xD5  // 1 byte param
#define OLED_SET_PRECHARGE  		0xD9  // 1 byte param
#define OLED_SET_VCOM_DESELECT		0xDB  // 1 byte param
#define OLED_NOP			 		0xE3  // 1 byte param

/* MACROS */
#define LCD_Select()    GPIO->GPIO_PORT[PIN_PB11/32].GPIO_OVRC = GPIO_PB11;
#define LCD_DeSelect()	GPIO->GPIO_PORT[PIN_PB11/32].GPIO_OVRS = GPIO_PB11;

#define LCD_DATA    1
#define LCD_COMMAND 2

#define LCD_RESET_CLEAR()	GPIO->GPIO_PORT[PIN_PC09/32].GPIO_OVRC = GPIO_PC09
#define LCD_RESET_SET()		GPIO->GPIO_PORT[PIN_PC09/32].GPIO_OVRS = GPIO_PC09

#define LCD_Sel_Data()      GPIO->GPIO_PORT[PIN_PC08/32].GPIO_OVRS = GPIO_PC08
#define LCD_Sel_Command()   GPIO->GPIO_PORT[PIN_PC08/32].GPIO_OVRC = GPIO_PC08

void SPI_Write_text(uint8_t * string);
void SPI_Send_Buffer(uint8_t * cmd, uint16_t length, uint8_t select);
void LCD_Init(void);

#endif /* OLED_H_ */
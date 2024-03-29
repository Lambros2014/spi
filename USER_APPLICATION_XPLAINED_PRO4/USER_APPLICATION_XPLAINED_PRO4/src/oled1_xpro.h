/*
 * oled1_xpro.h
 *
 * Created: 02.11.2012 10:31:38
 *  Author: Are.Halvorsen
 */ 


#ifndef OLED1_XPRO_H_
#define OLED1_XPRO_H_

//#include "SAM4L_XPRO.h"

//Buttons
#define OLED1_BUTTON1_GPIO	EXT2_GPIO09
#define OLED1_BUTTON1_PIN	EXT2_PIN09
#define OLED1_BUTTON2_GPIO	EXT2_GPIO03
#define OLED1_BUTTON2_PIN	EXT2_PIN03
#define OLED1_BUTTON3_GPIO	EXT2_GPIO04
#define OLED1_BUTTON3_PIN	EXT2_PIN04

//LEDs
#define OLED1_LED1_GPIO		EXT2_GPIO07
#define OLED1_LED1_PIN		EXT2_PIN07
#define OLED1_LED2_GPIO		EXT2_GPIO08
#define OLED1_LED2_PIN		EXT2_PIN08
#define OLED1_LED3_GPIO		EXT2_GPIO06
#define OLED1_LED3_PIN		EXT2_PIN06

//OLED Display
#define OLED1_DATACMD_GPIO			EXT2_GPIO05
#define OLED1_DATACMD_PIN			EXT2_PIN05
#define OLED1_DISPLAY_RESET_GPIO	EXT2_GPIO10
#define	OLED1_DISPLAY_RESET_PIN		EXT2_PIN10
#define OELD1_DISPLAY_MOSI_GPIO		EXT2_GPIO16
#define OLED1_DISPLAY_MOSI_PIN		EXT2_PIN16
#define OLED1_DISPLAY_SCK_GPIO		EXT2_GPIO18
#define OLED1_DISPLAY_SCK_PIN		EXT2_PIN18
#define OLED1_DISPLAY_SS_GPIO		EXT2_GPIO15
#define OLED1_DISPLAY_SS_PIN		EXT2_PIN15

#endif /* OLED1_XPRO_H_ */
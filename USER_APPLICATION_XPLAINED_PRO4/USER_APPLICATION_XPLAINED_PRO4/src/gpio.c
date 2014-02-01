/*
 * gpio.c
 *
 * Created: 29.10.2012 11:24:55
 *  Author: Are.Halvorsen
 */ 

#include <stdbool.h>

#include "sam.h"
#include "gpio.h"

void gpio_set_mux(uint32_t gpio, uint32_t pin, uint32_t mux){

	if ( mux & (1 << 0) ) { 
		GPIO->GPIO_PORT[pin/32].GPIO_PMR0S = gpio;
	} else {
		GPIO->GPIO_PORT[pin/32].GPIO_PMR0C = gpio;
	}
	
	if ( mux & (1 << 1) ) {
		GPIO->GPIO_PORT[pin/32].GPIO_PMR1S = gpio;
		} else {
		GPIO->GPIO_PORT[pin/32].GPIO_PMR1C = gpio;
	}
	
	if ( mux & (1 << 2) ) {
		GPIO->GPIO_PORT[pin/32].GPIO_PMR2S = gpio;
		} else {
		GPIO->GPIO_PORT[pin/32].GPIO_PMR2C = gpio;
	}
	
}

void gpio_disable_register(uint32_t gpio, uint32_t pin)
{
	GPIO->GPIO_PORT[pin/32].GPIO_GPERC = gpio;
}

void gpio_set_input(uint32_t gpio, uint32_t pin){
	
	GPIO->GPIO_PORT[pin/32].GPIO_GPERS = gpio; //Enable GPIO
	GPIO->GPIO_PORT[pin/32].GPIO_STERS = gpio; //Enable schmitt trigger
	GPIO->GPIO_PORT[pin/32].GPIO_ODERC = gpio; //Disable Output Driver
	
}

void gpio_set_output(uint32_t gpio, uint32_t pin){
	
	GPIO->GPIO_PORT[pin/32].GPIO_GPERS = gpio; //Enable GPIO
	GPIO->GPIO_PORT[pin/32].GPIO_STERC = gpio; //Disable schmitt trigger
	GPIO->GPIO_PORT[pin/32].GPIO_ODERS = gpio; //Enable Output Driver
	
}

void gpio_set_high(uint32_t gpio, uint32_t pin)
{
	GPIO->GPIO_PORT[pin/32].GPIO_OVRS  = gpio;
}

void gpio_set_low(uint32_t gpio, uint32_t pin)
{
	GPIO->GPIO_PORT[pin/32].GPIO_OVRC  = gpio;
}

void gpio_toggle(uint32_t gpio, uint32_t pin)
{
	GPIO->GPIO_PORT[pin/32].GPIO_OVRT  = gpio;
}

void gpio_set_level(uint32_t gpio, uint32_t pin, bool level)
{
	if(level)
		gpio_set_high(gpio, pin);
	else
		gpio_set_low(gpio, pin);
}

bool gpio_get_output(uint32_t gpio, uint32_t pin)
{
	return ((GPIO->GPIO_PORT[pin/32].GPIO_PVR & gpio) == 0);
}

volatile uint8_t btn0 = 1;
volatile uint8_t btn1 = 1;
volatile uint8_t btn2 = 1;
volatile uint8_t btn3 = 1;
/*
uint8_t gpio_read_button(uint8_t number){
	
	uint8_t state = 0;
	
	switch(number){
		case 0: 
			//Button 0
			if(btn0 == 1) {
				if( (GPIO->GPIO_PORT[BUTTON0_PIN/32].GPIO_PVR & BUTTON0_GPIO) == 0 ){
					btn0 = 0;
					state = 1;
				}
			} else {
				if( GPIO->GPIO_PORT[BUTTON0_PIN/32].GPIO_PVR & BUTTON0_GPIO ){
					btn0 = 1;
				}
			}			
			break;
		case 1:
			//Button 1
			if(btn1 == 1) {
				if( (GPIO->GPIO_PORT[OLED1_BUTTON1_PIN/32].GPIO_PVR & OLED1_BUTTON1_GPIO) == 0 ){
					btn1 = 0;
					state = 1;
				}
			} else {
				if( GPIO->GPIO_PORT[OLED1_BUTTON1_PIN/32].GPIO_PVR & OLED1_BUTTON1_GPIO ){
					btn1 = 1;
				}
			}			
			break;
		case 2:
			//Button 2
			if(btn2 == 1) {
				if( (GPIO->GPIO_PORT[OLED1_BUTTON2_PIN/32].GPIO_PVR & OLED1_BUTTON2_GPIO) == 0 ){
					btn2 = 0;
					state = 1;
				}
			} else {
				if( GPIO->GPIO_PORT[OLED1_BUTTON2_PIN/32].GPIO_PVR & OLED1_BUTTON2_GPIO ){
					btn2 = 1;
				}
			}		
			break;
		case 3:
			//Button 3
			if(btn3 == 1) {
				if( (GPIO->GPIO_PORT[OLED1_BUTTON3_PIN/32].GPIO_PVR & OLED1_BUTTON3_GPIO) == 0 ){
					btn3 = 0;
					state = 1;
				}
			} else {
				if( GPIO->GPIO_PORT[OLED1_BUTTON3_PIN/32].GPIO_PVR & OLED1_BUTTON3_GPIO ){
					btn3 = 1;
				}
			}		
			break;
		default:
			break;
			
	}	
	
	return state;
}
*/
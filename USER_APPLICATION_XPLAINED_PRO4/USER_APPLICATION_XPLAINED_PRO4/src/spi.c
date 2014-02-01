/*
 * spi.c
 *
 * Created: 01.02.2014 03:12:39
 *  Author: student
 */ 

#include <asf.h>
#include "gpio.h"
#include <stdint.h>
#include "spi.h"

void spi_ss_enable()
{
	gpio_set_low(EXT1_GPIO_SPI_SS_0, EXT1_PIN_SPI_SS_0);
}

void spi_ss_disable()
{
	gpio_set_high(EXT1_GPIO_SPI_SS_0, EXT1_PIN_SPI_SS_0);
}

void spi_send_byte(uint8_t data_byte){	
	SPI->SPI_TDR |= data_byte;
	while (!(SPI->SPI_SR & SPI_SR_TDRE));
}

void spi_init(void){
	
	
	// disable GPIO ports
	
	gpio_disable_register(EXT1_GPIO_SPI_MOSI, EXT1_PIN_SPI_MOSI); // usikker på SPI_MOSI_GPIO
	gpio_disable_register(EXT1_GPIO_SPI_SCK, EXT1_PIN_SPI_SCK); // usikker på SPI_SPCK_GPIO
	
	
	gpio_set_mux(EXT1_GPIO_SPI_MOSI, EXT1_PIN_SPI_MOSI, EXT1_SPI_SS_MOSI);
	gpio_set_mux(EXT1_GPIO_SPI_SCK, EXT1_PIN_SPI_SCK, EXT1_SPI_SS_SCK);
	
	// CS pin as output
	gpio_set_output(EXT1_GPIO_SPI_SS_0, EXT1_PIN_SPI_SS_0);
	gpio_set_high(EXT1_GPIO_SPI_SS_0, EXT1_PIN_SPI_SS_0);
	

	// alt som kommer etter dette er magi



	// Enable SPI clock.
	PM->PM_UNLOCK = PM_UNLOCK_KEY(0xAA) | PM_UNLOCK_ADDR(0x028);
	PM->PM_PBAMASK |= PM_PBAMASK_SPI;
	
	// Set up SPI mode
	SPI->SPI_MR |= SPI_MR_MSTR | SPI_MR_MODFDIS | SPI_MR_PCS(0b1011);
	
	
	
	
	// Configure NPCS2
	SPI->SPI_CSR[2] |= SPI_CSR_SCBR(1) | SPI_CSR_DLYBCT(0x01) | SPI_CSR_CPOL;
	
	//Enable the SPI module.
	SPI->SPI_CR |= SPI_CR_SPIEN;
	

}

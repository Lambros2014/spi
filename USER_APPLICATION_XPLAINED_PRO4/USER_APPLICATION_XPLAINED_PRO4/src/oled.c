/*
 * oled.c
 *
 * Created: 02.11.2012 12:09:12
 *  Author: Are.Halvorsen
 */ 

#include "oled.h"
#include "oled1_xpro.h"
#include "gpio.h"


uint8_t char_set[30][5] = {
	{ 0xFE, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	
};



unsigned char rawData[268] =
{
	0x00, 0x00, 0x00, 0x0F,
	0x00, 0x00, 0x00, 0xCF,
	0x00, 0x00, 0x03, 0xCF,
	0x00, 0x00, 0x0F, 0xCF,
	0x00, 0x00, 0x3F, 0xCF,
	0x00, 0x00, 0xFF, 0xCF,
	0x00, 0x01, 0xFF, 0xCF,
	0x00, 0x07, 0xFF, 0xCF,
	0x00, 0x1F, 0xF8, 0x0F,
	0x00, 0x7F, 0xF0, 0x0F,
	0x01, 0xFF, 0xFF, 0xCF,
	0x01, 0xFF, 0xFF, 0xCF,
	0x0D, 0xFF, 0xFF, 0xCF,
	0x3D, 0xFF, 0xFF, 0xCF,
	0x7D, 0xFF, 0xFF, 0xCF,
	0xFC, 0x00, 0x00, 0x0F,
	0xFC, 0x00, 0x00, 0x0F,
	0xFF, 0xFF, 0xFF, 0xCF,
	0xFF, 0xFF, 0xFF, 0xCF,
	0xFF, 0xFF, 0xFF, 0xCF,
	0xFF, 0xFF, 0xFF, 0xCF,
	0xFF, 0xFF, 0xFF, 0xCF,
	0xFC, 0x00, 0x00, 0x0F,
	0xFC, 0x00, 0x00, 0x0F,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xC0, 0x00, 0x0F,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xC0, 0x00, 0x0F,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFC, 0xFF, 0xFF, 0xCF,
	0xFC, 0xFF, 0xFF, 0xCF,
	0xFC, 0x7F, 0xFF, 0xCF,
	0xFC, 0x00, 0x00, 0x0F,
	0xFC, 0x00, 0x00, 0x0F,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFD, 0xFB, 0xE7, 0xCF,
	0xFC, 0x00, 0x00, 0x0F,
	0xFC, 0x00, 0x00, 0x0F,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFD, 0xFF, 0xFF, 0xCF,
	0xFC, 0x00, 0x07, 0xCE,
	0xFC, 0x00, 0x07, 0xC8,
	0xFC, 0x00, 0x07, 0xC0,
	0xFC, 0x00, 0x07, 0x80,
	0xFC, 0x00, 0x06, 0x00,
} ;

uint8_t cmd_buffer[20];
uint8_t initialized = 0;
uint8_t LCD_buffer[20];

void SPI_Send_Buffer(uint8_t * cmd, uint16_t length, uint8_t select){
	
	uint16_t i = 0;

	if(select == LCD_DATA){
		LCD_Sel_Data();
		}else{
		LCD_Sel_Command();
	}
	
	LCD_Select();
	//SPI->SPI_MR = (SPI->SPI_MR & ~SPI_MR_PCS(0b1111)) | SPI_MR_PCS(0b1011);
	
	for (i = 0; i < length; i++) {
		
		SPI->SPI_TDR |= cmd[i];
		while (!(SPI->SPI_SR & SPI_SR_TDRE));

	}
	
	LCD_DeSelect();
	//SPI->SPI_MR |= SPI_MR_PCS(0b1111);
	
}

void SPI_Send_Byte(uint8_t select, uint8_t data_byte){

	if(select == LCD_DATA){
		LCD_Sel_Data();
		}else{
		LCD_Sel_Command();
	}
	
	//SPI->SPI_MR = (SPI->SPI_MR & ~SPI_MR_PCS(0b1111)) | SPI_MR_PCS(0b1011);
	LCD_Select();
	
	SPI->SPI_TDR |= data_byte;
	while (!(SPI->SPI_SR & SPI_SR_TDRE));

	//SPI->SPI_MR |= SPI_MR_PCS(0b1111);
	LCD_DeSelect();
}

void SPI_write_byte(int8_t data_byte){
	
	SPI->SPI_TDR |= data_byte;
	while (!(SPI->SPI_SR & SPI_SR_TDRE));
	
}


void LCD_Poweron_Reset(void){
	
	LCD_RESET_CLEAR();
	
	//Wait for minimum 100ms
	//delay_us(100000);
	uint8_t i,j;
	
	for(i=0; i!=255; i++){
		for(j=0; j!=255; j++){
			asm("nop");
		}
	}
	
	//Reset low pulse
	LCD_RESET_SET();
	
}

void LCD_Powerdown(void){
	
	//Set Display off
	LCD_buffer[0] = 0xAE;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);
	
	//Disable charge pump
	LCD_buffer[0] = 0x8D;
	LCD_buffer[1] = 0x10;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	uint8_t i,j;
	
	for(i=0; i!=255; i++){
		for(j=0; j!=255; j++){
			asm("nop");
		}
	}
	
}

void LCD_Init(void){
	
	GPIO->GPIO_PORT[OLED1_DISPLAY_MOSI_PIN/32].GPIO_GPERC = OELD1_DISPLAY_MOSI_GPIO;
	GPIO->GPIO_PORT[OLED1_DISPLAY_SCK_PIN/32].GPIO_GPERC = OLED1_DISPLAY_SCK_GPIO;
	
	gpio_set_mux(OELD1_DISPLAY_MOSI_GPIO, OLED1_DISPLAY_MOSI_PIN, MUX_PERIPHERAL_A);
	gpio_set_mux(OLED1_DISPLAY_SCK_GPIO, OLED1_DISPLAY_SCK_PIN, MUX_PERIPHERAL_B);
	
	// CS pin as output
	gpio_set_output(OLED1_DISPLAY_SS_GPIO, OLED1_DISPLAY_SS_PIN);
	GPIO->GPIO_PORT[OLED1_DISPLAY_SS_PIN/32].GPIO_OVRS = OLED1_DISPLAY_SS_GPIO;
	
	// OLED reset pin as output
	gpio_set_output(OLED1_DISPLAY_RESET_GPIO, OLED1_DISPLAY_RESET_PIN);
	GPIO->GPIO_PORT[OLED1_DISPLAY_RESET_PIN/32].GPIO_OVRS = OLED1_DISPLAY_RESET_GPIO;
	
	// OLED data/cmd pin as output
	gpio_set_output(OLED1_DATACMD_GPIO, OLED1_DATACMD_PIN);
	GPIO->GPIO_PORT[OLED1_DATACMD_PIN/32].GPIO_OVRS = OLED1_DATACMD_GPIO;

	// Enable SPI clock.
	PM->PM_UNLOCK = PM_UNLOCK_KEY(0xAA) | PM_UNLOCK_ADDR(0x028);
	PM->PM_PBAMASK |= PM_PBAMASK_SPI;
	
	// Set up SPI mode
	SPI->SPI_MR |= SPI_MR_MSTR | SPI_MR_MODFDIS | SPI_MR_PCS(0b1011);
	
	// Configure NPCS2
	SPI->SPI_CSR[2] |= SPI_CSR_SCBR(1) | SPI_CSR_DLYBCT(0x01) | SPI_CSR_CPOL;
	
	//Enable the SPI module.
	SPI->SPI_CR |= SPI_CR_SPIEN;
	
	LCD_Poweron_Reset();
	#if 1 //128x32
	//Set Display off
	LCD_buffer[0] = OLED_SET_DISPLAY_OFF;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);
	
	//Set Display clock Div Ration
	LCD_buffer[0] = OLED_SET_FREQUENCY;
	LCD_buffer[1] = 0x80;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display mux ratio
	LCD_buffer[0] = OLED_SET_MUX_RATIO;
	LCD_buffer[1] = 0x1F;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display offset
	LCD_buffer[0] = OLED_SET_DISP_OFFSET;
	LCD_buffer[1] = 0x00;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display Start line
	LCD_buffer[0] = OLED_SET_START_LINE(0);
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Enable charge pump
	LCD_buffer[0] = 0x8D;
	LCD_buffer[1] = 0x14;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Display Segment remap
	LCD_buffer[0] = OLED_SET_SEG_REMAP_REW;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display COM Scan Direction
	LCD_buffer[0] = OLED_SET_COM_SCAN_DIR_REW;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set COM pins HW Config
	LCD_buffer[0] = OLED_SET_COM_HW_CONF;
	LCD_buffer[1] = 0x02;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Contrast
	LCD_buffer[0] = OLED_SET_CONTRAST;
	LCD_buffer[1] = 0x8F;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Precharge
	LCD_buffer[0] = OLED_SET_PRECHARGE;
	LCD_buffer[1] = 0x22;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set VCOMH Deselect Level
	LCD_buffer[0] = OLED_SET_VCOM_DESELECT;
	LCD_buffer[1] = 0x40;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Display On/Off
	LCD_buffer[0] = OLED_ENTIRE_DISPLAY_OFF;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display Normal/Inverse
	LCD_buffer[0] = OLED_SET_DISPLAY_NORMAL;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display On
	LCD_buffer[0] = OLED_SET_DISPLAY_ON;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);
	#else //128x64

	//Set Display off
	LCD_buffer[0] = OLED_SET_DISPLAY_OFF;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);
	
	//Set Display clock Div Ration
	LCD_buffer[0] = OLED_SET_FREQUENCY;
	LCD_buffer[1] = 0x80;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display mux ratio
	LCD_buffer[0] = OLED_SET_MUX_RATIO;
	LCD_buffer[1] = 0x1F;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display offset
	LCD_buffer[0] = OLED_SET_DISP_OFFSET;
	LCD_buffer[1] = 0x00;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
	
	//Set Display Start line
	LCD_buffer[0] = OLED_SET_START_LINE(0);
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Enable charge pump
	LCD_buffer[0] = 0x8D;
	LCD_buffer[1] = 0x14;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Display Segment remap
	LCD_buffer[0] = OLED_SET_SEG_REMAP_REW;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display COM Scan Direction
	LCD_buffer[0] = OLED_SET_COM_SCAN_DIR_REW;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set COM pins HW Config
	LCD_buffer[0] = OLED_SET_COM_HW_CONF;
	LCD_buffer[1] = 0x12;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Contrast
	LCD_buffer[0] = OLED_SET_CONTRAST;
	LCD_buffer[1] = 0x9F;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Precharge
	LCD_buffer[0] = OLED_SET_PRECHARGE;
	LCD_buffer[1] = 0x22;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set VCOMH Deselect Level
	LCD_buffer[0] = OLED_SET_VCOM_DESELECT;
	LCD_buffer[1] = 0x30;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);

	//Set Display On/Off
	LCD_buffer[0] = OLED_ENTIRE_DISPLAY_OFF;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display Normal/Inverse
	LCD_buffer[0] = OLED_SET_DISPLAY_NORMAL;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);

	//Set Display On
	LCD_buffer[0] = OLED_SET_DISPLAY_ON;
	SPI_Send_Buffer(&LCD_buffer[0], 1, LCD_COMMAND);
	#endif

	//Clear all RAM
	for(uint8_t page = 0; page<8; page++) {
		SPI_Send_Byte(LCD_COMMAND, OLED_SET_START_PAGE(page));
		for(uint8_t col = 0; col<128; col++){
			SPI_Send_Byte(LCD_DATA, 0x00);
		}
	}

	SPI_Send_Byte(LCD_COMMAND, OLED_SET_START_PAGE(0));

	LCD_buffer[0] = 0x22;
	LCD_buffer[1] = 0;
	LCD_buffer[2] = 3;
	SPI_Send_Buffer(&LCD_buffer[0], 3, LCD_COMMAND);

	LCD_buffer[0] = OLED_SET_ADDRESS_MODE;
	LCD_buffer[1] = 0x00;
	SPI_Send_Buffer(&LCD_buffer[0], 2, LCD_COMMAND);
}


void SPI_Write_text(uint8_t * string){
	
	uint8_t * char_ptr;
	uint8_t i;
	//volatile uint8_t testbyte = 0;
	
	LCD_Select();
	LCD_Sel_Data();
	
	while(*string != 0){
		char_ptr = fontz_table[(*string - 32) & 0x7F];
		for(i = 1; i <= char_ptr[0]; i++){
			SPI_write_byte(char_ptr[i]);
		}
		SPI_write_byte(0x00);
		string++;
		
		
	}
	LCD_DeSelect();
}

uint8_t flipbits(uint8_t input){
	uint8_t temp = 0;
	
	if (input&0x01) temp |= 0x80;
	if (input&0x02) temp |= 0x40;
	if (input&0x04) temp |= 0x20;
	if (input&0x08) temp |= 0x10;
	if (input&0x10) temp |= 0x08;
	if (input&0x20) temp |= 0x04;
	if (input&0x40) temp |= 0x02;
	if (input&0x80) temp |= 0x01;
	
	return temp;
}
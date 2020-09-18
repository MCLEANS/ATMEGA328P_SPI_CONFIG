/*
 * AVR_SPI.cpp
 *
 * Created: 1/16/2020 8:15:19 AM
 * Author : MCLEANS
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"

#define MOSI_PORT_DIRECTION DDRB
#define SCLK_PORT_DIRECTION DDRB
#define MOSI_PIN PINB3
#define SCLK_PIN PINB5
#define SS_PORT_DIRECTION DDRB
#define SS_PORT PORTB
#define SS_PIN PINB2

void init_spi_master(){
	
	//set MOSI AND SCK to output
	MOSI_PORT_DIRECTION |= (1<<MOSI_PIN);
	SCLK_PORT_DIRECTION |= (1<<SCLK_PIN);
	//Enable master mode
	//set clock frequency to fosc/64
	//Enable the SPI
	//CPOL = 0, CPHA = 0
	SPCR |= (1<<MSTR)|(1<<SPR1)|(1<<SPE);
	
}


int main(void)
{
    /* Replace with your application code */
	init_spi_master();
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	SS_PORT_DIRECTION |= (1<<SS_PIN);
	
	char sent_bytes = 'H';

	SS_PORT &= ~(1<<SS_PIN);
		SPDR = sent_bytes;
		while(!(SPSR & (1<< SPIF)));
		SS_PORT |=(1<<SS_PIN);
							
	
	while (1)
	{
		
	}
		
}


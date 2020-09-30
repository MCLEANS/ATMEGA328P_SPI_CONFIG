#include "SPI.h"

namespace custom_libraries{

SPI::SPI(uint8_t prescaler,bool phase,bool polarity,bool LSBFIRST):prescaler(prescaler),
																	phase(phase),
																	polarity(polarity),
																	LSBFIRST(LSBFIRST){
 /*   //set MOSI AND SCK to output
	MOSI_PORT_DIRECTION |= (1<<MOSI_PIN);
	SCLK_PORT_DIRECTION |= (1<<SCLK_PIN);
	//set MISO pin to Input
	MISO_PORT_DIRECTION &= ~(1<<MISO_PIN);
	//Enable master mode
	SPCR |= (1<<MSTR);
	//set clock frequency to fosc/64
	if(this->prescaler == 4){
		SPCR &= ~(1<<SPR0);
		SPCR &= ~(1<<SPR1);
		SPSR &= ~(1<<SPI2X);
	}
	if(this->prescaler == 16){
		SPCR |= (1<<SPR0);
		SPCR &= ~(1<<SPR1);
		SPSR &= ~(1<<SPI2X);
	}
	if(this->prescaler == 64){
		SPCR &= ~(1<<SPR0);
		SPCR |= (1<<SPR1);
		SPSR &= ~(1<<SPI2X);
	}
	if(this->prescaler == 128){
		SPCR |= (1<<SPR0);
		SPCR |= (1<<SPR1);
		SPSR &= ~(1<<SPI2X);
	}
	if(this->prescaler == 2){
		SPCR &= ~(1<<SPR0);
		SPCR &= ~(1<<SPR1);
		SPSR |= (1<<SPI2X);
	}
	if(this->prescaler == 8){
		SPCR |= (1<<SPR0);
		SPCR &= ~(1<<SPR1);
		SPSR |= (1<<SPI2X);
	}
	if(this->prescaler == 32){
		SPCR &= ~(1<<SPR0);
		SPCR |= (1<<SPR1);
		SPSR |= (1<<SPI2X);
	}

	//Set clock polarity
	if(this->polarity){
		SPCR |= (1<<CPOL);
	}
	else{
		SPCR &= ~(1<<CPOL);
	}

	//Set clock phase
	if(this->phase){
		SPCR |= (1<<CPHA);
	}
	else{
		SPCR &= ~(1<<CPHA);
	}

	//set byte order MSB or LSB first
	if(this->LSBFIRST){
		SPCR |= (1<<DORD);
	}
	else{
		SPCR &= ~(1<<DORD);
	}

	//Enable the SPI
	SPCR |= (1<<SPE);   
*/
MOSI_PORT_DIRECTION |= (1<<MOSI_PIN);
	SCLK_PORT_DIRECTION |= (1<<SCLK_PIN);
	//Enable master mode
	//set clock frequency to fosc/64
	//Enable the SPI
	//CPOL = 0, CPHA = 0
	SPCR |= (1<<MSTR)|(1<<SPR1)|(1<<SPE);                                 
                                        
}

void SPI::write(char data){
    SPDR = data;
	while(!(SPSR & (1<< SPIF))){}
}

char SPI::read(char junk){
	SPDR = junk;
	while(!(SPSR & (1<< SPIF))){}
	return SPDR;
}

SPI::~SPI(){

}


}



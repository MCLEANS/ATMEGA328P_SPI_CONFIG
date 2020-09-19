#include "SPI.h"



SPI::SPI(bool phase,bool polarity):phase(phase),
                                    polarity(polarity){
    //set MOSI AND SCK to output
	MOSI_PORT_DIRECTION |= (1<<MOSI_PIN);
	SCLK_PORT_DIRECTION |= (1<<SCLK_PIN);
	//Enable master mode
	//set clock frequency to fosc/64
	//Enable the SPI
	//CPOL = 0, CPHA = 0
	SPCR |= (1<<MSTR)|(1<<SPR1)|(1<<SPE);                                    
                                        
}

void SPI::transmit(uint8_t data){
    SPDR = data;
	while(!(SPSR & (1<< SPIF)));
}

SPI::~SPI(){

}


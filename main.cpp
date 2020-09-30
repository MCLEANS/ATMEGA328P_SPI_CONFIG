/*
 * AVR_SPI.cpp
 *
 * Created: 9/30/2020 8:15:19 AM
 * Author : MCLEANS
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"

custom_libraries::SPI spi(2,false,false,false);

int main(void){

	//configure chip select pin
	DDRB |= (1 << PIN2);
	PORTB |= (1<<PIN2);

	PORTB &= ~(1 << PIN2);
	spi.write('S');
	PORTB |= (1<< PIN2);

	while (1){

	}
}


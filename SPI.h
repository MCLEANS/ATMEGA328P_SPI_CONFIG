#ifndef _SPI_H
#define _SPI_H

#include <avr/io.h>

#define MOSI_PORT_DIRECTION DDRB
#define SCLK_PORT_DIRECTION DDRB
#define MOSI_PIN PINB3
#define SCLK_PIN PINB5
#define SS_PORT_DIRECTION DDRB
#define SS_PORT PORTB
#define SS_PIN PINB2


    

class SPI{
    private:
        uint8_t _SPI;
        bool phase;
        bool polarity; 
        uint8_t prescaler;       
    private:
    public:
    public:
        SPI(uint8_t _SPI = 1,bool phase,bool polarity,uint8_t prescaler);
        void transmit(uint8_t data);
        ~SPI();
};




#endif //_SPI_H
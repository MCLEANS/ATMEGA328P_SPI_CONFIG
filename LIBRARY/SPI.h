#ifndef _SPI_H
#define _SPI_H

#include <avr/io.h>

#define MOSI_PORT_DIRECTION DDRB
#define SCLK_PORT_DIRECTION DDRB
#define MISO_PORT_DIRECTION DDRB
#define MOSI_PIN PINB3
#define SCLK_PIN PINB5
#define MISO_PIN PINB4


namespace custom_libraries{
class SPI{
    private:
        uint8_t prescaler; 
        bool phase;
        bool polarity; 
        bool LSBFIRST;
              
    private:
    public:
    public:
        SPI(uint8_t prescaler,bool phase,bool polarity,bool LSBFIRST);
        void write(char data);
        char read(char junk);
        ~SPI();
};

}

#endif //_SPI_H
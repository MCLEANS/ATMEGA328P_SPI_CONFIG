MCU = atmega328p
TARGET = main
PROGRAMMER =  usbasp
PORT = usb
CC = avr-g++
CFLAGS = -Os -D F_CPU=16000000 -mmcu=$(MCU) 
LFLAGS = -D F_CPU=16000000 -mmcu=$(MCU) 

SOURCES = SPI.cpp
OBJS = SPI.o



all :
	$(CC) $(CFLAGS) -c $(TARGET).cpp $(SOURCES)
	$(CC) $(LFLAGS) -o $(TARGET).elf $(TARGET).o $(OBJS)
	avr-objcopy -O ihex $(TARGET).elf $(TARGET).hex
	avr-size --format=avr --mcu=$(MCU) $(TARGET).elf


flash :
	avrdude -c $(PROGRAMMER) -p m328p -P $(PORT) -U flash:w:$(TARGET).hex

clean :
	rm *.hex *.o *.elf
	

#include <HTinySPI.h>

void HTinySPI::begin(){
    SPI_DDR = (1 << MOSI_DR) | (1 << SCK_DR); // set MOSI and SCK to output, all others are input

    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // enable SPI, Master, and set clock rate fck/16
}

uint8_t HTinySPI::transfer(uint8_t spiData){
    SPDR = spiData; // start transmission

    while (!(SPSR & (1 << SPIF))); // wait for transmission to finish

    return SPDR;
}

void HTinySPI::end(){
    SPCR &= ~(1 << SPE) | ~(1 << MSTR); // disable SPI and Master
}

HTinySPI SPI;
#ifndef TINYSPI_H_INCLUDED
#define TINYSPI_H_INCLUDED

#define SPI_DDR DDRD
#define MOSI_DR PB3
#define MISO_DR PB4
#define SCK_DR PB5

class HTinySPI
{
    public:
        HTinySPI(int SS_DataDirectionRegister, int SS_DataRegister){
            SS_DDR = SS_DataDirectionRegister;
            SS_DR = SS_DataRegister;
        }

        static void begin();
        static uint8_t transfer(uint8_t spiData);
        static void end();

    private:
        int SS_DDR;
        int SS_DR;
};

extern HTinySPI SPI;

#endif
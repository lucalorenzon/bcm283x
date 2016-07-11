/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BCM283X.h
 * Author: X86
 *
 * Created on 8 luglio 2016, 23.20
 */

#ifndef BCM283X_H
#define BCM283X_H

#include <stdint.h>

class BCM283X {
public:
    struct SPIConf{
        uint8_t bitOrder;
        uint16_t clockDiveder;
        uint8_t dataMode;
        uint8_t chipSelect;
        uint8_t chipSelectPolarity;
    };
    enum EXCEPTION{INITIALIZATION_FAIL=-1, CLOSE_FAIL=-2, BEGIN_SPI_FAIL=-3, END_SPI_FAIL=-4};
    BCM283X();
    BCM283X(const BCM283X& orig);
    virtual ~BCM283X();
    void beginSPI(SPIConf conf);
    void beginSPI(uint8_t bitOrder, uint16_t clockDivender, uint8_t dataMode,
                 uint8_t chipSelect, uint8_t chipSelectPolarity);
    void beginSPI(uint8_t chipSelect);
    void endSPI();
    void close();
    uint8_t transfer(uint8_t value);
    void transfern(char *buff, uint32_t lenght);
    void transferb(char *rxBuff, char *txBuff, uint32_t lenght);
private:
    SPIConf spiConfiguration;
    void _beginSPI(uint8_t bitOrder, uint16_t clockDivender, uint8_t dataMode,
             uint8_t chipSelect, uint8_t chipSelectPolarity);

};

#endif /* BCM283X_H */


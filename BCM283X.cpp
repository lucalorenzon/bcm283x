/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BCM283X.cpp
 * Author: X86
 * 
 * Created on 8 luglio 2016, 23.20
 */

#include "BCM283X.h"
#include "bcm2835.h"

BCM283X::BCM283X() {
    if(!bcm2835_init()){
        throw INITIALIZATION_FAIL;
    }
}

BCM283X::BCM283X(const BCM283X& orig) {
    if(!bcm2835_init()){
        throw INITIALIZATION_FAIL;
    }
}

BCM283X::~BCM283X() {
    if(!bcm2835_close()){
        throw CLOSE_FAIL;
    }
}

void BCM283X::beginSPI(BCM283X::SPIConf conf){
    _beginSPI(conf.bitOrder, conf.clockDiveder, conf.dataMode, conf.chipSelect, conf.chipSelectPolarity);
}
void BCM283X::beginSPI(uint8_t bitOrder, uint16_t clockDivender, uint8_t dataMode,
                 uint8_t chipSelect, uint8_t chipSelectPolarity){
    _beginSPI(bitOrder, clockDivender, dataMode, chipSelect, chipSelectPolarity);
}
void BCM283X::beginSPI(uint8_t chipSelect){
    _beginSPI(BCM2835_SPI_BIT_ORDER_LSBFIRST, BCM2835_SPI_CLOCK_DIVIDER_16, BCM2835_SPI_MODE0, chipSelect, 1);
}
void BCM283X::close(){
    if(!bcm2835_close()){
        throw CLOSE_FAIL;
    }
}
void BCM283X::endSPI(){
    if(!bcm2835_close()){
        throw END_SPI_FAIL;
    }
}

uint8_t transfer(uint8_t value){
    return bcm2835_spi_transfer(value);
}
void transfern(char *buff, uint32_t lenght){
    bcm2835_spi_transfern(buff, lenght);
}
void transferb(char *rxBuff, char *txBuff, uint32_t lenght){
    bcm2835_spi_transfernb(txBuff, rxBuff, lenght);
}

void BCM283X::_beginSPI(uint8_t bitOrder, uint16_t clockDivender, uint8_t dataMode,
                 uint8_t chipSelect, uint8_t chipSelectPolarity){
    bcm2835_spi_setBitOrder(bitOrder);
    bcm2835_spi_setClockDivider(clockDivender);
    bcm2835_spi_setDataMode(dataMode);
    bcm2835_spi_chipSelect(chipSelect);
    bcm2835_spi_setChipSelectPolarity(chipSelect, chipSelectPolarity);
    if(!bcm2835_spi_begin()){
        throw BEGIN_SPI_FAIL;
    }
}

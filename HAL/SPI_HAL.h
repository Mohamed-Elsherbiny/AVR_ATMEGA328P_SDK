/*
 * SPI_HAL.h
 *
 * Created: 1/20/2018 1:28:30 PM
 *  Author: Admin
 */ 

#include "hw_types.h"
//#include "gpio.h"
#ifndef SPI_HAL_H_
#define SPI_HAL_H_
#define SPCR 0x2D
#define SPSR 0x2E
#define SPDR 0x2F
#define SPIE 7  
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPIF 7
#define WCOL 6
#define SPI2X 0
#define MOSI 5
#define MISO 6
#define SS 4
#define SCK 7
#define PORTB 0x38
#endif /* SPI_HAL_H_ */
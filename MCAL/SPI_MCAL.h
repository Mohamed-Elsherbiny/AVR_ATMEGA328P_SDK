/*
 * SPI_MCAL.h
 *
 * Created: 1/20/2018 12:05:02 PM
 *  Author: MOHAMED EL-SHERBINY
 */ 

#include "SPI_HAL.h"
#include "gpio.h"
#ifndef SPI_MCAL_H_
#define SPI_MCAL_H_

	
	

typedef enum SPI_Data{
	Slave ,
	Master,
	/*HIGH=1,
	LOW=0,
	OUTPUT=1,
	INPUT=0,*/
	}Master_Slave_obj_E;


typedef struct spi{
	uint8 SPI_PORT;
	Master_Slave_obj_E M_S;
	uint8 Freq;
	}SPI_obj_s;

typedef enum SPI_1{
	PASS_1,
	MASTER_SLAVE_ERROR,
}SPI_ERROR_obj_E;

SPI_ERROR_obj_E SPI_INIT(SPI_obj_s *choice);

SPI_ERROR_obj_E SPI_Transmet(uint8 data);

uint8 SPI_Recive(void);

#endif /* SPI_MCAL_H_ */
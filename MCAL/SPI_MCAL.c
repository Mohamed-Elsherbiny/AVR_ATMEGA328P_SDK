/*
 * SPI_MCAL.c
 *
 * Created: 1/20/2018 12:04:09 PM
 *  Author: Mohamed El-Sherbiny
 */ 
#include "SPI_MCAL.h"

SPI_ERROR_obj_E SPI_INIT(SPI_obj_s *choice)
{
	//Enable SPI AND SPIE
	//HW_WriteBit(SPCR,SPIE,HIGH);
	HW_WriteBit(SPCR,SPE,HIGH);
	if(choice->M_S == Master)
	{
		GPIO_pin_S SPI_MOSI={choice->SPI_PORT,MOSI,OUTPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_SCK={choice->SPI_PORT,SCK,OUTPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_MISO={choice->SPI_PORT,MISO,INPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_SS={choice->SPI_PORT,SS,OUTPUT,NONE_RESISTACE};		
		HW_WriteBit(SPCR,MSTR,Master);
		GPIO_InitPin(&SPI_MOSI);
		GPIO_InitPin(&SPI_MISO);
		GPIO_InitPin(&SPI_SCK);
		GPIO_InitPin(&SPI_SS);
	
		return PASS_1;
	}
	else if (choice->M_S==Slave)
	{
		GPIO_pin_S SPI_MOSI={choice->SPI_PORT,MOSI,INPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_SCK={choice->SPI_PORT,SCK,INPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_MISO={choice->SPI_PORT,MISO,OUTPUT,NONE_RESISTACE};
		GPIO_pin_S SPI_SS={choice->SPI_PORT,SS,INPUT,NONE_RESISTACE};
		HW_WriteBit(SPCR,MSTR,Slave);
			GPIO_InitPin(&SPI_MOSI);
			GPIO_InitPin(&SPI_MISO);
			GPIO_InitPin(&SPI_SCK);
			GPIO_InitPin(&SPI_SS);
		
		return PASS_1;
	}
	else
	{
		return MASTER_SLAVE_ERROR;	
	}
	
	
	
}


SPI_ERROR_obj_E SPI_Transmet(uint8 data)
{
	HW_WriteRegister(SPDR,data);
	while (!(HW_ReadBit(SPSR,SPIF)))
	{
		
	}
	return PASS_1;
	
	
}

uint8 SPI_Recive(void)
{
	uint8 Data;
	while (!(HW_ReadBit(SPSR,SPIF)))
	{
		
	}	
	Data=HW_ReadRegister(SPDR);
	
	return Data;
}

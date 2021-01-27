/*
 * hw_types.h
 *
 * Created: 9/23/2017 2:58:39 PM
 *  Author: Ahmed
 */ 


#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#include "data_types.h"

static inline void HW_WriteBit(uint16 reg, uint8 bit, uint8 value)
{
	if (1 == value)
	{
		*(volatile uint16 *) (reg) |= 1<<bit ;
	}
	else if(0 == value)
	{
		*(volatile uint16 *)(reg) &= ~(1<<bit);	
	}
	else 
	{
		//MISRA Rule
	}
}



static inline uint8 HW_ReadBit(uint16 reg, uint8 bit)
{
	return (*(volatile uint16 *)(reg) & (1<<bit))>>bit;
}


static inline void HW_ToggleBit(uint16 reg, uint8 bit)
{
	*(volatile uint16 *)(reg) ^= 1<<bit ; 
}

/**********************************************************************************/

static inline void HW_WriteRegister(uint16 reg, uint8 value)
{
	*(volatile uint16 *)(reg)= value;
}

static inline uint8 HW_ReadRegister(uint16 reg)
{
	return (*(volatile uint16 *)(reg));
}


/***********************************************************************************************/

static inline uint8 HW_ReadHalfRegister(uint16 reg, uint8 half)
{
	uint8 data=0;
	if(0 == half) //write half (0:3)
	{
		data= (*(volatile uint16 *)(reg)) & 0x0f ;
	}
	else if(1 == half) //left half (4:7)
	{
		data= ((*(volatile uint16 *)(reg)) & 0xf0)>>4;
	}
	else
	{
		
	}
	return data;
}


static inline void HW_WriteHalfRegister(uint16 reg, uint8 half, uint8 value)
{
	if(0 == half) //write half (0:3)
	{
		(*(volatile uint16 *)(reg))= ((*(volatile uint16 *)(reg)) & 0xf0)| ( value & 0x0f) ;
	}
	else if(1 == half) //left half (4:7)
	{
		(*(volatile uint16 *)(reg))= ((*(volatile uint16 *)(reg)) & 0x0f)| ( (value<<4) & 0xf0) ;
	}
	
}

static inline void HW_WriteRegister_16bit(uint16 reg, uint16 value)
{
	*(volatile uint16 *)(reg)= value;
}

static inline uint16 HW_ReadRegister_16bit(uint16 reg)
{
	return (*(volatile uint16 *)(reg));
}


#endif /* HW_TYPES_H_ */
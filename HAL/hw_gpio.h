/*
 * hw_gpio.h
 *
 * Created: 9/23/2017 4:12:39 PM
 *  Author: Ahmed
 */ 


#ifndef HW_GPIO_H_
#define HW_GPIO_H_


#define BASE_B 0x23
#define BASE_C 0x26
#define BASE_D 0x29


#define INPUT_OFFSET 0		//PIN read only
#define DIRECTION_OFFSET 1	//DDR direction set
#define DATA_OFFSET 2		//PORT write


#endif /* HW_GPIO_H_ */
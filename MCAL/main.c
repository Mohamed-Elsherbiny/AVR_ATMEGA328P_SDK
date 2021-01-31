/*
 * GccApplication1.c
 *
 * Created: 8/6/2018 9:53:43 PM
 * Author : Mohamed El-Sherbiny
 */ 

#include <avr/io.h>
#include "UART_MCAL.h"


int main(void)
{
 UART_CONFIG_t y = {9600};
 UART_INIT(&y);
 /* Replace with your application code */
 while (1)
 {
	 UART_SEND('c');
 }
}


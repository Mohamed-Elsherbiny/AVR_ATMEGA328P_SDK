/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "UART_MCAL.h"
/* ========================================================================== */
/*                 Default Structures and declarations                        */
/* ========================================================================== */

/* ========================================================================== */
/*                      Static Function Prototypes                            */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief    
 *         
 * \details  
 *           
 *
 * \param    
 *
 * \note     
 *
 */
void UART_INIT(UART_CONFIG_t * Obj)
{
	// Set the Baudrate
	UBRR0H = (uint8) ( (Obj->baud_rate) >> 8);
	UBRR0L = (uint8) (Obj->baud_rate);
	// Set frame format: 8data, no parity & 2 stop bits
	UCSR0C = (0<<UMSEL0) | (0<<UPM0) | (1<<USBS0) | (3<<UCSZ0);
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);	
		
}
/**
 * \brief    
 *         
 * \details  
 *           
 *
 * \param    
 *
 * \note     
 *
 */
void UART_SEND(uint8 data)
{
	/* Wait for empty transmit buffer */
	while ( ! ( UCSR0A & (1<<UDRE0)));
	/* Put data into buffer, sends the data */
	UDR0 = data;
	
}
/**
 * \brief    
 *         
 * \details  
 *           
 *
 * \param    
 *
 * \note     
 *
 */
uint8 UART_RECIVE(void)
{
	/* Wait for data to be received */
	while ( ! (UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
	
	
}

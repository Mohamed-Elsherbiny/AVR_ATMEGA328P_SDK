


#ifndef GPIO_H_
#define GPIO_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "hw_gpio.h"
#include "hw_types.h"

/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef enum GPIO_DIRECTION{
	INPUT=0,
	OUTPUT=1,
	PORT_INPUT=0,
	PORT_OUTPUT=0xff,
	HALF_PORT_INPUT=0,
	HALF_PORT_OUTPUT=0x0f,
	}GPIO_ddr_E;
	
typedef enum GPIO_DATA{
	LOW=0,
	HIGH=1,
	PORT_LOW=0,
	PORT_HIGH=0xff,
	HALF_PORT_LOW=0,
	HALF_PORT_HIGH=0x0f,
	}GPIO_data_E;
	
typedef enum GPIO_ERROR{
	FAIL = 0,
	PASS,
	PINNO_OVF,
	DIR_ERORR,
	VAL_ERROR,
	}GPIO_error_E;
	

typedef enum GPIO_PIN_NUMBER{
	PIN0= 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	MAXPINS,
} GPIO_PinNumber_E;


typedef enum GPIO_PORT_HALF{
	RIGHT=0,
	LEFT,
}GPIO_halfPort_E;

typedef enum GPIO_RESISTANCE_SET{
	NONE_RESISTACE=0,
	PULL_DOWN=0,
	PULLUP=1,
}GPIO_resistance_E;


typedef struct GPIO_PIN{
	uint16 base;
	GPIO_PinNumber_E pin_number;
	GPIO_ddr_E direction;
	GPIO_resistance_E resistance_select;
	}GPIO_pin_S;
	
typedef struct GPIO_PORT{
	uint16 base;
	GPIO_ddr_E direction;
	GPIO_resistance_E resistance_select;
}GPIO_port_S;

typedef struct GPIO_HALF_PORT{
	uint16 base;
	GPIO_ddr_E direction;
	GPIO_halfPort_E half;
	GPIO_resistance_E resistance_select;
}GPIO_half_port_S;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */
#ifdef GPIO_DEFAULT
	extern GPIO_pin_S default_pin;
	extern GPIO_port_S default_port;
	extern GPIO_half_port_S default_half_port;
#endif
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief    To initialize any pin of the general purposes I/O pins
 *
 * \details  user should select settings and options by filling the GPIO_pin_S struct
 *           
 * \param    selected_pin	-> pointer to struct GPIO_pin_S
 *
 * \note     
 *
 */	
GPIO_error_E GPIO_InitPin(GPIO_pin_S* selected_pin);



/**
 * \brief    For digital writing on a pin
 *
 * \details  user send an initialized pin struct and select the value to printed on pin           
 *
 * \param    selected_pin	-> pointer to struct GPIO_pin_S
 *			 val			-> enum GPIO_data_E
 * \note     Before using this function you should initialize the pin struct using GPIO_InitPin 
 *			 function, unless the performance is undefined 
 *
 */
GPIO_error_E GPIO_WritePin(GPIO_pin_S* selected_pin, GPIO_data_E val);




/**
 * \brief   For digital reading from a selected pin  
 *
 * \details user send an initialized pin struct and a wait to get the digital input through val pointer       
 *
 * \param   selected_pin	-> pointer to struct GPIO_pin_S
 *			val			-> pointer to uint8  
 *
 * \note    Before using this function you should initialize the pin struct using GPIO_InitPin
 *			function, unless the performance is undefined 
 */
GPIO_error_E GPIO_ReadPin(GPIO_pin_S* selected_pin, uint8 *val);



/**
 * \brief   For Toggle a selected output for digital pin usage 
 *
 * \details using this function will inverse the digital output of pin 
 *           
 * \param   selected_pin	-> pointer to struct GPIO_pin_S 
 *
 * \note    Before using this function you should initialize the pin struct using GPIO_InitPin
 *			function, unless the performance is undefined 
 */
GPIO_error_E GPIO_TogglePin(GPIO_pin_S* selected_pin);





/**
 * \brief    To initialize any port of the general purposes I/O ports
 *
 * \details  user should select settings and options by filling the GPIO_port_S struct
 *           
 * \param    selected_port	-> pointer to struct GPIO_port_S
 *
 * \note     
 *
 */	
GPIO_error_E GPIO_InitPort(GPIO_port_S* selected_port);



/**
 * \brief    For digital writing on a port
 *
 * \details  user send an initialized port struct and select the value to printed on the port          
 *
 * \param    selected_port	-> pointer to struct GPIO_port_S
 *			 val			-> enum GPIO_data_E
 * \note     Before using this function you should initialize the port struct using GPIO_InitPort 
 *			 function, unless the performance is undefined 
 *
 */
GPIO_error_E GPIO_WritePort(GPIO_port_S* selected_port, GPIO_data_E val);



/**
 * \brief   For digital reading from a selected port  
 *
 * \details user send an initialized port struct and a wait to get the digital input through val pointer       
 *
 * \param   selected_port	-> pointer to struct GPIO_port_S
 *			val			-> pointer to uint8  
 *
 * \note    Before using this function you should initialize the port struct using GPIO_InitPort
 *			function, unless the performance is undefined 
 *
 */
GPIO_error_E GPIO_ReadPort(GPIO_port_S* selected_port, uint8 *val);




/**
 * \brief    To initialize half port of the general purposes I/O ports
 *
 * \details  user should select settings and options by filling the GPIO_half_port_S struct
 *           
 * \param    selected_half_port	-> pointer to struct GPIO_half_port_S
 *
 * \note     user should understand the GPIO_half_port_s parameters
 *
 */	
GPIO_error_E GPIO_InitHalfPort(GPIO_half_port_S* selected_half_port);




/**
 * \brief    For digital writing on a half port
 *
 * \details  user send an initialized half port struct and select the value to printed on the half port          
 *
 * \param    selected_half_port	-> pointer to struct GPIO_half_port_S
 *			 val			-> enum GPIO_data_E
 * \note     Before using this function you should initialize the half port struct using GPIO_InitHalfPort 
 *			 function, unless the performance is undefined 
 *
 */
GPIO_error_E GPIO_WriteHalfPort(GPIO_half_port_S* selected_half_port, GPIO_data_E val);




/**
 * \brief   For digital reading from a selected half port  
 *
 * \details user send an initialized half port struct and wait to get the digital input through val pointer       
 *
 * \param   selected_half_port	-> pointer to struct GPIO_half_port_S
 *			val			-> pointer to uint8  
 *
 * \note    Before using this function you should initialize the half port struct using GPIO_InitHalfPort
 *			function, unless the performance is undefined 
 *
 */
GPIO_error_E GPIO_ReadHalfPort(GPIO_half_port_S* selected_half_port, uint8 *val);

#endif /* GPIO_H_ */
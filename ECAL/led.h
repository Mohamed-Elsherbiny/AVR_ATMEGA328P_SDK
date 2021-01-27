/*
 * led.h
 *
 * Created: 9/23/2017 8:46:42 PM
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "gpio.h"

/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef enum LED_ERROR{
	LED_FAIL = 0,
	LED_PASS,
}LED_error_E;

typedef enum LED_CONTROL{
	LED_OFF=0,
	LED_ON,
	LED_TOGGLE,
	}LED_led_control_E;
typedef struct LED{
	uint16 base;
	GPIO_PinNumber_E pin_number;
	}LED_led_obj_S;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
LED_error_E LED_InitLed(LED_led_obj_S* selected_led);
LED_error_E LED_ControlLed(LED_led_obj_S* selected_led, LED_led_control_E choice);

#endif /* LED_H_ */
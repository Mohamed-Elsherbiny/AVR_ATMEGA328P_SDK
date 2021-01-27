/*
 * led.c
 *
 * Created: 9/23/2017 8:46:25 PM
 *  Author: Ahmed
 */ 
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "led.h"

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

LED_error_E LED_InitLed(LED_led_obj_S* selected_led)
{
	LED_error_E status=LED_FAIL;
	GPIO_error_E gpio_status;
	
	GPIO_pin_S led={
		selected_led->base,
		selected_led->pin_number,
		OUTPUT,
		NONE_RESISTACE};
		
	gpio_status=GPIO_InitPin(&led);

	if(gpio_status==PASS)
	{
		status=LED_PASS;
	}
	else
	{
		
	}
	return status;
}

LED_error_E LED_ControlLed(LED_led_obj_S* selected_led, LED_led_control_E choice)
{
	LED_error_E status=FAIL;
	GPIO_error_E gpio_status;
	
	GPIO_pin_S led={
		selected_led->base,
		selected_led->pin_number,
		OUTPUT,
		NONE_RESISTACE};
	
	if(choice == LED_ON)
	{
		gpio_status=GPIO_WritePin(&led, HIGH);
	}
	else if(choice == LED_OFF)
	{
		gpio_status=GPIO_WritePin(&led, LOW);
	}
	else if(choice == LED_TOGGLE)
	{
		gpio_status=GPIO_TogglePin(&led);
	}
	else
	{
		gpio_status= FAIL;
	}
	
	if(gpio_status==PASS)
	{
		status=LED_PASS;
	}
	return status;
		
}
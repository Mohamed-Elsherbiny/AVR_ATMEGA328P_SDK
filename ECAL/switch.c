/*
 * switch.c
 *
 * Created: 9/29/2017 6:41:26 AM
 *  Author: Ahmed
 */ 

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "switch.h"

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
SWITCH_error_E SWITCH_InitSwitch(SWITCH_switch_obj_S* selected_switch)
{
	SWITCH_error_E status=SWITCH_FAIL;
	GPIO_error_E gpio_status;
		
	GPIO_pin_S switch_obj={
		selected_switch->base,
		selected_switch->pin_number,
		INPUT,
		selected_switch->resistance_type};
		
	gpio_status=GPIO_InitPin(&switch_obj);
		
	if(gpio_status==PASS)
	{
		status=SWITCH_PASS;
	}
	else
	{
			
	}
	return status;
}

SWITCH_error_E SWITCH_ReadSwitch(SWITCH_switch_obj_S* selected_switch,SWITCH_status_E* val)
{
	SWITCH_error_E status=SWITCH_FAIL;
	GPIO_error_E gpio_status;
	uint8 switch_value;
	
	GPIO_pin_S switch_obj={
		selected_switch->base,
		selected_switch->pin_number,
		INPUT,
		selected_switch->resistance_type};
	
	gpio_status=GPIO_ReadPin(&switch_obj,&switch_value);
	
	if(gpio_status==PASS)
	{
		*val= switch_value;
		status=SWITCH_PASS;
	}
	else
	{
		
	}
	return status;	
}
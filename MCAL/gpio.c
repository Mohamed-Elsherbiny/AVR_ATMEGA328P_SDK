

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "gpio.h"

/* ========================================================================== */
/*                 Default Structures and declarations                        */
/* ========================================================================== */
#ifdef GPIO_DEFAULT 
	GPIO_pin_S default_pin={
		BASE_A,
		PIN0,
		OUTPUT,
		NONE_RESISTACE};
	
	GPIO_port_S default_port={
		BASE_A,
		OUTPUT,
		NONE_RESISTACE};

	GPIO_half_port_S default_half_port={
		BASE_A,
		OUTPUT,
		RIGHT,
		NONE_RESISTACE};
#endif
/* ========================================================================== */
/*                      Static Function Prototypes                            */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

GPIO_error_E GPIO_InitPin(GPIO_pin_S* selected_pin)
{
	GPIO_error_E status=FAIL;
	
	if(selected_pin->direction == OUTPUT || selected_pin->direction == INPUT)
	{
		if(selected_pin->pin_number < MAXPINS)
		{
			HW_WriteBit(selected_pin->base+DIRECTION_OFFSET,selected_pin->pin_number,selected_pin->direction);
			status= PASS;
		}
		else
		{
			status= PINNO_OVF;
		}
	}
	else
	{
		status= DIR_ERORR;
	}
	
	if(selected_pin->direction == INPUT)
	{
		if(selected_pin->resistance_select == PULLUP)
		{
			HW_WriteBit(selected_pin->base+DATA_OFFSET,selected_pin->pin_number,HIGH);
		}
		else
		{
			HW_WriteBit(selected_pin->base+DATA_OFFSET,selected_pin->pin_number,LOW);
		}
	}
	return status;
}

GPIO_error_E GPIO_WritePin(GPIO_pin_S* selected_pin, GPIO_data_E val)
{
	GPIO_error_E status;
	
	if(val == HIGH || val == LOW)
	{
		HW_WriteBit(selected_pin->base+DATA_OFFSET,selected_pin->pin_number,val);
		status= PASS;
	}
	else
	{
		status= VAL_ERROR;
	}
	return status;	
}

GPIO_error_E GPIO_ReadPin(GPIO_pin_S* selected_pin, uint8 *val)
{
	GPIO_error_E status;
	*val= HW_ReadBit(selected_pin->base+INPUT_OFFSET,selected_pin->pin_number);
	status= PASS;
	
	return status;	
}

GPIO_error_E GPIO_TogglePin(GPIO_pin_S* selected_pin)
{
	GPIO_error_E status;
	HW_ToggleBit(selected_pin->base+DATA_OFFSET,selected_pin->pin_number);
	status= PASS;
	
	return status;
}

/*************************************************************************************************************/
GPIO_error_E GPIO_InitPort(GPIO_port_S* selected_port)
{
	GPIO_error_E status;
	
	if(selected_port->direction == PORT_OUTPUT || selected_port->direction == PORT_INPUT)
	{
		HW_WriteRegister(selected_port->base+DIRECTION_OFFSET,selected_port->direction);
		status= PASS;
	}
	else
	{
		status= DIR_ERORR;
	}
	
	if(selected_port->direction == PORT_INPUT)
	{
		if(selected_port->resistance_select == PULLUP)
		{
			HW_WriteRegister(selected_port->base+DATA_OFFSET,PORT_HIGH);
		}
		else
		{
			HW_WriteRegister(selected_port->base+DATA_OFFSET,PORT_LOW);
		}
	}
	return status;
}


GPIO_error_E GPIO_WritePort(GPIO_port_S* selected_port, GPIO_data_E val)
{
	GPIO_error_E status;
	
	if(val == PORT_HIGH || val == PORT_LOW)
	{
		HW_WriteRegister(selected_port->base+DATA_OFFSET,val);
		status= PASS;
	}
	else
	{
		status= VAL_ERROR;
	}
	return status;
}

GPIO_error_E GPIO_ReadPort(GPIO_port_S* selected_port, uint8 *val)
{
	GPIO_error_E status;
	*val= HW_ReadRegister(selected_port->base+INPUT_OFFSET);
	status= PASS;
	
	return status;
}


/******************************************************************************************************************/

GPIO_error_E GPIO_InitHalfPort(GPIO_half_port_S* selected_half_port)
{
	GPIO_error_E status= FAIL;
	
	if(selected_half_port->direction == HALF_PORT_INPUT || selected_half_port->direction == HALF_PORT_OUTPUT)
	{
		if(selected_half_port->half == RIGHT || selected_half_port->half == LEFT)
		{
			HW_WriteHalfRegister(selected_half_port->base+DIRECTION_OFFSET,selected_half_port->half,selected_half_port->direction);
			status= PASS;
		}
		else
		{
			
		}
	}
	else
	{
		status= DIR_ERORR;
	}
	
	if(selected_half_port->direction == HALF_PORT_INPUT)
	{
		if(selected_half_port->resistance_select == PULLUP)
		{
			HW_WriteHalfRegister(selected_half_port->base+DATA_OFFSET,selected_half_port->half,HALF_PORT_HIGH);
		}
		else
		{
			HW_WriteHalfRegister(selected_half_port->base+DATA_OFFSET,selected_half_port->half,HALF_PORT_LOW);
		}
	}
	return status;
}


GPIO_error_E GPIO_WriteHalfPort(GPIO_half_port_S* selected_half_port, GPIO_data_E val)
{
	GPIO_error_E status;
	
	if(val == HALF_PORT_HIGH || val == HALF_PORT_LOW)
	{
		HW_WriteHalfRegister(selected_half_port->base+DATA_OFFSET,selected_half_port->half,val);
		status= PASS;
	}
	else
	{
		status= VAL_ERROR;
	}
	return status;
}

GPIO_error_E GPIO_ReadHalfPort(GPIO_half_port_S* selected_half_port, uint8 *val)
{
	GPIO_error_E status;
	*val= HW_ReadHalfRegister(selected_half_port->base+INPUT_OFFSET,selected_half_port->half);
	status= PASS;
	
	return status;
}

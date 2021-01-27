/*
 * switch.h
 *
 * Created: 9/29/2017 6:41:48 AM
 *  Author: Ahmed
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_
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
typedef enum SWITCH_ERROR{
	SWITCH_FAIL = 0,
	SWITCH_PASS,
}SWITCH_error_E;

typedef enum SWITCH_STATUS{
	PULLUP_PRESSED=0,
	PULLUP_FREE=1,
	PULLDOWN_PRESSED=1,
	PULLDOWN_FREE=0,
}SWITCH_status_E;
typedef struct SWITCH{
	uint16 base;
	GPIO_PinNumber_E pin_number;
	GPIO_resistance_E resistance_type;
}SWITCH_switch_obj_S;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
SWITCH_error_E SWITCH_InitSwitch(SWITCH_switch_obj_S* selected_switch);
SWITCH_error_E SWITCH_ReadSwitch(SWITCH_switch_obj_S* selected_switch,SWITCH_status_E* val);




#endif /* SWITCH_H_ */
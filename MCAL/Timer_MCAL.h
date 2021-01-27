/*
 * Timer.h
 *
 * Created: 11/21/2017 11:19:25 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_MCAL_H_
#define TIMER_MCAL_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "TIMER_HAL.h"

/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

/* None */









/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef enum TIMER_ERROR{
	Timer_select_error,
	Timer_Pass,
	}Timer_error_E;
	
	
typedef enum timerMode {
	Normal,
	CTC,
	PWM,
	FAST_PWM,	
	}TimerMode_E;
	
typedef enum timerSelector {
	T0,
	T1,
	T2,
	XTAL1,
	XRAL2,
	}Timer_Selector_E;

/*typedef enum OSCILLATOR_FREQ{
	ONE_MHZ,
	EIGHT_MHZ,
	}OSC_freq_E;*/	
	
		
typedef struct timer {
	Timer_Selector_E TimerNum; 
	TimerMode_E Timer_mode_selector;
	}Timer_obj_S;
	
	/* ========================================================================== */
	/*                         Global Variables Declarations                      */
	/* ========================================================================== */

	/* ========================================================================== */
	/*                          Function Declarations                             */
	/* ========================================================================== */
	
	Timer_error_E Delay(uint16,Timer_Selector_E);
 




#endif /* TIMER_H_ */
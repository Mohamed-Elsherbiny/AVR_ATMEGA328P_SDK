/*
 * Timer.c
 *
 * Created: 11/21/2017 11:19:01 PM
 *  Author: Mohamed El-Sherbiny Emam
 */ 
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Timer_MCAL.h"


/* ========================================================================== */
/*                 Default Structures and declarations                        */
/* ========================================================================== */
	#ifndef F_CPU
/* prevent compiler error by supplying a default */
# warning "F_CPU not defined for <Timer_MCAL.h>"
/** \ingroup util_delay
    \def F_CPU
    \brief CPU frequency in Hz

    The macro F_CPU specifies the CPU frequency to be considered by
    the delay macros.  This macro is normally supplied by the
    environment (e.g. from within a project header, or the project's
    Makefile).  The value 1 MHz here is only provided as a "vanilla"
    fallback if no such user-provided definition could be found.

 */
# define F_CPU 1000000
#endif


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

Timer_error_E Delay(uint16 Time_delay,Timer_Selector_E choice)
{
	Timer_error_E status=Timer_select_error;
	if (choice == T0)								//max delay time =262.14 ms
		{
			//enabling timer interrupt
			HW_WriteBit(TIMSK,TOIE0,0x1);
			
			//pin0 portB Dirction output
			HW_WriteBit(DDRB,DDB7,Output);
			
			uint8 TCNT0_value =256-Time_delay*F_CPU/(1024*1000);
			//intializing TCnT0
			HW_WriteRegister(TCNT0,TCNT0_value);
			//intializing Timer control register with prescaler 1:1024
			HW_WriteRegister(TCCR0,0x5);
			while(0 == HW_ReadBit(TIFR,TOV0))
			{
			}
			HW_WriteRegister(TCCR0,0x0);
			HW_WriteBit(TIFR,TOV0,0X1);
			status=Timer_Pass;
		}
	else if(choice == T2)
		{
			//enabling timer interrupt
			HW_WriteBit(TIMSK,TOIE2,0x1);
			
			//pin0 portB Dirction output
			HW_WriteBit(DDRB,DDB7,Output);
			
			uint8 TCNT2_value =256-Time_delay/0.128;
			//intializing TCnT2
			HW_WriteRegister(TCNT2,TCNT2_value);
			//intializing Timer control register with prescaler 1:1024
			HW_WriteRegister(TCCR2,0x7);
			while(0 == HW_ReadBit(TIFR,TOV2))
			{
			}
			HW_WriteRegister(TCCR2,0x0);
			HW_WriteBit(TIFR,TOV2,0X1);
			status=Timer_Pass;
		}
	else if (choice == T1)							//max delay using T1 with prescalar 1024 = 8 sec
		{
			//enabling timer interrupt
			HW_WriteBit(TIMSK,TOIE1,0x1);
			
			//pin0 portB Dirction output
			HW_WriteBit(DDRB,DDB1,Output);
			
			uint16 TCNT1_Value=65536-(F_CPU*Time_delay/1024)/(1000);
			HW_WriteRegister_16bit(TCNT1,TCNT1_Value);
			/*uint16 Temp=TCNT1_Value & 0xff00;
			HW_WriteRegister_16bit(TCNT1,Temp);
			TCNT1_Value=TCNT1_Value | Temp;
			*/
			//intializing Timer control register with prescaler 1:1024
			HW_WriteRegister(TCCR1A,0x0);
			//intializing Timer control register with prescaler 1:1024
			HW_WriteRegister(TCCR1B,0x5);
			
			while(0 == HW_ReadBit(TIFR,TOV1))
			{
			}
			HW_WriteRegister(TCCR1A,0x0);
			HW_WriteRegister(TCCR1B,0x0);
			HW_WriteBit(TIFR,TOV1,0X1);
			status=Timer_Pass;
		}
	else{
			return status;
		}
			return status;
}






















































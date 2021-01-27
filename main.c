/*
 * AVR_ATMEGA328P_SDK.c
 *
 * Created: 1/22/2018 8:19:53 PM
 * Author : Admin
 */ 

#include "Timer_MCAL.h"
#include "data_types.h"
#include "led.h"
#include "switch.h"
#include "SPI_MCAL.h"


int main(void)
{
   LED_led_obj_S led1={BASE_B,PIN0};
   (void)LED_InitLed(&led1);
  /* HW_WriteBit(0x24,0,1);
   HW_WriteBit(0x25,0,1);
    */
  while (1) 
    {
		LED_ControlLed(&led1,LED_ON);
		/*Delay(1000,T1);
		LED_ControlLed(&led1,LED_OFF);
		Delay(1000,T1);
    */}
}


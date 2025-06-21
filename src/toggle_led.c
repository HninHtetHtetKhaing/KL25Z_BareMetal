/*
 * Name: toggle_led.c
 * Author: Hnin Htet Htet Khaing
 *
 */

//bitwise operations 

#include "kl25z.h"
#include "wdog.h"

int __attribute__ ((weak)) main(void)
{
	wdog_init(WDOG_CONF_DIS);

		//portb 18 pin is red led and port a pin 4 is button 
	PORTB -> PCR[18] = PORT_PCR_MUX (1);	//red led
	PORTA -> PCR[4] = PORT_PCR_MUX (1);	//button

		//port data direction register
	GPIOB -> PDDR = GPIOB -> PDDR | (1<<18);	

	int state_old, state_new;

	state_old = GPIOA -> PDIR & (1<<4);

	while (1) {
		state_new = GPIOA -> PDIR & (1<<4);

		if((state_old != 0) && (state_new == 0))
		{
			GPIOB -> PTOR =  1<<18;	//port toggle output register
		}

		state_old = state_new;

	}

	return 0;
}

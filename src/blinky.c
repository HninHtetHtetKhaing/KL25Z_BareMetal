/*
 * Name: main.c
 * Author: Hnin Htet Htet Khaing
 *
 */

#include "kl25z.h"
#include "wdog.h"

int __attribute__ ((weak)) main(void)
{
	wdog_init(WDOG_CONF_DIS);
		//LED is on PORTB of  pin 18
	PORTB -> PCR[18] = PORT_PCR_MUX (1);

		//PDDR => Port Data direction register
	GPIOB -> PDDR = GPIOB -> PDDR | (1<<18);	// Set the pint 18 to low

	while (1) {
		// PDOR=> port data output register
		GPIOB -> PDOR =  GPIOB -> PDOR & ~(1<<18);
		for(int wait=0; wait<1000000; wait++);
		GPIOB -> PDOR = GPIOB -> PDOR | (1<<18);
		for(int wait=0; wait<1000000; wait++);
	}

	return 0;
}

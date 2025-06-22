#include "kl25z.h"
#include "wdog.h"

	//button interrupt hendler
void PORTA_IRQHandler(void)
{
	
	if(PORTA->ISFR & (1<<4)) {
		PORTA -> ISFR = 1 << 4;
		GPIOB -> PTOR = 1 << 19;
	}
	else {
		PORTA -> ISFR = 1 << 5;
		GPIOB -> PTOR = 1 << 18;
	}

}



int __attribute__ ((weak)) main(void)
{
	wdog_init(WDOG_CONF_DIS);

	//led setup
	PORTB -> PCR[19] = PORT_PCR_MUX(1);
	GPIOB -> PDDR = 1 << 19;	//port data direction, PTB jest teraz outputem
	GPIOB -> PSOR = 1 << 19;	//set output, led off

	// button setup - PTA[4]
	PORTA -> PCR[4] = PORT_PCR_MUX(1) | PORT_PCR_IRQC(10);

	//CMSIS function, need to enable to reveive input from porta
	//NVIC_EnableIRQ(30); //not readable
	NVIC_EnableIRQ(PORTA_IRQn);

	while (1) {
	}

	return 0;
}

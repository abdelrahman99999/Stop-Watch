#include"Timer1_CTC.h"

void timer1_init(){
	TCNT1 = 0;//Initial value
	/*
		 prescaler=1024
		 F_CPU=1 MHz
		 F_timer=1 kHz
		 T_timer=1 msec
		 for one second i will put compare value to 1000
		 so interrupt happen every 1*1000 = 1000 msec =1 sec
	*/
	OCR1A = 1000;  //compare value
	TIMSK|=(1<<OCIE1A); //Timer Output Compare A match interrupt is enabled

	/* Configure timer control register TCCR1A
		 1. Disconnect OC1A and OC1B  COM1A1=0 COM1A0=0 COM1B0=0 COM1B1=0
		 2. FOC1A=1 FOC1B=0
		 3. CTC Mode WGM10=0 WGM11=0 (Mode Number 4)
	 */
	TCCR1A = (1<<FOC1A);

	/* Configure timer control register TCCR1B
		 * 1. CTC Mode WGM12=1 WGM13=0 (Mode Number 4)
		 * 2. Prescaler = F_CPU/1024 CS10=1 CS11=0 CS12=1
	*/

	TCCR1B=(1<<CS10)|(1<<CS12); //prescaler=1024
	TCCR1B|=(1<<WGM12); //CTC mode
}

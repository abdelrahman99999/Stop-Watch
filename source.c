/**************************************************************************************************
 Author      : Abdelrahman Elsayed Mohamed
 Description : stop watch
 **************************************************************************************************/

#include "six_digits_7segment.h"
#include "Interrupts_Init.h"
#include "Timer1_CTC.h"

ISR(TIMER1_COMPA_vect){
	SREG|=(1<<7);//enable interrupts nesting
	timer1_interrupt_flag=set;
}

ISR(INT0_vect){
	SREG|=(1<<7);//enable interrupts nesting
	//RESET stop watch
	for(int i=0;i<6;i++){
		_clock[i]=0;
	}
	TCNT1=0;
}

ISR(INT1_vect){
	SREG|=(1<<7);//enable interrupts nesting
	//pause stop watch ,we can do this by stop timer1 (no clock source)
	TCCR1B &= ~(1<<CS12);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS10);
}

ISR(INT2_vect){
	SREG|=(1<<7);//enable interrupts nesting
	//resume stop watch ,we can do this by reactive timer1 (connect to clock source again)
	//enable _clock with prescaler=1024
	TCCR1B|=(1<<CS10);
	TCCR1B|=(1<<CS12);
}

int main(){
	SREG|=(1<<7); //enable I-bit(global interrupt enable)

	//initializations
	external_interrupt_0_init();
	external_interrupt_1_init();
	external_interrupt_2_init();
	timer1_init();
	seven_segment_controller_init();
	decoder_init();

	while(1){
		display();
		if(timer1_interrupt_flag==set){
			update_stop_watch_digits();
			timer1_interrupt_flag=cleared;
		}
	}
	return 0;
}

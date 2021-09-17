#include"Interrupts_Init.h"

//Implementations
void external_interrupt_0_init(){
	DDRD &=~(1<<PD2);//input pin
	PORTD|=(1<<PD2);//enable internal pull up
	GICR|=(1<<INT0);//enable external interrupt 0
	MCUCR|=(1<<ISC01);//falling edge
}

void external_interrupt_1_init(){
	DDRD &=~(1<<PD3);//input pin
	PORTD &=~(1<<PD3);//disable internal pull up
	GICR|=(1<<INT1);//enable external interrupt 1
	MCUCR|=(1<<ISC11)|(1<<ISC10);//rising edge
}

void external_interrupt_2_init(){
	DDRB &=~(1<<PB2);//input pin
	PORTB=(1<<PB2);//enable internal pull up
	GICR|=(1<<INT2);//enable external interrupt 2
	MCUCSR&=~(1<<ISC2);//falling edge
}

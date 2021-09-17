#ifndef TIMER1_CTC_H_
#define TIMER1_CTC_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

enum states{cleared,set};

char timer1_interrupt_flag;

void timer1_init();


#endif

#ifndef SIX_DIGITS_7SEGMENT_H_
#define SIX_DIGITS_7SEGMENT_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

char _clock[6];
/*
 no_seconds_digit1 = clock[0]
 no_seconds_digit2 = clock[1]
 no_minutes_digit1 = clock[2]
 no_minutes_digit2 = clock[3]
 no_hours_digit1 = clock[4]
 no_hours_digit2 = clock[5]
*/

//prototypes
void update_stop_watch_digits();

void display();

void seven_segment_controller_init();

void decoder_init();

#endif

#include "six_digits_7segment.h"

//Implementations
void update_stop_watch_digits(){
	_clock[0]++; //every timer1 interrupt (every second) increase seconds
	if(_clock[0]==10){
		_clock[0]=0;
		_clock[1]++;
		if(_clock[1]==6 && _clock[0]==0){
			_clock[1]=0;
			_clock[2]++;
		}
	}
	if(_clock[2]==10){
		_clock[2]=0;
		_clock[3]++;
		if(_clock[3]==6 && _clock[2]==0){
				_clock[3]=0;
				_clock[4]++;
		}
	}
	if(_clock[4]==10){
		_clock[4]=0;
		_clock[5]++;
		if(_clock[5]==10 && _clock[4]==0){
				//here we will reach our maximum  stop watch(99hours:59minutes:59seconds),no enough bits for hours
				//so i will reset stop watch
				for(int i=0;i<6;i++){
					_clock[i]=0;
				}
				TCNT1=0; //make Timer register startng from zero
		}
	}

}

void display(){
	/*
	 looping on each digit ,change value of portc depend on digit
	 as we loop very fast no person can realize this
	 */
	 for(int j=0;j<6;j++){
		PORTA=1<<j;
		PORTC=_clock[j];
		_delay_ms(3);
	}
}

void seven_segment_controller_init(){
	//outputs of MCU, inputs for 6digits seven segment
	DDRA=0x3f;  //first 6bits as output pins
	//with these bits,I can control (6 digits 7-segment) to choose which digit will take the output of 7447 decoder
	PORTA=0x01;
}

void decoder_init(){
	//outputs of MCU, inputs for 7447 decoder
	DDRC=0x0f;//first 4bits of portc as output pins
	PORTC=0;
}


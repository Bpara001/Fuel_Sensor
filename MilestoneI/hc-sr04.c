#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/portpins.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#define trigger  PB2
#include "lcd.h"
//FreeRTOS include files
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"


// Trigger Pin B3
//ECHO PIN B5


enum LEDState {INIT,test} led_state;
//variables

int timer_count=0;
long count;
double distance;
char char_distance[10];
ISR(INT2_vect)
{
	timer_count++;
}

void initPCInt() {

	EIMSK |= (1 << INT2); // Pin Change Interrupt 0 (Pins 7...0) mask
	EICRA |= (1 << ISC00); //Enable Pin Change Interrupt on PCINT0
	TIMSK0= (1 << TOIE0);
	TCCR1A=0;
	//SREG = 0x01; // Enable global interrupts
	sei();
}

void LEDS_Init(){
	led_state = INIT;
}

void LEDS_Tick(){
	//Actions
	switch(led_state){
		case INIT:
		led_state=test;
		break;
		case test:
		led_state=test;
		break;
		default:
		led_state=test;
		break;
	}
	//Transitions
	switch(led_state){
		case test:
		PORTB |= (1 <<trigger);
		_delay_us(10);
		PORTB &= ~(1 <<trigger);
		
		TCNT1=0;
		TCCR1B = 0x41; 
		TIFR3 = (1<<ICF3);
		TIFR3=(1 << TOV3);
		
		
		while((TIFR3 & (1 <<ICF3)) ==0);
		TCNT1=0;
		TCCR1B = 0x01;
		TIFR3 = (1<<ICF3);
		TIFR3=(1 << TOV3);
		timer_count=0;
		
		while((TIFR3 & (1 <<ICF3)) ==0);
		count = ICR1 + (65535 * timer_count);
		distance= (double)count/466.47;
		dtostrf(distance, 2, 2, char_distance);
		LCD_DisplayString(1,char_distance);
		break;
		
		default:
		led_state = test;
		break;
	}
}

void LedSecTask()
{
	LEDS_Init();
	for(;;)
	{
		LEDS_Tick();
		vTaskDelay(200);
	}
}

void StartSecPulse(unsigned portBASE_TYPE Priority)
{
	xTaskCreate(LedSecTask, (signed portCHAR *)"LedSecTask", configMINIMAL_STACK_SIZE, NULL, Priority, NULL );
}

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0xFF;
	DDRB=0xBF;
	LCD_init();
	initPCInt();
	
	//Start Tasks
	StartSecPulse(1);
	//RunSchedular
	vTaskStartScheduler();

	return 0;
}
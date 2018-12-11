#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/portpins.h>
#include <avr/pgmspace.h>
#include "lcd.h"
#define TriggerPin		PIND3			//white:Defining PIND1 as trigger pin
#define EchoPin			PIND2			//black:Defining PIN2 (INT0 pin) as echo pin
volatile int i = 0;
volatile int pulse = 0;
int distance = 0;
char distance_a[16];
ISR(INT0_vect) {
	
	if (i == 1)
	{
		TCCR3B = 0;
		pulse = TCNT3;
		TCNT3 = 0;
		i = 0;
	}
	else
	{
		TCCR3B |= 1 << CS30;
		i = 1;
	}
}
/*int get_distance()
{
	PORTD |= (1<<TriggerPin);				//10us pulse procedure
	_delay_us(10);
	PORTD &= ~(1<<TriggerPin);
	distance = pulse/58.0;	
	_delay_us(60);
}*/
void Convert_Value(char x[16])
{
	char temp=x[0];
	x[0]='0';
	x[1]=temp;
	x[2]= '\0';
}
void Distance_Converter()
{		
	PORTD |= (1<<TriggerPin);				//10us pulse procedure
	_delay_us(10);
	PORTD &= ~(1<<TriggerPin);
	distance = pulse/58.0;
	itoa(distance,distance_a,10);
	if(distance <10)
		Convert_Value(distance_a);
	LCD_DisplayString_nclear(29,distance_a);
	LCD_DisplayString_nclear(31,"cm");
	_delay_us(60);
}
void Distance_Converter2()
{
	PORTD |= (1<<TriggerPin);				//10us pulse procedure
	_delay_us(10);
	PORTD &= ~(1<<TriggerPin);
	distance = pulse/58.0;
	if(distance <=36)
		distance=36-distance;
	itoa(distance,distance_a,10);
	if(distance <10)
	Convert_Value(distance_a);
	LCD_DisplayString_nclear(24,distance_a);
	LCD_DisplayString_nclear(26,"cm");
}
int Water_Amount()
{
	PORTD |= (1<<TriggerPin);				//10us pulse procedure
	_delay_us(10);
	PORTD &= ~(1<<TriggerPin);
	distance = pulse/58.0;
	_delay_us(60);
	return distance;
}
void init_HC_SR04() {
	EICRA |= 1 << ISC00;
	EIMSK |= 1 << INT0;
	sei();
}
	
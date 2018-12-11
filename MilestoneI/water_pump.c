/*
 * water_pump.c
 *
 * Created: 11/14/2018 10:38:01 PM
 *  Author: Jesse
 */ 


#include <avr/io.h>
/*
void Water_Pump(char input)
{

	while(1) {
		x = GetKeypadKey();
		switch (x) {
			case 'A': 
			PORTA = 0x04; 
			delay_ms(10000);
			PORTA=0x00;
			break; // All 5 LEDs on
			case 'B': 
			PORTA = 0x04;
			delay_ms(40000);
			PORTA=0x00; 
			
			break; // hex equivalent
			case 'C': 
			PORTA = 0x04; 
			delay_ms(60000);
			PORTA= 0x00;
			break;
			case 'D':
			PORTA=0x04;
			delay_ms(10000);
			PORTA=0x00;
			// . . . ***** FINISH *****

			default: PORTB = 0x00; break; // Should never occur. Middle LED off.
		}
	}
}

void T0Delay ()
{
	
	TCNT0=0x20;
	TCCR0B= 0x01;
	while((TIFR0 &0x1) ==0);
	TCCR0B=0;
	TIFR0=1;
	
}
*/
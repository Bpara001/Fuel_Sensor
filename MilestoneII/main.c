//#define  F_CPU 16000000UL
#include <stdint.h> 
#include <stdlib.h> 
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
#include "SRO4.h"
#include "keypad.h"
#include "lcd_matrix.h"
#include "usart_ATmega1284.h"
#include "Add_Water.h"
//Bucket Size 36cm
//Flags
int flag=0;

int main(void) 
{ 
  DDRA = 0xFF;
  DDRB = 0xFF;
  DDRD = 0xFB;
  DDRC = 0xF0; PORTC = 0x0F; //keypadS
  LCD_init();
  delay_ms(50);
  init_HC_SR04();
  LCD_DisplayString(1,"Liquid Level    Sensor");
  delay_ms(200);
  LCD_ClearScreen();
  TCCR1B = 0;
  TCNT1 = 0;
 char option;
 int screen=0;		
 int Restart_flag=1;
 int Addwater_flag=0;			//options A
 int Removewater_flag=0;		//		  B
 int Centimeter_flag=0;			//		  C
 int User_flag=0;				//		  D

 while(1)
 {
	 option=GetKeypadKey();
	
	 if(Restart_flag)
	 {
		  
		 LCD_DisplayString_nclear(1,"ADD:A Remove:B  H20 Level:C");
		 Restart_flag=0;
	 }
	 else if(option=='A')
	{
		Addwater_flag=1;
		Restart_flag=0;
		LCD_ClearScreen();
	}
	else if(option=='B')
	{
		Removewater_flag=1;
		Restart_flag=0;
		LCD_ClearScreen();
	}
	else if(option=='C')
	{
		Centimeter_flag=1;
		Restart_flag=0;
		LCD_ClearScreen();
	}
	else if(option=='D')
	{
		User_flag=1;
		Restart_flag=0;
		LCD_ClearScreen();
	}

// Menu Choice (flags)
	if(Addwater_flag)
	{
		
		AddWater();
		transmit_data(0xFF);
		transmit_data2(0x00);
		Restart_flag=1;
		Addwater_flag=0;
		
	}
	else if(Centimeter_flag)
	{
		LCD_DisplayString_nclear(1,"Distance to     water in cm:");
		while(option !='*')
		{
			Distance_Converter();	
			option=GetKeypadKey();
		}
		LCD_ClearScreen();
		Centimeter_flag=0;
		Restart_flag=1;
	}
	else if(Removewater_flag)
	{
		RemoveWater();
		transmit_data(0xFF);
		transmit_data2(0x00);
		Restart_flag=1;
		Removewater_flag=0;
	}
	else if(User_flag)
	{
		Water_Display();
		transmit_data(0xFF);
		transmit_data2(0x00);
		LCD_ClearScreen();
		Restart_flag=1;
		User_flag=0;
	}
 
   
}
	return 0; 
}
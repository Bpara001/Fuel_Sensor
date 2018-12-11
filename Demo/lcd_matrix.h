#define SET_BIT(p,i) ((p) |= (1 << (i)))
#define CLR_BIT(p,i) ((p) &= ~(1 << (i)))
#define GET_BIT(p,i) ((p) & (1 << (i)))


// delay 450 us
//rows 0
void transmit_data(unsigned char data) {
	// for each bit of data
	// Set SRCLR to 1 allowing data to be set
	for(int i=0;i<8;++i)
	{
		PORTD=0x80;
		PORTD |= CLR_BIT(PORTD,6);
		PORTD |= ((data >> i) & 0x01);
		PORTD |=0x40;
	}
	PORTD=0x20;
	// Also clear SRCLK in preparation of sending data
	// set SER = next bit of data to be sent.
	// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
	// end for each bit of data
	// set RCLK = 1. Rising edge copies data from the "Shift" register to the "Storage" register
	// clears all lines in preparation of a new transmission
	PORTD = 0x00;
}
// columns 1
void transmit_data2(unsigned char data) {
	// for each bit of data
	// Set SRCLR to 1 allowing data to be set
	for(int i=0;i<8;++i)
	{
		PORTB=0x80;
		PORTB |= CLR_BIT(PORTB,6);
		PORTB |= ((data >> i) & 0x01);
		PORTB |=0x40;
	}
	PORTB=0x20;
	// Also clear SRCLK in preparation of sending data
	// set SER = next bit of data to be sent.
	// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
	// end for each bit of data
	// set RCLK = 1. Rising edge copies data from the "Shift" register to the "Storage" register
	// clears all lines in preparation of a new transmission
	PORTB = 0x00;
}
// Transmit_1	row(0) 
//Transmit_2	col(1)

int water=10;
int water_change;
int bucket_size = 38;
unsigned char col[2];
unsigned char row[2];
char exit_check;
void Matrix_Display(int time,int port)
{
	
	int r=0;
	int c=0;
	int temp=0;
	int counter_hold=0;
	water_change=Water_Amount();
	water_change=water_change-water;
	
	while(time !=temp )
	{
		
	exit_check=GetKeypadKey();
		if(exit_check =='*' )
			temp=time;
		
		PORTB=port;
		water=Water_Amount();
		water=bucket_size-water;
		
		if(water != water_change)
		{
			r=0;
			c=0;
			water_change=water;
		}
		if(r > 1 || c > 1)
		{
			r=0;
			c==0;
		}
		if(water<=0)
		{
			row[0]=0xFF;row[1]=0xFF;
			col[0]=0x00;col[1]=0x00;
		}
		else if(water <=3)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0x80;col[1]=0x80;
		}
		else if(water <=5)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xC0;col[1]=0xC0;
		}
		else if(water <=7)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xE0;col[1]=0xE0;
		}
		else if(water <=8)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xF0;col[1]=0xF0;
		}
		else if(water <=9)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xF8;col[1]=0xF8;
		}
		else if(water <=10)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xF8;col[1]=0xF8;
		}
		else if(water <=11)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xFC;col[1]=0xFC;
			
		}
		else if(water <=12)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xFE;col[1]=0xFE;
		}
		else if(water <=13)
		{
			row[0]=0xEF;row[1]=0xEF;
			col[0]=0xFF;col[1]=0xFF;
		}
		//row2
		else if(water <=14)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0x80;
		}
		else if(water <=15)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0xC0;
		}
		else if(water <=16)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0xE0;
		}
		else if(water <=17)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0xF0;
		}
		else if(water <=18)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0xFC;
		}
		else if(water <=19)
		{
			row[0]=0xEF;row[1]=0xF7;
			col[0]=0xFF;col[1]=0xFE;
		}
		
		else if(water <=20)
		{
			row[0]=0xE7;row[1]=0xE7;
			col[0]=0xFF;col[1]=0xFF;
			//row  3
		}
		else if(water <=21)
		{
			row[0]=0xE7;row[1]=0xFB;
			col[0]=0xFF;col[1]=0xC0;
		}
		else if(water <=22)
		{
			row[0]=0xE7;row[1]=0xFB;
			col[0]=0xFF;col[1]=0xF0;
		}
		else if (water <=23)
		{
			row[0]=0xE7;row[1]=0xFB;
			col[0]=0xFF;col[1]=0xFC;
		}
		else if (water <=24)
		{
			row[0]=0xE3;row[1]=0xE3;
			col[0]=0xFF;col[1]=0xFF;
		}
		//row 4
		else if (water <=25)
		{
			row[0]=0xE3;row[1]=0xFD;
			col[0]=0xFF;col[1]=0xC0;
		}
		else if (water <=26)
		{
			row[0]=0xE3;row[1]=0xFD;
			col[0]=0xFF;col[1]=0xF0;
		}
		else if (water <=27)
		{
			row[0]=0xE3;row[1]=0xFD;
			col[0]=0xFF;col[1]=0xFC;
		}
		else if (water <=28)
		{
			row[0]=0xE3;row[1]=0xFD;
			col[0]=0xFF;col[1]=0xFE;
		}
		else if (water <=29)
		{
			row[0]=0xE1;row[1]=0xE1;
			col[0]=0xFF;col[1]=0xFF;
		}
		//row 5
		else if (water <=30)
		{
			row[0]=0xE1;row[1]=0xFE;
			col[0]=0xFF;col[1]=0x80;
		}
		else if (water <=31)
		{
			row[0]=0xE1;row[1]=0xFE;
			col[0]=0xFF;col[1]=0xC0;
		}
		else if (water <=32)
		{
			row[0]=0xE1;row[1]=0xFE;
			col[0]=0xFF;col[1]=0xF0;
		}
		else if (water <=33)
		{
			row[0]=0xE1;row[1]=0xFE;
			col[0]=0xFF;col[1]=0xFC;
		}
		else if(water <=36)
		{
			row[0]=0x00;row[1]=0x00;
			col[0]=0xFF;col[1]=0xFF;
		}
		else 
		{
			temp=time;
		}
		if(water <=13 || water ==15  ||water==19 || water == 20 || water==25 ||(water >=33 && water <=36))
		{
			transmit_data(row[0]);
			transmit_data2(col[0]);
		}
		else
		{
			transmit_data(row[r]);
			transmit_data2(col[c]);
			
		}
		if(time !=10)
			counter_hold++;
		r++;
		c++;
		
		if (counter_hold==2000 )
		{
			temp++;
			counter_hold=0;
		}
		
		//_delay_us(450);
	}
}
void Water_Display(int limit, int port_new)
{
		int r=0;
		int c=0;
		int temp=1;
		water_change=Water_Amount();
		water_change=water_change-water;
		
		while(temp )
		{
			
			exit_check=GetKeypadKey();
			if(exit_check =='*' )
				temp=0;
			
			PORTB=port_new;
			water=Water_Amount();
			
			water=bucket_size-water;
				if(limit >=water)
					temp=0;
			if(water != water_change)
			{
				r=0;
				c=0;
				water_change=water;
			}
			if(r > 1 || c > 1)
			{
				r=0;
				c==0;
			}
			if(water<=0)
			{
				row[0]=0xFF;row[1]=0xFF;
				col[0]=0x00;col[1]=0x00;
			}
			else if(water <=3)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0x80;col[1]=0x80;
			}
			else if(water <=5)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xC0;col[1]=0xC0;
			}
			else if(water <=7)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xE0;col[1]=0xE0;
			}
			else if(water <=8)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xF0;col[1]=0xF0;
			}
			else if(water <=9)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xF8;col[1]=0xF8;
			}
			else if(water <=10)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xF8;col[1]=0xF8;
			}
			else if(water <=11)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xFC;col[1]=0xFC;
				
			}
			else if(water <=12)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xFE;col[1]=0xFE;
			}
			else if(water <=13)
			{
				row[0]=0xEF;row[1]=0xEF;
				col[0]=0xFF;col[1]=0xFF;
			}
			//row2
			else if(water <=14)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0x80;
			}
			else if(water <=15)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0xC0;
			}
			else if(water <=16)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0xE0;
			}
			else if(water <=17)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0xF0;
			}
			else if(water <=18)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0xFC;
			}
			else if(water <=19)
			{
				row[0]=0xEF;row[1]=0xF7;
				col[0]=0xFF;col[1]=0xFE;
			}
			
			else if(water <=20)
			{
				row[0]=0xE7;row[1]=0xE7;
				col[0]=0xFF;col[1]=0xFF;
				//row  3
			}
			else if(water <=21)
			{
				row[0]=0xE7;row[1]=0xFB;
				col[0]=0xFF;col[1]=0xC0;
			}
			else if(water <=22)
			{
				row[0]=0xE7;row[1]=0xFB;
				col[0]=0xFF;col[1]=0xF0;
			}
			else if (water <=23)
			{
				row[0]=0xE7;row[1]=0xFB;
				col[0]=0xFF;col[1]=0xFC;
			}
			else if (water <=24)
			{
				row[0]=0xE3;row[1]=0xE3;
				col[0]=0xFF;col[1]=0xFF;
			}
			//row 4
			else if (water <=25)
			{
				row[0]=0xE3;row[1]=0xFD;
				col[0]=0xFF;col[1]=0xC0;
			}
			else if (water <=26)
			{
				row[0]=0xE3;row[1]=0xFD;
				col[0]=0xFF;col[1]=0xF0;
			}
			else if (water <=27)
			{
				row[0]=0xE3;row[1]=0xFD;
				col[0]=0xFF;col[1]=0xFC;
			}
			else if (water <=28)
			{
				row[0]=0xE3;row[1]=0xFD;
				col[0]=0xFF;col[1]=0xFE;
			}
			else if (water <=29)
			{
				row[0]=0xE1;row[1]=0xE1;
				col[0]=0xFF;col[1]=0xFF;
			}
			//row 5
			else if (water <=30)
			{
				row[0]=0xE1;row[1]=0xFE;
				col[0]=0xFF;col[1]=0x80;
			}
			else if (water <=31)
			{
				row[0]=0xE1;row[1]=0xFE;
				col[0]=0xFF;col[1]=0xC0;
			}
			else if (water <=32)
			{
				row[0]=0xE1;row[1]=0xFE;
				col[0]=0xFF;col[1]=0xF0;
			}
			else if (water <=33)
			{
				row[0]=0xE1;row[1]=0xFE;
				col[0]=0xFF;col[1]=0xFC;
			}
			else if(water <=36)
			{
				row[0]=0x00;row[1]=0x00;
				col[0]=0xFF;col[1]=0xFF;
			}
			else
			{
				temp=0;
			}
			if(water <=13 || water ==15  ||water==19 || water == 20 || water==25 ||(water >=33 && water <=36))
			{
				transmit_data(row[0]);
				transmit_data2(col[0]);
			}
			else
			{
				transmit_data(row[r]);
				transmit_data2(col[c]);
				
			}
			r++;
			c++;
			
			
			
			//_delay_us(450);
		}
}
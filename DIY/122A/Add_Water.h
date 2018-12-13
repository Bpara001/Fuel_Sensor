void AddWater()
{
	int port=0x08;
	char add_timer;
	int pump_duration=0;
	int temp_flag=1;
	while(temp_flag)
	{
		LCD_DisplayString_nclear(1,"H20 Amount Low:1Med:2 Full:3" );
		add_timer=GetKeypadKey();
		if ( add_timer=='1')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Adding Small    Amount of Water");
			pump_duration=2;
			temp_flag=0;
		}
		else if (add_timer=='2')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Adding Medium   Amount of Water");
			pump_duration=4;
			temp_flag=0;
		}
		else if (add_timer=='3')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Adding Maximum  Amount of Water");
			pump_duration=10;
			temp_flag=0;
		}
	}
	Matrix_Display(pump_duration,port);
	LCD_ClearScreen();
	PORTB=0x00;
	
}
//|| add_timer !='4' || add_timer !='5' || add_timer != '6'
void RemoveWater()
{
	char add_timer;
	int port=0x10;
	int pump_duration=0;
	int temp_flag=1;
	while(temp_flag)
	{
		LCD_DisplayString_nclear(1,"H20 Amount Low:4Med:5 Full:6" );
		add_timer=GetKeypadKey();
		if ( add_timer=='4')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Removing Small  Amount of Water");
			pump_duration=1;
			temp_flag=0;
		}
		else if (add_timer=='5')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Removing Medium Amount of Water");
			pump_duration=2;
			temp_flag=0;
		}
		else if (add_timer=='6')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Removing MaximumAmount of Water");
			pump_duration=3;
			temp_flag=0;
		}
	}
	
	Matrix_Display(pump_duration,port);
	LCD_ClearScreen();
	PORTB=0x00;
}

void Amount_User()
{
	int pass=1;
	int pass_next=1;
	char user_value;
	char user_value2;
	int amount;
	int amount2;
	int amount_total;
	int temp1;
	int temp2;
	int total;
	int title=1;
	int title_next=1;
	char amount_sum[16];
		while(pass)
		{
		if(title)
		{
			LCD_DisplayString_nclear(1,"How much water  to pump? max:36" );
			title=0;
		}
		user_value=GetKeypadKey();
		if(user_value== '0' )
		{
			amount=0;
			
			pass=0;
		}
		else if(user_value== '1')
		{
			amount=1;
			
			pass=0;
		}
		else if( user_value=='2')
		{
			amount=2;
			
			pass=0;
		}
		else if (user_value=='3')
		{
			amount=3;
			
			pass=0;
		}
		else if(user_value=='*')
		{
			pass==0;
			pass_next==0;
		}
		else if(user_value =='4' || user_value=='5' || user_value=='6' ||user_value=='7' || user_value=='8' || user_value=='9')
		{
			LCD_ClearScreen();
			LCD_DisplayString_nclear(1,"Too Much Enteredmax(1):36" );
			_delay_ms(600);
			title=1;
		}
		}
		_delay_ms(200);
		//next
		while(pass_next)
		{
			user_value2=GetKeypadKey();
			if(title_next)
			{
				LCD_DisplayString_nclear(1,"How much water  to pump2? max:36" );
				title_next=0;
			}
			if(user_value2== '0' )
			{
				amount2=0;
				pass_next=0;
				
			}
			else if(user_value2== '1')
			{
				amount2=1;
				pass_next=0;
		
			}
			else if( user_value2=='2')
			{
				amount2=2;
				pass_next=0;
				
			}
			else if (user_value2=='3')
			{
				amount2=3;
				pass_next=0;
				
				
			}
			else if (user_value2=='4')
			{
				amount2=4;
				pass_next=0;
			
			}
			else if (user_value2=='5')
			{
				amount2=5;
				pass_next=0;
				
			
			}
			else if (user_value2=='6')
			{
				amount2=6;
				pass_next=0;
			
			}
			else if(user_value2=='*')
			{
				
				pass_next=0;
				LCD_ClearScreen();
			}
			else if(user_value2=='7' || user_value2=='8' || user_value2=='9')
			{
				LCD_ClearScreen();
				LCD_DisplayString_nclear(1,"Too Much Enteredmax(2):36" );
				title=1;
				pass_next=0;
				_delay_ms(600);
				LCD_ClearScreen();
			}
		
		}
	
	if(pass==0 && pass_next==0)
	{
		
	
	total=(amount*10)+amount2;
	char new[3];
	new[0]=amount +'0';
	new[1]=amount2 + '0';
	new[3]='\0';
	LCD_DisplayString(1,"Entered amount:  ");
	LCD_DisplayString_nclear(17,new);
	
	delay_ms(1000);
	LCD_ClearScreen();
	}
	int rev=1;
	int port2;
	while(rev)
	{
		char x=GetKeypadKey();
		LCD_DisplayString_nclear(1,"A:add water     B:remove water");
		if(x=='A')
		{
			port2=0x08;
			rev=0;
		}
		else if(x=='B')
		{
			port2=0x10;
			rev=0;
		}
	}
	
	Water_Display(total, port2);

}
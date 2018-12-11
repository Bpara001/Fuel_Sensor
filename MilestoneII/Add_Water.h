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
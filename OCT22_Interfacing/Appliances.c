/*
 * Appliances.c
 *
 * Created: 4/17/2023 12:05:39 AM
 *  Author: user
 */ 
#include "Appliances.h"
#include "Keypad.h"

void HandleAC(AC_Mode ac_mode,AC_Operation ac_operation)
{
	
	if (ac_mode == AC_Auto)
	{
		u16 temp = 0;
		temp = LM35_Read(ADC_Channel0);
		if(temp >= 28)
		{
			activate_ac();
		}
		if(temp <= 21)
		{
			deactivate_ac();
		}
		
	}
	else if (ac_mode == AC_Man)
	{
		if (ac_operation == AC_On)
		{
			activate_ac();
		}
		else if (ac_operation == AC_Off)
		{
			deactivate_ac();
		}
	}
}

void HandleDoor()
{
	
}

void HandleLamps()
{
	
}

void HandleDimmingLamp()
{
	
}

void HandleLCD(States state)
{
	switch(state)
	{
		switch(state)
		{
			case Init:
			LCD_SetPos(1,0);
			LCD_String("1.SignUp Admin");
			LCD_SetPos(2,0);
			LCD_String("2.SignUp User");
			break;
			
			case SignUp_Admin:
			LCD_SetPos(1,0);
			LCD_String("Password:");
			LCD_SetPos(2,0);
			LCD_String(""); // Enter Password via keyboard
			break;
			
			case SignUp_User:
			LCD_SetPos(1,0);
			LCD_String("Password:");
			LCD_SetPos(2,0);
			LCD_String(""); // Enter Password via keyboard
			break;
			
			case LogIn_Menu:
			LCD_SetPos(1,0);
			LCD_String("1.Admin Mode");
			LCD_SetPos(2,0);
			LCD_String("2.User Mode");
			break;
			
			case LogIn_Admin:
			LCD_SetPos(1,0);
			LCD_String("Admin Mode ");
			LCD_SetPos(2,0);
			LCD_String("Password: ");
			LCD_SetPos(2,10);
			LCD_String("") // Enter Password via keyboard
			break;
			
			case LogIn_User:
			LCD_SetPos(1,0);
			LCD_String("User Mode ");
			LCD_SetPos(2,0);
			LCD_String("Password: ");
			LCD_SetPos(2,10);
			LCD_String("") // Enter Password via keyboard
			break;
			
			case Menu_Admin1:
			LCD_SetPos(1,0);
			LCD_String("1.Room1 2.Room2");
			LCD_SetPos(2,0);
			LCD_String("3.Room3 4.Room4");
			break;
			
			case Menu_Admin2:
			LCD_SetPos(1,0);
			LCD_String("1.Room5 2.Dim");
			LCD_SetPos(2,0);
			LCD_String("3.Door 4.Exit");
			break;
			
			case Menu_User1:
			LCD_SetPos(1,0);
			LCD_String("1.Room1 2.Room2");
			LCD_SetPos(2,0);
			LCD_String("3.Room3 4.Room4");
			break;
			
			case Menu_User2:
			LCD_SetPos(1,0);
			LCD_String("1.Room5 2.Dim");
			LCD_SetPos(2,0);
			LCD_String("3.Exit");
			break;
			
			case ROOM1:
			LCD_SetPos(1,0);
			LCD_String("1.ON 2.OFF");
			break;
			
			case ROOM2:
			LCD_SetPos(1,0);
			LCD_String("1.ON 2.OFF");
			break;
			
			case ROOM3:
			LCD_SetPos(1,0);
			LCD_String("1.ON 2.OFF");
			break;
			
			case ROOM4:
			LCD_SetPos(1,0);
			LCD_String("1.ON 2.OFF");
			break;
			
			case ROOM5:
			LCD_SetPos(1,0);
			LCD_String("1.ON 2.OFF");
			break;
			
			case Dimmer:
			LCD_SetPos(1,0);
			LCD_String("Levels");
			LCD_SetPos(2,0);
			LCD_String("1  2  3  4  5");
			break;
			
			case Door:
			LCD_SetPos(1,0);
			LCD_String("1.Open 2.Close");
			break;
		
	}	
}

u8 HandleKeypad()
{
	return GetKey();
}
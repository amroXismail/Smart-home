/*
 * Appliances.c
 *
 * Created: 4/17/2023 12:05:39 AM
 *  Author: user
 */ 
#include "Appliances.h"

void HandleAC()
{
	
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
		case MenuAdmin:
			LCD_SetPos(1,0);
			LCD_String("1.Room1 2.Room2");
			LCD_SetPos(2,0);
			LCD_String("3.Room3 4.Room4");
			break;
		
	}	
}

void HandleKeypad()
{
	
}
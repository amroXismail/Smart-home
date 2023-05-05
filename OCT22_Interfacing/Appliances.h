/*
 * Appliances.h
 *
 * Created: 3/30/2023 6:14:22 AM
 *  Author: user
 */ 


#ifndef APPLIANCES_H_
#define APPLIANCES_H_
# include "LCD.h"
typedef enum
{
	 Init = 0,
	 SignUp_Admin,
	 SignUp_User,
	 LogIn_Menu,
	 LogIn_Admin,
	 LogIn_User,
	 Menu_Admin1,
	 Menu_Admin2,
	 Menu_User1,
	 Menu_User2,
	 ROOM1,
	 ROOM2,
	 ROOM3,
	 ROOM4,
	 ROOM5,
	 Dimmer,
	 Door
	 
}States;

void HandleAC();
void HandleDoor();
void HandleLamps();
void HandleDimmingLamp();
void HandleLCD(States state);
void HandleKeypad();




#endif /* APPLIANCES_H_ */
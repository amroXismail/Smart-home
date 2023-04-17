/*
 * Appliances.h
 *
 * Created: 3/30/2023 6:14:22 AM
 *  Author: user
 */ 


#ifndef APPLIANCES_H_
#define APPLIANCES_H_

typedef enum
{
	 Init = 0,
	 MenuAdmin,
	 MenuUser,
	 
}States;

void HandleAC();
void HandleDoor();
void HandleLamps();
void HandleDimmingLamp();
void HandleLCD(States state);
void HandleKeypad();




#endif /* APPLIANCES_H_ */
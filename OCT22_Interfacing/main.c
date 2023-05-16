/*
* OCT22_Interfacing.c
*
* Created: 1/6/2023 2:55:18 PM
* Author : user
*/

#include <avr/interrupt.h>
#include <stdlib.h>
#include "DIO.h"
#include "LED.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "ADC.h"
#include "LM35.h"
#include "TIMERS.h"
#include "Ultrasonic.h"
#include "PWM.h"
#include "UART.h"
#include "SPI.h"
#include "TWI.h"
#include "EEPROM.h"
#include "User.h"
#include "Appliances.h"

int main(void)
{
	Keypad_Init();
	DIO_Init();
	LCD_Init();
	ADC_InitTypes ADCoptions = {ADC_PreScaler128,ADC_Vref_Internal};
	LM35_Init(&ADCoptions);
	while(1)
	{
		
	}
	
}
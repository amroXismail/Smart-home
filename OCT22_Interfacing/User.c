/*
 * User.c
 *
 * Created: 4/17/2023 12:06:08 AM
 *  Author: user
 */ 
#include "User.h"

void CreateUser(u8* password)
{
	u8 byteAddrs;
	byteAddrs = PASSWORD_LENGTH * EEPROM_ReadByte(USERS_COUNT_ADDRS);
	for (u8 i = 0 ; i<4 ; i++)
	{
		EEPROM_WriteByte(0x50, byteAddrs + i, password[i]);
	}
	EEPROM_WriteByte(0x50, USERS_COUNT_ADDRS ,EEPROM_ReadByte(USERS_COUNT_ADDRS)+1);
}

void DeleteUser(u8 userNo)
{
	u8 overWriteFrom;
	u8 overWriteTo;
	overWriteTo = (userNo - 1) * PASSWORD_LENGTH;
	overWriteFrom = userNo * PASSWORD_LENGTH;
	for (u8 i = 0 ; i < ((EEPROM_ReadByte(USERS_COUNT_ADDRS) - userNo) * PASSWORD_LENGTH) ; i++)
	{
		EEPROM_WriteByte(0x50 , overWriteTo , EEPROM_ReadByte(0x50 , overWriteFrom));
		overWriteTo++;
		overWriteFrom++;
	}
	for (u8 i = 0 ; i<4 ; i++)
	{
		EEPROM_WriteByte(0x50, overWriteFrom, 0);
		overWriteFrom++;
	}
	
}

void Alarm()
{
	_delay_ms(1000*20);
}

u8 Login(u8* password)
{
	u8 hasAcc = 0;
	for (u8 i = 0 ; i < (PASSWORD_LENGTH * EEPROM_ReadByte(0x50,USERS_COUNT_ADDRS)) ; i+=4)
	{
		if (password[0] == EEPROM_ReadByte(0x50, i))
		{
			if ((password[1] == EEPROM_ReadByte(0x50, i+1)
			&& (password[2] == EEPROM_ReadByte(0x50, i+2)
			&& (password[3] == EEPROM_ReadByte(0x50, i+3))
			{
				hasAcc = 1;
				return hasAcc;
			}
		}
	}
	return hasAcc;
}
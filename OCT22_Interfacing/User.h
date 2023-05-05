/*
 * User.h
 *
 * Created: 3/30/2023 12:37:14 AM
 *  Author: user
 */ 


#ifndef USER_H_
#define USER_H_
#include "EEPROM.h"
#include <avr/io.h>

#define USERS_COUNT_ADDRS 0x1FFF
#define PASSWORD_LENGTH 4

void CreateUser(u8 password);
void DeleteUser();
void Alarm();
u8 Login(u8* password);



#endif /* USER_H_ */
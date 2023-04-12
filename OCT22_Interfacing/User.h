/*
 * User.h
 *
 * Created: 3/30/2023 12:37:14 AM
 *  Author: user
 */ 


#ifndef USER_H_
#define USER_H_
typedef struct
{
	u8[10] UserName;
	u8[4] Password;
	u8 Admin:1;
}User;

void CreateUser();
void DeleteUser();
void Alarm();
void Login();



#endif /* USER_H_ */
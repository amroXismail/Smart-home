/*
* Ultrasonic.c
*
* Created: 2/11/2023 7:46:16 PM
*  Author: user
*/
#include "Ultrasonic.h"

extern unsigned long OVF_Count;

double Ultrasonic_Read(){
	//TIMER1_TCCR1A_Reg = 0;//Normal Mode
	//SetBit(TIMER1_TCCR1B_Reg,TIMER1_TCCR1B_CS10_Bit);//N = 8
	//SetBit(TIMER1_TCCR1B_Reg,TIMER1_TCCR1B_CS11_Bit);
	//SetBit(TIMER1_TCCR1B_Reg,TIMER1_TCCR1B_ICES1_Bit);//ICU Rising Edge
	TIMER1_TCCR1B_Reg.ICES1_Bit = 1;//ICU Rising Edge
	TIMER_TIFR_Reg.ICF1_Bit = 1;//clear ICF Flag
	
	DIO_WriteChannel(DIO_ChannelA0,STD_High);//Trigger
	_delay_us(10);
	DIO_WriteChannel(DIO_ChannelA0,STD_Low);
	
	//while (GetBit(TIMER_TIFR_Reg,TIMER_TIFR_ICF_Bit) == 0);//waiting Rising Edge
	while (TIMER_TIFR_Reg.ICF1_Bit == 0);
	TIMER1_TCNT1_Reg = 0;
	TIMER1_ICR1_Reg = 0;
	OVF_Count = 0;
	//ClearBit(TIMER1_TCCR1B_Reg,TIMER1_TCCR1B_ICES1_Bit);//ICU Falling Edge
	TIMER1_TCCR1B_Reg.ICES1_Bit = 0;
	//SetBit(TIMER_TIFR_Reg,TIMER_TIFR_ICF_Bit);//clear ICF Flag
	TIMER_TIFR_Reg.ICF1_Bit = 1;
	
	//while (GetBit(TIMER_TIFR_Reg,TIMER_TIFR_ICF_Bit) == 0);//waiting Falling Edge
	while (TIMER_TIFR_Reg.ICF1_Bit == 0);
	//SetBit(TIMER_TIFR_Reg,TIMER_TIFR_ICF_Bit);//clear ICF Flag
	TIMER_TIFR_Reg.ICF1_Bit = 1;
	
	unsigned long Count = TIMER1_ICR1_Reg + (OVF_Count*65536);
	double distance = (double)Count * 0.008575;
	//double distance = (double)Count *((SoundSpeed*(PreScale/F_CPU))/2);
	return distance;
}
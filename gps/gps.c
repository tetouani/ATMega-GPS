/*
 * gps.c
 *
 * Created: 2/24/2012 11:33:38 PM
 *  Author: Harindra
 */ 
#ifndef F_CPU
#define F_CPU 7372800UL
#endif
#include <avr/io.h>
#include "nmea_fsm.h"
#include "usart.h"
#include <util/delay.h>
//nmea.h is no longer used. instead, nmea_fsm.h will be used
int main(void)
{
	_delay_ms(20);//wait for the LCD to startup before sending commands
	init_HD44780();
	initButtonHandler();
	init_USART();
	
	write_HD44780_Command(DIS_ON_CUR_OFF_BLNK_OFF);
	_delay_ms(20);
	sei();//Enable global interrupts.
	init_NMEA_FSM();
	return 0;
}
/*
 * IO_Uno_lib.cpp
 *
 * Created: 22-Oct-15 10:10:20 AM
 *  Author: Trisna Julian
 */ 
#include <avr/io.h>
#include "IO_lib.h"



digital::digital()
{
	
}

digital::digital(digital_ch_t ch)
{
	channel=ch;
}

digital::~digital()
{
	
}


void digital::set_channel(digital_ch_t ch)
{
	channel=ch;
}
void digital::on(void)
{
	char ch=channel;
	if (ch>=8 && ch<=13)
	{
		PORTB|=(1<<(ch-8));
		DDRB|=(1<<(ch-8));
	}
	else
	{
		PORTD&=~(1<<ch);
		DDRD|=(1<<ch);
	}
}
void digital::off(void)
{
	char ch=channel;
	if (ch>=8 && ch<=13)
	{
		PORTB&=~(1<<(ch-8));
		DDRB|=(1<<(ch-8));
	}
	else
	{
		PORTD&=~(1<<ch);
		DDRD|=(1<<ch);
	}
}

char digital::read()
{
	char ch=channel;
	if (ch>=8 && ch<=13)
	{
		DDRB&=~(1<<(ch-8));
		return (PINB>>(ch-8))&0x01;
	}
	else
	{
		DDRD&=~(1<<ch);
		return (PIND>>ch)&0x01;
	}
}

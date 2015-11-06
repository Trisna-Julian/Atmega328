/*
 * serial_Uno_lib.cpp
 *
 * Created: 26-Oct-15 3:03:52 PM
 *  Author: Trisna Julian
 */ 


#include "serial_lib.h"

serial::serial()
{
	baud=Baud_9600;
	
	init();
}
serial::serial(baud_rate_t newBaud)
{
	baud=newBaud;
	
	init();
	
}
serial::~serial()
{
	
}

void serial::baud_setting(void)
{
	if (!(UCSR0A&(1<<U2X0)))
	{
		UBRR0H=(F_CPU/baud/16-1)>>8;
		UBRR0L=(F_CPU/baud/16-1);
	}
	else if (UCSR0A&(1<<U2X0))
	{
		UBRR0H=(F_CPU/baud/8-1)>>8;
		UBRR0L=(F_CPU/baud/8-1);
	}
	
}

void serial::init(void)
{
	//set baut rate
	
	baud_setting();
	//setting normal speed
	//UCSR0A&=~(1<<U2X0);
	//enable Tx and Rx and enable interrup Rx and Tx
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	UCSR0B|=(1<<RXCIE0)|(1<<TXCIE0);
	
	// set frame: data 8 bit, no parity and 1 stop bit
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);

}

unsigned char serial::flush (void)
{
	while (UCSR0A&(1<<RXC0));
	return UDR0;
}

void serial::putch(unsigned char c)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0=c;
}

void serial::puts(char *s)
{
	char c;
	
	while ((c=*s++)!='\0')
	{
		putch(c);
	}
}

char serial::getch(void)
{
	unsigned char ch;
	
	////mastiin gak ada data yang lagi dikirim / diterima
	while (!(UCSR0A&(1<<RXC0)));
	
	//baca data
	ch=UDR0;
	
	//verifikasi, dikembaliin ke terminal
	/*uart_putch2(ch);*/
	return ch;
}

char* serial::getstring(end_line_t EL)
{
// 	for(uint8_t i=0;i<max_buffer;i++)
// 	{
// 		buffer[i]=getch();
// 		if(buffer[i]==EL)
// 		{
// 			buffer[i]='\0';
// 			break;
// 		}
// 	}
// 	

	//sizeof(buffer) return array size in byte, size of(buffer[0]) return size of elemen in byte
	for(uint8_t i=0;i<(sizeof((buffer))/sizeof((buffer[0])));i++)
	{
		buffer[i]=getch();
		if (EL==CR)
		{
			if(buffer[i]==EL)
			{
				buffer[i]='\0';
				break;
			}
		}
		else if(EL==NL)
		{
			if(buffer[i]==EL)
			{
				buffer[i]='\0';
				break;
			}
		}
		else if(EL==CRNL)
		{
			if((buffer[i]==CR)&&(buffer[i+1]==NL))
			{
				buffer[i]='\0';
				break;
			}
		}
		else if(EL==NLCR)
		{
			if((buffer[i]==NL)&&(buffer[i+1]==CR))
			{
				buffer[i]='\0';
				break;
			}
		}
	}
	
	
	
	return buffer;
}

void serial::nr(void)
{
	putch('\n');
	putch('\r');
}

void serial::rn(void)
{
	putch('\r');
	putch('\n');
}

void serial::n(void)
{
	putch('\n');
}

void serial::r(void)
{
	putch('\r');
}

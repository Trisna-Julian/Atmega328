/*
 * USART_lib.h
 *
 * Created: 24-Apr-15 1:07:44 AM
 *  Author: Trisna Julian
 */ 


/*contoh penggunaan*/
// serial connect(Baud_19200);
// 
// connect.puts(adc2str(ADC0.read()));
// connect.putch(';');
// connect.puts(adc2str(ADC1.read()));
// connect.putch(';');
// connect.puts(adc2str(ADC2.read()));
// connect.putch(';');






#ifndef F_CPU
#define F_CPU 16000000
#endif


#ifndef SERIAL_LIB_H_
#define SERIAL_LIB_H_

#include <avr/io.h>
const uint8_t max_buffer=255;

typedef enum
{
	Baud_300 =300,
	Baud_1200 =1200,
	Baud_2400 =2400,
	Baud_4800 =4800,
	Baud_9600 =9600,
	Baud_19200 =19200,
	Baud_38400 =38400,
	Baud_57600 =57600,
	Baud_76800 =76800,
	Baud_115200 =115200
}baud_rate_t;

typedef enum
{
	CR='\r',
	NL='\n',
	CRNL,
	NLCR,
}end_line_t;


class serial
{
	public:
	//konstruktor
	serial();
	serial(baud_rate_t);
	~serial();
	
	//mutator function
	unsigned char flush (void);
	void putch(unsigned char c);
	void puts(char *s);
	char getch(void);
	void nr(void);
	void rn(void);
	void n(void);
	void r(void);
	char *getstring(end_line_t EL);
	
	private:
	baud_rate_t baud;
	char buffer[max_buffer];
	void baud_setting(void);
	void init(void);
	
	
	
};



#endif /* USART_LIB_H_ */

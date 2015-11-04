/*
 * convert.h
 *
 * Created: 28-May-15 7:26:46 AM
 *  Author: Trisna Julian
 */ 




#ifndef CONVERT_H_
#define CONVERT_H_

#include <math.h>


//convert number to ascii
uint16_t num2ascii(uint8_t angka)
{
	angka=angka+0x30;
	return angka;
}


//convert ADC 10 bit value to string
char* adc2str(uint16_t data)
{
	static char string[5];
	string[0]=num2ascii(data/1000);
	string[1]=num2ascii(data/100%10);
	string[2]=num2ascii(data/10%10);
	string[3]=num2ascii(data%10);
	string[4]='\0';
	
	return string;
}

//convert decimal value to string
char* dec2str(uint16_t data)
{
	static char string[6];
	string[0]=num2ascii(data/10000);
	string[1]=num2ascii(data/1000%10);
	string[2]=num2ascii(data/100%10);
	string[3]=num2ascii(data/10%10);
	string[4]=num2ascii(data%10);
	string[5]='\0';
	
	return string;
}

//convert decimal value to string
char* decimal2str(uint16_t data)
{
	static char string[6];
	string[0]=num2ascii(data/10000);
	string[1]=num2ascii(data/1000%10);
	string[2]=num2ascii(data/100%10);
	string[3]=num2ascii(data/10%10);
	string[4]=num2ascii(data%10);
	string[5]='\0';
	
	for(char n=0;n<5;n++)
	{
		if(string[0]=='0')
		{
			for(uint8_t i=0;i<5;i++)
			{
				string[i]=string[i+1];
			}
		}
		else
		{
			break;
		}
	}
	
	return string;
	
}

//convert decimal value to string
char* sdecimal2str(uint16_t data)
{
	static char string[7];
	if((data>>15)==1)
	{
		string[0]='-';
	}
	else
	{
		string[0]='+';
	}
	data&=~(1<<15);
	
	string[1]=num2ascii(data/10000);
	string[2]=num2ascii(data/1000%10);
	string[3]=num2ascii(data/100%10);
	string[4]=num2ascii(data/10%10);
	string[5]=num2ascii(data%10);
	string[6]='\0';
	
	for(uint8_t n=1;n<5;n++)
	{
		if(string[n]=='0')
		{
			for(uint8_t i=0;i<5;i++)
			{
				string[i]=string[i+1];
			}
		}
		else
		{
			break;
		}
	}
	
	return string;
	
}

//TODO

// char* float2str(float data)
// {
// 	static char string[7];
// 	if((data>>31)==1)
// 	{
// 		string[0]='-';
// 	}
// 	else
// 	{
// 		string[0]='+';
// 	}
// 	data&=~(1<<31);
// 	
// 	string[1]=num2ascii(data/10000);
// 	string[2]=num2ascii(data/1000%10);
// 	string[3]=num2ascii(data/100%10);
// 	string[4]=num2ascii(data/10%10);
// 	string[5]=num2ascii(data%10);
// 	string[6]='\0';
// 	
// 	for(char n=1;n<5;n++)
// 	{
// 		if(string[n]=='0')
// 		{
// 			for(char i=0;i<5;i++)
// 			{
// 				string[i]=string[i+1];
// 			}
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	}
// 	
// 	return string;
// 	
// }

//convert binnary to string (exampel 11110000) can be use for read value of register
char* uint2str(uint16_t in)
{
	static char string[16];
	for(char i=0;i<16;i++)
	{
		if(((in>>i)&0x01)==0x01)
		{
			string[15-i]='1';
		}
		else
		{
			string[15-i]='0';
		}
	}
	string[16]='\0';
	return string;
}



//convert bit to ascii
char* bit2char(bool b)
{
	static char string[2];
	string[0]=num2ascii(b);
	string[1]='\0';
	return string;
}

//convert byte to string
char* byte2str(char byte)
{
	static char string[8];
	for(char i=0;i<8;i++)
	{
		if(((byte>>i)&0x01)==0x01)
		{
			string[7-i]='1';
		}
		else
		{
			string[7-i]='0';
		}
	}
	string[8]='\0';
	return string;
}


//convert ASCII number '0'-'9'to number 0-9
char char2num (char c)
{
	switch (c)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
	
}


adc_ch_t char2ch (char string)
{
	switch (string)
	{
		case '0': return ch0;
		case '1': return ch1;
		case '2': return ch2;
		case '3': return ch3;
		case '4': return ch4;
		case '5': return ch5;
		case '6': return ch6;
		case '7': return ch7;
		default: return ch0;
	}
	
}

//convert a number 0-9 to ASCII representation '0'-'7'
char num2char (char c)
{
	switch(c)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		default: return '0';
	}
}




#endif /* CONVERT_H_ */

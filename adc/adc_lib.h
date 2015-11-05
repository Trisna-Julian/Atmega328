/*
 * adc_lib.h
 *
 * Created: 4/22/2015 11:38:12 PM
 *  Author: Trisna Julian
 */ 



#ifndef ADC_LIB_H_
#define ADC_LIB_H_

#ifndef F_CPU
#define F_CPU 16000000
#endif


/*-----------------exampel use---------------*/
// int main(void)
// {
//analog ADC1(AREF);
//analog ADC2()

// 	while(1)
// 	{
// 		int read1;
// 		int read2;
// 		
// 		read1=adc_read_10bit(div_128,low_speed);
// 		read2=adc_read_8bit(div_64,low_speed);
// 		
// 		
// 		
// 	}
// }


typedef enum
{
	AREF=0,
	AVCC=1,
	INTERNAL=3
}adc_ref_t;



typedef enum
{
	div_2=1,
	div_4=2,
	div_8=3,
	div_16=4,
	div_32=5,
	div_64=6,
	div_128=7,
}div_factor_t;

typedef enum
{
	low_speed=0,
	hi_speed=1,
}speed_t;

typedef enum
{
	
	ch0=0,
	ch1=1,
	ch2=2,
	ch3=3,
	ch4=4,
	ch5=5,
	ch6=6,
	ch7=7,
	
	ch0_10x=8,
	dif_ch10_10x=9,
	ch0_200x=10,
	dif_ch10_200x=11,
	ch2_10x=12,
	dif_ch32_10x=13,
	ch2_200x=14,
	dif_ch32_200x=15,
	
	dif_ch01=16,
	dif_ch11=17,
	dif_ch21=18,
	dif_ch31=19,
	dif_ch41=20,
	dif_ch51=21,
	dif_ch61=22,
	dif_ch71=23,
	dif_ch02=24,
	dif_ch12=25,
	dif_ch22=26,
	dif_ch32=27,
	dif_ch42=28,
	dif_ch52=29,
}adc_ch_t;

typedef enum
{
	freerun=0x00,
	comparator=0x01,
	exter_interup=0x02,
	time0_match=0x03,
	time0_overflow=0x04,
	time1_match=0x05,
	time1_overflow=0x06,
	time1_event=0x07,
}adc_trig_t;

class analog
{
	
	public:
	adc_ref_t Vreff;
	
	//default constructor
	analog();
	
	//overload constructor
	analog(adc_ref_t);
	analog(adc_ref_t,adc_ch_t);
	analog(adc_ref_t,adc_trig_t,adc_ch_t);
	
	//destructor
	~analog();
	
	//acesstor function
	
	
	//mutator function
	void set_ref(adc_ref_t);
	void set_trig(adc_trig_t);
	void set_channel(adc_ch_t);
	
	void set();
	
	int read();
	int readCh(adc_ch_t);
	int readCh(int);
	
	void start();
	void enable();
	void disable();
	void run();
	
	private:
	
	adc_trig_t trigger;
	adc_ch_t channel;
	
	unsigned int adc_prescaler();
};

#endif /* ADC_LIB_H_ */

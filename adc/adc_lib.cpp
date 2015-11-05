/*
 * adc_lib.cpp
 *
 * Created: 25-Oct-15 1:46:30 PM
 *  Author: Trisna Julian
 */ 

#include <avr/io.h>
#include "adc_lib.h"

//default constructor
analog::analog()
{
	Vreff=AVCC;
	trigger=freerun;
	channel=ch0;
	
	set();
	
}

//overload constructor
analog::analog(adc_ref_t newRef)
{
	Vreff=newRef;
	trigger=freerun;
	channel=ch0;
	
	set();
	
}

analog::analog(adc_ref_t newRef, adc_ch_t newCh)
{
	Vreff=newRef;
	trigger=freerun;
	channel=newCh;
	
	set();
	
}

analog::analog(adc_ref_t newRef, adc_trig_t newTrig, adc_ch_t newCh)
{
	Vreff=newRef;
	trigger=newTrig;
	channel=newCh;
	
	set();
}

//destructor
analog::~analog()
{
	
}




//mutator function
void analog::set_ref(adc_ref_t newRef)
{
	Vreff=newRef;
	
	set();
}
void analog::set_trig(adc_trig_t newTrig)
{
	trigger=newTrig;
	
	set();
}

void analog::set_channel(adc_ch_t newCh)
{
	channel=newCh;
	
	set();
}

void analog::set()
{
	if(((ADMUX>>REFS0)!=Vreff))
	{
		ADMUX&=~((1<<REFS0)&(1<<REFS1));
		ADMUX|=(Vreff<<REFS0);
	}
	
	
	; //set referensi
	
	ADMUX&=~(1<<ADLAR); //set ADLAR
	
	

	//DIDR0|=(1<<channel); //Digital Input Disable Register, mematikan input buffer digital
	
	ADCSRA|=adc_prescaler(); //set prescaler
	ADCSRA|=(1<<ADEN); //adc enable
}




int analog::read()
{
	ADMUX&=~((1<<MUX3)&(1<<MUX2)&(1<<MUX1)&(1<<MUX0));
	ADMUX|=channel; //set channel ADC
	ADCSRA|=(1<<ADSC); //adc start
	loop_until_bit_is_clear(ADCSRA,ADSC); //tunggu hasil
	
	return ADCW;
}



int analog::readCh(adc_ch_t ch)
{
	channel=ch; //change channel w/o change anything else
	//DIDR0|=(1<<channel); //Digital Input Disable Register, mematikan input buffer digital
	
	return read();
	
}



void analog::enable()
{
	ADCSRA|=(1<<ADEN); //ADC enable
}

void analog::disable()
{
	ADCSRA&=~(1<<ADEN); //ADC disable
}

void analog::start()
{
	ADCSRA|=(1<<ADSC); //adc start
}

void analog::run()
{
	ADMUX&=~((1<<MUX3)&(1<<MUX2)&(1<<MUX1)&(1<<MUX0));
	ADMUX|=channel; //set channel ADC
	
	ADCSRA|=(1<<ADEN); //adc enable
	ADCSRA|=adc_prescaler(); //setting prescaler
	ADCSRA|=(1<<ADIE); //adc interrup enable
	ADCSRA|=(1<<ADATE); //adc auto trigger enable
	ADCSRB|=trigger; //setting trigger
	
	ADCSRA|=(1<<ADSC); //start convertion
};

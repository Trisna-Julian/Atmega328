/*
 * Input_output.h
 *
 * Created: 28-Apr-15 9:19:43 PM
 *  Author: Trisna Julian
 */ 


#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

// IO liblary for atmega 328 and 168 (arduino uno and nano board)
// the diference between atmega 16 or 32 is atmega 328 doesn't have PORTA (see datasheet to be sure)

typedef enum
{
	dig_0=0,
	dig_1=1,
	dig_2=2,
	dig_3=3,
	dig_4=4,
	dig_5=5,
	dig_6=6,
	dig_7=7,
	dig_8=8,
	dig_9=9,
	dig_10=10,
	dig_11=11,
	dig_12=12,
	dig_13=13

}digital_ch_t;


class digital
{
	
	
	public:
	digital();
	digital(digital_ch_t);
	~digital();
	void set_channel(digital_ch_t);
	void on();
	void off();
	char read();
		
	private:
	digital_ch_t channel;
	
};





#endif /* INPUT_OUTPUT_H_ */

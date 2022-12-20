/*
 * @topic: Interfacing PCF8575 with AT89CS52
 * @author: Aditya Chaudhary
 */
 
#include <reg51.h>

//Configure SDA and SCL pins
sbit SDA = P2^0;
sbit SCL = P2^1;


void i2c_start();
void i2c_stop();
void generate_clock();
void i2c_write(unsigned char write_data);
void delay(unsigned int count);


void i2c_start(){
	SCL = 0;
	delay(1);
	
	SDA = 1;
	delay(1);
	SCL = 1;
	
	delay(1);
	
	SDA = 0;
	delay(1);
	SCL = 0;
	
}

void i2c_write(unsigned char write_data){
	unsigned int i;
	
	for(i = 0; i < 8; i++){
	
		SDA = (write_data&(1<<7))?1:0;
		
		generate_clock();
		
		write_data = write_data << 1;
	
	}
	
	generate_clock();
}

void i2c_stop(){
  SDA = 0;
	delay(1);
	SCL = 0;
	
	delay(1);
	
	SCL = 1;
	delay(1);
	SDA = 1;
}

void generate_clock(){
	delay(1);
	SCL = 1;
	delay(1);
	SCL = 0;
}

void write_to_pcf(unsigned char write_data,unsigned char write_data1){
	i2c_write(write_data); //For Port 0
	i2c_write(write_data1);
}

void delay(unsigned int count){

	while((count--) != 0);
}

void main(){
  
	i2c_start();
	i2c_write(0x40); //Sending slave address
	
	/*
	 *@param1 : Port 0
	 *@param2 : Port 1
	 */
	
	write_to_pcf(0x00,0xE0);
	i2c_stop();
}
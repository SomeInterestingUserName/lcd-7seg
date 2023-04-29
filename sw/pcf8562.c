#include "pcf8562.h"
#include <string.h>

void PCF8562_SetMode(int i2c_fd, unsigned char i2c_addr, PCF8562_Mode_Enable enable, PCF8562_Mode_Bias bias, PCF8562_Mode_Backplane backplane){
	PCF8562_I2CWriteByte(i2c_fd, i2c_addr, PCF8562_OPCODE_SETMODE | enable | bias | backplane); 
}

void PCF8562_LoadPointer(int i2c_fd, unsigned char i2c_addr, unsigned char ptrAddr){
	PCF8562_I2CWriteByte(i2c_fd, i2c_addr, PCF8562_OPCODE_LOADPTR | (ptrAddr & 0b00011111));
}

void PCF8562_SelectDevice(int i2c_fd, unsigned char i2c_addr, unsigned char devAddr){
	PCF8562_I2CWriteByte(i2c_fd, i2c_addr, PCF8562_OPCODE_DEVICESEL | (devAddr & 0b00000111));
}

void PCF8562_SetBlink(int i2c_fd, unsigned char i2c_addr, PCF8562_Blink_Mode mode, PCF8562_Blink_Freq freq){
	PCF8562_I2CWriteByte(i2c_fd, i2c_addr, PCF8562_OPCODE_BLINKSEL | mode | freq);
}

void PCF8562_SetBank(int i2c_fd, unsigned char i2c_addr, PCF8562_Bank_In bankIn, PCF8562_Bank_Out bankOut){
	PCF8562_I2CWriteByte(i2c_fd, i2c_addr, PCF8562_OPCODE_BANKSEL | bankIn | bankOut);
}

void PCF8562_WriteData(int i2c_fd, unsigned char i2c_addr, unsigned char ptrAddr, int numBytes, unsigned char * data){
	unsigned char buf[17];
	buf[0] = PCF8562_OPCODE_LOADPTR | (ptrAddr & 0b00011111);
	memcpy(&(buf[1]), data, numBytes);
	PCF8562_I2CWriteBytes(i2c_fd, i2c_addr, numBytes+1, buf);
}

void PCF8562_I2CConnect(int i2c_fd, unsigned char i2c_addr){
	ioctl(i2c_fd, I2C_SLAVE, i2c_addr);
}

void PCF8562_I2CWriteByte(int i2c_fd, unsigned char i2c_addr, unsigned char data){
	unsigned char buf[1];
	PCF8562_I2CConnect(i2c_fd, i2c_addr);
	buf[0] = data;
	write(i2c_fd, buf, 1);
}

void PCF8562_I2CWriteBytes(int i2c_fd, unsigned char i2c_addr, int numBytes, unsigned char * data){
	PCF8562_I2CConnect(i2c_fd, i2c_addr);
	write(i2c_fd, data, numBytes);
}

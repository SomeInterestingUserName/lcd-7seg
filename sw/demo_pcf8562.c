#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "lcd7seg.h"

// How many nanoseconds are in a millisecond
#define US_IN_MS 1E3

void sleep_millis(int millis){
	usleep(US_IN_MS * millis);
}

int main(){
    int i2c_file;
	
	// Set up I2C bus
    char * i2c_filename = "/dev/i2c-1";
    unsigned char pcf8562_addr = PCF8562_I2C_ADDR;

    if((i2c_file = open(i2c_filename,O_RDWR)) < 0){
        printf("ERROR: failed to open I2C bus\n");
        exit(1);
    }
	
	// Using char arrays avoids endianness issues (the LCD is "big-endian", ie the most significant digit has the lowest memory address)
	unsigned char buf[5];
	// Set up the LCD module
	LCD7Seg_init(i2c_file, pcf8562_addr);
	LCD7Seg_disableBlink(i2c_file, pcf8562_addr);
	
	while(1){
		// Turn on all segments for 2 seconds
		memset(buf, 0xFF, 4);
		LCD7Seg_writeToLCD(i2c_file, pcf8562_addr, 0, 4, buf);

		sleep(2);
		
		// Display alternates between "PCF" and "8562"
		for(int i=0; i<3; ++i){
			LCD7Seg_stringToLCDSimple(i2c_file, pcf8562_addr, "PCF");
			sleep(1);
			LCD7Seg_stringToLCDSimple(i2c_file, pcf8562_addr, "8562");
			sleep(1);
		}

		// Use the hardware blink function to alternatively flash "85" and "62".
		// Note that this animation requires no additional commands after setup, freeing 
		// the processor to do other tasks, in contrast to the previous animation.
		LCD7Seg_stringToLCD(i2c_file, pcf8562_addr, 0, 4, "85  ", 0);
		LCD7Seg_stringToLCD(i2c_file, pcf8562_addr, 1, 4, "  62", 0);
		LCD7Seg_enableBlink(i2c_file, pcf8562_addr, 1);

		sleep(3);
		
		// Stops blinking and displays the word "TEST" (or more accurately, "tESt") on the LCD
		LCD7Seg_disableBlink(i2c_file, pcf8562_addr);
		LCD7Seg_stringToLCDSimple(i2c_file, pcf8562_addr, "TEST");

		sleep(2);

		// Sequentially set and then clear all segments (I think this pattern looks cool)
		memset(buf, 0, 4);
		for(int i=0; i<64; ++i){
			int digit = (i/8)%4;
			buf[digit] >>= 1;
			if(i < 32)
				buf[digit] |= 0x80;
			LCD7Seg_writeToLCD(i2c_file, pcf8562_addr, 0, 4, buf);
			sleep_millis(100);
		}

		sleep(2);

		// Counts up from 0 to F in hexadecimal on all digits (displays 0000-FFFF)
		for(int i=0; i<16; ++i){
			if (i < 10)
				memset(buf, '0' + i, 4);
			else
				memset(buf, 'A' - 10 + i, 4);
			LCD7Seg_stringToLCDSimple(i2c_file, pcf8562_addr, buf);
			sleep_millis(500);
		}

		sleep(2);

		// Counts up from 0000 to 10000 at 100 Hz (approximately)
		for(int i=0; i<1001; ++i){
			sprintf(buf, "%04d", i);
			LCD7Seg_stringToLCDSimple(i2c_file, pcf8562_addr, buf);
			sleep_millis(10);
		}
		
		// Moves the decimal point around
		unsigned char dec = 0b10000000;
		int dir=0;
		for(int i=0; i<6; ++i){
			for(int j=0; j<3; ++j){
				LCD7Seg_stringToLCD(i2c_file, pcf8562_addr, 0, 4, buf, dec);
				if(dir)
					dec <<= 1;
				else
					dec >>= 1;

				sleep_millis(500);
			}
			dir = !dir;
		}

		sleep(2);
	}
}

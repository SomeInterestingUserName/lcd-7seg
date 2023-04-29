#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include "pcf8562.h"

int main(){
	int i2c_file;
	char * i2c_filename = "/dev/i2c-1";
	unsigned char pcf8562_addr = PCF8562_I2C_ADDR;

	if((i2c_file = open(i2c_filename,O_RDWR)) < 0){
		printf("ERROR: failed to open I2C bus\n");
		exit(1);
	}

	// Displays "8562" on the LCD
	unsigned char buf[4] = {0xfe, 0xb6, 0xbe, 0xda};
	
	PCF8562_SetMode(i2c_file, pcf8562_addr, PCF8562_MODE_ENABLE, PCF8562_MODE_BIAS_1_2, PCF8562_MODE_BACKPLANE_STATIC);
	PCF8562_WriteData(i2c_file, pcf8562_addr, 0, 4, buf);
	return 0;
}

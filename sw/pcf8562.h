/**
 * @file pcf8562.h
 * A collection of functions and definitions for the PCF8562 I2C LCD controller IC
 */

#ifndef PCF8562_H
#define PCF8562_H

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/** @brief The default I2C address, if pin SA0 is low */
#define PCF8562_I2C_ADDR 		(0x38)
/** @brief The alternate I2C address, if pin SA0 is high */
#define PCF8562_I2C_ADDR_SA0	(0x39)

/**
 * @brief Continue bit. This is bit 7 (MSB) of every opcode and is used to
 * signal whether the next byte is another opcode (1) or display data (0)
 */
typedef enum{
	PCF8562_CONTINUE	=	(1 << 7), 	/**< The next byte is another opcode */
	PCF8562_NOCONTINUE	=	0			/**< This is the last opcode before display data */
} PCF8562_Continue;

/**
 * @defgroup PCF8562Mode Mode Configuration
 * @{
 */

/**
 * @brief Enable bit. 1 to enable the display and 0 to disable (blank) the
 * display. The contents of the display memory are retained when in the disabled
 * state.
 */
typedef enum{
	PCF8562_MODE_ENABLE		=	(1 << 3),	/**< Enable the display */
	PCF8562_MODE_DISABLE	=	0			/**< Disable (blank) the display */
} PCF8562_Mode_Enable;

/**
 * @brief Sets the bias voltage level when driving a multiplexed display
 *
 * This setting has no effect in static mode.
 */
typedef enum{
	PCF8562_MODE_BIAS_1_2	=	(1 << 2),	/**< 1/2 bias */
	PCF8562_MODE_BIAS_1_3	=	0			/**< 1/3 bias */
} PCF8562_Mode_Bias;

/**
 * @brief Configures the number of backplanes to be driven
 */
typedef enum{
	PCF8562_MODE_BACKPLANE_STATIC	=	0b01, /**< Static (non-multiplexed) display */
	PCF8562_MODE_BACKPLANE_2		=	0b10, /**< 1:2 multiplexing (2 backplanes) */
	PCF8562_MODE_BACKPLANE_3		=	0b11, /**< 1:3 multiplexing */
	PCF8562_MODE_BACKPLANE_4		=	0b00  /**< 1:4 multiplexing */
} PCF8562_Mode_Backplane;
/**@}*/

/**
 * @defgroup PCF8562Bank Bank Selection
 *
 * **Bank selection is only available for static or 1:2 multiplexing modes.**
 *
 * @{
 */

/**
 * @brief Input bank selection
 */
typedef enum{
	PCF8562_BANK_IN_01	=	0,			/**< Input data will be written to bank 0 in static mode, or banks 0 and 1 in 1:2 multiplexing mode */
	PCF8562_BANK_IN_23	=	(1 << 1)	/**< Input data will be written to bank 2 in static mode, or banks 2 and 3 in 1:2 multiplexing mode */
} PCF8562_Bank_In;

/**
 * @brief Output bank selection
 */
typedef enum{
	PCF8562_BANK_OUT_01	=	0,	/**< Display the contents of Bank 0 in static mode, or banks 0 and 1 in 1:2 multiplexing mode */
	PCF8562_BANK_OUT_23	=	1	/**< Display the contents of Bank 2 in static mode, or banks 2 and 3 in 1:2 multiplexing mode */
} PCF8562_Bank_Out;
/**@}*/

/**
 * @defgroup PCF8562Blink Blink Configuration
 * @{
 */

/**
 * @brief Blink mode selection
 */
typedef enum{
	PCF8562_BLINK_MODE_NORMAL		=	0,			/**< Normal (on-off) blink mode */
	PCF8562_BLINK_MODE_ALTERNATE	=	(1 << 2)	/**< Alternate blink mode, which alternately displays the contents of the display memory banks. **Not available in 1:3 or 1:4 multiplexing modes** */
} PCF8562_Blink_Mode;

/**
 * @brief Blink frequency selection
 *
 * Blink frequency can be 1/768, 1/1536, or 1/3072 of f_clk
 * Frequency of internal f_clk is nominally 1850 Hz, but can be anywhere betwen
 * 1440 and 2640 Hz.
 */
typedef enum{
	PCF8562_BLINK_FREQ_DISABLE	=	0b00,	/**< Disable blinking */
	PCF8562_BLINK_FREQ_1		=	0b01,	/**< 1/768 * f_clk, or approx. 2.4 Hz on the internal oscillator */
	PCF8562_BLINK_FREQ_2		=	0b10,	/**< 1/1536 * f_clk, or approx. 1.2 Hz on the internal oscillator */
	PCF8562_BLINK_FREQ_3		=	0b11	/**< 1/3072 * f_clk, or approx. 0.6 Hz on the internal oscillator */
} PCF8562_Blink_Freq;
/**@}*/

/**
 * @brief Opcodes
 * Each non-data byte sent to the PCF8562 consists of a continue bit followed by
 * a 7-bit opcode, which consists of a command OR-ed together with its parameter
 * values. This enum contains the beginning parts of each command.
 */
typedef enum{
	PCF8562_OPCODE_LOADPTR		=	0b0000000,	/**< 0b00ppppp Set the device data pointer to ppppp */
	PCF8562_OPCODE_SETMODE		=	0b1000000,	/**< 0b100ebmm Set enable to e, bias level to b, and backplane to mm. See \ref PCF8562Mode for details */
	PCF8562_OPCODE_DEVICESEL	=	0b1100000,	/**< 0b1100aaa Select device aaa, which is helpful when multiple PCF8562 devices share the same I2C bus */
	PCF8562_OPCODE_BLINKSEL 	=	0b1110000, 	/**< 0b1110abb Set blink mode to a and blink frequency to bb. See \ref PCF8562Blink for details */
	PCF8562_OPCODE_BANKSEL		=	0b1111000	/**< 0b11110io Write incoming data to bank i and display data from bank o. See \ref PCF8562Bank for details */
} PCF8562_Opcode;

/**
 * @ingroup PCF8562Mode
 * @brief Configures PCF8562 Mode
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param enable Whether or not to display content on the LCD
 * @param bias Set the bias level of the LCD
 * @param backplane Set the multiplex mode of the LCD
 */
void PCF8562_SetMode(int i2c_fd, unsigned char i2c_addr, PCF8562_Mode_Enable enable, PCF8562_Mode_Bias bias, PCF8562_Mode_Backplane backplane);

/**
 * @brief Sets the PCF8562 data pointer address
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param ptrAddr the 5-bit address to set the data pointer. The upper 3 bits
 * are ignored.
 */
void PCF8562_LoadPointer(int i2c_fd, unsigned char i2c_addr, unsigned char ptrAddr);

/**
 * @brief Selects a particular PCF8562 depending on its A0, A1, and A2 pin
 * configuration
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param devAddr the 3-bit sub-address corresponding to the A2 (MSB), A1, and A0 (LSB) pin status of the device to select. The upper 5 bits are ignored.
 */
void PCF8562_SelectDevice(int i2c_fd, unsigned char i2c_addr, unsigned char devAddr);

/**
 * @ingroup PCF8562Blink
 * @brief Configures the blink function
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param mode sets either standard or alternate blinking modes
 * @param freq sets the blink frequency
 */
void PCF8562_SetBlink(int i2c_fd, unsigned char i2c_addr, PCF8562_Blink_Mode mode, PCF8562_Blink_Freq freq);

/**
 * @ingroup PCF8562Bank
 * @brief Sets the PCF8562 memory banks
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param bankIn the memory bank in which incoming data is stored 
 * @param bankOut the memory bank from which display data is shown on the LCD
 */
void PCF8562_SetBank(int i2c_fd, unsigned char i2c_addr, PCF8562_Bank_In bankIn, PCF8562_Bank_Out bankOut);

/**
 * @brief Writes display data to the PCF8562
 *
 * Writes an array of display data to the PCF8562, up to maxlen bytes. Note that
 * the PCF8562 can only store up to a maximum of 128 bits (16 bytes), though
 * this varies depending on multiplex mode. Attempting to write more bytes than
 * are available in the current multiplex mode may result in undefined behavior.
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param ptrAddr the memory address from which to start writing display data
 * @param numBytes the number of bytes to write
 * @param data the array of data to write
 */
void PCF8562_WriteData(int i2c_fd, unsigned char i2c_addr, unsigned char ptrAddr, int numBytes, unsigned char * data);

/**
 * @brief Establish an I2C connection to the PCF8562
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 */
void PCF8562_I2CConnect(int i2c_fd, unsigned char i2c_addr);

/**
 * @brief Write a single byte to the PCF8562 over I2C
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param data the byte to write
 */
void PCF8562_I2CWriteByte(int i2c_fd, unsigned char i2c_addr, unsigned char data);

/**
 * @brief Writes a series of bytes to the PCF8562 over I2C
 *
 * This function does not save a copy of data to be written; modifying the array
 * while a write is occurring may lead to unexpected output.
 *
 * @param i2c_fd the I2C device file descriptor                                 
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param numBytes the number of bytes to write
 * @param data the data to send
 */
void PCF8562_I2CWriteBytes(int i2c_fd, unsigned char i2c_addr, int numBytes, unsigned char * data);

#endif

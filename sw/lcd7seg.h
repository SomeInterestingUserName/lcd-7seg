/**
 * @file lcd7seg.h
 * Functions and definitions specific to this PCF8562-based LCD module. For more
 * advanced features, see \ref pcf8562.h
 */

#ifndef LCD7SEG_H
#define LCD7SEG_H

#include "pcf8562.h"

/*
 * Segment Definitions:
 *
 *      A
 *     ###
 *  F #   # B
 *    # G #
 *     ###
 *  E #   # C
 *    #   #
 *     ###  #
 *		D   DP
 *
 * Wiring:
 *
 * LCD Segment		PCF8562 Pin
 * A				S0
 * B				S1
 * C				S2
 * D				S3
 * E				S4
 * F				S5
 * G				S6
 * DP				S7
 */

#define LCD7SEG_CHAR_0	0b11111100			/**< the character '0' */
#define LCD7SEG_CHAR_1	0b01100000			/**< the character '1' */
#define LCD7SEG_CHAR_2	0b11011010			/**< the character '2' */
#define LCD7SEG_CHAR_3	0b11110010			/**< the character '3' */
#define LCD7SEG_CHAR_4	0b01100110			/**< the character '4' */
#define LCD7SEG_CHAR_5	0b10110110			/**< the character '5' */
#define LCD7SEG_CHAR_6	0b10111110			/**< the character '6' */
#define LCD7SEG_CHAR_7	0b11100000			/**< the character '7' */
#define LCD7SEG_CHAR_8	0b11111110			/**< the character '8' */
#define LCD7SEG_CHAR_9	0b11110110			/**< the character '9' */
#define LCD7SEG_CHAR_DP	0b00000001			/**< A decimal point */
                                  			
#define LCD7SEG_CHAR_A	0b11101110			/**< the character 'A' */
#define LCD7SEG_CHAR_B	0b00111110			/**< the character 'B' */
#define LCD7SEG_CHAR_C	0b10011100			/**< the character 'C' */
#define LCD7SEG_CHAR_D	0b01111010			/**< the character 'D' */
#define LCD7SEG_CHAR_E	0b10011110			/**< the character 'E' */
#define LCD7SEG_CHAR_F	0b10001110			/**< the character 'F' */
#define LCD7SEG_CHAR_G	0b11110110			/**< the character 'G' */
#define LCD7SEG_CHAR_H	0b01101110			/**< the character 'H' */
#define LCD7SEG_CHAR_I	0b01100000			/**< the character 'I' */
#define LCD7SEG_CHAR_J	0b01111000			/**< the character 'J' */
#define LCD7SEG_CHAR_L	0b00011100			/**< the character 'L' */
#define LCD7SEG_CHAR_N	0b11101100			/**< the character 'N' */
#define LCD7SEG_CHAR_O	0b11111100			/**< the character 'O' */
#define LCD7SEG_CHAR_P	0b11001110			/**< the character 'P' */
#define LCD7SEG_CHAR_Q	0b11100110			/**< the character 'Q' */
#define LCD7SEG_CHAR_R	0b00001010			/**< the character 'R' */
#define LCD7SEG_CHAR_S	0b10110110			/**< the character 'S' */
#define LCD7SEG_CHAR_T	0b00011110			/**< the character 'T' */
#define LCD7SEG_CHAR_U	0b01111100			/**< the character 'U' */
#define LCD7SEG_CHAR_MINUS	0b00000010		/**< the character '-' */ 
#define LCD7SEG_CHAR_UNDERSCORE	0b00010000	/**< the character '_' */ 
#define LCD7SEG_CHAR_BLANK 0b00000000		/**< no segments */
#define LCD7SEG_CHAR_ALL	0b11111111		/**< all segments */

/**
 * @brief Converts a char from ASCII to its LCD segment representation.
 *
 * Takes a single character and returns the byte representing the segments that 
 * need to be active to display the character. Unknown characters are replaced
 * with a blank.
 *
 * @param c the character to be converted
 * @return the LCD segment representation of the provided character
 */
unsigned char LCD7Seg_convertChar(unsigned char c);

/**
 * @brief Writes raw bytes to the LCD display memory, starting at 0.
 *
 * Configures the LCD module to accept display data bytes, then writes up to 4
 * bytes to the LCD's memory, in the specified bank. The output bank is set to
 * the bank that was just written, so the LCD always displays the contents of 
 * the display memory bank that was most recently modified. Writing to
 * different banks is a common approach to blinking segments on the LCD, as the
 * controller is capable of alternating between displaying the two banks.
 *
 * This function writes up to 4 bytes, or the specified maximum length,
 * whichever is smaller.
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param len the maximum length of data to send, up to 4 bytes
 * @param bank either 0 or 1, specifying whether to write to the first (0) or second (1) display memory bank
 * @param bytes a pointer to the start of the byte array from which to read data
 */
void LCD7Seg_writeToLCD(int i2c_fd, unsigned char i2c_addr, int bank, int len, char *bytes);

/**
 * @brief Writes a string to the LCD, including decimal points.
 *
 * Configures the LCD module to accept display data bytes, then writes
 * character data to the LCD representing the provided string and decimal point
 * data
 *
 * This function writes up to 4 bytes, or the specified maximum length,
 * whichever is smaller.
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param bank either 0 or 1, specifying whether to write to the first (0) or second (1) display memory bank
 * @param len the maximum length of the string to send, up to 4 bytes
 * @param str a pointer to the start of the string from which to read data
 * @param dp A byte representing which decimal points to activate. The most
 * significant bit (ie 0x80) corresponds to the most significant digit, the
 * second (ie 0x40) to the second-most significant digit, and so on. 
 */
void LCD7Seg_stringToLCD(int i2c_fd, unsigned char i2c_addr, int bank, int len, char * str, unsigned char dp);

/**
 * @brief Writes a string to the LCD, as simple as possible.
 *
 * Configures the LCD module to accept display data bytes, then writes
 * character data to the LCD representing the provided string.
 *
 * This function writes up to 4 bytes, but may write fewer bytes if the string
 * is null-terminated (\0) before four characters. This function is safe to use
 * on non-null-terminated strings, and will only write the first four
 * characters.
 *
 * This function writes to the first bank (Bank 0)
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param str a pointer to the start of the string from which to read data
 */
void LCD7Seg_stringToLCDSimple(int i2c_fd, unsigned char i2c_addr, char * str);


/**
 * @brief Sets up the PCF8562 to begin displaying data.
 *
 * Enables the LCD controller and configures it for the display type.
 *
 * The options it sets are: 
 *   * Enable: True
 *   * Bias: 1/3 (required but doesn't matter for static displays)
 *   * Backplane: Static
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 */
void LCD7Seg_init(int i2c_fd, unsigned char i2c_addr);

/**
 * @brief Enables the LCD's hardware blinking function
 *
 * Enables either standard (on-off) or alternate blinking, which alternates
 * between the two display memory banks.
 *
 * To set up alternate mode blinking, write data into both display memory banks.
 * The controller will then alternate between displaying the contents of bank 0
 * and bank 1.
 *
 * Blink frequency is approximately 1 Hz (though it uses the internal oscillator
 * so it may not be very precise)
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 * @param alternate 1 for alternate blinking, 0 for standard blinking.
 */
void LCD7Seg_enableBlink(int i2c_fd, unsigned char i2c_addr, unsigned char alternate);

/**
 * @brief Disables the LCD's hardware blinking function
 *
 * @param i2c_fd the I2C device file descriptor
 * @param i2c_addr the I2C address of the LCD module (either 0x38 (default) or 0x39)
 */
void LCD7Seg_disableBlink(int i2c_fd, unsigned char i2c_addr);

#endif

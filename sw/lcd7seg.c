#include "lcd7seg.h"

unsigned char LCD7Seg_convertChar(unsigned char c){
    switch (c){
        case '0':
            return LCD7SEG_CHAR_0;
        case '1':
            return LCD7SEG_CHAR_1;
        case '2':
            return LCD7SEG_CHAR_2;
        case '3':
            return LCD7SEG_CHAR_3;
        case '4':
            return LCD7SEG_CHAR_4;
        case '5':
            return LCD7SEG_CHAR_5;
        case '6':
            return LCD7SEG_CHAR_6;
        case '7':
            return LCD7SEG_CHAR_7;
        case '8':
            return LCD7SEG_CHAR_8;
        case '9':
            return LCD7SEG_CHAR_9;
        case 'A':
            return LCD7SEG_CHAR_A;
        case 'B':
            return LCD7SEG_CHAR_B;
        case 'C':
            return LCD7SEG_CHAR_C;
        case 'D':
            return LCD7SEG_CHAR_D;
        case 'E':
            return LCD7SEG_CHAR_E;
        case 'F':
            return LCD7SEG_CHAR_F;
        case 'G':
            return LCD7SEG_CHAR_G;
        case 'H':
            return LCD7SEG_CHAR_H;
        case 'I':
            return LCD7SEG_CHAR_I;
        case 'J':
            return LCD7SEG_CHAR_J;
        case 'L':
            return LCD7SEG_CHAR_L;
        case 'N':
            return LCD7SEG_CHAR_N;
        case 'O':
            return LCD7SEG_CHAR_O;
        case 'P':
            return LCD7SEG_CHAR_P;
        case 'Q':
            return LCD7SEG_CHAR_Q;
        case 'R':
            return LCD7SEG_CHAR_R;
        case 'S':
            return LCD7SEG_CHAR_S;
        case 'T':
            return LCD7SEG_CHAR_T;
        case 'U':
            return LCD7SEG_CHAR_U;
        case '-':
            return LCD7SEG_CHAR_MINUS;
        case '_':
            return LCD7SEG_CHAR_UNDERSCORE;
        default:
            return LCD7SEG_CHAR_BLANK;
    }
}

void LCD7Seg_writeToLCD(int i2c_fd, unsigned char i2c_addr, int bank, int len, char *bytes){
    if (!bank){
        PCF8562_SetBank(i2c_fd, i2c_addr, PCF8562_BANK_IN_01, PCF8562_BANK_OUT_01);
    }
    else{
        PCF8562_SetBank(i2c_fd, i2c_addr, PCF8562_BANK_IN_23, PCF8562_BANK_OUT_23);
    }
	PCF8562_WriteData(i2c_fd, i2c_addr, 0, len, bytes);
}

void LCD7Seg_stringToLCD(int i2c_fd, unsigned char i2c_addr, int bank, int len, char * str, unsigned char dp){
    unsigned char buf[4];
    for(int i=0; i<4; ++i){
        if(i >= len || str[i] == 0){
            buf[i] = LCD7SEG_CHAR_BLANK;
        }
        buf[i] = LCD7Seg_convertChar(str[i]);
        if (dp & (0b10000000 >> i)){
            buf[i] |= LCD7SEG_CHAR_DP;
        }
    }
    LCD7Seg_writeToLCD(i2c_fd, i2c_addr, bank, 4, buf);
}

void LCD7Seg_stringToLCDSimple(int i2c_fd, unsigned char i2c_addr, char * str){
    LCD7Seg_stringToLCD(i2c_fd, i2c_addr, 0, 4, str, 0);
}	

void LCD7Seg_init(int i2c_fd, unsigned char i2c_addr){
    PCF8562_SetMode(i2c_fd, i2c_addr, PCF8562_MODE_ENABLE, PCF8562_MODE_BIAS_1_3, PCF8562_MODE_BACKPLANE_STATIC);
}

void LCD7Seg_enableBlink(int i2c_fd, unsigned char i2c_addr, unsigned char alternate){
    unsigned char blinkMode;
    if(alternate){
        blinkMode = PCF8562_BLINK_MODE_ALTERNATE;
    }
    else{
        blinkMode = PCF8562_BLINK_MODE_NORMAL;
    }
    PCF8562_SetBlink(i2c_fd, i2c_addr, blinkMode, PCF8562_BLINK_FREQ_2);
}

void LCD7Seg_disableBlink(int i2c_fd, unsigned char i2c_addr){
    PCF8562_SetBlink(i2c_fd, i2c_addr, PCF8562_BLINK_MODE_NORMAL, PCF8562_BLINK_FREQ_DISABLE);
}

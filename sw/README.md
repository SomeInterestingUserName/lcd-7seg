# Software
Library to drive the 7 Segment LCD module using the Linux I2C interface. This should work on any I2C capable Linux system, such as the BeagleBone (tested) or Raspberry Pi (untested). Note that the PCF8562 driver IC will **not** respond to read commands, so `i2cdetect` may fail to detect this device. However, it does still respond with ACK to valid write commands. 

An invalid command may cause the module to stop responding. The only fix I can think of right now is to briefly disconnect it from power.

## Build instructions
1. First compile `pcf8562.c` : `gcc -c pcf8562.c`
2. Then compile `lcd7seg.c` : `gcc -c lcd7seg.c`
3. You can now include `pcf8562.o` and `lcd7seg.o` when building your own programs.

## Directory Structure
* `pcf8562.c` / `pcf8562.h` : A generic API for the PCF8562 IC, including all documented features/configurations from the datasheet.
* `lcd7seg.c` / `lcd7seg.h` : API for this specific 4-digit 7 segment LCD module, including some helpful functions that allow you to directly print strings to the LCD module.
* `demo_lcd7seg.c` : A demo program that showcases some of the LCD module's features. Build using `gcc pcf8562.o lcd7seg.o demo_lcd7seg.c`
* `hello_pcf8562.c` : A minimal example that writes "8562" (for the PCF8562) to the LCD. Build using `gcc pcf8562.o hello_pcf8562.c`
* `Doxyfile` A Doxygen API reference. You can generate a Doxygen page with `doxygen Doxyfile`

# lcd-7seg
A 4-digit 7-segment display module based on the NXP PCF8562 driver IC. The PCB fits a Lumex LCD-S401C52TR display. With the exception of Backplanes 2-4, all other pins of the PCF8562 are broken out to headers or jumpers to allow for evaluation of advanced features.
![Front view of the LCD module](img/front.jpg)
**Note:** The NXP datasheet currently lists the PCF8562 as "Not Recommended for New Designs". The PCF85162 (note the additional "1") is a drop-in replacement for this part. However, the PCF8562 (without the "1") is still widely available, and in fact appears to be available in larger quantities at the moment (as of January 2021).

## Hardware Notes
* The PCB was designed to fit JLCPCB's design rules. Although a quick cross-check shows these rules are compatible with some other PCB fabs, please check that they meet your preferred PCB fab's specs.
* If PCBs are manufactured using the HASL (Hot-Air Solder Leveling) surface finish, small solder bumps may be left on the TSSOP footprint's pins. It is recommended to clean these with some solder wick to make IC alignment easier. This is only necessary for the PCF8562 (U1).
* This board can be hand-soldered, although some practice is recommended. All passives are 0805 size, and the PCF8562 can be quickly "drag-soldered" using plenty of flux. Be sure to closely inspect the PCF8562 pins for solder bridges and touch-up with solder wick as necessary.
* All 3-way jumpers must have **one** option selected for the module to function correctly. The default values are:
    * `A0`: `0`
    * `A1`: `0`
    * `A2`: `0`
    * `I2C ADDR`: `0x70`
    * `OSC`: `INT`
    * `VLCD`: `VDD`

![Rear view of the LCD module](img/rear.jpg)

## Datasheets (from mouser.com)
* [PCF8562](https://www.mouser.com/datasheet/2/302/PCF8562-1127585.pdf) (Driver IC)
* [LCD-S401C52TR](https://www.mouser.com/datasheet/2/244/LCD-S401C52TR-1141159.pdf) (LCD)

EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "LCD 7 Segment Driver"
Date "2021-02-01"
Rev "2020.12"
Comp "github.com/SomeInterestingUserName/lcd-7seg"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L custom_components:LCD-S401C52TR DISP1
U 1 1 5FDDA4AA
P 7600 2150
F 0 "DISP1" H 8578 396 50  0000 L CNN
F 1 "LCD-S401C52TR" H 8578 305 50  0000 L CNN
F 2 "custom_components:S401C52TR" H 7600 2150 50  0001 C CNN
F 3 "" H 7600 2150 50  0001 C CNN
	1    7600 2150
	1    0    0    -1  
$EndComp
$Comp
L custom_components:PCF8562 U1
U 1 1 5FDDA59C
P 5750 2150
F 0 "U1" H 6275 2528 50  0000 C CNN
F 1 "PCF8562" H 6275 2437 50  0000 C CNN
F 2 "Package_SO:TSSOP-48_6.1x12.5mm_P0.5mm" V 6150 1900 50  0001 C CNN
F 3 "" V 6150 1900 50  0001 C CNN
	1    5750 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2350 7400 2350
Wire Wire Line
	7000 2250 7400 2250
Wire Wire Line
	7000 2550 7400 2550
Wire Wire Line
	7000 2450 7400 2450
Wire Wire Line
	7000 2750 7400 2750
Wire Wire Line
	7000 2650 7400 2650
Wire Wire Line
	7000 2950 7400 2950
Wire Wire Line
	7000 2850 7400 2850
Wire Wire Line
	7000 3150 7400 3150
Wire Wire Line
	7000 3050 7400 3050
Wire Wire Line
	7000 3350 7400 3350
Wire Wire Line
	7000 3250 7400 3250
Wire Wire Line
	7000 3550 7400 3550
Wire Wire Line
	7000 3450 7400 3450
Wire Wire Line
	7000 3750 7400 3750
Wire Wire Line
	7000 3650 7400 3650
Wire Wire Line
	7000 3950 7400 3950
Wire Wire Line
	7000 3850 7400 3850
Wire Wire Line
	7000 4150 7400 4150
Wire Wire Line
	7000 4050 7400 4050
Wire Wire Line
	7000 4350 7400 4350
Wire Wire Line
	7000 4250 7400 4250
Wire Wire Line
	7000 4550 7400 4550
Wire Wire Line
	7000 4450 7400 4450
Wire Wire Line
	7000 4750 7400 4750
Wire Wire Line
	7000 4650 7400 4650
Wire Wire Line
	7000 4950 7400 4950
Wire Wire Line
	7000 4850 7400 4850
Wire Wire Line
	7000 5150 7400 5150
Wire Wire Line
	7000 5050 7400 5050
Wire Wire Line
	7000 5350 7400 5350
Wire Wire Line
	7000 5250 7400 5250
Wire Wire Line
	7000 5550 7300 5550
Wire Wire Line
	7400 5650 7300 5650
Wire Wire Line
	7300 5650 7300 5550
Connection ~ 7300 5550
Wire Wire Line
	7300 5550 7400 5550
NoConn ~ 7000 5650
NoConn ~ 7000 5750
NoConn ~ 7000 5850
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5FDDD3C8
P 5250 2000
F 0 "JP2" V 5250 2068 50  0000 L CNN
F 1 "SolderJumper_2_Open" V 5295 2068 50  0001 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 5250 2000 50  0001 C CNN
F 3 "~" H 5250 2000 50  0001 C CNN
	1    5250 2000
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5FDDD48D
P 4950 2000
F 0 "JP1" V 4950 2068 50  0000 L CNN
F 1 "SolderJumper_2_Open" V 4995 2068 50  0001 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 4950 2000 50  0001 C CNN
F 3 "~" H 4950 2000 50  0001 C CNN
	1    4950 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FDDD6CD
P 5250 1600
F 0 "R2" H 5320 1646 50  0000 L CNN
F 1 "10k" H 5320 1555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5180 1600 50  0001 C CNN
F 3 "~" H 5250 1600 50  0001 C CNN
	1    5250 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FDDD77B
P 4950 1600
F 0 "R1" H 5020 1646 50  0000 L CNN
F 1 "10k" H 5020 1555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4880 1600 50  0001 C CNN
F 3 "~" H 4950 1600 50  0001 C CNN
	1    4950 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2150 5250 2250
Wire Wire Line
	5250 2250 5550 2250
Wire Wire Line
	4950 2150 4950 2350
Wire Wire Line
	4950 2350 5550 2350
Wire Wire Line
	5250 1750 5250 1850
Wire Wire Line
	4950 1750 4950 1850
Wire Wire Line
	4950 1450 4950 1350
Wire Wire Line
	4950 1350 5100 1350
Wire Wire Line
	5250 1350 5250 1450
Wire Wire Line
	5100 1350 5100 1250
Connection ~ 5100 1350
Wire Wire Line
	5100 1350 5250 1350
$Comp
L power:VDD #PWR01
U 1 1 5FDE1932
P 5100 1250
F 0 "#PWR01" H 5100 1100 50  0001 C CNN
F 1 "VDD" H 5117 1423 50  0000 C CNN
F 2 "" H 5100 1250 50  0001 C CNN
F 3 "" H 5100 1250 50  0001 C CNN
	1    5100 1250
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP3
U 1 1 5FDE1A57
P 3750 2150
F 0 "JP3" V 3750 2218 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 3705 2218 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3750 2150 50  0001 C CNN
F 3 "~" H 3750 2150 50  0001 C CNN
	1    3750 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR02
U 1 1 5FDE1C3D
P 3750 1900
F 0 "#PWR02" H 3750 1750 50  0001 C CNN
F 1 "VDD" H 3767 2073 50  0000 C CNN
F 2 "" H 3750 1900 50  0001 C CNN
F 3 "" H 3750 1900 50  0001 C CNN
	1    3750 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5FDE1CB3
P 3750 2400
F 0 "#PWR04" H 3750 2150 50  0001 C CNN
F 1 "GND" H 3755 2227 50  0000 C CNN
F 2 "" H 3750 2400 50  0001 C CNN
F 3 "" H 3750 2400 50  0001 C CNN
	1    3750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2400 3750 2350
Wire Wire Line
	3750 1900 3750 1950
$Comp
L Jumper:SolderJumper_3_Open JP4
U 1 1 5FDE3502
P 3600 2650
F 0 "JP4" V 3600 2718 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 3555 2718 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3600 2650 50  0001 C CNN
F 3 "~" H 3600 2650 50  0001 C CNN
	1    3600 2650
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR03
U 1 1 5FDE3508
P 3600 2400
F 0 "#PWR03" H 3600 2250 50  0001 C CNN
F 1 "VDD" H 3617 2573 50  0000 C CNN
F 2 "" H 3600 2400 50  0001 C CNN
F 3 "" H 3600 2400 50  0001 C CNN
	1    3600 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FDE350E
P 3600 2900
F 0 "#PWR06" H 3600 2650 50  0001 C CNN
F 1 "GND" H 3605 2727 50  0000 C CNN
F 2 "" H 3600 2900 50  0001 C CNN
F 3 "" H 3600 2900 50  0001 C CNN
	1    3600 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2900 3600 2850
Wire Wire Line
	3600 2400 3600 2450
$Comp
L Jumper:SolderJumper_3_Open JP5
U 1 1 5FDE41DC
P 3450 3150
F 0 "JP5" V 3450 3218 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 3405 3218 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3450 3150 50  0001 C CNN
F 3 "~" H 3450 3150 50  0001 C CNN
	1    3450 3150
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR05
U 1 1 5FDE41E3
P 3450 2900
F 0 "#PWR05" H 3450 2750 50  0001 C CNN
F 1 "VDD" H 3467 3073 50  0000 C CNN
F 2 "" H 3450 2900 50  0001 C CNN
F 3 "" H 3450 2900 50  0001 C CNN
	1    3450 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5FDE41E9
P 3450 3400
F 0 "#PWR08" H 3450 3150 50  0001 C CNN
F 1 "GND" H 3455 3227 50  0000 C CNN
F 2 "" H 3450 3400 50  0001 C CNN
F 3 "" H 3450 3400 50  0001 C CNN
	1    3450 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3400 3450 3350
Wire Wire Line
	3450 2900 3450 2950
$Comp
L Jumper:SolderJumper_3_Open JP6
U 1 1 5FDE4ED5
P 3300 3650
F 0 "JP6" V 3300 3718 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 3255 3718 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3300 3650 50  0001 C CNN
F 3 "~" H 3300 3650 50  0001 C CNN
	1    3300 3650
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR07
U 1 1 5FDE4EDC
P 3300 3400
F 0 "#PWR07" H 3300 3250 50  0001 C CNN
F 1 "VDD" H 3317 3573 50  0000 C CNN
F 2 "" H 3300 3400 50  0001 C CNN
F 3 "" H 3300 3400 50  0001 C CNN
	1    3300 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FDE4EE2
P 3300 3900
F 0 "#PWR010" H 3300 3650 50  0001 C CNN
F 1 "GND" H 3305 3727 50  0000 C CNN
F 2 "" H 3300 3900 50  0001 C CNN
F 3 "" H 3300 3900 50  0001 C CNN
	1    3300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3900 3300 3850
Wire Wire Line
	3300 3400 3300 3450
Wire Wire Line
	3900 2150 3950 2150
Wire Wire Line
	3950 2550 5550 2550
Wire Wire Line
	3950 2150 3950 2550
Wire Wire Line
	3750 2650 5550 2650
Wire Wire Line
	5550 2750 3700 2750
Wire Wire Line
	3700 2750 3700 3150
Wire Wire Line
	3700 3150 3600 3150
Wire Wire Line
	5550 2850 3750 2850
Wire Wire Line
	3750 2850 3750 3650
Wire Wire Line
	3750 3650 3450 3650
$Comp
L Jumper:SolderJumper_3_Open JP7
U 1 1 5FDF1EFC
P 3150 4150
F 0 "JP7" V 3150 4218 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 3105 4218 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3150 4150 50  0001 C CNN
F 3 "~" H 3150 4150 50  0001 C CNN
	1    3150 4150
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR09
U 1 1 5FDF1F03
P 3150 3900
F 0 "#PWR09" H 3150 3750 50  0001 C CNN
F 1 "VDD" H 3167 4073 50  0000 C CNN
F 2 "" H 3150 3900 50  0001 C CNN
F 3 "" H 3150 3900 50  0001 C CNN
	1    3150 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5FDF1F09
P 3150 4400
F 0 "#PWR012" H 3150 4150 50  0001 C CNN
F 1 "GND" H 3155 4227 50  0000 C CNN
F 2 "" H 3150 4400 50  0001 C CNN
F 3 "" H 3150 4400 50  0001 C CNN
	1    3150 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4400 3150 4350
Wire Wire Line
	3150 3900 3150 3950
Wire Wire Line
	3300 4150 3800 4150
Wire Wire Line
	3800 4150 3800 3050
Wire Wire Line
	3800 3050 5550 3050
$Comp
L Jumper:SolderJumper_3_Open JP8
U 1 1 5FDF50D2
P 3000 4650
F 0 "JP8" V 3000 4718 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 2955 4718 50  0001 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3000 4650 50  0001 C CNN
F 3 "~" H 3000 4650 50  0001 C CNN
	1    3000 4650
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR011
U 1 1 5FDF50D9
P 3000 4400
F 0 "#PWR011" H 3000 4250 50  0001 C CNN
F 1 "VDD" H 3017 4573 50  0000 C CNN
F 2 "" H 3000 4400 50  0001 C CNN
F 3 "" H 3000 4400 50  0001 C CNN
	1    3000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 4900 3000 4850
Wire Wire Line
	3000 4400 3000 4450
Wire Wire Line
	3150 4650 3850 4650
Wire Wire Line
	3850 4650 3850 3450
Wire Wire Line
	3850 3450 5550 3450
Text Label 3000 4900 3    50   ~ 0
VLCD
Text Label 5400 3150 2    50   ~ 0
CLK
Wire Wire Line
	5400 3150 5550 3150
Text Label 3850 5350 0    50   ~ 0
VSS
Wire Wire Line
	3600 5350 3850 5350
Text Label 3850 5450 0    50   ~ 0
VDD
Wire Wire Line
	3850 5450 3600 5450
Text Label 3850 5550 0    50   ~ 0
VLCD
Wire Wire Line
	3850 5550 3600 5550
$Comp
L Connector_Generic:Conn_01x07 J1
U 1 1 5FE1440F
P 3400 5650
F 0 "J1" H 3320 6167 50  0000 C CNN
F 1 "Conn_01x07" H 3320 6076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 3400 5650 50  0001 C CNN
F 3 "~" H 3400 5650 50  0001 C CNN
	1    3400 5650
	-1   0    0    -1  
$EndComp
Text Label 3850 5750 0    50   ~ 0
SCL
Text Label 3850 5650 0    50   ~ 0
SDA
Wire Wire Line
	3850 5650 3600 5650
Wire Wire Line
	3850 5750 3600 5750
Text Label 3850 5850 0    50   ~ 0
CLK
Wire Wire Line
	3850 5850 3600 5850
Wire Wire Line
	5400 3250 5550 3250
Text Label 5400 3250 2    50   ~ 0
~SYNC
Text Label 3850 5950 0    50   ~ 0
~SYNC
Wire Wire Line
	3850 5950 3600 5950
$Comp
L power:VDD #PWR013
U 1 1 5FE24650
P 4450 4450
F 0 "#PWR013" H 4450 4300 50  0001 C CNN
F 1 "VDD" H 4467 4623 50  0000 C CNN
F 2 "" H 4450 4450 50  0001 C CNN
F 3 "" H 4450 4450 50  0001 C CNN
	1    4450 4450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5FE247F7
P 4450 4500
F 0 "#FLG01" H 4450 4575 50  0001 C CNN
F 1 "PWR_FLAG" H 4450 4673 50  0000 C CNN
F 2 "" H 4450 4500 50  0001 C CNN
F 3 "~" H 4450 4500 50  0001 C CNN
	1    4450 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 4500 4450 4450
Wire Wire Line
	5250 2250 4800 2250
Connection ~ 5250 2250
Wire Wire Line
	4950 2350 4800 2350
Connection ~ 4950 2350
Text Label 4800 2250 2    50   ~ 0
SCL
Text Label 4800 2350 2    50   ~ 0
SDA
$Comp
L power:VSS #PWR0101
U 1 1 5FE2C5C1
P 4750 4450
F 0 "#PWR0101" H 4750 4300 50  0001 C CNN
F 1 "VSS" H 4767 4623 50  0000 C CNN
F 2 "" H 4750 4450 50  0001 C CNN
F 3 "" H 4750 4450 50  0001 C CNN
	1    4750 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FE2C61F
P 4750 4500
F 0 "#PWR0102" H 4750 4250 50  0001 C CNN
F 1 "GND" H 4755 4327 50  0000 C CNN
F 2 "" H 4750 4500 50  0001 C CNN
F 3 "" H 4750 4500 50  0001 C CNN
	1    4750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4500 4750 4450
$Comp
L Device:C C1
U 1 1 5FE35BB7
P 4450 6600
F 0 "C1" H 4565 6646 50  0000 L CNN
F 1 "10u" H 4565 6555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4488 6450 50  0001 C CNN
F 3 "~" H 4450 6600 50  0001 C CNN
	1    4450 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5FE35F53
P 4750 6600
F 0 "C2" H 4865 6646 50  0000 L CNN
F 1 "0.1u" H 4865 6555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4788 6450 50  0001 C CNN
F 3 "~" H 4750 6600 50  0001 C CNN
	1    4750 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5FE35F95
P 5250 6600
F 0 "C3" H 5365 6646 50  0000 L CNN
F 1 "10u" H 5365 6555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5288 6450 50  0001 C CNN
F 3 "~" H 5250 6600 50  0001 C CNN
	1    5250 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5FE35FCD
P 5550 6600
F 0 "C4" H 5665 6646 50  0000 L CNN
F 1 "0.1u" H 5665 6555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5588 6450 50  0001 C CNN
F 3 "~" H 5550 6600 50  0001 C CNN
	1    5550 6600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FE38A6E
P 4450 6900
F 0 "#PWR015" H 4450 6650 50  0001 C CNN
F 1 "GND" H 4455 6727 50  0000 C CNN
F 2 "" H 4450 6900 50  0001 C CNN
F 3 "" H 4450 6900 50  0001 C CNN
	1    4450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 6900 4450 6850
Wire Wire Line
	4450 6850 4750 6850
Wire Wire Line
	4750 6850 4750 6750
Connection ~ 4450 6850
Wire Wire Line
	4450 6850 4450 6750
Wire Wire Line
	4750 6850 5250 6850
Wire Wire Line
	5250 6850 5250 6750
Connection ~ 4750 6850
Wire Wire Line
	5250 6850 5550 6850
Wire Wire Line
	5550 6850 5550 6750
Connection ~ 5250 6850
Wire Wire Line
	5250 6450 5250 6350
Wire Wire Line
	5250 6350 5400 6350
Wire Wire Line
	5550 6350 5550 6450
Wire Wire Line
	4750 6450 4750 6350
Wire Wire Line
	4750 6350 4600 6350
Wire Wire Line
	4450 6350 4450 6450
$Comp
L power:VDD #PWR014
U 1 1 5FE4A606
P 4600 6250
F 0 "#PWR014" H 4600 6100 50  0001 C CNN
F 1 "VDD" H 4617 6423 50  0000 C CNN
F 2 "" H 4600 6250 50  0001 C CNN
F 3 "" H 4600 6250 50  0001 C CNN
	1    4600 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 6250 4600 6350
Connection ~ 4600 6350
Wire Wire Line
	4600 6350 4450 6350
Wire Wire Line
	5400 6250 5400 6350
Connection ~ 5400 6350
Wire Wire Line
	5400 6350 5550 6350
Text Label 5400 6250 1    50   ~ 0
VLCD_JP
Text Label 4750 3450 1    50   ~ 0
VLCD_JP
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5FE527D5
P 8750 1350
F 0 "H1" H 8700 1550 50  0000 L CNN
F 1 "MountingHole_Pad" H 8850 1310 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 8750 1350 50  0001 C CNN
F 3 "~" H 8750 1350 50  0001 C CNN
	1    8750 1350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5FE5622A
P 8950 1350
F 0 "H2" H 8900 1550 50  0000 L CNN
F 1 "MountingHole_Pad" H 9050 1310 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 8950 1350 50  0001 C CNN
F 3 "~" H 8950 1350 50  0001 C CNN
	1    8950 1350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5FE5626C
P 9150 1350
F 0 "H3" H 9100 1550 50  0000 L CNN
F 1 "MountingHole_Pad" H 9250 1310 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9150 1350 50  0001 C CNN
F 3 "~" H 9150 1350 50  0001 C CNN
	1    9150 1350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5FE562A8
P 9350 1350
F 0 "H4" H 9300 1550 50  0000 L CNN
F 1 "MountingHole_Pad" H 9450 1310 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9350 1350 50  0001 C CNN
F 3 "~" H 9350 1350 50  0001 C CNN
	1    9350 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5FE563C8
P 8750 1550
F 0 "#PWR016" H 8750 1300 50  0001 C CNN
F 1 "GND" H 8755 1377 50  0000 C CNN
F 2 "" H 8750 1550 50  0001 C CNN
F 3 "" H 8750 1550 50  0001 C CNN
	1    8750 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 1550 8750 1500
Wire Wire Line
	8750 1500 8950 1500
Wire Wire Line
	8950 1500 8950 1450
Connection ~ 8750 1500
Wire Wire Line
	8750 1500 8750 1450
Wire Wire Line
	8950 1500 9150 1500
Wire Wire Line
	9150 1500 9150 1450
Connection ~ 8950 1500
Wire Wire Line
	9150 1500 9350 1500
Wire Wire Line
	9350 1500 9350 1450
Connection ~ 9150 1500
$EndSCHEMATC

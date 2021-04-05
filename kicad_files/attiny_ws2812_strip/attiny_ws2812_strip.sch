EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED:WS2812B D1
U 1 1 601102DC
P 6600 3300
F 0 "D1" H 6941 3346 50  0000 L CNN
F 1 "WS2812B" H 6941 3255 50  0000 L CNN
F 2 "LED_custom:ws2812_header_custom_smd_strip" H 6650 3000 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 6700 2925 50  0001 L TNN
	1    6600 3300
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATtiny:ATtiny85-20SU U2
U 1 1 601103CF
P 5250 3200
F 0 "U2" H 4720 3246 50  0000 R CNN
F 1 "ATtiny85-20SU" H 4720 3155 50  0000 R CNN
F 2 "arduino:attiny85_arduino_enbedded" H 5250 3200 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 5250 3200 50  0001 C CNN
	1    5250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3300 6300 3300
Wire Wire Line
	6600 3600 6600 3800
Wire Wire Line
	5250 2600 6600 2600
Wire Wire Line
	6600 2600 6600 3000
$Comp
L battery_custom:battery_custom U1
U 1 1 60110501
P 3850 3150
F 0 "U1" V 4115 3219 50  0000 C CNN
F 1 "battery_custom" V 4024 3219 50  0000 C CNN
F 2 "battery_connector_custom:vcc_gnd_2pin_custom" H 3850 3150 50  0001 C CNN
F 3 "" H 3850 3150 50  0001 C CNN
	1    3850 3150
	0    -1   -1   0   
$EndComp
Connection ~ 5250 3800
Wire Wire Line
	5250 3800 6600 3800
Wire Wire Line
	3950 3200 3950 3800
Wire Wire Line
	3950 3800 5250 3800
Wire Wire Line
	3950 3100 3950 2600
Wire Wire Line
	3950 2600 5250 2600
Connection ~ 5250 2600
$EndSCHEMATC

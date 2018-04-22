// 1-channel LoRa Gateway for ESP8266
// Copyright (c) 2016, 2017 Maarten Westenberg version for ESP8266
// Version 5.0.9
// Date: 2018-04-07
//
// 	based on work done by Thomas Telkamp for Raspberry PI 1ch gateway
//	and many others.
//
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the MIT License
// which accompanies this distribution, and is available at
// https://opensource.org/licenses/mit-license.php
//
// Author: Maarten Westenberg (mw12554@hotmail.com)
//
// This file contains a number of compile-time settings and definitions for OLED support.
//
// ----------------------------------------------------------------------------------------

// OLEDs dupported by this program must be I2C.
// This is because we do not want any diisturbance in the SPI area
// which is also interfacing the LORA tranceiver.
//
// The following OLDs are supported:
// 0. No OLED connected
// 1. 0.9" OLED (cheap)
// 2. 1.3" OLED with much better display

#if OLED>=1

#if ESP32BUILD
#define OLED_SCL 15              // GPIO5 / D1
#define OLED_SDA 4              // GPIO4 / D2
#else
#define OLED_SCL 5								// GPIO5 / D1
#define OLED_SDA 4								// GPIO4 / D2
#endif

#define OLED_ADDR 0x3C            // Default 0x3C for 0.9", for 1.3" it is 0x78

#if OLED==1
#include "SSD1306.h"
#endif

// This is an 1.3" OLED display which is runnint on I2C
#if OLED==2
#include "SH1106.h"
#endif

SSD1306  display(OLED_ADDR, OLED_SDA, OLED_SCL);// i2c ADDR & SDA, SCL on wemos

#endif//OLED>=1

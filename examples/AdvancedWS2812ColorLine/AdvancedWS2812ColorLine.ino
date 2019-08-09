//----------------------------------------------------
// File:		AdvancedWS2812ColorLine.ino
// Version:  	v0.1.0
// Change date:	09.08.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------

#include <WS2812.h>

//-Led
//DOut MC
uint8_t dataPin = 12;
//Connected Leds on data line
uint8_t ledQuantity = 4;
unsigned char color[] = { 	50, 100, 200	};

WS2812 ws2812 = WS2812(ledQuantity, dataPin);

//Setup
void setup(void) {
	Serial.begin(115200);
	while(!Serial);
	Serial.println();
	Serial.println("Ready!");
	
}
//Loop
void loop() 
{
	ws2812.showColorLine(&color[0]);
	Serial.println("f");
	delay(1000);
}
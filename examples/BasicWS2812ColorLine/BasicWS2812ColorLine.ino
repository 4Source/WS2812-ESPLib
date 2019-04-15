//----------------------------------------------------
// File:		BasicWS2812ColorLine.ino
// Version:  	v0.1
// Change date:	15.04.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------

#include <WS2812.h>

//-Led
//DOut MC
uint8_t dataPin = 12;
//Connected Leds on data line
uint8_t ledQuantity = 3;	

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
	ws2812.showColorLine(0,0,0);
	delay(1000);
}
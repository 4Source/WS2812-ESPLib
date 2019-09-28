//----------------------------------------------------
// File:		BasicWS2812SingleChange.ino
// Version:  	v0.1.9
// Change date:	28.09.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------

#include <WS2812.h>

//-Led
//DOut MC
uint8_t dataPin = 12;
//Connected Leds on data line
uint8_t ledQuantity = 3;	
//Red Value 0-255
uint8_t red = 0;
//Green Value 0-255
uint8_t green = 50;
//Blue Value 0-255
uint8_t blue = 100;
//Led Nr Value 0-(ledQuantity)
uint8_t nr = 1;

WS2812 ws2812 = WS2812(ledQuantity, dataPin);

//Setup
void setup(void) {
	Serial.begin(115200);
	while(!Serial);
	Serial.println();
	Serial.println("Ready!");
	
	ws2812.Single(red, green, blue, nr);
	ws2812.Single(0, 100, 0, 0);
	ws2812.show();
}
//Loop
void loop() 
{

}
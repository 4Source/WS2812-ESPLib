//----------------------------------------------------
// File:		BasicWS2812SingleChange.ino
// Version:  	v0.1
// Change date:	08.05.2019
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
	
	ws2812.showChangeSingle(50,0,0,1);
	ws2812.showChangeSingle(0,100,0,0);
}
//Loop
void loop() 
{

}
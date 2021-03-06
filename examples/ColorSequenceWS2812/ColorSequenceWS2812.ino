//----------------------------------------------------
// File:		ColorSequenceWS2812.ino
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
unsigned char color[9];
unsigned char muster[] = {	255,0,0,	0,0,0,		0,0,0,
							0,0,0,		255,0,0,	0,0,0,
							0,0,0,		0,0,0,		255,0,0};

int tick=0;

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
	ws2812.showSpecificColorLine(&color[0]);

	for(int i = 0; i < 9; i++)
	{
		color[i] = muster[i+(tick*9)];
	}
	
	if(tick >= 2)
	{
		tick = 0;
	}
	else
	{
		tick++;
	}
	
	delay(1000);
	Serial.println(tick);
}
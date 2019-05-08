//----------------------------------------------------
// File:		WS2812.h
// Version:  	v0.1.2
// Change date:	08.05.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------
#ifndef WS2812_h
#define WS2812_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <arduino.h>
#endif

#include <Adafruit_NeoPixel.h>

class WS2812
{
	private:
		Adafruit_NeoPixel neoPixel;
		uint8_t aktivPixel;
		uint8_t pixels;
		uint8_t pin;
		
		void sendPixelGRB( unsigned char, unsigned char, unsigned char);
		void show();
		
	public:
		WS2812(uint8_t,uint8_t);
	
		void showChangeSingle( unsigned char, unsigned char, unsigned char, uint8_t );		//Change Singel Led Color
		void showColorLine( unsigned char, unsigned char, unsigned char);					//Show all Leds same Color
		void showSpecificColorLine(unsigned char*);											//Show for every Led Specific Color
		uint8_t countPixel();
		void setPixels(uint8_t);
		uint8_t getPin();
		void setPin(uint8_t);
	
};
#endif
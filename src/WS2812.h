//----------------------------------------------------
// File:	WS2812.h
// Version:  	v0.1.4
// Change date:	10.06.2019
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
	
		void showChangeSingle(unsigned char, unsigned char, unsigned char, uint8_t);
		void showChangeSingle(uint32_t);
		void showColorLine(unsigned char, unsigned char, unsigned char);
		void showColorLine(unsigned char*);
		void showSpecificColorLine(unsigned char*);
		uint8_t countPixel();
		void setPixels(uint8_t);
		uint8_t getPin();
		void setPin(uint8_t);
	
};
#endif
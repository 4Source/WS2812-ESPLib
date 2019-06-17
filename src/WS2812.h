//----------------------------------------------------
// File:	WS2812.h
// Version:  	v0.1.5
// Change date:	17.06.2019
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
		
		void sendPixelGRB( uint8_t, uint8_t, uint8_t);
		void show();
		
	public:
		WS2812(uint8_t,uint8_t);
	
		void showChangeSingle(uint8_t, uint8_t, uint8_t, uint8_t);
		void showChangeSingle(uint32_t);
		void showColorLine(uint8_t, uint8_t, uint8_t);
		void showColorLine(uint8_t*);
		void showSpecificColor(uint8_t*);
		uint8_t countPixel();
		void setPixels(uint8_t);
		uint8_t getPin();
		void setPin(uint8_t);
	
};
#endif
//----------------------------------------------------
// File:	WS2812.h
// Version:  	v0.1.8
// Change date:	26.09.2019
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
		
	public:
		WS2812(uint8_t,uint8_t);
		
		void show();
	
		void showChangeSingle(uint8_t, uint8_t, uint8_t, uint8_t);
		void showChangeSingle(uint32_t);
		
		void showColorLine(uint8_t, uint8_t, uint8_t);
		void showColorLine(uint8_t*);
		
		void showSpecificColor(uint8_t*);
		
		static uint32_t color(uint8_t, uint8_t, uint8_t);
		static uint32_t color(uint8_t, uint8_t, uint8_t, uint8_t);
		static uint8_t color_red(uint32_t);
		static uint8_t color_green(uint32_t);
		static uint8_t color_blue(uint32_t);
		static uint8_t color_white(uint32_t);
		
		uint8_t countPixel();
		void setPixels(uint8_t);
		uint8_t getPin();
		void setPin(uint8_t);
	
};
#endif
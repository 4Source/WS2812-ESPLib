//----------------------------------------------------
// File:		WS2812.cpp
// Version:  	v0.1.2
// Change date:	15.04.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------
#include "WS2812.h"
//Set the specified pin as Digital Output 
WS2812::WS2812(uint8_t countPixel, uint8_t gpio_pin)
{
	#if defined (__AVR_ATtiny85__)
	if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
	#endif
	
	pixels=countPixel;
	pin=gpio_pin;
	
	neoPixel = Adafruit_NeoPixel(countPixel, gpio_pin, NEO_GRB + NEO_KHZ800);
	
	neoPixel.begin();
	neoPixel.show(); 
}
void WS2812::sendPixelGRB( unsigned char r, unsigned char g , unsigned char b )  
{
	neoPixel.setPixelColor(aPixel, r, g, b);  
}
void WS2812::show() 
{
	neoPixel.show();
}
//Show Color for all pixels
void WS2812::showColorLine( unsigned char r , unsigned char g , unsigned char b ) 
{ 
	aPixel=0;
	for( int p = 0; p  < pixels; p++ ) 
	{
		sendPixelGRB( r , g , b );
		aPixel++;
	}
	show();
}
//Show specific Color for each pixel
void WS2812::showSpecificColorLine(unsigned char *buffer)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	aPixel=0;
	for( int p = 0; p  < pixels; p++ ) 
	{
		r = *buffer;
		buffer++;
		g = *buffer;
		buffer++;
		b = *buffer;
		buffer++;

		sendPixelGRB( r , g , b );
		aPixel++;
	}
	show();
}

uint8_t WS2812::countPixel()
{
	return pixels;
}
void WS2812::setPixels(uint8_t countPixel)
{
	pixels=countPixel;
}
uint8_t WS2812::getPin()
{
	return pin;
}
void WS2812::setPin(uint8_t gpio_pin)
{
	pin = gpio_pin;
}

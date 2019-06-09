//----------------------------------------------------
// File:	WS2812.cpp
// Version:  	v0.1.3
// Change date:	09.06.2019
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
	
	pixels = countPixel;
	pin = gpio_pin;
	
	neoPixel = Adafruit_NeoPixel(pixels, pin, NEO_GRB + NEO_KHZ800);
	
	neoPixel.begin();
	neoPixel.show(); 
}
void WS2812::sendPixelGRB( unsigned char r, unsigned char g , unsigned char b )  
{
	neoPixel.setPixelColor(aktivPixel, r, g, b);  
}
void WS2812::show() 
{
	neoPixel.show();
}
//Show Color for all pixels
void WS2812::showChangeSingle( unsigned char r , unsigned char g , unsigned char b, uint8_t pixelNr ) 
{ 
	if(pixelNr < pixels)
	{
		aktivPixel = pixelNr;
		sendPixelGRB( r , g , b );
		show();
	}
}
//Show Color for all pixels
void WS2812::showColorLine( unsigned char r , unsigned char g , unsigned char b ) 
{ 
	aktivPixel = 0;
	while( aktivPixel  < pixels ) 
	{
		sendPixelGRB( r , g , b );
		aktivPixel++;
	}
	show();
}
//Show specific Color for each pixel
void WS2812::showSpecificColorLine(unsigned char *buffer)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	aktivPixel = 0;
	while( aktivPixel  < pixels ) 
	{
		r = *buffer;
		buffer++;
		g = *buffer;
		buffer++;
		b = *buffer;
		buffer++;

		sendPixelGRB( r , g , b );
		aktivPixel++;
	}
	show();
}

uint8_t WS2812::countPixel()
{
	return pixels;
}
void WS2812::setPixels(uint8_t countPixel)
{
	pixels = countPixel;
	neoPixel.updateLength(pixels);
}
uint8_t WS2812::getPin()
{
	return pin;
}
void WS2812::setPin(uint8_t gpio_pin)
{
	pin = gpio_pin;
	neoPixel.setPin(pin);
}

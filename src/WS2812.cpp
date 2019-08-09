//----------------------------------------------------
// File:	WS2812.cpp
// Version:  	v0.1.6
// Change date:	09.08.2019
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
void WS2812::sendPixelGRB( uint8_t r, uint8_t g , uint8_t b )  
{
	// Serial.print("nr,r,g,b: "); Serial.print(aktivPixel); Serial.print(", ");Serial.print(r); Serial.print(", "); Serial.print(g); Serial.print(", "); Serial.println(b);
	neoPixel.setPixelColor(aktivPixel, r, g, b);  //Error  
}
void WS2812::show() 
{
	neoPixel.show();
}
//Show Color for pixel
void WS2812::showChangeSingle( uint8_t r , uint8_t g , uint8_t b, uint8_t pixelNr ) 
{ 
	if(pixelNr < pixels)
	{
		aktivPixel = pixelNr;
		sendPixelGRB( r , g , b );
		show();
	}
}
void WS2812::showChangeSingle(uint32_t pixel)
{
    uint8_t pixelNr = (uint8_t)pixel;
    uint8_t b = (uint8_t)(pixel>>=8);
    uint8_t g = (uint8_t)(pixel>>=8);
    uint8_t r = (uint8_t)(pixel>>=8);
	
	showChangeSingle(r, g, b, pixelNr);
}
//Show Color for all pixels
void WS2812::showColorLine( uint8_t r , uint8_t g , uint8_t b ) 
{ 
	for( aktivPixel = 0; aktivPixel < pixels; aktivPixel++)
	{
		sendPixelGRB(r, g, b);
	}
	show();
}
void WS2812::showColorLine(uint8_t *buffer)
{
	uint8_t r = *buffer;
	uint8_t g = *(buffer + 1);
	uint8_t b = *(buffer + 2);
	
	for( aktivPixel = 0; aktivPixel < pixels; aktivPixel++)
	{
		sendPixelGRB(r, g, b);
	}
	show();
}
//Show specific Color for each pixel
void WS2812::showSpecificColor(uint8_t *buffer)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	
	for( aktivPixel = 0; aktivPixel < pixels; aktivPixel++)
	{
		r = *buffer;
		buffer++;
		g = *buffer;
		buffer++;
		b = *buffer;
		buffer++;

		sendPixelGRB( r , g , b );
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
	neoPixel.updateLength(pixels);		//Error
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

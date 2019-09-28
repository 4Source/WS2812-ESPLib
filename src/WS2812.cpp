//----------------------------------------------------
// File:	WS2812.cpp
// Version:  	v0.1.9
// Change date:	28.09.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------
#include "WS2812.h"

static uint32_t _getCycleCount(void) __attribute__((always_inline));
static inline uint32_t _getCycleCount(void) {
  uint32_t ccount;
  __asm__ __volatile__("rsr %0,ccount":"=a" (ccount));
  return ccount;
}

//Set the specified pin as Digital Output 
WS2812::WS2812(uint8_t countPixel, uint8_t gpio_pin)
{
	#if defined (__AVR_ATtiny85__)
	if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
	#endif
	
	pixels = countPixel;
	pin = gpio_pin;
	aktivByte = 0;
	
	uint16_t bytes = pixels * 3;
	
	colorBuffer = (uint8_t*)calloc(bytes, sizeof(uint8_t));
	pinMode(pin, OUTPUT);
}
void WS2812::setPixelGRB( uint8_t r, uint8_t g , uint8_t b )  
{	
	colorBuffer[aktivByte] = g;
	colorBuffer[aktivByte + 1] = r;
	colorBuffer[aktivByte + 2] = b;
}
void WS2812::show() 
{
	noInterrupts();
	uint32_t time;
	uint32_t time_long = T1H;
	uint32_t time_short = T0H; 
	uint32_t time_ret = RES;
	uint32_t time_peri = PERI; 
	uint32_t cycle_start = 0; 
	uint32_t cycle_now = 0;
	uint8_t mask = 0x80;
	uint32_t index = 0;
	
	while(index < (pixels * 3))
	{
		while(mask > 0)
		{
			if((colorBuffer[index] & mask)== mask)
			{
				time = time_long;
			}
			else
			{
				time = time_short;
	
			}
			while(((cycle_now = _getCycleCount()) - cycle_start) < time_peri);
			PIN_OUT_SET(pin);
			cycle_start = cycle_now;
			while(((cycle_now = _getCycleCount()) - cycle_start) < time);
			PIN_OUT_CLEAR(pin);
			while(((cycle_now = _getCycleCount()) - cycle_start) < time_peri);
			
			mask >>= 1;
		}
		mask = 0x80;
		index++;
	}
	PIN_OUT_CLEAR(pin);
	cycle_start = cycle_now;
	while(((cycle_now = _getCycleCount()) - cycle_start) < time_ret);
	interrupts();
}
//Color for pixel
void WS2812::Single( uint8_t r , uint8_t g , uint8_t b, uint8_t pixelNr ) 
{ 
	if(pixelNr < pixels)
	{
		aktivByte = pixelNr * 3;
		setPixelGRB( r , g , b );
	}
}
void WS2812::Single(uint32_t pixel)
{
    uint8_t pixelNr = (uint8_t)pixel;
    uint8_t b = (uint8_t)(pixel>>=8);
    uint8_t g = (uint8_t)(pixel>>=8);
    uint8_t r = (uint8_t)(pixel>>=8);
	
	Single(r, g, b, pixelNr);
}
//Color for all pixels
void WS2812::ColorLine( uint8_t r , uint8_t g , uint8_t b ) 
{ 
	for(aktivByte = 0; aktivByte < pixels * 3; aktivByte += 3)
	{
		setPixelGRB(r, g, b);
	}
}
void WS2812::ColorLine(uint8_t *buffer)
{
	uint8_t r = *buffer;
	uint8_t g = *(buffer + 1);
	uint8_t b = *(buffer + 2);
	
	for(aktivByte = 0; aktivByte < pixels * 3; aktivByte += 3)
	{
		setPixelGRB(r, g, b);
	}
}
// specific Color for each pixel
void WS2812::SpecificColor(uint8_t *buffer)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	
	for(aktivByte = 0; aktivByte < pixels * 3; aktivByte += 3)
	{
		r = *buffer;
		buffer++;
		g = *buffer;
		buffer++;
		b = *buffer;
		buffer++;

		setPixelGRB( r , g , b );
	}
}

uint32_t WS2812::color(uint8_t r, uint8_t g, uint8_t b)
{
	return ((uint32_t)r << 16) + ((uint32_t)g <<  8) + b;
}
uint32_t WS2812::color(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
	return ((uint32_t)w << 24) + ((uint32_t)r << 16) + ((uint32_t)g <<  8) + b;
}
uint8_t WS2812::color_red(uint32_t color)
{
	return (uint8_t) color >> 16;
}
uint8_t WS2812::color_green(uint32_t color)
{
	return (uint8_t) color >> 8;
}
uint8_t WS2812::color_blue(uint32_t color)
{
	return (uint8_t) color;
}
uint8_t WS2812::color_white(uint32_t color)
{
	return (uint8_t) color >> 24;
}



uint8_t WS2812::countPixel()
{
	return pixels;
}
uint8_t WS2812::getPin()
{
	return pin;
}
void WS2812::setPin(uint8_t gpio_pin)
{
	pin = gpio_pin;
	pinMode(pin, OUTPUT);
}

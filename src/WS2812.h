//----------------------------------------------------
// File:	WS2812.h
// Version:  	v0.1.9
// Change date:	28.09.2019
// Autor:    	4Source
// Homepage: 	github.com/4Source
//----------------------------------------------------
//Inspired by the blog of Josh Levine (https://wp.josh.com/)
#ifndef WS2812_h
#define WS2812_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <arduino.h>
#endif

//GPIO
#define PIN_OUT(n) (WRITE_PERI_REG( 0x60000300, (n)))
#define PIN_OUT_SET(n) (WRITE_PERI_REG( 0x60000304, (1<<(n)) ))
#define PIN_OUT_CLEAR(n) (WRITE_PERI_REG( 0x60000308, (1<<(n)) ))

//WS2812 Timing
#define T0H	(F_CPU / 2500000)	//400 ns
#define T1H	(F_CPU / 1176470)	//850 ns
#define PERI (F_CPU / 800000) //1200 ns
#define RES (F_CPU / 20000)	//50000 ns

class WS2812
{
  private:
    uint16_t aktivByte;
    uint8_t pixels;
    uint8_t pin;
    uint8_t* colorBuffer;

    void setPixelGRB( uint8_t, uint8_t, uint8_t);


  public:
    WS2812(uint8_t, uint8_t);

    void show();

    void Single(uint8_t, uint8_t, uint8_t, uint8_t);
    void Single(uint32_t);

    void ColorLine(uint8_t, uint8_t, uint8_t);
    void ColorLine(uint8_t*);

    void SpecificColor(uint8_t*);

    static uint32_t color(uint8_t, uint8_t, uint8_t);
    static uint32_t color(uint8_t, uint8_t, uint8_t, uint8_t);
    static uint8_t color_red(uint32_t);
    static uint8_t color_green(uint32_t);
    static uint8_t color_blue(uint32_t);
    static uint8_t color_white(uint32_t);

    uint8_t countPixel();
    uint8_t getPin();
    void setPin(uint8_t);

};
#endif

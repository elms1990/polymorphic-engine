/*
 *  File: color.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "color.h"
#include <SDL2/SDL.h>

using Polymorphic::Color;

Color::Color(int r, int g, int b, int a) {
    Red = r;
    Green = g;
    Blue = b;
    Alpha = a;
}

Color::Color(int color) {
    SetColor(color);
}

Color::Color() {
    Red = 0;
    Green = 0;
    Blue = 0;
    Alpha = 0;
}

Color::~Color() {

}

void Color::SetColor(int color) {
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        Alpha = color&0xff000000;
        Red = color&0x00ff0000;
        Green = color&0x0000ff00;
        Blue = color&0x000000ff;
    #else
        Alpha = color&0x000000ff;
        Red = color&0x0000ff00;
        Green = color&0x00ff0000;
        Blue = color&0xff000000;
    #endif
}

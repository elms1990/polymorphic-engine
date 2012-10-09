/*
 *  File: color.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "color.h"

using namespace Polymorphic;

Color::Color(int r, int g, int b, int a) {
    Red = r;
    Green = g;
    Blue = b;
    Alpha = a;
}

Color::Color() {
    Red = 0;
    Green = 0;
    Blue = 0;
    Alpha = 0;
}

Color::~Color() {

}

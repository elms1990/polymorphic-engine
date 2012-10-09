/*
 *  File: math_helper.cpp
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "math_helper.h"
#include <math.h>

using namespace Polymorphic;

double MathHelper::Round(double r) {
    return (r > 0.0f) ? floor (r + 0.5) : ceil (r - 0.5);
}


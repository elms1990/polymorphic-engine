/*
 *  File: rectangle.h
 *  Last Updated: 27/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "rectanglef.h"

using namespace Polymorphic;

Rectanglef::Rectanglef() {
    X = 0;
    Y = 0;
    Width = 0;
    Height = 0;
}

Rectanglef::Rectanglef(float x, float y, int w, int h) {
    X = x;
    Y = y;
    Z = 0.f;
    Width = w;
    Height = h;
}

Rectanglef::Rectanglef(float x, float y, float z, int w, int h) {
    X = x;
    Y = y;
    Z = z;
    Width = w;
    Height = h;
}

Rectanglef::~Rectanglef() {

}

bool Rectanglef::InRange(int value, int min, int max)
{
    return (value >= min) && (value <= max);
}

bool Rectanglef::Intersects(Rectanglef r) {
    bool xOverlap = InRange(r.X, X, X + Width) ||
        InRange(X, r.X, r.X + r.Width);

    bool yOverlap = InRange(r.Y, Y, Y + Height) ||
        InRange(Y, r.Y, r.Y + r.Height);

    return xOverlap && yOverlap;
}

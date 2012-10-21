/*
 *  File: rectanglef.h
 *  Last Updated: 27/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __RECTANGLEF_H__
#define __RECTANGLEF_H__

namespace Polymorphic {

    class Rectanglef {
        public:
            Rectanglef();
            Rectanglef(float x, float y, int w, int h);
            Rectanglef(float x, float y, float z, int w, int h);
            ~Rectanglef();

            float X;
            float Y;
            float Z;
            int Width;
            int Height;

            bool Intersects(Rectanglef r);

        private:
            inline bool InRange(int value, int min, int max);
    };

}
#endif /* __RECTANGLE_H__ */

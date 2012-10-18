/*
 *  File: color.h
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __COLOR_H__
#define __COLOR_H__

namespace Polymorphic {

    class Color {
        public:
            Color();
            Color(int r, int g, int b,
                    int a);
            Color(int color);
            ~Color();

            void SetColor(int color);

            int Red;
            int Green;
            int Blue;
            int Alpha;
    };

}
#endif /* __COLOR_H__ */

/*
 *  File: color.h
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __COLOR_H__
#define __COLOR_H__

namespace Polymorphic {

    class Color {
        public:

            /* Default Constructor */
            Color();

            /* Constructor */
            Color(int r, int g, int b,
                    int a);

            /* Destructor */
            ~Color();

            int Red;
            int Green;
            int Blue;
            int Alpha;
    };

}
#endif /* __COLOR_H__ */

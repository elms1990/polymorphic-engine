/*
 *  File: hack.h
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __HACK_H__
#define __HACK_H__

#include <string>
using std::string;

namespace Polymorphic {

    /* this is a "hack" to allow stl map lexically compare the
     * virtual key string, so we can retrieve its value.
     */
    class _strhack {
        public:
            bool operator()(const string c1, const string c2) {
                return c1.compare(c2) <= 0;
            }
    };

}
#endif /* __HACK_H__ */

/*
 *  File: object_if.h
 *  Last Updated: 19/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __OBJECT_IF_H__
#define __OBJECT_IF_H__

namespace Polymorphic {

    class ObjectInterface {
        public:

            virtual float GetX() = 0;
            virtual float GetY() = 0;
            virtual float GetWidth() = 0;
            virtual float GetHeight() = 0;
            virtual int GetID() = 0;
            virtual void Update(int deltaTime) = 0;

    };

}
#endif /* __OBJECT_IF_H__ */

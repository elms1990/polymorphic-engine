/*
 *  File: actor_if.h
 *  Last Updated: 19/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __ACTOR_IF_H__
#define __ACTOR_IF_H__

#include "object_if.h"

namespace Polymorphic {

    class ActorInterface : public ObjectInterface {
        public:

            /* @name: Render
             * @descr: Method used to render objects
             * on the screen.
             * @params:
             *      @deltaTime: Time elapsed since last update.
             * @return: Nothing.
             */
            virtual void Render(int deltaTime) = 0;
    };

}
#endif /* __ACTOR_IF_H__ */

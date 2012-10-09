/*
 *  File: game_if.h
 *  Last Updated: 01/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __GAME_IF_H__
#define __GAME_IF_H__

namespace Polymorphic {

    class GameInterface {
        public:

            /* @name: Initialize
             * @descr: Initializes a game instance.
             * @params: None.
             * @return: Returns 0 if successfully set up.
             * Non-zero value, otherwise.
             */
            virtual int Initialize() = 0;

            /* @name: Update
             * @descr: Updates the game state.
             * @params: 
             *      @deltaTime: Time elapsed since last update.
             * @return: Nothing.
             */
            virtual void Update(int deltaTime) = 0;

            /* @name: Render
             * @descr: Renders objects on the screen.
             * @params:
             *      @deltaTime: Time elapsed since last update.
             * @return: Nothing.
             */
            virtual void Render(int deltaTime) = 0;

            /* @name: Shutdown
             * @descr: Shuts down this game instance,
             * calling clean up routines.
             * @params: None.
             * @return: Nothing.
             */
            virtual void Shutdown() = 0;

    };

}
#endif /* __GAME_IF_H__ */

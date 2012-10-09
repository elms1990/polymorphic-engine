/*
 *  File: input_state.h
 *  Last Updated: 16/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __INPUT_STATE_H__
#define __INPUT_STATE_H__

#include <SDL.h>
#include <list>
#include <string>
using std::list;
using std::string;

namespace Polymorphic {

    /* Stores input information of a frame */
    class InputState {
        public:
            list<string> GetJustPressedButtons() { return justPressed; }
            list<string> GetPressedButtons() { return pressed; }
            list<string> GetJustReleasedButtons() { return justReleased; }
            list<string> GetReleasedButtons() { return released; }

            bool IsButtonJustPressed(string virtual_name);
            bool IsButtonPressed(string virtual_name);
            bool IsButtonJustReleased(string virtual_name);
            bool IsButtonReleased(string virtual_name);
            bool IsButtonDown(string virtual_name);
            bool IsButtonUp(string virtual_name);

            //mouse pos
            int X, Y;

            InputState(list<string> justPressed, list<string> justReleased,
                    list<string> pressed, list<string> released);
            InputState();

        private:
            list<string> justPressed, justReleased, pressed, released;
    };

}

#endif /* __INPUT_STATE_H__ */

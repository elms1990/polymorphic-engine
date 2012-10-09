/*
 *  File: input_state.cpp
 *  Last Updated: 16/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "input_state.h"
#include "log.h"
#include <algorithm>
#include <list>
#include <map>

using namespace std;
using namespace Polymorphic;

/* InputState implementation */
InputState::InputState(list<string> justPressed, list<string> justReleased,
        list<string> pressed, list<string> released) {
        this->justPressed = justPressed;
        this->justReleased = justReleased;
        this->pressed = pressed;
        this->released = released;
}

InputState::InputState() {
}

bool InputState::IsButtonJustPressed(string virtual_name) {
    list<string>::iterator it = find(justPressed.begin(), justPressed.end(), virtual_name);

    return it != justPressed.end();
}

bool InputState::IsButtonPressed(string virtual_name) {
    list<string>::iterator it = find(pressed.begin(), pressed.end(), virtual_name);

    return it != pressed.end();
}

bool InputState::IsButtonJustReleased(string virtual_name) {
    list<string>::iterator it = find(justReleased.begin(), justReleased.end(), virtual_name);

    return it != justReleased.end();
}

bool InputState::IsButtonReleased(string virtual_name) {
    list<string>::iterator it = find(released.begin(), released.end(), virtual_name);

    return it != released.end();
}

bool InputState::IsButtonDown(string virtual_name) {
    return InputState::IsButtonJustPressed(virtual_name) || InputState::IsButtonPressed(virtual_name);
}

bool InputState::IsButtonUp(string virtual_name) {
    return InputState::IsButtonJustReleased(virtual_name) || InputState::IsButtonReleased(virtual_name);
}


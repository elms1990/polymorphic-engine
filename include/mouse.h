/*
 *  File: mouse.h
 *  Last Updated: 02/03/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "input_state.h"
#include "hack.h"
#include <string>
#include <map>

using std::string;
using std::map;

namespace Polymorphic {

    typedef enum _mousebutton {
        LeftButton, MiddleButton, RightButton, WheelUp, WheelDown
    } MouseButton;

    class Mouse {
        public:
            Mouse();
            ~Mouse();

            InputState* GetState();
            void Update();

            int Initialize();
            void Shutdown();

            void SaveMappingToFile(const char* file);
            bool LoadMappingFromFile(const char* file);

            void LoadDefaultButtonMapping();

            void MapButton(string virtual_name, MouseButton bt);
            void UnmapButton(string virtual_name);
            void RemapButton(string virtual_name, MouseButton new_bt);
            bool GetMapped(string virtual_name, MouseButton& mapped);

            int X, Y;

        private:
            const char *mapping_fpath;
            map<string, MouseButton, _strhack> mapping;
            InputState *newIS, *oldIS;

    };

}
#endif /* __MOUSE_H__ */

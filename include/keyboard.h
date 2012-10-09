/*
 *  File: keyboard.h
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "keys.h"
#include "input_state.h"
#include "hack.h"
#include <string>
#include <map>

using std::string;
using std::map;

namespace Polymorphic {

    class Keyboard {
        public:
            Keyboard();
            ~Keyboard();

            InputState* GetState();
            void Update();

            int Initialize();
            void Shutdown();

            void SaveMappingToFile(const char* file);
            bool LoadMappingFromFile(const char* file);

            void LoadDefaultKeyMapping();

            void MapKey(string virtual_name, Keys key);
            void UnmapKey(string virtual_name);
            void RemapKey(string virtual_name, Keys new_key);
            bool GetMapped(string virtual_name, Keys& mapped);

        private:
            const char *mapping_fpath;
            map<string, Keys, _strhack> mapping;
            InputState *newIS, *oldIS;
    };

}
#endif /* __KEYBOARD_H__ */

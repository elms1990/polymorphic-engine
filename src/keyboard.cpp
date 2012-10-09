/*
 *  File: keyboard.cpp
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "keyboard.h"

#include <fstream>
#include <iostream>
using namespace std;
using namespace Polymorphic;

Keyboard::Keyboard() {
    newIS = NULL;
    oldIS = NULL;
    mapping_fpath = "keyboard.txt";
}

Keyboard::~Keyboard() {

}

void Keyboard::Update() {

    if (oldIS != NULL) {
        delete oldIS;
        oldIS = NULL;
    } else {
        newIS = new InputState();
    }

    oldIS = newIS;

    Uint8 *keys = SDL_GetKeyState(NULL);
    list<string> _pressed, _justPressed, _released, _justReleased;

    /* Compares the new state with the old one */
    for (map<string, Keys, _strhack>::iterator it = mapping.begin();
        it != mapping.end(); it++) {

            /* Mapping the new state */
            if (keys[(*it).second]) {
                if (oldIS->IsButtonDown((*it).first)) {
                    /* Pressed */
                    _pressed.push_front((*it).first);
                } else {
                    /* justPressed */
                    _justPressed.push_front((*it).first);
                }
            } else {
                if (oldIS->IsButtonDown((*it).first)) {
                    /* justReleased */
                    _justReleased.push_front((*it).first);
                } else {
                    /* released */
                    _released.push_front((*it).first);
                }
            }
    }

    newIS = new InputState(_justPressed, _justReleased, _pressed, _released);

}

void Keyboard::LoadDefaultKeyMapping() {
    mapping["up"] = KEY_UP;
    mapping["down"] = KEY_DOWN;
    mapping["left"] = KEY_LEFT;
    mapping["right"] = KEY_RIGHT;
    mapping["action"] = KEY_Z;
}

bool Keyboard::GetMapped(string virtual_name, Keys& mapped) {
    map<string, Keys, _strhack>::iterator it;

    for (it = mapping.begin(); it != mapping.end(); it++) {
        if (it->first.compare(virtual_name) == 0) {
            mapped = it->second;
            return true;
        }
    }

    return false;
}

InputState* Keyboard::GetState() {
    if (newIS == NULL)
        Update();
    return newIS;
}

void Keyboard::Shutdown() {
    if (newIS != NULL) {
        delete newIS;
    }

    if (oldIS != NULL) {
        delete oldIS;
    }
}

void Keyboard::MapKey(string virtual_name, Keys key) {
    mapping[virtual_name] = key;
}

void Keyboard::UnmapKey(string virtual_name) {
    for (map<string, Keys, _strhack>::iterator it = mapping.begin();
        it != mapping.end(); it++) {
            if ((*it).first.compare(virtual_name) == 0) {
                mapping.erase(it);
                return;
            }
    }
}

void Keyboard::RemapKey(string virtual_name, Keys new_key) {
    UnmapKey(virtual_name);
    MapKey(virtual_name, new_key);
}

int Keyboard::Initialize() {
    LoadMappingFromFile(mapping_fpath);
//    if (!LoadMappingFromFile(mapping_fpath)) {
//        LoadDefaultKeyMapping();
//        SaveMappingToFile(mapping_fpath);
//    }

    return 0;
}

bool Keyboard::LoadMappingFromFile(const char* file) {
    ifstream f(file);

    if (f.is_open()) {
        int k;
        string v_name;
        char c;

        while (!f.eof()) {
            while ((c = f.get()) != '=')
            v_name = v_name + c;
            f >> k;
            mapping[v_name] = (Keys)k;
            v_name.clear();
            f.get();
        }

        return true;
    }

    return false;
}

void Keyboard::SaveMappingToFile(const char* file) {
    ofstream f(file);

    if (f.is_open()) {
        for (map<string, Keys, _strhack>::iterator it = mapping.begin();
            it != mapping.end(); it++) {
                f << it->first << "=" << it->second;
                if (++it != mapping.end())
                    f << endl;
                --it;
        }
        f.close();
    }
}

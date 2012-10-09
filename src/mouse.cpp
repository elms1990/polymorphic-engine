/*
 *  File: mouse.cpp
 *  Last Updated: 02/03/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "mouse.h"
#include <iostream>
#include <fstream>
#include <SDL.h>

using namespace std;
using namespace Polymorphic;

Mouse::Mouse() {
    mapping_fpath = "mouse.txt";
    newIS = NULL;
    oldIS = NULL;
    X = 0;
    Y = 0;
}

Mouse::~Mouse() {

}

InputState* Mouse::GetState() {
    if (newIS == NULL)
        Update();
    return newIS;
}

void Mouse::Update() {

    if (oldIS != NULL) {
        delete oldIS;
        oldIS = NULL;
    } else {
        newIS = new InputState();
    }

    oldIS = newIS;

    Uint8 mstate = SDL_GetMouseState(&X, &Y);

    list<string> _pressed, _justp, _released, _jreleased;

    /* Compares the new state with the old one */
    for (map<string, MouseButton, _strhack>::iterator it = mapping.begin();
        it != mapping.end(); it++) {

            if (mstate & it->second) {
                if (oldIS->IsButtonDown(it->first)) {
                    // pressed
                    _pressed.push_front(it->first);
                } else {
                    //just pressed
                    _justp.push_front(it->first);
                }
            } else {
                if (oldIS->IsButtonDown(it->first)) {
                    //just released
                    _jreleased.push_front(it->first);
                } else {
                    //released
                    _released.push_front(it->first);
                }
            }
    }

    newIS = new InputState(_justp, _jreleased, _pressed, _released);
    newIS->X = X;
    newIS->Y = Y;
}

int Mouse::Initialize() {
    LoadMappingFromFile(mapping_fpath);
//    if (!LoadMappingFromFile(mapping_fpath)) {
//        LoadDefaultButtonMapping();
//        SaveMappingToFile(mapping_fpath);
//    }

    return 0;
}

void Mouse::Shutdown() {
    if (newIS != NULL) {
        delete newIS;
    }

    if (oldIS != NULL) {
        delete oldIS;
    }
}

void Mouse::LoadDefaultButtonMapping() {
    mapping["action2"] = LeftButton;
    mapping["action3"] = RightButton;
}

void Mouse::SaveMappingToFile(const char* file) {
    ofstream off(file);

    if (off.is_open()) {
        for (map<string, MouseButton, _strhack>::iterator it = mapping.begin();
            it != mapping.end(); it++) {
                off << it->first << "=" << (int)it->second;
                if (++it != mapping.end())
                    off << endl;
                --it;
        }

        off.close();
    }
}

bool Mouse::LoadMappingFromFile(const char* file) {
    ifstream f(file);

    if (f.is_open()) {
        int k;
        string v_name;
        char c;

        while (!f.eof()) {
            while ((c = f.get()) != '=')
            v_name = v_name + c;
            f >> k;
            mapping[v_name] = (MouseButton)k;
            v_name.clear();
            f.get();
        }

        return true;
    }

    return false;
}

void Mouse::MapButton(string virtual_name, MouseButton bt) {
    mapping[virtual_name] = bt;
}

void Mouse::UnmapButton(string virtual_name) {
    for (map<string, MouseButton, _strhack>::iterator it = mapping.begin();
        it != mapping.end(); it++) {
            if ((*it).first.compare(virtual_name) == 0) {
                mapping.erase(it);
                return;
            }
    }
}

void Mouse::RemapButton(string virtual_name, MouseButton new_bt) {
    UnmapButton(virtual_name);
    MapButton(virtual_name, new_bt);
}

bool Mouse::GetMapped(string virtual_name, MouseButton& mapped) {
    map<string, MouseButton, _strhack>::iterator it;

    for (it = mapping.begin(); it != mapping.end(); it++) {
        if (it->first.compare(virtual_name) == 0) {
            mapped = it->second;
            return true;
        }
    }

    return false;
}


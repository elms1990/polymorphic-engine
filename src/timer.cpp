/*
 *  File: timer.cpp
 *  Last Updated: 14/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "timer.h"
#include <SDL2/SDL.h>

using namespace Polymorphic;

Timer::Timer() {
    started = false;
    paused = false;
    startTicks = 0;
    pauseTicks = 0;
}

void Timer::Start() {
    paused = false;
    started = true;
    startTicks = SDL_GetTicks();
}

void Timer::Pause() {
    if (started == true && paused == false) {
        paused = true;
        pauseTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::Stop() {
    paused = false;
    started = false;
}

void Timer::Unpause() {
    if (paused == true) {
        paused = false;
        startTicks = SDL_GetTicks() - pauseTicks;
        pauseTicks = 0;
    }
}

unsigned int Timer::GetTicks() {
    if (started == true) {
        if (paused == true) {
            return pauseTicks;
        } else {
            return SDL_GetTicks() - startTicks;
        }
    }

    return 0;
}


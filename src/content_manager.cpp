/*
 *  File: content.cpp
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "content_manager.h"
#include "engine.h"
#include <algorithm>
#include <cmath>

using namespace Polymorphic;

Music* ContentManager::LoadMusic(const char* name, const char* path) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (Music*)exist;

    Mix_Music* music = Mix_LoadMUS(path);

    if (music != NULL) {
        Music* r = (new Music(music, name));
        resources[name] = (Resource*)r;
        return r;
    } else {
        Engine::log.LogMessage("Error", "Could not find file: " + (string)path);
        return NULL;
    }
}

SoundEffect* ContentManager::LoadSoundEffect(const char* name, const char* path) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (SoundEffect*)exist;

    Mix_Chunk* snd = Mix_LoadWAV(path);

    if (snd != NULL) {
        SoundEffect* r = (new SoundEffect(snd, name));
        resources[name] = (Resource*)r;
        return r;
    } else {
        Engine::log.LogMessage("Error", "Could not find file: " + (string)path);
        return NULL;
    }
}

Texture* ContentManager::LoadImage(const char* name, const char* path) {
    Resource* exist = GetResource(name);

    if (exist != NULL)
        return (Texture*)exist;

    SDL_Surface* text = IMG_Load(path);

    if (text != NULL) {
        SDL_Surface* tt = SDL_DisplayFormatAlpha(text);
        SDL_FreeSurface(text);

        Texture* r = (new Texture(tt, name));
        resources[name] = (Resource*)r;
        return r;
    } else {
        Engine::log.LogMessage("Error", "Could not find file: " + (string)path);
        return NULL;
    }
}

Font* ContentManager::LoadFont(const char *name, const char *path) {
    return LoadFont(name, path, 128);
}

Font* ContentManager::LoadFont(const char* name, const char* path, int font_size) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (Font*)exist;

    TTF_Font* ft = TTF_OpenFont(path, font_size);

    if (ft == NULL) {
        Engine::log.LogMessage("Error", "Could not find file: " + (string)path);
        return NULL;
    }

    Font* r = (new Font(ft, name, font_size));
    resources[name] = (Resource*)r;
    return r;
}

Resource* ContentManager::GetResource(const char* name) {
    map<string, Resource*, _strhack>::iterator it;

    for (it = resources.begin(); it != resources.end(); it++) {
        if (it->first.compare(name) == 0) {
            return it->second;
        }
    }

    return NULL;
}

void ContentManager::Initialize() {
    channel = 0;
    DeallocateOnShutdown = true;
}

void ContentManager::UnloadResource(const char* name) {
    for (map<string, Resource*, _strhack>::iterator it = resources.begin();
        it != resources.end(); it++) {
            if (it->first.compare(name) == 0) {
                delete it->second;
                resources.erase(it);
                return;
            }
    }
}

void ContentManager::Shutdown() {
    if (DeallocateOnShutdown) {
        for (map<string, Resource*, _strhack>::iterator it = resources.begin();
            it != resources.end(); it++) {
                if (it->second != NULL) {
                    delete it->second;
                }
        }

        resources.clear();
    }
}

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

void ContentManager::AddResource(Resource *r, string name) {
    resources[name] = r;
}

Music* ContentManager::LoadMusic(string name, string path) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (Music*)exist;

    Mix_Music* music = Mix_LoadMUS(path.c_str());

    if (music != NULL) {
        Music* r = (new Music(music, name));
        resources[name] = (Resource*)r;
        return r;
    } else {
        Engine::log.LogMessage("Error", "Could not find file: " + path);
        return NULL;
    }
}

SoundEffect* ContentManager::LoadSoundEffect(string name, string path) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (SoundEffect*)exist;

    Mix_Chunk* snd = Mix_LoadWAV(path.c_str());

    if (snd != NULL) {
        SoundEffect* r = (new SoundEffect(snd, name));
        resources[name] = (Resource*)r;
        return r;
    } else {
        Engine::log.LogMessage("Error", "Could not find file: " + path);
        return NULL;
    }
}

Image* ContentManager::LoadImage(string name, string path) {
    Resource* exist = GetResource(name);

    if (exist != NULL)
        return (Image*)exist;

    Image *r = Image::LoadImage(path.c_str());
    if (r == NULL) {
        Engine::log.LogMessage("Error", "Could not find file: " + (string)path);
        return NULL;
    }
    resources[name] = (Resource*)r;

    return r;
}

Font* ContentManager::LoadFont(string name, string path) {
    return LoadFont(name, path, 40);
}

Font* ContentManager::LoadFont(string name, string path, int font_size) {
    Resource* exist = GetResource(name);
    if (exist != NULL)
        return (Font*)exist;

    TTF_Font* ft = TTF_OpenFont(path.c_str(), font_size);

    if (ft == NULL) {
        Engine::log.LogMessage("Error", "Could not find file: " + path);
        return NULL;
    }

    Font* r = (new Font(ft, name, font_size));
    resources[name] = (Resource*)r;
    return r;
}

Resource* ContentManager::GetResource(string name) {
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

void ContentManager::UnloadResource(string name) {
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

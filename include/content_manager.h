/*
 *  File: content_manager.h
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __CONTENT_MANAGER_H__
#define __CONTENT_MANAGER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>
#include "hack.h"
#include "resource.h"

using std::map;
using std::string;

namespace Polymorphic {

#define DEFAULT_MIX_NUMCHAN 64

    class ContentManager {
        private:
            map<string, Resource*, _strhack> resources;
            int channel;

        public:
            bool DeallocateOnShutdown;

            void Initialize();
            void Shutdown();

            Image* LoadImage(string name, string path);
            Font* LoadFont(string name, string path, int font_size);
            Font* LoadFont(string name, string path);
            SoundEffect* LoadSoundEffect(string name, string path);
            Music* LoadMusic(string name, string path);

            void UnloadResource(string name);
            void AddResource(Resource *r, string name);
            Resource* GetResource(string name);
    };

}
#endif /* __CONTENT_MANAGER_H__ */

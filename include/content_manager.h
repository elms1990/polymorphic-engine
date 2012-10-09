/*
 *  File: content_manager.h
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __CONTENT_MANAGER_H__
#define __CONTENT_MANAGER_H__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_opengl.h>
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
            GLuint SurfaceToTexture(SDL_Surface* s);

        public:
            bool DeallocateOnShutdown;

            void Initialize();
            void Shutdown();

            Resource* LoadImage(const char* name, const char* path);
            Resource* LoadFont(const char* name, const char* path, int font_size);
            Resource* LoadSoundEffect(const char* name, const char* path);
            Resource* LoadMusic(const char* name, const char* path);

            void UnloadResource(const char* name);
            Resource* GetResource(const char* name);
    };

}
#endif /* __CONTENT_MANAGER_H__ */

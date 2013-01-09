/*
 *  File: resource.h
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_opengl.h>

namespace Polymorphic {

    class Resource {
        public:
            Resource(void* res, const char* name);
            virtual ~Resource() = 0;

            void* GetResource() { return res; }
            const char* GetName() { return name; }

        protected:
            void* res;
            const char* name;

    };

    class Texture : public Resource {
        public:
            Texture(SDL_Surface* sfc, const char* name);
            ~Texture();

            int Width;
            int Height;

            GLuint GetID();

        private:
            GLuint tid;

            void SurfaceToTexture();
    };

    class Font : public Resource {
        public:
            Font(TTF_Font* ft, const char* name, int size);
            Font(TTF_Font* ft, const char* name);
            ~Font();

            int GetFontSize();

        private:
            int font_size;
    };

    class Music : public Resource {
        public:
            Music(Mix_Music* music, const char* name);
            ~Music();

            bool Loop;

            // 0: Muted 1: Max Volume
            void SetVolume(float volume);

            int GetVolume();

            void Play();
            void Pause();
            void Resume();
            void Stop();

        private:
            bool playing, paused, halted;
    };

    class SoundEffect : public Resource {
        public:
            SoundEffect(Mix_Chunk* snd, const char* name);
            ~SoundEffect();

            bool Loop;

            // 0: Muted 1: Max Volume
            void SetVolume(float volume);

            int GetVolume();

            void Play();
            void Play(int milisecs);
            void Pause();
            void Resume();
            void Stop();

        private:
            bool playing, paused, halted;
            int channel;
    };

}
#endif /* __RESOURCE_H__ */

/*
 *  File: resource.h
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>

using std::string;

namespace Polymorphic {

    class Resource {
        public:
            Resource();
            Resource(void *res, string name);
            virtual ~Resource() = 0;

            void* GetResource();
            void SetResource(void *res);
            string GetName();
            void SetName(string name);

        protected:
            void *res;
            string name;
    };
    
    class Image : public Resource {
        public:
            Image();
            ~Image();

            static Image* LoadImage(string path);

            int GetWidth();
            int GetHeight();

        private:
            Image* InternalLoadImage(string path);
    };

    class Texture : public Resource {
        public:
            Texture();
            ~Texture();

            static Texture* CreateTextureFromImage(Image *img);

            int GetWidth();
            int GetHeight();
    };

    class Font : public Resource {
        public:
            Font(TTF_Font *ft, string name, int size);
            Font(TTF_Font *ft, string name);
            ~Font();

            int GetFontSize();

        private:
            int font_size;
    };

    class Music : public Resource {
        public:
            Music(Mix_Music *music, string name);
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
            SoundEffect(Mix_Chunk *snd, string name);
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

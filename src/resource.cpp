/*
 *  File: resource.cpp
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */
#include "resource.h"
#include "log.h"

using namespace Polymorphic;

/* Resource implementation */
Resource::Resource(void* res, const char* name) {
    this->res = res;
    this->name = name;
}

Resource::~Resource() {

}

/* Texture implementation */
Texture::Texture(SDL_Surface* sfc, const char* name) :
    Resource((void*)sfc, name) {
    Width = sfc->w;
    Height = sfc->h;
    SurfaceToTexture();
}

Texture::~Texture() {
    if (res != NULL) {
        SDL_FreeSurface((SDL_Surface*)res);
        glDeleteTextures(1, &tid);
    }
}

void Texture::SurfaceToTexture() {
    GLuint tid;;
    GLenum texture_format;
    GLint ncolors;
    SDL_Surface* s = (SDL_Surface*)res;

    /* Convert SDL_Surface to OpenGL Texture */
    ncolors = s->format->BytesPerPixel;
    if (ncolors == 4) {
        //alpha channel
        if (s->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    } else {
        if (ncolors == 3) {
            //no alpha channel
            if (s->format->Rmask == 0x000000ff)
                texture_format = GL_RGB;
            else
                texture_format = GL_BGR;
        } else {
            return;
        }
    }

    glGenTextures(1, &tid);
    glBindTexture(GL_TEXTURE_2D, tid);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, ncolors, s->w, s->h, 0,
                texture_format, GL_UNSIGNED_BYTE, s->pixels);

    this->tid = tid;
}

GLuint Texture::GetID() {
    return tid;
}

/* Font implementation */
Font::Font(TTF_Font* ft, const char* name, int size) : Resource((void*)ft, name) {
    font_size = size;
}

Font::~Font() {
    if (res != NULL) {
        TTF_CloseFont((TTF_Font*)res);
        res = NULL;
    }
}

int Font::GetFontSize() {
    return font_size;
}

/* SoundEffect implementation */
SoundEffect::SoundEffect(Mix_Chunk* snd, const char* name) : Resource((void*)snd, name) {
    SetVolume(0.5f);
    playing = false;
    halted = false;
    paused = false;
    channel = -2;
    Loop = false;
}

SoundEffect::~SoundEffect() {
    if (res != NULL) {
        Mix_FreeChunk((Mix_Chunk*)res);
    }
}

void SoundEffect::SetVolume(float volume) {
    Mix_VolumeChunk((Mix_Chunk*)res, 128*volume);
}

int SoundEffect::GetVolume() {
    return Mix_VolumeChunk((Mix_Chunk*)res, -1);
}

void SoundEffect::Play(int milisecs) {
    Mix_PlayChannelTimed(channel, (Mix_Chunk*)res, 0, milisecs);
    playing = true;
    paused = false;
    halted = false;
}

void SoundEffect::Play() {
    if (!Loop)
        channel = Mix_PlayChannel(-1, (Mix_Chunk*)res, 0);
    else
        channel = Mix_PlayChannel(-1, (Mix_Chunk*)res, -1);
    playing = true;
    paused = false;
    halted = false;
}

void SoundEffect::Pause() {
    if (playing && channel != -2) {
        Mix_Pause(channel);
        playing = false;
        paused = true;
    }
}

void SoundEffect::Resume() {
    if (paused && channel != -2) {
        Mix_Resume(channel);
        playing = true;
        paused = false;
    }
}

void SoundEffect::Stop() {
    if ((playing || paused) && channel != -2) {
        Mix_HaltChannel(channel);
        playing = false;
        paused = false;
        halted = true;
    }
}

/* Music implementation */
Music::Music(Mix_Music* music, const char* name) : Resource((void*)music, name) {
    SetVolume(0.5f);
    playing = false;
    halted = false;
    paused = false;
    Loop = false;
}

Music::~Music() {
    if (res != NULL) {
        Mix_FreeMusic((Mix_Music*)res);
    }
}

void Music::SetVolume(float volume) {
    Mix_VolumeMusic(128*volume);
}

int Music::GetVolume() {
    return Mix_VolumeMusic(-1);
}

void Music::Play() {
    if (!Loop)
        Mix_PlayMusic((Mix_Music*)res, 0);
    else
        Mix_PlayMusic((Mix_Music*)res, -1);
    playing = true;
    paused = false;
    halted = false;
}

void Music::Pause() {
    if (playing) {
        Mix_PauseMusic();
        playing = false;
        paused = true;
    }
}

void Music::Resume() {
    if (paused) {
        Mix_ResumeMusic();
        playing = true;
        paused = false;
    }
}

void Music::Stop() {
    if (playing || paused) {
        Mix_HaltMusic();
        playing = false;
        paused = false;
        halted = true;
    }
}

/*
 *  File: resource.cpp
 *  Last Updated: 25/02/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */
#include "resource.h"
#include "log.h"
#include "engine.h"

using namespace Polymorphic;

/* Resource implementation */
Resource::Resource() {
    res = NULL;
    name = "";
}

Resource::Resource(void *res, string name) {
    this->res = res;
    this->name = name;
}

Resource::~Resource() {

}

void* Resource::GetResource() {
    return res;
}

void Resource::SetResource(void *res) {
    this->res = res;
}

string Resource::GetName() {
    return name;
}

void Resource::SetName(string name) {
    this->name = name;
}

/* Texture implementation */
Texture::Texture() : Resource() {
}

Texture::~Texture() {
    if (res != NULL) {
        SDL_DestroyTexture((SDL_Texture*)res);
    }
}

int Texture::GetWidth() {
    int w, h, access;
    Uint32 format;

    SDL_QueryTexture((SDL_Texture*)res, &format, &access, &w, &h);

    return w;
}

int Texture::GetHeight() {
    int w, h, access;
    Uint32 format;

    SDL_QueryTexture((SDL_Texture*)res, &format, &access, &w, &h);

    return h;
}

Texture* Texture::CreateTextureFromImage(Image *img) {
    Texture *txt = new Texture();
    txt->SetResource(SDL_CreateTextureFromSurface(Engine::graphics.renderer,
                (SDL_Surface*)img->GetResource()));
    txt->SetName(img->GetName());

    return txt;
}

Image::Image() : Resource() {
}

Image::~Image() {
    if (res != NULL) {
        SDL_FreeSurface((SDL_Surface*)res);
    }
}

Image* Image::LoadImage(string path) {
    return (new Image())->InternalLoadImage(path);
}

Image* Image::InternalLoadImage(string path) {
    SDL_Surface* text = IMG_Load(path.c_str());

    if (text != NULL) {
        res = (void*)text;
        return this;
    }

    return NULL;
}

int Image::GetWidth() {
    return ((SDL_Surface*)res)->w;
}

int Image::GetHeight() {
    return ((SDL_Surface*)res)->h;
}

/* Font implementation */
Font::Font(TTF_Font* ft, string name, int size) : Resource((void*)ft, name) {
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
SoundEffect::SoundEffect(Mix_Chunk* snd, string name) : Resource((void*)snd, name) {
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
Music::Music(Mix_Music* music, string name) : Resource((void*)music, name) {
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

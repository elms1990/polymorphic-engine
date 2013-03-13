/*
 *  File: graphics.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "graphics.h"
#include "engine.h"
#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>

using std::string;
using namespace Polymorphic;

#define DEFAULT_WINDOW_FLAGS (SDL_WINDOW_SHOWN)
#define DEFAULT_RENDERER_FLAGS (SDL_RENDERER_ACCELERATED)
#define DEFAULT_VIEWPORT_WIDTH 600
#define DEFAULT_VIEWPORT_HEIGHT 600
#define DEFAULT_FSCREEN_MODE false

Graphics::Graphics() {
    window = NULL;
    renderer = NULL;
    sw = 0.f;
    sh = 0.f;
    width = 0;
    height = 0;
    fs = DEFAULT_FSCREEN_MODE;
    vw = DEFAULT_VIEWPORT_WIDTH;
    vh = DEFAULT_VIEWPORT_HEIGHT;
}

Graphics::~Graphics() {

}

int Graphics::Initialize() {
    if (CreateContext(vw, vh) == -1)
        return -1;
    SetWindowFullscreen(fs);

    Engine::log.LogMessage("Success", "Graphics engine successfully started.");

    return 0;
}

void Graphics::SetWindowTitle(string title) {
    SDL_SetWindowTitle(window, title.c_str());
}

void Graphics::SetWindowSize(int w, int h) {
    width = w;
    height = h;
    SDL_SetWindowSize(window, w, h);
    sw = (float)w/vw;
    sh = (float)h/vh;
}

void Graphics::SetWindowIcon(Image *img) {
    SDL_SetWindowIcon(window, (SDL_Surface*)img->GetResource());
}

int Graphics::SetWindowFullscreen(bool fs) {
    if ((!this->fs && fs)) {
        this->fs = fs;
        return SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    } else {
        if (this->fs && !fs) {
            this->fs = fs;
            return SDL_SetWindowFullscreen(window, 0x0);
        }
    }

    return 0;
}

void Graphics::Draw(Texture *src, Rectanglef src_rect, Rectanglef dst_rect) {
    SDL_Rect sr = { sr.x = src_rect.X, sr.y = src_rect.Y,sr.w = src_rect.Width,
        sr.h = src_rect.Height };
    SDL_Rect dr = { dr.x = dst_rect.X*sw, dr.y = dst_rect.Y*sh,dr.w = dst_rect.Width*sw,
        dr.h = dst_rect.Height*sh };

    SDL_RenderCopy(renderer, (SDL_Texture*)src->GetResource(), &sr, &dr);
}

void Graphics::Draw(Texture *src, Rectanglef src_rect, float dest_x, float dest_y) {
    Draw(src, src_rect, Rectanglef(dest_x, dest_y, src->GetWidth(), src->GetHeight()));
}

void Graphics::Draw(Texture *src, float dest_x, float dest_y) {
    Draw(src, Rectanglef(0.f, 0.f, src->GetWidth(), src->GetHeight()), 
            Rectanglef(dest_x, dest_y, src->GetWidth(), src->GetHeight()));
}

void Graphics::Flush() {
    SDL_RenderPresent(renderer);
}

void Graphics::DrawText(TextBuffer* t, float x, float y) {
    Draw(t->GetBuffer(), Rectanglef(0, 0, t->GetBuffer()->GetWidth(), 
                t->GetBuffer()->GetHeight()), Rectanglef(x, y, 
                t->GetBuffer()->GetWidth()*t->GetScaleFactor(), 
                t->GetBuffer()->GetHeight()*t->GetScaleFactor()));
}

void Graphics::Clear() {
    SDL_RenderClear(renderer);
}

void Graphics::SetRenderColor(Color c) {
    SDL_SetRenderDrawColor(renderer, c.Red, c.Green, c.Blue, c.Alpha);
}

void Graphics::Shutdown() {
    if (renderer != NULL)
        SDL_DestroyRenderer(renderer);
    if (window != NULL)
        SDL_DestroyWindow(window);
}

int Graphics::GetWidth() {
    return width;
}

int Graphics::GetHeight() {
    return height;
}

int Graphics::CreateContext(int w, int h) {
    window = SDL_CreateWindow("",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            w, 
            h, 
            DEFAULT_WINDOW_FLAGS);
    renderer = SDL_CreateRenderer(window, -1, DEFAULT_RENDERER_FLAGS);

    if ((window == NULL) | (renderer == NULL)) {
        Engine::log.LogMessage("Error", "Failed to set up a Window...");
        return -1;
    }
    int a,b;
    SDL_GetWindowSize(window, &a, &b);
    width = w;
    height = h;
    sw = GetViewportWidth()/w;
    sh = GetViewportHeight()/h;

    return 0;
}

int Graphics::GetViewportWidth() {
    return vw;
}

int Graphics::GetViewportHeight() {
    return vh;
}

void Graphics::SetViewportSize(int w, int h) {
    vw = w;
    vh = h;
}

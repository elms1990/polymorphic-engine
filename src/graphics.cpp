/*
 *  File: graphics.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "graphics.h"
#include "engine.h"
#include <SDL2/SDL.h>
#include <string>

using std::string;
using namespace Polymorphic;

#define DEFAULT_WINDOW_FLAGS (SDL_WINDOW_SHOWN)
#define DEFAULT_RENDERER_FLAGS (SDL_RENDERER_ACCELERATED)

Graphics::Graphics() {
    window = NULL;
    renderer = NULL;
    sw = 0.f;
    sh = 0.f;
    width = 0;
    height = 0;
}

Graphics::~Graphics() {

}

int Graphics::Initialize() {
    EngineAttributes eat = Engine::GetAttributes();
    if (CreateContext(eat.width, eat.height, eat.fullscreen) == -1)
        return -1;

    Engine::log.LogMessage("Success", "Graphics engine successfully started.");

    return 0;
}

void Graphics::SetWindowTitle(string title) {
    SDL_SetWindowTitle(window, title.c_str());
}

bool Graphics::ResizeWindow(int new_w, int new_h, bool full_screen) {

    if (CreateContext(new_w, new_h, full_screen) == -1)
        return false;
    return true;
}

void Graphics::Draw(Texture *src, Rectanglef src_rect, Rectanglef dst_rect) {
    SDL_Rect sr = { sr.x = src_rect.X, sr.y = src_rect.Y,sr.w = src_rect.Width,
        sr.h = src_rect.Height };
    SDL_Rect dr = { dr.x = dst_rect.X, dr.y = dst_rect.Y,dr.w = dst_rect.Width,
        dr.h = dst_rect.Height };

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
    SDL_SetRenderDrawColor(renderer, c.Red, c.Blue, c.Green, c.Alpha);
}

void Graphics::Shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int Graphics::GetWidth() {
    return width;
}

int Graphics::GetHeight() {
    return height;
}

int Graphics::CreateContext(int w, int h, bool fscreen) {
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
    SDL_GetWindowSize(window, &width, &height);

    return 0;
}

/*
 *  File: graphics.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "graphics.h"
#include "engine.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <algorithm>

using std::sort;
using namespace Polymorphic;

#define DEFAULT_WINDOW_FLAGS (SDL_HWSURFACE | SDL_OPENGL)

Graphics::Graphics() {
    scr = NULL;
    width = 0;
    height = 0;
}

Graphics::~Graphics() {

}

int Graphics::Initialize() {
    EngineAttributes eat = Engine::GetAttributes();
    SDL_putenv((char*)"SDL_VIDEO_CENTERED=1");
    if (CreateContext(eat.width, eat.height, eat.fullscreen) == -1)
        return -1;

    Engine::log.LogMessage("Success", "Graphics engine successfully started.");

    return 0;
}

void Graphics::SetWindowTitle(const char* title) {
    SDL_WM_SetCaption(title, title);
}

bool Graphics::ResizeWindow(int new_w, int new_h, bool full_screen) {

    if (CreateContext(new_w, new_h, full_screen) == -1)
        return false;
    return true;
}

void Graphics::DrawBatch() {
    int i;
    //draw
   
    glScalef(sw, sh, 1.f);
    for (i = 1; i < MAX_LAYERS; i++) {
        for (list<DrawableUnit>::iterator it = batch[i].begin(); it != batch[i].end();
                it++) {
            glBindTexture(GL_TEXTURE_2D, it->t->GetID());

            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
            glBegin(GL_QUADS);

            //bottom-left
            glTexCoord2f(it->src.X/it->t->Width, (it->src.Y)/it->t->Height);
            glVertex2f(it->dst.X, it->dst.Y);

            //bottom-right
            glTexCoord2f((it->src.X+it->src.Width)/it->t->Width,
                    it->src.Y/it->t->Height);
            glVertex2f(it->dst.X + it->dst.Width, it->dst.Y);

            //top-right
            glTexCoord2f((it->src.X+it->src.Width)/it->t->Width, 
                    (it->src.Y+it->src.Height)/it->t->Height);
            glVertex2f((it->dst.X + it->dst.Width), (it->dst.Y + it->dst.Height));

            //top-left
            glTexCoord2f(it->src.X/it->t->Width, 
                    (it->src.Y+it->src.Height)/it->t->Height);
            glVertex2f(it->dst.X, (it->dst.Y + it->dst.Height));
            glEnd();
        }
        batch[i].clear();
    }
    batch[0].clear();
    glLoadIdentity();
}

void Graphics::Draw(Texture* src, Rectanglef src_rect, Rectanglef dst_rect) {
    if (src != NULL) {
        DrawableUnit du = { du.t = src, du.src = src_rect, du.dst = dst_rect };
        batch[(int)(dst_rect.Z)+1].push_back(du);
    }
}

void Graphics::Draw(Texture* src, Rectanglef src_rect, float dest_x, float dest_y) {
    if (src != NULL)
        Draw(src, src_rect, Rectanglef(dest_x, dest_y, src_rect.Z, 0, 0));
}

void Graphics::Draw(Texture* src, float dest_x, float dest_y) {
    if (src != NULL)
        Draw(src, Rectanglef(0.f, 0.f, src->Width, src->Height), Rectanglef(dest_x, dest_y, src->Width, src->Height));
}

void Graphics::Draw(Texture* src, float dest_x, float dest_y, int layer) {
    if (src != NULL) {
        Draw(src, Rectanglef(0.f, 0.f, 0.f, src->Width, src->Height), 
                Rectanglef(dest_x, dest_y, (float)layer, src->Width, src->Height));
    }
}

void Graphics::Flush() {
    SDL_GL_SwapBuffers();
}

void Graphics::DrawText(TextBuffer* t, float x, float y) {
    Draw(t->GetBuffer(), Rectanglef(0, 0, t->GetBuffer()->Width, 
                t->GetBuffer()->Height), Rectanglef(x, y, 
                t->GetBuffer()->Width*t->GetScaleFactor(), 
                t->GetBuffer()->Height*t->GetScaleFactor()));
}

void Graphics::DrawText(TextBuffer* t, float x, float y, int layer) {
    Draw(t->GetBuffer(), Rectanglef(0, 0, t->GetBuffer()->Width, 
                t->GetBuffer()->Height), Rectanglef(x, y, (float)layer,
                t->GetBuffer()->Width*t->GetScaleFactor(), 
                t->GetBuffer()->Height*t->GetScaleFactor()));
}

void Graphics::Clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::SetClearColor(Color c) {
    glClearColor(c.Red, c.Green, c.Blue, c.Alpha);
}

int Graphics::CreateContext(int w, int h, bool fscreen) {
    SDL_Surface* screen = NULL;
    c = Color(0.f, 0.f, 0.f, 1.f);

    /* Initializes OpenGL Context */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    screen = SDL_SetVideoMode(w, h, 32, DEFAULT_WINDOW_FLAGS);
    if (screen == NULL) {
        Engine::log.LogMessage("Error", "Could not initialize SDL... Quitting!");
        return -1;
    }

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glClearColor(c.Red, c.Green, c.Blue, c.Alpha);
    glViewport(0, 0, w, h);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.f, w, h, 0.f, -1.f, 1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    const SDL_VideoInfo *vi = SDL_GetVideoInfo(); 
    width = vi->current_w;
    height = vi->current_h;

    scr = screen;

    EngineAttributes eat = Engine::GetAttributes();

    sw = (float)(width)/eat.width;
    sh = (float)(height)/eat.height;
    return 0;
}

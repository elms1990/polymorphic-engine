/*
 *  File: graphics.cpp
 *  Last Updated: 19/07/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "graphics.h"
#include "engine.h"
#include <SDL.h>
#include <SDL_opengl.h>

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

void Graphics::Draw(Texture* src, Rectanglef src_rect, Rectanglef dst_rect) {
    glBindTexture(GL_TEXTURE_2D, src->GetID());

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glBegin(GL_QUADS);

    //bottom-left
    glTexCoord2f(src_rect.X/src->Width, (src_rect.Y)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f(dst_rect.X, dst_rect.Y, 0.f);
    glLoadIdentity();

    //bottom-right
    glTexCoord2f((src_rect.X+src_rect.Width)/src->Width,
            src_rect.Y/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f(dst_rect.X + dst_rect.Width, dst_rect.Y, 0.f);
    glLoadIdentity();

    //top-right
    glTexCoord2f((src_rect.X+src_rect.Width)/src->Width, 
            (src_rect.Y+src_rect.Height)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f((dst_rect.X + dst_rect.Width), (dst_rect.Y + dst_rect.Height), 
            0.f);
    glLoadIdentity();

    //top-left
    glTexCoord2f(src_rect.X/src->Width, 
            (src_rect.Y+src_rect.Height)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f(dst_rect.X, (dst_rect.Y + dst_rect.Height), 0.f);
    glLoadIdentity();
    glEnd();
}

void Graphics::Draw(Texture* src, Rectanglef src_rect, float dest_x, float dest_y) {
    glBindTexture(GL_TEXTURE_2D, src->GetID());

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glBegin(GL_QUADS);

    //bottom-left
    glTexCoord2f(src_rect.X/src->Width, (src_rect.Y)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f(dest_x, dest_y, 0.f);
    glLoadIdentity();

    //bottom-right
    glTexCoord2f((src_rect.X+src_rect.Width)/src->Width,
            src_rect.Y/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f((dest_x + src_rect.Width), dest_y, 0.f);
    glLoadIdentity();

    //top-right
    glTexCoord2f((src_rect.X+src_rect.Width)/src->Width, 
            (src_rect.Y+src_rect.Height)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f((dest_x + src_rect.Width), (dest_y + src_rect.Height), 
            0.f);
    glLoadIdentity();

    //top-left
    glTexCoord2f(src_rect.X/src->Width, 
            (src_rect.Y+src_rect.Height)/src->Height);
    glScalef(sw, sh, 1.f);
    glVertex3f(dest_x, (dest_y + src_rect.Height), 0.f);
    glLoadIdentity();
    glEnd();

}

void Graphics::Draw(Texture* src, float dest_x, float dest_y) {
    glBindTexture(GL_TEXTURE_2D, src->GetID());

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glBegin(GL_QUADS);

    //bottom-left
    glTexCoord2f(0, 0);
    glScalef(sw, sh, 1.f);
    glVertex3f(dest_x, dest_y, 0.f);
    glLoadIdentity();

    //bottom-right
    glTexCoord2f(1, 0);
    glScalef(sw, sh, 1.f);
    glVertex3f((dest_x + src->Width), dest_y, 0.f);
    glLoadIdentity();

    //top-right
    glTexCoord2f(1, 1);
    glScalef(sw, sh, 1.f);
    glVertex3f((dest_x + src->Width), (dest_y + src->Height), 0.f);
    glLoadIdentity();

    //top-left
    glTexCoord2f(0, 1);
    glVertex3f(dest_x, (dest_y + src->Height), 0.f);
    glScalef(sw, sh, 1.f);
    glLoadIdentity();
    glEnd();
}

void Graphics::Flush() {
    SDL_GL_SwapBuffers();
}

void Graphics::DrawText(Font* font, const char* text, int x, int y, Color color) {
    if (font != NULL) {
        SDL_Color scl = { scl.r = color.Red, scl.b = color.Blue, scl.g = color.Green };
        SDL_Surface* txt = TTF_RenderUTF8_Blended((TTF_Font*)font->GetResource(),
                text, scl);
        
        if (txt != NULL) {
            Texture t = Texture(txt, "");
            Draw(&t, x, y);
        }
    }
}

void Graphics::DrawText(TextBuffer* t, int x, int y) {
    Draw(t->GetBuffer(), Rectanglef(0, 0, t->GetBuffer()->Width, 
                t->GetBuffer()->Height), Rectanglef(x, y, 
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

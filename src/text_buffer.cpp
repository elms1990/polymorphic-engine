#include "text_buffer.h"

using Polymorphic::Font;
using Polymorphic::Texture;
using Polymorphic::TextBuffer;

TextBuffer::TextBuffer() {
    dirty = false;
    f = NULL;
    size = 0;
    t = NULL;
    c = Color(0xff, 0xff, 0xff, 0xff);
}

TextBuffer::TextBuffer(Font *f, string text) {
    this->f = f;
    this->text = text;
    dirty = true;
    size = f->GetFontSize();
    t = NULL;
    c = Color(0xff, 0xff, 0xff, 0xff);
    UpdateBuffer();
}

TextBuffer::~TextBuffer() {
    if (t != NULL)
        delete t;
}

void TextBuffer::SetDisplayText(string text) {
    this->text = text;
    dirty = true;
}

void TextBuffer::SetDisplayFont(Font *f) {
    if (this->f == NULL) {
        size = f->GetFontSize();
    }
    this->f = f;
    dirty = true;
}

void TextBuffer::SetFontSize(int size) {
    this->size = size;
    dirty = true;
}

void TextBuffer::SetTextColor(Color c) {
    this->c = c;
    dirty = true;
}

Texture* TextBuffer::GetBuffer() {
    if (dirty) {
        UpdateBuffer();
    }
    return t;
}

void TextBuffer::UpdateBuffer() {
    SDL_Color scl = { scl.r = c.Red, scl.g = c.Green, scl.b = c.Blue, 
        scl.unused = c.Alpha };
    SDL_Surface *txt = TTF_RenderUTF8_Blended((TTF_Font*)f->GetResource(), 
            text.c_str(), scl);

    if (txt != NULL) {
        Image img;
        img.SetResource((void*)txt);
        if (t != NULL)
            delete t;
        t = Texture::CreateTextureFromImage(&img);
        dirty = false;
    }
    
}

float TextBuffer::GetScaleFactor() {
    return ((float)size/f->GetFontSize());
}

int TextBuffer::GetFontSize() {
    return size; 
}

string TextBuffer::GetText() {
    return text;
}

string TextBuffer::GetFontName() {
    return f->GetName();
}

#include "text_buffer.h"

using Polymorphic::Font;
using Polymorphic::Texture;
using Polymorphic::TextBuffer;

TextBuffer::TextBuffer() {
    dirty = false;
    text = NULL;
    f = NULL;
    size = 0;
    t = NULL;
    c = Color(0xff, 0xff, 0xff, 0xff);
}

TextBuffer::TextBuffer(Font* f, const char* text) {
    dirty = false;
    this->f = f;
    this->text = text;
    size = f->GetFontSize();
    t = NULL;
    c = Color(0xff, 0xff, 0xff, 0xff);
    UpdateBuffer();
}

TextBuffer::~TextBuffer() {
}

void TextBuffer::SetDisplayText(const char* text) {
    this->text = text;
    dirty = true;
}

void TextBuffer::SetDisplayFont(Font* f) {
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
    SDL_Color scl = { scl.r = c.Red, scl.g = c.Green, scl.b = c.Blue, scl.unused = c.Alpha };
    SDL_Surface* txt = TTF_RenderUTF8_Blended((TTF_Font*)f->GetResource(), text, scl);

    if (txt != NULL) {
        if (t != NULL)
            delete t;
        t = new Texture(txt, "");
        dirty = false;
    }
    
}

float TextBuffer::GetScaleFactor() {
    return ((float)size/f->GetFontSize());
}

int TextBuffer::GetFontSize() {
    return size; 
}

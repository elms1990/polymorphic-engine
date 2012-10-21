/*
 *  File: text_buffer.h
 *  Last Updated: 09/10/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __TEXT_BUFFER_H__
#define __TEXT_BUFFER_H__

#include "resource.h"
#include "color.h"

namespace Polymorphic {

    class TextBuffer {
        public:
            TextBuffer(Font *f, char *text);
            TextBuffer();
            ~TextBuffer();

            void SetDisplayText(char *text);
            void SetDisplayFont(Font *f);
            void SetFontSize(int size);
            void SetTextColor(Color c);

            Texture* GetBuffer();
            float GetScaleFactor();
            int GetFontSize();
            char* GetText();
            const char* GetFontName();

        private:
            inline void UpdateBuffer();

            Color c;
            Font *f;
            Texture *t;
            char *text;
            int size;
            bool dirty;
    };
}

#endif /* __TEXT_BUFFER__ */

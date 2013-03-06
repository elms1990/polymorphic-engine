#ifndef __HW_H__
#define __HW_H__

#include "resource.h"
#include "game_if.h"
#include "text_buffer.h"

using Polymorphic::Font;
using Polymorphic::GameIF;
using Polymorphic::TextBuffer;
using Polymorphic::Texture;
using Polymorphic::Image;

class HW : public GameIF {
    public:
        HW();
        ~HW();

        //Game Interface
        int Initialize();
        void Update(int deltaTime);
        void Render();
        void Shutdown();
    private:
        TextBuffer *hello;
        Font *def;
        Texture *tex;
};

#endif

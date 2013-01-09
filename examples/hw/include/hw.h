#ifndef __HW_H__
#define __HW_H__

#include "resource.h"
#include "game_if.h"
#include "text_buffer.h"

using Polymorphic::Font;
using Polymorphic::GameIF;
using Polymorphic::TextBuffer;

class HW : public GameIF {
    public:
        HW();
        ~HW();

        //Game Interface
        int Initialize();
        void Update(int deltaTime);
        void Render(int deltaTime);
        void Shutdown();
    private:
        TextBuffer *hello;
        Font *def;
};

#endif

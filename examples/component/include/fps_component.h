#ifndef __FPS_COMPONENT_H__
#define __FPS_COMPONENT_H__

#include "component.h"
#include "game_object.h"
#include "text_buffer.h"

using Polymorphic::TextBuffer;

class FpsComponent : public Component {
    public:
        FpsComponent();
        ~FpsComponent();

        void Initialize();
        void Execute();

    private:
        TextBuffer tb;
};

#endif

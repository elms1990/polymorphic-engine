#ifndef __INPUT_COMPONENT_H__
#define __INPUT_COMPONENT_H__

#include "component.h"
#include "game_object.h"
#include "transform_component.h"

class InputComponent : public Component {
    public:
        InputComponent(GameObject *go);
        ~InputComponent();

        void Initialize();
        void Execute();

    private:
        TransformComponent *tc;
        GameObject *go;
};

#endif

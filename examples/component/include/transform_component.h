#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include "game_object.h"
#include "component.h"

class TransformComponent : public Component {
    public:
        TransformComponent(GameObject *go);
        ~TransformComponent();

        void Initialize();
        void Execute();

        float x;
        float y;
        int w;
        int h;
        float sx;
        float sy;
        float rot;

    private:
        GameObject *go;
};

#endif

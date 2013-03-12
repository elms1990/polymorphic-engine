#ifndef __RENDER_COMPONENT_H__
#define __RENDER_COMPONENT_H__

#include "component.h"
#include "transform_component.h"
#include "resource.h"

using Polymorphic::Texture;

class RenderComponent : public Component {
    public:
        RenderComponent(GameObject *go);
        ~RenderComponent();

        void Initialize();
        void Execute();
    private:
        GameObject *go;
        TransformComponent *tc;
        Texture *t;
};

#endif

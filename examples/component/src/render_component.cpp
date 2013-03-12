#include "render_component.h"
#include <stdio.h>
#include "engine.h"

using namespace Polymorphic;

RenderComponent::RenderComponent(GameObject *go) : Component("Render") {
    this->go = go;
    t = NULL;
}

RenderComponent::~RenderComponent() {

}

void RenderComponent::Initialize() {
    tc = (TransformComponent*)go->GetComponent("Transform");
    Image *i = Engine::cmanager.LoadImage("player_image",
            "img/he.png");
    t = Texture::CreateTextureFromImage(i);
}

void RenderComponent::Execute() {
    Engine::graphics.Draw(t, tc->x, tc->y);
}

#include "cmp.h"
#include "engine.h"
#include "input_component.h"
#include "render_component.h"
#include "transform_component.h"

using namespace Polymorphic;

CMP::CMP() {
}

CMP::~CMP() {

}

int CMP::Initialize() {
    GameObject *go = new GameObject();
    go->AddComponent(new RenderComponent(go));
    go->AddComponent(new TransformComponent(go));
    go->AddComponent(new InputComponent(go));

    stuff.push_back(go);

    TransformComponent *tc = (TransformComponent*)go->GetComponent("Transform");
    tc->x = 100;
    tc->y = 100;

    for (list<GameObject*>::iterator it = stuff.begin();
            it != stuff.end(); it++) {
        (*it)->Initialize();
    }

    return 0;
}

void CMP::Update(int deltaTime) {
    for (list<GameObject*>::iterator it = stuff.begin(); it != stuff.end();
            it++) {
        (*it)->Update();
    }
}

void CMP::Render() {
}

void CMP::Shutdown() {
}

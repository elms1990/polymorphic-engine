#include "input_component.h"
#include "engine.h"
#include <stdio.h>

using namespace Polymorphic;

InputComponent::InputComponent(GameObject *go) : Component("Input") {
    this->go = go;
    this->tc = NULL;
}

InputComponent::~InputComponent() {

}

void InputComponent::Initialize() {
    tc = (TransformComponent*)go->GetComponent("Transform");
}

void InputComponent::Execute() {
    InputState *iS = Engine::keyboard.GetState();

    if (iS->IsButtonDown("up")) {
        tc->y -= 100.f*Engine::GetElapsedTime()/1000.f;
    }
    if (iS->IsButtonDown("left")) {
        tc->x -= 100.f*Engine::GetElapsedTime()/1000.f;
    }

    if (iS->IsButtonDown("right")) {
        tc->x += 100.f*Engine::GetElapsedTime()/1000.f;
    }
    if (iS->IsButtonDown("down")) {
        tc->y += 100.f*Engine::GetElapsedTime()/1000.f;
    }
}

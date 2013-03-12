#include "transform_component.h"

TransformComponent::TransformComponent(GameObject *go) : Component("Transform") {
    this->go = go;
    x = 0.f;
    y = 0.f;
    sx = 1.f;
    sy = 1.f;
    rot = 0.f;
}

TransformComponent::~TransformComponent() {

}

void TransformComponent::Initialize() {

}

void TransformComponent::Execute() {

}

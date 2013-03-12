#include "component.h"

Component::Component() {

}

Component::Component(string name) {
    this->name = name;
}

Component::~Component() {

}

string Component::GetName() {
    return name;
}

void Component::SetName(string name) {
    this->name = name;
}

void Component::Execute() {

}

void Component::Initialize() {

}

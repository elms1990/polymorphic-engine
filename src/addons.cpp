#include "addons.h"

using namespace Polymorphic;

AddOn::AddOn(const char *name) {
    this->name = name;
}

AddOn::~AddOn() {

}

int AddOn::Initialize() {
    return 0;
}

void AddOn::Update(int deltaTime) {

}

void AddOn::Render(int deltaTime) {

}

void AddOn::Shutdown() {

}

const char* AddOn::GetName() {
    return name;
}

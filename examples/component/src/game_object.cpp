#include "game_object.h"
#include <string.h>

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::Initialize() {
    for (list<Component*>::iterator it = cps.begin(); 
            it != cps.end(); it++) {
        (*it)->Initialize();
    }
}

void GameObject::AddComponent(Component *c) {
    cps.push_back(c);
}

Component* GameObject::GetComponent(string name) {
    for (list<Component*>::iterator it = cps.begin();
            it != cps.end(); it++) {
        if (strcmp((*it)->GetName().c_str(), name.c_str()) == 0)
            return (*it);
    }
    return NULL;
}

void GameObject::Update() {
    for (list<Component*>::iterator it = cps.begin();
            it != cps.end(); it++) {
        (*it)->Execute();
    }
}

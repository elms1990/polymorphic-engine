/*
 *  File: game_object.cpp
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#include "game_object.h"
#include "event.h"

using Polymorphic::GameObject;

GameObject::GameObject(string id) {
    mId = id;
}

GameObject::~GameObject() {
}

void GameObject::SetId(string id) {
    mId = id;
}

string GameObject::GetId() {
    return mId;
}

void GameObject::Initialize() {
    for (list<GameComponent*>::iterator it = mChildren.begin();
            it != mChildren.end(); it++) {
        (*it)->Initialize();
    }
}

void GameObject::Update(float timeStep) {
    for (list<GameComponent*>::iterator it = mChildren.begin();
            it != mChildren.end(); it++) {
        (*it)->Update(timeStep);
    }
}

void GameObject::Render() {
    for (list<GameComponent*>::iterator it = mChildren.begin();
            it != mChildren.end(); it++) {
        (*it)->Render();
    }
}

void GameObject::Shutdown() {
    for (list<GameComponent*>::iterator it = mChildren.begin();
            it != mChildren.end(); it++) {
        (*it)->Shutdown();
    }
}

GameObject* GameObject::AddComponent(GameComponent *component) {
    mChildren.push_back(component);

    return this;
}

GameComponent* GameObject::GetComponent(string name) {
    list<GameComponent*>::iterator it;

    for (it = mChildren.begin(); it != mChildren.end(); it++) {
        if (name.compare((*it)->GetId()) == 0) {
            return (*it);
        }
    }

    return NULL;
}

GameObject* GameObject::RemoveComponent(string name) {
    list<GameComponent*>::iterator it;

    for (it = mChildren.begin(); it != mChildren.end(); it++) {
        if (name.compare((*it)->GetId()) == 0) {
            mChildren.remove(*it);
            break;
        }
    }

    return this;
}

void GameObject::SendMessage(Event *e) {
    if (e->Receiver == NULL) {
        return;
    }

    e->Sender->ReceiveMessage(e);
}

void GameObject::ReceiveMessage(Event *e) {
    OnEvent(e);
}

void GameObject::OnEvent(Event *e) {
}

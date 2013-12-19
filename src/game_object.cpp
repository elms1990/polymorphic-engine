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

}

void GameObject::Update(float timeStep) {
}

void GameObject::Render() {
}

void GameObject::Shutdown() {
}

GameObject* GameObject::AddComponent(string name, GameComponent *component) {
    mChildren.push_back(pair<string, GameComponent*>(name, component));

    return this;
}

GameComponent* GameObject::GetComponent(string name) {
    list<pair<string, GameComponent*> >::iterator it;

    for (it = mChildren.begin(); it != mChildren.end(); it++) {
        if (name.compare(it->first) == 0) {
            return it->second;
        }
    }

    return NULL;
}

GameObject* GameObject::RemoveComponent(string name) {
    list<pair<string, GameComponent*> >::iterator it;

    for (it = mChildren.begin(); it != mChildren.end(); it++) {
        if (name.compare(it->first) == 0) {
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

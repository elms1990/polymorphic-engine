/*
 *  File: game_component.cpp
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#include "game_component.h"

using Polymorphic::GameComponent;

GameComponent::GameComponent(string id) {
    mId = id;
}

GameComponent::~GameComponent() {

}

void GameComponent::SetId(string id) {
    mId = id;
}

string GameComponent::GetId() {
    return mId;
}

void GameComponent::Initialize() {

}

void GameComponent::Update(float timeStep) {

}

void GameComponent::Render() {

}

void GameComponent::Shutdown() {

}

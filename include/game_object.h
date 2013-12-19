/*
 *  File: game_object.h
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <list>
#include <map>
#include <string>
#include "game_component.h"
#include "hack.h"

using std::list;
using std::pair;
using std::string;
using Polymorphic::GameComponent;

namespace Polymorphic {
    class Event;
    
    class GameObject {
        public:
            GameObject(string id);
            virtual ~GameObject();

            void SetId(string id);
            string GetId();

            virtual void Initialize();
            virtual void Update(float timeStep);
            virtual void Render();
            virtual void Shutdown();

            GameObject* AddComponent(string name, GameComponent *component);
            GameComponent* GetComponent(string name);
            GameObject* RemoveComponent(string name);

            void SendMessage(Event *e);
            void ReceiveMessage(Event *e);

        private:
            string mId;
            list<pair<string, GameComponent*> > mChildren;

            virtual void OnEvent(Event *e);
    };
}

#endif

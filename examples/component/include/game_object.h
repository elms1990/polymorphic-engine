#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "component.h"
#include <list>
#include <string>

using std::list;
using std::string;

class GameObject {
    public:
        GameObject(string name);
        GameObject();
        ~GameObject();

        void Initialize();

        string GetName();
        void SetName(string name);

        void AddComponent(Component *c);
        Component* GetComponent(string name);
        void Update();

    private:
        list<Component*> cps;
        string name;
};

#endif

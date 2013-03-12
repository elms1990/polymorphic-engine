#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "component.h"
#include <list>
#include <string>

using std::list;
using std::string;

class GameObject {
    public:
        GameObject();
        ~GameObject();

        void Initialize();

        void AddComponent(Component *c);
        Component* GetComponent(string name);
        void Update();

    private:
        list<Component*> cps;
};

#endif

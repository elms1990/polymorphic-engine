#ifndef __HW_H__
#define __HW_H__

#include "game_if.h"
#include "component.h"
#include "game_object.h"
#include <list>

using std::list;
using Polymorphic::GameIF;

class CMP : public GameIF {
    public:
        CMP();
        ~CMP();

        //Game Interface
        int Initialize();
        void Update(int deltaTime);
        void Render();
        void Shutdown();
        
    private:
        list<GameObject*> stuff;
};

#endif

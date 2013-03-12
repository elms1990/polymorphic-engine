#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <string>

using std::string;

class Component {
    public:
        Component();
        Component(string name);
        virtual ~Component();

        string GetName();
        void SetName(string name);

        virtual void Initialize();
        virtual void Execute();

    protected:
        string name;
};


#endif

#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "Component.h"
#include <string>
#include <vector>

class GameObject
{
public:
    template <typename T>
    bool addComponent()
    {
        try
        {
            components.push_back(new T);
            return true;
        }
        return false;
    }

    template <typename T>
    T* getComponent()
    {
	    std::string name = typeid(T).name();

        for (Component* comp: components)
        {
            if (comp->name == name)
                return static_cast<T*>(comp);
        }
        return nullptr;
    }

    template <typename T>
    bool removeComponent()
    {
        std::string name = typeid(T).name();

        for (int i = 0; i < components.size(); i++)
        {
            if (components[i]->name == name)
            {
                delete components[i];
                components.erase(components.begin() + i);
                return true;
            }
            return false;
        }
    }
private:
    std::vector<Component*> components;
};

#endif
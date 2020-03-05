#include "Component.h"
#include <string>
#include <vector>

class GameObject
{
public:
    template <typename T>
    void addComponent()
    {
        T* obj = new T;
        components.push_back(obj);
    }

    template <typename T>
    T* getComponent(std::string name)    // bad iteration
    {
        for (Component* comp: components)
        {
            if (comp->name == name)
                return static_cast<T*>(comp);
        }
        return nullptr;
    }
private:
    std::vector<Component*> components;
};

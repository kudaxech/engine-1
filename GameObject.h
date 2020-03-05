#include "Component.h"
#include <string>
#include <vector>

class GameObject
{
public:
    template <typename T>
    void addComponent()
    {
        components.push_back(new T);
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
private:
    std::vector<Component*> components;
};

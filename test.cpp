#include "GameObject.h"
#include <iostream>

int main()
{
    GameObject test_object;
    test_object.addComponent<TestType>();

    TestType* test_comp = test_object.getComponent<TestType>();
    std::cout << test_comp->test_string << std::endl;

    return 0;
}

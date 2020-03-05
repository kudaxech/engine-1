#include <string>

class Component
{
public:
    std::string name;
};

class TestType: public Component
{
public:
    TestType()
    {
        name = "TestType";
    }
    std::string test_string = "it works :)";
};

#include <iostream>
#include <string>

class Entity{
private:
    std::string m_Name;    
public:
    Entity()
        : m_Name("Unknown") // initializer list is used
    { // the constructor block is empty but cut be used for calling methods, init functions, etc..
    }
    
    Entity(const std::string& name)
        : m_Name(name)
    {
    }

    const std::string& GetName() const { return m_Name; }
};

int main(){
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Cherno");
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}
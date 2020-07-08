#include <iostream>
#include <string>

class Example{
public: 
    Example(){
        std::cout << "Created Entity" << std::endl;
    }

    Example(int x){
        std::cout << "Created Entity with " << x << std::endl;
    }
};

class Entity{
private:
    std::string m_Name;    
    Example m_Example;
public:
    Entity()
        : m_Name("Unknown") 
        // , m_Example(Example(8)) // single construction -> better performance
        , m_Example(8) // single construction -> better performance
    {
        // m_Example = Example(8); // causes double construction of Entity object
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
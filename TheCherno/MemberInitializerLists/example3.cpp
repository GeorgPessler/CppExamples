#include <iostream>
#include <string>

class Entity{
private:
    std::string m_Name;   // the order of the members is important for the order of initialization
    int m_Scope;          // in the initializer list of constructors!
public:
    Entity()
        : m_Name("Unknown") // this order is correct 
        , m_Scope(8)
        // : m_Scope(8) // ERROR wrong order
        // , m_Name("Unknown")
    {
    }
    
    Entity(const std::string& name, const int& scope)
        : m_Name(name)
        , m_Scope(scope)
    {
    }

    const std::string& GetName() const { return m_Name; }
};

int main(){
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Cherno",5);
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}
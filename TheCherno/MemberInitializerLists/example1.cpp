#include <iostream>
#include <string>

class Entity{
private:
    std::string m_Name;    
public:
    Entity()        // no initializer list 
    {
        m_Name = "Unknown"; // member is initialized inside constructor scope
    }
    
    Entity(const std::string& name)
    {
        m_Name = name;
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
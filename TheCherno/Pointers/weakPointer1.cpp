// basic use of weak pointer
#include <iostream>
#include <memory>

class Entity{
private:
    int m_number;
public: 
    Entity():m_number(42){
        std::cout << "Created entity " << m_number << std::endl;
    }
    Entity(int n):m_number(n){
        std::cout << "Created entity " << m_number << std::endl;
    }
    ~Entity(){
        std::cout << "Destroyed entity" << m_number << std::endl;
    }
    void Print(){
        std::cout << "I am entity " << m_number << std::endl;
    }
};

int main(void){

    std::weak_ptr<Entity> weakEnt;

    {
        std::shared_ptr<Entity> sharedEnt = std::make_shared<Entity>(1);
        weakEnt = sharedEnt;

        sharedEnt->Print();

        std::cout << "Weak entity use count: " << weakEnt.use_count() << std::endl;
        std::cout << "Shared entity use count: " << sharedEnt.use_count() << std::endl;
    }
    
    std::cin.get();
}
// basic use of shared pointer
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
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(1);
    auto sharedEntity2 = sharedEntity;
    std::shared_ptr<Entity> e3 = sharedEntity2;

    sharedEntity->Print();
    sharedEntity2->Print();
    e3->Print();

    std::cout << "Shared entity use count: " << sharedEntity.use_count() << std::endl;

    sharedEntity2.reset();
    std::cout << "Shared entity use count: " << sharedEntity.use_count() << std::endl;

    e3.reset(new Entity(2));
    std::cout << "Shared entity use count: " << sharedEntity.use_count() << std::endl;

    std::cin.get();
}
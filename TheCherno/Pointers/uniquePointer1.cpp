// basic use of unique_ptr
#include <iostream>
#include <memory>

class Entity{
public:
    Entity(){
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity(){
        std::cout << "Destroyed Entity" << std::endl;
    }
    void Print(){
        std::cout << "Print something" << std::endl;
    } 
};

int main(){
    std::cout << "Entry of main" << std::endl;

    // create a unique pointer inside a scope
    // unique pointers can not be copied(, but moved i think)
    // the memory gets freed if scope is left
    {   
        std::cout << "Entry of scope" << std::endl;

        // there are two ways to construct the pointer
        // the first way is to construct inside brackets(, not exception safe)
        std::unique_ptr<Entity> entity(new Entity);
        // std::unique_ptr<Entity> entity = new Entity; // ERROR not possible because of explicit constr of unique_ptrs
        entity->Print();

        // second way is to use std::make_unique, which is the preferred way
        // , because it is safer, when exceptions are called
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        entity2->Print();

        std::cout << "End of scope" << std::endl;
    }
    std::cout << "Scope Left" << std::endl;
    std::cin.get();
}


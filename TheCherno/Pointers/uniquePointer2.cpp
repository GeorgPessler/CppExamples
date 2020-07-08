// copy / move / swap of unique_ptr
#include <iostream>
#include <memory>

class Entity{
private: 
    int m_number;
public:
    Entity():m_number(1984){
        std::cout << "Created Entity " << m_number << std::endl;
    }
    Entity(int number):m_number(number){
        std::cout << "Created Entity " << m_number << std::endl;
    }
    ~Entity(){
        std::cout << "Destroyed Entity "<< m_number << std::endl;
    }
    void Print(){
        std::cout << "Hello im number: " << m_number << std::endl;
    } 
};

int main(){
    std::cout << "Entry of main" << std::endl;

    {   
        std::cout << "Entry of scope" << std::endl;


        std::unique_ptr<Entity> entity(new Entity(1));
        entity->Print();

        //std::unique_ptr<Entity> entity2 = entity; // ERROR unique_ptr cannot be copied!
        std::unique_ptr<Entity> entity2 = std::move(entity); // entity2 owns the ressource now!
        std::cout << "entity2 = " << entity2.get() << ": ";
        entity2->Print();

        // entity doesn't point to the ressource anymore
        // Print() can still be called, which will lead the program to crash!! 
        // std::cout << "entity = " << entity.get() << ": ";
        // entity->Print(); // ERROR

        // unique pointers can be swapped
        std::unique_ptr<Entity> ent3 = std::make_unique<Entity>(3);
        auto ent4 = std::make_unique<Entity>(4);    // here it is very comfortable to use auto

        std::cout << "ent3 = " << ent3.get() << ": "; ent3->Print();
        std::cout << "ent4 = " << ent4.get() << ": "; ent4->Print();

        std::swap(ent3, ent4);

        std::cout << "ent3 = " << ent3.get() << ": "; ent3->Print();
        std::cout << "ent4 = " << ent4.get() << ": "; ent4->Print();

        std::cout << "End of scope" << std::endl;
    }
    std::cout << "Scope Left" << std::endl;
    std::cin.get();
}


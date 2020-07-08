#include <iostream>

class Entity{
private:
    int m_a, m_b;
    int* m_c, *m_d;
    mutable int var;
public: 
    int GetA() const{ // const promises not to change any members (m_a, m_b, m_c, m_d)
        var = 3; // can be changed because it is mutable
        // mutable is for special occasions when you need to bypass const methods or const classes
        return m_a;
    }
    int GetB(){
        return m_b;
    }
    const int* const GetC() const{ // const int* const promises that the returned pointer won't be changed, neither its value
        return m_c;
    }
    void SetB(int value){ // no const because the purpose is to change something
        m_b = value;
    }
};

//void PrintEntity(const Entity*const  e){ // neither pointer nor value are allowed to be changed
void PrintEntity(const Entity& e){ // same as before because reference points always to same object and const prevents change of value
    std::cout << e.GetA() << std::endl; // because GetA is const it is allowed to call it
    //std::cout << e.GetB() << std::endl; // ERROR because GetB does not guarantee const
};

int main(){
    const int MAXIMUM_VALUE = 90; // const promises that the variable won't be changed after definition
    // MAXIMUM_VALUE = 3; // ERROR
    //int* a = &MAXIMUM_VALUE; // ERROR, one could try to explicitly cast, but that would be stupid
    int* a = (int*) &MAXIMUM_VALUE; // possible trough explicitly cast, but that would be stupid and dangerous
    *a = 2;                         // the value gets changed despite it is not expected, nor allowed
    std::cout << *a << std::endl;

    int b = 4;

    const int* c = &b; // promises that the value of the pointer won't be changed
    int const* d = &b; // same as above
    //*c = 3; // ERROR
    //*d = 3; // ERROR
    c = nullptr; // pointer can be changed
    d = nullptr;

    int* const e = &b; // promises that pointer won't be changed
    //e = nullptr; // ERROR
    *e = 3; // value can be changed

    const int* const f = &b; // neither pointer nor value allowed to change
    int const * const g = &b; // same as above 
}
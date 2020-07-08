/*
basic use of function pointers 

https://isocpp.org/wiki/faq/pointers-to-members
https://www.learncpp.com/cpp-tutorial/78-function-pointers/
https://www.cprogramming.com/tutorial/function-pointers.html
https://www.geeksforgeeks.org/function-pointer-in-c/
https://riptutorial.com/c/example/31818/typedef-for-function-pointers
*/


#include <iostream>

// because it is awful to read people usually use typedef or using 
using HelloWorldFunctionWithUsing = void(*)();
typedef void(*HelloWorldFunctionWithTypedef)();
// what's the difference? 
// https://www.internalpointers.com/post/differences-between-using-and-typedef-modern-c
// https://stackoverflow.com/questions/10747810/what-is-the-difference-between-typedef-and-using-in-c11

void HelloWorld(){
    std::cout << "Hello World!" << std::endl;
}

bool Example(int number){
    std::cout << "Example" << number << std::endl;
    return true;
}

int main(){
    HelloWorld();

    // different ways to assign a function to a variable
    auto function = HelloWorld;
    auto sameFunction = &HelloWorld;
    void (*withoutAuto)(){HelloWorld}; // without auto it is much uglier 
    void (*alsoPossible)();
    alsoPossible = HelloWorld;

    // this is how to call the original function with the different funct pointers
    function();
    sameFunction();
    withoutAuto();
    alsoPossible();

    bool (*example)(int){Example}; // second example, without auto, with params
    example(2); // calling the example function with the function pointer

    // because it is awful to read people usually use typedef or using 
    HelloWorldFunctionWithTypedef fantasticReadable = HelloWorld;
    fantasticReadable();
    HelloWorldFunctionWithUsing superReadable = HelloWorld;
    superReadable();

    std::cin.get();
}
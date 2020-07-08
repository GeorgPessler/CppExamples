#include <iomanip>
#include <iostream>
#include <typeinfo>

template <typename T>
void printInfoFor(T value){

  std::cout << std::boolalpha;
  std::cout << std::setw(5) << value << ": " << "(type: " << std::setw(3) << typeid(value).name() << ",size: " << sizeof(value) << ")\n";

}

template<typename T>
void printValueInfo(T value){

    // print the information of the value
    printInfoFor(value);

}

template<typename First,typename ... Rest>
void printValueInfo(First first,Rest ... rest){

    // print the information of the value
    printInfoFor(first);

    // invoke value Information for the rest, excluding first
    printValueInfo(rest...);

}

int main(){

  std::cout << std::endl;

  //printValueInfo(); // => compile error

  printValueInfo(true,42,2.3,'c',"C++0x");

  std::cout << std::endl;

}


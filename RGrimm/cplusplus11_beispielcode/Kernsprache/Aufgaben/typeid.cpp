#include <iostream>
#include <typeinfo>

template<typename T1, typename T2>
auto getType(T1 first, T2 second) -> decltype(first + second){
    return first + second;
}

int main(){

  // -> int
  std::cout << typeid( getType(1,false) ).name() << std::endl;
  std::cout << typeid( getType('a',1) ).name() << std::endl;
  std::cout << typeid( getType(false,false) ).name() << std::endl;

  // -> double
  std::cout << typeid( getType(true,3.14) ).name() << std::endl;
  std::cout << typeid( getType(1,4.0) ).name() << std::endl;

}


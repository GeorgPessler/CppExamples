#include <iostream>

template <class T>
auto getValue(T d)-> decltype(d){
    return d;
}

template<typename T1, typename T2>
auto add(T1 first, T2 second) -> decltype(first + second){
    return first + second;
}

int main(){

  std::cout << std::endl;

  auto testDouble= getValue(3.4);
  std::cout << "testDouble: " << testDouble << "\n";

  auto testString= getValue("I'm a string.");
  std::cout << "testString: " << testString << "\n";

  auto a1= add(1,1);
  auto a2= add(1,2.1);
  std::cout << "add(1,1)= " << a1 << std::endl;
  std::cout << "add(1,2.1)= " << a2 << std::endl;
  std::cout << "add(1000LL,5)= " << add(1000LL,5) << std::endl;

  std::cout << std::endl;
}

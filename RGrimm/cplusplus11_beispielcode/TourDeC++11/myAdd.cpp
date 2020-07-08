#include <iostream>

int main(){

  // define the function pointer
  int (*myAdd1)(int,int)= [](int a, int b){return a + b;};

  // use type inference of the C++11 compiler
  auto myAdd2= [](int a, int b){return a + b;};

  std::cout << "\n";

  // use the function pointer
  std::cout << "myAdd1(1,2)= " << myAdd1(1,2) << std::endl;

  // use the auto variable
  std::cout << "myAdd2(1,2)= " << myAdd2(1,2) << std::endl;

  std::cout << "\n";

}

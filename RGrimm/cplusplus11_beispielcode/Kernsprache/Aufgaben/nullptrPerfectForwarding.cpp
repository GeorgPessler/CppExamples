#include <iostream>
#include <string>

std::string overloadTest(char*){
  return "char*";
}

std::string overloadTest(int){
  return "int";
}

template <typename T>
std::string forwardMe(T&& arg){
  return overloadTest(arg);
}

int main(){

  std::cout << std::endl;

  std::cout << std::boolalpha;

  overloadTest(nullptr);
  forwardMe(nullptr);

  // calls char*
  std::cout << "overloadTest(nullptr): " <<  overloadTest(nullptr) << std::endl;
  std::cout << "forwardMe(nullptr): " <<  forwardMe(nullptr) << std::endl;

  std::cout << std::endl;

}

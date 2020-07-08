#include <iostream>
#include <string>

std::string overloadTest(char*){
  return "char*";
}

std::string overloadTest(int){
  return "int";
}

int main(){

  std::cout << std::endl;

  int* pi = nullptr;    // OK
  int i= nullptr;       // ERROR
  bool b = nullptr;     // OK. b is false.

  std::cout << std::boolalpha << "b: "  << b << std::endl;

  // calls int
  std::cout << "overloadTest(0)= " <<  overloadTest(0) << std::endl;

  // calls char*
  std::cout<< "overloadTest(static_cast<char*>(0))= " << overloadTest(static_cast<char*>(0)) << std::endl;

  // calls char*
  std::cout << "overloadTest(nullptr)= " <<  overloadTest(nullptr)<< std::endl;

  // ambiguous error
  std::cout << "overloadTest(NULL)= " << overloadTest(NULL) << std::endl;

  std::cout << std::endl;

}


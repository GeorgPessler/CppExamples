#include <iostream>
#include <string>

struct MyData{};

std::string referenceTo(MyData& ) {
  return "lvalue reference";
}

std::string referenceTo(const MyData&  ) {
  return "const lvalue reference";
}

std::string rValueToFunction(const MyData& ) {
  return "const lvalue reference";
}

std::string rValueToFunction(MyData&& ) {
  return "rvalue reference";
}

std::string onlyRvalue(MyData&& ){
  return "rvalue reference";
}


int main(){

  std::cout << std::endl;

  // C++98 rules:
  // lvalue to lvalue reference
  // rvalue to const lvalue reference
  MyData myData;
  std::cout << "referenceTo(myData): " << referenceTo(myData) << std::endl;
  std::cout << "referenceTo(MyData()): " << referenceTo(MyData()) << std::endl;

  std::cout << std::endl;

  // rvalue reference binds stronger than const lvalue reference
  std::cout << "rValueToFunction(MyData()): " << rValueToFunction(MyData()) << std::endl;

  std::cout << std::endl;

  // only for rvalues
  std::cout << "onlyRvalue(MyData()): " <<  onlyRvalue(MyData()) << std::endl;

  // try it with lvalue and const lvalue
  /*
  const MyData myConstData= static_cast<MyData>(myData);
  onlyRvalue(myData);
  onlyRvalue(myConstData);
  */

  std::cout << std::endl;

}



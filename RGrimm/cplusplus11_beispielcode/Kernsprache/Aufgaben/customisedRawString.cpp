#include <iostream>
#include <string>

int main(){
  std::cout << std::endl;

  std::string myRawString(R"RAINER("))RAINER");
  std::cout << myRawString << std::endl;

  std::cout << std::endl;
}

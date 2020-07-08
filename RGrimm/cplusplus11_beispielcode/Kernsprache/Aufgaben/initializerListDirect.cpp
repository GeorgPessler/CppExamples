#include <initializer_list>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::initializer_list<std::string> myInitList{"I'm ","a ","initialiser ","list."};
  for ( auto i: myInitList ) std::cout << i;

  std::cout << std::endl;

}

#include <iostream>

int main(){

  std::cout << std::endl;

  if ( 1/0 ) std::cout << "(1/0)" << std::endl;
  if ( true or (1/0) ) std::cout << "(true or 1/0)" << std::endl;

  std::cout << std::endl;

}

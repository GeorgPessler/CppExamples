#include <iostream>
#include <random>

int main(){

  std::cout << std::endl;

  std::random_device seed;

  // generator
  std::mt19937 engine(seed());

  // distribution
  std::uniform_int_distribution<int> six(1,6);

  for ( int i=1; i<= 3; ++i){
    std::cout << "dice["<< i << "]: " << six(engine) << std::endl;
  }

  std::cout << std::endl;

}

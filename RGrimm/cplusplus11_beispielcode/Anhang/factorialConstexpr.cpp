#include <iostream>

constexpr long long factorial( long long i ){
  return (i > 0) ? i * factorial(i - 1) : 1;
}

int main(){

  std::cout << std::endl;

  std::cout << "factorial(10): " << factorial(10) << std::endl;
  std::cout << "factorial(20): " << factorial(20) << std::endl;

  static_assert( factorial(5) == 120,"Not available at compile time.");

  std::cout << std::endl;

}

#include <iostream>

int factorialLoop(int n){
  int fac=1;
  for (int i= 2; i <= n; ++i) fac *= i;
  return fac;
}

template <int N>
struct FactorialRec{
  static int const value= N * FactorialRec<N-1>::value;
};

template <>
struct FactorialRec<1>{
  static int const value = 1;
};

template <>
struct FactorialRec<0>{
  static int const value = 1;
};

int main(){

  std::cout << std::endl;

  // check at compile time the value
  static_assert(FactorialRec<5>::value == 120, "Is not available at compile time.");
  std::cout << "FactorialRec<5>::value: " << FactorialRec<5>::value << std::endl;

  std::cout << "factorialLoop(5): " << factorialLoop(5) << std::endl;

  std::cout << std::endl;

}

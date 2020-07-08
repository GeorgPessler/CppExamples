#include <iostream>

template <int n >
struct NoOfDivisor;

template <int n>
struct IsPrime{
  enum { value = NoOfDivisor<n>::value == 2 ? 1 : 0 };
};

template <int Start, int End>
struct NumDivisorsLoop{
  enum { value = (End % Start == 0 ? 1 : 0)   + NumDivisorsLoop<Start + 1, End>::value };
};

template <int End>
struct NumDivisorsLoop<End, End>{
  enum { value = 1 };
};

template <int n>
struct NoOfDivisor{
  enum { value = NumDivisorsLoop<1, n>::value };
};

int main(){

  std::cout << "IsPrime<10>::value: " << IsPrime<10>::value<< std::endl;

  std::cout << "IsPrime<11>::value: " << IsPrime<11>::value<< std::endl;

  std::cout << "IsPrime<12>::value: " << IsPrime<12>::value<< std::endl;

  std::cout << "IsPrime<13>::value: " << IsPrime<13>::value<< std::endl;

}

#include <array>
#include <iostream>
#include <vector>

int main(){

  std::vector<int> myVec({1,2,3,4,5});

  for (auto v: myVec) std::cout << v << " ";

  std::cout << std::endl;

  std::array<int,5> myArr({{1,2,3,4,5}});

  for (auto a: myArr) std::cout << a << " ";

  std::cout << std::endl;

}


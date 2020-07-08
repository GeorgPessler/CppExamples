#include <algorithm>
#include <iostream>
#include <vector>

static const int SIZE=10;

int main(){

  std::cout << std::endl;

  std::vector<int> myListRange;
  for (auto i= 0; i < SIZE; ++i) myListRange.push_back(0);

  int inc= 1;
  for (auto& i: myListRange) i= ++inc;
  for (auto& i: myListRange) i= (i*i);
  std::vector<int> myListForEach= myListRange;
  for (int i: myListRange) std::cout << i << " ";

  std::cout << std::endl;

  std::for_each( myListForEach.begin(), myListForEach.end(),[](int& i){return i*i;});
  for (int i: myListForEach) std::cout << i << " ";

  std::cout << std::endl;

}

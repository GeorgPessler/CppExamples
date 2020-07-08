#include <iostream>
#include <list>

static const int SIZE=20;

int main(){

  std::cout << std::endl;

  std::list<int> myList;
  for (auto i= 0; i < SIZE; ++i) myList.push_back(0);

  int inc= 0;
  for (auto& i: myList) i= ++inc;

  for (auto i: myList) std::cout << i << " ";

  std::cout << std::endl;

}

#include <algorithm>
#include <iostream>
#include <vector>

int main(){

  std::cout << std::endl;
  std::cout << std::boolalpha;

  //std::vector<int> myVec{4000,3998,3999,-5,11,2011,10,-5,-10,1998,-4,3,8,23};
  std::vector<int> myVec{-2,-1,0,1,2,3,4,5,6,7,8,9};

  std::cout << "myVec: ";
  for ( auto i: myVec) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "std::is_heap(myVec.being(),myVec.end()): " << std::is_heap(myVec.begin(),myVec.end()) << std::endl;

  std::cout << "std::is_heap_until(myVec.being(),myVec.end()): " << *(std::is_heap_until(myVec.begin(),myVec.end())) << std::endl;

  std::make_heap(myVec.begin(),myVec.end());
  std::cout << "myVec: ";
  for ( auto i: myVec) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "std::is_heap(myVec.being(),myVec.end()): " << std::is_heap(myVec.begin(),myVec.end()) << std::endl;

  std::sort_heap(myVec.begin(),myVec.end());
  std::cout << "std::sort_heap(myVec.begin(),myVec.end()): ";
  for ( auto i: myVec) std::cout << i << " ";

  std::cout << "\n\n";

}

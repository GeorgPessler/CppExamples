#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

int main(){

  std::cout << std::endl;

  std::vector<std::unique_ptr<int>> myVector;
  myVector.push_back(std::unique_ptr<int> (new int(2011)));
  myVector.push_back(std::unique_ptr<int> (new int(1998)));
  myVector.push_back(std::unique_ptr<int> (new int(2003)));

  sort(myVector.begin(),myVector.end());
  for ( auto v= myVector.begin(); v != myVector.end(); ++v) std::cout << *(v->get()) << " ";

  std::cout << std::endl;

  sort(myVector.begin(),myVector.end(),std::greater<std::unique_ptr<int>>());
  for ( auto v= myVector.begin(); v != myVector.end(); ++v) std::cout << *(v->get()) << " ";

  std::cout << std::endl << std::endl;

}



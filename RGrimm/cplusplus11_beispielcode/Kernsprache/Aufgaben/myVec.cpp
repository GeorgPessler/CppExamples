#include <initializer_list>
#include <iostream>
#include <vector>

template <typename T>
class MyVec{
public:
  MyVec(std::initializer_list<T> ele): vec(ele){};

private:
  std::vector<T> vec;

};

int main(){

  MyVec<int> myVec{1,2,3,4,5};

  // that should work
  //for ( auto m : myVec) std::cout << m << std::endl;

}

#include <initializer_list>
#include <iterator>
#include <iostream>
#include <vector>

template <typename T>
class MyVec{
public:
  MyVec(std::initializer_list<T> ele): vec(ele){};

  typedef typename std::vector<T>::iterator iterator;
  typedef typename std::vector<T>::const_iterator const_iterator;

  typename std::vector<T>::iterator begin() { return vec.begin(); }
  typename std::vector<T>::iterator end() { return vec.end(); }
  typename std::vector<T>::const_iterator begin() const { return vec.begin(); }
  typename std::vector<T>::const_iterator end() const { return vec.end(); }

private:
  std::vector<T> vec;

};

int main(){

  MyVec<int> myVec{1,2,3,4,5};

  // that should work
  for ( auto m : myVec) std::cout << m << std::endl;

}

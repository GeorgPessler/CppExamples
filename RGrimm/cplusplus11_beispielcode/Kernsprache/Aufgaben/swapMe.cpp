#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void swapMe(T& a, T& b){
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

struct Move{
  std::vector<int> myData;

  Move():myData({1,2,3,4,5}){}

  Move(Move&& m): myData(std::move(m.myData)){
    std::cout << "move constructor" << std::endl;
  }

  Move& operator=(Move&& m){
    myData= std::move(m.myData);
    std::cout << "move assignment operator" << std::endl;
    return *this;
  }

};

struct Copy{
  std::vector<int> myData;

  Copy():myData({1,2,3,4,5}){}

  // copy semantic
  Copy(const Copy& m):myData(m.myData){
    std::cout << "copy constructor"  << std::endl;
  }

  Copy& operator=(const Copy& m){
    myData= m.myData;
    std::cout << "copy assignment operator"  << std::endl;
    return *this;
  }

};

int main(){

  std::cout << std::endl;

  Copy a,b;
  std::cout << "-- swapMove ------------" <<std::endl;
  swapMe(a,b);

  Move c,d;
  std::cout << "---swapMove ------------" << std::endl;
  swapMe(c,d);

  std::cout << std::endl;

};


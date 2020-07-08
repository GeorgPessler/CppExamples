#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void swapCopy(T& a, T& b){
    T tmp(a);
    a = b;
    b = tmp;
}

template <typename T>
void swapMove(T& a, T& b){
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

struct MyData{
  std::vector<int> myData;

  MyData():myData({1,2,3,4,5}){}

  // copy semantic
  MyData(const MyData& m):myData(m.myData){
    std::cout << "copy constructor"  << std::endl;
  }

  MyData& operator=(const MyData& m){
    myData= m.myData;
    std::cout << "copy assignment operator"  << std::endl;
    return *this;
  }

  // move semantic
  MyData(MyData&& m): myData(std::move(m.myData)){
    std::cout << "move constructor" << std::endl;
  }

  MyData& operator=(MyData&& m){
    myData= std::move(m.myData);
    std::cout << "move assignment operator" << std::endl;
    return *this;
  }

};

int main(){

  std::cout << std::endl;

  MyData a,b;
  std::cout << "-- swapCopy ------------" <<std::endl;
  swapCopy(a,b);
  std::cout << "---swapMove ------------" << std::endl;
  swapMove(a,b);

  std::cout << std::endl;

};


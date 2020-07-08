#include <iostream>
#include <memory>
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

int main(){

  std::unique_ptr<int> unique1(new int(1));
  std::unique_ptr<int> unique2(new int(5));

  std::vector<std::unique_ptr<int> > myInt1;
  myInt1.push_back(std::move(unique1));
  myInt1.push_back(std::move(unique2));

  std::vector<std::unique_ptr<int> > myInt2;
  myInt2.push_back(std::move(unique1));

  swapMove(unique1,unique2);

  swapCopy(myInt1,myInt2);

}

#include <algorithm>
#include <forward_list>
#include <iostream>

template<typename T>
int sizeOf(std::forward_list<T> l){
  int size=0;
  std::for_each(l.begin(),l.end(),[&](T e){size++;});
  return size;
}

int main(){

  std::forward_list<int> myForList;
  myForList.push_front(7);
  myForList.push_front(6);
  myForList.push_front(5);
  myForList.push_front(4);
  myForList.push_front(3);
  myForList.push_front(2);
  myForList.push_front(1);

  std::cout << "sizeOf(myForList): " << sizeOf(myForList) << std::endl;

  std::forward_list<double> myForList2;
  std::cout << "sizeOf(myForList2): " << sizeOf(myForList2) << std::endl;

}

#include <forward_list>
#include <iostream>

int main(){

  std::forward_list<int> myForList;
  myForList.push_front(9);
  myForList.push_front(8);
  myForList.push_front(7);
  myForList.push_front(6);
  myForList.push_front(5);
  myForList.push_front(4);
  myForList.push_front(3);
  myForList.push_front(2);
  myForList.push_front(1);

  for (auto It=myForList.begin(); It != myForList.end();++It) std::cout << *It;
  std::cout << std::endl;

  myForList.remove(8);
  for (auto It=myForList.begin(); It != myForList.end();++It) std::cout << *It;
  std::cout << std::endl;

  myForList.remove_if([](int i){ return !( 2<i && i<6 );});
  for (auto It=myForList.begin(); It != myForList.end();++It) std::cout << *It;
  std::cout << std::endl;

}

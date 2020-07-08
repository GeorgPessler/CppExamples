#include <forward_list>
#include <iostream>

int main(){

  std::cout << std::endl;

  //std::forward_list<int> myForList{1,2,3,4,5,6,7};
  std::forward_list<int> myForList;
  myForList.push_front(7);
  myForList.push_front(6);
  myForList.push_front(5);
  myForList.push_front(4);
  myForList.push_front(3);
  myForList.push_front(2);
  myForList.push_front(1);

  std::cout << "forward list: " << std::endl;
  //for (auto f: myForList) std::cout << f << " ";
  for (auto It= myForList.cbegin();It != myForList.cend();++It) std::cout << *It << " ";
  std::cout << "\n\n";

  std::cout << "remove the 4-th element: " << std::endl;
  auto begin= myForList.begin();
  begin++;
  begin++;
  myForList.erase_after(begin);

  //for (auto f: myForList) std::cout << f << " ";
  for (auto It= myForList.cbegin();It != myForList.cend();++It) std::cout << *It << " ";
  std::cout << "\n\n";

  std::cout << "remove the first element: " << std::endl;
  myForList.erase_after(myForList.before_begin());

  //for (auto f: myForList) std::cout << f << " ";
  for (auto It= myForList.cbegin();It != myForList.cend();++It) std::cout << *It << " ";
  std::cout << "\n";

  std::cout << std::endl;

}

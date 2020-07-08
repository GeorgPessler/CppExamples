#include <iostream>
#include <list>

template <typename ... Args>
int countMe(Args ... args){
  return (sizeof ... args);
}

int main(){

  std::cout << "\n";

  std::list<int> myList{1,2,3,4,5,6,7,8,9};

  std::cout << "countMe() has " << countMe() << " arguments" << std::endl;
  std::cout << "countMe(\"one\", 3.14 , myList ) has " << countMe("one", 3.14 , myList ) << " arguments" << std::endl;
  std::cout << "countMe(myList) has " << countMe(myList) << " argument" << std::endl;

  std::cout << "\n";

}

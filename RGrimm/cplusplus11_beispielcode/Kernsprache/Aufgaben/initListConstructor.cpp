#include <initializer_list>
#include <iostream>
#include <string>
#include <utility>

class MyData{
public:
  MyData(std::initializer_list<std::pair<int,std::string>> myPairs){

    for (auto myPair: myPairs) std::cout << myPair.first << ", " << myPair.second << "\n";
  }
};


int main(){

  MyData{{1,std::string("one")},{2,std::string("two")},{3,std::string("three")}};

}

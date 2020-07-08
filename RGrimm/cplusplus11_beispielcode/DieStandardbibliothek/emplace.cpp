#include <deque>
#include <iostream>
#include <map>
#include <utility>

class MyVal{
public:
  MyVal(){};
  MyVal(int i):val(i){}
  int getVal() const{
    return val;
   }
private:
  int val;
};

int main(){

  std::cout << std::endl;

  std::deque<MyVal> myDeq;
  myDeq.push_back(MyVal(10));
  myDeq.push_front(MyVal(11));
  myDeq.emplace_back(12);
  myDeq.emplace_front(13);

  std::cout << "myDeq: ";
  for ( auto it= myDeq.cbegin(); it != myDeq.cend(); ++it){
    std::cout << it->getVal() << " ";
  }

  std::cout << std::endl;

  std::map<int,MyVal> myMap;
  myMap.insert(std::make_pair(1,MyVal(14)));
  myMap.insert(std::make_pair(2,15));

  std::cout << "myMap: ";
  std::cout << myMap[1].getVal() << " ";
  std::cout << myMap[2].getVal();

  std::cout << "\n\n";

}

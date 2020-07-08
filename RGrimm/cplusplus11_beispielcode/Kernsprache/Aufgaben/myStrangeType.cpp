#include <initializer_list>
#include <iostream>
#include <string>

template <typename T>
class MyStrangeType{
public:
  MyStrangeType(std::initializer_list<T> myList= std::initializer_list<T>() ){
    std::cout << "std::initializer_list<T> initList= {})" << std::endl;
  }
  MyStrangeType(T t ){
    std::cout << "MyStrangeType(T t )" << std::endl;
  }
};

int main(){

  MyStrangeType<double>();
  MyStrangeType<int>({1,2,3,4,5});
  MyStrangeType<std::string>("dummy");

}

#include <initializer_list>
#include <iostream>

class MyData{
  public:

    MyData(std::string,int){
      std::cout << "MyData(std::string,int)" << std::endl;
    }

    MyData(int,int){
      std::cout << "MyData(int,int)" << std::endl;
    }

    MyData(std::initializer_list<int>){
      std::cout << "MyData(std::initializer_list<int>)" << std::endl;
    }
};

int main(){

  std::cout << std::endl;

  // sequence constructor has a higher priority
  MyData{1,2};

  // invoke the classical constructor explicitly
  MyData(1,2);

  // use the classical constructor
  MyData{"dummy",2};

  // still valid with C++11
  int a{1};

  // still valid with C++11
  int intArray[] = {1,2};

  std::cout << std::endl;

}

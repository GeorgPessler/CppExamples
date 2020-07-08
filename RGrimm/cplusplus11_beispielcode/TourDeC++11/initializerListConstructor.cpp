#include <iostream>
#include <map>
#include <string>

// class template, parametrized with T
template <typename T>
class MyContainer{
  public:
    MyContainer(std::initializer_list<T> values){

      for (auto v : values) std::cout << v << " ";

    }
};

int main(){

  // using a initialiser list for a string
  std::string cppInventor={"Bjarne Stroustrup"};

  std::cout << "\n";
  std::cout << "Name of the cpp Inventor: " << cppInventor << std::endl;

  // using a initializer list for a map
  std::cout << "\nA few import cpp developer: " << std::endl;
  std::map<std::string,std::string> phonebook{ {cppInventor,"+1 (212) 555-1212"},{"Gabriel Dos Reis", "+1 (858) 555-9734"},{"Daveed Vandevoorde","+44 99 74855424"}};

  for (auto mapIt= phonebook.begin();mapIt!= phonebook.end();++mapIt){
    std::cout << mapIt->first << ": " << mapIt->second << std::endl;
  }

  std::cout << "\n";

  // using MyContainer with int
  MyContainer<int> myIntCont{1,2,3,4,5,6,7,8,9,10};
  std::cout << "\n";

  // using MyContainer with string
  MyContainer<std::string> myStringCont{"Range","based","for","loop."};

  std::cout << "\n\n";

}


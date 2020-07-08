#include <iostream>
#include <map>
#include <vector>


int main(){

  std::cout << "\n";

  // iterating over a C-Array
  int myArray[5] = {1, 2, 3, 4, 5};
  for (int &x : myArray) x *= 2;
  for (int x: myArray) std::cout << x << " ";
  std::cout << std::endl;

  // iterating over a std::vector
  std::vector<int> vecInt({1, 2, 3, 4, 5});
  for (int &x: vecInt) x *= 2;
  for (int x: vecInt) std::cout << x << " ";
  std::cout << std::endl;

  // iterating over a initializer list
  for (const auto x : {1,2,3,5,8,13,21,34}) std::cout << x << " ";
  std::cout << std::endl;

  // iterating over a initialiser list
  std::initializer_list<std::string>initList {"Only","For","Testing","Purpose"};
  for ( const auto x: initList) std::cout << x << " ";
  std::cout << std::endl;

  //iterating over a std::map
  std::map<std::string,std::string> phonebook{{"Bjarne Stroustrup","+1 (212) 555-1212"},{"Gabriel Dos Reis", "+1 (858) 555-9734"},{"Daveed Vandevoorde","+44 99 74855424"}};
  for ( auto mapIt: phonebook) std::cout << mapIt.first << ": " << mapIt.second << std::endl;

  std::cout << "\n";

}

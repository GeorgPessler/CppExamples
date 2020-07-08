#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string nat="a \t native string \n a native string";
  std::cout << nat << std::endl;

  // including \t \n
  std::string raw1= std::string(R"(a \t raw string \n a raw string)");
  std::cout << "\n" << raw1 << std::endl;

  // including \t \n and using delimiter
  std::string raw2= std::string(R"MyDel(a \t raw string \n a raw string)MyDel");
  std::cout << "\n" << raw2 << std::endl;

  // raw string including
  std::string raw3= std::string(R"(a raw string including ")");
  std::cout << "\n" << raw3 << std::endl;

  std::cout << std::endl;

}



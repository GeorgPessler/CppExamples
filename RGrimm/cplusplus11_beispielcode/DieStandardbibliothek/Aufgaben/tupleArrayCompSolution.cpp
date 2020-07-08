#include <array>
#include <iostream>

int main(){

  std::cout << std::endl;

  typedef std::array<int,3> IntArray;

  IntArray intArray={{1,2,3}};

  std::cout << "std::tuple_size<IntArray>::value: " <<  std::tuple_size<IntArray>::value << std::endl;
  typedef std::tuple_element<0,IntArray>::type MyInt;
  MyInt a= 5;

  std::cout << "a: " << a << std::endl;

  std::cout << "intArray: "
            << std::get<0>(intArray) << ","
            << std::get<1>(intArray) << ","
            << std::get<2>(intArray) << std::endl;

  std::cout << std::endl;

}

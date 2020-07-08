#include <iostream>
#include <tuple>

int main(){

  std::cout << std::endl;

  typedef std::tuple<int,int,int> IntTuple;

  IntTuple intTuple(1,2,3);

  std::cout << "std::tuple_size<IntTuple>::value: " <<  std::tuple_size<IntTuple>::value << std::endl;
  typedef std::tuple_element<0,IntTuple>::type MyInt;
  MyInt a= 5;

  std::cout << "a: " << a << std::endl;

  std::cout << "intTuple: "
            << std::get<0>(intTuple) << ","
            << std::get<1>(intTuple) << ","
            << std::get<2>(intTuple) << std::endl;

  std::cout << std::endl;

}

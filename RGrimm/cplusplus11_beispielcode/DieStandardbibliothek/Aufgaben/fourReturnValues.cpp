#include <iostream>
#include <string>
#include <tuple>

std::tuple<int,double,std::string,bool> returnFourValues(){
  int a= 5;
  double b= 10.1;
  std::string c= "test";
  bool d= true;
  return std::make_tuple(a, b, c, d);
}


int main(){

  //std::tuple<int,double,std::string,bool> myTuple= returnFourValues();
  auto myTuple= returnFourValues();

  std::cout << std::boolalpha;

  std::cout << std::get<0>(myTuple) << std::endl;
  std::cout << std::get<1>(myTuple) << std::endl;
  std::cout << std::get<2>(myTuple) << std::endl;
  std::cout << std::get<3>(myTuple) << std::endl;

}

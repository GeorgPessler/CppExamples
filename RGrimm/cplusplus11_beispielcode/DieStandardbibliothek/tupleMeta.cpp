#include <iostream>
#include <tuple>

typedef std::tuple<std::string,double,bool> tup1;

template <int v>
struct Int2Type {
  const static int value= v;
};

typedef std::tuple<Int2Type<2000>,Int2Type<10>,Int2Type<1>> tup2;

int main(){

  std::cout << std::endl;

  std::cout << std::boolalpha;

  std::tuple_element<0,tup1>::type fir= "meta-programming";
  std::tuple_element<1,tup1>::type sec= 3.14;
  std::tuple_element<2,tup1>::type thir= true;

  std::cout << fir << std::endl;
  std::cout << sec << std::endl;
  std::cout << thir << std::endl;

  std::cout << std::endl;

  std::cout << "std::tuple_size<tup1>::value: " << std::tuple_size<tup1>::value << std::endl;

  std::cout << std::endl;

  typedef std::tuple_element<0,tup2>::type twoThousand;
  typedef std::tuple_element<1,tup2>::type ten;
  typedef std::tuple_element<2,tup2>::type one;

  const int actYear= twoThousand::value + ten::value + one::value;

  static_assert(actYear == 2011 ,"Will be done at runtime");

  std::cout << "The actual year: " << actYear << std::endl;

  std::cout << std::endl;

}



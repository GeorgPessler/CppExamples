#include <iostream>

// primary template
template<int ...> struct sum;

// specialization for no argument
template<>struct
sum<>{
  static const int value= 0;
};

// specialization for one or more arguments
template<int i, int ... tail> struct
sum<i,tail...>{
  static const int value= i + sum<tail...>::value;
};

template<int ...> struct mult;

template<>struct
mult<>{
  static const int value= 1;
};

template<int i, int ... tail> struct
mult<i,tail...>{
  static const int value= i * mult<tail...>::value;
};

int main(){

  std::cout << std::endl;

  std::cout << "sum<>: " << sum<>::value <<std::endl;
  std::cout << "sum<1,2,3,4,5>::value: " << sum<1,2,3,4,5>::value << std::endl;
  std::cout << "sum<-20,-10,10,20>::value: " << sum<-20,-10,10,20>::value << std::endl;

  std::cout << std::endl;

  std::cout << "mult<>: " << mult<>::value <<std::endl;
  std::cout << "mult<1,2,3,4,5>::value: " << mult<1,2,3,4,5>::value << std::endl;
  std::cout << "mult<-20,-10,10,20>::value: " << mult<-20,-10,10,20>::value << std::endl;


  std::cout << std::endl;

}

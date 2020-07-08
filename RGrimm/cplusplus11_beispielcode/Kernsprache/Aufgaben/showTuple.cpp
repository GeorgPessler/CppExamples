#include <iostream>
#include <tuple>

template<typename Tuple, std::size_t N>
struct ShowTupleImpl{
  static void printMe(const Tuple& t){
    ShowTupleImpl<Tuple,N-1>::printMe(t);
    std::cout << "," << std::get<N-1>(t);
  }
};

template<typename Tuple>
struct ShowTupleImpl<Tuple, 1>{
  static void printMe(const Tuple& t){
    std::cout << std::get<0>(t);
  }
};


template<typename ... args>
void showTuple(const std::tuple<args...>& t){
  typedef const std::tuple<args...>& tuple_type;
  static const int tuple_size = sizeof...(args);
  std::cout << "(";
  ShowTupleImpl<tuple_type,tuple_size>::printMe(t);
  std::cout << ")" << std::endl;
}



int main(){

  auto tup1=std::make_tuple(1,"C++0x",3.147);
  auto tup2=std::make_tuple(1,2,3,4,5,6,7,8,9,10);
  auto tup3= std::make_tuple(1998);

  showTuple(tup1);
  showTuple(tup2);
  showTuple(tup3);

}

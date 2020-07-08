#include <iostream>
#include <set>

template <typename T>
bool greaterCompare(const T& a, const T& b){
  return a > b;
}

template <typename T>
struct GreaterCompare{
  bool operator()(const T& a, const T& b){
    return  a > b;
  }
};

template<typename T>
using SetFunctionGT= std::set<T,bool(*)(const T&, const T&)>;

template<typename T>
using SetFunctorGT= std::set<T,GreaterCompare<T>>;

template<typename T>
using SetPredefFunctorGT= std::set<T,std::greater<T>>;

template<typename T>
using SetLambdaGT= std::set<T,bool(*)(const T&, const T&)>;

int main(){

  // default behaviour
  std::set<int> mySet1{5,1,3,7,9,0};
  for ( auto s: mySet1) std::cout << s << " ";
  std::cout << std::endl;

  // using function pointer
  typedef SetFunctionGT<int> SetFunction;
  SetFunction mySet2({5,1,3,7,9,0},greaterCompare<int>);
  for ( auto s: mySet2) std::cout << s << " ";
  std::cout << std::endl;

  // using a functor
  typedef SetFunctorGT<int> SetFunctor;
  SetFunctor mySet3({5,1,3,7,9,0});
  for ( auto s: mySet3) std::cout << s << " ";
  std::cout << std::endl;

  // using a predefined functor
  typedef SetPredefFunctorGT<int> SetPredefFunctor;
  SetPredefFunctor mySet4({5,1,3,7,9,0});
  for ( auto s: mySet4) std::cout << s << " ";
  std::cout << std::endl;

  // using lambda function
  typedef SetLambdaGT<int> SetLambda;
  SetLambda mySet5({5,1,3,7,9,0},[](const int& a,const int& b){ return a > b;});
  for ( auto s: mySet5) std::cout << s << " ";
  std::cout << std::endl;

}


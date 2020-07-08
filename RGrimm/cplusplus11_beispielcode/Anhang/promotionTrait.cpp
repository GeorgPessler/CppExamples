#include <iostream>

template<typename T1, typename T2>
struct PromotionTrait{
};

template<typename T>
struct PromotionTrait<T,T>{
  typedef  T ResultT;
};

template<>
struct PromotionTrait<int,long long int>{
  typedef long long int ResultT;
};

template<>
struct PromotionTrait<long long int,int>{
  typedef long long int ResultT;
};

template<>
struct PromotionTrait<int,double>{
  typedef double ResultT;
};

template<>
struct PromotionTrait<double,int>{
  typedef double ResultT;
};

template<typename T1, typename T2>
inline typename PromotionTrait<T1,T2>::ResultT add(T1 first, T2 second){
    return first + second;
}

int main(){

  std::cout << std::endl;

  std::cout << "add(1,1)= " << add(1,1) << std::endl;
  std::cout << "add(1,2.1)= " << add(1,2.1)  << std::endl;
  std::cout << "add(1000LL,5)= " << add(1000LL,5) << std::endl;

  std::cout << std::endl;

}


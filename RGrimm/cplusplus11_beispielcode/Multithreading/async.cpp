#include <future>
#include <iostream>

int product(int a, int b){
  return a*b;
}

struct Div{
  int operator()(int a, int b){
    return a/b;
  }
};


int main(){

  int a= 20;
  int b= 10;

  std::cout << std::endl;

  std::future<int> sum=std::async([=]{ return a+b;});
  std::future<int> prod= std::async(product,a,b);
  Div divide;
  auto div=std::async(divide,a,b);

  std::cout << "20+10= " << sum.get() << std::endl;
  std::cout << "20*10= " << prod.get() << std::endl;
  std::cout << "20/10= " << div.get() << std::endl;

  std::cout << std::endl;
}

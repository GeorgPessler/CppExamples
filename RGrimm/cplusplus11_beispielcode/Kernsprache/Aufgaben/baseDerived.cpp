#include <algorithm>
#include <iostream>

struct Base{
  Base(const std::string& n){
    std::cout<< "Base(const std::string& n)" << std::endl;
  }
  Base(std::string&& n){
    std::cout<< "Base( std::string&& n)" << std::endl;
  }
};

struct Derived: Base{
  template <typename ... Args>
  Derived(Args&& ...args):Base(std::forward<Args>(args)...){}

};

int main(){

  Derived deriv1(std::string("Rvalue"));

  std::string lvalue{"lvalue"};
  Derived deriv2(lvalue);

  Derived deriv3(std::move(lvalue));

}

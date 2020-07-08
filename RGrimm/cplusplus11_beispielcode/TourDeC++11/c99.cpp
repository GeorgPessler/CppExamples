#include <iostream>

void showFuncName(){
  std::cout << "__func__=  " << __func__ << std::endl;
}

int main(){

  std::cout << std::endl;

  long long int ll=10;
  int i= 10;

  std::cout << "sizeof(long long int)= " << sizeof(ll) << std::endl;
  std::cout << "sizeof(int)= " << sizeof(i) << std::endl;

  std::cout << "__func__=  " << __func__ << std::endl;
  showFuncName();

  std::cout << std::endl;

}

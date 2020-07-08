#include <memory>

int main(){

  std::auto_ptr<int> auto1(new int(5));

  // implicit transfer of ownership
  std::auto_ptr<int> auto2(auto1);

  // undefined behaviour
  int a= *auto1;

}

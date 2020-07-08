#include <algorithm>
#include <iostream>

class WithReferenceMemberFunction{
public:
  void reference() & {
    std::cout << "LValue Reference" << std::endl;
  }
    void reference() && {
    std::cout << "RValue Reference" << std::endl;
  }
};

int main(){

  WithReferenceMemberFunction lvalue;
  lvalue.reference();

  WithReferenceMemberFunction().reference();

}

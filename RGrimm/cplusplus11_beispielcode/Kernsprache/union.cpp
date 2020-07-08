#include <iostream>
#include <string>

union MemorySizeChar{
    char a;
    char b;
};

union MemorySizeDouble{
    char a;
    double d;
};

union UnionWithString{
  std::string s;
  int i;
//  UnionWithString():s("hello"){}
//  ~UnionWithString(){}
};

using std::string;

int main(){

  std::cout << std::endl;

  MemorySizeChar mSC{'a'};
  std::cout << "mSC.a= " << mSC.a << std::endl;
  mSC.b='b';
  std::cout << "mSC.b= " << mSC.b << std::endl;

  std::cout << std::endl;

  std::cout << "sizeof(mSC)= " << sizeof(mSC) << std::endl;

  MemorySizeDouble mSD;
  std::cout << "sizeof(mSC)= " << sizeof(mSD) << std::endl;

  std::cout << std::endl;

  UnionWithString uWithString;

  std::cout << uWithString.s << std::endl;
  // invoke the destructor explicitly
  uWithString.s.~string();

  uWithString.i=10;
  std::cout << uWithString.i << std::endl;

  // use placement new
  new (&uWithString.s) std::string("hello again");
  std::cout << uWithString.s << std::endl;
  // invoke the destructor explicitly
  uWithString.s.~string();

  std::cout << std::endl;

}




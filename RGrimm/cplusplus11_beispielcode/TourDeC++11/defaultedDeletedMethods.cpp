#include <iostream>

class NonCopyableClass{
  public:

    // state the compiler generated default constructor
  //NonCopyableClass()= default;

    // disallow copying
  NonCopyableClass& operator =(const NonCopyableClass&)= delete;
  NonCopyableClass (const NonCopyableClass&)= delete;
};

class SomeType{
  public:

  // state the compiler generated default constructor
  SomeType()= default;

  // constructor for int
  SomeType(int value){};

};

class TypeOnStack {
  public:

    void* operator new(std::size_t)= delete;
};

int main(){

  NonCopyableClass nonCopyableClass;
  SomeType someType;
  TypeOnStack typeOnStack;

  // force the compiler error
  NonCopyableClass nonCopyableClass2(nonCopyableClass);

  // force the compiler error
  TypeOnStack* typeOnHeap= new TypeOnStack;

}

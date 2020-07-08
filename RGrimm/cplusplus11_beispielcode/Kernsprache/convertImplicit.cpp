class A{};

class B{};

class MyClass{
  public:
    MyClass(){}
    MyClass(A){}
    operator B(){ return B();}
};

void needMyClass(MyClass){};
void needB(B){};

int main(){

  // A -> MyClass
  A a;

  // explicit invocation
  MyClass myClass1(a);
  // implicit conversion from A to MyClass
  MyClass myClass2= a;
  needMyClass(a);

  // MyClass -> B
  MyClass myCl;

  // explicit invocation
  B b1(myCl);
  // implicit conversion from MyClass to B
  B b2= myCl;
  needB(myCl);

}


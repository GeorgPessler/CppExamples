#include <mutex>
#include <thread>

class MyClass{
  int i;
  public:

    constexpr MyClass():i(0){}
    MyClass(int i_):i(i_){}

};

void blockScope(){

  // statically initialized
  static MyClass myClass(1);

}

MyClass* myClass3=nullptr;

void createInstance(){

  myClass3=new MyClass(2);

}


int main(){

  // protected initialized, because of

  // constexpr
  MyClass myClass;

  // block scope
  blockScope();

  // threading library functions
  std::once_flag initFlag;
  std::call_once(initFlag,createInstance);

}

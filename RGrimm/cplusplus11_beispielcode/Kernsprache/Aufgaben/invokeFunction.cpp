#include <iostream>
#include <string>

void invokeFunction(auto func){
  std::cout << "I'm a " << func() << "." << std::endl;
}

std::string myFunction(){
  return "function";
}

struct MyFunctionObject{
  std::string operator()(){
    return "function object";
  }
};

int main(){

  invokeFunction([]{ return "lambda function";});

  invokeFunction(&myFunction);

  invokeFunction(MyFunctionObject());

}

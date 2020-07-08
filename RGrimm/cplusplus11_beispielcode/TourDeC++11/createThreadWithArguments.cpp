#include <iostream>
#include <string>
#include <thread>

void helloFunction(const std::string& s){
  std::cout << s << std::endl;
}

class HelloFunctionObject{
  public:
    void operator()(const std::string& s) const {
      std::cout << s << std::endl;
    }
};


int main(){

  std::cout << std::endl;

  // thread executing helloFunction
  std::thread t1(helloFunction,"Hello C++11 from function.");

  // thread executing helloFunctionObject
  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject,"Hello C++11 from function object.");

  // thread executing lambda function
  std::thread t3([](const std::string& s){std::cout << s << std::endl;},"Hello C++11 from lambda function.");

  // ensure that t1, t2 and t3 have finished before main terminates
  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl;

};


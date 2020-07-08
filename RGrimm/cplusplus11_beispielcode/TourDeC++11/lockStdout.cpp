#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex coutMutex;

void helloFunction(const std::string& s){

  // acquire lock
  std::lock_guard<std::mutex> guard(coutMutex);
  std::cout << s << std::endl;

} // release lock automatically


class HelloFunctionObject{
  public:
    void operator()(const std::string& s) const {

      // acquire lock
      std::lock_guard<std::mutex> guard(coutMutex);
      std::cout << s << std::endl;

    } // release lock automatically
};


int main(){

  std::cout << std::endl;

  // thread executing helloFunction
  std::thread t1(helloFunction,"Hello C++0x from function.");

  // thread executing HelloFunctionObject
  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject,"Hello C++0x from function object.");

  // thread executing lambda function
  std::thread t3([&]{std::lock_guard<std::mutex> guard(coutMutex); std::cout << "Hello C++0x from lambda function." << std::endl;});

  // ensure that t1, t2 and t3 have finished before main terminates
  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl;

};


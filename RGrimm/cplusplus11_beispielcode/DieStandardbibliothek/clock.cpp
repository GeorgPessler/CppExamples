#include <chrono>
#include <iostream>

int main(){

  std::cout << std::boolalpha<< std::endl;

  auto timeNow= std::chrono::system_clock::now();
  auto duration= timeNow.time_since_epoch();

  std::cout << "nanoseconds since 1.1.1970 :" <<  duration.count() << std::endl;

  std::cout << "is steady: " << std::chrono::system_clock::is_steady << std::endl;

  std::cout << std::endl;

}

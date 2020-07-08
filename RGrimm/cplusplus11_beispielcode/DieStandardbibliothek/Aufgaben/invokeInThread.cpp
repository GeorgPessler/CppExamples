#include <functional>
#include <iostream>
#include <thread>
#include <vector>

void func1(){std::cout << "Only ";}
void func2(){std::cout << "for ";}
void func3(){std::cout << "testing ";}
void func4(){std::cout << "purpose";}
void func5(){std::cout << ".\n";}

int main(){

  typedef void callable();

  std::vector<std::reference_wrapper<callable>> myCallables{func1,func2,func3,func4,func5};

  std::thread writeTextThread([&myCallables]{for ( auto f : myCallables) f();});

  writeTextThread.join();

}

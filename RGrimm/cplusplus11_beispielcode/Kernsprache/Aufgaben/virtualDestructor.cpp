#include <chrono>
#include <iostream>
#include <vector>

class BaseManually{
public:
  virtual ~BaseManually(){};
};

class Derived1: public BaseManually{};

class BaseCompiler{
public:
  virtual ~BaseCompiler();
};
BaseCompiler::~BaseCompiler() = default;

class Derived2: public BaseCompiler{};

int main(){

  const int num= 1000000;

  std::vector<BaseManually*> vecDer1;
  std::vector<BaseCompiler*> vecDer2;

  for (int i= 0; i<= num; ++i){
    vecDer1.push_back(new Derived1() );
    vecDer2.push_back(new Derived2() );
  }

  /*
  auto begin1= std::chrono::system_clock::now();
  for (int i= 0; i<= num; ++i) delete vecDer1[i];
  std::chrono::duration<double> dur1  = std::chrono::system_clock::now() - begin1;
  std::cout << dur1.count() << std::endl;

  */

  auto begin2= std::chrono::system_clock::now();
  for (int i= 0; i<= num; ++i) delete vecDer2[i];
  std::chrono::duration<double> dur2  = std::chrono::system_clock::now() - begin2;
  std::cout << dur2.count() << std::endl;

  auto begin1= std::chrono::system_clock::now();
  for (int i= 0; i<= num; ++i) delete vecDer1[i];
  std::chrono::duration<double> dur1  = std::chrono::system_clock::now() - begin1;
  std::cout << dur1.count() << std::endl;



}

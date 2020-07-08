#include <future>
#include <iostream>
#include <iostream>

void setDataReady();

void waitingForWork1(){

  auto getStartSignal= std::async( std::launch::async,[]{ return setDataReady(); });
  std::cout << "--- Worker 1 done" << std::endl;

}

void waitingForWork2(){

  auto getStartSignal= std::async( std::launch::async,[]{ return waitingForWork1(); });
  std::cout << "--- Worker 2 done" << std::endl;

}

void waitingForWork3(){

  auto getStartSignal= std::async( std::launch::async,[]{ return waitingForWork2(); });
  std::cout << "--- Worker 3 done" << std::endl;

}

void setDataReady(){

  std::cout << "Starting Workflow"  << std::endl;

}

int main(){

  std::cout << std::endl;

  waitingForWork3();

  std::cout << "Work done" << std::endl;

  std::cout << std::endl;

}



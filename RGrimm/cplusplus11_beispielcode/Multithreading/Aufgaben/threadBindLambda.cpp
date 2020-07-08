#include <functional>
#include <iostream>
#include <cmath>
#include <thread>


void sinAt(double val){
  std::cout << sin(val) << std::endl;
}

int main(){
  double val= 1.0;
  std::thread threadLOut([=]{std::cout<< sin(val) << std::endl;});
  std::thread threadBOut(std::bind(sinAt,val));

  threadLOut.join();
  threadBOut.join();

}

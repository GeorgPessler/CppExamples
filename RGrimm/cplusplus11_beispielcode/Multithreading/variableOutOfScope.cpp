#include <chrono>
#include <iostream>
#include <thread>

void runThread(){
  int valRunThread= 10;
  std::thread t([&]{std::cout << "valRunThread= " <<  valRunThread << std::endl;});
  t.join();
}

class Sleeper{

  public:
    Sleeper(int& i_):i{i_}{};
    void operator() (int k){
      for (unsigned int j= 0; j <= 5; ++j){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        i += k;
      }
    }
  private:
    int& i;
};


int main(){

  std::cout << std::endl;
  runThread();

  std::cout << std::endl;

  int valSleeper= 1000;
  std::thread t(Sleeper(valSleeper),5);
  // t.detach();
  t.join();
  std::cout << "valSleeper = " << valSleeper << std::endl;

  std::cout << std::endl;

}

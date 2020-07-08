#include <chrono>
#include <future>
#include <iostream>
#include <thread>

std::mutex coutMutex;

struct Requestor{

  void operator ()(std::shared_future<void> shaFut,int time){

    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    auto begin = std::chrono::system_clock::now();
    shaFut.wait();
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - begin;
    std::lock_guard<std::mutex> coutGuard(coutMutex);
    std::cout << "thread(" << std::this_thread::get_id() << ") have to wait for " << dur.count() << " seconds." << std::endl  ;

  }

};

int main(){

  std::cout << std::endl;

  // define the promises
  std::promise<void> divPromise;

  // get the futures
  std::shared_future<void> divResult= divPromise.get_future();

  Requestor req;
  std::thread sharedThread1(req,divResult,1000);

  std::thread sharedThread2(req,divResult,500);

  std::thread sharedThread3(req,divResult,2000);

  std::thread sharedThread4(req,divResult,2500);

  std::thread sharedThread5(req,divResult,0);

  // synchronise the Threads by invoking set_value
  // each thread have to wait up to 3 seconds
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  divPromise.set_value();

  sharedThread1.join();
  sharedThread2.join();
  sharedThread3.join();
  sharedThread4.join();
  sharedThread5.join();

  std::cout << std::endl;

}


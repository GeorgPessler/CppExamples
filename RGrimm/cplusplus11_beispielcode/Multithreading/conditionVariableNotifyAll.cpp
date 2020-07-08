#include <chrono>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;

void waitingForWork(){

  std::unique_lock<std::mutex> lck(mutex_);
  condVar.wait(lck,[]{return dataReady;});
  std::cout << "Hello from thread: " << std::this_thread::get_id() << std::endl;

}

void setDataReady(){

  std::lock_guard<std::mutex> lck(mutex_);
  dataReady=true;
  condVar.notify_all();

}

int main(){

  std::cout << std::endl;

  std::thread w1(waitingForWork);
  std::thread w2(waitingForWork);
  std::thread w3(waitingForWork);
  std::thread w4(waitingForWork);
  std::thread w5(waitingForWork);

  std::thread t(setDataReady);

  t.join();

  w1.join();
  w2.join();
  w3.join();
  w4.join();
  w5.join();

  std::cout << std::endl;

}



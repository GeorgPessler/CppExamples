#include <iostream>
#include <condition_variable>
#include <thread>

std::mutex mutex1, mutex2, mutex3;

std::condition_variable condVar1, condVar2, condVar3;

bool dataReady1, dataReady2, dataReady3;


void waitingForWork1(){

  std::unique_lock<std::mutex> lck(mutex1);
  condVar1.wait(lck,[]{return dataReady1;});
  std::cout << "--- Worker 1 done" << std::endl;
  std::lock_guard<std::mutex> lckGuard(mutex2);
  dataReady2=true;
  condVar2.notify_one();

}

void waitingForWork2(){

  std::unique_lock<std::mutex> lck(mutex2);
  condVar2.wait(lck,[]{return dataReady2;});
  std::cout << "--- Worker 2 done" << std::endl;
  std::lock_guard<std::mutex> lckGuard(mutex3);
  dataReady3=true;
  condVar3.notify_one();

}

void waitingForWork3(){

  std::unique_lock<std::mutex> lck(mutex3);
  condVar3.wait(lck,[]{return dataReady3;});
  std::cout << "--- Worker 3 done" << std::endl;

}

void setDataReady(){

  std::lock_guard<std::mutex> lck(mutex1);
  std::cout << "Starting Workflow"  << std::endl;
  dataReady1=true;
  condVar1.notify_one();

}

int main(){

  std::cout << std::endl;

  std::thread w1(waitingForWork1);
  std::thread w2(waitingForWork2);
  std::thread w3(waitingForWork3);

  std::thread t(setDataReady);

  t.join();
  w1.join();
  w2.join();
  w3.join();

  std::cout << "Work done" << std::endl;

  std::cout << std::endl;

}



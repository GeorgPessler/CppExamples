#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_1;
std::condition_variable condVar1;

std::mutex mutex_2;
std::condition_variable condVar2;


bool dataReady1;
bool dataReady2;


void waitingForWork(){

  std::unique_lock<std::mutex> lck1(mutex_1);
  std::unique_lock<std::mutex> lck2(mutex_2);
  std::cout << "waiting" << std::endl;
  condVar1.wait(lck1,[]{return dataReady1;});
  std::cout << "dataReady1 done" << std::endl;
  condVar2.wait(lck2,[]{return dataReady2;});
  std::cout << "dataReady2 done" << std::endl;

}

void setDataReady1(){

  std::lock_guard<std::mutex> lck(mutex_1);
  dataReady1=true;
  condVar1.notify_one();

}

void setDataReady2(){

  std::lock_guard<std::mutex> lck(mutex_2);
  dataReady2=true;
  condVar2.notify_one();

}


int main(){

  std::thread tWait(waitingForWork);
  std::thread tSet1(setDataReady1);
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::thread tSet2(setDataReady2);

  tWait.join();
  tSet1.join();
  tSet2.join();

  std::cout << "all done" << std::endl;
}


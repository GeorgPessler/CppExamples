#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex;
std::condition_variable condVar;

bool dataReady;

void waitingForWork(){

  std::unique_lock<std::mutex> lck(mutex);
  std::cout << "waiting" << std::endl;
  condVar.wait(lck,[]{return dataReady;});
  std::cout << "waitingForWork done" << std::endl;

}

void setDataReady1(){

  std::unique_lock<std::mutex> lck(mutex);
  dataReady=true;
  condVar.notify_one();
  std::cout << "setDataReady1 done" << std::endl;

}

void setDataReady2(){

  std::unique_lock<std::mutex> lck(mutex);
  dataReady=true;
  condVar.notify_one();
  std::cout << "setDataReady2 done" << std::endl;

}

int main(){

  std::thread tWait(waitingForWork);
  std::thread tSet1(setDataReady1);
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::thread tSet2(setDataReady2);

  tWait.join();
  tSet1.join();
  tSet2.join();

  std::cout << std::boolalpha;
  std::cout << "all done" << std::endl;
}


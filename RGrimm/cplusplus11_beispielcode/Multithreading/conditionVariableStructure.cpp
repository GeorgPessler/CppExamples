#include <condition_variable>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;


void waitingForWork(){

  std::unique_lock<std::mutex> lck(mutex_);
  condVar.wait(lck,[]{return dataReady;});

}

void setDataReady(){

  std::lock_guard<std::mutex> lck(mutex_);
  dataReady=true;
  condVar.notify_one();

}

int main(){

  std::thread t1(waitingForWork);
  std::thread t2(setDataReady);

  t1.join();
  t2.join();
}



#include <chrono>
#include <iostream>
#include <thread>


class CritData{

  private:
    std::unique_lock<std::mutex>&& myLock;

  public:
    CritData(std::unique_lock<std::mutex>&& myLo_):myLock(std::move(myLo_)){}

    CritData(CritData&& other) :myLock(std::move(other.myLock)){}

    CritData& operator=(CritData&& other){
      if(&other != this){
        myLock=std::move(other.myLock);
      }
      return *this;
    }
    void doCriticalWork(){
      std::cout << "a lot to do" << std::endl;
    }
};

void exclusiveExecution(){

  static std::mutex myMutex;
  std::unique_lock<std::mutex> myLock(myMutex);

  std::cout << std::this_thread::get_id() << std::endl;

  // owner of myLock
  CritData criticalData(std::move(myLock));
  criticalData.doCriticalWork();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // new owner of myLock
  CritData criticalData2(std::move(criticalData));
  criticalData.doCriticalWork();

  std::cout << std::this_thread::get_id() << std::endl;

}

int main(){

  std::cout << std::endl;

  std::thread t1(exclusiveExecution);

  std::thread t2(exclusiveExecution);

  t1.join();
  t2.join();

  std::cout << std::endl;

}


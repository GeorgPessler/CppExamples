#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <thread>

std::timed_mutex myMapMutex;

std::map<std::string,int> myMap{ {"red",1},{"green",2},{"blue",3}};

// critical region => modifying the global variable myMap
void addToMap(const std::string& key,int value){
  auto it= myMap.find(key);
  if ( it == myMap.end()) myMap[key]= value;
}

void workThread1(){

  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  // try to get the lock; potential blocking
  myMapMutex.lock();
  std::cout<< "Thread1 get the lock"  << std::endl;
  addToMap("yellow",4);
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  myMapMutex.unlock();

}

void workThread2(){

  // try to get the lock once
  if ( myMapMutex.try_lock() ){
    std::cout << "Thread2 get the lock" << std::endl;
    addToMap("brown",5);
    myMapMutex.unlock();
  }

}

void workThread3(){

  std::this_thread::sleep_for(std::chrono::milliseconds(15));

  // try to get the lock for 2000 Milliseconds
  if ( myMapMutex.try_lock_for(std::chrono::milliseconds(2000)) ){
    std::cout << "Thread3 get the lock" << std::endl;
    addToMap("purple",6);
    myMapMutex.unlock();
  }

}

int main(){

  std::cout << std::endl;

  std::thread t1([=]{workThread1();});
  std::thread t2([=]{workThread2();});
  std::thread t3([=]{workThread3();});

  t1.join();
  t2.join();
  t3.join();

  for ( auto mapIt: myMap) std::cout << mapIt.first << ": " << mapIt.second << std::endl;

  std::cout << std::endl;

}

#include <chrono>
#include <iostream>
#include <ratio>
#include <thread>

int main(){

  std::cout << std::endl;

  // get the actual time
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

  // sleep 1000 * 1 Millisecond
  for ( int i = 0; i <= 1000;++i){
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  std::chrono::duration<double> dur  = std::chrono::system_clock::now() - start;

  std::cout << "sleeping 1000 times 1 Millisecond take: "<< dur.count() << std::endl;

  auto begin= std::chrono::system_clock::now();

  auto end = std::chrono::system_clock::now() + std::chrono::duration<double, std::ratio<1>>(0.5);

  while (std::chrono::system_clock::now() < end);

  std::chrono::duration<double> dur1  = std::chrono::system_clock::now() - begin;

  std::cout << "busy waiting for half a second :" << dur1.count() << std::endl;

  // typedef for minutes, seconds and milliseconds
  typedef std::chrono::duration<long long, std::ratio<60>> minutes;
  typedef std::chrono::duration<long long, std::ratio<1>> seconds;
  typedef std::chrono::duration<long long, std::ratio<1,1000>> milliseconds;

  seconds sec(5);
  minutes min(2);
  milliseconds mil(10);

  milliseconds milRes= min + sec + mil;

  std::cout << "2 Minutes + 5 Seconds + 10 Milliseconds=  "<< milRes.count() << " Milliseconds" << std::endl;

  // typedef for hours
  typedef std::chrono::duration<double,std::ratio<3600>> hours;
  hours hourRes= milRes;

  std::cout << "2 Minutes + 5 Seconds + 10 Milliseconds=  "<< hourRes.count() << " Hours" << std::endl;

  std::cout << std::endl;

}

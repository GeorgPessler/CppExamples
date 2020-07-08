#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <deque>

class SumUp{
  public:
    SumUp(int b, int e): beg(b),end(e),sum(0){}
    int operator()(){
      for (int i= beg; i < end; ++i ) sum += i;
      return sum;
    }
  private:
    int beg;
    int end;
    int sum;
};

int main(){

  std::cout << std::endl;

  SumUp sumUp1(0,2500);
  SumUp sumUp2(2500,5000);
  SumUp sumUp3(5000,7500);
  SumUp sumUp4(7500,10001);

  // define the tasks
  std::packaged_task<int()> sumTask1(sumUp1);
  std::packaged_task<int()> sumTask2(sumUp2);
  std::packaged_task<int()> sumTask3(sumUp3);
  std::packaged_task<int()> sumTask4(sumUp4);

  // get the futures
  std::future<int> sumResult1= sumTask1.get_future();
  std::future<int> sumResult2= sumTask2.get_future();
  std::future<int> sumResult3= sumTask3.get_future();
  std::future<int> sumResult4= sumTask4.get_future();

  // push the tasks on the container
  std::deque< std::packaged_task<int()> > allTasks;
  allTasks.push_back(std::move(sumTask1));
  allTasks.push_back(std::move(sumTask2));
  allTasks.push_back(std::move(sumTask3));
  allTasks.push_back(std::move(sumTask4));

  // execute each task in a separate thread
  while ( not allTasks.empty() ){
    std::packaged_task<int()> myTask= std::move(allTasks.front());
    allTasks.pop_front();
    std::thread sumThread(std::move(myTask));
    sumThread.detach();
  }

  // get the results
  int sum= sumResult1.get() + sumResult2.get() + sumResult3.get() + sumResult4.get();

  std::cout << "sum of 0 .. 100000 = " << sum << std::endl;

  std::cout << std::endl;

}

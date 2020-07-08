#include <future>
#include <iostream>

int product(int a, int b){
  return a*b;
}

struct Div{
  int operator()(int a, int b){
    return a/b;
  }
};


int main(){

  std::cout << std::endl;

  // define the package tasks
  std::packaged_task<int(int,int)> sumTask([](int x, int y){return x+y;});
  std::packaged_task<int(int,int)> prodTask(product);
  Div divide;
  std::packaged_task<int(int,int)> divTask(divide);

  // get the futures
  std::future<int> sumResult= sumTask.get_future();
  std::future<int> prodResult= prodTask.get_future();
  std::future<int> divResult= divTask.get_future();

  // calculate the result
  sumTask(20,10);
  prodTask(20,10);
  divTask(20,10);

  // get the result
  std::cout << "20+10= " << sumResult.get() << std::endl;
  std::cout << "20*10= " << prodResult.get() << std::endl;
  std::cout << "20/10= " << divResult.get() << std::endl;

  std::cout << std::endl;

}



#include <algorithm>
#include <iostream>
#include <vector>

class AccumTemp{
    int& sum;
    int inc;

  public:

    AccumTemp (int& sum_, int inc_): sum(sum_), inc(inc_) {}

    int operator()(int v) const {
      return sum += v+inc;
    }
};

int main(){

  std::cout << std::endl;

  std::vector<int> vecInt{1,2,3,4,5,6,7,8,9,10};
  int sumLambda=0;
  int inc=5;

  // summation with the lambda function
  std::for_each(vecInt.begin(),vecInt.end(),[&sumLambda,inc](int v){sumLambda += v+inc;});

  std::cout << "Summation with the Lambda Function: " << sumLambda << std::endl;

  std::cout << std::endl;

  int sumFunctionObject=0;

  // summation with the function object
  std::for_each(vecInt.begin(),vecInt.end(),AccumTemp(sumFunctionObject,inc));

  std::cout << "Summation with the Function Object: " << sumFunctionObject << std::endl;

  std::cout << std::endl;

}

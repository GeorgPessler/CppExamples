#include <algorithm>
#include <iostream>

class SumMe{
  private:
    int sum;

  public:
    // init sum with 0
    SumMe(): sum(0){};

  // add x to sum
  void operator()(int x){
    sum +=x;
  }

  // get the result
  int getSum(){
    return sum;
  }

};

int main(){

  std::vector<int> intVec= {1,2,3,4,5,6,7,8,9,10};

  // sum the values up and bind the function object to sumMe
  SumMe sumMe= std::for_each(intVec.begin(),intVec.end(), SumMe());

  std::cout << "\n";
  std::cout << "Sum of intVec= " << sumMe.getSum() << std::endl;
  std::cout << "\n";

}

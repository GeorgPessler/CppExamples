#include <iostream>
#include <random>

class GetOneZero{
public:
  GetOneZero(){}
  bool operator()(){
    static std::random_device seed;
    static std::mt19937 engine(seed());
    return binDist(engine);
  }
private:
  std::bernoulli_distribution binDist;
};

int main(){

  std::cout << std::endl;

  GetOneZero getOneZero;
  for (unsigned int i=0; i< 10; ++i) std::cout << getOneZero();

  std::cout << std::endl << std::endl;

}

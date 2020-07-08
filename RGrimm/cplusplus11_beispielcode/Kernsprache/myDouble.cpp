#include <iostream>

class MyDouble{
  private:
    double myVal1;
    double myVal2;
  public:
    constexpr MyDouble(double v1,double v2):myVal1(v1),myVal2(v2){}
    constexpr double getSum(){ return myVal1+myVal2;}
};


int main(){

  std::cout << std::endl;

  // use a constant expression
  constexpr double myStatVal= 2.0;
  constexpr MyDouble myStatic(10.5,myStatVal);
  constexpr double sumStat= myStatic.getSum();

  static_assert(myStatic.getSum() == 12.5,"you calculated it wrong");
  static_assert(sumStat == 12.5,"you calculated it wrong");
  std::cout << "myStatic.getSum()= " << myStatic.getSum() << std::endl;

  // use the constant expression at runtime
  double myDynVal= 2.0;
  MyDouble myDyn(10.5,myDynVal);
  double sumDyn= myDyn.getSum();
  std::cout << "myDyn.getSum()= " << myDyn.getSum() << std::endl;

  std::cout << std::endl;

}

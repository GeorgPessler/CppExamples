#include <vector>

int func(int){ return 2011;}

int main(){

  auto i= 5;
  auto& intRef=i;             // int&
  auto* intPoint= &i;         // int*
  const auto constInt= i;    // const int
  volatile auto volInt=i;    // volatile int
  static auto staticInt= 10; // static int

  const std::vector<int> myVec;
  auto vec = myVec;           // std::vector<int>
  auto& vecRef = vec;         // const std::vector<int>&

  int myData[10];
  auto v1 = myData;           // int*
  auto& v2 = myData;          // int (&)[10]

  auto myFunc= func;          // func*
  auto& myFuncRef= func;      // (int)(*)(int)

}
